; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py
; RUN: llc -mtriple=riscv32 -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32I

@addr = global i8* null

define void @test_blockaddress() nounwind {
; RV32I-LABEL: test_blockaddress:
; RV32I:       # %bb.0:
; RV32I-NEXT:    addi sp, sp, -16
; RV32I-NEXT:    sw ra, 12(sp)
; RV32I-NEXT:    lui a0, %hi(.Ltmp0)
; RV32I-NEXT:    addi a0, a0, %lo(.Ltmp0)
; RV32I-NEXT:    lui a1, %hi(addr)
; RV32I-NEXT:    sw a0, %lo(addr)(a1)
; RV32I-NEXT:    lw a0, %lo(addr)(a1)
; RV32I-NEXT:    jr a0
; RV32I-NEXT:  .Ltmp0: # Block address taken
; RV32I-NEXT:  .LBB0_1: # %block
; RV32I-NEXT:    lw ra, 12(sp)
; RV32I-NEXT:    addi sp, sp, 16
; RV32I-NEXT:    ret
  store volatile i8* blockaddress(@test_blockaddress, %block), i8** @addr
  %val = load volatile i8*, i8** @addr
  indirectbr i8* %val, [label %block]

block:
  ret void
}
