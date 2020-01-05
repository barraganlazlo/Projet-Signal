#include <vector>
#include <math.h>
#include "genereGamme.hpp"
#include "fourier.hpp"
#include "io.hpp"

using namespace std;

void appendVector(vector<double>& a, vector<double>& b){
	for(size_t i=0 ; i<b.size() ; i++){
		a.push_back(b[i]);
	}
}


void genereGamme(double tempsNote, double freqEch, int nbChannels, vector<double> notes, string nomFichOutput){
	long long N = freqEch * tempsNote; // taille du tableau du signal réel
	int FFT_m = next_pow2(N); // exposant de la prochaine puissance de 2
	long long FFT_Size = FFT_size(FFT_m); // taille du futur tableau du signal transformé
	vector<double> signal = vector<double>(); // futur réceptacle du signal

	for(size_t i = 0; i < notes.size(); i++){
		vector<double> signal_real(FFT_Size, 0.0); // Réceptacle de la partie réelle
		vector<double> signal_imaginary(FFT_Size, 0.0);  // Réceptacle de la partie imaginaire

		size_t k1 = FFT_Size*(notes[i]/freqEch);//index à modifier pour atteindre la fréquence voulue
		size_t k2 = FFT_Size - k1; // symetrie par freq de Shannon
		signal_real[k1] = 10.0; // Peu importe la valeur (tq != 0) va être normalisé
		signal_real[k2] = 10.0;
		signal_imaginary[k1] = 10.0;
		signal_imaginary[k2] = 10.0;

		FFT(-1, FFT_m, signal_real, signal_imaginary); // Transformée inverse

		vector<double>::const_iterator first = signal_real.begin(); // Copie des N premiers éléments
		vector<double>::const_iterator last = signal_real.begin() + N;
		// La partie imaginaire est négligeable, on en tient pas compte

		vector<double> signal_temp = vector<double>(first, last);

		appendVector(signal, signal_temp); // concaténation de la nouvelle note avec le reste

	}

	write_signal(nomFichOutput, signal, nbChannels, freqEch); // sortie dans un fichier

}


void genereAccord(double tempsNote, double freqEch, int nbChannels, vector<double> notes, string nomFichOutput){
	long long N = freqEch * tempsNote; // taille du tableau du signal réel
	int FFT_m = next_pow2(N);
	long long FFT_Size = FFT_size(FFT_m); // taille du futur tableau du signal transformé

	vector<double> signal_real(FFT_Size, 0.0); // Réceptacle de la partie réelle
	vector<double> signal_imaginary(FFT_Size, 0.0);  // Réceptacle de la partie imaginaire

	for (size_t i = 0; i < notes.size(); i++){
		size_t k1 = FFT_Size*(notes[i]/freqEch);
		size_t k2 = FFT_Size - k1; // symetrie

		signal_real[k1] = 10.0;
		signal_real[k2] = 10.0;
		signal_imaginary[k1] = 10.0;
		signal_imaginary[k2] = 10.0;
	}


	FFT(-1, FFT_m, signal_real, signal_imaginary);

	vector<double>::const_iterator first = signal_real.begin();
	vector<double>::const_iterator last = signal_real.begin() + N;
	vector<double> signal = vector<double>(first, last);

	write_signal(nomFichOutput, signal, nbChannels, freqEch);

}
