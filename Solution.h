#ifndef SOLUTION_H
#define SOLUTION_H
#include "Fitness_t.h"
#include "Chromosome.h"
#include "Canevas.h"

class Solution
{
private:
	fitness_t mFitness;
	Chromosome mChromosome;

public:
	Solution() = default;
	virtual ~Solution() = default;
	Solution(std::vector <bool> const & vect, std::vector <size_t> vectBit);
	fitness_t fitness() const;
	Chromosome & chromosome();
	Chromosome const & chromosome() const;
	void setFitness(double num);

	virtual void processFitness()=0;
	virtual void randomize()=0;
	virtual std::vector <bool> encode(std::vector<size_t> vectSize)=0;
	virtual void decode(std::vector <bool> vect, std::vector<size_t> vectSize)=0;
	virtual Solution* clone()=0;
private:
};

#endif // SOLUTION_H
