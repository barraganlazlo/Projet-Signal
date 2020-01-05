#include "filtres.hpp"
#include "fourier.hpp"
#include "io.hpp"
#include <iostream>

using namespace std;

void passe_haut(double freqEch, double fcoupure, int nbChannels, vector<double> signal, string output){
  long long N = signal.size();
	int FFT_m = next_pow2(N); // exposant de la prochaine puissance de 2
	long long FFT_Size = FFT_size(FFT_m); // taille du futur tableau du signal transformé = M

  vector<double> reelsFourier = vector<double>(FFT_Size, 0.0);
  vector<double> imaginairesFourier = vector<double>(FFT_Size, 0.0);

  for(long long i=0 ; i<N ; i++){
    reelsFourier[i] = signal[i];
  }

  FFT(1, FFT_m, reelsFourier, imaginairesFourier); // Transformée Fourier

  size_t k1 = FFT_Size*(fcoupure/freqEch);//index à modifier pour atteindre la fréquence voulue
  size_t k2 = FFT_Size - k1;

  while(k1 >= 0){
    reelsFourier[k1] = 0;
    reelsFourier[k2] = 0;
    imaginairesFourier[k1] = 0;
    imaginairesFourier[k2] = 0;
    k1--;
    k2++;
  }

  FFT(-1, FFT_m, reelsFourier, imaginairesFourier); // Transformée Fourier

  vector<double>::const_iterator first = reelsFourier.begin(); // Copie des N premiers éléments
  vector<double>::const_iterator last = reelsFourier.begin() + N;

  signal = vector<double>(first, last);

  write_signal(output, signal, nbChannels, freqEch); // sortie dans un fichier
}







void passe_bas(double freqEch, double fcoupure, int nbChannels, vector<double> signal, string output){
  long long N = signal.size();
	int FFT_m = next_pow2(N); // exposant de la prochaine puissance de 2
	long long FFT_Size = FFT_size(FFT_m); // taille du futur tableau du signal transformé = M

  vector<double> reelsFourier = vector<double>(FFT_Size, 0.0);
  vector<double> imaginairesFourier = vector<double>(FFT_Size, 0.0);

  for(long long i=0 ; i<N ; i++){
    reelsFourier[i] = signal[i];
  }

  FFT(1, FFT_m, reelsFourier, imaginairesFourier); // Transformée Fourier

  size_t k1 = FFT_Size*(fcoupure/freqEch);//index à modifier pour atteindre la fréquence voulue
  size_t k2 = FFT_Size - k1;

  while(k1 <= k2){
    reelsFourier[k1] = 0;
    reelsFourier[k2] = 0;
    imaginairesFourier[k1] = 0;
    imaginairesFourier[k2] = 0;
    k1++;
    k2--;
  }

  FFT(-1, FFT_m, reelsFourier, imaginairesFourier); // Transformée Fourier

  vector<double>::const_iterator first = reelsFourier.begin(); // Copie des N premiers éléments
  vector<double>::const_iterator last = reelsFourier.begin() + N;

  signal = vector<double>(first, last);
  write_signal(output, signal, nbChannels, freqEch); // sortie dans un fichier
}







void passe_bande(double freqEch, double fcoupureB, double fcoupureH, int nbChannels, vector<double> signal, string output){

}
