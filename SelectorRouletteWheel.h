#ifndef SELECTOR_ROULETTE_WHEEL_H
#define SELECTOR_ROULETTE_WHEEL_H

#include "Selector.h"

class SelectorRouletteWheel : public Selector 
{
public:
	SelectorRouletteWheel() = default;
	~SelectorRouletteWheel() = default;

	void prepare(Population const & population) override;
	Solution & select(Population & population) const override;

protected:
	std::vector <double> mRankWeight;
};

#endif // SELECTOR_ROULETTE_WHEEL_H