#ifndef GENERE_GAMME_HPP_INCLUDED
#define GENERE_GAMME_HPP_INCLUDED

#include <string>
#include <vector>

#define DO3  261.63
#define RE3  293.66
#define MI3  329.63
#define FA3  349.23
#define SOL3 392.00
#define LA3  440.00
#define SI3  493.88

// Ajoute le contenu de 'b' à la fin de 'a'
void appendVector(
	std::vector<double>& a,
	std::vector<double>& b
);

void genereGamme(
	double tempsNote,
	double freqEch,
	int nbChannels,
	std::vector<double> notes,
	std::string nomFichOutput
);

void genereAccord(
	double tempsNote,
	double freqEch,
	int nbChannels,
	std::vector<double> notes,
	std::string nomFichOutput
);

#endif //GENERE_GAMME_HPP_INCLUDED
