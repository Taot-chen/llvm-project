add_llvm_component_library(LLVMCpu0Desc
    Cpu0MCTargetDesc.cpp
    Cpu0ABIInfo.cpp

    LINK_COMPONENTS
    Cpu0Info
    MC
    Support
    Object
    TargetParser

    ADD_TO_COMPONENT
    Cpu0
)
