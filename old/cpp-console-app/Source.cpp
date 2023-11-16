#include <iostream>

using namespace std;

int main()
{
    int a;
    a = 3;
    if ((a > 2) && true) {
        cout << "оператор 1";
        return 0;
    }
    else {
        cout << "оператор 2 и оператор 3";
        return 0;
    }
}