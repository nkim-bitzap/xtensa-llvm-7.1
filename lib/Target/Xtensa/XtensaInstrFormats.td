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

class InstXtensa<dag outs,
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
  let Size = 24;

  field bits<32> SoftFail = 0;
}

//------------------------------------------------------------------------------
// Xtensa narrow (16-bit) instruction template
//------------------------------------------------------------------------------

class InstXtensaN<dag outs,
                  dag ins,
                  string asmstr,
                  list<dag> pattern>
: Instruction
{
  field bits<16> Inst;

  let Namespace = "Xtensa";
  dag OutOperandList = outs;
  dag InOperandList = ins;
  let AsmString   = asmstr;
  let Pattern = pattern;
  let Size = 16;

  field bits<32> SoftFail = 0;
}

//------------------------------------------------------------------------------
// Xtensa pseudo instruction template
//------------------------------------------------------------------------------

class PseudoInstXtensa<dag outs,
                       dag ins,
                       string asmstr,
                       list<dag> pattern>
: InstXtensa<outs, ins, asmstr, pattern>
{
  let isPseudo = 1;
}

//------------------------------------------------------------------------------
// Xtensa RRR instruction format, little endian layout
//------------------------------------------------------------------------------

class RRR<dag outs, dag ins, string asmstr, list<dag> pattern>
: InstXtensa<outs, ins, asmstr, pattern>
{
/*
  bits<4> op0;
  bits<4> t;
  bits<4> s;
  bits<4> r;
  bits<4> op1;
  bits<4> op2;

  let Inst{0-3} = op0;
  let Inst{4-7} = t;
  let Inst{8-11} = s;
  let Inst{12-15} = r;
  let Inst{16-19} = op1;
  let Inst{20-23} = op2;
*/
}

//------------------------------------------------------------------------------
// Xtensa RRI4 instruction format, little endian layout
//------------------------------------------------------------------------------

class RRI4<dag outs, dag ins, string asmstr, list<dag> pattern>
: InstXtensa<outs, ins, asmstr, pattern>
{
/*
  bits<4> op0;
  bits<4> t;
  bits<4> s;
  bits<4> r;
  bits<4> op1;
  bits<4> imm4;

  let Inst{0-3} = op0;
  let Inst{4-7} = t;
  let Inst{8-11} = s;
  let Inst{12-15} = r;
  let Inst{16-19} = op1;
  let Inst{16-19} = imm4;
*/
}

//------------------------------------------------------------------------------
// Xtensa RRI8 instruction format, little endian layout
//------------------------------------------------------------------------------

class RRI8<dag outs, dag ins, string asmstr, list<dag> pattern>
: InstXtensa<outs, ins, asmstr, pattern>
{
/*
  bits<4> op0;
  bits<4> t;
  bits<4> s;
  bits<4> r;
  bits<8> imm8;

  let Inst{0-3} = op0;
  let Inst{4-7} = t;
  let Inst{8-11} = s;
  let Inst{12-15} = r;
  let Inst{16-23} = imm8;
*/
}

