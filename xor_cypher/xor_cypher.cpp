
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

int main(int argc, char** argv){

    // assign inputs to string array
    string inputs[argc];    
    for (int i=0; i<argc; i++){
        cout << argv[i] << endl;
        inputs[i] = string(argv[i]);
    }

    // default function parameters
    // string filename = inputs[1], key = "k";
    // char encode = 'e';
    // int method = 1, step = 1;


    struct 
    {
        string filename;
        string key = "k";
        char encode = 'e';
        int method = 1;
        int step = 1;
    } params;

    params.filename = inputs[1];
    

    if (argc == 2){ // if help command invoked

        string flag = string(argv[1]);
        cout << "flag: " << flag << endl; 

        if (flag == "-help" || flag == "--help"){
            format_message();
        }
        else if ((flag == "-defaults" || flag == "--defaults" || flag == "-default" || flag == "--default")){

            printf("Defaults input flags in order: -e -m 1 -k \"k\" -s 1 \n");

            printf("\t Where: \n");

            printf("\t\t -e <none>: \n");
            printf("\t\t\t -e for encrypt, -d for decrypt. \n");

            printf("\t\t -m <int>: \n");
            printf("\t\t\t methods include 1, 2, 3, etc. in general, \n\t\t\t larger the integer the more advanced the encryption. \n");
            
            printf("\t\t -k <string>: \n");
            printf("\t\t\t string of one character or more to use for encryption/decryption. \n");

            printf("\t\t -s <int>: \n");
            printf("\t\t\t Steps to use during encryption (if applicable). \n");
        }
        else{
            cout << "assuming defaults, encypting/decrypting file: " << argv[1] << endl;
            encode_cypher(params.filename, params.key);
        }
    }
    else if (argc < 2 || argc > 9){
        format_message();
    }
    else if (argc > 2 && argc < 10){
        
        // update defaults as needed
        for (int i=0; i<argc; i++){

            // cout << inputs[i] << endl;
            int j = i + 1;

            if (inputs[i][0] == '-'){
                switch (inputs[i][1])
                {
                case 'e':

                    params.encode = inputs[i][1];
                    // cout << "update -e: " << encode << endl;
                    break;
                case 'm':
                    
                    params.method = inputs[j][0] - '0';
                    // cout << "update -m: " << method << endl;
                    break;
                case 'k':

                    params.key = inputs[j];
                    // cout << "update -k: " << key << endl;
                    break;
                case 's':
                    
                    params.step = inputs[j][0] - '0';
                    // cout << "update -s: " << step << endl;
                    break;
                
                default:
                    break;
                }
            }
        }

        switch (params.encode)
        {
        case 'e':{
            encode_cypher(params.filename, params.key);
            break;
        }
        case 'd':{
            // decode_cypher(filename, key);
            break;
        }
        default:
            format_message();
            break;
        }
    }
    else{

        cout << "\t Using Encryption Method:" << params.method << endl;

        if (params.method == '1'){
            params.key = "K";
        }
        else if (params.method == '2'){
            params.key = "ABCSasdaskjflskdLSKDNFLKSJDF";
        }
        else{
            params.key = "K";
            printf("NOTE: Method %c does not exist, using default method 1 \n", params.method);
        }

        switch (params.encode)
        {
            case 'e':{
                encode_cypher(params.filename, params.key);
                break;
            }
            case 'd':{
                // decode_cypher(params.filename, key);
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