#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

class Book {
public:
    string title;
    string author;
    bool isIssued;

    Book(string t, string a) : title(t), author(a), isIssued(false) {}
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // Using push_back
        cout << "Book added successfully: " << title << endl;
    }

    void issueBook(const string& title) {
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].title == title) {
                if (!books[i].isIssued) {
                    books[i].isIssued = true;
                    cout << "Book issued: " << title << endl;
                } else {
                    cout << "Book is already issued: " << title << endl;
                }
                return;
            }
        }
        cout << "Book not found: " << title << endl;
    }

    void returnBook(const string& title) {
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].title == title) {
                if (books[i].isIssued) {
                    books[i].isIssued = false;

                    // Ask the user for the number of days the book was kept
                    int daysKept;
                    cout << "Enter the number of days the book was kept: ";
                    cin >> daysKept;

                    if (daysKept > 7) {
                        int fine = (daysKept - 7) * 10;
                        cout << "Book returned late by " << daysKept - 7
                             << " days. Fine imposed: Rs. " << fine << endl;
                    } else {
                        cout << "Book returned on time: " << title << endl;
                    }
                } else {
                    cout << "Book was not issued: " << title << endl;
                }
                return;
            }
        }
        cout << "Book not found: " << title << endl;
    }

    void displayBooks() {
        cout << left << setw(30) << "Title" << setw(30) << "Author" << "Status" << endl;
        cout << string(80, '-') << endl;
        for (size_t i = 0; i < books.size(); ++i) {
            cout << left << setw(30) << books[i].title << setw(30) << books[i].author
                 << (books[i].isIssued ? "Issued" : "Available") << endl;
        }
    }
};

int main() 
{
	
	cout<<"***  WELCOME TO LIBRARY MANAGEMENT ***\n \n";
	char pass[5]="1234",p[5];
	int opt;
	cout<<"Enter the 4-digit system PIN:";
	cin>>p;

	if(strcmp(pass,p)==0)
	{
			 	cout<<"** You are Logged in **\n";
    Library library;
    int choice;
    string title, author;

    do {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Issue Book" << endl;
        cout << "3. Return Book" << endl;
        cout << "4. Display All Books" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // to clear the newline character from the buffer

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter author name: ";
                getline(cin, author);
                library.addBook(title, author);
                break;
            case 2:
                cout << "Enter book title to issue: ";
                getline(cin, title);
                library.issueBook(title);
                break;
            case 3:
                cout << "Enter book title to return: ";
                getline(cin, title);
                library.returnBook(title);
                break;
            case 4:
                library.displayBooks();
                break;
            case 5:
                cout << " * Thank You * \n" << endl;
                cout<<"**You are exicted***";
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
            cout<<"!!!----------------*******---------------!!!\n \n";
        }
    } while (choice != 5);
   }
   else
   {
   		cout<<"Wrong password\n";
   }

    return 0;
}

