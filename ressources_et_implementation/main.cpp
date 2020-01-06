#include <iostream>
#include <math.h>
#include <string>
#include <assert.h>
#include "io.hpp"
#include "genereGamme.hpp"
#include "filtres.hpp"
#include "butterworth.hpp"

using namespace std;


// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
// #   QUESTION 1 : AJOUT D'UN SIGNAL SINUSOÏDAL EN FONCTION D'UNE FRÉQUENCE, EN FIN DE SIGNAL                   #
// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

void add_note(vector<double>& signal, double freq_note, double duration, double freq_ech, double amplitude=1){

	long long nb_ech = (long long)(duration * freq_ech);

	for (long long i = 0; i < nb_ech; ++i)
		signal.push_back(amplitude * sin(2 * M_PI * freq_note * (i / freq_ech)));
}


int main(int argc, char* argv[], char* env[]){

	// QUESTION 1:
	
	string output = "la_question_1.wav";
	vector<double> signal;// = read_signal("sounds/GammePiano.wav", 1, 44100);
	add_note(signal, 440, 6, 44100);
	write_signal(output, signal, 1, 44100);
	


	//QUESTION 2: gamme
	
	vector<double> notes2;
	notes2.push_back(DO3);
	notes2.push_back(RE3);
	notes2.push_back(MI3);
	notes2.push_back(FA3);
	notes2.push_back(SOL3);
	notes2.push_back(LA3);
	notes2.push_back(SI3);

	genereGamme(5, 44100, 1, notes2, "gammeQ2.wav");
	


	//QUESTION 2: accord
	
	vector<double> notes1;
	notes1.push_back(LA3);
	notes1.push_back(DO3);
	notes1.push_back(MI3);

	genereAccord(15, 44100, 1, notes1, "accordQ2.wav");
	

	//QUESTION 4: Filtres
	
	string file = "sounds/Whistle.wav";
	int freqEch = 8000;
	vector<double> signal = read_signal(file, 1);

	passe_bas(freqEch, 950.0, 1, signal, "filtre_passe_bas.wav");
	

	//QUESTION 5: Butterworth
	
	string file2 = "gammeQ2.wav";
	int freqEch2 = 44100;
	vector<double> signal2 = read_signal(file2, 1);
	butterworth(150, freqEch2, signal2, "butterworth.wav");
	
	return 0;
}
