#pragma once


// Прототипы функций:
int closeConsole(bool Close); // Не закрывать консоль без нажатия ENTER. после завершения программы

int input(std::string numberValue); // Получает в себя введённое пользователем целочисленное значение

char input(); // Получается в себя введённый пользователем символ

int mathematick(int firstValue, char argument, int secondValue); // Делает математический расчёт на основе двух целочисленных и символа

// Функции:
int closeConsole(bool Close)
{
	if (!Close)
	{
		std::cout << std::endl << "\n" << "Нажмите ENTER для закрытия приложения: " << std::endl;
		std::cin.ignore();
		std::cin.get();
	}

	return 0;
}

int input(std::string numberValue)
{
	std::cout << "Введите " << numberValue << " число: "; // просим пользователя ввести число
	int inputValue = 0;
	std::cin >> inputValue; // получаем пользовательское число и сохраняем его в переменную

	return inputValue;
}

char input()
{
	std::cout << "Введите действие: "; // просим пользователя ввести действие
	char inputChar = '0';
	std::cin >> inputChar; // получаем действие и сохраняем его в переменную b

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
			std::cout << "Делитель не может равняться нулю!\n";
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
		std::cout << "Ошибка расчёта!\n";
		break;
	}
	return 0;
}