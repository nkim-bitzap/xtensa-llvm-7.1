//===-- XtensaRegisterInfo.h - Xtensa Register Information Impl -----------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the Xtensa implementation of the MRegisterInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_XTENSA_XTENSAREGISTERINFO_H
#define LLVM_LIB_TARGET_XTENSA_XTENSAREGISTERINFO_H

#include "llvm/CodeGen/TargetRegisterInfo.h"

#define GET_REGINFO_HEADER
#include "XtensaGenRegisterInfo.inc"

namespace llvm {

class TargetInstrInfo;

struct XtensaRegisterInfo : public XtensaGenRegisterInfo {
  public:
    XtensaRegisterInfo();

    const MCPhysReg*
    getCalleeSavedRegs(const MachineFunction *MF) const override;

    BitVector getReservedRegs(const MachineFunction &MF) const override;

    bool enableMultipleCopyHints() const override;

    bool requiresRegisterScavenging(const MachineFunction &MF) const override;

    bool trackLivenessAfterRegAlloc(const MachineFunction &MF) const override;

    bool useFPForScavengingIndex(const MachineFunction &MF) const override;

    void eliminateFrameIndex(MachineBasicBlock::iterator II,
                             int SPAdj,
                             unsigned FIOperandNum,
                             RegScavenger *RS = nullptr) const override;

    unsigned getFrameRegister(const MachineFunction &MF) const override;
};

#endif /* LLVM_LIB_TARGET_XTENSA_XTENSAREGISTERINFO_H */ 

