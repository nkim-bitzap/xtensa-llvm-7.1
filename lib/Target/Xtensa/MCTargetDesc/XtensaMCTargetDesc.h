//===-- XtensaMCTargetDesc.h - Xtensa Target Descriptions -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides Xtensa specific target descriptions.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_XTENSA_MCTARGETDESC_XTENSAMCTARGETDESC_H
#define LLVM_LIB_TARGET_XTENSA_MCTARGETDESC_XTENSAMCTARGETDESC_H

namespace llvm {

class Target;

// provide a creator function for the Xtensa target to be used
// for target registering, see 'XtensaTargetMachine.cpp'
Target &getTheXtensaTarget();

} // end of namespace llvm

// Defines symbolic names for Xtensa registers as found in the
// auto-generated file
#define GET_REGINFO_ENUM
#include "XtensaGenRegisterInfo.inc"

// Defines symbolic names for the Xtensa instructions as found
// in the auto-generated file
#define GET_INSTRINFO_ENUM
#include "XtensaGenInstrInfo.inc"

// Defines a subtarget names for Xtensa as found in the auto-
// generated file
#define GET_SUBTARGETINFO_ENUM
#include "XtensaGenSubtargetInfo.inc"

#endif // LLVM_LIB_TARGET_XTENSA_MCTARGETDESC_XTENSAMCTARGETDESC_H
