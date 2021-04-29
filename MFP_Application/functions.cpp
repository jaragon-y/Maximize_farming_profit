/* 
 * File:   functions.cpp
 * Author: Joaquín Arturo Aragon Yauris
 * Codigo: 20181252
 * Created on 28 de abril de 2021, 09:47 PM
 */
#include "functions.h"
using namespace std;

int read_data(double *&loss,double *&profit,double &cap){
    ifstream Arch("Data.txt",ios::in);if(!Arch){cout<<"Data is not found"<<endl;exit(1);}
    double performance,sale_price;
    double crop,seed;
    double land_treaty,time_treaty,workforce_price,capital;
    double buffer1[100],buffer2[100];
    int n;
    Arch>>n>>capital;
    loss = new double [n+1];
    profit = new double [n+1];
    for(int i=0;i<n;i++){
            Arch>>performance>>sale_price>>crop>>seed>>land_treaty>>time_treaty>>workforce_price;
            loss[i]=(crop*seed)+(land_treaty*time_treaty*workforce_price);
            profit[i]=(performance*sale_price*1000)-loss[i];
    }
    cap = capital;
    return n;
}
void mergeSort(double *profit,double *loss,int l,int r){
    if(l>=r) return;
    int m =l+ (r-l)/2;
    mergeSort(profit,loss,l,m);
    mergeSort(profit,loss,m+1,r);
    merge(profit,loss,l,m,r);
}
void merge(double arr[],double arr2[],int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    double L[n1], R[n2],L2[n1], R2[n2];
    for (int i = 0; i < n1; i++){
        L[i] = arr[l + i];
        L2[i] = arr2[l + i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
        R2[j] = arr2[m + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            arr2[k] = L2[i];
            i++;
        }
        else {
            arr[k] = R[j];
            arr2[k] = R2[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        arr2[k] = L2[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        arr2[k] = R2[j];
        j++;
        k++;
    }
}