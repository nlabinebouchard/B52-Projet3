#ifndef CROSSOVER_H
#define CROSSOVER_H

class Solution;

class Crossover
{
public:
	Crossover() = default;
	~Crossover() = default;

	virtual void breed(Solution const & genitor1, Solution const & genitor2, Solution & offspring) = 0;

};

#endif // CROSSOVER_H