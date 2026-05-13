#ifndef FILE_READER_H
#define FILE_READER_H
#include <vector>
#include <string>
#include <iostream>
#include "conference.h"
using namespace std;

vector<CONFERENCE> readFile(const string& filename);
void filter(const vector<CONFERENCE>& reports, int choice);
#endif