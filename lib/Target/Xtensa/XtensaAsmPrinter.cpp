//===- XtensaAsmPrinter.cpp - Xtensa LLVM Assembly Printer ----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains a printer that converts from our internal representation
// of machine-dependent LLVM code to GAS-format Xtensa assembly language.
//
//===----------------------------------------------------------------------===//

#include "MCTargetDesc/XtensaMCTargetDesc.h"
#include "InstPrinter/XtensaInstPrinter.h"
#include "XtensaSubtarget.h"
#include "XtensaTargetStreamer.h"
#include "XtensaMachineFunctionInfo.h"
#include "XtensaMCInstLower.h"

#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstr.h"

#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/MCSymbolELF.h"

/*
#include "llvm/ADT/SmallString.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/DebugInfo.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Mangler.h"
#include "llvm/IR/Module.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/MCSymbolELF.h"
#include "llvm/Target/TargetLoweringObjectFile.h"
*/
#include <algorithm>
#include <cctype>
#include <cassert>

//#include "Xtensa.h"
/*
#include "XtensaInstrInfo.h"
#include "XtensaSubtarget.h"

#include "XtensaInstrInfo.h"
#include "XtensaMCInstLower.h"
#include "XtensaSubtarget.h"
#include "XtensaTargetMachine.h"
#include "XtensaTargetStreamer.h"
*/

using namespace llvm;

#define DEBUG_TYPE "asm-printer"

//------------------------------------------------------------------------------
// XtensaAsmPrinter implementation
//------------------------------------------------------------------------------

namespace {

class XtensaAsmPrinter : public AsmPrinter {
    const XtensaSubtarget *Subtarget;
    const XtensaMachineFunctionInfo *FI;
    XtensaMCInstLower MCInstLowering;

  protected:
    XtensaTargetStreamer &getTargetStreamer() const;

  public:
    explicit XtensaAsmPrinter(TargetMachine &TM,
                              std::unique_ptr<MCStreamer> Streamer);

    StringRef getPassName() const override;

    void EmitFunctionEntryLabel() override;
    void EmitInstruction(const MachineInstr *MI) override;
    void EmitFunctionBodyStart() override;
    void EmitFunctionBodyEnd() override;

    void printOperand(const MachineInstr *MI, int opNum, raw_ostream &O);

    bool runOnMachineFunction(MachineFunction &MF) override;
};

} // end of anonymous namespace

//------------------------------------------------------------------------------

XtensaAsmPrinter::XtensaAsmPrinter(TargetMachine &TM,
                                   std::unique_ptr<MCStreamer> Streamer)

: AsmPrinter(TM, std::move(Streamer)), MCInstLowering(*this)
{}

//------------------------------------------------------------------------------

XtensaTargetStreamer &XtensaAsmPrinter::getTargetStreamer() const {
  return static_cast<XtensaTargetStreamer &>(
    *OutStreamer->getTargetStreamer());
}

//------------------------------------------------------------------------------

StringRef XtensaAsmPrinter::getPassName() const {
  return "Xtensa Assembly Printer";
}

//------------------------------------------------------------------------------

void XtensaAsmPrinter::EmitFunctionBodyStart() {
  assert(false && "XtensaAsmPrinter::EmitFunctionBodyStart"
         " not implemented");
}

//------------------------------------------------------------------------------

void XtensaAsmPrinter::EmitFunctionBodyEnd() {
  assert(false && "XtensaAsmPrinter::EmitFunctionBodyEnd"
         " not implemented");
}

//------------------------------------------------------------------------------

void XtensaAsmPrinter::EmitFunctionEntryLabel() {
  assert(false && "XtensaAsmPrinter::EmitFunctionEntryLabel"
         " not implemented");
}

//------------------------------------------------------------------------------

void XtensaAsmPrinter::printOperand(const MachineInstr *MI,
                                    int opNum,
                                    raw_ostream &O)
{
  assert(false && "XtensaAsmPrinter::printOperand not implemented");
}

//------------------------------------------------------------------------------

void XtensaAsmPrinter::EmitInstruction(const MachineInstr *MI) {
  assert(false && "XtensaAsmPrinter::EmitInstruction not implemented");
}

//------------------------------------------------------------------------------

bool XtensaAsmPrinter::runOnMachineFunction(MachineFunction &MF) {
  AsmPrinter::runOnMachineFunction(MF);
  return true;
}

//------------------------------------------------------------------------------

extern "C" void LLVMInitializeXtensaAsmPrinter() {
  RegisterAsmPrinter<XtensaAsmPrinter> X(getTheXtensaTarget());
}
