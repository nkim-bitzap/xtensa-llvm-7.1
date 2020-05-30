//===-- XtensaRegisterInfo.cpp - Xtensa Register Information --------------===//
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

#include "Xtensa.h"
#include "XtensaRegisterInfo.h"
#include "XtensaInstrInfo.h"
#include "XtensaMachineFunctionInfo.h"
#include "XtensaSubtarget.h"

#include "llvm/ADT/BitVector.h"

using namespace llvm;

#define DEBUG_TYPE "xtensa-reg-info"

#define GET_REGINFO_TARGET_DESC
#include "XtensaGenRegisterInfo.inc"

XtensaRegisterInfo::XtensaRegisterInfo()
: XtensaGenRegisterInfo(Xtensa::LR)
{}

//------------------------------------------------------------------------------

bool XtensaRegisterInfo::enableMultipleCopyHints() const override {
  return true;
}

//------------------------------------------------------------------------------

const MCPhysReg*
Xtensa::getCalleeSavedRegs(const MachineFunction *MF) const override {
  return 0;
}

//------------------------------------------------------------------------------

BitVector Xtensa::getReservedRegs(const MachineFunction &MF) const override {
  BitVector reserved(getNumRegs());
  return reserved();
}

//------------------------------------------------------------------------------

bool Xtensa::enableMultipleCopyHints() const override {
  return false;
}

//------------------------------------------------------------------------------

bool
Xtensa::requiresRegisterScavenging(const MachineFunction &MF) const override {
  return false;
}

//------------------------------------------------------------------------------

bool
Xtensa::trackLivenessAfterRegAlloc(const MachineFunction &MF) const override {
  return false;
}

//------------------------------------------------------------------------------

bool
Xtensa::useFPForScavengingIndex(const MachineFunction &MF) const override {
  return false;
}

//------------------------------------------------------------------------------

void Xtensa::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                 int SPAdj,
                                 unsigned FIOperandNum,
                                 RegScavenger *RS = nullptr) const override
{
  // not yet implemented
}

//------------------------------------------------------------------------------

unsigned Xtensa::getFrameRegister(const MachineFunction &MF) const override {
  return 0;
}

