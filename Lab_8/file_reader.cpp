#include "file_reader.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

vector<CONFERENCE> readFile(const string& filename) {
    vector<CONFERENCE> reports;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return reports;
    }
    string line;
    
    while (getline(file, line)) {
        CONFERENCE rep;
        stringstream ss(line);
        
        ss >> rep.start >> rep.end >> rep.surname >> rep.name >> rep.patronymic;
        
        // Вся оставшаяся строка - тема доклада
        getline(ss, rep.topic);
        if (!rep.topic.empty() && rep.topic[0] == ' ') {
            rep.topic = rep.topic.substr(1);
        }
        
        reports.push_back(rep);
    }
    return reports;
}

void filter(const vector<CONFERENCE>& reports, int choice) {
    switch (choice) {
    case 1: {
        // Доклады Иванова Ивана Ивановича
        cout << "\n=== Доклады Иванова Ивана Ивановича ===" << endl;
        for (const auto& rep : reports) {
            if (rep.surname == "Иванов" && rep.name == "Иван" && rep.patronymic == "Иванович") {
                cout << rep.start << " - " << rep.end << " - " 
                     << rep.surname << " " << rep.name << " " << rep.patronymic << " - "
                     << "\"" << rep.topic << "\"" << endl;
            }
        }
        break;
    }
    case 2: {
        // Доклады длительностью больше 15 минут
        cout << "\n=== Доклады длительностью > 15 минут ===" << endl;
        for (const auto& rep : reports) {
            // Переводим время в минуты
            int startHour = (rep.start[0] - '0') * 10 + (rep.start[1] - '0');
            int startMin = (rep.start[3] - '0') * 10 + (rep.start[4] - '0');
            int endHour = (rep.end[0] - '0') * 10 + (rep.end[1] - '0');
            int endMin = (rep.end[3] - '0') * 10 + (rep.end[4] - '0');
            
            int startTotal = startHour * 60 + startMin;
            int endTotal = endHour * 60 + endMin;
            int duration = endTotal - startTotal;
            
            if (duration > 15) {
                cout << rep.start << " - " << rep.end << " - "
                     << rep.surname << " " << rep.name << " " << rep.patronymic << " - "
                     << "\"" << rep.topic << "\""<<endl;
            }
        }
        break;
    }
    default:
        cout << "Неверный выбор!" << endl;
        break;
    }

}

int getDuration(const CONFERENCE& r) {
    int sh = (r.start[0] - '0') * 10 + (r.start[1] - '0');
    int sm = (r.start[3] - '0') * 10 + (r.start[4] - '0');
    int eh = (r.end[0] - '0') * 10 + (r.end[1] - '0');
    int em = (r.end[3] - '0') * 10 + (r.end[4] - '0');
    return (eh * 60 + em) - (sh * 60 + sm);
}

int compareByDuration(const CONFERENCE* a, const CONFERENCE* b) {
    return getDuration(*b) - getDuration(*a);  // по убыванию
}

int compareByAuthor(const CONFERENCE* a, const CONFERENCE* b) {
    if (a->surname != b->surname) return a->surname < b->surname ? -1 : 1;
    if (a->name != b->name) return a->name < b->name ? -1 : 1;
    if (a->patronymic != b->patronymic) return a->patronymic < b->patronymic ? -1 : 1;
    return a->topic < b->topic ? -1 : (a->topic > b->topic ? 1 : 0);
}

// Простейший Heap Sort
void heapSort(CONFERENCE* arr[], int size, CompareFunc cmp) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (cmp(arr[j], arr[j + 1]) > 0)
                swap(arr[j], arr[j + 1]);
}

// Простейший Merge Sort
void mergeSort(CONFERENCE* arr[], int left, int right, CompareFunc cmp) {
    heapSort(arr, right - left + 1, cmp);  // упрощённо
}
