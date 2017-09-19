#include <fstream>
#include <cstdlib>
#include <iostream>
using namespace std;
#include "Specifications.h"

Prob3Table::Prob3Table(char* txt, int row, int col){
    ifstream infile;
    infile.open(txt);
    if(!infile)
        cout << "File does not exist" << endl;
    
    rows = row;
    cols = col;
    table = new int[cols*rows];
    for(int i=0; i<rows*cols; i++)  //MIGHT NOT READ FULL DATA
        infile >> table[i];
    
    for(int pos=0; pos<rows*cols-1; pos++){ //mrkSort
        for(int i=pos+1; i<rows*cols; i++){
            if(table[pos]>table[i]){
                table[pos]=table[pos]^table[i];
                table[i]=table[pos]^table[i];
                table[pos]=table[pos]^table[i];
            }
        }   
    }
    infile.close();
}
void Prob3Table::calcTable(){
    rowSum = new int[rows];
    colSum = new int[cols];
    grandTotal=0;
    for(int i=0; i<rows; i++)
        rowSum[i] = 0;
    for(int i=0; i<cols; i++)
        colSum[i] = 0;
    
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++){
            rowSum[i] += table[i*cols+j];
        }
    for(int i=0; i<cols; i++)
        for(int j=0; j<rows; j++){
            colSum[i] += table[j*cols+i];
        }
    for(int i=0; i<rows; i++){
        grandTotal += rowSum[i];
    }
}

Prob3TableInherited::Prob3TableInherited(char *txt,int r,int c)
:Prob3Table(txt, r, c){
    this->calcTable();
    
    augTable = new int[(r+1)*(c+1)];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
        {
            augTable[i*c+(j+i)] = table[i*c+j]; 
        }
    
    for(int i = 0; i < r; i++)
        augTable[i*c+(c+i)] = rowSum[i];
    
    for(int i = 0; i < c; i++)
        augTable[r*(c+1)+i] = colSum[i];
    
    augTable[r*(c+1)+c] = grandTotal;
}

    