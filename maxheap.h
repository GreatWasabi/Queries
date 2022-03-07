//
// Created by devansh tomar on 3/4/22.
//

#ifndef DEFNS_H
#define DEFNS_H
#include "defns.h"
#endif

#include <iostream>
#include <string>
using namespace std;

string Add_Comma(int n);
void maxheapifyTotal(SOC arr[], int n, int i);
void maxheapifyMen(SOC arr[], int n, int i);
void maxheapifyWomen(SOC arr[], int n, int i);
void buildMaxHeap(SOC arr[], int n, string keyword);
void  extractMaxTotal(SOC arr[], int size, int numberOfOccupations);
void  extractMaxMen(SOC arr[], int size, int numberOfOccupations);
void  extractMaxWomen(SOC arr[], int size, int numberOfOccupations);
void readingCSV(string line, SOC &arr);
void initialize(SOC arr[], int size);


