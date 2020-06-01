//===-- XtensaTargetObjectFile.cpp - Xtensa Object Info -------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "XtensaTargetObjectFile.h"
#include "XtensaSubtarget.h"

#include "llvm/BinaryFormat/ELF.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCSectionELF.h"
#include "llvm/Target/TargetMachine.h"

#include <cassert>

using namespace llvm;

//------------------------------------------------------------------------------
// XtensaTargetObjectFile implementation
//------------------------------------------------------------------------------

void XtensaTargetObjectFile::Initialize(MCContext &Ctx,
                                        const TargetMachine &TM)
{}

//------------------------------------------------------------------------------

MCSection*
XtensaTargetObjectFile::getExplicitSectionGlobal(
                                      const GlobalObject *GO,
                                      SectionKind Kind,
                                      const TargetMachine &TM) const
{
  assert(false && "XtensaTargetObjectFile::getExplicitSectionGlobal"
         " not implemented");

  return 0;
}

//------------------------------------------------------------------------------

MCSection*
XtensaTargetObjectFile::SelectSectionForGlobal(
                                      const GlobalObject *GO,
                                      SectionKind Kind,
                                      const TargetMachine &TM) const
{
  assert(false && "XtensaTargetObjectFile::SelectSectionForGlobal"
         " not implemented");

  return 0;
}

//------------------------------------------------------------------------------

MCSection*
XtensaTargetObjectFile::getSectionForConstant(
                                      const DataLayout &DL,
                                      SectionKind Kind,
                                      const Constant *C,
                                      unsigned &Align) const
{
  assert(false && "XtensaTargetObjectFile::getSectionForConstant"
         " not implemented");

  return 0;
}

