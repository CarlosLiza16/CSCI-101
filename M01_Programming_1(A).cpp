/* Program name: Custom Cars
*  Author: Carlos Lizarazu
*  Date last updated: 09/25/2024
* Purpose: The program is for a Dealership shop. It will be able to let the user choose 3 different colors.
* One for the Body, one for the Top, and one for the Trim.
*/

#include <iostream>
#include <limits> 

using namespace std;

enum carColorType{
  Sunset_Orange=1,
  Cherry_Bomb,
  Phantom_Black,
  Titanium_Silver,
  Geaux_Gold,
  Lightning_Yellow,
  Fores_Green,
  Midnight_Blue,
  Passion_Purple,
  Root_Beer,
  Storm_Surge,
  Oceans_Rip,
  Glacial_White
};
//Function for the list
string colorList(){
  string arr[13]={"Sunset_Orange",
  "Cherry_Bomb",
  "Phantom_Black",
  "Titanium_Silver",
  "Geaux_Gold",
  "Lightning_Yellow",
  "Fores_Green",
  "Midnight_Blue",
  "Passion_Purple",
  "Root_Beer",
  "Storm_Surge",
  "Oceans_Rip",
  "Glacial_White"};
  //Declare the variable
  string output="";
  for(int i=0; i<=12; i++){
    output += to_string(i+1)+". "+arr[i]+'\n';
  }
  return output;
}
//Function to get the color
string getColor(){
  int cPart;
  cout<<colorList();
  while(true){
    if(cin>>cPart){
      if(cPart<=0 || cPart>13){
        cout<<"Please enter the number next to the color you want to choose: "<<endl;
      }else{
        switch(cPart){
          case 1:
            return "Sunset Orange";
            break;
          case 2:
            return "Cherry Bomb";
            break;
          case 3:
            return "Phantom Black";
            break;
          case 4:
            return "Titanium Silver";
            break;
          case 5:
            return "Geaux Gold";
            break;
          case 6:
            return "Lightning Yellow";
            break;
          case 7:
            return "Fores Green";
            break;
          case 8:
            return "Midnight Blue";
            break;
          case 9:
            return "Passion Purple";
            break;
          case 10:
            return "Root Beer";
            break;
          case 11:
            return "Storm Surge";
            break;
          case 12:
            return "Oceans Rip";
            break;
          case 13:
            return "Glacial White";
            break;
        }
        
      }
    }else{
      cout<<"You entered something that is not a number. Please Try again."<<endl;
      cin.clear();  // clear the error flag
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }
}

//Function to print the color
void printColor(string array[3]){
  for(int j=0; j<=3; j++){
    if(j==0){
      cout<<"You have chosen "<<array[j]<<" for the body, ";
    }else if(j==1){
      cout<<array[j]<<" for the top, and ";
    }else if(j==2){
      cout<<array[j]<<" for the trim"<<endl;
    }
  }
}

//Main function starts here

int main(){
  
  string arr[3]={"","",""};
  for (int i=0; i<=3;i++){
    if(i==0){
      cout<<"Please choose a color for the Body"<<endl;
      string color = getColor();
      arr[i]=color;
    }else if(i==1){
      cout<<"Please choose a color for the Top"<<endl;
      string color = getColor();
      arr[i]=color;
    }else if(i==2){
      cout<<"Please choose a color for the Trim"<<endl;
      string color = getColor();
      arr[i]=color;
    }
  }  
  //Call the print color function
  printColor(arr);
  cout<<"Do you want to continue with your order? [Y]es or [N]ot"<<endl;
  
  return 0;
}