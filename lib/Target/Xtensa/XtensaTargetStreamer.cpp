//===-- XtensaTargetStreamer.cpp - Xtensa Target Streamer Description -----===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides Xtensa specific target streamer descriptions
//
//===----------------------------------------------------------------------===//

using namespace llvm;

#include "XtensaTargetStreamer.h"
#include "MCTargetDesc/XtensaMCTargetDesc.h"

XtensaTargetStreamer::XtensaTargetStreamer(MCStreamer &S)
: MCTargetStreamer(S)
{}

//------------------------------------------------------------------------------

XtensaTargetStreamer::~XtensaTargetStreamer() = default;

//------------------------------------------------------------------------------

XtensaTargetAsmStreamer::XtensaTargetAsmStreamer(MCStreamer &S,
                                                 formatted_raw_ostream &OS)
: XtensaTargetStreamer(S), OS(OS)
{}

//------------------------------------------------------------------------------

void XtensaTargetAsmStreamer::emitCCTopData(StringRef Name) {
  OS << "XtensaTargetAsmStreamer::emitCCTopData not yet implemented"
     << std::endl;
}

//------------------------------------------------------------------------------

void XtensaTargetAsmStreamer::emitCCTopFunction(StringRef Name) {
  OS << "XtensaTargetAsmStreamer::emitCCTopFunction not yet implemented"
     << std::endl;
}

//------------------------------------------------------------------------------

void XtensaTargetAsmStreamer::emitCCBottomData(StringRef Name) {
  OS << "XtensaTargetAsmStreamer::emitCCBottomData not yet implemented"
     << std::endl;
}

//------------------------------------------------------------------------------

void XtensaTargetAsmStreamer::emitCCBottomFunction(StringRef Name) {
  OS << "XtensaTargetAsmStreamer::emitCCBottomData not yet implemented"
     << std::endl;
}

