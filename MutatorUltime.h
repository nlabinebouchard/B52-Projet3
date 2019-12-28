#ifndef MUTATORULTIME_H
#define MUTATORULTIME_H

#include "Mutator.h"
#include "vector"
#include "Solution.h"
#include <list>
#include <utility>

class Mutator;

class MutatorUltime : public Mutator
{
public:
	MutatorUltime() = default;
	~MutatorUltime() override;

	void mutate(Solution & offspring) override;
	void add(Mutator * newMut);

private:
	std::list<Mutator*> mMutatorImplemented;

};

#endif // MUTATORULTIME_H