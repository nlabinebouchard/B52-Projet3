#include "ShapeOptimizer.h"
#include "Console\Console.h"
#include "Console\ConsoleContext.h"
#include "Console\ConsoleKeyFilterDown.h"
#include "Console\ConsoleKeyFilterModifiers.h"

#include "CrossoverChromoSinglePoint.h"
#include "CrossoverGeneSinglePoint.h"

#include "MutatorChromo.h"
#include "MutatorGene.h"
#include "MutatorInversionChromo.h"
#include "MutatorInversionGene.h"
#include "MutatorScrambleChromo.h"
#include "MutatorScrambleGene.h"
#include "MutatorSwapChromo.h"
#include "MutatorSwapGene.h"
#include "MutatorGeneLeastSignificant.h"
#include "MutatorExtreme.h"
#include "MutatorUltime.h"

#include "SelectorRouletteWheel.h"
#include "SelectorTournament.h"
#include "SelectorRankwise.h"
#include "SelectorUniform.h"

#include "CircleSolution.h"
#include "OrthoRectSolution.h"

void ShapeOptimizer::setup(SOParameters & SOParams, GAParameters & GAParams)
{
	// Params du canevas
	SOParams.height = 400;
	SOParams.width = 400;
	SOParams.obstacleCount = 1;
	// Params du Genetic algorithm engine
	setupMidRun(GAParams);

}

void ShapeOptimizer::setupMidRun(GAParameters & GAParams)
{
	GAParams.convergenceRate = 10;
	GAParams.crossover = new CrossoverChromoSinglePoint;
	GAParams.elitismSize = 2;
	GAParams.maximumGenerationCount = 1000;
	GAParams.mutationRate = 0.10;
	GAParams.mutator = new MutatorGene;
	GAParams.mutator->setMutationRate(GAParams.mutationRate);
	GAParams.populationCount = 1;
	GAParams.populationSize = 10;
	GAParams.selector = new SelectorTournament;
	GAParams.solutionSample = new CircleSolution(&mCanvas);
	//GAParams.solutionSample = new OrthoRectSolution(&mCanvas);


}


void ShapeOptimizer::run()
{
	SOParameters SOparams;
	GAParameters GAparam;

	setup(SOparams, GAparam);

	mCanvas.setup(SOparams);

	mEngine.setup(GAparam);

	ConsoleContext myContext(mCanvas.width(), mCanvas.height(), "Projet-3 B52", 2, 2, L"Consolas");
	Console::defineContext(myContext);
	ConsoleWriter &curWriter{ Console::getInstance().writer() };
	std::vector<Obstacle> const &vectObstacle{ mCanvas.obstacles() };

	curWriter.createImage("Forme");

	ConsoleKeyReader::KeyEvents keys;
	ConsoleKeyReader &curReader{ Console::getInstance().keyReader() };
	curReader.installFilter(new ConsoleKeyFilterDown);
	curReader.installFilter(new ConsoleKeyFilterModifiers);

	accueil(curReader, curWriter, keys, mCanvas);

}

void ShapeOptimizer::accueil(ConsoleKeyReader &curReader,ConsoleWriter &curWriter, ConsoleKeyReader::KeyEvents &keys, Canevas &canvas)
{
	bool start{ false };
	bool affichageObs{ true };
	size_t etatSolution{ 1 };
	size_t pressedCrossover{};
	size_t pressedMutator{};
	size_t pressedSelector{};

	std::vector<Obstacle> const &vectObstacle{ canvas.obstacles() };

	GAParameters GAparam;

	setupMidRun(GAparam);

	//Affichage de base
	afficherObstacle(curWriter, canvas, affichageObs);
	afficherSolution(curWriter, canvas, etatSolution);

	while (start != true)
	{ 
		// menu d'acceuil

		curReader.read(keys);

		if (keys.size() != 0)
		{
			for (auto &keyPressed : keys)
			{

				switch (keyPressed.keyA())
				{
				case 'q':	// augmente le nombre d'obstacle de 10
					
					if (vectObstacle.size() <= 245){
						canvas.setObstacleCount(vectObstacle.size() + 10);
					}
					break;
				case 'w':	// diminue le nombre d'obstacle de 10

					if (vectObstacle.size() >= 15) {
						canvas.setObstacleCount(vectObstacle.size() - 10);
					}
					curWriter.removeImage("Forme");
					curWriter.createImage("Forme");



					for (size_t i{ 0 }; i < mEngine.getParameters().populationCount; ++i) {
						for (size_t j{ 0 }; j < mEngine.population(i).size(); ++j) {
							static_cast<ShapeSolution const &>(mEngine.population(i)[j]).draw(curWriter);
						}
					}

					break;

				case 'e':	// r�initialise les positions des obstacles

					canvas.randomizeObstaclesPosition();
					curWriter.removeImage("Forme");
					curWriter.createImage("Forme");


					for (size_t i{ 0 }; i < mEngine.getParameters().populationCount; ++i) {
						for (size_t j{ 0 }; j < mEngine.population(i).size(); ++j) {
							static_cast<ShapeSolution const &>(mEngine.population(i)[j]).draw(curWriter);
						}
					}

					break;
				case '1':	// D�termine le nombre de population
					GAparam.populationCount = 1;
					break; 
				case '2':	// D�termine le nombre de population:
					GAparam.populationCount = 2;
					break;
				case '3':	// D�termine le nombre de population:
					GAparam.populationCount = 3;
					break;
				case '4':	// D�termine le nombre de population:
					GAparam.populationCount = 4;
					break;
				case 'a':	// bascule forme a traiter ( cercle - rectangle - polygone)
					
					if (dynamic_cast<CircleSolution const *>(GAparam.solutionSample))
					{
						delete GAparam.solutionSample;
						GAparam.solutionSample =  new OrthoRectSolution(&mCanvas);
					}
					else if (dynamic_cast<OrthoRectSolution const *>(GAparam.solutionSample))
					{
						//placeholder for polygone
						delete GAparam.solutionSample;
						GAparam.solutionSample = new CircleSolution(&mCanvas);
					}
					else { // if (dynamic_cast<PolygoneSolution const *>(GAparam.solutionSample))
						delete GAparam.solutionSample;
						GAparam.solutionSample = new CircleSolution(&mCanvas);
					}

					break;
				case 'z':	// bascule obstacle entre affichage 0 et tous
					
					affichageObs = !affichageObs;

					break;
				case 'x':	// cache ou affiche la forme g�om�trique

					etatSolution = !etatSolution;

					break;
				case 32: 
					mEngine = GAEngine();
					mEngine.setup(GAparam);
					ShapeOptimizer::evolution(curReader, curWriter, keys, canvas); // barre d'espace // debute l'�volution
					break;
				case 'h':	//Changement CrossOver
					if (pressedCrossover >= 1) {
						pressedCrossover = 0;
					}
					else {
						++pressedCrossover;
					}
					changeCrossover(GAparam, pressedCrossover);	//toute casse quand je le mets et je ne comprends pas pk...Charles
					break;
				case 'k':	//Chagement Mutator
					if (pressedMutator >= 10) {
						pressedMutator = 0;
					}
					else {
						++pressedMutator;
					}
					changeMutator(GAparam, pressedMutator);
					break;
				case 'l':	//Changement Selector
					if (pressedSelector >= 3) {
						pressedSelector = 0;
					}
					else {
						++pressedSelector;
					}
					changeSelector(GAparam, pressedSelector);
					break;
				}
			}
		}
		afficherObstacle(curWriter, canvas, affichageObs);
		afficherSolution(curWriter, canvas, etatSolution);
		curWriter.write("Forme"); // affiche l'image
		
	}
}

void ShapeOptimizer::evolution(ConsoleKeyReader & curReader, ConsoleWriter & curWriter, ConsoleKeyReader::KeyEvents & keys,Canevas &canvas)
{
	bool start{ false };
	bool affichageObs{ true };
	bool enPause{ false };
	size_t etatSolution{ 1 };

	while (start != true)
	{
		// menu d'acceuil

		curReader.read(keys);


		if (keys.size() != 0)
		{
			for (auto &keyPressed : keys)
			{
				switch (keyPressed.keyA())
				{
				case 's':
					if (enPause) {
						mEngine.evolve();
					}
					break;
				case 'z':	// Bascule l'affichage des obstacles ( aucun - tous)
					affichageObs = !affichageObs;
					ShapeOptimizer::afficherObstacle(curWriter,canvas,affichageObs);
					break;
				case 'x': // Bascule l'affichage des solution ( aucune - toutes - la meilleurs).
					++etatSolution;
					if (etatSolution == 3) { etatSolution = 0; }
					break;
				case 27: 
					ShapeOptimizer::accueil(curReader, curWriter, keys,canvas);
					break;
				case 32: // barre d'espace // met sur pause
					enPause = !enPause;
					break;
				}
			}
		}
		//curWriter.createImage("Forme").drawRect(5 + keyPressed.keyA(), 5 + keyPressed.keyA(), 10, 10, ' ', ConsoleColor::bR);
		if (!enPause) {
			mEngine.evolve();

		}

		curWriter.removeImage("Forme");
		curWriter.createImage("Forme");
		afficherObstacle(curWriter, canvas, affichageObs);
		afficherSolution(curWriter, canvas, etatSolution);

		curWriter.write("Forme"); // affiche l'image
	}


}

void ShapeOptimizer::afficherSolution(ConsoleWriter & curWriter, Canevas & canvas, size_t etat)
{
	switch (etat)
	{
	case 0:
		break;
	case 1:
		for (size_t i{ 0 }; i < mEngine.getParameters().populationCount; ++i) {
			for (size_t j{ 0 }; j < mEngine.population(i).size(); ++j) {
				static_cast<ShapeSolution const &>(mEngine.population(i)[j]).draw(curWriter);
			}
		}
		break;
	case 2:
		for (size_t i{ 0 }; i < mEngine.getParameters().populationCount; ++i) {
			static_cast<ShapeSolution const &>(mEngine.population(i)[0]).draw(curWriter);
		}
		break;
	}
}

void ShapeOptimizer::afficherObstacle(ConsoleWriter & curWriter,Canevas &canvas, bool & affichageObs)
{
	std::vector<Obstacle> const &vectObstacle{ canvas.obstacles() };

	if (affichageObs) {
		for (size_t i{ 0 }; i < vectObstacle.size(); ++i)
		{
			curWriter.image("Forme").drawPoint(vectObstacle[i].posX(), vectObstacle[i].posY(), ' ', ConsoleColor::bW);;
		}
	}
	else {
		for (size_t i{ 0 }; i < vectObstacle.size(); ++i)
		{
			curWriter.image("Forme").drawPoint(vectObstacle[i].posX(), vectObstacle[i].posY(), ' ', ConsoleColor::bk);;
		}
	}
}

void ShapeOptimizer::changeCrossover(GAParameters & GAEparam, size_t pressed)
{
	delete GAEparam.crossover;

	switch (pressed) {
	case 0:
		GAEparam.crossover = new CrossoverChromoSinglePoint;
		break;
	case 1:
		GAEparam.crossover = new CrossoverGeneSinglePoint;
		break;
	}
}

void ShapeOptimizer::changeMutator(GAParameters & GAEparam, size_t pressed)
{
	delete GAEparam.mutator;

	switch (pressed){
		case 0:
			GAEparam.mutator = new MutatorChromo;
			break;
		case 1:
			GAEparam.mutator = new MutatorGene;
			break;
		case 2:
			GAEparam.mutator = new MutatorInversionChromo;
			break;
		case 3:
			GAEparam.mutator = new MutatorInversionGene;
			break;
		case 4:
			GAEparam.mutator = new MutatorScrambleChromo;
			break;
		case 5:
			GAEparam.mutator = new MutatorScrambleGene;
			break;
		case 6:
			GAEparam.mutator = new MutatorSwapChromo;
			break;
		case 7:
			GAEparam.mutator = new MutatorSwapChromo;
			break;
		case 8:
			GAEparam.mutator = new MutatorGeneLeastSignificant;
			break;
		case 9:
			GAEparam.mutator = new MutatorExtreme;
			
			//Faire dinamic cast

			// Faire l'ajout des mutator ici
			//GAEparam.mutator.add(MutatorGene, 10);
			//GAEparam.mutator.add(MutatorSwapChromo, 3);
			//GAEparam.mutator.add(MutatorInversionGene, 6);
			//GAEparam.mutator.add(MutatorScrambleGene, 8);
			break;
		case 10:
			GAEparam.mutator = new MutatorUltime;
			//Faire dinamic cast

			// Faire l'ajout des mutator ici
			//GAEparam.mutator.add(MutatorGene);
			//GAEparam.mutator.add(MutatorSwapChromo);
			//GAEparam.mutator.add(MutatorInversionGene);
			//GAEparam.mutator.add(MutatorScrambleGene);
			break;
	}
}

void ShapeOptimizer::changeSelector(GAParameters & GAEparam, size_t pressed)
{
	delete GAEparam.selector;
	switch (pressed) {
		case 0:
			GAEparam.selector = new SelectorRouletteWheel;
			break;
		case 1:
			GAEparam.selector = new SelectorRankwise;
			break;
		case 2:
			GAEparam.selector = new SelectorTournament;
			break;
		case 3:
			GAEparam.selector = new SelectorUniform;
			break;
	}
}




int main()
{
	ShapeOptimizer masterClass;


	masterClass.run();

}