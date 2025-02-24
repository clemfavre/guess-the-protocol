#include <iostream>
#include "parser.h"
//#include "parser.cpp"
using namespace std;



int main() {
    cout << "program started" << endl;
    int error = fsm();
    cout << "" << endl;
    if (error) {cout << "an error occured : ";
      cout << error;
    }
    return error;
}