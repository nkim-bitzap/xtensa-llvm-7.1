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

#include "XtensaRegisterInfo.h"
#include "Xtensa.h"
#include "XtensaInstrInfo.h"
#include "XtensaMachineFunctionInfo.h"
#include "XtensaSubtarget.h"

// #include "MCTargetDesc/XtensaMCTargetDesc.h"

#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineModuleInfo.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/CodeGen/RegisterScavenging.h"
#include "llvm/CodeGen/TargetFrameLowering.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/ADT/BitVector.h"

using namespace llvm;

#define DEBUG_TYPE "xtensa-reg-info"

#define GET_REGINFO_ENUM
#define GET_REGINFO_TARGET_DESC
#include "XtensaGenRegisterInfo.inc"

XtensaRegisterInfo::XtensaRegisterInfo()
: XtensaGenRegisterInfo(Xtensa::AR0)
{}

//------------------------------------------------------------------------------

bool XtensaRegisterInfo::enableMultipleCopyHints() const {
  return true;
}

//------------------------------------------------------------------------------

const MCPhysReg*
XtensaRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  return 0;
}

//------------------------------------------------------------------------------

BitVector
XtensaRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  BitVector reserved(getNumRegs());
  return reserved;
}

//------------------------------------------------------------------------------

bool XtensaRegisterInfo::requiresRegisterScavenging(
                                             const MachineFunction &MF) const
{
  return false;
}

//------------------------------------------------------------------------------

bool XtensaRegisterInfo::trackLivenessAfterRegAlloc(
                                             const MachineFunction &MF) const
{
  return false;
}

//------------------------------------------------------------------------------

bool XtensaRegisterInfo::useFPForScavengingIndex(
                                             const MachineFunction &MF) const
{
  return false;
}

//------------------------------------------------------------------------------

void XtensaRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                             int SPAdj,
                                             unsigned FIOperandNum,
                                             RegScavenger *RS) const
{
  // not yet implemented
}

//------------------------------------------------------------------------------

unsigned
XtensaRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  return 0;
}

