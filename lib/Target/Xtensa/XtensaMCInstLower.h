//===-- XtensaMCInstLower.h - Lower MachineInstr to MCInst ----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_XTENSA_XTENSAMCINSTLOWER_H
#define LLVM_LIB_TARGET_XTENSA_XTENSAMCINSTLOWER_H

#include "llvm/CodeGen/MachineOperand.h"
#include "llvm/Support/Compiler.h"

namespace llvm {
  class MCContext;
  class MCInst;
  class MCOperand;
  class MachineInstr;
  class MachineFunction;
  class Mangler;
  class AsmPrinter;

class LLVM_LIBRARY_VISIBILITY XtensaMCInstLower {
    typedef MachineOperand::MachineOperandType MachineOperandType;
    MCContext *Ctx;
    AsmPrinter &Printer;

  public:
    XtensaMCInstLower(class AsmPrinter &asmprinter);

    void Initialize(MCContext *C);
    void Lower(const MachineInstr *MI, MCInst &OutMI) const;
    MCOperand LowerOperand(const MachineOperand& MO,
                           unsigned offset = 0) const;

  private:
    MCOperand LowerSymbolOperand(const MachineOperand &MO,
                                 MachineOperandType MOTy,
                                 unsigned Offset) const;
};

} // end of namespace llvm

#endif /* LLVM_LIB_TARGET_XTENSA_XTENSAMCINSTLOWER_H */

