#include "file_reader.h"
#include <fstream>
#include <sstream>
using namespace std;

vector<BOOK> readFile(const string& filename) {
    vector<BOOK> records;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        BOOK rec;
        stringstream ss(line);

        ss >> rec.familiya >> rec.name >> rec.otchestvo
            >> rec.start_date >> rec.end_date >> rec.author_fam
            >> rec.author_name >> rec.author_otch;

        getline(ss, rec.book_name);
        if (!rec.book_name.empty() && rec.book_name[0] == ' ') {
            rec.book_name = rec.book_name.substr(1);
        }

        records.push_back(rec);
    }
    return records;
}