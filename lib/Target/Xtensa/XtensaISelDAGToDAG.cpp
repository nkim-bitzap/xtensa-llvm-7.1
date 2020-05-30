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

using namespace llvm;

namespace {

class XtensaDAGToDAGISel : public SelectionDAGISel {
  public:
    XtensaDAGToDAGISel(XCoreTargetMachine &TM, CodeGenOpt::Level OptLevel)
    : SelectionDAGISel(TM, OptLevel)
    {}
};

} // end of anonymous namespace

