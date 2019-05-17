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

	size_t size() const;								//size de mData
	size_t sizeGene() const;							//size de mGene
	void resize(size_t grandeur);						//resize mData
	size_t read(size_t indDebut, size_t indFin) const;	//read mData
	bool read(size_t ind) const;						//read mData
	std::vector <bool> read() const;					//get mData
	size_t readGene(size_t ind) const;					//read mGene
	void write(size_t indDebut, size_t indFin, size_t valeur);	//write mData
	void write(size_t ind, size_t valeur);				//write mData
	void flip(size_t indice);							//flip mData

};

#endif // CHROMOSOME_H


