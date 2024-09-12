/* Program name: High Score
   Author: Carlos Lizarazu
   Date last updated: 9/10/24
   Purpose: Read a file anf look for the highest score
*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<string> vec;
  string text;

  ifstream file("D:/Ivy Tech/Fall Semester 2024/CSCI-101/C++/M04 Assignments/scores.txt");

  while (file >> text) {
    vec.push_back(text);
  }

  cout << "IvyGames Tournament Results:" << endl;
  cout << setw(35) << setfill('-')<< "-"  << endl;
  cout << setfill(' ');
  cout << "| " << setw(15) << left << "Username" << "| " << setw(15) << "Score" << "|" << endl;
  cout << setw(35) << setfill('-') << "-" << endl;
  cout << setfill(' ');

  for (size_t i = 0; i < vec.size(); i = i + 2) {
    cout << "| " << setw(15) << left << vec[i] << "| " << setw(15) << vec[i + 1] << "|" << endl;
    cout << setw(35) << setfill('-') << "-" << endl;
    cout << setfill(' ');
  }

  //     looking the 3largest numbers   
  int first=0,second=0,third=0, in1=0, in2=0, in3=0;
  for (size_t j=1; j<vec.size(); j+=2){
    int num = stoi(vec[j]);

    if(num>first){
      third = second;
      in3 = in2;
      second=first;
      in2 = in1;
      first=num;
      in1 = j;
    }else if(num>second){
      third = second;
      in3 = in2;
      second = num;
      in2 = j;
    }else if(num>third){
      third = num;
      in3 = j;
    }
  }

  cout<<"The gold medal winner is "<<vec[in1-1]<<" with "<<vec[in1]<<" points"<<endl;
  cout<<"The silver medal winner is "<<vec[in2-1]<<" with "<<vec[in2]<<" points"<<endl;
  cout<<"The bronze medal winner is "<<vec[in3-1]<<" with "<<vec[in3]<<" points"<<endl;
  cout<<"Congratulations to the winners! See you at the next tournament."<<endl;
  return 0;
}