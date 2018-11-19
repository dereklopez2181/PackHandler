//******************************************************************
// Assignment 7: Postal Packages
// Programmer: Derek Lopez
// Completed : 10/29/2018
// Status    : Complete
//
// This source file contains functions: getCost, getGirth,
// validateShipReq and showInfo.
//******************************************************************

#include "PostalPackages.hpp"
#include <iostream>
#include <iomanip>


using namespace std;

const int SIZE = 15;

/*************************************************
 // Function: getCost()
 //
 // This function receives two arrays and a value.
 // It then uses linear search to find and return
 // the price.
 **************************************************/

double getCost(const int weight[], const double cost[], int value)
{
    
    
    //linear search function to find cost in parallel arrays
    int index = 0;
    int position = -1;
    bool found = false;
    double price = 0.0;
    
    while(index < SIZE && !found)
    {
        if(value <= weight[index])
        {
            found = true;
            position = index;
            price = cost[index];
        }
        index++;
    }
    
    return price;
   
}

/*************************************************
 // Function: getGirth()
 //
 // This function accepts an object as a parameter
 // and calculates the girth of the package.
 **************************************************/

int getGirth(ShippingInfo &package)
{
    //find the largest side of package
    int largest, girth;
    
    largest = package.side1;
    
    if(largest < package.side2)
        largest = package.side2;
    else if(largest < package.side3)
        largest = package.side3;
    
    //calculate girth
    girth = 2 * (package.side1 + package.side2 + package.side3 - largest);
    
    return girth;
    
}

/*************************************************
 // Function: validateShipReq()
 //
 // This function accepts an object as a parameter
 // and validates shipping requirements.
 **************************************************/

void validateShipReq(ShippingInfo &package)
{
    //variable to store package girth
    int girth;
   
    
    //function call to get girth
    girth = getGirth(package);
    
    //condition to validate package and set status
    if((package.packageWeight <= 0 || package.packageWeight > 50) || (package.side1 <= 0 || package.side1 > 36) || (package.side2 <= 0 || package.side2 > 36)||(package.side3 <= 0 || package.side3 > 36))
    {
        cout << "Error - package weight and dimensions must be larger than 0" << endl << endl;
        package.status = "Rejected";
        
    }
    else if(girth > 60)
        package.status = "Rejected";
    else
        package.status = "Accepted";
    
}
    
/*************************************************
 // Function: showInfo()
 //
 // This function accepts an object as a parameter
 // and validates shipping requirements.
 **************************************************/

void showInfo(ShippingInfo &package)
{
    
    //condition to format output based on package weight
    if(package.packageWeight <= 7)
        cout << showpoint << setprecision(3);
    else
        cout << showpoint << setprecision(4);
    
    //condition to format output based on package status
    if(package.status == "Rejected")
    {
        
        cout << "Status     :" << setw(10) << package.status << endl
             << "Weight     :" << setw(10) << package.packageWeight << endl
             << "Cost       :" << setw(10) << "N/A" << endl << endl;
    }
    else
    {
        
        cout << "Status     :" << setw(10) << package.status << endl
             << "Weight     :" << setw(10) << package.packageWeight << endl
             << "Cost       :" << setw(10) << package.cost << endl << endl;
    }
    
    cout << "For each transaction, enter package weight(lbs) and 3 dimensions(in) or -1 to quit: ";
    
}
