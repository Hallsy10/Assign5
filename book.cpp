//***************************************************************************
//
//  book.h
//  CSCI 241 Assignment 5
//
//  Created by Aaron Hall (z1980019)
//
//***************************************************************************

#include "book.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

book::book()
{
	strcpy(ISBN, "Nothing");
	strcpy(title, "Nothing");
	price = 0;
	quantity = 0;
}

char* book::get_isbn() 
{
	return ISBN;
}

double book::get_price()
{
	return price;
}

int book::fulfill_order(int quant)
{
	if (quantity == 0)
		return 0;
	else if (quant <= quantity) 
	{
		quantity = quantity - quant;
		return quant;
	}
	else
	{
		quant = quantity;
		quantity = 0;
		return quant;
	}
}

int book::compare(book b) 
{
	return strcmp(ISBN, b.get_isbn());
}

void book::print()
{
	cout << setfill(' ');
	cout << left << setw(14) << ISBN << setw(44) << title << setw(5) << right << fixed << setprecision(2)
		<< price << setw(6) << quantity << "\n";
}
