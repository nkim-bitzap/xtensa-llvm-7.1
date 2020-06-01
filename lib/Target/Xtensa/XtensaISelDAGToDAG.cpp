//===-- XtensaISelDAGToDAG.cpp - A dag to dag inst selector for Xtensa ----===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines an instruction selector for the Xtensa target.
//
//===----------------------------------------------------------------------===//

#include "XtensaTargetMachine.h"

#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/SelectionDAGISel.h"

using namespace llvm;

namespace {

class XtensaDAGToDAGISel : public SelectionDAGISel {
  public:
    XtensaDAGToDAGISel(XtensaTargetMachine &TM, CodeGenOpt::Level OptLevel)
    : SelectionDAGISel(TM, OptLevel)
    {}
};

} // end of anonymous namespace

