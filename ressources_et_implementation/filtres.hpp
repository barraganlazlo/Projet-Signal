#ifndef FILTRES_HPP_INCLUDED
#define FILTRES_HPP_INCLUDED

#include <string>
#include <vector>

void passe_haut(double fech, double fcoupure, int nbChannels, std::vector<double> signal, std::string output); // Laisse passer les basses freq

void passe_bas(double fech, double fcoupure, int nbChannels, std::vector<double> signal, std::string output);

void passe_bande(double fech, double fcoupureB, double fcoupureH, int nbChannels, std::vector<double> signal, std::string output);

#endif //FILTRES_HPP_INCLUDED
