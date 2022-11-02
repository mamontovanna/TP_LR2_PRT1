#include"Note.h"
#include<fstream>
#include<Windows.h>

using namespace std;

void printMenu();
void addObject(Marray<Note>& notes);
void changeObject(Marray<Note>& notes);
void deleteObject(Marray<Note>& notes);
void deleteAll(Marray<Note>& notes);
void print(Marray<Note>& notes);
void printLast(Marray<Note>& notes);
void searchObjects(Marray<Note>& notes);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Marray<Note> notes;

	bool isExit = false;
	while (!isExit) {
		printMenu();
		int method = safeInput(0, 5);
		switch (method)
		{
		case 1:
			addObject(notes);
			break;
		case 2:
			changeObject(notes);
			break;
		case 3:
			deleteObject(notes);
			break;
		case 4:
			deleteAll(notes);
			break;
		case 5:
			print(notes);
			break;
		case 6:
			searchObjects(notes);
			break;
		case 7:
			printLast(notes);
			break;
		case 0:

			isExit = true;
			break;

		}
	}

}

void printMenu() {
	cout << "1. Добавить объект" << endl;
	cout << "2. Изменить объект" << endl;
	cout << "3. Удалить объект" << endl;
	cout << "4. Удалить все записи" << endl;
	cout << "5. Вывести данные" << endl;
	cout << "6. Вывести запись по номеру телефона" << endl;
	cout << "7. Вывести данные последнего добавленного элемента" << endl;
	cout << "0. Выход" << endl;
	cout << "Выберете пункт меню: ";

}

void addObject(Marray<Note>& notes) {
	Note student;
	student.inputFromConsole();
	notes += student;
	notes.sort();
}

void changeObject(Marray<Note>& notes) {
	if (notes.getSize() > 0) {
		print(notes);
		cout << "Введите номер записи для изменения: ";
		notes[safeInput(1, notes.getSize()) - 1].change();
	}
	else
		cout << "Список записей пуст. Нечего изменять\n";
	notes.sort();
}

void deleteObject(Marray<Note>& notes) {
	if (notes.getSize() > 0) {
		print(notes);
		cout << "Введите номер записи для удаления: ";
		notes -= safeInput(1, notes.getSize()) - 1;
	}
	else
		cout << "Список записей пуст. Нечего удалять\n";
	notes.sort();
}
void deleteAll(Marray<Note>& notes) {
	if (notes.getSize() > 0)
		notes.clear();
	else
		std::cout << "Список записей пуст. Нечего удалять\n";
	notes.sort();
}

void print(Marray<Note>& notes) {
	if (notes.getSize() == 0)
		cout << "Список записей пуст.\n";
	else {
		cout << "Список записей\n";
		for (int i = 0; i < notes.getSize(); i++) {
			cout << i + 1 << ". Запись\n";
			notes[i].printToConsole();
		}
	}
}
void printLast(Marray<Note>& notes) {
	if (notes.getSize() == 0)
		cout << "Список записей пуст.\n";
	else {
		cout << "Последний добавленный элемент:\n";
		int i = notes.getSize() - 1;
		notes[i].printToConsole();
	}
}

void searchObjects(Marray<Note>& notes) {
	if (notes.getSize() == 0)
		cout << "Список записей пуст\n";
	else {
		bool isPrint = false;
		string phone = inputPhoneNumber();
		for (int i = 0; i < notes.getSize(); i++)
			if (notes[i].getPhoneNumber() == phone) {
				isPrint = true;
				notes[i].printToConsole();
			}

		if (!isPrint)
			cout << "Людей, с таким номером телефона нет.\n";
	}
}
