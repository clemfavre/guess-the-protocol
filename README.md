# guess-the-protocol
The function fsm(path) in code/parser.cpp decodes a message encoded in a .txt file with the following rules :  
    1: ascii characters are encoded in binary, each one preceded and followed by a 0. That makes blocks of 10 bits  
    2: there is as many 1's between each block of 10 bits  

# How can I run the available tests ?
Once the repo has been cloned on linux, enter the following commands :  
    mkdir build  
    cd build  
    cmake ..  
    make  
    ./my_tests  

# How can I use it to decode my own message ?
Once the repo has been cloned, add your own .txt file containing the message and hardcode the path to it in code/main.cpp, remove commented #include at line 3, compile and run main.cpp  
