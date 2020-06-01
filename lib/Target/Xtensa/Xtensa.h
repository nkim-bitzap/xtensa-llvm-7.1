//===-- Xtensa.h - Top-level interface for Xtensa representation ----------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the entry points for global functions defined in the
// LLVM Xtensa back-end.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_XTENSA_XTENSA_H
#define LLVM_LIB_TARGET_XTENSA_XTENSA_H

namespace llvm {
class FunctionPass;

// insert target passes here as the backend matures, nothing useful
// for xtensa code generation here yet
FunctionPass *createXCoreFrameToArgsOffsetEliminationPass();

} // end namespace llvm

#endif /* LLVM_LIB_TARGET_XTENSA_XTENSA_H */

