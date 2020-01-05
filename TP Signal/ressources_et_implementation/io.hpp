#ifndef IO_HPP_INCLUDED
#define IO_HPP_INCLUDED

#include <vector>
#include <string>
#include "cast_data.hpp"

void write_signal(std::string& filename, std::vector<double>& signal, int nb_channels, int sampling_freq);

std::vector<double> read_signal(std::string filepath, int nb_channels);

#endif //IO_HPP_INCLUDED
