/* Program name: Computer Specifications
*  Author: Carlos Lizarazu
*  Date last updated: 9/5/2024
* Purpose: The program will determine if a user has enough RAM to do certain tasks.
*/

#include <iostream>
using namespace std;

int main() {

  int RAM, option;

  cout << "Enter the amount of RAM your computer has in GB: ";
  cin >> RAM;
  if (cin.fail()||RAM<0) {
    cout << "You have entered an invalid value. The program will unable to continue. Exiting.";
  } else {
    cout << "Choose the task you want to do on your computer from the following list: " << endl;
    cout << "1. Android Studio" << endl
         << "2. Visual Studio Code"<< endl
         << "3. Gaming"<< endl
         << "4. Web Browsing with the Chrome"<< endl
         << "5. Multiple Programming Tasks (both Android and VS Code"<< endl
         << "6. Zoom"<< endl
         << "7. Email"<< endl
         << "8. Create and edit documents"<< endl
         << "9. Everything listed above"<< endl;
    cin >> option;
    if (cin.fail()|| option<1 || option>9){
      cout << "You have entered an invalid value. The program will unable to continue. Exiting."<< endl;
    }
    else{
        switch (option) {
          case 1:
            if (RAM>=12){
              cout << "Congratulations! You have sufficient RAM for your task.";
            }else{
              cout << "Sorry the RAM you have is not sufficient.";
            }
            break;
          case 2:
            if (RAM>=8){
              cout << "Congratulations! You have sufficient RAM for your task.";
            }else{
              cout << "Sorry the RAM you have is not sufficient.";
            }
            break;
          case 3:
            if (RAM>=16){
              cout << "Congratulations! You have sufficient RAM for your task.";
            }else{
              cout << "Sorry the RAM you have is not sufficient.";
            }
            break;
          case 4:
            if (RAM>=8){
              cout << "Congratulations! You have sufficient RAM for your task.";
            }else{
              cout << "Sorry the RAM you have is not sufficient.";
            }
            break;
          case 5:
            if (RAM>=20){
              cout << "Congratulations! You have sufficient RAM for your task.";
            }else{
              cout << "Sorry the RAM you have is not sufficient.";
            }
            break;
          case 6:
            if (RAM>=8){
              cout << "Congratulations! You have sufficient RAM for your task.";
            }else{
              cout << "Sorry the RAM you have is not sufficient.";
            }
            break;
          case 7:
            if (RAM>=6){
              cout << "Congratulations! You have sufficient RAM for your task.";
            }else{
              cout << "Sorry the RAM you have is not sufficient.";
            }
            break;
          case 8:
            if (RAM>=6){
              cout << "Congratulations! You have sufficient RAM for your task.";
            }else{
              cout << "Sorry the RAM you have is not sufficient.";
            }
          break;
          case 9:
            if (RAM>=32){
              cout << "Congratulations! You have sufficient RAM for your task.";
            }else{
              cout << "Sorry the RAM you have is not sufficient.";
            }
          break;
      }
    }
  }

  return 0;
}