#if 0
#include <iostream>
#include <cstring>
using std::cout;
using std::cin; 
int main(int argc, char *argv[]){
    if (argc != 2)
    {
        std::cerr <<"Invalid number of arguments"; 
        return -1;
    }
    char *hexnum = argv[1]; // a pointer of string pointed to argv[1]

    // valid format : 0x00 - 0xFF(x could be X or x)

    if (strncmp(hexnum, "0x", 2) != 0 && strncmp(hexnum, "0X", 2) != 0 )
    {
        cout <<"Invalid format of hexa number";
        return -2;
    }
    else{// check hexa number
        for (int i = 2; i < strlen(hexnum); i++)
        {
            if (isxdigit(hexnum[i]))
            {
                continue; // valid hexa number
            }
            else
            {
                cout<<"Invalid format of hexa number \n";
                return -3;
            }
            
        }
        cout <<"Got the hexanumber: " << hexnum;
    }
    return 0;
}
#endif
#if 1
#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Invalid number";
        return -1;
    }
    char *str;
    strcpy(str, argv[1]);                 // copy string from argv[1] to str
    if (*str != '0' && *(str + 1) != 'x') // check the prefix '0x'
    {
        std::cerr << "Invalid value";
        return -2;
    }
    for (int i = 2; i < strlen(str); i++)
    {
        if (isxdigit(str[i])) // check the hexa elements
        {
            continue;
        }
        else
        {
            std::cerr << "Invalid value";
            return -3;
        }

        cout << "Got the hexa number:" << str;
        return 0;
    }
}
#endif