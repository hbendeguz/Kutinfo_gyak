#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <functional>
using namespace std;

double nf = 500; // number of foxes
double nr= 500; //number of rabbits

double r = 1; //logistic rate 
double a = 0.4; //rate of ...
double b = 0.004; // rate of ...
double c = 0.004;//rate of ...
double d = 0.9; // rate of ...
double K = 800; // capacity 
double s = 2500;


double* LotkaVolterra(double nr, double nf){
    double np[2];
    np[0] = a*nr-b*nr*nf;
    np[1] = c*nr*nf-d*nf;
    return np;
}

double* competitive(double x, double y){
    double np[2];
    np[0] = r1*x*(1-(x+alpha*y)/k1);
    np[1] = r2*y*(1-(y+beta*x)/k2);
    return np;
}

double* CapacityLV(double nr, double nf){
    double np[2];
    np[0] = a*(1-nr/K)*nr-b*nr*nf;
    np[1] = c*nr*nf-d*nf;
    return np;
}


double* eulerStep(double x, double tau, double y, function<double* (double,double)> f1){
    x = x+tau*f1(x, y)[0];
    y = y+tau*f1(x, y)[1];
    double ret[2];
    ret[0] = x, ret[1] = y;
    return ret;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout << "Let the simulation begin!\n";

    return 0;
}
