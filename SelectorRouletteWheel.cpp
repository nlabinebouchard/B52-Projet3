#include "SelectorRouletteWheel.h"
#include "Population.h"
#include "Solution.h"	//	V�rifier s'il faut supprimer ce include l�

void SelectorRouletteWheel::prepare(Population const & population)
{
	//	Calculer le taux de fitness du parent par rapport au rester de la population
	//	Faire une r�gle de trois pour le mettre sur 100
	//	Mettre les valeurs r�sultante dans le vecteur<double>

	//	-----
	//	Plus le fitness du Chromosone est grand, plus il y a de chance qu'il soit s�lectionner 
	//	-----






}


Solution & SelectorRouletteWheel::select(Population & population) const
{

	
	//	Faire un random de 0 � 100
	//	Trouver la la Solution associ� � cette valeur 
	//	Retourner le parent s�lectionner


	//	retrun UN parent ->Solution&

}
