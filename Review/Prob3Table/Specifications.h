/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Specifications.h
 * Author: Bryan
 *
 * Created on September 18, 2017, 3:27 PM
 */

#ifndef SPECIFICATIONS_H
#define SPECIFICATIONS_H

class Prob3Table
{
	protected:
		int rows;                                 //Number of rows in the table
		int cols;                                 //Number of cols in the table
		int *rowSum;                              //RowSum array
		int *colSum;                              //ColSum array
		int *table;                               //Table array
		int grandTotal;                           //Grand total
		void calcTable(void);                     //Calculate all the sums
	public:
		Prob3Table(char *,int,int);               //Constructor then Destructor
		~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
		const int *getTable(void){return table;};
		const int *getRowSum(void){return rowSum;};
		const int *getColSum(void){return colSum;};
		int getGrandTotal(void){return grandTotal;};
};

class Prob3TableInherited:public Prob3Table
{
	protected:
		int *augTable;                                  //Augmented Table with sums
	public:
		Prob3TableInherited(char *,int,int);          //Constructor
		~Prob3TableInherited(){delete [] augTable;};  //Destructor
		const int *getAugTable(void){return augTable;}; 
};


#endif /* SPECIFICATIONS_H */

