// cpp-console-app.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

// Заголовочные файлы:
#include <iostream>
#include <Windows.h>
#include <string>

#include "main.h"

// Пространства имён
using namespace std;


// Главная функция:
int main()
{	
	setlocale(0, "");
	SetConsoleCP(1251);
	
	cout << mathematick(input("второе"), input(), input("первое")) << endl;

	closeConsole(false);
}