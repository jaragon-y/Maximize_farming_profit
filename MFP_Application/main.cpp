/* 
 * File:   main.cpp
 * Author: Joaquín Arturo Aragon Yauris
 * Created on 28 de abril de 2021, 05:32 PM
 */

#include <iostream>
#include <iomanip>
#include "functions.h"
using namespace std;

int main(int argc, char** argv) {
    double *loss,*profit,capital;
    int n;
    //read_Data
    n = read_data(loss,profit,capital);
    //sort_Data
    mergeSort(profit,loss,0,n-1);
    //for(int i =0;i<n;i++)cout<<"profit = "<<setw(8)<<setprecision(2)<<fixed<<profit[i]<<endl;
    return 0;
}

