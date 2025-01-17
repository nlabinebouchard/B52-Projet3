#ifndef SELECTOR_H
#define SELECTOR_H

class Population;
class Solution;

class Selector
{
public:
	Selector() = default;
	virtual ~Selector() = default;

	virtual void prepare(Population const & pop) = 0;
	virtual Solution & select(Population & pop) = 0;

};

#endif // SELECTOR_H
