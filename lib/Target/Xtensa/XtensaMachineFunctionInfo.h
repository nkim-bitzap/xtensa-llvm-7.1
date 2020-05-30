//===- XtensaMachineFunctionInfo.h - Xtensa machine function info ---------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares Xtensa-specific per-machine-function information.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_XTENSA_XTENSAMACHINEFUNCTIONINFO_H
#define LLVM_LIB_TARGET_XTENSA_XTENSAMACHINEFUNCTIONINFO_H

#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"

namespace llvm {

class XtensaMachineFunctionInfo : public MachineFunctionInfo {
    virtual void anchor();

  public:
    XtensaMachineFunctionInfo() = default;
    ~XtensaMachineFunctionInfo() override = default;

    explicit XtensaMachineFunctionInfo(MachineFunction &MF);
};

#endif /* LLVM_LIB_TARGET_XTENSA_XTENSAMACHINEFUNCTIONINFO_H */

