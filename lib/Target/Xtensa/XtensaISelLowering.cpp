//===-- XtensaISelLowering.cpp - Xtensa DAG Lowering Interface ------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the interfaces that Xtensa uses to lower LLVM code
// into a DAG ready for selection
//
//===----------------------------------------------------------------------===//

#include "Xtensa.h"
#include "XtensaISelLowering.h"
#include "XtensaSubtarget.h"
#include "XtensaTargetMachine.h"

#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineJumpTableInfo.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/CodeGen/SelectionDAGISel.h"
#include "llvm/CodeGen/ValueTypes.h"

#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/KnownBits.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "xtensa-lower"

// DAG->viewGraph("dag-combine1 input for " + BlockName);
// DAG->dump();

//------------------------------------------------------------------------------
// XtensaTargetLowering implementation
//------------------------------------------------------------------------------

XtensaTargetLowering::XtensaTargetLowering(const XtensaTargetMachine &TM,
                                           const XtensaSubtarget &ST)
: TargetLowering(TM), Subtarget(ST)
{
  // TODO, extend properly
}

//------------------------------------------------------------------------------

const char *XtensaTargetLowering::getTargetNodeName(unsigned Opcode) const {
  return "unknown";
}

//------------------------------------------------------------------------------

SDValue XtensaTargetLowering::LowerOperation(SDValue Op,
                                             SelectionDAG &DAG) const
{
  SDValue ret;
  return ret;
}

//------------------------------------------------------------------------------

SDValue XtensaTargetLowering::LowerLOAD(SDValue Op,
                                        SelectionDAG &DAG) const
{
  SDValue ret;
  return ret;
}

//------------------------------------------------------------------------------

SDValue XtensaTargetLowering::LowerSTORE(SDValue Op,
                                         SelectionDAG &DAG) const
{
  SDValue ret;
  return ret;
}

//------------------------------------------------------------------------------

SDValue XtensaTargetLowering::LowerGlobalAddress(SDValue Op,
                                                 SelectionDAG &DAG) const
{
  SDValue ret;
  return ret;
}

//------------------------------------------------------------------------------

SDValue XtensaTargetLowering::LowerGlobalTLSAddress(SDValue Op,
                                                    SelectionDAG &DAG) const
{
  SDValue ret;
  return ret;
}

//------------------------------------------------------------------------------

SDValue XtensaTargetLowering::LowerRETURNADDR(SDValue Op,
                                              SelectionDAG &DAG) const
{
  SDValue ret;
  return ret;
}

//------------------------------------------------------------------------------

SDValue XtensaTargetLowering::LowerFormalArguments(
                              SDValue Chain,
                              CallingConv::ID CallConv,
                              bool isVarArg,
                              const SmallVectorImpl<ISD::InputArg> &Ins,
                              const SDLoc &dl,
                              SelectionDAG &DAG,
                              SmallVectorImpl<SDValue> &InVals) const
{
  SDValue ret;
  return ret;
}

//------------------------------------------------------------------------------

SDValue XtensaTargetLowering::LowerCall(
                              TargetLowering::CallLoweringInfo &CLI,
                              SmallVectorImpl<SDValue> &InVals) const
{
  SDValue ret;
  return ret;
}

//------------------------------------------------------------------------------

SDValue XtensaTargetLowering::LowerReturn(SDValue Chain,
                              CallingConv::ID CallConv,
                              bool isVarArg,
                              const SmallVectorImpl<ISD::OutputArg> &Outs,
                              const SmallVectorImpl<SDValue> &OutVals,
                              const SDLoc &dl,
                              SelectionDAG &DAG) const
{
  SDValue ret;
  return ret;
}

