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
	fitness_t mTotalFitness;
	fitness_t mWeight;
	double mProbabilities;
	double mValueRandom;
	double mInterval;

};

#endif // SELECTOR_ROULETTE_WHEEL_H