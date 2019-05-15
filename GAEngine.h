#pragma once

#include "../B52-Projet3/GAParameters.h"

using Population = size_t; //à enlever

class GAEngine
{
public:


	GAEngine() = default;

	~GAEngine() = default;

	size_t & epoch() const;

	Population & population();

	void reset();

	void evolve();

	void setup(GAParameters parameters);



private:

	size_t mEpoch;

};