//***************************************************************************
//
//  book.h
//  CSCI 241 Assignment 5
//
//  Created by Aaron Hall (z1980019)
//
//***************************************************************************

#include "book_store.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int book_store::binarySearch(char* isbn)
{
	int start = 0;
	int end = count - 1;
	int mid = (end - start) / 2;

	while ( start <= end)
	{
	if (strcmp(arr[mid].get_isbn(), isbn) == 0)
		return mid;
	else if (strcmp(arr[mid].get_isbn(), isbn) < 0)
		start = mid + 1;
	else
		end = mid - 1;
	}

	return -1;
}

void book_store::sort()
{
	std::vector<book> books(arr, arr + 15);
	std::sort(books.begin(), books.end(), [](book a,book b){
		return stoull(a.get_isbn()) < stoull(b.get_isbn());
	});
	for (size_t i = 0; i < books.size(); i++)
		arr[i] = books[i];
}

book_store::book_store()
{
	count = 0;
}

void book_store::print()
{
	cout << setfill(' ');

	cout << left << setw(14) << "ISBN" << setw(44) << "Title" << setw(5) << right << "Price"
		<< setw(10) << "Qty.\n\n";

	for(size_t i = 0; i < 15; i++)
		arr[i].print();

	cout << "Book Inventory Listing\n\n";
	
}

void book_store::read_book_data(string bookdata)
{
	ifstream in_file;

    // Open the input file and test for failure.
    in_file.open(bookdata);
    if (!in_file)
    {
        cerr << "Error - unable to open input file " << bookdata << endl;
        exit(1);
    }
    
    // Read an entire Course object worth of bytes into the Course object
    // that was used to call the read_student_data() member function.
    in_file.read((char*) this, sizeof(book_store));
    
    in_file.close();
	sort();
}

void book_store::process_orders(string orders)
{
	//I couldn't get this working properly so I just commented it all out
	
	// ifstream file(orders);

	// int orderNumber = 0;
	// int quantity = 0;
	// string isbn;
	// char* array[11];

	// cout << "\n\nOrder Listing\n\n";

	// for(int j = 0; j < 10; j++)
	// {
	// 	file >> orderNumber >> isbn >> quantity;

	// 	strcpy(array, isbn.c_str());
	// 	int i = binarySearch(array);
	// 	int q;
	// 	if (i == -1)
	// 		cout << "Order: " << orderNumber << " error - ISBN " << isbn << " does not exist\n";

	// 	else
	// 	{
	// 		q = arr[i].fulfill_order(quantity);

	// 		cout << "Order: " << orderNumber << " ISBN " << isbn << ", " << q << " of " << quantity
	// 			<< " shipped, order total $" << q * arr[i].get_price() << "\n";
	// 	}
	// }
}