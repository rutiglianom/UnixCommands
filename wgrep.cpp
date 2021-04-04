// Matthew Rutigliano
// CPSC 3500
// 7 January 2021

// wgrep: Finds term in file

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void wgrep(const char*, const char*);
void stdinGrep(const char*);

int main(int argc, char *argv[]) {
    
    int status = 0;
    
    if (argc > 2){
        for (int i=2; i<argc; i++)
            wgrep(argv[1], argv[i]);
    }
    // No file
    else if (argc == 2) {
        stdinGrep(argv[1]);
    }

    // No arguments
    else {
        cout << "wgrep: searchterm [file ...]\n";
        status = 1;
    }
    
    return status;
}

void wgrep(const char* search, const char* fname) {
    string line;
    ifstream infile;
    infile.open(fname);
    
    if (infile){
        while (!infile.eof()) {
            // Search for term
            getline(infile, line);
            if (line.find(search) != (size_t)-1)
                cout << line << endl;
         }
         infile.close();
    }
    
    // File can't be opened
    else {
        cout << "wgrep: cannot open file\n";
        exit(1);
    }
}

void stdinGrep(const char* search) {
    string line;
    
    // Search for term
    getline(cin, line);
    
    if (line.find(search) != (size_t)-1)
        cout << line << endl;
}