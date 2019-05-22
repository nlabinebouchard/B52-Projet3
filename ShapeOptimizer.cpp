#include "ShapeOptimizer.h"
#include "Console\Console.h"
#include "Console\ConsoleContext.h"
#include "Console\ConsoleKeyReader.h"
#include "Canevas.h"
#include "Console\ConsoleKeyFilterDown.h"
#include "Console\ConsoleKeyFilterModifiers.h"
#include <iostream>


void ShapeOptimizer::setup(SOParameters & SOParams, GAParameters & GAParams)
{

	// Params du canevas
	SOParams.height = 200;
	SOParams.width = 200;
	SOParams.obstacleCount = 20;
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

void ShapeOptimizer::accueil(ConsoleKeyReader &curReader,ConsoleWriter &curWriter, ConsoleKeyReader::KeyEvents &keys)
{
	bool start{ false };

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
					break;
				case 'w':	// diminue le nombre d'obstacle de 10
					break;
				case 'e':	// réinitialise les positions des obstacles
					break;
				case '1':	// Détermine le nombre de population
					break;
				case '2':	// Détermine le nombre de population:
					break;
				case '3':	// Détermine le nombre de population:
					break;
				case '4':	// Détermine le nombre de population:
					break;


				case 32: start = true; // barre d'espace // debute l'évolution
					break;

				default:
					break;
				}
			}
		}
		//curWriter.createImage("Allo").drawRect(5 + keyPressed.keyA(), 5 + keyPressed.keyA(), 10, 10, ' ', ConsoleColor::bR);
		curWriter.write("Allo");
	}
}


int main()
{
	Canevas canvas;
	SOParameters SOparams;
	GAParameters GAparam;
	ShapeOptimizer main;

	main.setup(SOparams, GAparam);

	canvas.setSize(50, 50);
	canvas.setObstacleCount(5);


	ConsoleContext myContext(canvas.width(), canvas.height(), "Projet-3 B52", 10, 10, L"Consolas");
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



}