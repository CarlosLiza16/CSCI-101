/* Program name: Ghost Hunting
*  Author: Carlos Lizarazu
*  Date last updated: 9/5/2024
* Purpose: The program will read data from ghosts.txt. The file contains evidence collected during a recent ghost hunt.
* If the haunting score is greater than 15, then you should display the message "This place is haunted." Otherwise, 
* the program should display "This place is probably not haunted."
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() 
{
  vector<string> elements;
  char ch;
  int num, score=0;
  
  ifstream file("D:/Ivy Tech/Fall Semester 2024/CSCI-101/C++/M03 Assignments/ghosts.txt");
  while(file.get(ch)){
    if(!isspace(ch)){
      elements.push_back(string(1,ch));
    }
  }
    
  for (int i=0; i<elements.size(); i++){
    if(elements[i]=="E"){
      cout<<"Found "<<elements[i+1]<<" instances of EVP (Electronic Voice Phenomena)"<<endl;
      num = stoi(elements[i+1]);
      num = num*3;
      score+=num;
    }else{
      if(elements[i]=="S"){
        cout<<"Found "<<elements[i+1]<<" instances of Shadows or Orbs"<<endl;
        num = stoi(elements[i+1]);
        num = num*1;
        score+=num;
      }else{
        if(elements[i]=="F"){
          cout<<"Found "<<elements[i+1]<<" instances of Footsteps"<<endl;
          num = stoi(elements[i+1]);
          num = num*2;
          score+=num;
        }else{
          if(elements[i]=="A"){
            cout<<"Found "<<elements[i+1]<<" instances of Full Body Apparition"<<endl;
            num = stoi(elements[i+1]);
            num = num*5;
            score+=num;
          }else{
            if(elements[i]=="O"){
              cout<<"Found "<<elements[i+1]<<" instances of Objects moving on own"<<endl;
              num = stoi(elements[i+1]);
              num = num*5;
              score+=num;
            }else{
              if(elements[i]=="D"){
                cout<<"Found "<<elements[i+1]<<" instances of Doors shutting on own"<<endl;
                num = stoi(elements[i+1]);
                num = num*3;
                score+=num;
              }else{
                if(elements[i]=="T"){
                  cout<<"Found "<<elements[i+1]<<" instances of ThermoCamera hot or cold spots"<<endl;
                  num = stoi(elements[i+1]);
                  num = num*2;
                  score+=num;
                }
              }
            }
          }
        }
      }
    }//closing the first else

  }//closing the for

  cout<<"The haunting score for this place is "<< score<<endl;
  if (score>15){
    cout<<"This place is hauted"<<endl;
  }else{
    cout<<"This place is probably not haunted."<<endl;
  }
  cout<<"Great job! On to the next one"<< endl;
  
  
  return 0;
}