//===-- XtensaFrameLowering.h - Frame info for Xtensa Target --------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains declaration of the Xtensa frame information
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_XTENSA_XTENSAFRAMELOWERING_H
#define LLVM_LIB_TARGET_XTENSA_XTENSAFRAMELOWERING_H

#include "llvm/CodeGen/TargetFrameLowering.h"

namespace llvm {

class XtensaSubtarget;

class XtensaFrameLowering: public TargetFrameLowering {
  public:
    XtensaFrameLowering(const XtensaSubtarget &STI);

    void emitPrologue(MachineFunction &MF,
                      MachineBasicBlock &MBB) const override;

    void emitEpilogue(MachineFunction &MF,
                      MachineBasicBlock &MBB) const override;

    bool spillCalleeSavedRegisters(MachineBasicBlock &MBB,
                                  MachineBasicBlock::iterator MI,
                                  const std::vector<CalleeSavedInfo> &CSI,
                                  const TargetRegisterInfo *TRI) const override;

    bool restoreCalleeSavedRegisters(MachineBasicBlock &MBB,
                                  MachineBasicBlock::iterator MI,
                                  std::vector<CalleeSavedInfo> &CSI,
                                  const TargetRegisterInfo *TRI) const override;

    MachineBasicBlock::iterator
    eliminateCallFramePseudoInstr(MachineFunction &MF, MachineBasicBlock &MBB,
                                  MachineBasicBlock::iterator I) const override;

    bool hasFP(const MachineFunction &MF) const override;

    void determineCalleeSaves(MachineFunction &MF, BitVector &SavedRegs,
                              RegScavenger *RS = nullptr) const override;

    void processFunctionBeforeFrameFinalized(MachineFunction &MF,
                                     RegScavenger *RS = nullptr) const override;
};

} // end of namespace llvm

#endif /* LLVM_LIB_TARGET_XTENSA_XTENSAFRAMELOWERING_H */
