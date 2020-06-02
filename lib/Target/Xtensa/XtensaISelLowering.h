//===-- XtensaISelLowering.h - Xtensa DAG Lowering Interface --------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines the interfaces that Xtensa uses to lower LLVM code into
// a DAG ready for selection
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_XTENSA_XTENSAISELLOWERING_H
#define LLVM_LIB_TARGET_XTENSA_XTENSAISELLOWERING_H

#include "Xtensa.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class XtensaSubtarget;
class XtensaTargetMachine;

class XtensaTargetLowering : public TargetLowering {
    const XtensaSubtarget &Subtarget;

  public:
    explicit XtensaTargetLowering(const XtensaTargetMachine &TM,
                                  const XtensaSubtarget &Subtarget);

    const char *getTargetNodeName(unsigned Opcode) const override;

    // lowering hooks, customized for the Xtensa target

    SDValue LowerOperation(SDValue Op, SelectionDAG &DAG) const override;
    SDValue LowerLOAD(SDValue Op, SelectionDAG &DAG) const;
    SDValue LowerSTORE(SDValue Op, SelectionDAG &DAG) const;
    SDValue LowerGlobalAddress(SDValue Op, SelectionDAG &DAG) const;
    SDValue LowerGlobalTLSAddress(SDValue Op, SelectionDAG &DAG) const;
    SDValue LowerRETURNADDR(SDValue Op, SelectionDAG &DAG) const;

    SDValue LowerFormalArguments(
                        SDValue Chain,
                        CallingConv::ID CallConv,
                        bool isVarArg,
                        const SmallVectorImpl<ISD::InputArg> &Ins,
                        const SDLoc &dl,
                        SelectionDAG &DAG,
                        SmallVectorImpl<SDValue> &InVals) const override;

    SDValue LowerCall(TargetLowering::CallLoweringInfo &CLI,
                      SmallVectorImpl<SDValue> &InVals) const override;

    SDValue LowerReturn(SDValue Chain,
                        CallingConv::ID CallConv,
                        bool isVarArg,
                        const SmallVectorImpl<ISD::OutputArg> &Outs,
                        const SmallVectorImpl<SDValue> &OutVals,
                        const SDLoc &dl,
                        SelectionDAG &DAG) const override;
};

} // end of namespace llvm

#endif // LLVM_LIB_TARGET_XTENSA_XTENSAISELLOWERING_H

