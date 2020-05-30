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

// Xtensa core ISA CPU registers

def AR0  : Ri< 0, "a0">, DwarfRegNum<[0]>;
def AR1  : Ri< 1, "a1">, DwarfRegNum<[1]>;
def AR2  : Ri< 2, "a2">, DwarfRegNum<[2]>;
def AR3  : Ri< 3, "a3">, DwarfRegNum<[3]>;
def AR4  : Ri< 4, "a4">, DwarfRegNum<[4]>;
def AR5  : Ri< 5, "a5">, DwarfRegNum<[5]>;
def AR6  : Ri< 6, "a6">, DwarfRegNum<[6]>;
def AR7  : Ri< 7, "a7">, DwarfRegNum<[7]>;
def AR8  : Ri< 8, "a8">, DwarfRegNum<[8]>;
def AR9  : Ri< 9, "a9">, DwarfRegNum<[9]>;
def AR10 : Ri<10, "a10">, DwarfRegNum<[10]>;
def AR11 : Ri<11, "a11">, DwarfRegNum<[11]>;
def AR12 : Ri<12, "a12">, DwarfRegNum<[12]>;
def AR13 : Ri<13, "a13">, DwarfRegNum<[13]>;
def AR14 : Ri<14, "a14">, DwarfRegNum<[14]>;
def AR15 : Ri<15, "a15">, DwarfRegNum<[15]>;
def PC   : Ri<16, "pc">, DwarfRegNum<[16]>;
def SAR  : Ri<17, "pc">, DwarfRegNum<[17]>;

// Xtensa general purpose registers

def GRRegs : RegisterClass<"Xtensa", [i32], 32,
  (add
    AR0, AR1, AR2, AR3,
    AR4, AR5, AR6, AR7,
    AR8, AR9, AR10, AR11,
    AR12, AR13, AR14, AR15)>;

// Xtensa special reserved registers

def PCRegs : RegisterClass<"Xtensa", [i32], 32,
  (add PC)>
{
  let isAllocatable = 0;
}

def SARRegs : RegisterClass<"Xtensa", [i32], 6,
  (add SAR)>
{
  let isAllocatable = 0;
}

