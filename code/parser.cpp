#include <bitset>
#include <fstream>
#include <iostream>
using namespace std;

int fsm() {
    //initialize the reader
    ifstream file("../res/bitstream.txt");
    if (!file) {return 3;}

    int state = 0;
    char bit;
    std::string binStr;
    char finalChar;
    while (file.get(bit)) {
        switch(state) {
            case 0://waiting
              if (bit == '0') {
                  state = 1;
                } else if (bit == '1') {
                  state = 0;
                } else {
                  if (bit!='\n') {return 1;}
                }
              break;
            case 1://reading
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
              if (bit!='0') {return 7;}
              state = 0;
              break;
          }
      }
      file.close();
      return 0;
}

int main() {
    cout << "program started" << endl;
    int error = fsm();
    cout << "" << endl;
    if (error) {cout << "an error occured : ";
      cout << error;
    }
    return error;
}