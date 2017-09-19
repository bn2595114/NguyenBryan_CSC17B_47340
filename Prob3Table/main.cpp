/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bryan
 *
 * Created on September 18, 2017, 3:26 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

#include "Specifications.h"

int main(int argc, char** argv) {
cout<<"Entering problem number 3"<<endl;
	int rows=5;
	int cols=6;
	Prob3TableInherited tab("Problem3.txt",rows,cols);
	const int *naugT=tab.getTable();
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cout<<naugT[i*cols+j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	const int *augT=tab.getAugTable();
	for(int i=0;i<=rows;i++)
	{
		for(int j=0;j<=cols;j++)
		{
			cout<<augT[i*(cols+1)+j]<<" ";
		}
		cout<<endl;
	}
    return 0;
}

