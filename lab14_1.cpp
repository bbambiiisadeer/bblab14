#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double sum = 0;
    for(int i = 0; i < N; i++) sum += A[i];
        B[0] = sum/N;
        
    double x = 0;
    for(int i = 0; i < N; i++) x += pow(A[i]-B[0],2);
        B[1] = sqrt(x/N);
        
    double y = 1;
    for(int i = 0; i < N; i++) y *= A[i]; 
        B[2] = pow(y,1.0/N);
        
    double z = 0;
    for(int i = 0; i < N; i++) z += 1.0/A[i]; 
        B[3] = N/z;
    
    int i = 0;
    double w = A[0];
        while(i < N){
            if(A[i] > w){
                w = A[i];
            }
        i++;
        }
        B[4] = w;
        
    i = 0;  
    double v = A[0];
        while(i < N){
            if(A[i] < v){
                v = A[i];
            }   
        i++;
        }
        B[5] = v;    
}