#ifndef SHAPEOPTIMIZER_H
#define SHAPEOPTIMIZER_H

#include "SOParameters.h"
#include "GAParameters.h"


class ShapeOptimizer
{
public:
	ShapeOptimizer() = default;
	~ShapeOptimizer() = default;

	void setup(SOParameters  &SOParams, GAParameters &GAParams);

	void run();

	//void accueil(ConsoleKeyReader &curReader, ConsoleWriter &curWriter, ConsoleKeyReader::KeyEvents &keys);
	void accueil(ConsoleKeyReader &curReader, ConsoleWriter &curWriter, ConsoleKeyReader::KeyEvents &keys);
};

#endif // SHAPEOPTIMIZER_H