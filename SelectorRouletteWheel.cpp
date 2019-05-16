#include "SelectorRouletteWheel.h"
#include "Population.h"
#include "Solution.h"	//	Vérifier s'il faut supprimer ce include là

void SelectorRouletteWheel::prepare(Population const & population)
{
	//	Calculer le taux de fitness du parent par rapport au rester de la population
	//	Faire une règle de trois pour le mettre sur 100
	//	Mettre les valeurs résultante dans le vecteur<double>

	//	-----
	//	Plus le fitness du Chromosone est grand, plus il y a de chance qu'il soit sélectionner 
	//	-----






}


Solution & SelectorRouletteWheel::select(Population & population) const
{

	
	//	Faire un random de 0 à 100
	//	Trouver la la Solution associé à cette valeur 
	//	Retourner le parent sélectionner


	//	retrun UN parent ->Solution&

}
