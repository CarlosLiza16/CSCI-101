/* Program name: Calendar Events
* Author: Carlos Lizarazu 
* Date last updated: 8/30/2024
* Purpose: Get information from the user regarding their next 5 calendar activities. Then, create a reminder one day before the event.
  Display the name event, day of the event, and the reminder. 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//function to format the day of the event
string formatDate(int month, int day, int year) {
    string monthStr = to_string(month);
    string dayStr = to_string(day);
    string yearStr = to_string(year);

    // Combine into mm/dd/yyyy format
    return monthStr + "/" + dayStr + "/" + yearStr;
}

int main(){

    //Define the variables for the event
    string first_event, second_event, third_event, fourth_event, fifth_event;
    
    //Define the variable for the month event
    int first_month, second_month, third_month, fourth_month, fifth_month;
    
    //Define the variable for the day event 
    int first_day, second_day, third_day, fourth_day, fifth_day;
    
    //Define the variable for the year
    int first_year, second_year, third_year, fourth_year, fifth_year;
    
    //Variable that will put together the month, day and year
    string fevent_day, Sevent_day, Tevent_day, Foevent_day, Fievent_day;

    //Variable that will put together the month, day and year for the reminder
    string freminder_event, Sreminder_event, Treminder_event, Foreminder_event, Fireminder_event;

    //define variable for the substraction of the day for the reminder
    int sus=0;

    //First event
    cout << "Enter the first event name: "; 
    getline(cin, first_event);
    cout << "Enter the month of the event: "; 
    cin >> first_month;
    cout << "Enter the day of the event: "; 
    cin >> first_day;
    cout << "Enter the year of the event: "; 
    cin >> first_year;
    
    cin.ignore();

    //Calling the function
    fevent_day = formatDate(first_month, first_day,first_year);

    //substract the day for the reminder
    sus = first_day - 1;

    //Calling the function for the reminder
    freminder_event = formatDate(first_month, sus, first_year);
    
    //second event
    cout << "Enter the second event name: "; 
    getline(cin, second_event);
    cout << "Enter the month of the event: "; 
    cin >> second_month;
    cout << "Enter the day of the event: "; 
    cin >> second_day;
    cout << "Enter the year of the event: "; 
    cin >> second_year;

    cin.ignore();

    //Calling the function
    Sevent_day = formatDate(second_month, second_day, second_year);

    //substract the day for the reminder
    sus = second_day - 1;

    //Calling the function for the reminder
    Sreminder_event = formatDate(second_month, sus, second_year);

    //Third event
    cout << "Enter the Third event name: "; 
    getline(cin, third_event);
    cout << "Enter the month of the event: "; 
    cin >> third_month;
    cout << "Enter the day of the event: "; 
    cin >> third_day;
    cout << "Enter the year of the event: "; 
    cin >> third_year;

    cin.ignore();

    //Calling the function
    Tevent_day = formatDate(third_month, third_day, third_year);

    //substract the day for the reminder
    sus = third_day - 1;

    //Calling the function for the reminder
    Treminder_event = formatDate(third_month, sus, third_year);

    //Fourth event
    cout << "Enter the Fourth event name: "; 
    getline(cin, fourth_event);
    cout << "Enter the month of the event: "; 
    cin >> fourth_month;
    cout << "Enter the day of the event: "; 
    cin >> fourth_day;
    cout << "Enter the year of the event: "; 
    cin >> fourth_year;

    cin.ignore();

    //Calling the function
    Foevent_day = formatDate(fourth_month, fourth_day, fourth_year);

    //substract the day for the reminder
    sus = fourth_day - 1;

    //Calling the function for the reminder
    Foreminder_event = formatDate(fourth_month, sus, fourth_year);

    //Fifth event
    cout << "Enter the Fifth event name: "; 
    getline(cin, fifth_event);
    cout << "Enter the month of the event: "; 
    cin >> fifth_month;
    cout << "Enter the day of the event: "; 
    cin >> fifth_day;
    cout << "Enter the year of the event: "; 
    cin >> fifth_year;

    cin.ignore();

    //Calling the function
    Fievent_day = formatDate(fifth_month, fifth_day, fifth_year);

    //substract the day for the reminder
    sus = fifth_day - 1;

    //Calling the function for the reminder
    Fireminder_event = formatDate(fifth_month, sus, fifth_year);


    //____________________________________Displayinf the table______________________________________
    //Table Heading
    cout << left;
    cout << "|" << setw(50) << setfill('-') << "-" << "|" << endl;
    cout << setfill(' ');
    cout << "| " << setw(19) << "Event Name" << "| " << setw(11) << "Event Date" << "| " << setw(15) << "Reminder Date" << "| " << endl;
    cout << "|" << setw(50) << setfill('-') << "-" << "|" << endl;

    //First row
    cout << setfill(' ');
    cout << "| " << setw(19) << first_event  << "| " << setw(11) << fevent_day << "| " << setw(15) << freminder_event << "| " << endl;
    cout << "|" << setw(50) << setfill('-') << "-" << "|" << endl;
    cout << setfill(' ');

    //Heading
    cout << setfill(' ');
    cout << "| " << setw(19) << "Event Name" << "| " << setw(11) << "Event Date" << "| " << setw(15) << "Reminder Date" << "| " << endl;
    cout << "|" << setw(50) << setfill('-') << "-" << "|" << endl;

    //Second row
    cout << setfill(' ');
    cout << "| " << setw(19) << second_event  << "| " << setw(11) << Sevent_day << "| " << setw(15) << Sreminder_event << "| " << endl;
    cout << "|" << setw(50) << setfill('-') << "-" << "|" << endl;
    cout << setfill(' ');

    //Heading
    cout << setfill(' ');
    cout << "| " << setw(19) << "Event Name" << "| " << setw(11) << "Event Date" << "| " << setw(15) << "Reminder Date" << "| " << endl;
    cout << "|" << setw(50) << setfill('-') << "-" << "|" << endl;

    //Thrid row
    cout << setfill(' ');
    cout << "| " << setw(19) << third_event  << "| " << setw(11) << Tevent_day << "| " << setw(15) << Treminder_event << "| " << endl;
    cout << "|" << setw(50) << setfill('-') << "-" << "|" << endl;
    cout << setfill(' ');

    //Heading
    cout << setfill(' ');
    cout << "| " << setw(19) << "Event Name" << "| " << setw(11) << "Event Date" << "| " << setw(15) << "Reminder Date" << "| " << endl;
    cout << "|" << setw(50) << setfill('-') << "-" << "|" << endl;

    //Fourth row
    cout << setfill(' ');
    cout << "| " << setw(19) << fourth_event  << "| " << setw(11) << Foevent_day << "| " << setw(15) << Foreminder_event << "| " << endl;
    cout << "|" << setw(50) << setfill('-') << "-" << "|" << endl;
    cout << setfill(' ');

    //Heading
    cout << setfill(' ');
    cout << "| " << setw(19) << "Event Name" << "| " << setw(11) << "Event Date" << "| " << setw(15) << "Reminder Date" << "| " << endl;
    cout << "|" << setw(50) << setfill('-') << "-" << "|" << endl;

    //Fifth row
    cout << setfill(' ');
    cout << "| " << setw(19) << fifth_event  << "| " << setw(11) << Fievent_day << "| " << setw(15) << Fireminder_event << "| " << endl;
    cout << "|" << setw(50) << setfill('-') << "-" << "|" << endl;
    cout << setfill(' ');
}