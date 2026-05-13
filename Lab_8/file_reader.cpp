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

void filter(const vector<BOOK>& records,
    int choice,
    const string& author_fam,
const string& author_name,
const string& author_otch,
int targetMonth,
int targetYear) {

    switch (choice) {
    case 1: {
        // Фильтрация по автору (Пушкин)
        cout << "=== Книги Пушкина А.С. ===" << endl;
        for (const auto& rec : records) {
            if (rec.author_fam == author_fam&&
                rec.author_name == author_name &&
                rec.author_otch == author_otch) {
                cout << rec.familiya << " " << rec.name << " "
                    << rec.otchestvo << " - " << rec.book_name << endl;
            }
        }
        break;
    }
    case 2: {
        // Фильтрация по дате (март 2015)
        cout << "=== Записи за март 2015 года ===" << endl;
        for (const auto& rec : records) {
            int month = (rec.start_date[3] - '0') * 10 + (rec.start_date[4] - '0');
            int year = (rec.start_date[6] - '0') * 10 + (rec.start_date[7] - '0');
            if (month == targetMonth && year == targetYear) {
                cout << rec.familiya << " " << rec.name << " "
                    << rec.otchestvo << " - "<< rec.book_name  << endl;
            }
        }
        break;
    }
    default:
        cout << "Неверный выбор!" << endl;
        break;
    }
}