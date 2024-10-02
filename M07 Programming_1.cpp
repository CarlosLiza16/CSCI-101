/* Program name: M07 Programming Assignment.cpp
*  Author: Carlos Lizarazu
*  Date last updated: 10/1/2024
*  Purpose: The program will let the user to create characters asking for a name and the type of character they want to have
*/

#include <iostream>
#include <string>
#include <cctype> //for the tolower
#include <limits>
using namespace std;

// Declaring the enum for the character class
enum class characterClassType { Fighter = 1, Rogue, Magic, Cleric };

// Declare a structure for the character type
struct characterType {
  string name;
  double hp;
  double mp;
  int strength;
  int dexterity;
  int intelligence;
  int speed;
  int endurance;
  int faith;
  characterClassType characterClass;
};
// Function to display the character array
void displayCharacters(const string chaArray[][9], int characterCount) {
    cout << "Here are the characters you created:" << endl;
    for (int i = 0; i < characterCount; i++) {
        // Print the character's name and class
        cout<< chaArray[i][0] << " the ";

        // For simplicity, let's assume classes can be determined by a simple condition (you can refine this)
        if (chaArray[i][1] == "30" && chaArray[i][2] == "0") {
            cout << "Fighter";
        } else if (chaArray[i][1] == "20" && chaArray[i][2] == "0") {
            cout << "Rogue";
        } else if (chaArray[i][1] == "10" && chaArray[i][2] == "20") {
            cout << "Magician";
        } else if (chaArray[i][1] == "25" && chaArray[i][2] == "15") {
            cout << "Cleric";
        }
        cout << " stats:" << endl;

        // Output character attributes
        cout << "HP: " << chaArray[i][1] << endl;
        cout << "MP: " << chaArray[i][2] << endl;
        cout << "Strength: " << chaArray[i][3] << endl;
        cout << "Dexterity: " << chaArray[i][4] << endl;
        cout << "Intelligence: " << chaArray[i][5] << endl;
        cout << "Speed: " << chaArray[i][6] << endl;
        cout << "Endurance: " << chaArray[i][7] << endl;
        cout << "Faith: " << chaArray[i][8] << endl;
        cout << endl; // Blank line between characters
    }
}

int main() {

  const int maxCharacters = 10;
  const int maxItems = 9;
  string chaArray[maxCharacters][maxItems];

  characterType character; // declaring the variable to use the struct
  int option;              // declaring variable for the user menu

  //Control variable
  string answer = "y";
  int characterControl = 0;//To keep track of how many characters have been created
  
  //Loop for the user input
  while(answer == "y"){
    if(characterControl < maxCharacters){
      cout << "What is your character name? ";
      getline(cin, character.name);
      cout << "What charcater class do you want " + character.name + " to be? "
           << endl;
      cout << "1. Fighter Class" << endl;
      cout << "2. Rogue Class" << endl;
      cout << "3. Magician Class" << endl;
      cout << "4. Cleric Class" << endl;
      cin>>option;
      if(option>=1 && option<=4){
        switch (option) {
          case static_cast<int>(characterClassType::Fighter):
            character.hp = 30;
            character.mp = 0;
            character.strength = 16;
            character.dexterity = 10;
            character.intelligence = 5;
            character.speed = 8;
            character.endurance = 15;
            character.faith = 5;
            break;
          case static_cast<int>(characterClassType::Rogue):
            character.hp = 30;
            character.mp = 0;
            character.strength = 16;
            character.dexterity = 10;
            character.intelligence = 5;
            character.speed = 8;
            character.endurance = 15;
            character.faith = 5;

            break;
          case static_cast<int>(characterClassType::Magic):
            character.hp = 30;
            character.mp = 0;
            character.strength = 16;
            character.dexterity = 10;
            character.intelligence = 5;
            character.speed = 8;
            character.endurance = 15;
            character.faith = 5;
            break;
          case static_cast<int>(characterClassType::Cleric):
            character.hp = 30;
            character.mp = 0;
            character.strength = 16;
            character.dexterity = 10;
            character.intelligence = 5;
            character.speed = 8;
            character.endurance = 15;
            character.faith = 5;
            break;
        }

        // Store character data in chaArray
        chaArray[characterControl][0] = character.name;
        chaArray[characterControl][1] = to_string(static_cast<int>(character.hp));
        chaArray[characterControl][2] = to_string(static_cast<int>(character.mp));
        chaArray[characterControl][3] = to_string(character.strength);
        chaArray[characterControl][4] = to_string(character.dexterity);
        chaArray[characterControl][5] = to_string(character.intelligence);
        chaArray[characterControl][6] = to_string(character.speed);
        chaArray[characterControl][7] = to_string(character.endurance);
        chaArray[characterControl][8] = to_string(character.faith);

        characterControl++; //Increment the control character variable

        char s;
        cout<<"Do you want to create a new character? [y]es or [n]o: ";
        cin>>s;
        answer = tolower(s);
      }else{
        cout<<"That is not a valid choice. Please choose the class by number from the list."<<endl;
      }
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
  }

  if (answer!="y"){
    // Display the created characters
    if (characterControl > 0) {
        displayCharacters(chaArray, characterControl);
    } else {
        cout << "No characters were created." << endl;
    }
  }  
  
  return 0;
}