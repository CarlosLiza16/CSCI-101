#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

//Enum for the menu
enum MenuItem{
  VEGGIE_BURGER = 35,
  HAMBURGER = 45,
  FRIED_CHICKEN_SLIDERS = 38,
  HAMBURGER_SLIDERS = 38,
  VEGGIE_SLIDERS = 38,
  HADDOCK_SANDWICH = 38,
  BLT = 42,
  FAUX_BLT = 42,
  CHICKEN_BURRITO = 42,
  FALAFEL_WRAP = 42,
  CHEESE_PIZZA = 59,
  PEPPERONI_PIZZA = 59,
  FAUX_MEAT_AND_CHIPS = 77,
  FISH_AND_CHIPS = 77
};

//Struct for the reservation
struct Reservation{
  string time;
  string customername;
  int numberParty;
};

//struct manage the table
struct Table{
  int tableNumber;
  int maxSize;
  int currentSeated;
  int isOccupied;

  Table(int num, int size) : tableNumber(num), maxSize(size), isOccupied(false) {}
};

//Struct for the order
struct Order {
    Table* assignedTable; // Pointer to the table assigned for the reservation
    Reservation* reservation;
    vector<MenuItem> itemsOrdered; // Vector holding the ordered items
    int numItemsOrdered; // Number of items ordered (1 per person in the party)
    bool isCompleted; // True if the order is completed (delivered to the table)
    bool isPaid; // True if the bill for this order has been paid

};

//function for the reservation
Reservation makeReservation(){

  Reservation reserv;
  char confirmation;

  cout<<"Enter a name for the reservation: ";
  cin.ignore();//ignore the empty new line
  getline(cin, reserv.customername);

  cout<<"Enter the number of people in the party: ";
  cin>>reserv.numberParty;

  cout<<"Enter a the time for the reservation: ";
  cin.ignore();//ignore the empty new line
  getline(cin, reserv.time);

  //Confirmation of the reservation
  cout<<"Please confirm the reservation:"<<endl;
  cout<<"Reservation name: "<<reserv.customername<<endl;
  cout<<"Reservation Time: "<<reserv.time<<endl;
  cout<<"Number in Party: "<<reserv.numberParty<<endl;
  cout<<"Is this information correct [Y]es, [N]o, [C]ancel ";
  cin>> confirmation;

  if (confirmation == 'Y' || confirmation == 'y') {
        cout << "Reservation confirmed!" << endl;
    }else {
        cout << "Sorry, let's try again" << endl;
        reserv = {}; // Reset the reservation data if not confirmed
    }

  return reserv;
}

void checkInReservation(vector<Reservation>& reservationList, vector<Table>& tables){
  if (reservationList.empty()) {
    cout << "No reservations available." << endl;
  } 
  else {
    cout << "Choose the reservation to check in:" << endl;
    for (size_t i = 0; i < reservationList.size(); ++i) {
        cout << (i + 1) << ": " << reservationList[i].customername 
              << " - " << reservationList[i].time 
              << ", " << reservationList[i].numberParty << " people" << endl;
    }

    // Prompt the user to select a reservation to check-in
    int reservationOption;
    cin>> reservationOption;

    //promop the available tables
    cout << "Please Assign a table ";

    if (reservationOption > 0 && reservationOption <= reservationList.size()) {
      Reservation selectedReservation = reservationList[reservationOption - 1];
        
      //show table availables
      for (const auto& table : tables) {
        if (!table.isOccupied && table.maxSize >= selectedReservation.numberParty) {
          cout<< table.tableNumber <<": "<< table.maxSize << endl;
        } 
      }

      //Select the table
      int selectTable;
      cin>>selectTable;
      // Mark the selected table as occupied
      for (auto& table : tables) {
          if (table.tableNumber == selectTable && !table.isOccupied && table.maxSize >= selectedReservation.numberParty) {
              table.isOccupied = true;
              cout << "Table " << selectTable << " is now occupied." << endl;
              break;
          }
      }
    }
  }
}

//function to enter the order
void enterOrder(vector<Table>& tables, vector<Reservation>& reservationList, vector<Order>& orders){
  //enter order
  cout<<"Please choose the table for the order: "<<endl;

  //variable to check if the tables are occupied or not
  bool occupiedTables = false;

  for (const auto& table: tables){
    if (table.isOccupied) {
      cout << table.tableNumber << ": Table for " << table.maxSize << " people" << endl;
      occupiedTables = true;
    }
  }

  if (!occupiedTables){
    cout<<"No tables have been checked in yet"<<endl;
  }

  int selectedTableOrder;
  cin>> selectedTableOrder;


  // Find the selected table and corresponding reservation
  Table* selectedTable = nullptr;
  Reservation* correspondingReservation = nullptr;
  for (auto& table : tables) {
      if (table.tableNumber == selectedTableOrder && table.isOccupied) {
          selectedTable = &table;
          break;
      }
  }
  //Find the part of the table selected
  for(auto& reservation : reservationList){
    if(reservation.numberParty == selectedTable-> maxSize){
      correspondingReservation = &reservation;
    }
  }
  if (!correspondingReservation) {
    cout << "No reservation found for the selected table." << endl;
  }

  // Start the order for the reservation
  int remainingOrders = correspondingReservation->numberParty;
  //Struct order 
  Order newOrder;
  newOrder.assignedTable = selectedTable;
  newOrder.reservation = correspondingReservation;
  newOrder.numItemsOrdered = 0;
  newOrder.isCompleted = false;
  newOrder.isPaid = false;

  //display the manu of option
  for(int i=1; i<=remainingOrders; ++i){
    cout << "Please choose entree number " << i << endl;
    cout << "1: Veggie Burger" << endl;
    cout << "2: Hamburger" << endl;
    cout << "3: Fried Chicken Sliders" << endl;
    cout << "4: Hamburger Sliders" << endl;
    cout << "5: Veggie Sliders" << endl;
    cout << "6: Haddock Sandwich" << endl;
    cout << "7: BLT" << endl;
    cout << "8: Faux BLT" << endl;
    cout << "9: Chicken Burrito" << endl;
    cout << "10: Falafel Wrap" << endl;
    cout << "11: Cheese Pizza" << endl;
    cout << "12: Pepperoni Pizza" << endl;
    cout << "13: Faux Meat and Chips" << endl;
    cout << "14: Fish and Chips" << endl;

    int menuOption;
    cout<<"Please choose entree number "<<i<<endl;
    cin>> menuOption;
    
    switch(menuOption){
      case 1:
      newOrder.itemsOrdered.push_back(MenuItem::VEGGIE_BURGER);
      break;
      case 2:
          newOrder.itemsOrdered.push_back(MenuItem::HAMBURGER);
          break;
      case 3:
          newOrder.itemsOrdered.push_back(MenuItem::FRIED_CHICKEN_SLIDERS);
          break;
      case 4:
          newOrder.itemsOrdered.push_back(MenuItem::HAMBURGER_SLIDERS);
          break;
      case 5:
          newOrder.itemsOrdered.push_back(MenuItem::VEGGIE_SLIDERS);
          break;
      case 6:
          newOrder.itemsOrdered.push_back(MenuItem::HADDOCK_SANDWICH);
          break;
      case 7:
          newOrder.itemsOrdered.push_back(MenuItem::BLT);
          break;
      case 8:
          newOrder.itemsOrdered.push_back(MenuItem::FAUX_BLT);
          break;
      case 9:
          newOrder.itemsOrdered.push_back(MenuItem::CHICKEN_BURRITO);
          break;
      case 10:
          newOrder.itemsOrdered.push_back(MenuItem::FALAFEL_WRAP);
          break;
      case 11:
          newOrder.itemsOrdered.push_back(MenuItem::CHEESE_PIZZA);
          break;
      case 12:
          newOrder.itemsOrdered.push_back(MenuItem::PEPPERONI_PIZZA);
          break;
      case 13:
          newOrder.itemsOrdered.push_back(MenuItem::FAUX_MEAT_AND_CHIPS);
          break;
      case 14:
          newOrder.itemsOrdered.push_back(MenuItem::FISH_AND_CHIPS);
          break;
    }
  }

  orders.push_back(newOrder); //adding the order to the table for orders to complete
  cout << "Order completed for table " << selectedTable->tableNumber << "." << endl;
}

//funciton for the complete order
void completeOrder(vector<Order>& orders){
  if(orders.empty()){
    cout<<"No actives orders to comple at the moment"<<endl;
  }

  cout<<"Choose the order to complete: "<<endl;
  for (size_t i = 0; i < orders.size(); ++i) {
    if (!orders[i].isCompleted) {
        cout << orders[i].assignedTable->tableNumber << ": Table for " 
              << orders[i].assignedTable->maxSize << " people" << endl;
    }
  }

  int tableToComplete;
  cin>>tableToComplete;

  bool foundOrder = false;
  for (auto& order : orders){
    if (order.assignedTable->tableNumber == tableToComplete && !order.isCompleted) {
            order.isCompleted = true;
            cout << "Order for table " << tableToComplete << " has been marked as completed." << endl;
            foundOrder = true;
        }
  }
}

//Function to calculate the bill
void calculateBillAndPay(vector<Order>& orders){
  int billTable;
  cout<<"Choose the order to calculate the bill: "<<endl;
  bool hasOrders = false;
  for (const auto& order : orders) {
      if (!order.isPaid) {
          cout << "Table " << order.assignedTable->tableNumber << endl;
          hasOrders = true;
      }
  }

  if (!hasOrders) {
    cout << "No tables with pending orders found." << endl;
    return;
  }

  cin >> billTable;

  //look for the order for the bill table selected
  Order* currentOrder = nullptr;
  for (auto& order : orders) {
    if (order.assignedTable->tableNumber == billTable && !order.isPaid) {
      currentOrder = &order;
      break;
    }
  }

  //calculate subtotal
  double subTotal = 0.0;
  for (const auto& item : currentOrder->itemsOrdered) {
    subTotal += static_cast<double>(item);  // MenuItem values correspond to the prices
  }

  // Calculate the tax and tip
  double tax = subTotal * 0.10;       
  double tip = subTotal * 0.20;       
  double total = subTotal + tax + tip;

  //display the total
  cout<<"Subtotal: $"<< subTotal <<endl;
  cout<<"Tip: $"<< tax <<endl;
  cout<<"Tax: $"<< tip <<endl;
  cout<<"Total: $"<< total <<endl;
  char confirmation;
  cout << "Pay bill? [Y]es, [N]o: ";
  cin >> confirmation;
  if (confirmation == 'Y' || confirmation == 'y') {
    currentOrder->isPaid = true;
    cout << "Payment received. Thank you!" << endl;
  } else {
    cout << "Payment deferred." << endl;
  }

}
//Main funciton starts here

int main(){

  vector<Reservation> reservationList; // Vector to store confirmed reservations
  Reservation reserv; //instance of the Reservation
  vector<Order> orders; //storr the orders

  //Creating an vector for the table and its capacities
  vector<Table> tables;
  for (int i = 1; i <= 8; ++i) tables.push_back(Table(i, 2));   // 8 tables of 2 people
  for (int i = 9; i <= 10; ++i) tables.push_back(Table(i, 10));  // 2 tables of 10 people
  for (int i = 11; i <= 14; ++i) tables.push_back(Table(i, 6));  // 4 tables of 6 people
  for (int i = 15; i <= 20; ++i) tables.push_back(Table(i, 4));  // 6 tables of 4 people

  int option;
  while (true){
    //Program start with the main opcion menu
    cout<<"welcome to MessiJoes"<<endl;
    cout<<"1. Make Reservation"<<endl;
    cout<<"2. Check-in Reservation"<<endl;
    cout<<"3. Enter Order"<<endl;
    cout<<"4. Complete Order"<<endl;
    cout<<"5. Calculate and Pay Bill"<<endl;  
    
    //validation of the first menu
  
    if(cin>>option){
      if(option>=1 && option<=5){
        switch (option){
          case 1:
            //make a reservation
            reserv = makeReservation();
            if (!reserv.customername.empty()) { // Check if reservation was confirmed
                reservationList.push_back(reserv);
            }
            break;
          case 2:
            //check in
              checkInReservation(reservationList, tables);
              break;
          case 3:
            //enter the order for table that are already check in
            enterOrder(tables, reservationList,orders);
            break;
          case 4:
            //complete order
            completeOrder(orders);
            break;
          case 5:
            //Calculate bill
            calculateBillAndPay(orders);
            break;
        }
      }
      else{
        cout<<"Choose one of the options from the list"<<endl;
      }
    }
    else{
      cout<<"You entered something that is not a number"<<endl;
      cin.clear();  // Clears the fail state of cin
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
  }//endl of the while
  

  return 0;
}
