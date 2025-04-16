#include <iostream>
#include <sstream>
#include <string>
#include <vector>



using namespace std;
void checkFlags(int argc, char* argv[]){
    int FLAG_ARRAY_SIZE = 8;
    string flags[FLAG_ARRAY_SIZE] = {"-e", "-i", "-k", "-o", "-E", "-I", "-K", "-O"};
    for (size_t i = 0; i < FLAG_ARRAY_SIZE; i++){
        for (size_t j = 1; j < argc; j++){
            if (argv[j] == flags[i]){
                cout << "Flag: " << argv[j] << endl;
                if (argv[j] == "-e" || argv[j] == "-E"){

                }
            }
        }
    }
}

int main(int argc, char* argv[]){
    checkFlags(argc, argv);
    return 0;
}