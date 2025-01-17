#ifndef SELECTOR_SELECTOR_RANKWISE_H
#define SELECTOR_SELECTOR_RANKWISE_H

#include "SelectorRouletteWheel.h"
#include <vector>

class SelectorRankwise : public SelectorRouletteWheel
{
public:
	SelectorRankwise() = default;
	~SelectorRankwise() override = default;

	double gamma()const;
	void setGamma(double gamma);
	void prepare(Population const & population) override;

private:
	double mGamma{ 2 };

};

#endif // SELECTOR_SELECTOR_RANKWISE_H