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
#include "Xtensa.h"
#include "llvm/Support/TargetRegistry.h"
  
using namespace llvm;
  
#define DEBUG_TYPE "xtensa-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "XtensaGenSubtargetInfo.inc"

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

XTENSA_ABI XtensaSubtarget::getABIType() const
{
  return _ABI;
}

//------------------------------------------------------------------------------

bool XtensaSubtarget::isWindowABI() const {
  return getABIType() == Window_ABI;
}

//------------------------------------------------------------------------------

bool XtensaSubtarget::isCall0ABI() const {
  return getABIType() == Call0_ABI;
}
