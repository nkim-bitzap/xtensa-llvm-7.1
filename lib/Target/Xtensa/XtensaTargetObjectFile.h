//===-- XtensaTargetObjectFile.h - Xtensa Object Info ---------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_XTENSA_XTENSATARGETOBJECTFILE_H
#define LLVM_LIB_TARGET_XTENSA_XTENSATARGETOBJECTFILE_H

#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"

namespace llvm {

static const unsigned CodeModelLargeSize = 256;

class XtensaTargetObjectFile : public TargetLoweringObjectFileELF {
    MCSection *BSSSectionLarge;
    MCSection *DataSectionLarge;
    MCSection *ReadOnlySectionLarge;
    MCSection *DataRelROSectionLarge;

  public:
    void Initialize(MCContext &Ctx, const TargetMachine &TM) override;

    MCSection*
    getExplicitSectionGlobal(const GlobalObject *GO,
                             SectionKind Kind,
                             const TargetMachine &TM) const override;

    MCSection*
    SelectSectionForGlobal(const GlobalObject *GO,
                           SectionKind Kind,
                           const TargetMachine &TM) const override;

    MCSection*
    getSectionForConstant(const DataLayout &DL,
                          SectionKind Kind,
                          const Constant *C,
                          unsigned &Align) const override;
};

} // end namespace llvm

#endif /* LLVM_LIB_TARGET_XTENSA_XTENSATARGETOBJECTFILE_H */

