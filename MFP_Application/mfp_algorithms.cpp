/* 
 * File:   mfp_algorithms.cpp
 * Author: Joaquín Arturo Aragon Yauris
 * Codigo: 20181252
 * Created on 2 de mayo de 2021, 10:16 AM
 */

#include "mfp_algorithms.h"
using namespace std;
int *get_results(double *profit,double *loss,int level,double capital,int n,int &n_results){
    int *res = new int[(n*2)+1], i=0;
    n_results = 0;
    int last = n-1, best_index,best_level;
    while(1){
        if(level == 0)break;
        if(capital < loss[last])break;
        last = get_best(profit,loss,level,capital,last,best_index,best_level);
        if(last == -1)break;
        res[i] = best_index;
        res[i+1] = best_level;
        n_results += 2;
        i += 2;
    }
    return res;
}

int get_best(double *profit,double *loss,int &level,double &capital,int last,int &best_index,int &best_level){
    
    for(int i = last;i>=0;i--){
        int res = binarySearchModify(loss[i],1,level,capital);
        if (res != -1){
            best_level = res;
            best_index = i;
            capital -= (best_level*loss[best_index]);
            level -= best_level;
            return i-1;
        }
    }
}
int binarySearchModify(double loss,int min,int max,double capital){
    if (max >= min) {
        int mid = min + (max - min) / 2;
        if((mid* loss)==capital )return mid;
        if(mid == max && ((mid* loss) > capital))return -1;
        if(mid == max && ((mid* loss) <= capital))return mid;
        if ((mid* loss)<capital && ((mid+1)*loss)>capital)
            return mid;
        if ((mid* loss) < capital)
            return binarySearchModify(loss, mid + min, max, capital);
        return binarySearchModify(loss, min, mid - min, capital);
    }
    return -1; 
}