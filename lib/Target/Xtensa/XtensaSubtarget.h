//===-- XtensaSubtarget.h - Define Subtarget for the Xtensa ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the Xtensa specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_XTENSA_XTENSASUBTARGET_H
#define LLVM_LIB_TARGET_XTENSA_XTENSASUBTARGET_H

namespace llvm {

class XtensaSubtarget : public XtensaGenSubtargetInfo {
    virtual void anchor();

    XtensaInstrInfo InstrInfo;
    XtensaFrameLowering FrameLowering;
    XtensaTargetLowering TLInfo;
    XtensaSelectionDAGInfo TSInfo;

  public:
    XtensaSubtarget(const Triple &TT,
                    const std::string &CPU,
                    const std::string &FS,
                    const TargetMachine &TM);

    void ParseSubtargetFeatures(StringRef CPU, StringRef FS);

    const XtensaInstrInfo *getInstrInfo() const override;

    const XtensaFrameLowering *getFrameLowering() const override;

    const XtensaTargetLowering *getTargetLowering() const override;

    const XtensaSelectionDAGInfo *getSelectionDAGInfo() const override;

    const TargetRegisterInfo *getRegisterInfo() const override;
};

#endif /* LLVM_LIB_TARGET_XTENSA_XTENSASUBTARGET_H */
