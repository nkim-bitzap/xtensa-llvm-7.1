//===-- XtensaInstrInfo.td - Target Description for Xtensa -*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file describes the Xtensa instructions in TableGen format.
//
//===----------------------------------------------------------------------===//

include "XtensaInstrFormats.td"

// These are target-independent nodes, but have target-specific formats.
def SDT_XtensaCallSeqStart : SDCallSeqStart<[SDTCisVT<0, i32>,
                                             SDTCisVT<1, i32>]>;

def SDT_XtensaCallSeqEnd : SDCallSeqEnd<[SDTCisVT<0, i32>,
                                         SDTCisVT<1, i32>]>;

def callseq_start : SDNode<"ISD::CALLSEQ_START", SDT_XtensaCallSeqStart,
                           [SDNPHasChain, SDNPOutGlue]>;

def callseq_end : SDNode<"ISD::CALLSEQ_END", SDT_XtensaCallSeqEnd,
                         [SDNPHasChain, SDNPOptInGlue, SDNPOutGlue]>;


// stack pointer in AR1
let Defs = [AR1],
    Uses = [AR1] in
{
  def ADJCALLSTACKDOWN : PseudoInstXtensa<
                           (outs),
                           (ins i32imm:$amt, i32imm:$amt2),
                           "# ADJCALLSTACKDOWN $amt, $amt2",
                           [(callseq_start timm:$amt, timm:$amt2)]>;

  def ADJCALLSTACKUP : PseudoInstXtensa<
                           (outs),
                           (ins i32imm:$amt1, i32imm:$amt2),
                           "# ADJCALLSTACKUP $amt1",
                           [(callseq_end timm:$amt1, timm:$amt2)]>;
}
