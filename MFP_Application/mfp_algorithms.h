/* 
 * File:   mfp_algorithms.h
 * Author: Joaquín Arturo Aragon Yauris
 * Codigo: 20181252
 * Created on 2 de mayo de 2021, 10:16 AM
 */

#ifndef MFP_ALGORITHMS_H
#define MFP_ALGORITHMS_H
#include <iostream>
int *get_results(double *profit,double *loss,int level,double capital,int n,int &n_results);
int get_best(double *profit,double *loss,int &level,double &capital,int last,int &best_index,int &best_level);
int binarySearchModify(double loss,int min,int max,double capital);
#endif /* MFP_ALGORITHMS_H */

