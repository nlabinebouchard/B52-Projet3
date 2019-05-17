#include "ShapeOptimizer.h"
#include "Console\Console.h"
#include "Console\ConsoleContext.h"
#include "Console\ConsoleKeyReader.h"
#include "Canevas.h"
#include "Console\ConsoleKeyFilterDown.h"
#include "Console\ConsoleKeyFilterModifiers.h"
#include <iostream>


//void ShapeOptimizer::setup(SOParameters const& SOParams, GAParameters const& GAParams)
//{
//
//	// constructeur du canevas call fct setup du canevas
//}

void ShapeOptimizer::setupTemp(SOParameters const & SOParams)
{



}

void ShapeOptimizer::run()
{
	Canevas canvas;



}


int main()
{
	Canevas canvas;

	canvas.setSize(200, 200);
	canvas.setObstacleCount(20);

	ConsoleContext myContext(canvas.width(), canvas.height(), "Projet-3 B52", 5, 5, L"Consolas");

	Console::defineContext(myContext);

	ConsoleWriter &curWriter{ Console::getInstance().writer() };

	std::vector<Obstacle> const &vectObstacle{ canvas.obstacles() };

	for (size_t i{ 0 }; i < vectObstacle.size(); ++i)
	{
		curWriter.createImage("Allo").drawPoint(vectObstacle[i].posX(), vectObstacle[i].posY(), ' ', ConsoleColor::bc);
	}

	curWriter.createImage("Allo").drawRect(5, 5, 10, 10, ' ', ConsoleColor::bR);

	curWriter.write("Allo");


	bool quit{ false};

	ConsoleKeyReader::KeyEvents keys;
	
	ConsoleKeyReader &curReader{ Console::getInstance().keyReader() };

	curReader.installFilter(new ConsoleKeyFilterDown);
	curReader.installFilter(new ConsoleKeyFilterModifiers);

	while (quit != true) {

		curReader.read(keys);

		if (keys.size() != 0) {
			for (auto &keyPressed : keys) {

				switch (keyPressed.keyA())
				{
				case 'q': quit = true;
					break;
				case 'w':
					break;
				default: curWriter.createImage("Allo").drawRect(5+ keyPressed.keyA(), 5+keyPressed.keyA(), 10, 10, ' ', ConsoleColor::bR);
					break;
				}






			}

		}

		curWriter.write("Allo");
	}


}