/* Program name: Binary to decimal conversion revisited
   Author: Carlos Lizarazu
   Date last updated: 9/11/24
   Purpose: The program will get any amount of numbers (binary 1,0) adn then convert them to decimal numbers.
   the program will also check if numbers is a number and it can only be 1 or 0. 
*/

#include <iostream>
#include <string>

using namespace std;

int main() {

    int number=0, i=1, decimal=0, base=1,temporal;
    string bin,ss;

    cout << "Welcome to the binary number converter 2.0." << endl; 
    cout << "You will enter a binary number 1 digit at a time and the program will convert the number to decimal." << endl;
    
    
    while (number!=-1){
        cout<<"Enter the "<<i<<" digit (Enter -1 to complete the convertion): "; cin>>number;
        if (cin.fail()){
            cout<<"You entered something that is not a number"<<endl;
            break;
        }else{
            if (number>=2){
                cout<<"A binary can only be a 1 or 0"<<endl;
                break;
            }else{
                if (number!=-1){
                    ss = to_string(number);
                    bin+=ss;
                }
            }
            
        }
        i+=1;
    }
    
    
    //convert the string binary number to an integer
    int num_bin = stoi(bin);
    //temporal will be storing our temporal number
    temporal= num_bin;
    while(temporal){
        int mod = temporal%10;
        temporal = temporal / 10;

        decimal += mod * base;

        base = base*2;
    }

    cout<<"Your number in decimal is: "<<decimal<<endl;

  return 0;
}