//******************************************************************
// Assignment 7: Postal Packages
// Programmer: Derek Lopez
// Completed : 10/29/2018
// Status    : Complete
//
// This header file contains a struct and four function prototypes
//******************************************************************

#ifndef PostalPackages_hpp
#define PostalPackages_hpp

#include <string>

using namespace std;

//define a struct ShippingInfo to hold package information
struct ShippingInfo
{
    
    int packageWeight,
        side1,
        side2,
        side3;
    string status;
    
    double cost;
    
};

//function protoypes
double getCost(const int weight[], const double cost[], int value);

int getGirth(ShippingInfo &package);

void validateShipReq(ShippingInfo &package);

void showInfo(ShippingInfo &package);


#endif /* PostalPackages_hpp */
