#include <iostream>
#include "book.h"
#include "file_reader.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<BOOK> records = readFile("library.txt");
    std::cout << "Загружено записей: " << records.size() << std::endl;
    return 0;
}