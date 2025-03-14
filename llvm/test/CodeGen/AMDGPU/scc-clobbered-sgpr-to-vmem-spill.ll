; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py UTC_ARGS: --version 2
; RUN: llc -mtriple=amdgcn--amdhsa -mcpu=gfx900 -verify-machineinstrs < %s | FileCheck %s

; This was a negative test to catch an extreme case when all options are exhausted
; while trying to spill SGPRs to memory. After we enabled SGPR spills into virtual VGPRs
; the edge case won't arise and the test would always compile.

define amdgpu_kernel void @kernel0(ptr addrspace(1) %out, i32 %in) #1 {
; CHECK-LABEL: kernel0:
; CHECK:       ; %bb.0:
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; def s[2:3]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    ; implicit-def: $vgpr22 : SGPR spill to VGPR lane
; CHECK-NEXT:    s_load_dword s0, s[4:5], 0x8
; CHECK-NEXT:    v_writelane_b32 v22, s2, 0
; CHECK-NEXT:    v_writelane_b32 v22, s3, 1
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; def s[4:7]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_writelane_b32 v22, s4, 2
; CHECK-NEXT:    v_writelane_b32 v22, s5, 3
; CHECK-NEXT:    v_writelane_b32 v22, s6, 4
; CHECK-NEXT:    v_writelane_b32 v22, s7, 5
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; def s[4:11]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_writelane_b32 v22, s4, 6
; CHECK-NEXT:    v_writelane_b32 v22, s5, 7
; CHECK-NEXT:    v_writelane_b32 v22, s6, 8
; CHECK-NEXT:    v_writelane_b32 v22, s7, 9
; CHECK-NEXT:    v_writelane_b32 v22, s8, 10
; CHECK-NEXT:    v_writelane_b32 v22, s9, 11
; CHECK-NEXT:    v_writelane_b32 v22, s10, 12
; CHECK-NEXT:    v_writelane_b32 v22, s11, 13
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; def s[4:19]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_writelane_b32 v22, s4, 14
; CHECK-NEXT:    v_writelane_b32 v22, s5, 15
; CHECK-NEXT:    v_writelane_b32 v22, s6, 16
; CHECK-NEXT:    v_writelane_b32 v22, s7, 17
; CHECK-NEXT:    v_writelane_b32 v22, s8, 18
; CHECK-NEXT:    v_writelane_b32 v22, s9, 19
; CHECK-NEXT:    v_writelane_b32 v22, s10, 20
; CHECK-NEXT:    v_writelane_b32 v22, s11, 21
; CHECK-NEXT:    v_writelane_b32 v22, s12, 22
; CHECK-NEXT:    v_writelane_b32 v22, s13, 23
; CHECK-NEXT:    v_writelane_b32 v22, s14, 24
; CHECK-NEXT:    v_writelane_b32 v22, s15, 25
; CHECK-NEXT:    v_writelane_b32 v22, s16, 26
; CHECK-NEXT:    v_writelane_b32 v22, s17, 27
; CHECK-NEXT:    v_writelane_b32 v22, s18, 28
; CHECK-NEXT:    v_writelane_b32 v22, s19, 29
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; def s[42:43]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; def s[52:55]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; def s[4:11]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_writelane_b32 v22, s4, 30
; CHECK-NEXT:    v_writelane_b32 v22, s5, 31
; CHECK-NEXT:    v_writelane_b32 v22, s6, 32
; CHECK-NEXT:    v_writelane_b32 v22, s7, 33
; CHECK-NEXT:    v_writelane_b32 v22, s8, 34
; CHECK-NEXT:    v_writelane_b32 v22, s9, 35
; CHECK-NEXT:    v_writelane_b32 v22, s10, 36
; CHECK-NEXT:    v_writelane_b32 v22, s11, 37
; CHECK-NEXT:    s_waitcnt lgkmcnt(0)
; CHECK-NEXT:    s_cmp_lg_u32 s0, 0
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; def s[16:31]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; def s[40:41]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; def s[36:39]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; def s[44:51]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; def s[0:15]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_writelane_b32 v22, s0, 38
; CHECK-NEXT:    v_writelane_b32 v22, s1, 39
; CHECK-NEXT:    v_writelane_b32 v22, s2, 40
; CHECK-NEXT:    v_writelane_b32 v22, s3, 41
; CHECK-NEXT:    v_writelane_b32 v22, s4, 42
; CHECK-NEXT:    v_writelane_b32 v22, s5, 43
; CHECK-NEXT:    v_writelane_b32 v22, s6, 44
; CHECK-NEXT:    v_writelane_b32 v22, s7, 45
; CHECK-NEXT:    v_writelane_b32 v22, s8, 46
; CHECK-NEXT:    v_writelane_b32 v22, s9, 47
; CHECK-NEXT:    v_writelane_b32 v22, s10, 48
; CHECK-NEXT:    v_writelane_b32 v22, s11, 49
; CHECK-NEXT:    v_writelane_b32 v22, s12, 50
; CHECK-NEXT:    v_writelane_b32 v22, s13, 51
; CHECK-NEXT:    v_writelane_b32 v22, s14, 52
; CHECK-NEXT:    v_writelane_b32 v22, s15, 53
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; def s[34:35]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; def s[0:3]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_writelane_b32 v22, s0, 54
; CHECK-NEXT:    v_writelane_b32 v22, s1, 55
; CHECK-NEXT:    v_writelane_b32 v22, s2, 56
; CHECK-NEXT:    v_writelane_b32 v22, s3, 57
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; def s[0:7]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_writelane_b32 v22, s0, 58
; CHECK-NEXT:    v_writelane_b32 v22, s1, 59
; CHECK-NEXT:    v_writelane_b32 v22, s2, 60
; CHECK-NEXT:    ; implicit-def: $vgpr23 : SGPR spill to VGPR lane
; CHECK-NEXT:    v_writelane_b32 v22, s3, 61
; CHECK-NEXT:    v_writelane_b32 v22, s4, 62
; CHECK-NEXT:    v_writelane_b32 v23, s6, 0
; CHECK-NEXT:    v_writelane_b32 v22, s5, 63
; CHECK-NEXT:    v_writelane_b32 v23, s7, 1
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; def s[0:15]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_writelane_b32 v23, s0, 2
; CHECK-NEXT:    v_writelane_b32 v23, s1, 3
; CHECK-NEXT:    v_writelane_b32 v23, s2, 4
; CHECK-NEXT:    v_writelane_b32 v23, s3, 5
; CHECK-NEXT:    v_writelane_b32 v23, s4, 6
; CHECK-NEXT:    v_writelane_b32 v23, s5, 7
; CHECK-NEXT:    v_writelane_b32 v23, s6, 8
; CHECK-NEXT:    v_writelane_b32 v23, s7, 9
; CHECK-NEXT:    v_writelane_b32 v23, s8, 10
; CHECK-NEXT:    v_writelane_b32 v23, s9, 11
; CHECK-NEXT:    v_writelane_b32 v23, s10, 12
; CHECK-NEXT:    v_writelane_b32 v23, s11, 13
; CHECK-NEXT:    v_writelane_b32 v23, s12, 14
; CHECK-NEXT:    v_writelane_b32 v23, s13, 15
; CHECK-NEXT:    v_writelane_b32 v23, s14, 16
; CHECK-NEXT:    v_writelane_b32 v23, s15, 17
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; def s[0:1]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_writelane_b32 v23, s0, 18
; CHECK-NEXT:    v_writelane_b32 v23, s1, 19
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; def s[0:3]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_writelane_b32 v23, s0, 20
; CHECK-NEXT:    v_writelane_b32 v23, s1, 21
; CHECK-NEXT:    v_writelane_b32 v23, s2, 22
; CHECK-NEXT:    v_writelane_b32 v23, s3, 23
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; def s[0:7]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_writelane_b32 v23, s0, 24
; CHECK-NEXT:    v_writelane_b32 v23, s1, 25
; CHECK-NEXT:    v_writelane_b32 v23, s2, 26
; CHECK-NEXT:    v_writelane_b32 v23, s3, 27
; CHECK-NEXT:    v_writelane_b32 v23, s4, 28
; CHECK-NEXT:    v_writelane_b32 v23, s5, 29
; CHECK-NEXT:    v_writelane_b32 v23, s6, 30
; CHECK-NEXT:    v_writelane_b32 v23, s7, 31
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; def s[0:15]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_writelane_b32 v23, s0, 32
; CHECK-NEXT:    v_writelane_b32 v23, s1, 33
; CHECK-NEXT:    v_writelane_b32 v23, s2, 34
; CHECK-NEXT:    v_writelane_b32 v23, s3, 35
; CHECK-NEXT:    v_writelane_b32 v23, s4, 36
; CHECK-NEXT:    v_writelane_b32 v23, s5, 37
; CHECK-NEXT:    v_writelane_b32 v23, s6, 38
; CHECK-NEXT:    v_writelane_b32 v23, s7, 39
; CHECK-NEXT:    v_writelane_b32 v23, s8, 40
; CHECK-NEXT:    v_writelane_b32 v23, s9, 41
; CHECK-NEXT:    v_writelane_b32 v23, s10, 42
; CHECK-NEXT:    v_writelane_b32 v23, s11, 43
; CHECK-NEXT:    v_writelane_b32 v23, s12, 44
; CHECK-NEXT:    v_writelane_b32 v23, s13, 45
; CHECK-NEXT:    v_writelane_b32 v23, s14, 46
; CHECK-NEXT:    v_writelane_b32 v23, s15, 47
; CHECK-NEXT:    s_cbranch_scc0 .LBB0_2
; CHECK-NEXT:  ; %bb.1: ; %ret
; CHECK-NEXT:    s_endpgm
; CHECK-NEXT:  .LBB0_2: ; %bb0
; CHECK-NEXT:    v_readlane_b32 s0, v22, 0
; CHECK-NEXT:    v_readlane_b32 s1, v22, 1
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; use s[0:1]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_readlane_b32 s0, v22, 2
; CHECK-NEXT:    v_readlane_b32 s1, v22, 3
; CHECK-NEXT:    v_readlane_b32 s2, v22, 4
; CHECK-NEXT:    v_readlane_b32 s3, v22, 5
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; use s[0:3]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_readlane_b32 s0, v22, 6
; CHECK-NEXT:    v_readlane_b32 s1, v22, 7
; CHECK-NEXT:    v_readlane_b32 s2, v22, 8
; CHECK-NEXT:    v_readlane_b32 s3, v22, 9
; CHECK-NEXT:    v_readlane_b32 s4, v22, 10
; CHECK-NEXT:    v_readlane_b32 s5, v22, 11
; CHECK-NEXT:    v_readlane_b32 s6, v22, 12
; CHECK-NEXT:    v_readlane_b32 s7, v22, 13
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; use s[0:7]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_readlane_b32 s0, v22, 14
; CHECK-NEXT:    v_readlane_b32 s1, v22, 15
; CHECK-NEXT:    v_readlane_b32 s2, v22, 16
; CHECK-NEXT:    v_readlane_b32 s3, v22, 17
; CHECK-NEXT:    v_readlane_b32 s4, v22, 18
; CHECK-NEXT:    v_readlane_b32 s5, v22, 19
; CHECK-NEXT:    v_readlane_b32 s6, v22, 20
; CHECK-NEXT:    v_readlane_b32 s7, v22, 21
; CHECK-NEXT:    v_readlane_b32 s8, v22, 22
; CHECK-NEXT:    v_readlane_b32 s9, v22, 23
; CHECK-NEXT:    v_readlane_b32 s10, v22, 24
; CHECK-NEXT:    v_readlane_b32 s11, v22, 25
; CHECK-NEXT:    v_readlane_b32 s12, v22, 26
; CHECK-NEXT:    v_readlane_b32 s13, v22, 27
; CHECK-NEXT:    v_readlane_b32 s14, v22, 28
; CHECK-NEXT:    v_readlane_b32 s15, v22, 29
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; use s[0:15]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_readlane_b32 s0, v22, 30
; CHECK-NEXT:    v_readlane_b32 s1, v22, 31
; CHECK-NEXT:    v_readlane_b32 s2, v22, 32
; CHECK-NEXT:    v_readlane_b32 s3, v22, 33
; CHECK-NEXT:    v_readlane_b32 s4, v22, 34
; CHECK-NEXT:    v_readlane_b32 s5, v22, 35
; CHECK-NEXT:    v_readlane_b32 s6, v22, 36
; CHECK-NEXT:    v_readlane_b32 s7, v22, 37
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; use s[42:43]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; use s[52:55]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; use s[0:7]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_readlane_b32 s0, v22, 38
; CHECK-NEXT:    v_readlane_b32 s1, v22, 39
; CHECK-NEXT:    v_readlane_b32 s2, v22, 40
; CHECK-NEXT:    v_readlane_b32 s3, v22, 41
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; use s[16:31]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; use s[40:41]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; use s[36:39]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; use s[44:51]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_readlane_b32 s4, v22, 42
; CHECK-NEXT:    v_readlane_b32 s5, v22, 43
; CHECK-NEXT:    v_readlane_b32 s6, v22, 44
; CHECK-NEXT:    v_readlane_b32 s7, v22, 45
; CHECK-NEXT:    v_readlane_b32 s8, v22, 46
; CHECK-NEXT:    v_readlane_b32 s9, v22, 47
; CHECK-NEXT:    v_readlane_b32 s10, v22, 48
; CHECK-NEXT:    v_readlane_b32 s11, v22, 49
; CHECK-NEXT:    v_readlane_b32 s12, v22, 50
; CHECK-NEXT:    v_readlane_b32 s13, v22, 51
; CHECK-NEXT:    v_readlane_b32 s14, v22, 52
; CHECK-NEXT:    v_readlane_b32 s15, v22, 53
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; use s[0:15]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_readlane_b32 s0, v22, 54
; CHECK-NEXT:    v_readlane_b32 s1, v22, 55
; CHECK-NEXT:    v_readlane_b32 s2, v22, 56
; CHECK-NEXT:    v_readlane_b32 s3, v22, 57
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; use s[34:35]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; use s[0:3]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_readlane_b32 s0, v22, 58
; CHECK-NEXT:    v_readlane_b32 s1, v22, 59
; CHECK-NEXT:    v_readlane_b32 s2, v22, 60
; CHECK-NEXT:    v_readlane_b32 s3, v22, 61
; CHECK-NEXT:    v_readlane_b32 s4, v22, 62
; CHECK-NEXT:    v_readlane_b32 s5, v22, 63
; CHECK-NEXT:    v_readlane_b32 s6, v23, 0
; CHECK-NEXT:    v_readlane_b32 s7, v23, 1
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; use s[0:7]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_readlane_b32 s0, v23, 2
; CHECK-NEXT:    v_readlane_b32 s1, v23, 3
; CHECK-NEXT:    v_readlane_b32 s2, v23, 4
; CHECK-NEXT:    v_readlane_b32 s3, v23, 5
; CHECK-NEXT:    v_readlane_b32 s4, v23, 6
; CHECK-NEXT:    v_readlane_b32 s5, v23, 7
; CHECK-NEXT:    v_readlane_b32 s6, v23, 8
; CHECK-NEXT:    v_readlane_b32 s7, v23, 9
; CHECK-NEXT:    v_readlane_b32 s8, v23, 10
; CHECK-NEXT:    v_readlane_b32 s9, v23, 11
; CHECK-NEXT:    v_readlane_b32 s10, v23, 12
; CHECK-NEXT:    v_readlane_b32 s11, v23, 13
; CHECK-NEXT:    v_readlane_b32 s12, v23, 14
; CHECK-NEXT:    v_readlane_b32 s13, v23, 15
; CHECK-NEXT:    v_readlane_b32 s14, v23, 16
; CHECK-NEXT:    v_readlane_b32 s15, v23, 17
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; use s[0:15]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_readlane_b32 s0, v23, 18
; CHECK-NEXT:    v_readlane_b32 s1, v23, 19
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; use s[0:1]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_readlane_b32 s0, v23, 20
; CHECK-NEXT:    v_readlane_b32 s1, v23, 21
; CHECK-NEXT:    v_readlane_b32 s2, v23, 22
; CHECK-NEXT:    v_readlane_b32 s3, v23, 23
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; use s[0:3]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_readlane_b32 s0, v23, 24
; CHECK-NEXT:    v_readlane_b32 s1, v23, 25
; CHECK-NEXT:    v_readlane_b32 s2, v23, 26
; CHECK-NEXT:    v_readlane_b32 s3, v23, 27
; CHECK-NEXT:    v_readlane_b32 s4, v23, 28
; CHECK-NEXT:    v_readlane_b32 s5, v23, 29
; CHECK-NEXT:    v_readlane_b32 s6, v23, 30
; CHECK-NEXT:    v_readlane_b32 s7, v23, 31
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; use s[0:7]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    v_readlane_b32 s0, v23, 32
; CHECK-NEXT:    v_readlane_b32 s1, v23, 33
; CHECK-NEXT:    v_readlane_b32 s2, v23, 34
; CHECK-NEXT:    v_readlane_b32 s3, v23, 35
; CHECK-NEXT:    v_readlane_b32 s4, v23, 36
; CHECK-NEXT:    v_readlane_b32 s5, v23, 37
; CHECK-NEXT:    v_readlane_b32 s6, v23, 38
; CHECK-NEXT:    v_readlane_b32 s7, v23, 39
; CHECK-NEXT:    v_readlane_b32 s8, v23, 40
; CHECK-NEXT:    v_readlane_b32 s9, v23, 41
; CHECK-NEXT:    v_readlane_b32 s10, v23, 42
; CHECK-NEXT:    v_readlane_b32 s11, v23, 43
; CHECK-NEXT:    v_readlane_b32 s12, v23, 44
; CHECK-NEXT:    v_readlane_b32 s13, v23, 45
; CHECK-NEXT:    v_readlane_b32 s14, v23, 46
; CHECK-NEXT:    v_readlane_b32 s15, v23, 47
; CHECK-NEXT:    ;;#ASMSTART
; CHECK-NEXT:    ; use s[0:15]
; CHECK-NEXT:    ;;#ASMEND
; CHECK-NEXT:    s_endpgm
  call void asm sideeffect "", "~{v[0:7]}" () #0
  call void asm sideeffect "", "~{v[8:15]}" () #0
  call void asm sideeffect "", "~{v[16:19]}"() #0
  call void asm sideeffect "", "~{v[20:21]}"() #0

  %val0 = call <2 x i32> asm sideeffect "; def $0", "=s" () #0
  %val1 = call <4 x i32> asm sideeffect "; def $0", "=s" () #0
  %val2 = call <8 x i32> asm sideeffect "; def $0", "=s" () #0
  %val3 = call <16 x i32> asm sideeffect "; def $0", "=s" () #0
  %val4 = call <2 x i32> asm sideeffect "; def $0", "=s" () #0
  %val5 = call <4 x i32> asm sideeffect "; def $0", "=s" () #0
  %val6 = call <8 x i32> asm sideeffect "; def $0", "=s" () #0
  %val7 = call <16 x i32> asm sideeffect "; def $0", "=s" () #0
  %val8 = call <2 x i32> asm sideeffect "; def $0", "=s" () #0
  %val9 = call <4 x i32> asm sideeffect "; def $0", "=s" () #0
  %val10 = call <8 x i32> asm sideeffect "; def $0", "=s" () #0
  %val11 = call <16 x i32> asm sideeffect "; def $0", "=s" () #0
  %val12 = call <2 x i32> asm sideeffect "; def $0", "=s" () #0
  %val13 = call <4 x i32> asm sideeffect "; def $0", "=s" () #0
  %val14 = call <8 x i32> asm sideeffect "; def $0", "=s" () #0
  %val15 = call <16 x i32> asm sideeffect "; def $0", "=s" () #0
  %val16 = call <2 x i32> asm sideeffect "; def $0", "=s" () #0
  %val17 = call <4 x i32> asm sideeffect "; def $0", "=s" () #0
  %val18 = call <8 x i32> asm sideeffect "; def $0", "=s" () #0
  %val19 = call <16 x i32> asm sideeffect "; def $0", "=s" () #0
  %cmp = icmp eq i32 %in, 0
  br i1 %cmp, label %bb0, label %ret

bb0:
  call void asm sideeffect "; use $0", "s"(<2 x i32> %val0) #0
  call void asm sideeffect "; use $0", "s"(<4 x i32> %val1) #0
  call void asm sideeffect "; use $0", "s"(<8 x i32> %val2) #0
  call void asm sideeffect "; use $0", "s"(<16 x i32> %val3) #0
  call void asm sideeffect "; use $0", "s"(<2 x i32> %val4) #0
  call void asm sideeffect "; use $0", "s"(<4 x i32> %val5) #0
  call void asm sideeffect "; use $0", "s"(<8 x i32> %val6) #0
  call void asm sideeffect "; use $0", "s"(<16 x i32> %val7) #0
  call void asm sideeffect "; use $0", "s"(<2 x i32> %val8) #0
  call void asm sideeffect "; use $0", "s"(<4 x i32> %val9) #0
  call void asm sideeffect "; use $0", "s"(<8 x i32> %val10) #0
  call void asm sideeffect "; use $0", "s"(<16 x i32> %val11) #0
  call void asm sideeffect "; use $0", "s"(<2 x i32> %val12) #0
  call void asm sideeffect "; use $0", "s"(<4 x i32> %val13) #0
  call void asm sideeffect "; use $0", "s"(<8 x i32> %val14) #0
  call void asm sideeffect "; use $0", "s"(<16 x i32> %val15) #0
  call void asm sideeffect "; use $0", "s"(<2 x i32> %val16) #0
  call void asm sideeffect "; use $0", "s"(<4 x i32> %val17) #0
  call void asm sideeffect "; use $0", "s"(<8 x i32> %val18) #0
  call void asm sideeffect "; use $0", "s"(<16 x i32> %val19) #0
  br label %ret

ret:
  ret void
}

attributes #0 = { nounwind }
attributes #1 = { nounwind "amdgpu-waves-per-eu"="10,10" }
