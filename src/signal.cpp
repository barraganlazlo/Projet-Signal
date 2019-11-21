#include <string>
#include <iostream>
#include "Wave.hpp"

#define LA 440.00

#define NB_NOTES 7

using namespace std;
void DFT(double *signal, double *partie_reelle, double *partie_imaginaire, int N);
void IDFT(double *signal, double *partie_reelle, double *partie_imaginaire, int N);
int main(){
    double sample_time = 2; // en secondes
	string filename = "./sounds/la.wav";
    int sampling_freq = 44100;
	int nb_channels = 1;
    unsigned char* data8 =NULL;
    int size=44100*sample_time;
    Wave wave(data8, size, nb_channels, sampling_freq);
    wave.getData8(&data8,&size);
    cout<<"data8 : "<<data8<<endl;
    for(int i=0;i<sampling_freq*sample_time;i++){
        data8[i]=127.5f*;
    }
}

void DFT(double *signal, double *partie_reelle, double *partie_imaginaire, int N){
    partie_reelle = new double[N];
    partie_imaginaire = new double[N];
    for(int i=0;i<N;i++){
        double d=signal[i];
    
    }
}