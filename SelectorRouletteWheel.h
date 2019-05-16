#ifndef SELECTOR_ROULETTE_WHEEL_H
#define SELECTOR_ROULETTE_WHEEL_H

#include "Selector.h"
#include <vector>

class SelectorRouletteWheel : public Selector 
{
public:
	SelectorRouletteWheel() = default;
	~SelectorRouletteWheel() = default;

	void prepare(Population const & pop) override;
	void select(Population & pop) override;

protected:
	std::vector <double> mRankWeight;

};

#endif // SELECTOR_ROULETTE_WHEEL_H