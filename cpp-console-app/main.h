#pragma once


// Прототипы функций:
int closeConsole(bool Close); // Не закрывать консоль без нажатия ENTER. после завершения программы

int inputValue(std::string numberValue); // Получает в себя введённое пользователем целочисленное значение

char inputChar(); // Получается в себя введённый пользователем символ

int mathematick(); // Делает математический расчёт на основе двух целочисленных и символа

// Функции:
int closeConsole(bool Close)
{
	if (!Close)
	{
		std::cout << std::endl << "\n" << "Нажмите ENTER для закрытия приложения: " << std::endl;
		//std::cin.ignore();
		std::cin.get();
	}

	return 0;
}

int inputValue(std::string numberValue)
{
	std::cout << "Введите " << numberValue << " число: "; // просим пользователя ввести число
	int inputValue = 0;
	std::cin >> inputValue; // получаем пользовательское число и сохраняем его в переменную

	return inputValue;
}

char inputChar()
{
	std::cout << "Введите действие: "; // просим пользователя ввести действие
	char inputChar = '0';
	std::cin >> inputChar; // получаем действие и сохраняем его в переменную b

	return inputChar;
}

int mathematick()
{
	int firstValue = inputValue("первое");
	char argument = inputChar();
	int secondValue = inputValue("второе");

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
		std::cout << "Ошибка расчёта!\n";
	}
	return 0;
}