#include "cast_data.hpp"

#include <cmath>
#include <string>
#include <assert.h>
#include <iostream>

using namespace std;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
// #   CONVERTISSEUR [-1;1] -> [0;255]                                                                           #
// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// Transpose une valeur d'entrée dans la range demandée
double range(double value, double leftMin, double leftMax, double rightMin, double rightMax){
	double leftSpan = leftMax - leftMin;
	double rightSpan = rightMax - rightMin;
	double valueScaled = ((double)(value - leftMin))/((double)(leftSpan));
	double valeurFinale = (valueScaled * (rightSpan)) + rightMin;
	assert((valeurFinale >= rightMin) && (valeurFinale <= rightMax));
	return valeurFinale;
}

// Isole le minimum et le maximum d'un vector de double
void minEtMax(const vector<double>& signal, double& minFinal, double& maxFinal){
	minFinal = signal[0];
	maxFinal = signal[0];

	for(size_t i=0 ; i<signal.size() ; i++){
		if(signal[i] < minFinal){
			minFinal = signal[i];
		}
		if(signal[i] > maxFinal){
			maxFinal = signal[i];
		}
	}

}

// Normalisation du signal: modification des amplitudes:
void normaliser(vector<double>& signal){
	double minTab = 0.0;
	double maxTab = 0.0;
	minEtMax(signal, minTab, maxTab);

	for(size_t i=0 ; i<signal.size() ; i++){
		signal[i] = range(signal[i], minTab, maxTab);
	}

}

// Le signal est comprimé entre 0 et 255.
unsigned char cast_char(double signal_ech){
	return floor((signal_ech + 1.0) * 127.5);
}

// Répète la normalisation + compression pour tout le signal
vector<unsigned char> to_data_octet(vector<double>& signal) {  // cast du tableau de double en tableau de char

	vector<unsigned char> data8(signal.size(), 0);
	normaliser(signal);
	for (size_t i = 0; i < signal.size(); i++){
		data8[i] = cast_char(signal[i]);
	}

	return data8;
	//return move(data8);
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
// #   CONVERTISSEUR [0;255] -> [-1;1]                                                                           #
// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

double cast_double(unsigned char a){
	double b = (double)a;
	//cout << "cast double " << b << endl;
	return range(b, 0, 255, -1.0, 1.0);
}


vector<double> to_data_double(unsigned char* signal, long int taille){
	vector<double> data_double(taille, 0.0);

	for (long int i = 0 ; i < taille ; i++){
		data_double[i] = cast_double(signal[i]);
	}

	return data_double;

}
