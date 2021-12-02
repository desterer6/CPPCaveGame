
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
using namespace std;

// Global constants
const int ROWS = 9;
const int COLS = 9;

//---------------------------------------------------
// Read and convert location string to row col value
//---------------------------------------------------
void get_location(int &row, int &col)
{
   // Initialize variables
   row = -1;
   col = -1;

   // Loop until a valid location is entered
   while (row < 0 || row > ROWS-1 || col < 0 || col > COLS-1)
   {
      // Get user input
      cout << "Enter location between A1 and I9: " << endl;
      string location = "";
      cin >> location;
   
      // Calculate col between 0 and COLS-1
      if (location.length() > 0)
         col = location[0] - 'A';
 
      // Print error message
      if (col < 0 || col > COLS-1)
         cout << "Error: column should be between A and I" << endl;

      // Calculate row between 0 and ROWS-1
      if (location.length() > 1)
         row = location[1] - '1';
 
      // Print error message
      if (row < 0 || row > ROWS-1)
         cout << "Error: row should be between 1 and 9" << endl;
   }
}

//---------------------------------------------------
// Print command menu to user and get input
//---------------------------------------------------
int get_menu_choice()
{
   // Print command menu
   cout << "Welcome to MiniCalc the PF1 Killer App\n"
        << "   0) Quit the program\n"
        << "   1) Store specified data value\n"
        << "   2) Store random data values\n"
        << "   3) Calculate minimum of data values\n"
        << "   4) Calculate maximum of data values\n"
        << "   5) Calculate sum of data values\n"
        << "   6) Calculate product of data values\n"
        << "   7) Calculate average of data values\n"
        << "   8) Calculate standard deviation of data values\n";

   // Initialize variables
   string input = "";
   int command = -1;

   // Loop until a valid location is entered
   while (command < 0 || command > 8)
   {
      // Get user input
      cout << "Enter command: ";
      cin >> input;
      if (input.length() == 1)
         command = input[0] - '0';

      // Print error message
      if (command < 0 || command > 8)
         cout << "Error: command should be between 0 and 8" << endl;
   }
   return command;
}

//STORE VALUE IN ARRAY
void storeValue(int row1, int col1, int row2, int col2, float val, float data[ROWS][COLS])
{
    
    for(int r = row1; r <= row2; r++)
    {
        for(int c = col1; c <= col2; c++)
        {
            data[r][c] = val;
        }
    }
    cout << "The value " << val << " has been stored.\n" << endl;
    return;
}

//STORE RANDOM VALUES
void randomValues(int high, int low, int row1, int col1, int row2, int col2, float data[ROWS][COLS])
{
    srand (time(NULL));
    int range = high - low + 1;
    for(int row = row1; row <= row2; row++)
    {
        for(int col = col1; col <= col2; col++)
        {
            data[row][col] = rand() % range + low;
        }
    }
}

//CALCULATE MINIMUM VALUE
void findMin(int row1, int col1, int row2, int col2, int row3, int col3, float data[ROWS][COLS])
{
    float min = data[row1][col1];
    for(int row = row1; row <= row2; row++)
    {
        for(int col = col1; col <= col2; col++)
        {
            
            if(data[row][col] < min)
                min = data[row][col];
        }
    }
    storeValue(row3, col3, row3, col3, min, data);
}

//CALCULATE MAXIMUM VALUE
void findMax(int row1, int col1, int row2, int col2, int row3, int col3, float data[ROWS][COLS])
{
    float max = data[row1][col1];
    for(int row = row1; row <= row2; row++)
    {
        for(int col = col1; col <= col2; col++)
        {
            
            if(data[row][col] > max)
                max = data[row][col];
        }
    }
    storeValue(row3, col3, row3, col3, max, data);
}

//CALCULATE SUM
void findSum(int row1, int col1, int row2, int col2, int row3, int col3, float data[ROWS][COLS])
{
    float sum = 0.0;
    for(int row = row1; row <= row2; row++)
    {
        for(int col = col1; col <= col2; col++)
        {
            sum = sum + data[row][col];
        }
    }
    storeValue(row3, col3, row3, col3, sum, data);
}


//CALCULATE PRODUCT
void findProduct(int row1, int col1, int row2, int col2, int row3, int col3, float data[ROWS][COLS])
{
    float prod = 1.0;
    for(int row = row1; row <= row2; row++)
    {
        for(int col = col1; col <= col2; col++)
        {
            prod = prod * data[row][col];
        }
    }
    storeValue(row3, col3, row3, col3, prod, data);
}


//CALCULATE AVERAGE
void findAverage(int row1, int col1, int row2, int col2, int row3, int col3, float data[ROWS][COLS])
{
    int count;
    float avg, sum;
    for(int row = row1; row <= row2; row++)
    {
        for(int col = col1; col <= col2; col++)
        {
            count++;
            sum = sum + data[row][col];
        }
    }
    avg = sum / count;
    storeValue(row3, col3, row3, col3, avg, data);
}

//CALCULATE STANDARD DEVIATION
void findSTD(int row1, int col1, int row2, int col2, int row3, int col3, float data[ROWS][COLS])
{
    int count;
    float avg, sum;
    for(int row = row1; row <= row2; row++)
    {
        for(int col = col1; col <= col2; col++)
        {
            count++;
            sum = sum + data[row][col];
        }
    }
    avg = sum / count;
    
    float std, total;
    for(int row = row1; row <= row2; row++)
    {
        for(int col = col1; col <= col2; col++)
        {
            float dif = data[row][col] - avg;
            total = total + dif * dif;
        }
    }
    
    std = sqrt(total / count);
    storeValue(row3, col3, row3, col3, std, data);
}



// MAIN
int main()
{
   // Initialize spreadsheet array
   float data[ROWS][COLS];
   for (int row = 0; row < ROWS; row++)
      for (int col = 0; col < COLS; col++)
         data[row][col] = 0;

   // Loop processing menu commands
   int command = get_menu_choice();
   while (command != 0)
   {
      
      switch(command)
      {
          int row1, col1, row2, col2;
          int row3, col3;
         //STORE VALUE 1
         case 1:
            float val;
            cout << "Please enter FLOAT value you want to store: ";
            cin >> val;
            get_location(row1, col1);
            get_location(row2, col2);
            if(row1 <= row2 && col1 <= col2)
                storeValue(row1, col1, row2, col2, val, data);
            else
                storeValue(row2, col2, row1, col1, val, data);
            break;

         //RANDOM VALUE 2
         case 2:
            int high, low;
            cin >> low >> high;
            get_location(row1, col1);
            get_location(row2, col2);
            if(row1 <= row2 && col1 <= col2)
                randomValues(low, high, row1, col1, row2, col2, data);
            else
                randomValues(low, high, row2, col2, row1, col1, data);
            break;
            
         //MINIMUM VALUE 3 
         case 3:
            get_location(row1, col1);
            get_location(row2, col2);
            get_location(row3, col3);
            if(row1 <= row2 && col1 <= col2)
                findMin(row1, col1, row2, col2, row3, col3, data);
            else
                findMin(row2, col2, row1, col1, row3, col3, data);
            break;
        
         //MAXIMUM VALUE 4
         case 4:
            get_location(row1, col1);
            get_location(row2, col2);
            get_location(row3, col3);
            if(row1 <= row2 && col1 <= col2)
                findMax(row1, col1, row2, col2, row3, col3, data);
            else
                findMax(row2, col2, row1, col1, row3, col3, data);
            break;
        
         //CALCULATE SUM 5
         case 5:
            get_location(row1, col1);
            get_location(row2, col2);
            get_location(row3, col3);
            if(row1 <= row2 && col1 <= col2)
                findSum(row1, col1, row2, col2, row3, col3, data);
            else
                findSum(row2, col2, row1, col1, row3, col3, data);
            break;
        
         //CALCULARE PRODUCT 6
         case 6:
            get_location(row1, col1);
            get_location(row2, col2);
            get_location(row3, col3);
            if(row1 <= row2 && col1 <= col2)
                findProduct(row1, col1, row2, col2, row3, col3, data);
            else
                findProduct(row2, col2, row1, col1, row3, col3, data);
            break;
        
         //CALCULATE AVERAGE 7
         case 7:
            get_location(row1, col1);
            get_location(row2, col2);
            get_location(row3, col3);
            if(row1 <= row2 && col1 <= col2)
                findAverage(row1, col1, row2, col2, row3, col3, data);
            else
                findAverage(row2, col2, row1, col1, row3, col3, data);
            break;
        
         //CALCULATE STDEV 8
         case 8:
            get_location(row1, col1);
            get_location(row2, col2);
            get_location(row3, col3);
            if(row1 <= row2 && col1 <= col2)
                findSTD(row1, col1, row2, col2, row3, col3, data);
            else
                findSTD(row2, col2, row1, col1, row3, col3, data);
            break;
         
         //ERROR
         default:
            cout << "ERROR. INVALID COMMAND." << endl;
          
      }
      
      for (int row = 0; row < ROWS; row++)
      {
        for (int col = 0; col < COLS; col++)
        {
            cout << data[row][col] << "\t";
        }
        cout << endl;
      }
      
      // Get next command
      command = get_menu_choice();
 
   }
   return 0;
}
