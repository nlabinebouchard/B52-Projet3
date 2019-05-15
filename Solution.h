#ifndef SOLUTION_H
#define SOLUTION_H

using fitness_t = size_t;

class Solution
{
public:
	fitness_t mFitness;
	fitness_t fitness();

private:
	virtual void processFitness();
	virtual void randomize();
	virtual void encode();
	virtual void decode();
	virtual Solution clone();
};

#endif // SOLUTION_H
