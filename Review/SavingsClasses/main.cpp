/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 13, 2017, 11:43 AM
 * Purpose:  Used as C++ functions for testing
 *           the GET/POST of PHP/Javascript
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//User Libraries
#include "SavingsClass.h"

//Universal Global Constants here

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    float pv=100;   //Present Value $'s
    float intr=6/100.0f;   //Interest Rate %
    int nYears=12;  //Number of compounding periods years

    //Perform Calculation / Call the function
    float p1, p2, p3, p4, p5, *p7;
    SavingsClass fv1;
    p1 = fv1.save1(pv,intr,nYears);
    SavingsClass fv2;
    p2 = fv2.save2(pv,intr,nYears);
    SavingsClass fv3;
    p3 = fv3.save3(pv,intr,nYears);
    SavingsClass fv4;
    p4 = fv4.save4(pv,intr,nYears);
    SavingsClass fv5;
    p5 = fv5.save5(pv,intr, nYears);
    SavingsClass fv6;
    float p6;
    fv6.save6(pv,intr,nYears,p6);
    SavingsClass *fv7;
    p7 = new float[nYears+1];
    p7 = fv7->save7(pv, intr, nYears);
    //Display the results
    cout<<"Present Value   = $"<<pv<<endl;
    cout<<"Interest Rate   =    "<<intr*100<<"%"<<endl;
    cout<<"Number of Years =   "<<nYears<<endl;
    cout<<"Future Value    = $"<<p1<<endl;
    cout<<"Future Value    = $"<<p2<<endl;
    cout<<"Future Value    = $"<<p3<<endl;
    cout<<"Future Value    = $"<<p4<<endl;
    cout<<"Future Value    = $"<<p5<<endl;
    cout<<"Future Value    = $"<<p6<<endl;
    cout<<endl;
    cout<<fixed<<setprecision(2)<<showpoint; // Can't figure this out.
    cout<<"Years   Savings"<<endl;
    for(int year=0;year<nYears+1;year++){
        cout<<setw(5)<<year;
        cout<<setw(10)<<p7[year]<<endl;
    }
    cout<<endl;
    
    //Deallocate memory
    delete []fv7;
    delete []p7;
    //Exit stage right
    return 0;
}
