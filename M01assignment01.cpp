/* Program name: Binary to decimal convertion
* Author: Carlos Lizarazu 
* Date last updated: 8/23/2024
* Purpose: Take 5 binary numbers and convert them to decimal base
*/

#include <iostream>
using namespace std;

int main() {
  int num1, num2, num3, num4, num5;

  cout << "Enter the 1st binary number: ";
  cin >> num1;
  cout << "Enter the 2nd binary number: ";
  cin >> num2;
  cout << "Enter the 3rd binary number: ";
  cin >> num3;
  cout << "Enter the 4th binary number: ";
  cin >> num4;
  cout << "Enter the 5th binary number: ";
  cin >> num5;

  int convertion = (num5 + num4 * 2) + (num3 * 4) + (num2 * 8) + (num1 * 16);

  cout << "The number is: " << convertion << endl;

  return 0;
}