#include <iostream>
#include <string> 
#include <exception>

using namespace std;

enum class yearOfMyBirth { 
	lesszero,
	more,
	less,
	inncorrect
};

class yearException : public exception {

private:
	yearOfMyBirth notice;

public:
	yearException(yearOfMyBirth notice) : notice(notice) {};

	const char* what() const throw() override {
		if (notice == yearOfMyBirth::lesszero) return "Вы ввели отрицательное число.";
		else if (notice == yearOfMyBirth::more) return "Вы ещё не родились.";
		else if (notice == yearOfMyBirth::less) return "Что-то не верится...";
		else if (notice == yearOfMyBirth::inncorrect) return "Некорректное значение";
		else return "Ошибка не опознана.";
	}
};

int main()
{
	setlocale(LC_ALL, "");

	int number = 0;
	string massage;
	try {
		cout << "Введите число 1, 2 или 3 : ";
		if (not (cin >> number)) throw  "Некорректное значение."; 
		switch (number) {
		case 1:
			massage = "Один";
			break;
		case 2:
			massage = "Два";
			break;
		case 3:
			massage = "Три";
			break;
		default:
			throw "Некорректное значение";
		}
		cout << massage;
	}

	catch (const char* mas) {
		cout << mas;
		cin.clear();
		while (cin.get() != '\n');
	}
	cout << endl;

	int yaerOfBirth;
	string lie;
	cout << endl << "Введите год рождения: ";

	try {
		if (not (cin >> yaerOfBirth)) throw "Некорректное значение";
		if (yaerOfBirth < 1850) lie = "Что-то не верится...";

		if (yaerOfBirth > 2022) lie = "Вы ещё не родились.";

		if (yaerOfBirth < 0) lie = "Вы ввели отрицательное число";
		if (not (lie.empty())) throw lie; 
		else cout << "Спасибо!" << endl;
	}

	catch (const char* mas) {
		cout << mas << endl;
		cin.clear();
		while (cin.get() != '\n');
	}
	catch (string msg) {
		cout << msg << endl;
	}

	cout << endl << "Введите год рождения: ";
	try {
		if (not (cin >> yaerOfBirth)) throw yearException(yearOfMyBirth::inncorrect);
		else if (yaerOfBirth < 0) throw yearException(yearOfMyBirth::lesszero);
		else if (yaerOfBirth < 1850) throw yearException(yearOfMyBirth::less);
		else if (yaerOfBirth > 2022) throw yearException(yearOfMyBirth::more);
		cout << "Спасибо!" << endl;
	}
	catch (yearException mas) {
		cout << mas.what() << endl;
	}
}