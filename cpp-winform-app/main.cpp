#include "pch.h"
#include <iostream>

#include <cstdlib> // Для работы с функцией system()
#include <windows.h>

#include "main.h"

using namespace System::Windows::Forms;
using namespace System;
using namespace std;

[STAThread]
int main() 
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew mainName::main());
	return 0;
}