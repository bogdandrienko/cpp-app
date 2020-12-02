#pragma once


// ��������� �������:
int closeConsole(bool Close); // �� ��������� ������� ��� ������� ENTER. ����� ���������� ���������

int input(std::string numberValue); // �������� � ���� �������� ������������� ������������� ��������

char input(); // ���������� � ���� �������� ������������� ������

int mathematick(int firstValue, char argument, int secondValue); // ������ �������������� ������ �� ������ ���� ������������� � �������

// �������:
int closeConsole(bool Close)
{
	if (!Close)
	{
		std::cout << std::endl << "\n" << "������� ENTER ��� �������� ����������: " << std::endl;
		std::cin.ignore();
		std::cin.get();
	}

	return 0;
}

int input(std::string numberValue)
{
	std::cout << "������� " << numberValue << " �����: "; // ������ ������������ ������ �����
	int inputValue = 0;
	std::cin >> inputValue; // �������� ���������������� ����� � ��������� ��� � ����������

	return inputValue;
}

char input()
{
	std::cout << "������� ��������: "; // ������ ������������ ������ ��������
	char inputChar = '0';
	std::cin >> inputChar; // �������� �������� � ��������� ��� � ���������� b

	return inputChar;
}

int mathematick(int secondValue, char argument, int firstValue)
{
	switch (argument)
	{
	case '*':
		return firstValue * secondValue;
		break;
	case '/':
		try {
			if (secondValue != 0) {
				return firstValue / secondValue;
			}
			else {
				throw (secondValue);
			}
		}
		catch (int number) {
			std::cout << "�������� �� ����� ��������� ����!\n";
			return 0;
		}
	case '+':
		return firstValue + secondValue;
		break;
	case '-':
		return firstValue - secondValue;
		break;
	case '%':
		return firstValue % secondValue;
		break;
	default:
		std::cout << "������ �������!\n";
		break;
	}
	return 0;
}