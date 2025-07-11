//===-- Cpu0TargetInfo.cpp - Cpu0 Target Implementation ---------*- C++ -*-===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===

#include "Cpu0.h"
#include "llvm/IR/Module.h"
#include "llvm/MC/TargetRegistry.h"
#include "Cpu0TargetInfo.h"

using namespace llvm;
Target& llvm::getTheCpu0Target() {
    static Target TheCpu0Target;
    return TheCpu0Target;
}

Target& llvm::getTheCpu0e1Target() {
    static Target TheCpu0e1Target;
    return TheCpu0e1Target;
}

extern "C" void LLVMInitializeCpu0TargetInfo() {
    RegisterTarget<Triple::cpu0, /*HasJIT=*/true> X(getTheCpu0Target(), "cpu0", "Cpu0", "Cpu0");
    RegisterTarget<Triple::cpu0e1, /*HasJIT=*/true> Y(getTheCpu0e1Target(), "cpu0e1", "Cpu0e1", "Cpu0");
}
