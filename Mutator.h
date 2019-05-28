#ifndef MUTATOR_H
#define MUTATOR_H

class Solution;

class Mutator
{
public:

	Mutator() = default;
	virtual ~Mutator() = default;

	double mutationRate() const;
	void setMutationRate(double newRate);

	virtual void mutate(Solution & chromo) = 0;

protected:
	double mMutationRate{};

};

#endif // MUTATOR_H