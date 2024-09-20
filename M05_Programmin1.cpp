/* Program name: Accelaration
*  Author: Carlos Lizarazu
*  Date last updated: 09/20/2024
* Purpose: The program will determine the acceleration. 
* The user will allow the user to input the force or the racing pedal, and the time of the total acceleration.
*/

#include <iostream>
#include <iomanip>
#include <limits> 

using namespace std;

//___________function validation of the input____________________
double validation(string text, double min, double max){
  double value;
  while(true){
    cout<<text;
    if (cin>>value){
      if(value>min && value<=max){
        return value;
      }else if(value<=0){
          cout<<"The value has to be greater than 0"<<endl;
      }else{
        cout << "The value needs to be between " << min << " and " << max<<endl;
      }
    }else{
      cout<<"You entered something that is not a number. Please try again"<<endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }
}

//___________function findind speed____________________
double speedduetoacceleration(double a, int t) {
  double speed = a * t;
  return speed;
}

//___________function findind acceleration____________________
double accelerationFromButton(double f) {
  double a = f * 0.463;
  return a;
}

//______________main function starts_______________
int main() {

  int time, i = 0;
  double force, acceleration, speed;
  force = validation("Enter the button force between 0 and 10: ", 0.0,10.0);
  time=validation("Enter the total acceleration time in seconds: ", 0.0,1000);


  
  acceleration = accelerationFromButton(force);

  cout << "Acceleration is " << setprecision(4) << acceleration << " m/s^2"<< endl;
  
  //header 
  cout << setw(15) <<left<< "Time in s" << setw(15) << "Speed in m/s" << endl;
  cout << setw(30) << setfill('*') << "*" << endl;
  cout << setfill(' ');
  
  if (time % 3 == 0) {
    while (i <= time) {
      speed = speedduetoacceleration(acceleration, i);
      cout << setw(15) << left << i << setw(15) << fixed << setprecision(3) << speed << endl;
      i += 3;
    }
  } else {
    while (i <= time) {
      speed = speedduetoacceleration(acceleration, i);
      cout << setw(15) << left << i << setw(15) << fixed << setprecision(3) << speed << endl;
      i += 3;
      if (i > time) {
        speed = speedduetoacceleration(acceleration, i = time);
         cout << setw(15) << left << i << setw(15) << fixed << setprecision(3) << speed << endl;
        break;
      }
    }
  }

  return 0;
}