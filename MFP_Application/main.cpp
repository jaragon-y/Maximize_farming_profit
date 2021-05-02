/* 
 * File:   main.cpp
 * Author: Joaquín Arturo Aragon Yauris
 * Created on 28 de abril de 2021, 05:32 PM
 */

#include <iostream>
#include <iomanip>
#include "functions.h"
#include "mfp_algorithms.h"
using namespace std;

int main(int argc, char** argv) {
    double *loss,*profit,capital;
    int n,level,*results,n_results;
    //read_Data
    n = read_data(loss,profit,level,capital,"Data.txt");
    //sort_Data
    mergeSort(profit,loss,0,n-1);
    //get_Results
    results = get_results(profit,loss,level,capital,n,n_results);
    //print_Results
    print_results(results,profit,loss,n_results);
    return 0;
}

