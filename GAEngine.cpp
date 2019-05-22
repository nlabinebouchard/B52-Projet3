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

void GAEngine::evolve() {//retourner un bool pour savoir que le evolve est finit


	if (mParameters.maximumGenerationCount > mEpoch)
	{


		mPopEngIt = mPopulationEngines.begin();
		size_t indice = 0;

		while (mPopEngIt!=mPopulationEngines.end())
		{
			//rajouter une condition if pour ne pas faire le evolve si la converge d'une pop est atteinte
			mFitnessHistory.insertNewStatistics(indice, mPopEngIt->statistics());

			mPopEngIt->evolve();

			++mPopEngIt;
			++indice;
		}


	
	}

	else
	{

	}

//vérifier les condtions de sorties pour arrêter de faire les evolve, avec une variable bool
	//convergencerate, maximumGeneration, 
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

void GAEngine::standardDeviation()
{

}



//calcul écart type des maximums de exemple 10 derniers statistics, si le rate de convergence est atteint, on arrête en comparant les écart types