#include <bitset>
#include <fstream>
#include <iostream>
#include "parser.h"

enum class State{
  waiting, reading
};

int readOneByte(std::ifstream* filePtr, char* bitPtr, char* finalCharPtr) {
  std::string binStr;
  for (int i=0; i<8; i++) {
    if (!(*bitPtr=='0' || *bitPtr=='1')) {filePtr->close(); return 5;}
    binStr+=*bitPtr;
    if (!filePtr->get(*bitPtr)) {filePtr->close(); return 4;}
  }
  std::bitset<8> bits(binStr);
  unsigned char byte = bits.to_ulong();
  *finalCharPtr = static_cast<char>(byte);
  std::cout << *finalCharPtr;
  if (*bitPtr!='0') {filePtr->close(); return 6;}
  return 0;
}

int fsm(std::string path) {
  //initialize the reader
  std::ifstream file(path);
  if (!file) {return 3;}
  State state = State::waiting;
  char bit;
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
        int error = readOneByte(&file, &bit, &finalChar);
        if (error) {return error;}
        state = State::waiting;
        break;
    }
  }
    file.close();
    return 0;
}