#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// A program to read particle.dat and parse the data

void read_file(char *);

int main(int argc , char *argv[]){


cout << "Check executable input" << endl;

for (int i=0; i<argc; i++){
    cout << "\t Input number " << i << ": " << argv[i] << endl;
}

cout << "Now read the file named " << argv[1] << endl;

read_file(argv[1]);

cout << "Done reading file." << endl;

return 0;

}

void read_file(char *filename){

    // string line;
    char line[1000];

    ifstream data(filename);

    // data will return value > 0 if file not found
    if (!data){
        cout << "file " << filename << " not found." << endl;
    }
    else{

        cout << "Loading data from file: " << filename << endl;

        while(!data.eof()){

            data.getline(line,1100);

            if (line[0] != '#'){

                cout << "\t" << line << endl;
            }
        }

        // close data stream
        data.close();
    }

}