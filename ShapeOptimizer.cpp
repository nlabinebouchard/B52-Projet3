#include "ShapeOptimizer.h"
#include "Console\Console.h"
#include "Console\ConsoleContext.h"
#include "Console\ConsoleKeyFilterDown.h"
#include "Console\ConsoleKeyFilterModifiers.h"
#include "CrossoverChromoSinglePoint.h"
#include "CrossoverGeneSinglePoint.h"
#include "MutatorChromo.h"
#include "MutatorGene.h"
#include "MutatorSwapGene.h"
#include "SelectorRouletteWheel.h"
#include "SelectorTournament.h"
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
	size_t etatForme{};

	std::vector<Obstacle> const &vectObstacle{ canvas.obstacles() };

	GAParameters GAparam;

	setupMidRun(GAparam);

	//Affichage de base
	afficherObstacle(curWriter, canvas, affichageObs);
	for (size_t i{ 0 }; i < mEngine.getParameters().populationCount; ++i) {
		for (size_t j{ 0 }; j < mEngine.population(i).size(); ++j) {
			static_cast<ShapeSolution const &>(mEngine.population(i)[j]).draw(curWriter);
		}
	}

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
					for (size_t i{ vectObstacle.size()-10 }; i < vectObstacle.size(); ++i)
					{
						curWriter.image("Forme").drawPoint(vectObstacle[i].posX(), vectObstacle[i].posY(), ' ', ConsoleColor::bW);
					}
					break;


				case 'w':	// diminue le nombre d'obstacle de 10

					if (vectObstacle.size() >= 15) {
						canvas.setObstacleCount(vectObstacle.size() - 10);
					}
					curWriter.removeImage("Forme");
					curWriter.createImage("Forme");

					for (size_t i{ 0 }; i < vectObstacle.size(); ++i)
					{
						curWriter.image("Forme").drawPoint(vectObstacle[i].posX(), vectObstacle[i].posY(), ' ', ConsoleColor::bW);
					}

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

					for (size_t i{ 0 }; i < vectObstacle.size(); ++i)
					{
						curWriter.image("Forme").drawPoint(vectObstacle[i].posX(), vectObstacle[i].posY(), ' ', ConsoleColor::bW);
					}

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
						//placeholder for solution
						delete GAparam.solutionSample;
						GAparam.solutionSample = new CircleSolution(&mCanvas);
					}
					else {
						delete GAparam.solutionSample;
						GAparam.solutionSample = new CircleSolution(&mCanvas);
					}

					break;
				case 'z':	// bascule obstacle entre 0 et tous
					start = false;
					break;
				case 'x':	// cache ou affiche la forme g�om�trique
					break;
				case 32: 
					mEngine = GAEngine();
					mEngine.setup(GAparam);
					ShapeOptimizer::evolution(curReader, curWriter, keys, canvas); // barre d'espace // debute l'�volution

					break;
				}
			}
		}

		curWriter.write("Forme"); // affiche l'image
		
	}
}

void ShapeOptimizer::evolution(ConsoleKeyReader & curReader, ConsoleWriter & curWriter, ConsoleKeyReader::KeyEvents & keys,Canevas &canvas)
{
	bool start{ false };
	bool affichageObs{ true };
	bool enPause{ false };
	size_t etatSolution{ 1 };
	int a{};

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
					ShapeOptimizer::afficherSolution(curWriter, canvas, etatSolution);
					break;
				case 'k':
					++a;
					break;
				case 27: 
					ShapeOptimizer::accueil(curReader, curWriter, keys,canvas);
					break;
				case 32: // barre d'espace // met sur pause
					enPause = !enPause;
					break;
				case 't':	//Changement de CrossOver
					//GAParams.crossover = new CrossoverChromoSinglePoint;
					//GAParams.crossover = new CrossoverGeneSinglePoint;
					break;
				case 'g':	//Changement de Mutator
					//GAParams.mutator = new MutatorChromo;
					//GAParams.mutator = new MutatorSwapGene;

					break;
				case 'h':	//Changement de Selector
					//GAParams.selector = new SelectorRouletteWheel;
					//GAParams.selector = new SelectorUniform;
					//mEngine.getParameters().selector = new SelectorUniform;

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
		for (size_t i{ 0 }; i < mEngine.getParameters().populationCount; ++i) {
			for (size_t j{ 0 }; j < mEngine.population(i).size();++j) {
				static_cast<ShapeSolution const &>(mEngine.population(i)[j]).draw(curWriter);
			}
		}

		curWriter.write("Forme"); // affiche l'image
	}


}

void ShapeOptimizer::afficherSolution(ConsoleWriter & curWriter, Canevas & canvas, size_t etat)
{
	switch (etat)
	{
	case 0:
		curWriter.createImage("Forme").drawRect(5, 5, 10, 10, ' ', ConsoleColor::bk); // a changer pour une boucle qui passe a travers la population pou rfaire afficher les solution avec la methode draw dans les obj
		break;
	case 1:
		curWriter.createImage("Forme").drawRect(5, 5, 10, 10, ' ', ConsoleColor::bR);
		break;
	case 2:
		curWriter.createImage("Forme").drawRect(5, 5, 10, 10, ' ', ConsoleColor::bC);
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


int main()
{
	ShapeOptimizer masterClass;


	masterClass.run();

}