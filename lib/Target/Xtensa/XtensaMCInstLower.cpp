//===-- XtensaMCInstLower.cpp - Lower MachineInstr to MCInst --------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "XtensaMCInstLower.h"

#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstr.h"
#include "llvm/CodeGen/MachineOperand.h"
#include "llvm/IR/Mangler.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCInst.h"

#include <cassert>

using namespace llvm;

//------------------------------------------------------------------------------
// XtensaMCInstLower implementation
//------------------------------------------------------------------------------

XtensaMCInstLower::XtensaMCInstLower(class AsmPrinter &asmprinter)
: Printer(asmprinter)
{}

//------------------------------------------------------------------------------

void XtensaMCInstLower::Initialize(MCContext *C) {
  Ctx = C;
}

//------------------------------------------------------------------------------

MCOperand XtensaMCInstLower::LowerSymbolOperand(const MachineOperand &MO,
                                                 MachineOperandType MOTy,
                                                 unsigned Offset) const
{
  return MCOperand();
}

//------------------------------------------------------------------------------

MCOperand XtensaMCInstLower::LowerOperand(const MachineOperand& MO,
                                          unsigned offset) const
{
  return MCOperand();
}

//------------------------------------------------------------------------------

void XtensaMCInstLower::Lower(const MachineInstr *MI, MCInst &OutMI) const {
  assert(false && "XtensaMCInstLower::Lower not implemented");  
}

