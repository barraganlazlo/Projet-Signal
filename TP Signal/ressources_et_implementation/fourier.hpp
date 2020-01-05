#ifndef FOURIER_HPP_INCLUDED
#define FOURIER_HPP_INCLUDED

#include <vector>

int next_pow2(int n) ;
long long FFT_size(int n);
int FFT(int dir, int m, double *x, double *y) ;
int FFT(int dir, int m, std::vector<double>& x, std::vector<double>& y);

#endif //FOURIER_HPP_INCLUDED
