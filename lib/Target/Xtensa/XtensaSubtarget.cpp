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
#include "XtensaSubtarget.h"
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
                                 const TargetMachine &TM)
: XtensaGenSubtargetInfo(TT, CPU, FS),
  InstrInfo(),
  FrameLowering(*this),
  TLInfo(TM, *this),
  TSInfo()
{}

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

