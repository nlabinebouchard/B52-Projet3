#ifndef SHAPEOPTIMIZER_H
#define SHAPEOPTIMIZER_H

#include "SOParameters.h"
#include "GAParameters.h"
#include "Console\ConsoleKeyReader.h"
#include "Canevas.h"


class ConsoleWriter;

class ShapeOptimizer
{
public:
	ShapeOptimizer() = default;
	~ShapeOptimizer() = default;

	void setup(SOParameters  &SOParams, GAParameters &GAParams);

	void run();

	//void accueil(ConsoleKeyReader &curReader, ConsoleWriter &curWriter, ConsoleKeyReader::KeyEvents &keys);

	void accueil(ConsoleKeyReader &curReader, ConsoleWriter &curWriter, ConsoleKeyReader::KeyEvents &keys, Canevas &canvas);

	void evolution(ConsoleKeyReader &curReader, ConsoleWriter &curWriter, ConsoleKeyReader::KeyEvents &keys, Canevas &canvas);

	void afficherObstacle(ConsoleWriter & curWriter, Canevas &canvas, bool & affObs);
	
private:
	//Canevas canvas;
};

#endif // SHAPEOPTIMIZER_H