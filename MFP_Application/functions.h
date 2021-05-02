/* 
 * File:   functions.h
 * Author: Joaquín Arturo Aragon Yauris
 * Created on 28 de abril de 2021, 09:47 PM
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fstream>
#include <iostream>

int read_data(double *&loss,double *&profit,int &lev,double &cap,const char *);
void mergeSort(double *profit,double *loss,int l,int r);
void merge(double arr[],double arr2[],int l, int m, int r);
void print_results(int *results,double *profit,double *loss,int n_results);

#endif /* FUNCTIONS_H */

