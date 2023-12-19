#include <iostream>
using std::cin;
using std::cout;
#if 0
int main()
{
    int a, b;
        try
        {
            cout << "Enter your number a: ";
            cin >> a;
            cout << "Enter ur number b: ";
            cin >> b;
            if (b == 0)
            {
                throw 101;
            }
            
        }
        catch (int errorCode)
        {
            std::cerr << "Invalid number\n";
            do{
                cout<<"Please enter again the value b: ";
                cin>>b;
            }while(b==0);
        }
        cout << "The result is: " <<(float) a / b;
    


    

    return 0;
}
#endif

int main(){
        int count = 0;
    std::cout << "\n\nRequest memory allocation ....\n";

    while (1) {
        //request memory allocation (1MB = 1024KB = 1024*1024 bytes)
        try {
            char *ip = new char[1024*1024]; //1MB
            count++;

            //print out address of allocated memory locations
            //std::cout   << "Block " << count << ", address = " << (void *) ip << "\n";
        } catch (std::bad_alloc errorcode) { //Handles std::bad_alloc exception
            std::cerr << "\nbad_alloc exception caught !\n";
            std::cerr << "Total memory allocated: " << count << " MB\n";
            break; //break the while loop
        }

    }   

    std::cout << "\nEnd of program !";
}