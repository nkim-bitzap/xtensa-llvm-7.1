//===-- XtensaSelectionDAGInfo.cpp - Xtensa SelectionDAG Info -------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the Xtensa subclass for SelectionDAGTargetInfo.
//
//===----------------------------------------------------------------------===//

#include "XtensaSelectionDAGInfo.h"
#include "XCoreTargetMachine.h"

#include <cassert>

#define DEBUG_TYPE "xtensa-selectiondag-info"

using namespace llvm;

SDValue
XtensaSelectionDAGInfo::EmitTargetCodeForMemcpy(
                               SelectionDAG &DAG,
                               const SDLoc &dl,
                               SDValue Chain,
                               SDValue Op1,
                               SDValue Op2,
                               SDValue Op3,
                               unsigned Align,
                               bool isVolatile,
                               bool AlwaysInline,
                               MachinePointerInfo DstPtrInfo,
                               MachinePointerInfo SrcPtrInfo) const override
{
  assert(false && "XtensaSelectionDAGInfo::EmitTargetCodeForMemcpy"
         " not implemented");

  SDValue ret;
  return ret;
}

