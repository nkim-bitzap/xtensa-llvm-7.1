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

//------------------------------------------------------------------------------
// Predicates for instruction set inclusion/exclusion
//------------------------------------------------------------------------------

def IsWindowABI : Predicate<"Subtarget->isWindowABI()">;
def IsCall0ABI : Predicate<"Subtarget->isCall0ABI()">;
def HasBoolRegs : Predicate<"Subtarget->hasBooleanRegs()">;
def HasIntMultiply : Predicate<"Subtarget->hasInt32Multiply()">;
def HasIntDivide : Predicate<"Subtarget->hasInt32Divide()">;

class ABI_WINDOW {
  list<Predicate> ABIPredicates = [IsWindowABI];
}

class ABI_CALL0 {
  list<Predicate> ABIPredicates = [IsCall0ABI];
}

class HAS_INT_MULTIPLY {
  list<Predicate> InsnPredicates = [HasIntMultiply];
}

class HAS_INT_DIVIDE {
  list<Predicate> InsnPredicates = [HasIntDivide];
}

class HAS_BOOLEAN_REGS {
  list<Predicate> InsnPredicates = [HasBoolRegs];
}

//------------------------------------------------------------------------------
// Immediate pattern leafs
//------------------------------------------------------------------------------

// signed 8-bit immediate
def simm8 : PatLeaf<(imm), [{
  return isInt<8>(N->getSExtValue());
}]>;

// 8-bit signed immediate, scaled by 256
def simm8_s8 : PatLeaf<(imm), [{
  return isShiftedInt<8, 8>(N->getSExtValue());
}]>;

// unsigned 4-bit immediate
def uimm4 : PatLeaf<(imm), [{
  return isUInt<4>(N->getSExtValue());
}]>;

// 4-bit signed (narrow) immediate
def simm4_n : PatLeaf<(imm), [{
  int64_t Val = N->getSExtValue();
  return Val && (Val >= -1 && Val <= 15);
}]>;

// unsigned 4-bit (mask) immediate
def uimm4_m : PatLeaf<(imm), [{
  int64_t Val = N->getSExtValue();
  return Val >= 1 && Val <= 16;
}]>;

// unsigned 5-bit immediate
def uimm5 : PatLeaf<(imm), [{
  return isUInt<5>(N->getSExtValue());
}]>;

// unsigned immediate in the rage of 1-31
def uimm_1_31 : PatLeaf<(imm), [{
  int64_t Val = N->getSExtValue();
  return Val > 0 && Val < 32;
}]>;

// immediate in the range of 7-22
def imm_7_22 : PatLeaf<(imm), [{
  int64_t Val = N->getSExtValue();
  return Val >= 7 && Val <= 22;
}]>;

// unsigned (15-bit - 8) entry immediate
def uimm15_e : PatLeaf<(imm), [{
  int64_t Val = N->getSExtValue();
  return Val >= 0 && Val <= 32760;
}]>;

//------------------------------------------------------------------------------
// Operands
//------------------------------------------------------------------------------

def immOperand : Operand<i32>;

//------------------------------------------------------------------------------
// Nodes
//------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------
// Multiclasses and RRR instructions. Eventhough writing to RA/SP is not
// allowed in Window mode, we still can read them
//------------------------------------------------------------------------------

multiclass RRR_2_MC<string opstr, list<dag> pat> {
  def _W : RRR<(outs WGP_Regs:$ar),
               (ins CGP_Regs:$at),
               !strconcat(opstr, " $ar, $at"), pat>, ABI_WINDOW;

  def _C : RRR<(outs CGP_Regs:$ar),
               (ins CGP_Regs:$as, CGP_Regs:$at),
               !strconcat(opstr, " $ar, $as, $at"), pat>, ABI_CALL0;
}

multiclass RRR_3_MC<string opstr, list<dag> pat> {
  def _W : RRR<(outs WGP_Regs:$ar),
               (ins CGP_Regs:$as, CGP_Regs:$at),
               !strconcat(opstr, " $ar, $as, $at"), pat>, ABI_WINDOW;

  def _C : RRR<(outs CGP_Regs:$ar),
               (ins CGP_Regs:$as, CGP_Regs:$at),
               !strconcat(opstr, " $ar, $as, $at"), pat>, ABI_CALL0;
}

multiclass RRR_3_I_1_MC<string opstr, Operand immval, list<dag> pat> {
  def _W : RRR<(outs WGP_Regs:$ar),
               (ins CGP_Regs:$as, immval:$val),
               !strconcat(opstr, " $ar, $as, $val"), pat>, ABI_WINDOW;

  def _C : RRR<(outs CGP_Regs:$ar),
               (ins CGP_Regs:$as, immval:$val),
               !strconcat(opstr, " $ar, $as, $val"), pat>, ABI_CALL0;
}

multiclass RRR_3_I_2_MC<string opstr, Operand immval, list<dag> pat> {
  def _W : RRR<(outs WGP_Regs:$ar),
               (ins CGP_Regs:$at, immval:$val),
               !strconcat(opstr, " $ar, $at, $val"), pat>, ABI_WINDOW;

  def _C : RRR<(outs CGP_Regs:$ar),
               (ins CGP_Regs:$at, immval:$val),
               !strconcat(opstr, " $ar, $at, $val"), pat>, ABI_CALL0;
}

multiclass RRR_3_BOOL_1_MC<string opstr, list<dag> pat> {
  def _W : RRR<(outs WGP_Regs:$ar),
               (ins CGP_Regs:$as, BOOL_Regs:$bt),
               !strconcat(opstr, " $ar, $as, $bt"), pat>, ABI_WINDOW;

  def _C : RRR<(outs CGP_Regs:$ar),
               (ins CGP_Regs:$as, BOOL_Regs:$bt),
               !strconcat(opstr, " $ar, $as, $bt"), pat>, ABI_CALL0;
}

multiclass RRR_4_I_MC<string opstr,
                      Operand immval1, Operand immval2, list<dag> pat>
{
  def _W : RRR<(outs WGP_Regs:$ar),
               (ins CGP_Regs:$at, immval1:$val1, immval2:$val2),
               !strconcat(opstr, " $ar, $at, $val1, $val2"), pat>,
               ABI_WINDOW;

  def _C : RRR<(outs CGP_Regs:$ar),
               (ins CGP_Regs:$at, immval1:$val1, immval2:$val2),
               !strconcat(opstr, " $ar, $at, $val1, $val2"), pat>,
               ABI_CALL0;
}

// Core arithmetic instructions
defm ABS : RRR_2_MC<"abs", []>;
defm ADD : RRR_3_MC<"add", []>;
defm ADDX2 : RRR_3_MC<"addx2", []>;
defm ADDX4 : RRR_3_MC<"addx4", []>;
defm ADDX8 : RRR_3_MC<"addx8", []>;
defm SUB : RRR_3_MC<"sub", []>;
defm SUBX2 : RRR_3_MC<"subx2", []>; 
defm SUBX4 : RRR_3_MC<"subx4", []>;
defm SUBX8 : RRR_3_MC<"subx8", []>;

defm MAX : RRR_3_MC<"max", []>;
defm MAXU : RRR_3_MC<"maxu", []>;
defm MIN : RRR_3_MC<"min", []>;
defm MINU : RRR_3_MC<"minu", []>;

// Core move instructions
defm MOVEQZ : RRR_3_MC<"moveqz", []>;
defm MOVGEZ : RRR_3_MC<"movgez", []>;
defm MOVLTZ : RRR_3_MC<"movltz", []>;
defm MOVNEZ : RRR_3_MC<"movnez", []>;

// Core bitwise instructions
defm NEG : RRR_2_MC<"neg", []>;
defm AND : RRR_3_MC<"and", []>;
defm OR : RRR_3_MC<"or", []>;
defm XOR : RRR_3_MC<"xor", []>;

// Core shift instructions
defm SLL : RRR_2_MC<"sll", []>;
defm SRA : RRR_2_MC<"sra", []>;
defm SRC : RRR_3_MC<"src", []>;
defm SRL : RRR_2_MC<"srl", []>;

let Defs = [SAR] in {
  def SSR : RRR<(outs), (ins CGP_Regs:$as), "ssr $as", []>;
  def SSL : RRR<(outs), (ins CGP_Regs:$as), "ssl $as", []>;
  def SSAI : RRR<(outs), (ins i32imm:$val), "ssai $val", []>;
}

defm SLLI : RRR_3_I_1_MC<"slli", immOperand, []>;
defm SRLI : RRR_3_I_2_MC<"srli", immOperand, []>;
defm SRAI : RRR_3_I_2_MC<"srai", immOperand, []>;

defm EXTUI : RRR_4_I_MC<"extui", immOperand, immOperand, []>;

// Optional 32-bit integer multiply
defm MULL : RRR_3_MC<"mull", []>, HAS_INT_MULTIPLY;
defm MULSH : RRR_3_MC<"mulsh", []>, HAS_INT_MULTIPLY;
defm MULUH : RRR_3_MC<"muluh", []>, HAS_INT_MULTIPLY;

// Optional 32-bit integer division
defm QUOS : RRR_3_MC<"quos", []>, HAS_INT_DIVIDE;
defm QUOU : RRR_3_MC<"quou", []>, HAS_INT_DIVIDE;
defm REMS : RRR_3_MC<"rems", []>, HAS_INT_DIVIDE;
defm REMU : RRR_3_MC<"remu", []>, HAS_INT_DIVIDE; 

// Optional boolean register instructions
defm MOVF : RRR_3_BOOL_1_MC<"movf", []>, HAS_BOOLEAN_REGS;
defm MOVT : RRR_3_BOOL_1_MC<"movt", []>, HAS_BOOLEAN_REGS;

def ANDB : RRR<(outs BOOL_Regs:$br),
               (ins BOOL_Regs:$bs, BOOL_Regs:$bt),
               "andb $br, $bs, $bt", []>, HAS_BOOLEAN_REGS;

def ANDBC : RRR<(outs BOOL_Regs:$br),
                (ins BOOL_Regs:$bs, BOOL_Regs:$bt),
                "andbc $br, $bs, $bt", []>, HAS_BOOLEAN_REGS;

def ORB : RRR<(outs BOOL_Regs:$br),
              (ins BOOL_Regs:$bs, BOOL_Regs:$bt),
              "orb $br, $bs, $bt", []>, HAS_BOOLEAN_REGS;

def ORBC : RRR<(outs BOOL_Regs:$br),
               (ins BOOL_Regs:$bs, BOOL_Regs:$bt),
               "orbc $br, $bs, $bt", []>, HAS_BOOLEAN_REGS;

def XORB : RRR<(outs BOOL_Regs:$br),
               (ins BOOL_Regs:$bs, BOOL_Regs:$bt),
               "xorb $br, $bs, $bt", []>, HAS_BOOLEAN_REGS;

//------------------------------------------------------------------------------
// Multiclasses and RRI8 instructions
//------------------------------------------------------------------------------

multiclass RRI8_MC<string opstr, Operand immval, list<dag> pat> {
  def _W : RRI8<(outs WGP_Regs:$at),
                (ins CGP_Regs:$as, immval:$val),
                !strconcat(opstr, " $at, $as, $val"), []>, ABI_WINDOW;

  def _C : RRI8<(outs CGP_Regs:$at),
                (ins CGP_Regs:$as, immval:$val),
                !strconcat(opstr, " $at, $as, $val"), []>, ABI_CALL0;
}

defm ADDI : RRI8_MC<"addi", immOperand, []>;
defm ADDMI : RRI8_MC<"addmi", immOperand, []>;

