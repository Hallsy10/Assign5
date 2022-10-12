//***************************************************************************
//
//  book.h
//  CSCI 241 Assignment 5
//
//  Created by Aaron Hall (z1980019)
//
//***************************************************************************

#include "book.h"
#include "book_store.h"

int main()
{
	book_store b;

	b.read_book_data("bookdata");
	b.print();
	b.process_orders("orders.txt");
	b.print();

	return 0;
}