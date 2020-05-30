//===-- XtensaFrameLowering.cpp - Frame info for Xtensa Target ------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains implementation of the Xtensa frame information
//
//===----------------------------------------------------------------------===//

#include "Xtensa.h"
#include "XtensaFrameLowering.h"
#include "XtensaInstrInfo.h"
#include "XtensaMachineFunctionInfo.h"
#include "XtensaSubtarget.h"

#include <cassert>

using namespace llvm;

//------------------------------------------------------------------------------

XtensaFrameLowering::XtensaFrameLowering(const XtensaSubtarget &sti)
: TargetFrameLowering(TargetFrameLowering::StackGrowsDown, 16, 0)
{
  // stacks grows down with the stack pointer being aligned on
  // 16 byte boundaries for both ABI's and local area offset of 0
}

//------------------------------------------------------------------------------

void XtensaFrameLowering::emitPrologue(MachineFunction &MF,
                                       MachineBasicBlock &MBB) const
{
  assert(false && "XtensaFrameLowering::emitPrologue not implemented");
}

//------------------------------------------------------------------------------

void XtensaFrameLowering::emitEpilogue(MachineFunction &MF,
                                       MachineBasicBlock &MBB) const override
{
  assert(false && "XtensaFrameLowering::emitEpilogue not implemented");
}

//------------------------------------------------------------------------------

bool XtensaFrameLowering::spillCalleeSavedRegisters(
                                MachineBasicBlock &MBB,
                                MachineBasicBlock::iterator MI,
                                const std::vector<CalleeSavedInfo> &CSI,
                                const TargetRegisterInfo *TRI) const override
{
  assert(false && "XtensaFrameLowering::spillCalleeSavedRegisters"
         " not implemented");

  return false;
}

//------------------------------------------------------------------------------

bool XtensaFrameLowering::restoreCalleeSavedRegisters(
                                MachineBasicBlock &MBB,
                                MachineBasicBlock::iterator MI,
                                std::vector<CalleeSavedInfo> &CSI,
                                const TargetRegisterInfo *TRI) const override
{
  assert(false && "XtensaFrameLowering::restoreCalleeSavedRegisters"
         " not implemented");

  return false;
}

//------------------------------------------------------------------------------

MachineBasicBlock::iterator
XtensaFrameLowering::eliminateCallFramePseudoInstr(
                                MachineFunction &MF,
                                MachineBasicBlock &MBB,
                                MachineBasicBlock::iterator I) const override
{
  assert(false && "XtensaFrameLowering::eliminateCallFramePseudoInstr"
         " not implemented");

  return MBB.end();
}

//------------------------------------------------------------------------------

bool XtensaFrameLowering::hasFP(const MachineFunction &MF) const override
{
  assert(false && "XtensaFrameLowering::hasFP not implemented");
  return false;
}

//------------------------------------------------------------------------------

void XtensaFrameLowering::determineCalleeSaves(
                                MachineFunction &MF,
                                BitVector &SavedRegs,
                                RegScavenger *RS) const override
{
  assert(false && "XtensaFrameLowering::determineCalleeSaves"
         " not implemented");
}

//------------------------------------------------------------------------------

void XtensaFrameLowering::processFunctionBeforeFrameFinalized(
                                MachineFunction &MF,
                                RegScavenger *RS) const override
{
  assert(false && "XtensaFrameLowering::processFunctionBeforeFrameFinalized"
         " not implemented");
}

