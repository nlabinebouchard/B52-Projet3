#ifndef MUTATOR_EXTREME_H
#define MUTATOR_EXTREME_H

#include "Mutator.h"
#include <list>
#include <utility>

class Mutator;

class MutatorExtreme : public Mutator
{
public:
	MutatorExtreme() = default;
	~MutatorExtreme() override;

	void mutate(Solution & offspring) override;
	void add(Mutator * newMut, double prob);

private:
	std::list<std::pair<Mutator*, double>> mMutatorImplemented;
	double mProb{};
};

#endif // MUTATOR_EXTREME_H