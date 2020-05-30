//===- XtensaCallingConv.td - Xtensa calling Conventions -*- tablegen -*---===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// This describes the calling conventions for Xtensa.
//===----------------------------------------------------------------------===//

// Convention for returning values

def RetCC_Xtensa : CallingConv<[
  // i32 are returned in registers AR2, AR3, AR4, AR5
  CCIfType<[i32], CCAssignToReg<[AR0, AR1, AR2, AR3]>>,

  // stack slot size and alignment for integral types
  CCIfType<[i32], CCAssignToStack<4, 4>>
]>;

//------------------------------------------------------------------------------
// Calling convention for the Window-ABI
//
// The convention provides information for integral data types with sizes
// up to 4-bytes. When passing in registers i8/i16 values get promoted to
// i32 and i64 represented as a i32 pair
//
// The Window-ABI does not provide a static chain register, instead it is
// packed onto the stack just below the caller's frame

def Window_CC_Xtensa : CallingConv<[
  // promote i8/i16 arguments to i32
  CCIfType<[i8, i16], CCPromoteToType<i32>>,

  // 6 argument registers, each for arguments up to 4-bytes
  CCIfType<[i32], CCAssignToReg<[AR2, AR3, AR4, AR5, AR6, AR7]>>,

  // if on stack, integral types up to 4 bytes require 4
  // bytes and are 4-byte aligned
  CCIfType<[i32], CCAssignToStack<4, 4>>

  // even though represented by a i32 bit pair, the long long
  // values need to be aligned properly
  CCIfType<[f64], CCAssignToStack<8, 8>>
]>;

//------------------------------------------------------------------------------
// Calling convention for the Call0-ABI
//
// Difference to the Window-ABI is the static chain argument register and
// the availability of the explicit frame pointer register

def Call0_CC_Xtensa : CallingConv<[
  // promote i8/i16 arguments to i32
  CCIfType<[i8, i16], CCPromoteToType<i32>>,
  
  // 6 argument registers, each for arguments up to 4-bytes
  CCIfType<[i32], CCAssignToReg<[AR2, AR3, AR4, AR5, AR6, AR7]>>,

  // static chain is passed in AR8
  CCIfNest<CCAssignToReg<[AR8]>>,
 
  // if on stack, integral types up to 4 bytes require 4
  // bytes and are 4-byte aligned
  CCIfType<[i32], CCAssignToStack<4, 4>>

  // even though represented by a i32 bit pair, the long long
  // values need to be aligned properly
  CCIfType<[f64], CCAssignToStack<8, 8>>
]>;

