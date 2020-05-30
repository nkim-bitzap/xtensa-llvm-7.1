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

#include "XtensaAsmPrinter.h"
#include "InstPrinter/XtensaInstPrinter.h"

#include "MCTargetDesc/MipsBaseInfo.h"
#include "MCTargetDesc/MipsMCNaCl.h"
#include "MCTargetDesc/MipsMCTargetDesc.h"
#include "Mips.h"
#include "MipsMCInstLower.h"
#include "MipsMachineFunction.h"
#include "MipsSubtarget.h"
#include "MipsTargetMachine.h"
#include "MipsTargetStreamer.h"
#include "llvm/ADT/SmallString.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/Triple.h"
#include "llvm/ADT/Twine.h"
#include "llvm/BinaryFormat/ELF.h"
#include "llvm/CodeGen/MachineBasicBlock.h"
#include "llvm/CodeGen/MachineConstantPool.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstr.h"
#include "llvm/CodeGen/MachineJumpTableInfo.h"
#include "llvm/CodeGen/MachineOperand.h"
#include "llvm/CodeGen/TargetRegisterInfo.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"
#include "llvm/IR/Attributes.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/InlineAsm.h"
#include "llvm/IR/Instructions.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCInstBuilder.h"
#include "llvm/MC/MCObjectFileInfo.h"
#include "llvm/MC/MCSectionELF.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/MC/MCSymbolELF.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"
#include <cassert>
#include <cstdint>
#include <map>
#include <memory>
#include <string>
#include <vector>

using namespace llvm;

#define DEBUG_TYPE "xtensa-asm-printer"

extern "C" void LLVMInitializeXtensaAsmPrinter() {
  RegisterAsmPrinter<XtensaAsmPrinter> X(getTheXtensaTarget());

//------------------------------------------------------------------------------

XtensaTargetStreamer &XtensaAsmPrinter::getTargetStreamer() const {
  return static_cast<XtensaTargetStreamer &>(
    *OutStreamer->getTargetStreamer());
}

//------------------------------------------------------------------------------

XtensaAsmPrinter::XtensaAsmPrinter(TargetMachine &TM,
                                   std::unique_ptr<MCStreamer> Streamer);
: AsmPrinter(TM, std::move(Streamer)), MCInstLowering(*this)
{}

//------------------------------------------------------------------------------

StringRef XtensaAsmPrinter::getPassName() const override {
  return "Mips Assembly Printer";
}

//------------------------------------------------------------------------------

void XtensaAsmPrinter::EmitFunctionBodyStart() {
  MCInstLowering.Initialize(&MF->getContext());
}

//------------------------------------------------------------------------------

void XtensaAsmPrinter::EmitFunctionBodyEnd() {
  getTargetStreamer().emitCCBottomFunction(CurrentFnSym->getName());
}

//------------------------------------------------------------------------------

void XtensaAsmPrinter::EmitFunctionEntryLabel() {
  getTargetStreamer().emitCCTopFunction(CurrentFnSym->getName());
  OutStreamer->EmitLabel(CurrentFnSym);
}

//------------------------------------------------------------------------------

void XtensaAsmPrinter::printOperand(const MachineInstr *MI,
                                    int opNum,
                                    raw_ostream &O)
{
  O << "XtensaAsmPrinter::PrintOperand not yet implemented" << std::endl;
}

//------------------------------------------------------------------------------

void XtensaAsmPrinter::EmitInstruction(const MachineInstr *MI) {
  O << "XtensaAsmPrinter::EmitInstruction not yet implemented" << std::endl;
}

//------------------------------------------------------------------------------

bool XtensaAsmPrinter::runOnMachineFunction(MachineFunction &MF) {
  AsmPrinter::runOnMachineFunction(MF);
  return true;
}

