#include <string>
#include <iostream>
#include <cmath>
#include "Wave.hpp"

#define LA 440.00

#define NB_NOTES 7

using namespace std;
void DFT(double *signal, double *partie_reelle, double *partie_imaginaire, int N);
void IDFT(double *signal, double *partie_reelle, double *partie_imaginaire, int N);
int main(){
    double sample_time = 6; // en secondes
	string filename = "./sounds/la.wav";
    int sampling_freq = 44100;
	int nb_channels = 1;
    unsigned char* data8 =NULL;
    int size=0;
    Wave wave(data8, size, nb_channels, sampling_freq);
    wave.getData8(&data8,&size);
    //cout<<"data8 : "<<data8<<endl;
}

void DFT(double *signal, double *partie_reelle, double *partie_imaginaire, int N){
    partie_reelle = new double[N];
    partie_imaginaire = new double[N];
    for(int k=0;k<N;k++){
        partie_reelle[k]=0;
        for (int n=0 ; n<N ; ++n){
            partie_reelle[k] += signal[n] * cos(n * k * M_PI_2 / N);
        } 
        partie_imaginaire[k]=0;
        for (int n=0 ; n<N ; ++n){
            partie_imaginaire[k] -= signal[n] * cos(n * k * M_PI_2 / N);
        } 
    }
}