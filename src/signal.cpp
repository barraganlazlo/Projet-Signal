#include <string>
#include <iostream>
#include <cmath>
#include "Wave.hpp"

#define LA 440.00

#define NB_NOTES 7

using namespace std;
void insert_note(double *data, double t1, double t2, double freq, int sampling_freq, double volume);
int char2real(char *s_char,double *s_real,int N);
int real2char(char *s_char,double *s_real,int N);
void DFT(double *signal, double *partie_reelle, double *partie_imaginaire, int N);
void IDFT(double *signal, double *partie_reelle, double *partie_imaginaire, int N);
int FFT(int dir,int m,double *x,double *y);
int main(){
    double sample_time = 6.0; // en secondes
    int sampling_freq = 44100;
	int nb_channels = 1;
    int size=(int)44100*sample_time;
    unsigned char data8[size];
    double data[size];
    insert_note(data,0.0,6.0,LA,sampling_freq,0.8);
    real2char((char*)data8,data,size);
    Wave wave(data8, size, nb_channels, sampling_freq);
    wave.write("sounds/la.wav");

}
void insert_note(double *data, double t1, double t2, double freq, int sampling_freq,double volume){ //volume entre 0 et 1
    for(int i=(int) t1*sampling_freq;i<t2*sampling_freq; i++){
        data[i] = volume * sin(i * M_PI_2 * freq/sampling_freq);
    }
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
int char2real(char *s_char,double *s_real,int N){
    int i;
    char *ptc;
    double *pt,*fin;
    pt=s_real;
    ptc=s_char;
    fin=pt+N;
    while(pt< fin){
        (*pt++) =((double)(*ptc++)/127.5)-1.0;
    }
    return 1;
}
int real2char(char *s_char,double *s_real,int N){
    int i;
    char *ptc;
    double *pt,*fin, valeur;
    pt=s_real;
    ptc=s_char;
    fin=pt+N;    
    while(pt< fin){
        valeur= (*pt++);
        valeur+=1.0;
        valeur*=127.5;
        valeur = valeur>255.0 ? 255.0 : valeur; 
        valeur = valeur<0.0 ? 0.0 : valeur;
        (*ptc++) =(char) floor(valeur);
    }
    return 1;
}
/*
	This FFT has been proposed by Paul Bourke 
	http://paulbourke.net/miscellaneous/dft/
	This computes an in-place complex-to-complex FFT 
	x and y are the real and imaginary arrays of 2^m points.
	dir =  1 gives forward transform
	dir = -1 gives reverse transform 
	You MUST compute first the value m such that
	2^(m-1) < n (size of your signal) <= 2^m
	allocate a new signal of nm=2^m values
	then fill the n first values of this new signal 
 with your signal and fill the rest with 0
	WARNING : you must pass m, not nm !!!
	*/

// int FFT(int dir,int m,double *x,double *y)
// {
// 	int n,i,i1,j,k,i2,l,l1,l2;
// 	double c1,c2,tx,ty,t1,t2,u1,u2,z;
	
// 	/* Calculate the number of points */
// 	n = 1;
// 	for (i=0;i<m;i++) 
// 		n *= 2;
	
// 	/* Do the bit reversal */
// 	i2 = n >> 1;
// 	j = 0;
// 	for (i=0;i<n-1;i++) {
// 		if (i < j) {
// 			tx = x[i];
// 			ty = y[i];
// 			x[i] = x[j];
// 			y[i] = y[j];
// 			x[j] = tx;
// 			y[j] = ty;
// 		}
// 		k = i2;
// 		while (k <= j) {
// 			j -= k;
// 			k >>= 1;
// 		}
// 		j += k;
// 	}
	
// 	/* Compute the FFT */
// 	c1 = -1.0; 
// 	c2 = 0.0;
// 	l2 = 1;
// 	for (l=0;l<m;l++) {
// 		l1 = l2;
// 		l2 <<= 1;
// 		u1 = 1.0; 
// 		u2 = 0.0;
// 		for (j=0;j<l1;j++) {
// 			for (i=j;i<n;i+=l2) {
// 				i1 = i + l1;
// 				t1 = u1 * x[i1] - u2 * y[i1];
// 				t2 = u1 * y[i1] + u2 * x[i1];
// 				x[i1] = x[i] - t1; 
// 				y[i1] = y[i] - t2;
// 				x[i] += t1;
// 				y[i] += t2;
// 			}
// 			z =  u1 * c1 - u2 * c2;
// 			u2 = u1 * c2 + u2 * c1;
// 			u1 = z;
// 		}
// 		c2 = sqrt((1.0 - c1) / 2.0);
// 		if (dir == 1) 
// 			c2 = 
//     wave.getData8(&data8,&size);
//     //cout<<"data8 : "<<data8<<endl;-c2;
// 		c1 = sqrt((1.0 + c1) / 2.0);
// 	}
	
// 	/* Scaling for forward transform */
// 	if (dir == 1) {
// 		for (i=0;i<n;i++) {
// 			x[i] /= n;
// 			y[i] /= n;
// 		}
// 	}
	
// 	return(1);
// }
