// cpp-console-app.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

// Заголовочные файлы:
#include <iostream>
#include <string>
#include <Windows.h>
#include <cmath>

#include "main.h"

using namespace std;

// Главная функция:
int main()
{	
	setlocale(0, "");
	SetConsoleCP(1251);

	/*
	int VALUE = 5; // инициализация целочисленной переменной, с будущим размером динамического массива.
	int *ptarrVALUE = new int[VALUE]; // Объявление массива и динамическое выделение памяти для массива.
	for (int count = 0; count < 10; count++) {
		ptarrVALUE[count] = count;
		cout << ptarrVALUE[count] << " ";
	}
	delete[] ptarrVALUE; // очистка памяти
	*/

	//Приведение к типу
	/*
		charValue = 'A';
		intValue = 9;
		floatValue = 5.7;

			cout << static_cast<char>(charValue) << endl;
			cout << static_cast<int>(charValue) << endl;
			cout << static_cast<float>(charValue) << endl;

			cout << static_cast<char>(intValue) << endl;
			cout << static_cast<int>(intValue) << endl;
			cout << static_cast<float>(intValue) << endl;
			cout << (float)intValue

			cout << static_cast<char>(floatValue) << endl;
			cout << static_cast<int>(floatValue) << endl;
			cout << static_cast<float>(floatValue) << endl;
			cout << (int)floatValue
	*/

	//Алгебраические операции
	/*
		Value = -1;
		Value = Value + 1;

		Value = 0;
		Value += 1;
		cout << Value << endl;

		Value = 0;
		Value++;
		cout << Value << endl;

		Value = 0;
		Value -= 1;
		cout << Value << endl;

		Value = 0;
		Value--;
		cout << Value << endl;

		Value = 0;
		Value *= 1;
		cout << Value << endl;

		Value = 0;
		Value /= 1;
		cout << Value << endl;

		Value = 0;
		Value %= 1;
		cout << Value << endl;

	*/

	//Уловия
	/*
		int x;
		int y;
			if (x == y)
				std::cout << x << " equals " << y << "\n";
			if (x != y)
				std::cout << x << " does not equal " << y << "\n";
			if (x > y)
				std::cout << x << " is greater than " << y << "\n";
			if (x < y)
				std::cout << x << " is less than " << y << "\n";
			if (x >= y)
				std::cout << x << " is greater than or equal to " << y << "\n";
			if (x <= y)
				std::cout << x << " is less than or equal to " << y << "\n";


		&& - ...
		|| - ...
		? - ...
		: - ...

		bool ifValue = true;
		if (ifValue) {
			cout << "Правда" << endl;
		} 
		else if {
			cout << "Ложь, если " << endl;
		}
		else {
			cout << "Ложь" << endl;
		}


		switch{
			case
		}


		enum{
			
		}
	*/


	
	closeConsole(false);
}