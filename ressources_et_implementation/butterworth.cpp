#include "butterworth.hpp"
#include "io.hpp"
#include <cmath>
#include <iostream>

using namespace std;

double process_alpha(double freqCoupure, double freqEch){
  return M_PI * (freqCoupure / freqEch);
}

double A(double alpha){
  return 1.0 + (2.0 * alpha) + (2.0 * pow(alpha, 2.0)) + pow(alpha, 3.0);
}

double B(double alpha){
  return -3.0 - (2.0 * alpha) + (2.0 * pow(alpha, 2.0)) + (3.0 * pow(alpha, 3.0));
}

double C(double alpha){
  return 3.0 - (2.0 * alpha) - (2.0 * pow(alpha, 2.0)) + (3.0 * pow(alpha, 3.0));
}

double D(double alpha){
  return -1.0 + (2.0 * alpha) - (2.0 * pow(alpha, 2.0)) + pow(alpha, 3.0);
}

double get(vector<double>& signal, long int index){
  if(index < 0){
    return 0.0;
  }
  else{
    return signal[index];
  }
}

double process_a(double alpha){
  return (pow(alpha, 3.0) / A(alpha));
}

double process_b(double alpha){
  return ((3.0 * pow(alpha, 3.0)) / A(alpha));
}

double process_c(double alpha){
  return ((3.0 * pow(alpha, 3.0)) / A(alpha));
}

double process_d(double alpha){
  return (pow(alpha, 3.0) / A(alpha));
}

double process_e(double alpha){
  return (-1.0 * B(alpha) / A(alpha));
}

double process_f(double alpha){
  return (-1.0 * C(alpha) / A(alpha));
}

double process_g(double alpha){
  return (-1.0 * D(alpha) / A(alpha));
}

// e = le sinal d'entrée
// fc = frequence de frequence de coupure
// fe = frequence d'echantillonage
void butterworth(int fc, int fe, vector<double>& e, string outputName){
  double alpha = process_alpha(fc, fe);
  vector<double> s(e.size(), 0.0); // signal traite
  double coeff_a = process_a(alpha);
  double coeff_b = process_b(alpha);
  double coeff_c = process_c(alpha);
  double coeff_d = process_d(alpha);
  double coeff_e = process_e(alpha);
  double coeff_f = process_f(alpha);
  double coeff_g = process_g(alpha);

  for(long int k = 0 ; k < (long int)e.size() ; k++){
    s[k] = (coeff_a * get(e, k-3)) + (coeff_b * get(e, k-2)) + (coeff_c * get(e, k-1)) + (coeff_d * get(e, k)) + (coeff_e * get(s, k-1)) + (coeff_f * get(s, k-2)) + (coeff_g * get(s, k-3));
  }

  write_signal(outputName, s, 1, fe);

}
