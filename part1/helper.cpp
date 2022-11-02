#include"helper.h"

bool checkStringToPhoneNumber(std::string s) {
	if (s.size() != 11)
		return false;
	for (char ch : s)
		if (!isdigit(ch))
			return false;
	return true;
}

std::string inputPhoneNumber() {
	std::cout << "������� ����� ��������(11 ����): ";
	std::string phone;
	while (true) {
		std::cin >> phone;
		if (!checkStringToPhoneNumber(phone))
			std::cout << "�������� ����.\n��������� �����: " << std::endl;
		else
			return phone;
	}
}
