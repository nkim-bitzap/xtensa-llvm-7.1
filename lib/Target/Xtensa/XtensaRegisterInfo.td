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

//------------------------------------------------------------------------------
// Xtensa core ISA features 18 registers in total, of which 16 are visible
// and can be allocated.
// 
//------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------
// General purpose/address registers
//------------------------------------------------------------------------------

def AR0 : Ri<0, "a0">, DwarfRegNum<[0]>;      // return address
def AR1  : Ri<1, "a1">, DwarfRegNum<[1]>;     // stack pointer
def AR2  : Ri<2, "a2">, DwarfRegNum<[2]>;     // argument #1
def AR3  : Ri<3, "a3">, DwarfRegNum<[3]>;     // argument #2
def AR4  : Ri<4, "a4">, DwarfRegNum<[4]>;     // argument #3
def AR5  : Ri<5, "a5">, DwarfRegNum<[5]>;     // argument #4
def AR6  : Ri<6, "a6">, DwarfRegNum<[6]>;     // argument #5
def AR7  : Ri<7, "a7">, DwarfRegNum<[7]>;     // argument #6
def AR8  : Ri<8, "a8">, DwarfRegNum<[8]>;     // static chain
def AR9  : Ri<9, "a9">, DwarfRegNum<[9]>;
def AR10 : Ri<10, "a10">, DwarfRegNum<[10]>;
def AR11 : Ri<11, "a11">, DwarfRegNum<[11]>;
def AR12 : Ri<12, "a12">, DwarfRegNum<[12]>;  // callee saved
def AR13 : Ri<13, "a13">, DwarfRegNum<[13]>;  // callee saved
def AR14 : Ri<14, "a14">, DwarfRegNum<[14]>;  // callee saved
def AR15 : Ri<15, "a15">, DwarfRegNum<[15]>;  // frame pointer
def PC   : Ri<16, "pc">, DwarfRegNum<[16]>;   // pc, invisible (?)
def SAR  : Ri<17, "pc">, DwarfRegNum<[17]>;   // status, invisible (?)

//------------------------------------------------------------------------------
// Optional, boolean registers 
//------------------------------------------------------------------------------

def BR0 : Ri<0, "b0">, DwarfRegNum<[18]>;
def BR1  : Ri<1, "b1">, DwarfRegNum<[19]>;
def BR2  : Ri<2, "b2">, DwarfRegNum<[20]>;
def BR3  : Ri<3, "b3">, DwarfRegNum<[21]>;
def BR4  : Ri<4, "b4">, DwarfRegNum<[22]>;
def BR5  : Ri<5, "b5">, DwarfRegNum<[23]>;
def BR6  : Ri<6, "b6">, DwarfRegNum<[24]>;
def BR7  : Ri<7, "b7">, DwarfRegNum<[25]>;
def BR8  : Ri<8, "b8">, DwarfRegNum<[26]>;
def BR9  : Ri<9, "b9">, DwarfRegNum<[27]>;
def BR10 : Ri<10, "b10">, DwarfRegNum<[28]>;
def BR11 : Ri<11, "b11">, DwarfRegNum<[29]>;
def BR12 : Ri<12, "b12">, DwarfRegNum<[30]>;
def BR13 : Ri<13, "b13">, DwarfRegNum<[31]>;
def BR14 : Ri<14, "b14">, DwarfRegNum<[32]>;
def BR15 : Ri<15, "b15">, DwarfRegNum<[33]>;

//------------------------------------------------------------------------------
// Provide register classes for the general allocation. The 'W' prefix
// denotes the 'Window' ABI while 'C' means 'Call0'. Stack pointer and
// return address are available (as general purpose registers) in Call0 ABI
//------------------------------------------------------------------------------

def WGP_Regs : RegisterClass<"Xtensa", [i32], 32,
  (add AR2, AR3, AR4, AR5, AR6, AR7, AR8, AR9,
       AR10, AR11, AR12, AR13, AR14, AR15)>;

def CGP_Regs : RegisterClass<"Xtensa", [i32], 32,
  (add AR0, AR1, AR2, AR3, AR4, AR5, AR6, AR7, AR8,
       AR9, AR10, AR11, AR12, AR13, AR14, AR15)>;

def RA_Regs : RegisterClass<"Xtensa", [i32], 32, (add AR0)>;
def SP_Regs : RegisterClass<"Xtensa", [i32], 32, (add AR1)>;

def PC_Regs : RegisterClass<"Xtensa", [i32], 32, (add PC)>, Unallocatable;
def SAR_Regs : RegisterClass<"Xtensa", [i32], 6, (add SAR)>;

//------------------------------------------------------------------------------
// Boolean register class, treat BR4 as 'special'
//------------------------------------------------------------------------------

def BOOL_Regs : RegisterClass<"Xtensa", [i1], 1,
  (add BR0, BR1, BR2, BR3, BR5, BR6, BR7, BR8,
       BR9, AR10, BR11, BR12, BR13, BR14, BR15)>;

def BR4_Regs : RegisterClass<"Xtensa", [i1], 1, (add BR4)>;
