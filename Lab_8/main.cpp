#include <iostream>
#include <iomanip>
#include "book.h"  // или BOOK.h
#include "file_reader.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");

    vector<BOOK> records = readFile("library.txt");

    cout << "========================================" <<  endl;
    cout << "Библиотечный абонемент" << endl;
    cout << "Студент: Ваша Фамилия Имя" <<  endl;  // <- ваше имя
    cout << "Группа: ИСиТ-2-1" << endl;          // <- ваша группа
    cout << "========================================" <<  endl;

    for (const auto& rec : records) {
         cout << rec.readerSurname << " " << rec.readerName
            << " - \"" << rec.bookTitle << "\"" <<  endl;
    }

    return 0;
}