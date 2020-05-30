//===-- XtensaTargetStreamer.h - Xtensa Target Streamer -------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_XTENSA_XTENSATARGETSTREAMER_H
#define LLVM_LIB_TARGET_XTENSA_XTENSATARGETSTREAMER_H

#include "llvm/MC/MCStreamer.h"

namespace llvm {

class XtensaTargetStreamer : public MCTargetStreamer {

public:
  XtensaTargetStreamer(MCStreamer &S);
  ~XtensaTargetStreamer() override;

  virtual void emitCCTopData(StringRef Name) = 0;
  virtual void emitCCTopFunction(StringRef Name) = 0;
  virtual void emitCCBottomData(StringRef Name) = 0;
  virtual void emitCCBottomFunction(StringRef Name) = 0;
};

//------------------------------------------------------------------------------

class XtensaTargetAsmStreamer : public XtensaTargetStreamer {
  formatted_raw_ostream &OS;

public:
  XtensaTargetAsmStreamer(MCStreamer &S, formatted_raw_ostream &OS);

  void emitCCTopData(StringRef Name) override;
  void emitCCTopFunction(StringRef Name) override;
  void emitCCBottomData(StringRef Name) override;
  void emitCCBottomFunction(StringRef Name) override;
};

}

#endif /* LLVM_LIB_TARGET_XTENSA_XTENSATARGETSTREAMER_H  */

