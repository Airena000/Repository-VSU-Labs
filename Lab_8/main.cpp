#include <iostream>
#include "book.h"
#include "file_reader.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    vector<BOOK> records = readFile("library.txt");

    cout << "========================================" << endl;
    cout << "Библиотечный абонемент" << endl;
    cout << "Студент: Хотейкина Е.Н." << endl;
    cout << "Группа: 25ИСИТ1д" << endl;
    cout << "========================================" << endl;
    cout << "Загружено записей: " << records.size() << endl;

    int choice;
    cout << "Выберите фильтр:" << endl;
    cout << "1. Книги Пушкина А.С." << endl;
    cout << "2. Записи за март 2015 года" << endl;
    cout << "Ваш выбор: ";
    cin >> choice;

    // Параметры для фильтрации
    string pushkinSurname = "Пушкин";
    string pushkinName = "Александр";
    string pushkinPatronymic = "Сергеевич";
    int march = 3;
    int year2015 = 15;

    filter(records, choice, pushkinSurname, pushkinName, pushkinPatronymic, march, year2015);

    return 0;
}