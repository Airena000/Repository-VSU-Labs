#include <iostream>
#include <iomanip>
#include "book_subscription.h"
#include "file_reader.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<BOOK> records = readFile("library.txt");

    std::cout << "========================================" << std::endl;
    std::cout << "Библиотечный абонемент" << std::endl;
    std::cout << "Группа: ИСиТ-1" << std::endl;   // ← ваш номер группы
    std::cout << "========================================" << std::endl;

    for (const auto& rec : records) {
        std::cout << rec.readerSurname << " " << rec.readerName
            << " - \"" << rec.bookTitle << "\"" << std::endl;
    }

    return 0;
}