# guess-the-protocol

The function fsm(path) in code/parser.cpp decodes a message encoded in a .txt file with the following rules :
    1: ascii characters are encoded in binary, each one preceded and followed by a 0. That makes blocks of 10 bits
    2: there is as many 1's between each block of 10 bits

How to use it ?
    1: to run the available tests, enter the following 3 commands : cd build; make; ./my_tests

    2: OR create your own .txt file and hardcode the path to it in code/main.cpp, remove commented #include at line 3, compile and run main.cpp
