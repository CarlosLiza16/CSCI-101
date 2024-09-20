/* Program name: Volume and Mass
*  Author: Carlos Lizarazu
*  Date last updated: 09/20/2024
* Purpose: The program will help bakers to convert measurements from weight to volume and vice versa
*/

#include <iostream>
#include <map>
#include <limits> 
#include <iomanip>

using namespace std;

//funciton 1 
string getingredient(){
  string in;
  // variable ingredient
  string arr[8]={"Sugar","Flour", "Cocoa Powder", "Honey", "Egg", "Milk", "Water", "Oil"}; 
  
  while(true){
    cout<<"Enter the name of the ingredient: ";
    getline(cin,in);
    
    if(!in.empty()){
      for(int i = 0; i < 8; i++) {
        if( arr[i] == in) {
          return in;          
        }
      }
    }
    cout<<"I don't know that ingredient. Here is a list of ingredients I know: "<<endl;
    for (int j=0; j < 8; j++){
      cout<<arr[j]<<(j < 7 ? ", " : "");
    }
    cout<<" "<<endl;
  }
}

//Function 2
double getDensity(int ingredientValue){

  //Creating the density varable
  double den[8]={1.59,0.762,1.35,1.38,1.031,1.025,0.997,0.91};
  switch(ingredientValue){
    case 1:
      return den[0];
      break;
    case 2:
      return den[1];
      break;
    case 3:
      return den[2];
      break;
    case 4:
      return den[3];
      break;
    case 5:
      return den[4];
      break;
    case 6:
      return den[5];
      break;
    case 7:
      return den[6];
      break;
    case 8:
      return den[7];
      break;
    //default value in case there is no matches
    default:
      return 0.0;
  }
}

//Function 3
//Get the weight
double getweight(){
  double w;

  while(true){
    cout<<"Enter the weight of your ingredient in g: ";
    if(cin>>w){
      if(w<=0){
        cout<<"Weight has to be greater than 0"<<endl;
      }
      else{
        return w;
      }
    }
    cout<<"You entered something that is not a number. Please Try again."<<endl;
    cin.clear();  // clear the error flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
}

//Function 4 get the Volumen
double getvolumen(){
  double v;

  while(true){
    cout<<"Enter the volumen of your ingredient in ml: ";
    if(cin>>v){
      if(v<=0){
        cout<<"Weight has to be greater than 0"<<endl;
      }
      else{
        return v;
      }
    }
    cout<<"You entered something that is not a number. Please Try again."<<endl;
    cin.clear();  // clear the error flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
}

//Function 5 convert Weight
double convertweight(double w, double d){
  double convertion = w/d;
  return convertion;
}

//Function 6 convert Weight
double convertvolumen(double v, double d){
  double convertion = v*d;
  return convertion;
}


int main(){
    
  string ingredient, convert;
  double density, weight,volumen,convertion;

  //Header messages
  cout<<"Welcome to the baking converter."<<endl;
  cout<<"This program takes a baking ingredient and converts a weight to a volume unit or a volume to a weight unit."<<endl;
  
  
  //Calling the function for the get ingredient
  ingredient = getingredient();

  // Create a map to associate ingredients with integers
  map<string, int> ingredientMap;
  ingredientMap["Sugar"] = 1;
  ingredientMap["Flour"] = 2;
  ingredientMap["Cocoa Powder"] = 3;
  ingredientMap["Honey"] = 4;
  ingredientMap["Egg"] = 5;
  ingredientMap["Milk"] = 6;
  ingredientMap["Water"] = 7;
  ingredientMap["Oil"] = 8;

  //Calling the function to get the density of the ingredient
  density = getDensity(ingredientMap[ingredient]);

  cout<<"Do you want to convert from weight or volumen? (Enter W or V): ";
  cin>>convert;
  if(convert == "V"){
    //Calling the function for the volumen
    volumen = getvolumen();
    convertion = convertvolumen(volumen,density);
    cout<<fixed << setprecision(4)<<volumen<<" ml of "<<ingredient<<" is "<< fixed << setprecision(4)<<convertion<<" g"<<endl;
  }else{
    //calling the function fo the weight
    weight = getweight();
    convertion = convertweight(weight,density);
    cout<<fixed << setprecision(4)<<weight<<" g of "<<ingredient<<" is "<<fixed << setprecision(4)<<convertion<<" ml"<<endl;
  }
  
  return 0;
}