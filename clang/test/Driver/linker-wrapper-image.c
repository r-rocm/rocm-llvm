// REQUIRES: x86-registered-target
// REQUIRES: nvptx-registered-target
// REQUIRES: amdgpu-registered-target

// RUN: %clang -cc1 %s -triple x86_64-unknown-linux-gnu -emit-obj -o %t.elf.o

// RUN: clang-offload-packager -o %t.out --image=file=%t.elf.o,kind=openmp,triple=nvptx64-nvidia-cuda,arch=sm_70
// RUN: %clang -cc1 %s -triple x86_64-unknown-linux-gnu -emit-obj -o %t.o \
// RUN:   -fembed-offload-object=%t.out
// RUN: clang-linker-wrapper --print-wrapped-module --dry-run --host-triple=x86_64-unknown-linux-gnu \
// RUN:   --linker-path=/usr/bin/ld -- %t.o -o a.out 2>&1 | FileCheck %s --check-prefixes=OPENMP,OPENMP-ELF
// RUN: clang-linker-wrapper --print-wrapped-module --dry-run --host-triple=x86_64-unknown-windows-gnu \
// RUN:   --linker-path=/usr/bin/ld -- %t.o -o a.out 2>&1 | FileCheck %s --check-prefixes=OPENMP,OPENMP-COFF

//      OPENMP-ELF: @__start_omp_offloading_entries = external hidden constant [0 x %struct.__tgt_offload_entry]
// OPENMP-ELF-NEXT: @__stop_omp_offloading_entries = external hidden constant [0 x %struct.__tgt_offload_entry]
// OPENMP-ELF-NEXT: @__dummy.omp_offloading_entries = hidden constant [0 x %struct.__tgt_offload_entry] zeroinitializer, section "omp_offloading_entries"

//      OPENMP-COFF: @__start_omp_offloading_entries = hidden constant [0 x %struct.__tgt_offload_entry] zeroinitializer, section "omp_offloading_entries$OA"
// OPENMP-COFF-NEXT: @__stop_omp_offloading_entries = hidden constant [0 x %struct.__tgt_offload_entry] zeroinitializer, section "omp_offloading_entries$OZ"

//      OPENMP: @.omp_offloading.device_image = internal unnamed_addr constant [[[SIZE:[0-9]+]] x i8] c"\10\FF\10\AD{{.*}}", section ".llvm.offloading", align 8
// OPENMP-NEXT: @.omp_offloading.device_images = internal unnamed_addr constant [1 x %__tgt_device_image] [%__tgt_device_image { ptr getelementptr inbounds ([[[BEGIN:[0-9]+]] x i8], ptr @.omp_offloading.device_image, i64 1, i64 0), ptr getelementptr inbounds ([[[END:[0-9]+]] x i8], ptr @.omp_offloading.device_image, i64 1, i64 0), ptr @__start_omp_offloading_entries, ptr @__stop_omp_offloading_entries }]
// OPENMP-NEXT: @.omp_offloading.descriptor = internal constant %__tgt_bin_desc { i32 1, ptr @.omp_offloading.device_images, ptr @__start_omp_offloading_entries, ptr @__stop_omp_offloading_entries }
// OPENMP-NEXT: @llvm.global_ctors = appending global [1 x { i32, ptr, ptr }] [{ i32, ptr, ptr } { i32 1, ptr @.omp_offloading.descriptor_reg, ptr null }]
// OPENMP-NEXT: @llvm.global_dtors = appending global [1 x { i32, ptr, ptr }] [{ i32, ptr, ptr } { i32 1, ptr @.omp_offloading.descriptor_unreg, ptr null }]

//      OPENMP: define internal void @.omp_offloading.descriptor_reg() section ".text.startup" {
// OPENMP-NEXT: entry:
// OPENMP-NEXT:   call void @__tgt_register_lib(ptr @.omp_offloading.descriptor)
// OPENMP-NEXT:   ret void
// OPENMP-NEXT: }

//      OPENMP: define internal void @.omp_offloading.descriptor_unreg() section ".text.startup" {
// OPENMP-NEXT: entry:
// OPENMP-NEXT:   call void @__tgt_unregister_lib(ptr @.omp_offloading.descriptor)
// OPENMP-NEXT:   ret void
// OPENMP-NEXT: }

// RUN: clang-offload-packager -o %t.out --image=file=%t.elf.o,kind=cuda,triple=nvptx64-nvidia-cuda,arch=sm_70
// RUN: %clang -cc1 %s -triple x86_64-unknown-linux-gnu -emit-obj -o %t.o \
// RUN:   -fembed-offload-object=%t.out
// RUN: clang-linker-wrapper --print-wrapped-module --dry-run --host-triple=x86_64-unknown-linux-gnu \
// RUN:   --linker-path=/usr/bin/ld -- %t.o -o a.out 2>&1 | FileCheck %s --check-prefixes=CUDA,CUDA-ELF
// RUN: clang-linker-wrapper --print-wrapped-module --dry-run --host-triple=x86_64-unknown-windows-gnu \
// RUN:   --linker-path=/usr/bin/ld -- %t.o -o a.out 2>&1 | FileCheck %s --check-prefixes=CUDA,CUDA-COFF

//      CUDA-ELF: @__start_cuda_offloading_entries = external hidden constant [0 x %struct.__tgt_offload_entry]
// CUDA-ELF-NEXT: @__stop_cuda_offloading_entries = external hidden constant [0 x %struct.__tgt_offload_entry]
// CUDA-ELF-NEXT: @__dummy.cuda_offloading_entries = hidden constant [0 x %struct.__tgt_offload_entry] zeroinitializer, section "cuda_offloading_entries"

//      CUDA-COFF: @__start_cuda_offloading_entries = hidden constant [0 x %struct.__tgt_offload_entry] zeroinitializer, section "cuda_offloading_entries$OA"
// CUDA-COFF-NEXT: @__stop_cuda_offloading_entries = hidden constant [0 x %struct.__tgt_offload_entry] zeroinitializer, section "cuda_offloading_entries$OZ"

//      CUDA: @.fatbin_image = internal constant [0 x i8] zeroinitializer, section ".nv_fatbin"
// CUDA-NEXT: @.fatbin_wrapper = internal constant %fatbin_wrapper { i32 1180844977, i32 1, ptr @.fatbin_image, ptr null }, section ".nvFatBinSegment", align 8
// CUDA-NEXT: @.cuda.binary_handle = internal global ptr null

// CUDA: @llvm.global_ctors = appending global [1 x { i32, ptr, ptr }] [{ i32, ptr, ptr } { i32 1, ptr @.cuda.fatbin_reg, ptr null }]

//      CUDA: define internal void @.cuda.fatbin_reg() section ".text.startup" {
// CUDA-NEXT: entry:
// CUDA-NEXT:   %0 = call ptr @__cudaRegisterFatBinary(ptr @.fatbin_wrapper)
// CUDA-NEXT:   store ptr %0, ptr @.cuda.binary_handle, align 8
// CUDA-NEXT:   call void @.cuda.globals_reg(ptr %0)
// CUDA-NEXT:   call void @__cudaRegisterFatBinaryEnd(ptr %0)
// CUDA-NEXT:   %1 = call i32 @atexit(ptr @.cuda.fatbin_unreg)
// CUDA-NEXT:   ret void
// CUDA-NEXT: }

//      CUDA: define internal void @.cuda.fatbin_unreg() section ".text.startup" {
// CUDA-NEXT: entry:
// CUDA-NEXT:   %0 = load ptr, ptr @.cuda.binary_handle, align 8
// CUDA-NEXT:   call void @__cudaUnregisterFatBinary(ptr %0)
// CUDA-NEXT:   ret void
// CUDA-NEXT: }

// CUDA: define internal void @.cuda.globals_reg(ptr %0) section ".text.startup" {
// CUDA-NEXT: entry:
// CUDA-NEXT:   br i1 icmp ne (ptr @__start_cuda_offloading_entries, ptr @__stop_cuda_offloading_entries), label %while.entry, label %while.end

//      CUDA: while.entry:
// CUDA-NEXT:   %entry1 = phi ptr [ @__start_cuda_offloading_entries, %entry ], [ %11, %if.end ]
// CUDA-NEXT:   %1 = getelementptr inbounds %struct.__tgt_offload_entry, ptr %entry1, i64 0, i32 0
// CUDA-NEXT:   %addr = load ptr, ptr %1, align 8
// CUDA-NEXT:   %2 = getelementptr inbounds %struct.__tgt_offload_entry, ptr %entry1, i64 0, i32 1
// CUDA-NEXT:   %name = load ptr, ptr %2, align 8
// CUDA-NEXT:   %3 = getelementptr inbounds %struct.__tgt_offload_entry, ptr %entry1, i64 0, i32 2
// CUDA-NEXT:   %size = load i64, ptr %3, align 4
// CUDA-NEXT:   %4 = getelementptr inbounds %struct.__tgt_offload_entry, ptr %entry1, i64 0, i32 3
// CUDA-NEXT:   %flags = load i32, ptr %4, align 4
// CUDA-NEXT:   %5 = getelementptr inbounds %struct.__tgt_offload_entry, ptr %entry1, i64 0, i32 4
// CUDA-NEXT:   %textype = load i32, ptr %5, align 4
// CUDA-NEXT:   %type = and i32 %flags, 7
// CUDA-NEXT:   %6 = and i32 %flags, 8
// CUDA-NEXT:   %extern = lshr i32 %6, 3
// CUDA-NEXT:   %7 = and i32 %flags, 16
// CUDA-NEXT:   %constant = lshr i32 %7, 4
// CUDA-NEXT:   %8 = and i32 %flags, 32
// CUDA-NEXT:   %normalized = lshr i32 %8, 5
// CUDA-NEXT:   %9 = icmp eq i64 %size, 0
// CUDA-NEXT:   br i1 %9, label %if.then, label %if.else

//      CUDA: if.then:
// CUDA-NEXT:   %10 = call i32 @__cudaRegisterFunction(ptr %0, ptr %addr, ptr %name, ptr %name, i32 -1, ptr null, ptr null, ptr null, ptr null, ptr null)
// CUDA-NEXT:   br label %if.end

//      CUDA: if.else:
// CUDA-NEXT:   switch i32 %type, label %if.end [
// CUDA-NEXT:     i32 0, label %sw.global
// CUDA-NEXT:     i32 1, label %sw.managed
// CUDA-NEXT:     i32 2, label %sw.surface
// CUDA-NEXT:     i32 3, label %sw.texture
// CUDA-NEXT:   ]

//      CUDA: sw.global:
// CUDA-NEXT:   call void @__cudaRegisterVar(ptr %0, ptr %addr, ptr %name, ptr %name, i32 %extern, i64 %size, i32 %constant, i32 0)
// CUDA-NEXT:   br label %if.end

//      CUDA: sw.managed:
// CUDA-NEXT:   br label %if.end

//      CUDA: sw.surface:
// CUDA-NEXT:   br label %if.end

//      CUDA: sw.texture:
// CUDA-NEXT:   br label %if.end

//      CUDA: if.end:
// CUDA-NEXT:   %11 = getelementptr inbounds %struct.__tgt_offload_entry, ptr %entry1, i64 1
// CUDA-NEXT:   %12 = icmp eq ptr %11, @__stop_cuda_offloading_entries
// CUDA-NEXT:   br i1 %12, label %while.end, label %while.entry

//      CUDA: while.end:
// CUDA-NEXT:   ret void
// CUDA-NEXT: }

// RUN: clang-offload-packager -o %t.out --image=file=%t.elf.o,kind=hip,triple=amdgcn-amd-amdhsa,arch=gfx908
// RUN: %clang -cc1 %s -triple x86_64-unknown-linux-gnu -emit-obj -o %t.o \
// RUN:   -fembed-offload-object=%t.out
// RUN: clang-linker-wrapper --print-wrapped-module --dry-run --host-triple=x86_64-unknown-linux-gnu \
// RUN:   --linker-path=/usr/bin/ld -- %t.o -o a.out 2>&1 | FileCheck %s --check-prefixes=HIP,HIP-ELF
// RUN: clang-linker-wrapper --print-wrapped-module --dry-run --host-triple=x86_64-unknown-windows-gnu \
// RUN:   --linker-path=/usr/bin/ld -- %t.o -o a.out 2>&1 | FileCheck %s --check-prefixes=HIP,HIP-COFF

//      HIP-ELF: @__start_hip_offloading_entries = external hidden constant [0 x %struct.__tgt_offload_entry]
// HIP-ELF-NEXT: @__stop_hip_offloading_entries = external hidden constant [0 x %struct.__tgt_offload_entry]
// HIP-ELF-NEXT: @__dummy.hip_offloading_entries = hidden constant [0 x %struct.__tgt_offload_entry] zeroinitializer, section "hip_offloading_entries"

//      HIP-COFF: @__start_hip_offloading_entries = hidden constant [0 x %struct.__tgt_offload_entry] zeroinitializer, section "hip_offloading_entries$OA"
// HIP-COFF-NEXT: @__stop_hip_offloading_entries = hidden constant [0 x %struct.__tgt_offload_entry] zeroinitializer, section "hip_offloading_entries$OZ"

//      HIP: @.fatbin_image = internal constant [0 x i8] zeroinitializer, section ".hip_fatbin"
// HIP-NEXT: @.fatbin_wrapper = internal constant %fatbin_wrapper { i32 1212764230, i32 1, ptr @.fatbin_image, ptr null }, section ".hipFatBinSegment", align 8
// HIP-NEXT: @.hip.binary_handle = internal global ptr null

// HIP: @llvm.global_ctors = appending global [1 x { i32, ptr, ptr }] [{ i32, ptr, ptr } { i32 1, ptr @.hip.fatbin_reg, ptr null }]

//      HIP: define internal void @.hip.fatbin_reg() section ".text.startup" {
// HIP-NEXT: entry:
// HIP-NEXT:   %0 = call ptr @__hipRegisterFatBinary(ptr @.fatbin_wrapper)
// HIP-NEXT:   store ptr %0, ptr @.hip.binary_handle, align 8
// HIP-NEXT:   call void @.hip.globals_reg(ptr %0)
// HIP-NEXT:   %1 = call i32 @atexit(ptr @.hip.fatbin_unreg)
// HIP-NEXT:   ret void
// HIP-NEXT: }

//      HIP: define internal void @.hip.fatbin_unreg() section ".text.startup" {
// HIP-NEXT: entry:
// HIP-NEXT:   %0 = load ptr, ptr @.hip.binary_handle, align 8
// HIP-NEXT:   call void @__hipUnregisterFatBinary(ptr %0)
// HIP-NEXT:   ret void
// HIP-NEXT: }

//      HIP: define internal void @.hip.globals_reg(ptr %0) section ".text.startup" {
// HIP-NEXT: entry:
// HIP-NEXT:   br i1 icmp ne (ptr @__start_hip_offloading_entries, ptr @__stop_hip_offloading_entries), label %while.entry, label %while.end

//      HIP: while.entry:
// HIP-NEXT:   %entry1 = phi ptr [ @__start_hip_offloading_entries, %entry ], [ %11, %if.end ]
// HIP-NEXT:   %1 = getelementptr inbounds %struct.__tgt_offload_entry, ptr %entry1, i64 0, i32 0
// HIP-NEXT:   %addr = load ptr, ptr %1, align 8
// HIP-NEXT:   %2 = getelementptr inbounds %struct.__tgt_offload_entry, ptr %entry1, i64 0, i32 1
// HIP-NEXT:   %name = load ptr, ptr %2, align 8
// HIP-NEXT:   %3 = getelementptr inbounds %struct.__tgt_offload_entry, ptr %entry1, i64 0, i32 2
// HIP-NEXT:   %size = load i64, ptr %3, align 4
// HIP-NEXT:   %4 = getelementptr inbounds %struct.__tgt_offload_entry, ptr %entry1, i64 0, i32 3
// HIP-NEXT:   %flags = load i32, ptr %4, align 4
// HIP-NEXT:   %5 = getelementptr inbounds %struct.__tgt_offload_entry, ptr %entry1, i64 0, i32 4
// HIP-NEXT:   %textype = load i32, ptr %5, align 4
// HIP-NEXT:   %type = and i32 %flags, 7
// HIP-NEXT:   %6 = and i32 %flags, 8
// HIP-NEXT:   %extern = lshr i32 %6, 3
// HIP-NEXT:   %7 = and i32 %flags, 16
// HIP-NEXT:   %constant = lshr i32 %7, 4
// HIP-NEXT:   %8 = and i32 %flags, 32
// HIP-NEXT:   %normalized = lshr i32 %8, 5
// HIP-NEXT:   %9 = icmp eq i64 %size, 0
// HIP-NEXT:   br i1 %9, label %if.then, label %if.else

//      HIP: if.then:
// HIP-NEXT:   %10 = call i32 @__hipRegisterFunction(ptr %0, ptr %addr, ptr %name, ptr %name, i32 -1, ptr null, ptr null, ptr null, ptr null, ptr null)
// HIP-NEXT:   br label %if.end

//      HIP: if.else:
// HIP-NEXT:   switch i32 %type, label %if.end [
// HIP-NEXT:     i32 0, label %sw.global
// HIP-NEXT:     i32 1, label %sw.managed
// HIP-NEXT:     i32 2, label %sw.surface
// HIP-NEXT:     i32 3, label %sw.texture
// HIP-NEXT:   ]

//      HIP: sw.global:
// HIP-NEXT:   call void @__hipRegisterVar(ptr %0, ptr %addr, ptr %name, ptr %name, i32 %extern, i64 %size, i32 %constant, i32 0)
// HIP-NEXT:   br label %if.end

//      HIP: sw.managed:
// HIP-NEXT:   br label %if.end

//      HIP: sw.surface:
// HIP-NEXT:   call void @__hipRegisterSurface(ptr %0, ptr %addr, ptr %name, ptr %name, i32 %textype, i32 %extern)
// HIP-NEXT:   br label %if.end

//      HIP: sw.texture:
// HIP-NEXT:   call void @__hipRegisterTexture(ptr %0, ptr %addr, ptr %name, ptr %name, i32 %textype, i32 %normalized, i32 %extern)
// HIP-NEXT:   br label %if.end

//      HIP: if.end:
// HIP-NEXT:   %11 = getelementptr inbounds %struct.__tgt_offload_entry, ptr %entry1, i64 1
// HIP-NEXT:   %12 = icmp eq ptr %11, @__stop_hip_offloading_entries
// HIP-NEXT:   br i1 %12, label %while.end, label %while.entry

//      HIP: while.end:
// HIP-NEXT:   ret void
// HIP-NEXT: }
