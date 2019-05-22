#include "ShapeOptimizer.h"
#include "Console\Console.h"
#include "Console\ConsoleContext.h"
#include "Console\ConsoleKeyFilterDown.h"
#include "Console\ConsoleKeyFilterModifiers.h"
#include <iostream>


void ShapeOptimizer::setup(SOParameters & SOParams, GAParameters & GAParams)
{

	// Params du canevas
	SOParams.height = 400;
	SOParams.width = 400;
	SOParams.obstacleCount = 50;
	// Params du Genetic algorithm engine
	GAParams.convergenceRate;		// = value
	GAParams.crossover;				// = value
	GAParams.elitismSize;			// = value
	GAParams.maximumGenerationCount;// = value
	GAParams.mutationRate;			// = value
	GAParams.mutator;				// = value
	GAParams.populationCount;		// = value
	GAParams.populationSize;		// = value
	GAParams.selector;				// = value
	GAParams.solutionSample;		// = value



}


void ShapeOptimizer::run()
{
	Canevas canvas;



}

void ShapeOptimizer::accueil(ConsoleKeyReader &curReader,ConsoleWriter &curWriter, ConsoleKeyReader::KeyEvents &keys, Canevas &canvas)
{
	bool start{ false };

	std::vector<Obstacle> const &vectObstacle{ canvas.obstacles() };

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
						curWriter.image("Allo").drawPoint(vectObstacle[i].posX(), vectObstacle[i].posY(), ' ', ConsoleColor::bc);
					}
					break;


				case 'w':	// diminue le nombre d'obstacle de 10

					if (vectObstacle.size() >= 15) {
						canvas.setObstacleCount(vectObstacle.size() - 10);
					}
					curWriter.removeImage("Allo");
					curWriter.createImage("Allo");

					for (size_t i{ 0 }; i < vectObstacle.size(); ++i)
					{
						curWriter.image("Allo").drawPoint(vectObstacle[i].posX(), vectObstacle[i].posY(), ' ', ConsoleColor::bc);
					}

					break;

				case 'e':	// réinitialise les positions des obstacles

					canvas.randomizeObstaclesPosition();

					break;
				case '1':	// Détermine le nombre de population
					break; 
				case '2':	// Détermine le nombre de population:
					break;
				case '3':	// Détermine le nombre de population:
					break;
				case '4':	// Détermine le nombre de population:
					break;
				case 'a':	// bascule forme a traiter ( cercle - rectangle - polygone)
					break;
				case 'z':	// bascule obstacle entre 0 et tous
					break;
				case 'x':	// cache ou affiche la forme géométrique
					break;
				case 32: start = true; // barre d'espace // debute l'évolution
				
					break;
				}
			}
		}

	
		//curWriter.createImage("Allo").drawRect(5 + keyPressed.keyA(), 5 + keyPressed.keyA(), 10, 10, ' ', ConsoleColor::bR);
		curWriter.write("Allo"); // affiche l'image
		
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
				case 27: ShapeOptimizer::accueil(curReader, curWriter, keys,canvas);

					break;
				case 32: // barre d'espace // met sur pause
					enPause = !enPause;
					break;
				}
			}
		}
		//curWriter.createImage("Allo").drawRect(5 + keyPressed.keyA(), 5 + keyPressed.keyA(), 10, 10, ' ', ConsoleColor::bR);
		curWriter.write("Allo"); // affiche l'image
	}
}

void ShapeOptimizer::afficherSolution(ConsoleWriter & curWriter, Canevas & canvas, size_t etat)
{
	switch (etat)
	{
	case 0:
		curWriter.createImage("Allo").drawRect(5, 5, 10, 10, ' ', ConsoleColor::bk); // a changer pour une boucle qui passe a travers la population pou rfaire afficher les solution avec la methode draw dans les obj
		break;
	case 1:
		curWriter.createImage("Allo").drawRect(5, 5, 10, 10, ' ', ConsoleColor::bR);
		break;
	case 2:
		curWriter.createImage("Allo").drawRect(5, 5, 10, 10, ' ', ConsoleColor::bR);
		break;
	}
}

void ShapeOptimizer::afficherObstacle(ConsoleWriter & curWriter,Canevas &canvas, bool & affichageObs)
{
	std::vector<Obstacle> const &vectObstacle{ canvas.obstacles() };

	if (affichageObs) {
		for (size_t i{ 0 }; i < vectObstacle.size(); ++i)
		{
			curWriter.image("Allo").drawPoint(vectObstacle[i].posX(), vectObstacle[i].posY(), ' ', ConsoleColor::bc);;
		}
	}
	else {
		for (size_t i{ 0 }; i < vectObstacle.size(); ++i)
		{
			curWriter.image("Allo").drawPoint(vectObstacle[i].posX(), vectObstacle[i].posY(), ' ', ConsoleColor::bk);;
		}
	}
}


int main()
{
	Canevas canvas;
	SOParameters SOparams;
	GAParameters GAparam;
	ShapeOptimizer main;

	main.setup(SOparams, GAparam);

	canvas.setup(SOparams);

	ConsoleContext myContext(canvas.width(), canvas.height(), "Projet-3 B52", 2, 2, L"Consolas");
	Console::defineContext(myContext);
	ConsoleWriter &curWriter{ Console::getInstance().writer() };
	std::vector<Obstacle> const &vectObstacle{ canvas.obstacles() };

	for (size_t i{ 0 }; i < vectObstacle.size(); ++i)
	{
		curWriter.createImage("Allo").drawPoint(vectObstacle[i].posX(), vectObstacle[i].posY(), ' ', ConsoleColor::bc);
	}

	curWriter.createImage("Allo").drawRect(5, 5, 10, 10, ' ', ConsoleColor::bR);
	curWriter.write("Allo");


	bool start{ false };

	ConsoleKeyReader::KeyEvents keys;
	ConsoleKeyReader &curReader{ Console::getInstance().keyReader() };
	curReader.installFilter(new ConsoleKeyFilterDown);
	curReader.installFilter(new ConsoleKeyFilterModifiers);

	main.evolution(curReader,curWriter, keys, canvas);
	

}