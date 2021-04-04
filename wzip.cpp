// Matthew Rutigliano
// CPSC 3500
// 10 January 2021

// wzip: Compresses file

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void wzip(const char*);

int main(int argc, char *argv[]) {
    
    int status = 0;
    
    if (argc > 1){
        for (int i=1; i<argc; i++)
            wzip(argv[i]);
    }
    
    // No filenames
    else {
        cout << "wzip: file1 [file2 ...]\n";
        status = 1;
    }
    
    return status;
}

void wzip(const char* fname){
    ifstream infile;
    string line;
    char let;
    int cursor = 1;
    int count = 1;
    int i = 0;
    
    infile.open(fname);
    
    if (infile){
        while (!infile.eof()) {
            
            getline(infile, line);
            
            while ((size_t)i<line.size()){
                let = line[i];
                while(1){
                    if (line[i+cursor] == let){
                        count++;
                        cursor++;
                    }
                    else {
                        fwrite((void*)&count, sizeof(int), 1, stdout);
                        cout << let;
                        i += cursor;
                        break;
                    }
                }
				// Reset cursor and count
				cursor = 1;
				count = 1;
            }
			// Reset i
			i = 0;
			
			// Print line's final term
			fwrite((void*)&count, sizeof(int), 1, stdout);
			cout << "\n";
        }
        infile.close();
    }
    
    // File can't be opened
    else {
        cout << "wzip: cannot open file\n";
        exit(1);
    }
}