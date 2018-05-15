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
double alpha = 2.3;

double beta =0.02;

double r1 = 0.5;
double r2 = 0.5;
double k1 = 20;
double k2 = 20;
// defining the functions:

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

double* SaturationLV(double nr, double nf){
    double np[2];
    np[0] = a*nr-b*nr*nf/(1+nr/s);
    np[1] = c*nr*nf/(1+nr/s)-d*nf;
    return np;
}

double* RealisticLV(double nr, double nf){
    double np[2];
    np[0] = a*nr*(1-nr/K)-b*nr*nf/(1+nr/s);
    np[1] = c*nr*nf/(1+nr/s)-d*nf;
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
    for(int i = 0; i<100000; i++){
        double x = nr;
        //  nr =eulerStep(nr, 0.00001, nf, Logistic)[0];
        //  nf =eulerStep(x, 0.00001, nf, Logistic)[1];
        
        nr =RK4Step(nr, 0.00001, nf, Logistic)[0];
        nf =RK4Step(x, 0.00001, nf, Logistic)[1];
        file << x/K <<'\t'<<nf << '\n';
    }
    file.close();
    cout << "Finished"<< endl;

    return 0;
}
