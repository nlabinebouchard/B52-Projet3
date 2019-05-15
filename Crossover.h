#ifndef CROSSOVER_H
#define CROSSOVER_H



class Crossover
{
public:
	Crossover() = default;
	~Crossover() = default;
	
	virtual void breed( Solution const & genitor1, Solution const & genitor2, Solution & offspring);

};

#endif // CROSSOVER_H