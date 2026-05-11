// При выполнении задания своего варианта нужно вписать номер и название варианта, а также свои имя и фамилию

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	ifstream file("library.txt");
	if (!file.is_open()) {
		cout << "Ошибка открытия файла!" << endl;
		return 1;
	}
	string familiya, name, otchestvo, start_date, end_date, author_fam, author_name, author_otch, book_name;
	cout << "Абонементы с книгами Пушкина: " << endl;
	while (file >> familiya >> name >> otchestvo >> start_date >> end_date >> author_fam >> author_name >> author_otch>>book_name) {
		if (author_fam == "Пушкин" && author_name == "Александр" && author_otch == "Сергеевич") {
			cout << familiya << " " << name << " " << otchestvo << ", " << start_date << ", " << end_date << ", " <<
				author_fam << " " << author_name << " " << author_otch << ", " << book_name << endl;
		}
	}
	file.close();
	file.open("library.txt");
	cout << "Абонементы с книгами взятыми в марте 2015:" << endl;
	while (file >> familiya >> name >> otchestvo >> start_date >> end_date >> author_fam >> author_name >> author_otch >> book_name) {
		if (start_date[3] == '0' && start_date[4] == '3' && start_date[6] == '1' && start_date[7] == '5') {
			cout << familiya << " " << name << " " << otchestvo << ", " << start_date << ", " << end_date << ", " <<
				author_fam << " " << author_name << " " << author_otch << ", " << book_name << endl;
		}
	}

	file.close();
	
	return 0;
}
