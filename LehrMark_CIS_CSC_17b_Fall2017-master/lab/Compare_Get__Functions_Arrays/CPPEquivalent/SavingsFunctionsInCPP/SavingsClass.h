/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 13, 2017, 11:43 AM
 * Purpose:  Used as C++ functions for testing
 *           the GET/POST of PHP/Java-script
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


#endif /* SAVINGSFUNCTIONS_H */

