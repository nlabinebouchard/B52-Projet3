#ifndef CHROMOSOME_H
#define CHROMOSOME_H
#include <vector>

class Chromosome
{
private :
	std::vector <bool> mData;
	std::vector <size_t> mGene;

public :
	Chromosome() = default;
	Chromosome(std::vector <bool> const & vect, std::vector <size_t> vectBit);

	size_t size() const;								//size de mData
	size_t sizeGene() const;							//size de mGene
	void resizeData(size_t gData);			//resize mData
	void resizeGene(size_t gGene);
	size_t read(size_t indDebut, size_t indFin) const;	//read mData
	bool read(size_t ind) const;						//read mData
	std::vector <bool> read() const;					//get mData
	size_t readGene(size_t ind) const;					//read mGene
	void write(size_t indDebut, size_t indFin, size_t valeur);	//write mData
	void write(size_t ind, size_t valeur);				//write mData
	void writeData(std::vector <bool> vectBool);
	void writeGene(std::vector <size_t> vectSize);
	void flip(size_t indice);							//flip mData

	std::vector <bool> myData();
	std::vector <size_t> myGene();
};

#endif // CHROMOSOME_H


