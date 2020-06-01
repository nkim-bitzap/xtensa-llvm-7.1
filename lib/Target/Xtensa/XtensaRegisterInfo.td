//===-- XtensaRegisterInfo.td - Xtensa Register defs -------*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//  Declarations that describe the Xtensa register file
//===----------------------------------------------------------------------===//

// Xtensa core ISA features 18 registers in total

class XtensaReg<string n> : Register<n> {
  field bits<5> Num;
  let Namespace = "Xtensa";
}

class Ri<bits<5> num, string n> : XtensaReg<n> {
  let Num = num;
}

class Unallocatable {
  bit isAllocatable = 0;
}

// return address register
def AR0 : Ri<0, "a0">, DwarfRegNum<[0]>;

// stack pointer
def AR1  : Ri<1, "a1">, DwarfRegNum<[1]>;

// argument registers
def AR2  : Ri<2, "a2">, DwarfRegNum<[2]>;
def AR3  : Ri<3, "a3">, DwarfRegNum<[3]>;
def AR4  : Ri<4, "a4">, DwarfRegNum<[4]>;
def AR5  : Ri<5, "a5">, DwarfRegNum<[5]>;
def AR6  : Ri<6, "a6">, DwarfRegNum<[6]>;

// callee's frame pointer for Window-ABI
def AR7  : Ri<7, "a7">, DwarfRegNum<[7]>;

// static chain register (Call0-ABI only)
def AR8  : Ri<8, "a8">, DwarfRegNum<[8]>;

// general purpose (Call0-ABI only)
def AR9  : Ri<9, "a9">, DwarfRegNum<[9]>;
def AR10 : Ri<10, "a10">, DwarfRegNum<[10]>;
def AR11 : Ri<11, "a11">, DwarfRegNum<[11]>;

// callee saved registers (Call0-ABI only)
def AR12 : Ri<12, "a12">, DwarfRegNum<[12]>;
def AR13 : Ri<13, "a13">, DwarfRegNum<[13]>;
def AR14 : Ri<14, "a14">, DwarfRegNum<[14]>;

// frame pointer, callee saved (Call0-ABI only)
def AR15 : Ri<15, "a15">, DwarfRegNum<[15]>;

def PC   : Ri<16, "pc">, DwarfRegNum<[16]>;
def SAR  : Ri<17, "pc">, DwarfRegNum<[17]>;

// Xtensa register classes. We use a convention here, register classes
// for the Window-ABI are prefixed by 'W' and those for the Call0-ABI
// by 'C'.

def WGP_Regs : RegisterClass<"Xtensa", [i32], 32,
  (add
    AR2, AR3, AR4, AR5, AR6, AR7)>;

// Stack pointer and return address are not allocatable in Window-ABI.
// The same applies to the program counter and the status register.

def WRA_Regs : RegisterClass<
  "Xtensa", [i32], 32, (add AR0)>, Unallocatable;

def WSP_Regs : RegisterClass<
  "Xtensa", [i32], 32, (add AR1)>, Unallocatable;

def WPC_Regs : RegisterClass<
  "Xtensa", [i32], 32, (add PC)>, Unallocatable;

def WSAR_Regs : RegisterClass<
  "Xtensa", [i32], 6, (add SAR)>, Unallocatable;

