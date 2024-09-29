/* Program name: Custom Cars
*  Author: Carlos Lizarazu
*  Date last updated: 09/25/2024
* Purpose: The program is for a Dealership shop. It will be able to let the user choose 3 different colors.
* One for the Body, one for the Top, and one for the Trim.
*/

#include <iostream>
//library for limits in the while true cin value
#include <limits>
//Addin libraries for the file, and string
#include <fstream>
#include <string>

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
  for(int i=0; i<13; i++){
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
          case 1: return "Sunset Orange";
            break;
          case 2: return "Cherry Bomb";
            break;
          case 3: return "Phantom Black";
            break;
          case 4: return "Titanium Silver";
            break;
          case 5: return "Geaux Gold";
            break;
          case 6: return "Lightning Yellow";
            break;
          case 7: return "Fores Green";
            break;
          case 8: return "Midnight Blue";
            break;
          case 9: return "Passion Purple";
            break;
          case 10: return "Root Beer";
            break;
          case 11: return "Storm Surge";
            break;
          case 12: return "Oceans Rip";
            break;
          case 13: return "Glacial White";
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
  cout<<"You have chosen "<<array[0]<<" for the body, "
    << array[1]<<" for the top, and "<<array[2]<<" for the trim."<<endl;
}

//Function that will store the orders
void readExistingOrder(){
  string cusName;
  cout << "Enter the customer last name for the order: ";
  cin >> cusName;
  string filename = cusName+".txt";
  //asking if the file exists
  ifstream file(filename);
      if (file) {
          string topColor, bodyColor, trimColor;
          getline(file, bodyColor);
          getline(file, topColor);
          getline(file, trimColor);

          cout << "Here is the order for " << cusName << "\n"
               << "Body Color: " << bodyColor << "\n"
               << "Top Color: " << topColor << "\n"
               << "Trim Color: " << trimColor << endl;
      } else {
          cout << "We could not find the order. Sorry " << cusName << endl;
      }
}
//Main function starts here

int main(){
  int maxCustomers = 10, cusCount=0, option;
  //Fisrt array for the 10 maximun customeres
  string cusNames[maxCustomers];
  //Second array 2d for the ustomer name and the 3 colors
  string cusColors[maxCustomers][3];
  //Yes or Not answer
  string answer="y";

  cout<<"Welcome to the car customizer!"<<endl;
  //Looping starts
  while(answer=="y" || answer=="Y"){
    cout<<"Please choose an option from the menu:"<<endl;
    cout<<"1. Read Existing Order"<<endl;
    cout<<"2. Add New Order"<<endl;
    cout<<"3. Quit"<<endl;
    cin>>option;

    if(option==1){
      readExistingOrder();
    }//closing the if 
    else if(option==2){
      if(cusCount >= maxCustomers){
        cout<<"You have entered the maximum number of orders, the program will now save all orders and quit."<<endl;
        cout<<"Thank you for using the car customizer. The orders will be saved in files named customerLastName.txt."<<endl;
        break;
      }
      //creating the new customer
      string lastname;
      cout<<"Enter the lastname for the order: ";
      cin>>lastname;
      cusNames[cusCount]=lastname;
      //For loop and calling the function to get the color
      for(int i=0; i<3; i++){
        cout<<"Please choose a color for the "
          << (i == 0 ? "Body" : i == 1 ? "Top" : "Trim") <<endl; //using ternary condition
        cusColors[cusCount][i]= getColor();
      }
      printColor(cusColors[cusCount]);
      cusCount+=1;
      cout<<"Do you want to continue with your order? [Y]es or [N]ot"<<endl;
      cin>>answer;
    }//closing else if option 2
    else if(option==3){
      //writing thew orders to the file
      for(int j=0; j<cusCount;j++){
        ofstream outfile(cusNames[j]+".txt");
        outfile<<cusColors[j][0]<<endl; //for the Body color
        outfile<<cusColors[j][1]<<endl; //for the top color
        outfile<<cusColors[j][2]<<endl;// for the trim color
        outfile.close();
      }
      
      cout<<"Thank you for using the car customizer. The orders will be saved in files named customerLastName.txt."<<endl;
      break;
    }//closing else if option 3
    else{
      cout<<"Invalid option entered"<<endl;
      break;
    }//closing the else statement
  }//closing the while loop
  for(int j=0; j<cusCount;j++){
    ofstream outfile(cusNames[j]+".txt");
    outfile<<cusColors[j][0]<<endl; //for the Body color
    outfile<<cusColors[j][1]<<endl; //for the top color
    outfile<<cusColors[j][2]<<endl;// for the trim color
    outfile.close();
  }
  
  return 0;
}