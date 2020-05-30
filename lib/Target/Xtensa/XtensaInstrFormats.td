//===-- XtensaInstrFormats.td - Xtensa Instruction Formats -*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// Avalable instruction formats for Xtensa.
//===----------------------------------------------------------------------===//

// basic/generic Xtensa instruction template

class InstXtensa<int size,
                 dag outs,
                 dag ins,
                 string asmstr,
                 list<dag> pattern>
: Instruction
{
  field bits<24> Inst;

  let Namespace = "Xtensa";
  dag OutOperandList = outs;
  dag InOperandList = ins;
  let AsmString   = asmstr;
  let Pattern = pattern;
  let Size = size;

  field bits<32> SoftFail = 0;
}

// subtype of the Xtensa instruction template to capture pseudo's

class PseudoInstXtensa<dag outs,
                       dag ins,
                       string asmstr,
                       list<dag> pattern>
: InstXtensa<0, outs, ins, asmstr, pattern>
{
  let isPseudo = 1;
}
