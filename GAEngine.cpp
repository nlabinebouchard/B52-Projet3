#include "GAEngine.h"

size_t GAEngine::epoch() const
{
	return mEpoch;

}

const Population & GAEngine::population(size_t populationEngine) const
{
	return mPopulationEngines[populationEngine].population();
}

const FitnessStatistics & GAEngine::statistics(size_t popIndex, size_t epoch) const {
	return mFitnessHistory.getStatistics(popIndex,epoch);  
}

void GAEngine::reset() {

	mEpoch = 0;
	mFitnessHistory.clearHistory(mParameters.populationCount);
	
	mPopEngIt = mPopulationEngines.begin();

	while (mPopEngIt != mPopulationEngines.end())
	{
		mPopEngIt->randomize();
		++mPopEngIt;
	}

}

void GAEngine::evolve() {

	mPopEngIt = mPopulationEngines.begin();
	size_t indice = 0;

	while (mPopEngIt!=mPopulationEngines.end())
	{

		mFitnessHistory.insertNewStatistics(indice, mPopEngIt->statistics());

		mPopEngIt->evolve();

		++mPopEngIt;
		++indice;
	}


//v�rifier les condtions de sorties pour arr�ter de faire les evolve, avec une variable bool
	//convergencerate, maximumGeneration, mutationRate???, 

	//remplir � la fin du evolve 

	//faire un HistoryStatistics----classe d�tenue par le GAEngine pour dealer avec les 
	//statistics de chaque PopulationEngine � chaque �poque, donc vecteur de vecteur ou dequoi de m�me.
}

void GAEngine::setup(GAParameters parameters) {

	for (size_t i = 0; i < parameters.populationCount; i++)
	{
		mPopulationEngines.push_back(PopulationEngine());
		mPopulationEngines[i].setElitism(parameters.elitismSize);
		mPopulationEngines[i].setCrossover(parameters.crossover);
		mPopulationEngines[i].setMutator(parameters.mutator);
		mPopulationEngines[i].setPopulation(parameters.populationSize,parameters.solutionSample);
		mPopulationEngines[i].setSelector(parameters.selector);
		
	}
	
}
