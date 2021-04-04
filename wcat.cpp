// Matthew Rutigliano
// CPSC 3500
// 7 January 2021

// wcat: Prints file contents

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void wcat(const char*);

int main(int argc, char *argv[]) {
    
    int status = 0;
    
    if (argc > 1){
        for (int i=1; i<argc; i++)
            wcat(argv[i]);
    }
    
    // No filenames
    else {
        cout << "wcat: file [file ...]\n";
        status = 1;
    }
    
    return status;
}

void wcat(const char* fname){
    ifstream infile;
    infile.open(fname);
    string line;
    
    if (infile){
        while (!infile.eof()) {
           getline(infile, line);
           cout << line << endl;;
         }
         infile.close();
    }
    
    // File can't be opened
    else {
        cout << "wcat: cannot open file\n";
        exit(1);
    }
}