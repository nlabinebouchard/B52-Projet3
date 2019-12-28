#ifndef SHAPEOPTIMIZER_H
#define SHAPEOPTIMIZER_H

#include "SOParameters.h"
#include "GAParameters.h"
#include "Console\ConsoleKeyReader.h"
#include "Canevas.h"
#include "GAEngine.h"


class ConsoleWriter;

class ShapeOptimizer
{
public:

	ShapeOptimizer() = default;
	~ShapeOptimizer() = default;

	void setup(SOParameters  &SOParams, GAParameters &GAParams);

	void run();

	void setupMidRun(GAParameters & GAParams);

	void accueil(ConsoleKeyReader &curReader, ConsoleWriter &curWriter, ConsoleKeyReader::KeyEvents &keys, Canevas &canvas);

	void evolution(ConsoleKeyReader &curReader, ConsoleWriter &curWriter, ConsoleKeyReader::KeyEvents &keys, Canevas &canvas);

	void afficherSolution(ConsoleWriter & curWriter, Canevas &canvas, size_t etat);
	void afficherObstacle(ConsoleWriter & curWriter, Canevas &canvas, bool & affObs);
	
private:
	Canevas mCanvas;
	GAEngine mEngine;

	void changeCrossover(GAParameters & GAEparam, size_t pressed);
	void changeMutator(GAParameters & GAEparam, size_t pressed);
	void changeSelector(GAParameters & GAEparam, size_t pressed);
};

#endif // SHAPEOPTIMIZER_H