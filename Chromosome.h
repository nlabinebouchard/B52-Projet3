#ifndef CHROMOSOME_H
#define CHROMOSOME_H
#include <vector>

class Chromosome
{
private :
	std::vector <bool> vectChromosome;
	static std::vector <size_t> vectLargeurBit;

public :

	Chromosome(std::vector <bool> const & vect, std::vector <size_t> vectBit);

	size_t size();
	void resize(size_t grandeur);
	size_t read(size_t indDebut, size_t indFin) const;
	bool read(size_t ind) const;
	std::vector <bool> read() const;
	void write(size_t indDebut, size_t indFin, size_t valeur);
	void flip(size_t indice);
};

#endif // CHROMOSOME_H


