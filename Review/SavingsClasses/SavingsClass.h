/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SavingsClass.h
 * Author: Bryan
 *
 * Created on September 19, 2017, 5:06 PM
 */

#ifndef SAVINGSCLASS_H
#define SAVINGSCLASS_H

class SavingsClass{
    private:
        float pv;
        float intr;
        int nYears;
    public:
        float save1(float, float, int);
        float save2(float, float, int);
        float save3(float, float, int);
        float save4(float, float, int);
        float save5(float, float, int);
        void save6(float, float, int, float&);
        float *save7(float, float, int);
        void display(float*, int);
};


#endif /* SAVINGSCLASS_H */

