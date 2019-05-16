#ifndef SELECTOR_H
#define SELECTOR_H

class Population;

class Selector
{
public:
	Selector() = default;
	~Selector() = default;

	virtual void prepare(Population const & pop);
	virtual void select(Population & pop);
};

#endif // SELECTOR_H
