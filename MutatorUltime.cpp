
#include "MutatorUltime.h"
#include "MutatorChromo.h"
#include "MutatorGene.h"
#include "MutatorInversionChromo.h"
#include "MutatorInversionGene.h"
#include "MutatorScrambleChromo.h"
#include "MutatorScrambleGene.h"
#include "MutatorSwapChromo.h"
#include "MutatorSwapGene.h"
#include "MutatorGeneLeastSignificant.h"
#include "RandomUtil.h"
#include "Solution.h"

MutatorUltime::~MutatorUltime()
{
	for (auto & cur : mMutatorImplemented) {
		delete cur;
	}
	mMutatorImplemented.clear();
}

void MutatorUltime::mutate(Solution & offspring)
{
	if (RandomUtil::generateEvent(mMutationRate)) {
		size_t index{};
		size_t mValueRandom{ RandomUtil::randomInRange(0, mMutatorImplemented.size() - 1) };

		for (auto & cur : mMutatorImplemented) {
			if (index == mValueRandom) {
				cur->mutate(offspring);
				break;
			}
			index++;
		}
	}
}

void MutatorUltime::add(Mutator * newMut)
{
	if (newMut) {
		newMut->setMutationRate(1);
		mMutatorImplemented.push_back(newMut);
	}
}
