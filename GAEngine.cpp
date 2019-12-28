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
			mFitnessHistory.insertNewStatistics(indice, mPopEngIt->statistics());

			//condition if pour ne pas faire le evolve si la converge d'une pop est atteinte
			//if (mFitnessHistory.standardDeviation(mParameters.convergenceEpochNb, indice)>mParameters.convergenceRate)
			//{
				mPopEngIt->evolve();
			//}


			++mPopEngIt;
			++indice;
		}
	
	}

	++mEpoch;

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
	delete parameters.solutionSample;

	
}

GAParameters  const & GAEngine::getParameters() const
{
	return mParameters;
}
