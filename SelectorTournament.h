#ifndef SELECTOR_TOURNAEMENT_H
#define SELECTOR_TOURNAEMENT_H

#include "SelectorRouletteWheel.h"
#include <vector>

class SelectorTournament : public SelectorRouletteWheel
{
public:
	SelectorTournament() = default;
	~SelectorTournament() override = default;

	Solution & select(Population & population) override;

private:

	static bool ToBeCompare(Solution* s1, Solution* s2);

};

#endif // SELECTOR_TOURNAEMENT_H