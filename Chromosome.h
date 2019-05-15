#ifndef CHROMOSOME_H
#define CHROMOSOME_H
#include <vector>

class Chromosome
{
private :
	std::vector <bool> vectChromosome;

public :

	Chromosome(std::vector <bool> const & vect);

	void resize(size_t grandeur);
	size_t read(size_t indDebut, size_t indFin) const;
	std::vector <bool> read() const;
	void write(size_t indDebut, size_t indFin, size_t valeur);
	void flip(size_t indice);
};

#endif // CHROMOSOME_H


