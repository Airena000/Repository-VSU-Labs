#include <iostream>
#include <iomanip>
#include "book.h"
#include "file_reader.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<BOOK> records = BOOK("library.txt");

    std::cout << "========================================" << std::endl;
    std::cout << "Библиотечный абонемент" << std::endl;
    std::cout << "========================================" << std::endl;

    for (const auto& rec : records) {
        std::cout << rec.familiya << " " << rec.name
            << " - \"" << rec.book_name << "\"" << std::endl;
    }

    return 0;
}