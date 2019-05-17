#ifndef SELECTOR_TOURNAEMENT_H
#define SELECTOR_TOURNAEMENT_H

#include "Selector.h"
#include <vector>

class SelectorTournament : public Selector 
{
public:
	SelectorTournament() = default;
	~SelectorTournament() = default;

	void prepare(Population const & population) override;
	Solution & select(Population & population) override;

};

#endif // SELECTOR_TOURNAEMENT_H