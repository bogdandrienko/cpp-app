#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void start_Button(string text){
    // print output to user
    std::cout << text;
    ofstream myfile;
    myfile.open ("example.txt");
    myfile << "Writing this to a file.\n";
    myfile.close();
}

#endif // MAIN_H
