//===-- XtensaTargetInfo.cpp - Xtensa Target Implementation ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "Xtensa.h"
#include "MCTargetDesc/XtensaMCTargetDesc.h"

#include "llvm/IR/Module.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheXtensaTarget() {
  static Target TheXtensaTarget;
  return TheXtensaTarget;
}

// prior to this, need to add 'xtensa' explicitly to the list of known
// triples in 'lib/Support/Triple.c' resp. 'include/llvm/ADT/Triple.h'
extern "C" void LLVMInitializeXtensaTargetInfo() {
  RegisterTarget<Triple::xtensa> X(
    getTheXtensaTarget(), "xtensa", "Xtensa", "Xtensa");
}
