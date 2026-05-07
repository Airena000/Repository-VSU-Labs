#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	ifstream file("library.txt");
	if (!file.is_open()) {
		cout << "Ошибка открытия файла!" << endl;
		return 1;
	}
	string familiya, name, otchestvo, start_date, end_date, author_fam, author_name, author_otch, book_name;
	cout << "Абонементы с книгами Пушкина: " << endl;
	while (file >> familiya >> name >> otchestvo >> start_date >> end_date >> author_fam >> author_name >> author_otch>>book_name) {
		if (author_fam == "Пушкин" && author_name == "Александр" && author_otch == "Сергеевич") {
			cout << familiya << " ," << name << " ," << otchestvo << " ," << start_date << " ," << end_date << " ," <<
				author_fam << " ," << author_name << " ," << author_otch << " ," << book_name << endl;
		}
	}
	file.close();

	return 0;
}