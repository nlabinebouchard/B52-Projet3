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


	if (mParameters.maximumGenerationCount >= mEpoch)
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

	mEpoch = 0;
	mParameters = parameters;

	mFitnessHistory.setup(mParameters.populationCount);

	mPopulationEngines.resize(mParameters.populationCount);


	for (size_t i = 0; i < parameters.populationCount; i++)
	{
		mPopulationEngines[i]=(PopulationEngine());
		mPopulationEngines[i].setElitism(mParameters.elitismSize);
		mPopulationEngines[i].setCrossover(mParameters.crossover);
		mPopulationEngines[i].setMutator(mParameters.mutator);
		mPopulationEngines[i].setPopulation(mParameters.populationSize, mParameters.solutionSample);
		mPopulationEngines[i].setSelector(mParameters.selector);
		
	}

	parameters.crossover = nullptr;
	parameters.mutator = nullptr;
	parameters.selector = nullptr;


	
}

void GAEngine::standardDeviation(size_t epochNumber, size_t popEngine)
{
	fitness_t mean{0};
	fitness_t variance{ 0 };
	fitness_t standardDeviation{ 0 };


	for (size_t i = mEpoch; i > mEpoch-epochNumber; i++)
	{
		mean+=mFitnessHistory.getStatistics(popEngine, i).maximum;
	}

	mean /= epochNumber;

	for (size_t i = mEpoch; i > mEpoch - epochNumber; i++)
	{
		variance += sqrt(mFitnessHistory.getStatistics(popEngine, i).maximum - mean);
	}

	standardDeviation = sqrt(variance / epochNumber);

	
}

GAParameters  const & GAEngine::getParameters() const
{
	return mParameters;
}


//calcul écart type des maximums de exemple 10 derniers statistics, si le rate de convergence est atteint, on arrête en comparant les écart types