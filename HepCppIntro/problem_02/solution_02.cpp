
#include "cryptography.h"

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){

    if (argc < 2 || argc > 3){
        printf("\t ********************** NOTE ************************ \n");
        printf("\t Encrypt or decrypt message by calling: \n\t\t ./encoder <filename> [encrypt/decrypt] \n");
        printf("\t Where [encrypt/decrypt] accepts: \n\t\t -e for encrypt, -d for decrypt \n");
        printf("\t ********************** NOTE ************************ \n");
    }
    else{

        int mask = 0xA3; // a number less that 255
        char key[10] = "a";
        char c,a,b; // character to be read and encrypted

        switch (argv[2][1])
        {
        case 'e':{

            cout << argv[2][1] << endl;

            encode_cypher(argv[1], key);

            break;
        }

        case 'd':{

            /* code */
            break;
        }
        
        default:
            break;
        }
    }
    return 0;
}