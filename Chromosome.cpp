# include "Chromosome.h"

Chromosome::Chromosome(std::vector<bool> const & vect, std::vector<size_t> vectBit)
	: mData{ vect }
{
	mGene = vectBit;
}

size_t Chromosome::size() const 
{ 
	return mData.size(); 
}

size_t Chromosome::sizeGene() const { 
	return mGene.size();
}

void Chromosome::resizeData(size_t gData)
{
	mData.resize(gData);
}

void Chromosome::resizeGene(size_t gGene)
{
	mGene.resize(gGene);
}

size_t Chromosome::read(size_t indDebut, size_t indFin) const
{
	size_t valeur{};

	if (indDebut < mData.size() && indFin < mData.size()) {
		for (size_t i{ indDebut }; i < indFin; ++i) {
			valeur <<= 1;
			valeur += static_cast<size_t>(mData[i]);
		}
		return valeur;
	}
	else
		return 0;
}

bool Chromosome::read(size_t ind) const 
{
	return mData[ind];
}

std::vector<bool> Chromosome::read() const 
{
	return mData; 
}

size_t Chromosome::readGene(size_t ind) const 
{
	return mGene[ind];
}

void Chromosome::write(size_t indDebut, size_t indFin, size_t valeur)
{
	if (indDebut < mData.size() && indFin < mData.size()) {
		while (indDebut <= indFin) {
			mData[indFin] = valeur & 1;
			valeur >>= 1;
			--indFin;
		}
	}
}

void Chromosome::write(size_t ind, size_t valeur)
{
	if (ind >=0 && ind < mData.size()) {
		mData[ind] = valeur;
	}
}

void Chromosome::writeData(std::vector<bool> vectBool)
{
	mData.resize(vectBool.size());
	mData = vectBool;
}

void Chromosome::writeGene(std::vector<size_t> vectSize)
{
	mGene.resize(vectSize.size());
	mGene = vectSize;
}

void Chromosome::flip(size_t indice)
{
	if (indice < mData.size()) {
		mData[indice] = !mData[indice];
	}
}

std::vector<bool> Chromosome::myData()
{
	return mData;
}

std::vector<size_t> Chromosome::myGene()
{
	return mGene;
}
