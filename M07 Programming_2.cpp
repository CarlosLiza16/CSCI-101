/* Program name: M07_programming assignment2.cpp
*  Author: Carlos Lizarazu
*  Date last updated: 10/07/24
*  Purpose: The program will open a file that has a list of items.
            Then the program will ask information to the user, and then track the order that they are making.
*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

// Ceclarinf the enum for the size
enum sizeType {
  S, // small
  M, // medium
  L  // large
};

// Declaring the struct for the mold
struct moldType {
  string shape;
  sizeType size;
  double price;
  double weight;
};

// declaring the struct for the customer
struct customerType {
  string fname;
  string lname;
  string address;
};

// declaring the order struct
struct orderType {
  customerType customer;
  vector<moldType> products; // array or vector for the molds
  int numProdOrdered;
  double subTotal;
  double totalWeight;
  double shippingCost;
};

// ReadCatalog function 1
void readCatalog(vector<moldType> &productCatalog, int &numProducts) {
  ifstream file("D:/Ivy Tech/Fall Semester 2024/CSCI-101/C++/M07 Assignments/catalog.txt"); // opening the file

  moldType mold;
  char sizeChar;

  // clear any precioud data
  productCatalog.clear();

  // Read each line, and storage in the vector
  while (file >> mold.shape >> sizeChar >> mold.price >> mold.weight) {
    // identify the size and map it
    if (sizeChar == 'S') {
      mold.size = S;
    } else if (sizeChar == 'M') {
      mold.size = M;
    } else if (sizeChar == 'L') {
      mold.size = L;
    }
    productCatalog.push_back(mold);
  }

  numProducts = productCatalog.size();
  file.close();
}

//Function 3 print the product
void printProduct(ostream& os, const moldType& mold){
  string sizeStr;
  switch (mold.size){
    case S:sizeStr = "Small";break;
    case M: sizeStr = "Medium"; break;
    case L: sizeStr = "Large"; break;
  }
  os <<mold.shape<<" - "<<sizeStr<<" $"<<fixed<<setprecision(2)<<mold.price<<" "<<mold.weight<<"g"<<endl;
}

//Function 4 print order
void printOrder(ostream& os, const orderType& order){
  os << " "<< endl;
  os << "Costumer: " << order.customer.fname <<" "<< order.customer.lname << endl;
  os << "Address: " << order.customer.address << endl;
  os<<" "<<endl;
  os << "Products Ordered:"<<endl;
  for (const auto& product : order.products) {
      printProduct(os, product);  // Reuse the printProduct function
  }

  double totalCost = order.subTotal + order.shippingCost;
  
  os <<" "<<endl;
  os << "Subtotal: $" << fixed << setprecision(2)<< order.subTotal << endl;
  os << "Total Weight: " << fixed << setprecision(2) << order.totalWeight << "g"<< endl;
  os << "Shipping Cost: $" << fixed << setprecision(2) << order.shippingCost << endl;
  os << "Total Cost: $" << fixed << setprecision(2) << totalCost << endl;
}

//Function 2 get the order from the user
void enterOrder(orderType &order, const vector<moldType> &catalog, int numItemInCatalog) {
  char answer = 'y';
  int count = 1;
  int choice;

  // Get customer information
  cout << "Enter the costumer first name: ";
  // using the struct order that also connects with the customer struct
  cin >> order.customer.fname;

  cout << "Enter the customer last name: ";
  cin >> order.customer.lname;

  cout << "Enter the customer street address: ";
  cin.ignore();
  getline(cin, order.customer.address);

  // The order starts
  while (answer == 'y') {
    if (count <= 10) {

      cout << "Please choose a product from the list: " << endl;
      // Show the list of the items
      for (size_t i = 0; i < numItemInCatalog; ++i) {
        cout << i + 1 << ": ";
        printProduct(cout, catalog[i]);  // Use printProduct to display catalog
      }
      // Loop until a valid product choice is made
      bool validChoice = false;
      while (!validChoice) {
          //Entering the option from the list
          if (cin >> choice) {
              if (choice >= 1 && choice <= numItemInCatalog) {
                  // Valid choice
                  validChoice = true;
                  order.products.push_back(catalog[choice - 1]);
                  order.subTotal += catalog[choice - 1].price;
                  order.totalWeight += catalog[choice - 1].weight;
                  order.shippingCost = 0.58 * (order.totalWeight / 28.35); // Calculate shipping cost
                  count += 1;
              }else {
                  // Invalid number, out of range
                  cout << "That is not a valid choice. Please choose a product from the list above." << endl;
              }
          }else{
            cout << "You entered something that is not a number. Please try again." << endl;
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
          }
      }

      //display that order
      for (const auto &product : order.products) {
        cout << "Item: " << product.shape << " - $" << product.price << " "
             << product.weight << "g added." << endl;
      }
      
      // Ask if they want to add another product
      cout << "Do you want to enter another product? [y]es - [n]o: ";
      cin >> answer;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout<<" "<<endl;
    }else{
      cout << "You have reached the limit of 10 products per order." << endl;
      break;
    }
  }
}

int main() {

  vector<moldType> productCatalog;
  int numProducts;
  orderType order;

  // Initialize the order fields
  order.subTotal = 0.0;
  order.totalWeight = 0.0;
  order.shippingCost = 0.0;

  // Read the catalog from the file and storage it in the arrar/vec
  readCatalog(productCatalog, numProducts);

  // Initializing the order
  cout << "Welcome to Judy's Resin Molds!" << endl;
  enterOrder(order, productCatalog, numProducts);

  //print the order
  printOrder(cout,order);

  

  return 0;
}
