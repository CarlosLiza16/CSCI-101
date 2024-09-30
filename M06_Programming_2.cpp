/* Program name: Grade Analysis
*  Author: Carlos Lizarazu
*  Date last updated: 09/30/2024
* Purpose: The program will open a file with grades of students.
* The Prgroam will create a 2d array and fill the grades in there. Next, the program will do some statidics with the grades.
* The program will get the highest score, lowest score, avergae score, and the median score. 
*/

#include <fstream>
#include <iomanip>
#include <iostream>


using namespace std;

// Function to find the highest score
void getHighScore(double scores[][5], int numRows, int column, double &highestScore){
  highestScore = scores[0][column];
  //Loop that will go trhough each row
  for (int r=1; r<numRows; r++){ //we start from the second row
    if(scores[r][column]>highestScore){
      highestScore = scores[r][column]; //update the ne highest score
    }
  }
}

// Function for the lowest score 
void getLowScore(double scores[][5], int numRows, int column, double &lowScore){
  lowScore = scores[0][column];

  //Loop that will go trhough each row
  for (int r = 1; r<numRows; r++){ //we start from the second row
    if(scores[r][column]<lowScore){
      lowScore = scores[r][column]; //update the lowest score
    }
  }
}

// Function for the Average score 
void getAverageScore(double scores[][5], int numRows, int column, double &averageScore){
  averageScore = 0;

  //Loop that will go trhough each row
  for (int r = 0; r<numRows; r++){ //we start from the second row
    averageScore += scores[r][column];
  }
  averageScore = averageScore/numRows;
}

//Function to sort the arra of numbers for the median.
void selectionSort(double array[],int numScores){
  for (int i=0; i<numScores-1; i++){
    int minIndex=i;
    for(int j=i+1; j<numScores; j++){
      if(array[j]<array[minIndex]){
        minIndex=j;
      }
    }
    if(minIndex!=i){
      swap(array[i],array[minIndex]);
    }
  }
}

// Function for the Median score 
void getMedianScore(double scores[][5], int numRows, int column, double &medianScore){
  //Create the the array that we will use to sort the numbers
  double sort[numRows];

  //pass the value form the scores to the new array
  for (int i = 0; i< numRows; i++){
    sort[i]= scores[i][column];
  }

  //calling the sort function
  selectionSort(sort,numRows);

  //making sure if we have a odd or even number of grades
  if(numRows%2==0){
    medianScore = (sort[(numRows/2)-1]+sort[numRows/2])/2.0;
  }else{
    medianScore = sort[numRows/2];
  }
  
}



int main() {
  const int maxStudents = 12;
  const int numTests = 5;

  double scores[maxStudents][numTests];
  ifstream file("grades.txt");

  // Check for the file
  if (!file) {
      cout << "Error opening the file" << endl;
      return 1;
  }

  // Read data from the file into the scores array
  for (int i = 0; i < maxStudents; i++) {
      for (int j = 0; j < numTests; j++) {
          file >> scores[i][j];
      }
  }

  file.close();
  
  cout<<"Grade Statistics: "<<endl;

  //We call the functions and show the results
  for (int i=0; i<5; i++){
    int column=i;

    cout<<"Test "<<i+1<<endl;
    //Calling the function for the highest number
    double highScore;
    getHighScore(scores, maxStudents, column, highScore);
    cout<<fixed<<setprecision(2)<< setw(20)<<"Highest score: "<<highScore<<endl;

    //Calling the funtion for the lowest number
    double lowestScore;
    getLowScore(scores, maxStudents, column, lowestScore);
    cout<<fixed<<setprecision(2)<< setw(19)<<"Lowest score: "<<lowestScore<<endl;

    //Calling the funtion for the average number
    double averageScore;
    getAverageScore(scores, maxStudents, column, averageScore);
    cout<<fixed<<setprecision(2)<< setw(20)<<"Average score: "<<averageScore<<endl;

    //Calling the median Score
    double medianScore;
    getMedianScore(scores, maxStudents, column, medianScore);
    cout<< setw(19)<<"Median score: "<<medianScore<<endl;

    cout<<""<<endl;
  }

  return 0;
}