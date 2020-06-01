//===-- XtensaMCTargetDesc.cpp - Xtensa Target Descriptions ---------------===//
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

#include "XtensaTargetStreamer.h"
#include "MCTargetDesc/XtensaMCTargetDesc.h"
#include "MCTargetDesc/XtensaMCAsmInfo.h"
#include "InstPrinter/XtensaInstPrinter.h"

#include "llvm/ADT/StringRef.h"
#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/Support/CodeGen.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/FormattedStream.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define GET_INSTRINFO_MC_DESC
#include "XtensaGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "XtensaGenSubtargetInfo.inc"

#define GET_REGINFO_MC_DESC
#include "XtensaGenRegisterInfo.inc"

namespace {
class XtensaTargetAsmStreamer : public XtensaTargetStreamer {
    formatted_raw_ostream &OS;

  public:
    XtensaTargetAsmStreamer(MCStreamer &S, formatted_raw_ostream &OS);

    void emitCCTopData(StringRef Name) override;
    void emitCCTopFunction(StringRef Name) override;
    void emitCCBottomData(StringRef Name) override;
    void emitCCBottomFunction(StringRef Name) override;
};

} // end of anonymous namespace

//------------------------------------------------------------------------------
// XtensaTargetStreamer implementation
//------------------------------------------------------------------------------

XtensaTargetStreamer::XtensaTargetStreamer(MCStreamer &S)
: MCTargetStreamer(S)
{}

//------------------------------------------------------------------------------

XtensaTargetStreamer::~XtensaTargetStreamer() = default;

//------------------------------------------------------------------------------
// XtensaTargetAsmStreamer implementation
//------------------------------------------------------------------------------

XtensaTargetAsmStreamer::XtensaTargetAsmStreamer(MCStreamer &S,
                                                 formatted_raw_ostream &OS)
: XtensaTargetStreamer(S), OS(OS)
{}

//------------------------------------------------------------------------------

void XtensaTargetAsmStreamer::emitCCTopData(StringRef Name) {
  OS << "XtensaTargetAsmStreamer::emitCCTopData not yet implemented\n";
}

//------------------------------------------------------------------------------

void XtensaTargetAsmStreamer::emitCCTopFunction(StringRef Name) {
  OS << "XtensaTargetAsmStreamer::emitCCTopFunction not yet implemented\n";
}

//------------------------------------------------------------------------------

void XtensaTargetAsmStreamer::emitCCBottomData(StringRef Name) {
  OS << "XtensaTargetAsmStreamer::emitCCBottomData not yet implemented\n";
}

//------------------------------------------------------------------------------

void XtensaTargetAsmStreamer::emitCCBottomFunction(StringRef Name) {
  OS << "XtensaTargetAsmStreamer::emitCCBottomData not yet implemented\n";
}

//------------------------------------------------------------------------------
// Static function implementation
//------------------------------------------------------------------------------

static MCInstrInfo *createXtensaMCInstrInfo() {
  MCInstrInfo *X = new MCInstrInfo();
  InitXtensaMCInstrInfo(X);
  return X;
}

//------------------------------------------------------------------------------

static MCRegisterInfo *createXtensaMCRegisterInfo(const Triple &TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  InitXtensaMCRegisterInfo(X, Xtensa::AR0);
  return X;
}

//------------------------------------------------------------------------------

static MCSubtargetInfo *createXtensaMCSubtargetInfo(const Triple &TT,
                                                    StringRef CPU,
                                                    StringRef FS)
{
  return createXtensaMCSubtargetInfoImpl(TT, CPU, FS);
}

//------------------------------------------------------------------------------

static MCAsmInfo *createXtensaMCAsmInfo(const MCRegisterInfo &MRI,
                                        const Triple &TT)
{
  MCAsmInfo *MAI = new XtensaMCAsmInfo(TT);
  return MAI;
}

//------------------------------------------------------------------------------

static MCInstPrinter *createXtensaMCInstPrinter(const Triple &T,
                                                unsigned SyntaxVariant,
                                                const MCAsmInfo &MAI,
                                                const MCInstrInfo &MII,
                                                const MCRegisterInfo &MRI)
{
  return new XtensaInstPrinter(MAI, MII, MRI);
}

//------------------------------------------------------------------------------

static MCTargetStreamer *createXtensaAsmStreamer(MCStreamer &S,
                                                 formatted_raw_ostream &OS,
                                                 MCInstPrinter *InstPrint,
                                                 bool isVerboseAsm)
{
  return new XtensaTargetAsmStreamer(S, OS);
}

//------------------------------------------------------------------------------

extern "C" void LLVMInitializeXtensaTargetMC() {
  // Register the MC asm info
  RegisterMCAsmInfoFn X(getTheXtensaTarget(), createXtensaMCAsmInfo);

  // Register the MC instruction info
  TargetRegistry::RegisterMCInstrInfo(getTheXtensaTarget(),
                                      createXtensaMCInstrInfo);

  // Register the MC register info
  TargetRegistry::RegisterMCRegInfo(getTheXtensaTarget(),
                                    createXtensaMCRegisterInfo);

  // Register the MC subtarget info
  TargetRegistry::RegisterMCSubtargetInfo(getTheXtensaTarget(),
                                          createXtensaMCSubtargetInfo);

  // Register the MCInstPrinter
  TargetRegistry::RegisterMCInstPrinter(getTheXtensaTarget(),
                                        createXtensaMCInstPrinter);

  // Register the AsmTargetStreamer
  TargetRegistry::RegisterAsmTargetStreamer(getTheXtensaTarget(),
                                            createXtensaAsmStreamer);
}
