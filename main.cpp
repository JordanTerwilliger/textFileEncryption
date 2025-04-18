#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;

void encryption(const string& inputFileName, const string& outputFileName, int key){
    if(inputFileName == outputFileName){
        cout << "Input file name cannot be output file name" << endl;
        return;
    }
    cout << "Encrypting" << endl;
    ifstream input(inputFileName);
    ofstream output(outputFileName);

    if (!input.is_open() || !output.is_open()) {
        cout << "Failed to open files in encryption function.\n";
        return;
    }

    string currText; 
    while (getline(input, currText)){
        for(char& letter : currText){ //For Each letter in currText
            if (isalpha(letter)){
                char base = islower(letter) ? 'a' : 'A';
                letter = (letter - base + key) % 26 + base; //Normalize (-base), Shift (+key), Modulo (%26), Shift Back (+base)
            }
        }
        output << currText << endl;
    }
    input.close();
    output.close();
    cout << "File encrypted; Key: " << key << endl;
}

void decryption(const string& inputFileName, const string& outputFileName, int key){
    if(inputFileName == outputFileName){
        cout << "Input file name cannot be output file name" << endl;
        return;
    }
    cout << "Decrypting" << endl;
    ifstream input(inputFileName);
    ofstream output(outputFileName);
    if (!input.is_open() || !output.is_open()) {
        cout << "Failed to open files in decryption function.\n";
        return;
    }

    string currText; 
    while (getline(input, currText)){
        for(char& letter : currText){ //For Each letter in currText
            if (isalpha(letter)){
                char base = islower(letter) ? 'a' : 'A';
                letter = (letter - base - key + 26) % 26 + base; //Normalize (-base), Shift (-key + 26), Modulo (%26), Shift Back (+base)
            }
        }
        output << currText << endl;
    }
    input.close();
    output.close();
    cout << "File Decrypted; Key: " << key << endl;
}

int main(int argc, char* argv[]){
    bool isEncrypt = false, isDecrypt = false, isKey = false, isOutput = false, isInput = false; 
    int key = 0;
    string inputFileName, outputFileName;

    for (size_t i = 0; i < argc; i++)
    {
        string parameter = argv[i];
        if (parameter == "-h" || parameter == "-H"){
            ifstream help("README.txt");
            string currText;
            while(getline(help, currText)){
                cout << currText << endl;
            }
        }
        if (parameter == "-e" || parameter == "-E"){
            isEncrypt = true;
        }
        else if (parameter == "-d" || parameter == "-D"){
            isDecrypt = true;
        }
        else if (parameter == "-k" || parameter == "-K") {
            if (i + 1 < argc) {
                key = atoi(argv[++i]);
                key = abs(key);
                if (key != 0) {
                    isKey = true;
            } else {
                    cout << "Invalid key. Must be a non-zero integer." << endl;
                    return 0;
            }
        }
    }
        else if (parameter == "-o" || parameter == "-O"){
            isOutput = true;
            if(i + 1 < argc){
                outputFileName = argv[++i];
                }
            else{cout << "Output file name must be next argument when using -o flag." << endl;};
        }
        else if (parameter == "-i" || parameter == "-I"){
            isInput = true;
            if(i + 1 < argc){
                inputFileName = argv[++i];
            }
            else{cout << "Input file name must be next argument when using -i flag." << endl;}
        }
            
        }
    if(isEncrypt && isDecrypt) {cout << "-e and -d were flagged. Choose only one. "; return 0;}
    if(!isEncrypt && !isDecrypt) {cout << "-e or -d flag not in use. Please choose to either encrypt or decrypt text file." << endl; return 0;}
    if(!isKey) {cout << "-k flag not in use. Please enter integer value greater than 0." << endl; return 0;}
    if(!isInput) {cout << "-i flag not in use. Please specify input filepath including \".txt\"." << endl; return 0;}
    if(!isOutput){ 
        cout << "No output file designated. Use \"output.txt\"? y or n" << endl;
        char a;
        cin >> a;
        if (a == 'y' || a == 'Y')
            outputFileName = "output.txt";
        else
            return 0;
    }

    if(isEncrypt){
        encryption(inputFileName, outputFileName, key);
    }
    else if(isDecrypt){
        decryption(inputFileName, outputFileName, key);
    }

    return 0;
}