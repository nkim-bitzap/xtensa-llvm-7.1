//===-- XtensaSelectionDAGInfo.h - Xtensa SelectionDAG Info ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines the Xtensa subclass for SelectionDAGTargetInfo.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_XTENSA_XTENSASELECTIONDAGINFO_H
#define LLVM_LIB_TARGET_XTENSA_XTENSASELECTIONDAGINFO_H

#include "llvm/CodeGen/SelectionDAGTargetInfo.h"

namespace llvm {

class XtensaTargetMachine;

class XtensaSelectionDAGInfo : public SelectionDAGTargetInfo {
  public:
    SDValue
    EmitTargetCodeForMemcpy(SelectionDAG &DAG,
                            const SDLoc &dl,
                            SDValue Chain,
                            SDValue Op1,
                            SDValue Op2,
                            SDValue Op3,
                            unsigned Align,
                            bool isVolatile,
                            bool AlwaysInline,
                            MachinePointerInfo DstPtrInfo,
                            MachinePointerInfo SrcPtrInfo) const override;
};

} // end of namespace llvm

#endif /* LLVM_LIB_TARGET_XTENSA_XTENSASELECTIONDAGINFO_H */

