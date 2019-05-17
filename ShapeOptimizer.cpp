#include "ShapeOptimizer.h"
#include "Console\Console.h"
#include "Console\ConsoleContext.h"
#include "Canevas.h"



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

}


int main()
{
	Canevas canvas;

	canvas.setSize(50, 50);
	canvas.setObstacleCount(4);
	
	ConsoleContext myContext(canvas.width(), canvas.height(), "Projet-3 B52", 20, 20, L"Consolas");

	Console::defineContext(myContext);

	ConsoleWriter curWriter = Console::getInstance().writer();

	std::vector<Obstacle> const &vectObstacle{ canvas.obstacles() };

	for (size_t i{ 0 }; i < vectObstacle.size(); ++i)
	{
		curWriter.createImage("Allo").drawPoint(vectObstacle[i].posX(), vectObstacle[i].posY(), 'o', ConsoleColor::tc);
	}
	
	curWriter.write("Allo");






	int a{0};

}