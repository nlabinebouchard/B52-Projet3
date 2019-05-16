#ifndef CHROMOSOME_H
#define CHROMOSOME_H
#include <vector>

class Chromosome
{
private :
	std::vector <bool> mData;
	static std::vector <size_t> mGene;

public :

	Chromosome(std::vector <bool> const & vect, std::vector <size_t> vectBit);

	size_t size() const;
	size_t sizeGene() const;
	void resize(size_t grandeur);
	size_t read(size_t indDebut, size_t indFin) const;
	bool read(size_t ind) const;
	std::vector <bool> read() const;
	size_t readGene(size_t ind) const;
	void write(size_t indDebut, size_t indFin, size_t valeur);
	void write(size_t ind, size_t valeur);
	void flip(size_t indice);
};

#endif // CHROMOSOME_H


