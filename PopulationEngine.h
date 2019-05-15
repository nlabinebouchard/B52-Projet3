#pragma once


class PopulationEngine
{
public:


	PopulationEngine() = default;

	~PopulationEngine() = default;



private:

	void processFitness();

	void processElitism();

	void processOneOffspring(size_t index);



};