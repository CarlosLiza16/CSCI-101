/* Program name: Gradebook
* Author: Carlos Lizarazu 
* Date last updated: 8/29/2024
* Purpose: Open a file, read it line by line and save it into a vector. Next, we will display the vector following a especif format.
*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include <sstream>
#include <vector>
using namespace std;

// Function to check if a sring is a float
bool isFloat(const string &str) {
  try {
    size_t idx;
    stof(str, &idx); // Try to convert the string to a float
    return idx == str.size() &&
           str.find('.') != string::npos; // Check if the entire string was a
                                          // valid float and contains a '.'
  } catch (const invalid_argument &) {
    return false; // Conversion failed, so it's not a float
  } catch (const out_of_range &) {
    return false; // Conversion failed due to out of range value
  }
}
// end of the function

int main() {
  // Create a vector to store 2 elements row, and column
  vector<vector<string>> elements; // elements vector
  string myText;

  ifstream MyReadFile("D:/Ivy Tech/Fall Semester 2024/CSCI-101/C++/M02 assignment/gradebook.txt");
  while (getline(MyReadFile, myText)) {
    // Makes the variable from the file to be able to manipulate as a value cin
    stringstream ss(myText);
    string element;

    vector<string> row; // row vector

    while (ss >> element) {
      // Check if the element is a floating-point number
      if (isFloat(element)) {
        float num = stof(element); // Convert the string to float
        num *= 100; // Multiply by 100 to get rid of the decimal point
        element = to_string(num); // Convert the number back to string
      }

      // Add the element to one row
      row.push_back(element);
    }
    // adding the whole row to the elements vector
    elements.push_back(row);
  }

  // Table header
  cout << left;
  cout << setfill('-') << setw(17) << "+-" << setw(32) << "+-" << setw(12) << "+-" << setw(12) << "+-" << "+" << endl;
  cout << setfill(' ');
  cout << "| " << setw(15) << "Student Num"<< "| " << setw(30) << "Student Name"<< "| " << setw(10) << "Percent"<< "| " << setw(10) << "Grade"<< "|" << endl;
  cout << setfill('-') << setw(17) << "+-" << setw(32) << "+-" << setw(12)<< "+-" << setw(12) << "+-"<< "+" << endl;
  cout << setfill(' ');

 for (size_t i = 0; i < elements.size(); ++i) {
        vector<string> row = elements[i];
        float num = stof(row[2]);
        //cout << "| " << setw(15) << row[0] << "| " << setw(30) << row[1] << "| " << setw(10) << setprecision(5) <<num<<"%" << "| " << setw(10) << row[3] << "|" << endl;
        cout << "| " << setw(15) << row[0]
        << "| " << setw(30) << row[1]
        << "| " << setw(6) << setprecision(5) << num 
        << "% " << setw(2) << " " 
        << "| " << setw(10)  << row[3] << "|" << endl;
        cout << setfill('-') << setw(17) << "+-" << setw(32) << "+-" << setw(12) << "+-" << setw(12) << "+-" << "+" << endl;
        cout << setfill(' ');
    }
  return 0;
}