#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <string.h>

using namespace std;

int main(int argc, char* argv[]){
    bool isEncryptOrDecrypt, isKey, isOutput, isInput = false; 
    for (size_t i = 1; i < argc; i++)
    {
        cout << argv[i] << endl;
        if (argv[i] == "-e" || argv[i] == "-E"){
            isEncryptOrDecrypt = true;
        }
        if (argv[i] == "-d" || argv[i] == "-D"){
            isEncryptOrDecrypt = true;
        }
        if (argv[i] == "-k" || argv[i] == "-K"){
            isKey = true;
            if (atoi(argv[i+1]) != 0){
                int key = atoi(argv[i + 1]);
            }else{ cout << "Non integer value detected for key parameter. Enter in a integer value for key. Key can also not be zero" << endl;}
        }
        if (argv[i] == "-o" || argv[i] == "-O"){
            isOutput = true;
            if (strstr(argv[i+1], ".txt")){
                ofstream output;
            }else{ cout << "Output file not detected. Make sure to add .txt.";}
        }
        if (argv[i] == "-i" || argv[i] == "-I"){
            isInput = true;
            string filename = argv[i+1];
            ifstream file(filename);
            if(file){
                string currText;
                while (getline(file, currText)){
                    cout << currText;
                }
            }
            else{cout << "Input file not detected. Make sure to add .txt." << endl;}
        }
            
        }
        
    cout << (isEncryptOrDecrypt ? "" : "-e or -d flag not used") << endl << (isKey ? "" : "-k flag not used") << endl << (isInput ? "" : "-i flag not used") << endl;
    
    return 0;
}