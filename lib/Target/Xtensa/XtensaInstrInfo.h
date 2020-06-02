//===-- XtensaInstrInfo.h - Xtensa Instruction Information ----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the Xtensa specific TargetInstrInfo implementation.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_XTENSA_XTENSAINSTRINFO_H
#define LLVM_LIB_TARGET_XTENSA_XTENSAINSTRINFO_H

#include "XtensaRegisterInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "XtensaGenInstrInfo.inc"

namespace llvm {

class XtensaInstrInfo : public XtensaGenInstrInfo {
    const XtensaRegisterInfo RI;
    virtual void anchor();

  public:
    XtensaInstrInfo();

    const TargetRegisterInfo &getRegisterInfo() const;

    bool analyzeBranch(MachineBasicBlock &MBB, MachineBasicBlock *&TBB,
                       MachineBasicBlock *&FBB,
                       SmallVectorImpl<MachineOperand> &Cond,
                       bool AllowModify) const override;

    unsigned insertBranch(MachineBasicBlock &MBB, MachineBasicBlock *TBB,
                          MachineBasicBlock *FBB, ArrayRef<MachineOperand> Cond,
                          const DebugLoc &DL,
                          int *BytesAdded = nullptr) const override;

    unsigned removeBranch(MachineBasicBlock &MBB,
                          int *BytesRemoved = nullptr) const override;

    void copyPhysReg(MachineBasicBlock &MBB, MachineBasicBlock::iterator I,
                     const DebugLoc &DL, unsigned DestReg, unsigned SrcReg,
                     bool KillSrc) const override;

};

} // end of namespace llvm

#endif // LLVM_LIB_TARGET_XTENSA_XTENSAINSTRINFO_H

