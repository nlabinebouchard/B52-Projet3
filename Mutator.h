#ifndef MUTATOR_H
#define MUTATOR_H


class Mutator
{
public:

	double mutationRate() const;
	void setMutationRate(double newRate);

	virtual void mutate();

private:

	double mMutationRate;

};

#endif // MUTATOR_H