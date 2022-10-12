//***************************************************************************
//
//  book.h
//  CSCI 241 Assignment 5
//
//  Created by Aaron Hall (z1980019)
//
//***************************************************************************

#pragma once

class book 
{
private:
	char ISBN[11];
	char title[41];
	double price;
	int quantity;

public:
	book();
	char* get_isbn();
	double get_price();
	int fulfill_order(int quant);
	int compare(book);
	void print();

};
