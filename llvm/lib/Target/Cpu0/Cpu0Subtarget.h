//===-- Cpu0Subtarget.h - Define Subtarget for the Cpu0 ---------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the Cpu0 specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_CPU0_CPU0SUBTARGET_H
#define LLVM_LIB_TARGET_CPU0_CPU0SUBTARGET_H

#include "Cpu0FrameLowering.h"
#include "Cpu0ISelLowering.h"
#include "Cpu0InstrInfo.h"
#include "llvm/CodeGen/SelectionDAGTargetInfo.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/MC/MCInstrItineraries.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"
#include <string>

#define GET_SUBTARGETINFO_HEADER
#include "Cpu0GenSubtargetInfo.inc"

namespace llvm {
class StringRef;
class Cpu0TargetMachine;

class Cpu0Subtarget : public Cpu0GenSubtargetInfo {
virtual void anchor();

protected:
    enum Cpu0ArchEnum {
        Cpu032I,
        Cpu032II
    };

    // Cpu0 architecture version
    // Controled by -mcpu in commandline
    Cpu0ArchEnum Cpu0ArchVersion;

    // IsLittle - The target is Little Endian
    bool IsLittle;

    bool EnableOverflow;

    // HasCmp - cmp instructions.
    bool HasCmp;

    // HasSlt - slt instructions.
    bool HasSlt;

    InstrItineraryData InstrItins;

    const Cpu0TargetMachine &TM;

    Triple TargetTriple;

    const SelectionDAGTargetInfo TSInfo;

    std::unique_ptr<const Cpu0InstrInfo> InstrInfo;
    std::unique_ptr<const Cpu0FrameLowering> FrameLowering;
    std::unique_ptr<const Cpu0TargetLowering> TLInfo;

    Align stackAlignment = Align(4);

public:
    Align getStackAlignment() const { return stackAlignment; }
};
} // end namesapce llvm

#endif
