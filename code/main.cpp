#include <iostream>
#include "parser.h"
//#include "parser.cpp"
using namespace std;



int main(std::string path) {
    cout << "program started" << endl;
    int error = fsm(path);
    cout << "" << endl;
    if (error) {cout << "an error occured : ";
      cout << error;
    }
    return error;
}