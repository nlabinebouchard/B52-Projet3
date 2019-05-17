#include "SelectorRouletteWheel.h"
#include "Population.h"
//#include "Solution.h"	//	Vérifier s'il faut supprimer ce include là
#include "RandomUtil.h"

void SelectorRouletteWheel::prepare(Population const & population)
{
	//	Calculer le taux de fitness du parent par rapport au rester de la population
	//	Faire une règle de trois pour le mettre sur 100
	//	Mettre les valeurs résultante dans le vecteur<double>

	//	-----
	//	Plus le fitness du Chromosone est grand, plus il y a de chance qu'il soit sélectionner 
	//	-----
	mRankWeight.resize(population.size());

	mTotalFitness = 0;
	for (size_t i{}; i < population.size(); ++i) {
		mTotalFitness+=population[i].fitness();
	}

	for (size_t i{}; i < population.size(); ++i) {
		mWeight = population[i].fitness();
		mProbabilities = (mWeight / mTotalFitness) * 100;
		mRankWeight.insert(mRankWeight.begin()+i, mProbabilities);
	}
}

Solution & SelectorRouletteWheel::select(Population & population) const
{

	//	Faire un random de 0 à 100
	//	Trouver la la Solution associé à cette valeur 
	//	Retourner le parent sélectionner
	//	retrun UN parent ->Solution&

	mValueRandom = RandomUtil::randomRangeHundred(0.00, 100.00);

	for (size_t i{}; i < population.size(); ++i) {
		mStuckInterval += mRankWeight.at(i);
		if (i > 0) {
			if (mValueRandom >= mRankWeight.at(i-1) && mValueRandom < mStuckInterval) {
				return population[i];
			}
		}
		else {
			if (mValueRandom >= 0 && mValueRandom < mStuckInterval) {
				return population[i];
			}
		}
	}
}
