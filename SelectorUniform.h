#ifndef SELECTOR_UNIFORM_H
#define SELECTOR_UNIFORM_H

#include "Selector.h"
#include <vector>

class SelectorUniform : public Selector 
{
public:
	SelectorUniform() = default;
	~SelectorUniform() = default;

	void prepare(Population const & population) override;
	Solution & select(Population & population) override;

private:
	size_t endPop{};
};

#endif // SELECTOR_UNIFORM_H