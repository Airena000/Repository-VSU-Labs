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