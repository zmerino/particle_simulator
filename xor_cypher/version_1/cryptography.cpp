#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

void encode_cypher(string read_filename, std::string key){

    // string line;
    char line[1000];
    // current line length
    int line_len;
    // load file to encrypt
    ifstream data(read_filename);
    // convert to string
    string read_filename_str = string(read_filename);
    // find index where '.' is located
    size_t lastindex = read_filename_str.find_last_of("."); 
    string read_file_substr = read_filename_str.substr(0, lastindex); 
    string write_filename = read_file_substr.append("_encrypted.txt");

    // file to write encrpyted message
    ofstream encoded_msg(write_filename);

    // data will return value > 0 if file not found
    if (!data){
        cout << "file " << read_filename << " not found." << endl;
    }
    else{

        cout << "\t Encrypting data from file: " << read_filename << endl;

        while(!data.eof()){

            data.getline(line,1100);
            string str = string(line); 
            int key_len = key.size();

            line_len = str.size();
            string encrypted_line = line;
            
            // encrypt each line of text file character by character
            for (int i=0; i<line_len; i++){

                // // apply multiple encryption keys per character
                // for (int j=0; j<key_len; j++){
                //     line[i] = line[i] ^ key[j]; 
                // }

                // apply multiple encryption keys to different characters
                int idx = i % key_len;
                line[i] = line[i] ^ key[idx];

                encrypted_line[i] = line[i];
            }

            cout << encrypted_line << endl;

            // save line by line to file
            encoded_msg << encrypted_line << "\n";
        }

        cout << "\t Writting Encrypting data to file: " << write_filename << endl;
        // close data stream(s)
        data.close();
        encoded_msg.close();
    }
}