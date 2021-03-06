#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
#include "SavingsClass.h"

//Savings with a for-loop
float SavingsClass::save1(float pv,float intr,int n){
    for(int year=1;year<=n;year++){
        pv*=(1+intr);
    }
    return pv;
}

//Savings with a power function
float SavingsClass::save2(float pv,float intr,int n){
    return pv*pow((1+intr),n);
}

//Savings with the exponential-log
float SavingsClass::save3(float pv,float intr,int n){
    return pv*exp(n*log(1+intr));
}

//Savings with recursion
float SavingsClass::save4(float pv,float intr,int n){
    if(n<=0)return pv;
    return save4(pv,intr,n-1)*(1+intr);
}

//Savings with a defaulted parameter
float SavingsClass::save5(float pv,float intr,int n=12){
    for(int year=1;year<=n;year++){
        pv*=(1+intr);
    }
    return pv;
}

//Savings with a reference object
void SavingsClass::save6(float pv,float intr,int n,float &fv){
    fv=pv*exp(n*log(1+intr));
}

//Savings with an array
float *SavingsClass::save7(float pv,float intr,int n){
    //Declare an array
    float *fv=new float[n];
    //Calculate all the values in the array
    fv[0]=pv;
    for(int year=1;year<=n;year++){
        fv[year]=fv[year-1]*(1+intr);
    }
    return fv;
}

//Display the savings array
void SavingsClass::display(float *fv,int n){
    //Output the heading for our table
    cout<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Years   Savings"<<endl;
    for(int year=0;year<n;year++){
        cout<<setw(5)<<year;
        cout<<setw(10)<<fv[year]<<endl;
    }
    cout<<endl;
}