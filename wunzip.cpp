// Matthew Rutigliano
// CPSC 3500
// 12 January 2021

// wunzip: Decompresses file

#include <iostream>
#include <fstream>

using namespace std;

void wunzip(const char*);

int main(int argc, char *argv[]) {
    
    int status = 0;
    
    if (argc > 1){
        for (int i=1; i<argc; i++)
            wunzip(argv[i]);
    }
    
    // No filenames
    else {
        cout << "wunzip: file1 [file2 ...]\n";
        status = 1;
    }
    
    return status;
}

void wunzip(const char* fname){
    FILE * pFile;
    int count;
    char let;
    
    pFile = fopen (fname, "rb" );
    
    if (pFile){
         while (!feof(pFile)) {
			// Reads integer
            fread((void*)&count, sizeof(int), 1, pFile);
			// Reads character
            fread((void*)&let, sizeof(char), 1, pFile);
			// Checks eof again so indicator is properly set
            if (!feof(pFile)) {
                for(int j=0; j<count; j++){
                    cout << let;
                }
            }
        }
        fclose(pFile);
    }
    
    // File can't be opened
    else {
        cout << "wunzip: cannot open file\n";
        exit(1);
    }
}