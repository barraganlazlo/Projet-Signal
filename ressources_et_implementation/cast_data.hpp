#ifndef CAST_DATA_HPP_INCLUDED
#define CAST_DATA_HPP_INCLUDED
#include <vector>


double range(double value, double leftMin, double leftMax, double rightMin = -1.0, double rightMax = 1.0);
void minEtMax(const std::vector<double>& signal, double& minFinal, double& maxFinal);
void normaliser(std::vector<double>& signal);
unsigned char cast_char(double signal_ech);
std::vector<unsigned char> to_data_octet(std::vector<double>& signal); // a utiliser (autres = intermédiaires)


double cast_double(unsigned char a);
std::vector<double> to_data_double(std::vector<unsigned char> signal) ;// a utiliser (autres = intermédiaires)
std::vector<double> to_data_double(unsigned char* signal, long int taille) ;// a utiliser (autres = intermédiaires)

#endif //CAST_DATA_HPP_INCLUDED
