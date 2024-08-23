/* Program name: Dividing winnings
   Author: Carlos Lizarazu 
   Date last updated: 8/23/2024
   Purpose: Take a jackpot amount and a number of winners. 
   Divide de amount between the winners giving the 1st winner 2x what everyine else gets
*/
#include <iostream>
using namespace std;

int main() { 
  int amount, winners;
  cout << "Enter the jackpot amount: "; cin>>amount;
  cout<< "Enter the amount of winners: ";cin>>winners;
  
  int div = amount/(winners+1);
  int winner1 = div*2;
  

  cout<<"The first winner gest: $"<<winner1<<endl;
  cout<<"All the winners get: $"<<div<<endl;
  
  return 0;
}