//===- XtensaAsmPrinter.h - Xtensa LLVM Assembly Printer ------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Xtensa assembly printer class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_XTENSA_XTENSAASMPRINTER_H
#define LLVM_LIB_TARGET_XTENSA_XTENSAASMPRINTER_H

#include "MipsMCInstLower.h"
#include "XtensaSubtarget.h"

#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/Support/Compiler.h"

#include <algorithm>
#include <memory>

namespace llvm {

class MCOperand;
class MCSubtargetInfo;
class MCSymbol;

class MachineBasicBlock;
class MachineConstantPool;
class MachineFunction;
class MachineInstr;
class MachineOperand;
class XtensaFunctionInfo;

class raw_ostream;
class TargetMachine;

//------------------------------------------------------------------------------

class LLVM_LIBRARY_VISIBILITY XtensaAsmPrinter : public AsmPrinter {
    const XtensaSubtarget *Subtarget;
    const XtensaFunctionInfo *FI;
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

} // end namespace llvm

#endif // LLVM_LIB_TARGET_XTENSA_XTENSAASMPRINTER_H
