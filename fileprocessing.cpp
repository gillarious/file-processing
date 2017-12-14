// fileprocessing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

void compute(double totalsales, double costofsales, double & netprofit, int & count, double & totalnetprofit);

int main()
{
	system("cls");
	system("Color 17");

	string salesperson;
	double totalsales, costofsales;
	double netprofit;

	int count = 0;
	double totalnetprofit = 0;
	ifstream inFile("empdata.txt", ios::in);

	if (!inFile)
	{
		cerr << "File could not be opened " << endl;

		exit(1);
	}
	while (inFile >> salesperson >> totalsales >> costofsales)
	{
		compute(totalsales, costofsales, netprofit, count, totalnetprofit);

		cout << setw(13) << salesperson << setw(9) << totalsales << setw(9) << costofsales << setw(9) << netprofit << endl;
	}

	cout << "The total net profit is " << totalnetprofit << endl;
	return 0;
}

void compute(double totalsales, double costofsales, double & netprofit, int & count, double & totalnetprofit)
{
	netprofit = totalsales - costofsales;
	count = count + 1;
	totalnetprofit = totalnetprofit + netprofit;

}
