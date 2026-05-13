#ifndef FILE_READER_H
#define FILE_READER_H
#include <vector>
#include <string>
#include <iostream>
#include "book.h"
using namespace std;

vector<BOOK> readFile(const string& filename);
void filter(const vector<BOOK>& records,
    int choice,
    const string& author_fam,
    const string& author_name,
    const string& author_otch,
    int targetMonth,
    int targetYear);
#endif