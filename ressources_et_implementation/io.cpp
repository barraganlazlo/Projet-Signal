#include "io.hpp"
#include "Wave.hpp"
#include <iostream>

using namespace std;

void write_signal(string& filename, vector<double>& signal, int nb_channels, int sampling_freq) {

	vector<unsigned char> data8 = to_data_octet(signal);

	Wave wave(data8.data(), data8.size(), nb_channels, sampling_freq);

	// convertie en char* car la fonction write de modifie pas la constante de toute façon
	wave.write((char*)filename.c_str());
}

vector<double> read_signal(string filepath, int nb_channels) {

	unsigned char* data8 = NULL;
	long int size = 0;

	Wave wave = Wave();
	wave.read((char*)filepath.c_str());
	wave.getData8(&data8, &size);

	vector<double> signal = to_data_double(data8, size);

	delete[] data8;

	return signal;
}
