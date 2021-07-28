#include <llvm/Pass.h>
#include <llvm/IR/Function.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/Analysis/CallGraph.h>
#include <llvm/Analysis/LoopInfo.h>
#include <llvm/Analysis/CFG.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/ValueSymbolTable.h>
#include <llvm/Support/CommandLine.h>
#include <llvm/Support/Debug.h>
#include <llvm/IR/Module.h>

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace llvm;

namespace APIFuzzErr {

/***
 * Pass that integrates various techniques to detect error
 * guarding branches in the given bitcode file.
 */
struct ModuleLevelPass : public ModulePass {
public:
	static char ID;

    ModuleLevelPass() : ModulePass(ID) {
	}

	~ModuleLevelPass() {
	}


	bool runOnModule(Module &m) override {
		return false;
	}

    void getAnalysisUsage(AnalysisUsage &AU) const override {

    }
};

char ModuleLevelPass::ID = 0;
// pass arg, pass desc, cfg_only, analysis only
static RegisterPass<ModuleLevelPass> x("errdetector",
                                       "Pass that tries to detect error guarding branches.",
                                       false, true);
}
