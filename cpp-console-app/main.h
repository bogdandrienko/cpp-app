#pragma once


// ��������� �������:
int closeConsole(bool Close); // �� ��������� ������� ��� ������� ENTER. ����� ���������� ���������

int inputValue(std::string numberValue); // �������� � ���� �������� ������������� ������������� ��������

char inputChar(); // ���������� � ���� �������� ������������� ������

int mathematick(); // ������ �������������� ������ �� ������ ���� ������������� � �������

// �������:
int closeConsole(bool Close)
{
	if (!Close)
	{
		std::cout << std::endl << "\n" << "������� ENTER ��� �������� ����������: " << std::endl;
		//std::cin.ignore();
		std::cin.get();
	}

	return 0;
}

int inputValue(std::string numberValue)
{
	std::cout << "������� " << numberValue << " �����: "; // ������ ������������ ������ �����
	int inputValue = 0;
	std::cin >> inputValue; // �������� ���������������� ����� � ��������� ��� � ����������

	return inputValue;
}

char inputChar()
{
	std::cout << "������� ��������: "; // ������ ������������ ������ ��������
	char inputChar = '0';
	std::cin >> inputChar; // �������� �������� � ��������� ��� � ���������� b

	return inputChar;
}

int mathematick()
{
	int firstValue = inputValue("������");
	char argument = inputChar();
	int secondValue = inputValue("������");

	switch (argument)
	{
	case '*':
		return firstValue * secondValue;
	case '/':
		return firstValue / secondValue;
	case '+':
		return firstValue + secondValue;
	case '-':
		return firstValue - secondValue;
	case '%':
		return firstValue % secondValue;
	default:
		std::cout << "������ �������!\n";
	}
	return 0;
}