#include <iostream>
#include "parser.h"
//#include "parser.cpp"
using namespace std;



int main() {
    string path = "../res/bitstream.txt";
    cout << "program started" << endl;
    int error = fsm(path);
    cout << "" << endl;
    if (error) {cout << "an error occured : ";
      cout << error;
    }
    return error;
}