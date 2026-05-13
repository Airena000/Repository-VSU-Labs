#include <iostream>
#include "conference.h"
#include "file_reader.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    vector<CONFERENCE> reports = readFile("conference.txt");

    cout << "========================================" << endl;
    cout << "Программа конференции" << endl;
    cout << "========================================" << endl;
    cout << "Загружено докладов: " << reports.size() << endl;

    int choice;
    cout << "Выберите фильтр:" << endl;
    cout << "1 - Доклады Иванова Ивана Ивановича" << endl;
    cout << "2 - Доклады длительностью > 15 минут" << endl;
    cout << "Ваш выбор: ";
    cin >> choice;

    filter(reports, choice);

    return 0;
}