//===-- XtensaTargetMachine.h - Define TargetMachine for Xtensa -----------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the Xtensa specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_XTENSA_XTENSATARGETMACHINE_H
#define LLVM_LIB_TARGET_XTENSA_XTENSATARGETMACHINE_H

#include "XtensaSubtarget.h"

#include "llvm/ADT/Optional.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/Analysis/TargetTransformInfo.h"
#include "llvm/Support/CodeGen.h"
#include "llvm/Target/TargetMachine.h"

#include <memory>

namespace llvm {

//------------------------------------------------------------------------------

class XtensaABIInfo {
  public:
    enum XTENSA_ABI { Window_ABI, Call0_ABI };

  protected:
    XTENSA_ABI _ABI;

  public:
    XtensaABIInfo(XTENSA_ABI ABI);

    XTENSA_ABI getABIType() const;
};

//------------------------------------------------------------------------------

class XtensaTargetMachine : public LLVMTargetMachine {
    std::unique_ptr<TargetLoweringObjectFile> TLOF;

    XtensaSubtarget Subtarget;
    XtensaABIInfo ABIInfo;

  public:
    XtensaTargetMachine(const Target &T,
                        const Triple &TT,
                        StringRef CPU,
                        StringRef FS,
                        const TargetOptions &Options,
                        Optional<Reloc::Model> RM,
                        Optional<CodeModel::Model> CM,
                        CodeGenOpt::Level OL,
                        bool JIT);

    ~XtensaTargetMachine() override;

    const XtensaSubtarget *getSubtargetImpl() const;
    const XtensaSubtarget *getSubtargetImpl(const Function &);

    TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
    TargetTransformInfo getTargetTransformInfo(const Function &F) override;
    TargetLoweringObjectFile *getObjFileLowering() const override;

  protected:
    static std::string computeDataLayout(const Triple &TT,
                                         StringRef CPU,
                                         const TargetOptions &Options,
                                         bool isBigEndian);

    static Reloc::Model
    getEffectiveRelocModel(bool JIT, Optional<Reloc::Model> RM);

    static CodeModel::Model
    getEffectiveCodeModel(Optional<CodeModel::Model> CM);
};

}; // end of namespace llvm

#endif /* LLVM_LIB_TARGET_XTENSA_XTENSATARGETMACHINE_H */

