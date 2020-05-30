//===-- XtensaInstrInfo.cpp - Xtensa Instruction Information --------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides the Xtensa specific TargetInstrInfo implementation.
//
//===----------------------------------------------------------------------===//

#include "Xtensa.h"
#include "XtensaInstrInfo.h"

#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"

#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "XtensaGenInstrInfo.inc"

//------------------------------------------------------------------------------

XtensaInstrInfo::XtensaInstrInfo(): TargetInstrInfo()
{}

//------------------------------------------------------------------------------

void XtensaInstrInfo::anchor() {}

//------------------------------------------------------------------------------

const TargetRegisterInfo &XtensaInstrInfo::getRegisterInfo() const {
  return RI;
}

//------------------------------------------------------------------------------

bool XtensaInstrInfo::analyzeBranch(MachineBasicBlock &MBB,
                                    MachineBasicBlock *&TBB,
                                    MachineBasicBlock *&FBB,
                                    SmallVectorImpl<MachineOperand> &Cond,
                                    bool AllowModify) const override
{
  std::cout << "XtensaInstrInfo::analyzeBranch not yet implemented"
            << std::endl;

  return false;
}

//------------------------------------------------------------------------------

unsigned XtensaInstrInfo::insertBranch(MachineBasicBlock &MBB,
                                       MachineBasicBlock *TBB,
                                       MachineBasicBlock *FBB,
                                       ArrayRef<MachineOperand> Cond,
                                       const DebugLoc &DL,
                                       int *BytesAdded) const override
{
  std::cout << "XtensaInstrInfo::insertBranch not yet implemented"
            << std::endl;

  return 0;
}

//------------------------------------------------------------------------------

unsigned XtensaInstrInfo::removeBranch(MachineBasicBlock &MBB,
                                       int *BytesRemoved) const override
{
  std::cout << "XtensaInstrInfo::removeBranch not yet implemented"
            << std::endl;

  return 0;
}

//------------------------------------------------------------------------------

void XtensaInstrInfo::copyPhysReg(MachineBasicBlock &MBB,
                                  MachineBasicBlock::iterator I,
                                  const DebugLoc &DL,
                                  unsigned DestReg,
                                  unsigned SrcReg,
                                  bool KillSrc) const override
{
  std::cout << "XtensaInstrInfo::copyPhysReg not yet implemented"
            << std::endl;

  return 0;
}

