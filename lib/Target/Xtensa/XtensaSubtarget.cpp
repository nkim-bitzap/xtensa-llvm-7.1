//===-- XtensaSubtarget.cpp - Define Subtarget for the Xtensa -------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the Xtensa specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#include "Xtensa.h"
#include "XtensaTargetMachine.h"

#include "llvm/Support/TargetRegistry.h"
  
using namespace llvm;
  
#define DEBUG_TYPE "xtensa-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "XtensaGenSubtargetInfo.inc"

//------------------------------------------------------------------------------
// XtensaSubtarget implementation
//------------------------------------------------------------------------------

void XtensaSubtarget::anchor() {}

//------------------------------------------------------------------------------

XtensaSubtarget::XtensaSubtarget(const Triple &TT,
                                 const std::string &CPU,
                                 const std::string &FS,
                                 const XtensaTargetMachine &TMarg)
: XtensaGenSubtargetInfo(TT, CPU, FS),
  TM(TMarg),
  InstrInfo(),
  FrameLowering(*this),
  TLInfo(TM, *this),
  TSInfo()
{}

//------------------------------------------------------------------------------

bool XtensaSubtarget::isWindowABI() const {
  return TM.getABIInfo().getABIType() == XtensaABIInfo::Window_ABI;
}

//------------------------------------------------------------------------------

bool XtensaSubtarget::isCall0ABI() const {
  return TM.getABIInfo().getABIType() == XtensaABIInfo::Call0_ABI;
}

//------------------------------------------------------------------------------

bool XtensaSubtarget::hasInt32Multiply() const {
  return Int32Multiply;
}

//------------------------------------------------------------------------------

bool XtensaSubtarget::hasInt32Divide() const {
  return Int32Divide;
}

//------------------------------------------------------------------------------

bool XtensaSubtarget::hasBooleanRegs() const {
  return BooleanRegs;
}

//------------------------------------------------------------------------------

const XtensaInstrInfo *XtensaSubtarget::getInstrInfo() const {
  return &InstrInfo;
}

//------------------------------------------------------------------------------

const XtensaFrameLowering *XtensaSubtarget::getFrameLowering() const {
  return &FrameLowering;
}

//------------------------------------------------------------------------------

const XtensaTargetLowering *XtensaSubtarget::getTargetLowering() const {
  return &TLInfo;
}

//------------------------------------------------------------------------------

const XtensaSelectionDAGInfo *XtensaSubtarget::getSelectionDAGInfo() const {
  return &TSInfo;
}

//------------------------------------------------------------------------------

const TargetRegisterInfo *XtensaSubtarget::getRegisterInfo() const {
  return &InstrInfo.getRegisterInfo();
}

