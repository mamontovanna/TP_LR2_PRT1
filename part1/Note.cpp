#include"Note.h"
using namespace std;
Note::Note() : secondName("Не задано"), firstName("Не задано"), phoneNumber("Не задано")
{
	birthDate[0] = 0;
	birthDate[1] = 0;
	birthDate[2] = 0;
	cout << "Вызван конструктор без параметров Note" << endl;
}

Note::Note(string secondName, string firstName, int birthDate[3], string phoneNumber) :
	secondName(secondName), firstName(firstName), phoneNumber(phoneNumber)
{
	setBirthDate(birthDate);
	cout << "Вызван конструктор с параметрами Note" << endl;
}

Note::Note(const Note& note) : secondName(note.secondName), firstName(note.firstName), phoneNumber(note.phoneNumber)
{
	setBirthDate(note.birthDate);
	cout << "Вызван конструктор копирования Note" << endl;
}

Note::~Note()
{
	cout << "Вызван деструктор Note" << endl;
}

void Note::inputFromConsole()
{
	cout << "Введите фамилию: ";
	getline(cin, secondName);
	cout << "Введит еимя: ";
	getline(cin, firstName);
	try
	{
		cout << "Введите день рождения: ";
		int d;
		cin >> d;
		if (d <= 0 || d > 31) {
			throw "Некорректный день рождения!";
		}
		else {
			birthDate[0] = d;
		}
	}
	catch (const char* er)
	{
		cout << er << endl;
		cout << "Исключение обработано!" << endl;
	}
	
	
	cout << "Введите месяц рождения: ";
	birthDate[1] = safeInput(1, 12);
	cout << "Введите год рождения: ";
	birthDate[2] = safeInput(1, INT32_MAX);
	phoneNumber = inputPhoneNumber();
}

void Note::printToConsole()
{
	cout << "Фамилия: " << secondName << endl;
	cout << "Имя: " << firstName << endl;
	cout << "Дата рождения: " << birthDate[0] << "." << birthDate[1] << "." << birthDate[2] << endl;
	cout << "Номер телефона: " << phoneNumber << endl;
}

void Note::change()
{
	cout << "Введите новую фамилию: ";
	getline(cin, secondName);
	cout << "Введите новое имя: ";
	getline(cin, firstName);
	cout << "Введите новый день рождения: ";
	birthDate[0] = safeInput(1, 31);
	cout << "Введите месяц рождения: ";
	birthDate[1] = safeInput(1, 12);
	cout << "Введите новый год рождения:\n";
	birthDate[2] = safeInput(1, INT32_MAX);
	phoneNumber = inputPhoneNumber();
}

Note& Note::operator=(const Note& note) {
	if (this == &note)
		return *this;
	secondName = note.secondName;
	firstName = note.firstName;
	phoneNumber = note.phoneNumber;
	setBirthDate(note.birthDate);
	return *this;
}

bool Note::operator>(Note& note) {
	return (birthDate[2] > note.birthDate[2]) ||
		(birthDate[2] == note.birthDate[2] && birthDate[1] > note.birthDate[1]) ||
		(birthDate[2] == note.birthDate[2] && birthDate[1] == note.birthDate[1] && birthDate[0] > note.birthDate[0]);
}
