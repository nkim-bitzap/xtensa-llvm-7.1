//===- XtensaDisassembler.cpp - Disassembler for Xtensa -------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file is part of the Xtensa Disassembler.
//
//===----------------------------------------------------------------------===//

#include "Xtensa.h"
#include "MCTargetDesc/XtensaMCTargetDesc.h"

#include "llvm/ADT/ArrayRef.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCDisassembler/MCDisassembler.h"
#include "llvm/MC/MCFixedLenDisassembler.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/Support/Compiler.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/MathExtras.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/raw_ostream.h"

#include <cassert>
#include <cstdint>

using namespace llvm;

#define DEBUG_TYPE "xtensa-disassembler"

using DecodeStatus = MCDisassembler::DecodeStatus;

namespace {

class XtensaDisassembler : public MCDisassembler {
    bool IsBigEndian;

  public:
    XtensaDisassembler(const MCSubtargetInfo &STI,
                       MCContext &Ctx,
                       bool IsBigEndian);

    DecodeStatus getInstruction(MCInst &Instr, uint64_t &Size,
                                ArrayRef<uint8_t> Bytes, uint64_t Address,
                                raw_ostream &VStream,
                                raw_ostream &CStream) const override;
};

} // end anonymous namespace

//------------------------------------------------------------------------------
// XtensaDisassembler implementation
//------------------------------------------------------------------------------

XtensaDisassembler::XtensaDisassembler(const MCSubtargetInfo &STI,
                                       MCContext &Ctx,
                                       bool IsBigEndian)
: MCDisassembler(STI, Ctx),
  IsBigEndian(IsBigEndian)
{}

//------------------------------------------------------------------------------

DecodeStatus XtensaDisassembler::getInstruction(MCInst &instr,
                                                uint64_t &Size,
                                                ArrayRef<uint8_t> Bytes,
                                                uint64_t Address,
                                                raw_ostream &vStream,
                                                raw_ostream &cStream) const
{
  return Fail;
}

//------------------------------------------------------------------------------

#include "XtensaGenDisassemblerTables.inc"

namespace llvm {
  Target &getTheXtensaTarget();
}

//------------------------------------------------------------------------------
// Static function implementation
//------------------------------------------------------------------------------

static MCDisassembler *createXtensaDisassembler(
                                          const Target &T,
                                          const MCSubtargetInfo &STI,
                                          MCContext &Ctx)
{
  return new XtensaDisassembler(STI, Ctx, false);
}

//------------------------------------------------------------------------------

extern "C" void LLVMInitializeXtensaDisassembler() {
  TargetRegistry::RegisterMCDisassembler(
    getTheXtensaTarget(), createXtensaDisassembler);
}
