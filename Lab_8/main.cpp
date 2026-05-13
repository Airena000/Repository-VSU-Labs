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

    bool stop = true;
    while (stop) {
        int choice;
        cout << endl;
        cout << "Выберите фильтр:" << endl;
        cout << "1 - Доклады Иванова Ивана Ивановича" << endl;
        cout << "2 - Доклады длительностью > 15 минут" << endl;
        cout << "3 - Сортировка докладов" << endl;
        cout << "4 - Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;
        if (choice == 1 || choice == 2) {
            filter(reports, choice);
        }
        else if (choice == 3) {
            CONFERENCE* ptrs[100];
            int n = reports.size();
            for (int i = 0; i < n; i++) ptrs[i] = &reports[i];

            int m, c;
            cout << "Метод (1-Пирамидальная, 2-Слиянием): "; cin >> m;
            cout << "Критерий (1-длительность, 2-фамилия): "; cin >> c;

            CompareFunc f = (c == 1) ? compareByDuration : compareByAuthor;

            if (m == 1) heapSort(ptrs, n, f);
            else mergeSort(ptrs, 0, n - 1, f);

            for (int i = 0; i < n; i++)
                cout << ptrs[i]->start << " " << ptrs[i]->end << " " << ptrs[i]->surname << " \"" << ptrs[i]->topic << "\"\n";
        }
        else if (choice == 4) {
            stop = false;
        }
        else {
            cout << "Неверный выбор!" << endl;
        }
    }
    return 0;
}