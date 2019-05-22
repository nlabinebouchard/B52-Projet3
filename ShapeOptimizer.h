#ifndef SHAPEOPTIMIZER_H
#define SHAPEOPTIMIZER_H

#include "SOParameters.h"
#include "GAParameters.h"
#include "Console\Console.h"
#include "Console\ConsoleContext.h"
#include "Console\ConsoleKeyReader.h"
#include "Canevas.h"
#include "Console\ConsoleKeyFilterDown.h"
#include "Console\ConsoleKeyFilterModifiers.h"


class ShapeOptimizer
{
public:
	ShapeOptimizer() = default;
	~ShapeOptimizer() = default;

	void setup(SOParameters  &SOParams, GAParameters &GAParams);

	void run();

	//void accueil(ConsoleKeyReader &curReader, ConsoleWriter &curWriter, ConsoleKeyReader::KeyEvents &keys);

	void accueil(ConsoleKeyReader &curReader, ConsoleWriter &curWriter, ConsoleKeyReader::KeyEvents &keys, Canevas &canvas);

	void evolution(ConsoleKeyReader &curReader, ConsoleWriter &curWriter, ConsoleKeyReader::KeyEvents &keys);

private:
	//Canevas canvas;

	void afficherObstacle();

};

#endif // SHAPEOPTIMIZER_H