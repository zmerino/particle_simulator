#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

void encode_cypher(char *filename, char *key){

    // string line;
    char line[1000];
    // current line length
    int line_len;

    ifstream data(filename);

    // data will return value > 0 if file not found
    if (!data){
        cout << "file " << filename << " not found." << endl;
    }
    else{

        cout << "Encrypting data from file: " << filename << endl;

        while(!data.eof()){

            data.getline(line,1100);
            string str = string(line); 

            line_len = str.size();
            string encrypted_line = line;
            
            // encrypt each line of text file character by character
            for (int i=0; i<line_len; i++){

                int key_len = std::strlen(key);
                char new_char;

                // apply multiple encryption keys per character
                for (int j=0; j<key_len; j++){
                    line[i] = line[i] ^ key[j]; 
                }

                encrypted_line[i] = line[i];
            }

            cout << encrypted_line << endl;
        }
        // close data stream
        data.close();
    }

}