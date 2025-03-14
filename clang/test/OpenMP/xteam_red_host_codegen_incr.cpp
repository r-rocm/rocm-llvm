// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature --include-generated-funcs --replace-value-regex "__omp_offloading_[0-9a-z]+_[0-9a-z]+" "reduction_size[.].+[.]" "pl_cond[.].+[.|,]" --prefix-filecheck-ir-name _
// RUN: %clang_cc1 -fopenmp -x c++ -std=c++11 -triple x86_64-unknown-unknown -fopenmp-targets=amdgcn-amd-amdhsa -fopenmp-target-ignore-env-vars -fopenmp-assume-no-nested-parallelism -fopenmp-assume-no-thread-state -emit-llvm %s -o - | FileCheck %s
// expected-no-diagnostics

int main()
{
  int N = 100;
  int sum1 = 0;

#pragma omp target teams distribute parallel for reduction(+:sum1)
  for (int i=0; i<N; i=i+1) {
    ++sum1;
  }
}
// CHECK-LABEL: define {{[^@]+}}@main
// CHECK-SAME: () #[[ATTR0:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[RETVAL:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[N:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[SUM1:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[N_CASTED:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[DOTOFFLOAD_BASEPTRS:%.*]] = alloca [2 x ptr], align 8
// CHECK-NEXT:    [[DOTOFFLOAD_PTRS:%.*]] = alloca [2 x ptr], align 8
// CHECK-NEXT:    [[DOTOFFLOAD_MAPPERS:%.*]] = alloca [2 x ptr], align 8
// CHECK-NEXT:    [[TMP:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTCAPTURE_EXPR_:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTCAPTURE_EXPR_1:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[KERNEL_ARGS:%.*]] = alloca [[STRUCT___TGT_KERNEL_ARGUMENTS:%.*]], align 8
// CHECK-NEXT:    store i32 0, ptr [[RETVAL]], align 4
// CHECK-NEXT:    store i32 100, ptr [[N]], align 4
// CHECK-NEXT:    store i32 0, ptr [[SUM1]], align 4
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr [[N]], align 4
// CHECK-NEXT:    store i32 [[TMP0]], ptr [[N_CASTED]], align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i64, ptr [[N_CASTED]], align 8
// CHECK-NEXT:    [[TMP2:%.*]] = getelementptr inbounds [2 x ptr], ptr [[DOTOFFLOAD_BASEPTRS]], i32 0, i32 0
// CHECK-NEXT:    store i64 [[TMP1]], ptr [[TMP2]], align 8
// CHECK-NEXT:    [[TMP3:%.*]] = getelementptr inbounds [2 x ptr], ptr [[DOTOFFLOAD_PTRS]], i32 0, i32 0
// CHECK-NEXT:    store i64 [[TMP1]], ptr [[TMP3]], align 8
// CHECK-NEXT:    [[TMP4:%.*]] = getelementptr inbounds [2 x ptr], ptr [[DOTOFFLOAD_MAPPERS]], i64 0, i64 0
// CHECK-NEXT:    store ptr null, ptr [[TMP4]], align 8
// CHECK-NEXT:    [[TMP5:%.*]] = getelementptr inbounds [2 x ptr], ptr [[DOTOFFLOAD_BASEPTRS]], i32 0, i32 1
// CHECK-NEXT:    store ptr [[SUM1]], ptr [[TMP5]], align 8
// CHECK-NEXT:    [[TMP6:%.*]] = getelementptr inbounds [2 x ptr], ptr [[DOTOFFLOAD_PTRS]], i32 0, i32 1
// CHECK-NEXT:    store ptr [[SUM1]], ptr [[TMP6]], align 8
// CHECK-NEXT:    [[TMP7:%.*]] = getelementptr inbounds [2 x ptr], ptr [[DOTOFFLOAD_MAPPERS]], i64 0, i64 1
// CHECK-NEXT:    store ptr null, ptr [[TMP7]], align 8
// CHECK-NEXT:    [[TMP8:%.*]] = getelementptr inbounds [2 x ptr], ptr [[DOTOFFLOAD_BASEPTRS]], i32 0, i32 0
// CHECK-NEXT:    [[TMP9:%.*]] = getelementptr inbounds [2 x ptr], ptr [[DOTOFFLOAD_PTRS]], i32 0, i32 0
// CHECK-NEXT:    [[TMP10:%.*]] = load i32, ptr [[N]], align 4
// CHECK-NEXT:    store i32 [[TMP10]], ptr [[DOTCAPTURE_EXPR_]], align 4
// CHECK-NEXT:    [[TMP11:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_]], align 4
// CHECK-NEXT:    [[SUB:%.*]] = sub nsw i32 [[TMP11]], 0
// CHECK-NEXT:    [[DIV:%.*]] = sdiv i32 [[SUB]], 1
// CHECK-NEXT:    [[SUB2:%.*]] = sub nsw i32 [[DIV]], 1
// CHECK-NEXT:    store i32 [[SUB2]], ptr [[DOTCAPTURE_EXPR_1]], align 4
// CHECK-NEXT:    [[TMP12:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_1]], align 4
// CHECK-NEXT:    [[ADD:%.*]] = add nsw i32 [[TMP12]], 1
// CHECK-NEXT:    [[TMP13:%.*]] = zext i32 [[ADD]] to i64
// CHECK-NEXT:    [[TMP14:%.*]] = getelementptr inbounds [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 0
// CHECK-NEXT:    store i32 3, ptr [[TMP14]], align 4
// CHECK-NEXT:    [[TMP15:%.*]] = getelementptr inbounds [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 1
// CHECK-NEXT:    store i32 2, ptr [[TMP15]], align 4
// CHECK-NEXT:    [[TMP16:%.*]] = getelementptr inbounds [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 2
// CHECK-NEXT:    store ptr [[TMP8]], ptr [[TMP16]], align 8
// CHECK-NEXT:    [[TMP17:%.*]] = getelementptr inbounds [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 3
// CHECK-NEXT:    store ptr [[TMP9]], ptr [[TMP17]], align 8
// CHECK-NEXT:    [[TMP18:%.*]] = getelementptr inbounds [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 4
// CHECK-NEXT:    store ptr @.offload_sizes, ptr [[TMP18]], align 8
// CHECK-NEXT:    [[TMP19:%.*]] = getelementptr inbounds [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 5
// CHECK-NEXT:    store ptr @.offload_maptypes, ptr [[TMP19]], align 8
// CHECK-NEXT:    [[TMP20:%.*]] = getelementptr inbounds [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 6
// CHECK-NEXT:    store ptr null, ptr [[TMP20]], align 8
// CHECK-NEXT:    [[TMP21:%.*]] = getelementptr inbounds [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 7
// CHECK-NEXT:    store ptr null, ptr [[TMP21]], align 8
// CHECK-NEXT:    [[TMP22:%.*]] = getelementptr inbounds [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 8
// CHECK-NEXT:    store i64 [[TMP13]], ptr [[TMP22]], align 8
// CHECK-NEXT:    [[TMP23:%.*]] = getelementptr inbounds [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 9
// CHECK-NEXT:    store i64 0, ptr [[TMP23]], align 8
// CHECK-NEXT:    [[TMP24:%.*]] = getelementptr inbounds [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 10
// CHECK-NEXT:    store [3 x i32] zeroinitializer, ptr [[TMP24]], align 4
// CHECK-NEXT:    [[TMP25:%.*]] = getelementptr inbounds [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 11
// CHECK-NEXT:    store [3 x i32] zeroinitializer, ptr [[TMP25]], align 4
// CHECK-NEXT:    [[TMP26:%.*]] = getelementptr inbounds [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 12
// CHECK-NEXT:    store i32 0, ptr [[TMP26]], align 4
// CHECK-NEXT:    [[TMP27:%.*]] = call i32 @__tgt_target_kernel(ptr @[[GLOB4:[0-9]+]], i64 -1, i32 0, i32 0, ptr @.{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_main_l10.region_id, ptr [[KERNEL_ARGS]])
// CHECK-NEXT:    [[TMP28:%.*]] = icmp ne i32 [[TMP27]], 0
// CHECK-NEXT:    br i1 [[TMP28]], label [[OMP_OFFLOAD_FAILED:%.*]], label [[OMP_OFFLOAD_CONT:%.*]]
// CHECK:       omp_offload.failed:
// CHECK-NEXT:    call void @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_main_l10(i64 [[TMP1]], ptr [[SUM1]]) #[[ATTR2:[0-9]+]]
// CHECK-NEXT:    br label [[OMP_OFFLOAD_CONT]]
// CHECK:       omp_offload.cont:
// CHECK-NEXT:    [[TMP29:%.*]] = load i32, ptr [[RETVAL]], align 4
// CHECK-NEXT:    ret i32 [[TMP29]]
//
//
// CHECK-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_main_l10
// CHECK-SAME: (i64 noundef [[N:%.*]], ptr noundef nonnull align 4 dereferenceable(4) [[SUM1:%.*]]) #[[ATTR1:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[N_ADDR:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[SUM1_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[N_CASTED:%.*]] = alloca i64, align 8
// CHECK-NEXT:    store i64 [[N]], ptr [[N_ADDR]], align 8
// CHECK-NEXT:    store ptr [[SUM1]], ptr [[SUM1_ADDR]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[SUM1_ADDR]], align 8
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr [[N_ADDR]], align 4
// CHECK-NEXT:    store i32 [[TMP1]], ptr [[N_CASTED]], align 4
// CHECK-NEXT:    [[TMP2:%.*]] = load i64, ptr [[N_CASTED]], align 8
// CHECK-NEXT:    call void (ptr, i32, ptr, ...) @__kmpc_fork_teams(ptr @[[GLOB4]], i32 2, ptr @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_main_l10.omp_outlined, i64 [[TMP2]], ptr [[TMP0]])
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_main_l10.omp_outlined
// CHECK-SAME: (ptr noalias noundef [[DOTGLOBAL_TID_:%.*]], ptr noalias noundef [[DOTBOUND_TID_:%.*]], i64 noundef [[N:%.*]], ptr noundef nonnull align 4 dereferenceable(4) [[SUM1:%.*]]) #[[ATTR1]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[DOTGLOBAL_TID__ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[DOTBOUND_TID__ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[N_ADDR:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[SUM1_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[SUM11:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTOMP_IV:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[TMP:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTCAPTURE_EXPR_:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTCAPTURE_EXPR_2:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[I:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTOMP_COMB_LB:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTOMP_COMB_UB:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTOMP_STRIDE:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTOMP_IS_LAST:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[I4:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[N_CASTED:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[DOTOMP_REDUCTION_RED_LIST:%.*]] = alloca [1 x ptr], align 8
// CHECK-NEXT:    store ptr [[DOTGLOBAL_TID_]], ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK-NEXT:    store ptr [[DOTBOUND_TID_]], ptr [[DOTBOUND_TID__ADDR]], align 8
// CHECK-NEXT:    store i64 [[N]], ptr [[N_ADDR]], align 8
// CHECK-NEXT:    store ptr [[SUM1]], ptr [[SUM1_ADDR]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[SUM1_ADDR]], align 8
// CHECK-NEXT:    store i32 0, ptr [[SUM11]], align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr [[N_ADDR]], align 4
// CHECK-NEXT:    store i32 [[TMP1]], ptr [[DOTCAPTURE_EXPR_]], align 4
// CHECK-NEXT:    [[TMP2:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_]], align 4
// CHECK-NEXT:    [[SUB:%.*]] = sub nsw i32 [[TMP2]], 0
// CHECK-NEXT:    [[DIV:%.*]] = sdiv i32 [[SUB]], 1
// CHECK-NEXT:    [[SUB3:%.*]] = sub nsw i32 [[DIV]], 1
// CHECK-NEXT:    store i32 [[SUB3]], ptr [[DOTCAPTURE_EXPR_2]], align 4
// CHECK-NEXT:    store i32 0, ptr [[I]], align 4
// CHECK-NEXT:    [[TMP3:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_]], align 4
// CHECK-NEXT:    [[CMP:%.*]] = icmp slt i32 0, [[TMP3]]
// CHECK-NEXT:    br i1 [[CMP]], label [[OMP_PRECOND_THEN:%.*]], label [[OMP_PRECOND_END:%.*]]
// CHECK:       omp.precond.then:
// CHECK-NEXT:    store i32 0, ptr [[DOTOMP_COMB_LB]], align 4
// CHECK-NEXT:    [[TMP4:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_2]], align 4
// CHECK-NEXT:    store i32 [[TMP4]], ptr [[DOTOMP_COMB_UB]], align 4
// CHECK-NEXT:    store i32 1, ptr [[DOTOMP_STRIDE]], align 4
// CHECK-NEXT:    store i32 0, ptr [[DOTOMP_IS_LAST]], align 4
// CHECK-NEXT:    [[TMP5:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK-NEXT:    [[TMP6:%.*]] = load i32, ptr [[TMP5]], align 4
// CHECK-NEXT:    call void @__kmpc_for_static_init_4(ptr @[[GLOB1:[0-9]+]], i32 [[TMP6]], i32 92, ptr [[DOTOMP_IS_LAST]], ptr [[DOTOMP_COMB_LB]], ptr [[DOTOMP_COMB_UB]], ptr [[DOTOMP_STRIDE]], i32 1, i32 1)
// CHECK-NEXT:    [[TMP7:%.*]] = load i32, ptr [[DOTOMP_COMB_UB]], align 4
// CHECK-NEXT:    [[TMP8:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_2]], align 4
// CHECK-NEXT:    [[CMP5:%.*]] = icmp sgt i32 [[TMP7]], [[TMP8]]
// CHECK-NEXT:    br i1 [[CMP5]], label [[COND_TRUE:%.*]], label [[COND_FALSE:%.*]]
// CHECK:       cond.true:
// CHECK-NEXT:    [[TMP9:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_2]], align 4
// CHECK-NEXT:    br label [[COND_END:%.*]]
// CHECK:       cond.false:
// CHECK-NEXT:    [[TMP10:%.*]] = load i32, ptr [[DOTOMP_COMB_UB]], align 4
// CHECK-NEXT:    br label [[COND_END]]
// CHECK:       cond.end:
// CHECK-NEXT:    [[COND:%.*]] = phi i32 [ [[TMP9]], [[COND_TRUE]] ], [ [[TMP10]], [[COND_FALSE]] ]
// CHECK-NEXT:    store i32 [[COND]], ptr [[DOTOMP_COMB_UB]], align 4
// CHECK-NEXT:    [[TMP11:%.*]] = load i32, ptr [[DOTOMP_COMB_LB]], align 4
// CHECK-NEXT:    store i32 [[TMP11]], ptr [[DOTOMP_IV]], align 4
// CHECK-NEXT:    br label [[OMP_INNER_FOR_COND:%.*]]
// CHECK:       omp.inner.for.cond:
// CHECK-NEXT:    [[TMP12:%.*]] = load i32, ptr [[DOTOMP_IV]], align 4
// CHECK-NEXT:    [[TMP13:%.*]] = load i32, ptr [[DOTOMP_COMB_UB]], align 4
// CHECK-NEXT:    [[CMP6:%.*]] = icmp sle i32 [[TMP12]], [[TMP13]]
// CHECK-NEXT:    br i1 [[CMP6]], label [[OMP_INNER_FOR_BODY:%.*]], label [[OMP_INNER_FOR_END:%.*]]
// CHECK:       omp.inner.for.body:
// CHECK-NEXT:    [[TMP14:%.*]] = load i32, ptr [[DOTOMP_COMB_LB]], align 4
// CHECK-NEXT:    [[TMP15:%.*]] = zext i32 [[TMP14]] to i64
// CHECK-NEXT:    [[TMP16:%.*]] = load i32, ptr [[DOTOMP_COMB_UB]], align 4
// CHECK-NEXT:    [[TMP17:%.*]] = zext i32 [[TMP16]] to i64
// CHECK-NEXT:    [[TMP18:%.*]] = load i32, ptr [[N_ADDR]], align 4
// CHECK-NEXT:    store i32 [[TMP18]], ptr [[N_CASTED]], align 4
// CHECK-NEXT:    [[TMP19:%.*]] = load i64, ptr [[N_CASTED]], align 8
// CHECK-NEXT:    call void (ptr, i32, ptr, ...) @__kmpc_fork_call(ptr @[[GLOB4]], i32 4, ptr @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_main_l10.omp_outlined.omp_outlined, i64 [[TMP15]], i64 [[TMP17]], i64 [[TMP19]], ptr [[SUM11]])
// CHECK-NEXT:    br label [[OMP_INNER_FOR_INC:%.*]]
// CHECK:       omp.inner.for.inc:
// CHECK-NEXT:    [[TMP20:%.*]] = load i32, ptr [[DOTOMP_IV]], align 4
// CHECK-NEXT:    [[TMP21:%.*]] = load i32, ptr [[DOTOMP_STRIDE]], align 4
// CHECK-NEXT:    [[ADD:%.*]] = add nsw i32 [[TMP20]], [[TMP21]]
// CHECK-NEXT:    store i32 [[ADD]], ptr [[DOTOMP_IV]], align 4
// CHECK-NEXT:    br label [[OMP_INNER_FOR_COND]]
// CHECK:       omp.inner.for.end:
// CHECK-NEXT:    br label [[OMP_LOOP_EXIT:%.*]]
// CHECK:       omp.loop.exit:
// CHECK-NEXT:    [[TMP22:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK-NEXT:    [[TMP23:%.*]] = load i32, ptr [[TMP22]], align 4
// CHECK-NEXT:    call void @__kmpc_for_static_fini(ptr @[[GLOB1]], i32 [[TMP23]])
// CHECK-NEXT:    br label [[OMP_PRECOND_END]]
// CHECK:       omp.precond.end:
// CHECK-NEXT:    [[TMP24:%.*]] = getelementptr inbounds [1 x ptr], ptr [[DOTOMP_REDUCTION_RED_LIST]], i64 0, i64 0
// CHECK-NEXT:    store ptr [[SUM11]], ptr [[TMP24]], align 8
// CHECK-NEXT:    [[TMP25:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK-NEXT:    [[TMP26:%.*]] = load i32, ptr [[TMP25]], align 4
// CHECK-NEXT:    [[TMP27:%.*]] = call i32 @__kmpc_reduce_nowait(ptr @[[GLOB3:[0-9]+]], i32 [[TMP26]], i32 1, i64 8, ptr [[DOTOMP_REDUCTION_RED_LIST]], ptr @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_main_l10.omp_outlined.omp.reduction.reduction_func, ptr @.gomp_critical_user_.reduction.var)
// CHECK-NEXT:    switch i32 [[TMP27]], label [[DOTOMP_REDUCTION_DEFAULT:%.*]] [
// CHECK-NEXT:      i32 1, label [[DOTOMP_REDUCTION_CASE1:%.*]]
// CHECK-NEXT:      i32 2, label [[DOTOMP_REDUCTION_CASE2:%.*]]
// CHECK-NEXT:    ]
// CHECK:       .omp.reduction.case1:
// CHECK-NEXT:    [[TMP28:%.*]] = load i32, ptr [[TMP0]], align 4
// CHECK-NEXT:    [[TMP29:%.*]] = load i32, ptr [[SUM11]], align 4
// CHECK-NEXT:    [[ADD7:%.*]] = add nsw i32 [[TMP28]], [[TMP29]]
// CHECK-NEXT:    store i32 [[ADD7]], ptr [[TMP0]], align 4
// CHECK-NEXT:    call void @__kmpc_end_reduce_nowait(ptr @[[GLOB3]], i32 [[TMP26]], ptr @.gomp_critical_user_.reduction.var)
// CHECK-NEXT:    br label [[DOTOMP_REDUCTION_DEFAULT]]
// CHECK:       .omp.reduction.case2:
// CHECK-NEXT:    [[TMP30:%.*]] = load i32, ptr [[SUM11]], align 4
// CHECK-NEXT:    [[TMP31:%.*]] = atomicrmw add ptr [[TMP0]], i32 [[TMP30]] monotonic, align 4
// CHECK-NEXT:    br label [[DOTOMP_REDUCTION_DEFAULT]]
// CHECK:       .omp.reduction.default:
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_main_l10.omp_outlined.omp_outlined
// CHECK-SAME: (ptr noalias noundef [[DOTGLOBAL_TID_:%.*]], ptr noalias noundef [[DOTBOUND_TID_:%.*]], i64 noundef [[DOTPREVIOUS_LB_:%.*]], i64 noundef [[DOTPREVIOUS_UB_:%.*]], i64 noundef [[N:%.*]], ptr noundef nonnull align 4 dereferenceable(4) [[SUM1:%.*]]) #[[ATTR1]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[DOTGLOBAL_TID__ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[DOTBOUND_TID__ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[DOTPREVIOUS_LB__ADDR:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[DOTPREVIOUS_UB__ADDR:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[N_ADDR:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[SUM1_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[DOTOMP_IV:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[TMP:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTCAPTURE_EXPR_:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTCAPTURE_EXPR_1:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[I:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTOMP_LB:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTOMP_UB:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTOMP_STRIDE:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTOMP_IS_LAST:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[SUM14:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[I5:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTOMP_REDUCTION_RED_LIST:%.*]] = alloca [1 x ptr], align 8
// CHECK-NEXT:    store ptr [[DOTGLOBAL_TID_]], ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK-NEXT:    store ptr [[DOTBOUND_TID_]], ptr [[DOTBOUND_TID__ADDR]], align 8
// CHECK-NEXT:    store i64 [[DOTPREVIOUS_LB_]], ptr [[DOTPREVIOUS_LB__ADDR]], align 8
// CHECK-NEXT:    store i64 [[DOTPREVIOUS_UB_]], ptr [[DOTPREVIOUS_UB__ADDR]], align 8
// CHECK-NEXT:    store i64 [[N]], ptr [[N_ADDR]], align 8
// CHECK-NEXT:    store ptr [[SUM1]], ptr [[SUM1_ADDR]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[SUM1_ADDR]], align 8
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr [[N_ADDR]], align 4
// CHECK-NEXT:    store i32 [[TMP1]], ptr [[DOTCAPTURE_EXPR_]], align 4
// CHECK-NEXT:    [[TMP2:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_]], align 4
// CHECK-NEXT:    [[SUB:%.*]] = sub nsw i32 [[TMP2]], 0
// CHECK-NEXT:    [[DIV:%.*]] = sdiv i32 [[SUB]], 1
// CHECK-NEXT:    [[SUB2:%.*]] = sub nsw i32 [[DIV]], 1
// CHECK-NEXT:    store i32 [[SUB2]], ptr [[DOTCAPTURE_EXPR_1]], align 4
// CHECK-NEXT:    store i32 0, ptr [[I]], align 4
// CHECK-NEXT:    [[TMP3:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_]], align 4
// CHECK-NEXT:    [[CMP:%.*]] = icmp slt i32 0, [[TMP3]]
// CHECK-NEXT:    br i1 [[CMP]], label [[OMP_PRECOND_THEN:%.*]], label [[OMP_PRECOND_END:%.*]]
// CHECK:       omp.precond.then:
// CHECK-NEXT:    store i32 0, ptr [[DOTOMP_LB]], align 4
// CHECK-NEXT:    [[TMP4:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_1]], align 4
// CHECK-NEXT:    store i32 [[TMP4]], ptr [[DOTOMP_UB]], align 4
// CHECK-NEXT:    [[TMP5:%.*]] = load i64, ptr [[DOTPREVIOUS_LB__ADDR]], align 8
// CHECK-NEXT:    [[CONV:%.*]] = trunc i64 [[TMP5]] to i32
// CHECK-NEXT:    [[TMP6:%.*]] = load i64, ptr [[DOTPREVIOUS_UB__ADDR]], align 8
// CHECK-NEXT:    [[CONV3:%.*]] = trunc i64 [[TMP6]] to i32
// CHECK-NEXT:    store i32 [[CONV]], ptr [[DOTOMP_LB]], align 4
// CHECK-NEXT:    store i32 [[CONV3]], ptr [[DOTOMP_UB]], align 4
// CHECK-NEXT:    store i32 1, ptr [[DOTOMP_STRIDE]], align 4
// CHECK-NEXT:    store i32 0, ptr [[DOTOMP_IS_LAST]], align 4
// CHECK-NEXT:    store i32 0, ptr [[SUM14]], align 4
// CHECK-NEXT:    [[TMP7:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK-NEXT:    [[TMP8:%.*]] = load i32, ptr [[TMP7]], align 4
// CHECK-NEXT:    call void @__kmpc_for_static_init_4(ptr @[[GLOB2:[0-9]+]], i32 [[TMP8]], i32 34, ptr [[DOTOMP_IS_LAST]], ptr [[DOTOMP_LB]], ptr [[DOTOMP_UB]], ptr [[DOTOMP_STRIDE]], i32 1, i32 1)
// CHECK-NEXT:    [[TMP9:%.*]] = load i32, ptr [[DOTOMP_UB]], align 4
// CHECK-NEXT:    [[TMP10:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_1]], align 4
// CHECK-NEXT:    [[CMP6:%.*]] = icmp sgt i32 [[TMP9]], [[TMP10]]
// CHECK-NEXT:    br i1 [[CMP6]], label [[COND_TRUE:%.*]], label [[COND_FALSE:%.*]]
// CHECK:       cond.true:
// CHECK-NEXT:    [[TMP11:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_1]], align 4
// CHECK-NEXT:    br label [[COND_END:%.*]]
// CHECK:       cond.false:
// CHECK-NEXT:    [[TMP12:%.*]] = load i32, ptr [[DOTOMP_UB]], align 4
// CHECK-NEXT:    br label [[COND_END]]
// CHECK:       cond.end:
// CHECK-NEXT:    [[COND:%.*]] = phi i32 [ [[TMP11]], [[COND_TRUE]] ], [ [[TMP12]], [[COND_FALSE]] ]
// CHECK-NEXT:    store i32 [[COND]], ptr [[DOTOMP_UB]], align 4
// CHECK-NEXT:    [[TMP13:%.*]] = load i32, ptr [[DOTOMP_LB]], align 4
// CHECK-NEXT:    store i32 [[TMP13]], ptr [[DOTOMP_IV]], align 4
// CHECK-NEXT:    br label [[OMP_INNER_FOR_COND:%.*]]
// CHECK:       omp.inner.for.cond:
// CHECK-NEXT:    [[TMP14:%.*]] = load i32, ptr [[DOTOMP_IV]], align 4
// CHECK-NEXT:    [[TMP15:%.*]] = load i32, ptr [[DOTOMP_UB]], align 4
// CHECK-NEXT:    [[CMP7:%.*]] = icmp sle i32 [[TMP14]], [[TMP15]]
// CHECK-NEXT:    br i1 [[CMP7]], label [[OMP_INNER_FOR_BODY:%.*]], label [[OMP_INNER_FOR_END:%.*]]
// CHECK:       omp.inner.for.body:
// CHECK-NEXT:    [[TMP16:%.*]] = load i32, ptr [[DOTOMP_IV]], align 4
// CHECK-NEXT:    [[MUL:%.*]] = mul nsw i32 [[TMP16]], 1
// CHECK-NEXT:    [[ADD:%.*]] = add nsw i32 0, [[MUL]]
// CHECK-NEXT:    store i32 [[ADD]], ptr [[I5]], align 4
// CHECK-NEXT:    [[TMP17:%.*]] = load i32, ptr [[SUM14]], align 4
// CHECK-NEXT:    [[INC:%.*]] = add nsw i32 [[TMP17]], 1
// CHECK-NEXT:    store i32 [[INC]], ptr [[SUM14]], align 4
// CHECK-NEXT:    br label [[OMP_BODY_CONTINUE:%.*]]
// CHECK:       omp.body.continue:
// CHECK-NEXT:    br label [[OMP_INNER_FOR_INC:%.*]]
// CHECK:       omp.inner.for.inc:
// CHECK-NEXT:    [[TMP18:%.*]] = load i32, ptr [[DOTOMP_IV]], align 4
// CHECK-NEXT:    [[ADD8:%.*]] = add nsw i32 [[TMP18]], 1
// CHECK-NEXT:    store i32 [[ADD8]], ptr [[DOTOMP_IV]], align 4
// CHECK-NEXT:    br label [[OMP_INNER_FOR_COND]]
// CHECK:       omp.inner.for.end:
// CHECK-NEXT:    br label [[OMP_LOOP_EXIT:%.*]]
// CHECK:       omp.loop.exit:
// CHECK-NEXT:    [[TMP19:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK-NEXT:    [[TMP20:%.*]] = load i32, ptr [[TMP19]], align 4
// CHECK-NEXT:    call void @__kmpc_for_static_fini(ptr @[[GLOB1]], i32 [[TMP20]])
// CHECK-NEXT:    [[TMP21:%.*]] = getelementptr inbounds [1 x ptr], ptr [[DOTOMP_REDUCTION_RED_LIST]], i64 0, i64 0
// CHECK-NEXT:    store ptr [[SUM14]], ptr [[TMP21]], align 8
// CHECK-NEXT:    [[TMP22:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK-NEXT:    [[TMP23:%.*]] = load i32, ptr [[TMP22]], align 4
// CHECK-NEXT:    [[TMP24:%.*]] = call i32 @__kmpc_reduce_nowait(ptr @[[GLOB3]], i32 [[TMP23]], i32 1, i64 8, ptr [[DOTOMP_REDUCTION_RED_LIST]], ptr @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_main_l10.omp_outlined.omp_outlined.omp.reduction.reduction_func, ptr @.gomp_critical_user_.reduction.var)
// CHECK-NEXT:    switch i32 [[TMP24]], label [[DOTOMP_REDUCTION_DEFAULT:%.*]] [
// CHECK-NEXT:      i32 1, label [[DOTOMP_REDUCTION_CASE1:%.*]]
// CHECK-NEXT:      i32 2, label [[DOTOMP_REDUCTION_CASE2:%.*]]
// CHECK-NEXT:    ]
// CHECK:       .omp.reduction.case1:
// CHECK-NEXT:    [[TMP25:%.*]] = load i32, ptr [[TMP0]], align 4
// CHECK-NEXT:    [[TMP26:%.*]] = load i32, ptr [[SUM14]], align 4
// CHECK-NEXT:    [[ADD9:%.*]] = add nsw i32 [[TMP25]], [[TMP26]]
// CHECK-NEXT:    store i32 [[ADD9]], ptr [[TMP0]], align 4
// CHECK-NEXT:    call void @__kmpc_end_reduce_nowait(ptr @[[GLOB3]], i32 [[TMP23]], ptr @.gomp_critical_user_.reduction.var)
// CHECK-NEXT:    br label [[DOTOMP_REDUCTION_DEFAULT]]
// CHECK:       .omp.reduction.case2:
// CHECK-NEXT:    [[TMP27:%.*]] = load i32, ptr [[SUM14]], align 4
// CHECK-NEXT:    [[TMP28:%.*]] = atomicrmw add ptr [[TMP0]], i32 [[TMP27]] monotonic, align 4
// CHECK-NEXT:    br label [[DOTOMP_REDUCTION_DEFAULT]]
// CHECK:       .omp.reduction.default:
// CHECK-NEXT:    br label [[OMP_PRECOND_END]]
// CHECK:       omp.precond.end:
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_main_l10.omp_outlined.omp_outlined.omp.reduction.reduction_func
// CHECK-SAME: (ptr noundef [[TMP0:%.*]], ptr noundef [[TMP1:%.*]]) #[[ATTR3:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[DOTADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[DOTADDR1:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    store ptr [[TMP0]], ptr [[DOTADDR]], align 8
// CHECK-NEXT:    store ptr [[TMP1]], ptr [[DOTADDR1]], align 8
// CHECK-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[DOTADDR]], align 8
// CHECK-NEXT:    [[TMP3:%.*]] = load ptr, ptr [[DOTADDR1]], align 8
// CHECK-NEXT:    [[TMP4:%.*]] = getelementptr inbounds [1 x ptr], ptr [[TMP3]], i64 0, i64 0
// CHECK-NEXT:    [[TMP5:%.*]] = load ptr, ptr [[TMP4]], align 8
// CHECK-NEXT:    [[TMP6:%.*]] = getelementptr inbounds [1 x ptr], ptr [[TMP2]], i64 0, i64 0
// CHECK-NEXT:    [[TMP7:%.*]] = load ptr, ptr [[TMP6]], align 8
// CHECK-NEXT:    [[TMP8:%.*]] = load i32, ptr [[TMP7]], align 4
// CHECK-NEXT:    [[TMP9:%.*]] = load i32, ptr [[TMP5]], align 4
// CHECK-NEXT:    [[ADD:%.*]] = add nsw i32 [[TMP8]], [[TMP9]]
// CHECK-NEXT:    store i32 [[ADD]], ptr [[TMP7]], align 4
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_main_l10.omp_outlined.omp.reduction.reduction_func
// CHECK-SAME: (ptr noundef [[TMP0:%.*]], ptr noundef [[TMP1:%.*]]) #[[ATTR3]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[DOTADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[DOTADDR1:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    store ptr [[TMP0]], ptr [[DOTADDR]], align 8
// CHECK-NEXT:    store ptr [[TMP1]], ptr [[DOTADDR1]], align 8
// CHECK-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[DOTADDR]], align 8
// CHECK-NEXT:    [[TMP3:%.*]] = load ptr, ptr [[DOTADDR1]], align 8
// CHECK-NEXT:    [[TMP4:%.*]] = getelementptr inbounds [1 x ptr], ptr [[TMP3]], i64 0, i64 0
// CHECK-NEXT:    [[TMP5:%.*]] = load ptr, ptr [[TMP4]], align 8
// CHECK-NEXT:    [[TMP6:%.*]] = getelementptr inbounds [1 x ptr], ptr [[TMP2]], i64 0, i64 0
// CHECK-NEXT:    [[TMP7:%.*]] = load ptr, ptr [[TMP6]], align 8
// CHECK-NEXT:    [[TMP8:%.*]] = load i32, ptr [[TMP7]], align 4
// CHECK-NEXT:    [[TMP9:%.*]] = load i32, ptr [[TMP5]], align 4
// CHECK-NEXT:    [[ADD:%.*]] = add nsw i32 [[TMP8]], [[TMP9]]
// CHECK-NEXT:    store i32 [[ADD]], ptr [[TMP7]], align 4
// CHECK-NEXT:    ret void
//
