#include <iostream>
#include <string>
using namespace std;
int main()
{


	int numUnits; 
	cout << "Units sent: ";
	cin >> numUnits;
	
	if (numUnits < 0)    // I put an if condition after each input that would end the progam if the input was invalid and print the correct message after the ---
	{
		cout << "---" << endl;
		cout << "The number of units sent must be nonnegative." << endl;
		return 1;   
	}
	cin.ignore(10000, '\n'); // since I'm using a getline after reading a number, I have to add this so it will work correctly

	string movieTitle;
	cout << "Title: ";
	getline(cin, movieTitle);
	
	if (movieTitle.empty())       
	{
		cout << "---" << endl;
		cout << "You must enter a title." << endl;
		return 1;
	}
	
	cout.setf(ios::fixed);
	cout.precision(2); // I used this to make sure that the $ values have two decimal places after

	double basePrice; 
	cout << "Base price: ";
	cin >> basePrice;
	
	if (basePrice < 0)
	{
		cout << "---" << endl;
		cout << "The base price must be nonnegative." << endl;
		return 1;
	}

	cin.ignore(10000, '\n');

	string premItem;
	cout << "Premium item? (y/n): ";
	getline(cin, premItem);
	
	if (premItem != "y" && premItem != "n")
	{
		cout << "---" << endl;
		cout << "You must enter y or n." << endl;
		return 1;
	}
	
	double royaltyRate;    //this changes the royalty rate that I multiply with the (up to)800 units after the initial 400 depending on if it's premium or not
	if (premItem == "y")
		royaltyRate = 0.16;
	else if (premItem == "n")
		royaltyRate = 0.13;
		
	cout << "---" << endl;
	 
	double lilUnits = 400.00 * basePrice * 0.09;                 //this is the total royalties from the first 400 units if there were at least 400 units sold  
	double lotsaUnits = 800.00 * basePrice * royaltyRate;        //this is the total royalties from the 800 units after the initial 400 if there were at least 1200 units sold
																 //I made doubles for these because I didn't want to type it all out in the lines below
	if (numUnits <= 400)
		cout << movieTitle << " earned $" << (numUnits * basePrice * 0.09) << " in royalties." << endl;
	else if (numUnits <= 1200)
		cout << movieTitle << " earned $" << lilUnits + ((numUnits - 400) * basePrice * royaltyRate) << " in royalties." << endl;
	else if (numUnits > 1200)
		cout << movieTitle << " earned $" << lilUnits + lotsaUnits + ((numUnits - 1200) * basePrice * 0.14) << " in royalties." << endl;
}