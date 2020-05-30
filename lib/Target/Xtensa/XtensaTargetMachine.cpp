//===-- XtensaTargetMachine.pp - Define TargetMachine for Xtensa ----------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the Xtensa specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//

#include "Xtensa.h"
#include "XtensaTargetMachine.h"
#include "XtensaSubtarget.h"

#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetOptions.h"

using namespace llvm;

#define DEBUG_TYPE "xtensa"

extern "C" void LLVMInitializeXtensaTarget() {
  RegisterTargetMachine<XtensaTargetMachine> X(getTheXtensaTarget());
}

//------------------------------------------------------------------------------

XtensaABIInfo::XtensaABIInfo(XTENSA_ABI _ABI)
: ABI(_ABI)
{}

//------------------------------------------------------------------------------

XtensaABIInfo::XTENSA_ABI XtensaABIInfo::getABIType() const
{
  return _ABI;
}

//------------------------------------------------------------------------------

XtensaTargetMachine::XtensaTargetMachine(const Target &T,
                                         const Triple &TT,
                                         StringRef CPU,
                                         StringRef FS,
                                         const TargetOptions &Options,
                                         Optional<Reloc::Model> RM,
                                         Optional<CodeModel::Model> CM,
                                         CodeGenOpt::Level OL,
                                         bool JIT,
                                         bool isBigEndian)
: LLVMTargetMachine(
    T,
    getDataLayoutString(TT, CPU, Options, isBigEndian),
    TT, CPU, FS, Options,
    getEffectiveRelocModel(JIT, RM),
    getEffectiveCodeModel(CM),
    OL),
  ABI(XtensaABIInfo::Call0_ABI),
  TLOF(llvm::make_unique<XtensaTargetObjectFile>()),
  Subtarget(TT, CPU, FS, *this)
{
  initAsmInfo();
}

//------------------------------------------------------------------------------

XtensaTargetMachine::~XtensaTargetMachine() = default;

//------------------------------------------------------------------------------

static std::string
XtensaTargetMachine::getDataLayoutString(const Triple &TT,
                                         StringRef CPU,
                                         const TargetOptions &Options,
                                         bool isBigEndian)
{
  std::string dl_string;

  if (isBigEndian)
    dl_string += "E"
  else dl_string += "e";

  // required stack alignment of 16 bytes
  dl_string += "-S128";

  // output symbol mangling in ELF style
  dl_string += "-m:e";

  // pointer alignment preference
  dl_string += "-p:32:32";

  // integral data type alignment
  dl_string += "-i1:8:32-i8:8:32-i16:16:32-i64:32";

  // size of native integral data types
  dl_string += "-n32";

  // floating point data type alignment;
  dl_string += "-f64:32";

  // aggregate alignment preference
  dl_string += "-a:0:32";
}

//------------------------------------------------------------------------------

static Reloc::Model
Xtensa::getEffectiveRelocModel(bool JIT, Optional<Reloc::Model> RM)
{
  if (!RM.hasValue() || JIT)
    return Reloc::Static;
  return *RM;
}

//------------------------------------------------------------------------------

static CodeModel::Model
XtensaTargetMachine::getEffectiveCodeModel(Optional<CodeModel::Model> CM)
{
  if (CM)
    return *CM;
  return CodeModel::Small;
}

//------------------------------------------------------------------------------

const XtensaSubtarget*
Xtensa::getSubtargetImpl(const Function &) const override {
  return &Subtarget;
}

//------------------------------------------------------------------------------

const XtensaSubtarget *Xtensa::getSubtargetImpl() const {
  return &Subtarget;
}

//------------------------------------------------------------------------------

TargetPassConfig*
XtensaTargetMachine::createPassConfig(PassManagerBase &PM) override {
  return new XtensaPassConfig(*this, PM);
}

//------------------------------------------------------------------------------

TargetTransformInfo
XtensaTargetMachine::getTargetTransformInfo(const Function &F) override {
  return TargetTransformInfo(XtensaTTIImpl(this, F));
}

//------------------------------------------------------------------------------

TargetLoweringObjectFile*
XtensaTargetMachine::getObjFileLowering() const override {
  return TLOF.get();
}

