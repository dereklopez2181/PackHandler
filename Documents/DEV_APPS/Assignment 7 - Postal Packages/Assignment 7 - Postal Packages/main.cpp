//******************************************************************
// Assignment 7: Postal Packages
// Programmer: Derek Lopez
// Completed : 10/29/2018
// Status    : Complete
//
// This main.cpp file calls functions from PostalPackages.hpp
//******************************************************************
#include "PostalPackages.hpp"
#include <iostream>
#include <iomanip>


using namespace std;

const int SIZE = 15;

int main()
{
    //declare a struct to hold package information
    ShippingInfo package;
    
    
    int index = 0,
        acceptedCount = 0,
        rejectedCount = 0;
    

    
    //initialize arrays
    int weightArray[SIZE] = {1,2,3,5,7,10,13,16,20,25,30,35,40,45,50};
    double costArray[SIZE] = {1.50,2.10,4.00,6.75,9.90,14.95,19.40,24.20,27.30,31.90,38.50,43.50,44.80,47.40,55.20};
    
    
    
    
    //Prompt user for transactions
    cout << "For each transaction, enter package weight(lbs) and 3 dimensions(in) or -1 to quit: ";
    
    //Read in transactons from user
    cin  >> package.packageWeight;
    
    //loop to process transactions
    while(package.packageWeight != -1)
    {
        
        
        //get sides from user
        cin >> package.side1 >> package.side2 >> package.side3;
        cout << endl << endl;
        
        //function call to validate shipping requirements
        validateShipReq(package);
        
        
        
        //function call to search for cost
        package.cost = getCost(weightArray, costArray, package.packageWeight);
        
        //output to display transaction number
        cout << "Transaction:" << setw(10) << index + 1 << endl;
        
        //function call to show package information
        showInfo(package);
         
        //count to keep track of Accepted and Rejected packages
        if(package.status == "Accepted")
            acceptedCount++;
        else
            rejectedCount++;
        
        //Read in transactons from user
        cin  >> package.packageWeight;
        
        //increment the transaction number
        index++;
        
    
    }
    
    //End program and display accepted and rejected transactions
    cout << "\nEnding program. . .\n\n"
         << "Accepted transactions: " << acceptedCount << endl
         << "Rejected transactions: " << rejectedCount << endl;
    
    
    return 0;
}
