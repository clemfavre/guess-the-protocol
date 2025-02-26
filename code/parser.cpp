#include <bitset>
#include <fstream>
#include <iostream>
#include "parser.h"
using namespace std;

enum State{
  waiting, reading
};

int fsm(std::string path) {
    //initialize the reader
    ifstream file(path);
    if (!file) {return 3;}

    State state = waiting;
    char bit;
    std::string binStr;
    char finalChar;
    while (file.get(bit)) {
      switch(state) {
        case waiting:
          if (bit == '0') {
              state = reading;
            } else if (bit == '1') {
              state = waiting;
            } else {
              if (bit!='\n') {return 1;}
            }
          break;
        case reading:
          binStr.clear();
          for (int i=0; i<8; i++) {
            if (!(bit=='0' || bit=='1')) {return 5;}
            binStr+=bit;
            if (!file.get(bit)) {return 4;}
          }
          std::bitset<8> bits(binStr);
          unsigned char byte = bits.to_ulong();
          finalChar = static_cast<char>(byte);
          cout << finalChar;
          if (bit!='0') {return 6;}
          state = waiting;
          break;
        }
      }
      file.close();
      return 0;
}