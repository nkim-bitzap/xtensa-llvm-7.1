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

#include "XtensaTargetMachine.h"
#include "MCTargetDesc/XtensaMCTargetDesc.h"

#include "Xtensa.h"
#include "XtensaSubtarget.h"
// #include "XtensaTargetObjectFile.h"

#include "llvm/Target/TargetOptions.h"
#include "llvm/ADT/Optional.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "xtensa"

//------------------------------------------------------------------------------

static std::string getDataLayoutString(const Triple &TT,
                                       StringRef CPU,
                                       const TargetOptions &Options,
                                       bool isBigEndian)
{
  std::string dl_string;

  if (isBigEndian)
    dl_string += "E";
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

  return dl_string;
}

//------------------------------------------------------------------------------

static Reloc::Model getEffectiveRelocModel(bool JIT,
                                           Optional<Reloc::Model> RM)
{
  if (!RM.hasValue() || JIT)
    return Reloc::Static;
  return *RM;
}

//------------------------------------------------------------------------------

static CodeModel::Model getEffectiveCodeModel(Optional<CodeModel::Model> CM) {
  if (CM)
    return *CM;
  return CodeModel::Small;
}

//------------------------------------------------------------------------------
// XtensaABIInfo implementation
//------------------------------------------------------------------------------

XtensaABIInfo::XtensaABIInfo(const TargetOptions &Options) {
  if (Options.getABIName.empty()) {
    _ABI = Call0_ABI;
  }
  else {
    if (Options.getABIName() == "window") _ABI = Window_ABI;
    else if (Options.getABIName() == "call0") _ABI = Call0_ABI;
    else {
      _ABI = Call0_ABI;

      errs() << "warning: unknown Xtensa ABI '"
             << Options.getABIName() << "', assuming 'call0'\n";
    }
  }
}

//------------------------------------------------------------------------------

XtensaABIInfo::XTENSA_ABI XtensaABIInfo::getABIType() const {
  return _ABI;
}

//------------------------------------------------------------------------------
// XtensaTargetMachine implementation
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
//  TLOF(llvm::make_unique<XtensaTargetObjectFile>()),
  Subtarget(TT, CPU, FS, *this),
  ABIInfo(XtensaABIInfo(Options))
{
  initAsmInfo();
}

//------------------------------------------------------------------------------

XtensaTargetMachine::~XtensaTargetMachine() = default;

//------------------------------------------------------------------------------

const XtensaABIInfo &XtensaTargetMachine::getABIInfo() const {
  return ABIInfo;
}

//------------------------------------------------------------------------------

bool XtensaTargetMachine::isWindowABI() const {
  return ABIInfo.getABIType() == XtensaABIInfo::Window_ABI;
}

//------------------------------------------------------------------------------

bool XtensaTargetMachine::isCall0ABI() const {
  return ABIInfo.getABIType() == XtensaABIInfo::Call0_ABI;
}

//------------------------------------------------------------------------------

const XtensaSubtarget*
XtensaTargetMachine::getSubtargetImpl(const Function &) const {
  return &Subtarget;
}

//------------------------------------------------------------------------------

const XtensaSubtarget *XtensaTargetMachine::getSubtargetImpl() const {
  return &Subtarget;
}

//------------------------------------------------------------------------------

TargetPassConfig*
XtensaTargetMachine::createPassConfig(PassManagerBase &PM) {
  return new XtensaPassConfig(*this, PM);
}

//------------------------------------------------------------------------------
/*
TargetTransformInfo
XtensaTargetMachine::getTargetTransformInfo(const Function &F) {
  return TargetTransformInfo(XtensaTTIImpl(this, F));
}
*/
//------------------------------------------------------------------------------

TargetLoweringObjectFile *XtensaTargetMachine::getObjFileLowering() const {
  return 0;
//  return TLOF.get();
}

//------------------------------------------------------------------------------
// XtensaPassConfig implementation
//------------------------------------------------------------------------------

XtensaPassConfig::XtensaPassConfig(XtensaTargetMachine &TM,
                                   PassManagerBase &PM)
: TargetPassConfig(TM, PM)
{}

//------------------------------------------------------------------------------

XtensaTargetMachine &XtensaPassConfig::getXtensaTargetMachine() const {
  return getTM<XtensaTargetMachine>();
}

//------------------------------------------------------------------------------

void XtensaPassConfig::addIRPasses() {
  TargetPassConfig::addIRPasses();
}

//------------------------------------------------------------------------------

bool XtensaPassConfig::addPreISel() {
  return false;
}

//------------------------------------------------------------------------------

bool XtensaPassConfig::addInstSelector() {
  return false;
}

//------------------------------------------------------------------------------

void XtensaPassConfig::addPreEmitPass() {
}

//------------------------------------------------------------------------------

extern "C" void LLVMInitializeXtensaTarget() {
  RegisterTargetMachine<XtensaTargetMachine> X(getTheXtensaTarget());
}
