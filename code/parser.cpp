#include <bitset>
#include <fstream>
#include <iostream>
#include "parser.h"

enum class State{
  waiting, reading
};

int fsm(std::string path) {
    //initialize the reader
    std::ifstream file(path);
    if (!file) {return 3;}

    State state = State::waiting;
    char bit;
    std::string binStr;
    char finalChar;
    while (file.get(bit)) {
      switch(state) {
        case State::waiting:

          if (!(bit=='0' || bit=='1' || bit=='\n')) {
            file.close(); return 1;
          }
          if (bit == '0') {
              state = State::reading;
            } else {
              state = State::waiting;
            }
          break;
        case State::reading:
          binStr.clear();
          for (int i=0; i<8; i++) {
            if (!(bit=='0' || bit=='1')) {file.close(); return 5;}
            binStr+=bit;
            if (!file.get(bit)) {file.close(); return 4;}
          }
          std::bitset<8> bits(binStr);
          unsigned char byte = bits.to_ulong();
          finalChar = static_cast<char>(byte);
          std::cout << finalChar;
          if (bit!='0') {file.close(); return 6;}
          state = State::waiting;
          break;
      }
    }
      file.close();
      return 0;
}