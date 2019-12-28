
#include "MutatorExtreme.h"
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
#include <iterator>

MutatorExtreme::~MutatorExtreme()
{
	for (auto & cur : mMutatorImplemented) {
		delete cur.first;
	}
	mMutatorImplemented.clear();
}

void MutatorExtreme::mutate(Solution & offspring)
{
	if (RandomUtil::generateEvent(mMutationRate)) {
		double mMaxValueInterval{};
		double mValueRandom{ RandomUtil::randomRangeHundred(0.00, mProb) };

		for (auto & cur : mMutatorImplemented) {
			mMaxValueInterval += cur.second;
			if (mValueRandom < mMaxValueInterval) {
				cur.first->mutate(offspring);
				break;
			}
		}
	}
}

void MutatorExtreme::add(Mutator * newMut, double prob)
{
	if (newMut) {
		newMut->setMutationRate(1);
		mMutatorImplemented.push_back(std::pair<Mutator*, double>(newMut, prob));
		mProb += prob;
	}
}
