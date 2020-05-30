//=== XtensaInstPrinter.cpp - Convert Xtensa MCInst to assembly syntax -----==//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This class prints a Xtensa MCInst to a .s file.
//
//===----------------------------------------------------------------------===//

#include "XtensaInstPrinter.h"
#include "XtensaInstrInfo.h"

#include "llvm/ADT/StringExtras.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "asm-printer"

#include "XtensaGenAsmWriter.inc"

//------------------------------------------------------------------------------

XtensaInstPrinter::XtensaInstPrinter(const MCAsmInfo &MAI,
                                     const MCInstrInfo &MII,
                                     const MCRegisterInfo &MRI)
: MCInstPrinter(MAI, MII, MRI)
{}

//------------------------------------------------------------------------------

void XtensaInstPrinter::printRegName(raw_ostream &OS,
                                     unsigned RegNo) const
{
  OS << "XtensaInstPrinter::printInst not yet implemented" << std::endl;
}

//------------------------------------------------------------------------------

void XtensaInstPrinter::printOperand(const MCInst *MI,
                                     unsigned OpNo,
                                     raw_ostream &O)
{
  OS << "XtensaInstPrinter::printOperand not yet implemented" << std::endl;
}

//------------------------------------------------------------------------------

void XtensaInstPrinter::printMemOperand(const MCInst *MI,
                                        int opNum,
                                        raw_ostream &O)
{
  OS << "XtensaInstPrinter::printMemOperand not yet implemented" << std::endl;
}

//------------------------------------------------------------------------------

void XtensaInstPrinter::printInst(const MCInst *MI,
                                  raw_ostream &O,
                                  StringRef Annot,
                                  const MCSubtargetInfo &STI)
{
  OS << "XtensaInstPrinter::printInst not yet implemented" << std::endl;
}

