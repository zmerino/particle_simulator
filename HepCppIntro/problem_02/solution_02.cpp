
#include "cryptography.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void format_message(void){
    printf("\t ********************** NOTE ************************ \n");
    printf("\t Encrypt or decrypt message by calling: \n");
    printf("\t\t ./encoder <filename> -e <none> -m <int> -k <string> -s <int> \n");

    printf("\t Where: \n");

    printf("\t\t -e <none>: \n");
    printf("\t\t\t -e for encrypt, -d for decrypt. \n");

    printf("\t\t -m <int>: \n");
    printf("\t\t\t methods include 1, 2, 3, etc. in general, \n\t\t\t larger the integer the more advanced the encryption. \n");
    
    printf("\t\t -k <string>: \n");
    printf("\t\t\t string of one character or more to use for encryption/decryption. \n");

    printf("\t\t -s <int>: \n");
    printf("\t\t\t Steps to use during encryption (if applicable). \n");

    printf("\t ********************** NOTE ************************ \n");
}

void divert_method(string key){
}

int main(int argc, char *argv[]){

    // get flag -m i.e. encryption method
    char method_type = *argv[4];

    string key;

    if (argc < 2 || argc > 5){
        format_message();
    }
    else if (argc > 2 && argc < 4){
        
        // defualt encrption key if no method specified
        key = "K";

        switch (argv[4][0])
        {
        case 'e':{
            string file_str = string(argv[1]);
            encode_cypher(file_str, key);
            break;
        }
        case 'd':{
            string file_str = string(argv[1]);
            // decode_cypher(file_str, key);
            break;
        }
        default:
            format_message();
            break;
        }
    }
    else{

        cout << "\t Using Encryption Method:" << *argv[4] << endl;

        if (*argv[4] == '1'){
            key = "K";
        }
        else if (*argv[4] == '2'){
            key = "ABCSasdaskjflskdLSKDNFLKSJDF";
        }
        else{
            key = "K";
            printf("NOTE: Method %c does not exist, using default method 1 \n", *argv[4]);
        }

        switch (argv[2][1])
        {
            case 'e':{
                string file_str = string(argv[1]);
                encode_cypher(file_str, key);
                break;
            }
            case 'd':{
                string file_str = string(argv[1]);
                // decode_cypher(file_str, key);
                break;
            }
            default:{
                format_message();
                break;
            }
        }
    }

    return 0;
}