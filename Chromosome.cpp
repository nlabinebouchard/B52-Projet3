# include "Chromosome.h"

Chromosome::Chromosome(std::vector<bool> const & vect)
	:vectChromosome{ vect }
{}

size_t Chromosome::size() { return vectChromosome.size(); }

void Chromosome::resize(size_t grandeur) { vectChromosome.resize(grandeur); }

size_t Chromosome::read(size_t indDebut, size_t indFin) const
{
	size_t valeur{};

	if (indDebut < vectChromosome.size() && indFin < vectChromosome.size()) {
		for (size_t i{ indDebut }; i < indFin; ++i) {
			valeur <<= 1;
			valeur += static_cast<size_t>(vectChromosome[i]);
		}
		return valeur;
	}
	else
		return 0;
}

bool Chromosome::read(size_t ind) const
{
	return vectChromosome[ind];
}

std::vector<bool> Chromosome::read() const
{
	return vectChromosome;
}

void Chromosome::write(size_t indDebut, size_t indFin, size_t valeur)
{
	if (indDebut < vectChromosome.size() && indFin < vectChromosome.size()) {
		while (indDebut <= indFin) {
			vectChromosome[indFin] = valeur & 1;
			valeur >>= 1;
			--indFin;
		}
	}
}

void Chromosome::flip(size_t indice)
{
	if (indice < vectChromosome.size()) {
		vectChromosome[indice] = !vectChromosome[indice];
	}
}
