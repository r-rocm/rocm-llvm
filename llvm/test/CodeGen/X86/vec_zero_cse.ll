; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py
; RUN: llc < %s -relocation-model=static -mtriple=i686-unknown -mattr=+mmx,+sse3   | FileCheck %s --check-prefix=X86
; RUN: llc < %s -relocation-model=static -mtriple=x86_64-unknown -mattr=+mmx,+sse3 | FileCheck %s --check-prefix=X64

; 64-bit stores here do not use MMX.

@M1 = external dso_local global <1 x i64>
@M2 = external dso_local global <2 x i32>

@S1 = external dso_local global <2 x i64>
@S2 = external dso_local global <4 x i32>

define void @test1() {
; X86-LABEL: test1:
; X86:       # %bb.0:
; X86-NEXT:    movl $0, M1+4
; X86-NEXT:    movl $0, M1
; X86-NEXT:    xorps %xmm0, %xmm0
; X86-NEXT:    movsd %xmm0, M2
; X86-NEXT:    retl
;
; X64-LABEL: test1:
; X64:       # %bb.0:
; X64-NEXT:    movq $0, M1(%rip)
; X64-NEXT:    movq $0, M2(%rip)
; X64-NEXT:    retq
  store <1 x i64> zeroinitializer, <1 x i64>* @M1
  store <2 x i32> zeroinitializer, <2 x i32>* @M2
  ret void
}

define void @test2() {
; X86-LABEL: test2:
; X86:       # %bb.0:
; X86-NEXT:    movl $-1, M1+4
; X86-NEXT:    movl $-1, M1
; X86-NEXT:    pcmpeqd %xmm0, %xmm0
; X86-NEXT:    movq %xmm0, M2
; X86-NEXT:    retl
;
; X64-LABEL: test2:
; X64:       # %bb.0:
; X64-NEXT:    movq $-1, M1(%rip)
; X64-NEXT:    movq $-1, M2(%rip)
; X64-NEXT:    retq
  store <1 x i64> < i64 -1 >, <1 x i64>* @M1
  store <2 x i32> < i32 -1, i32 -1 >, <2 x i32>* @M2
  ret void
}

define void @test3() {
; X86-LABEL: test3:
; X86:       # %bb.0:
; X86-NEXT:    xorps %xmm0, %xmm0
; X86-NEXT:    movaps %xmm0, S1
; X86-NEXT:    movaps %xmm0, S2
; X86-NEXT:    retl
;
; X64-LABEL: test3:
; X64:       # %bb.0:
; X64-NEXT:    xorps %xmm0, %xmm0
; X64-NEXT:    movaps %xmm0, S1(%rip)
; X64-NEXT:    movaps %xmm0, S2(%rip)
; X64-NEXT:    retq
  store <2 x i64> zeroinitializer, <2 x i64>* @S1
  store <4 x i32> zeroinitializer, <4 x i32>* @S2
  ret void
}

define void @test4() {
; X86-LABEL: test4:
; X86:       # %bb.0:
; X86-NEXT:    pcmpeqd %xmm0, %xmm0
; X86-NEXT:    movdqa %xmm0, S1
; X86-NEXT:    movdqa %xmm0, S2
; X86-NEXT:    retl
;
; X64-LABEL: test4:
; X64:       # %bb.0:
; X64-NEXT:    pcmpeqd %xmm0, %xmm0
; X64-NEXT:    movdqa %xmm0, S1(%rip)
; X64-NEXT:    movdqa %xmm0, S2(%rip)
; X64-NEXT:    retq
  store <2 x i64> < i64 -1, i64 -1>, <2 x i64>* @S1
  store <4 x i32> < i32 -1, i32 -1, i32 -1, i32 -1 >, <4 x i32>* @S2
  ret void
}
