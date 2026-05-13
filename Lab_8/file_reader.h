#ifndef FILE_READER_H
#define FILE_READER_H
#include <vector>
#include <string>
#include <iostream>
#include "conference.h"
using namespace std;

vector<CONFERENCE> readFile(const string& filename);
void filter(const vector<CONFERENCE>& reports, int choice);
typedef int (*CompareFunc)(const CONFERENCE*, const CONFERENCE*);

void heapSort(CONFERENCE* arr[], int size, CompareFunc cmp);
void mergeSort(CONFERENCE* arr[], int left, int right, CompareFunc cmp);
int compareByDuration(const CONFERENCE* a, const CONFERENCE* b);
int compareByAuthor(const CONFERENCE* a, const CONFERENCE* b);
int getDuration(const CONFERENCE& r);

#endif