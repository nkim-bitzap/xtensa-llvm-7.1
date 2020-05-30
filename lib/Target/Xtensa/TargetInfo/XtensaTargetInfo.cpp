//===-- XtensaTargetInfo.cpp - Xtensa Target Implementation ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "Xtensa.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheXtensaTarget() {
  static Target TheXtensaTarget;
  return TheXtensaTarget;
}

extern "C" void LLVMInitializeXtensaTargetInfo() {
  RegisterTarget<Triple::xtensa, 
                 X(getTheXtensaTarget(), "xtensa", "Xtensa", "Xtensa");
}
