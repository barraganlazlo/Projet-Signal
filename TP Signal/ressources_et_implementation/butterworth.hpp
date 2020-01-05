#include <string>
#include <vector>

double process_alpha(double freqCoupure, double freqEch);

double A(double alpha);

double B(double alpha);

double C(double alpha);

double D(double alpha);

double get(std::vector<double>& signal, long int index);

double process_a(double alpha);

double process_b(double alpha);

double process_c(double alpha);

double process_d(double alpha);

double process_e(double alpha);

double process_f(double alpha);

double process_g(double alpha);

void butterworth(int fc, int fe, std::vector<double>& signal, std::string outputName);
