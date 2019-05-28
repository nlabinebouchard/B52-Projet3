#ifndef SELECTOR_ROULETTE_WHEEL_H
#define SELECTOR_ROULETTE_WHEEL_H

#include "Selector.h"
#include <vector>

class SelectorRouletteWheel : public Selector
{
public:
	SelectorRouletteWheel() = default;
	~SelectorRouletteWheel() = default;

	void prepare(Population const & population) override;
	Solution & select(Population & population) override;

protected:
	std::vector<double> mRankWeight;
	double mValueMax;
};

#endif // SELECTOR_ROULETTE_WHEEL_H