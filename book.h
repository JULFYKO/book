#pragma once
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;

struct Book {
    string author;
    string name;
    int year;
    bool available;

    Book(const string& author, const string& name, int year, bool available)
        : author(author), name(name), year(year), available(available) {}

    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << "Author: " << book.author << ", Title: " << book.name
            << ", Year: " << book.year << ", Available: "
            << (book.available ? "Yes" : "No");
        return os;
    }
};

class Library {
    list<Book> lib;

public:
    void addBook(const string& author, const string& name, int year, bool available = true) {
        lib.emplace_back(author, name, year, available);
    }

    void printAllBooks() const {
        for (const auto& book : lib) {
            cout << book << endl;
        }
    }

    void findBook(const string& author, const string& name) const {
        auto it = std::find_if(lib.begin(), lib.end(), [&author, &name](const Book& b) {
            return b.author == author && b.name == name;
            });
        if (it != lib.end()) {
            cout << "Found: " << *it << endl;
        }
        else {
            cout << "Book not found.\n";
        }
    }

    void findBooksByAuthor(const string& author) const {
        for (const auto& book : lib) {
            if (book.author == author) {
                cout << book << endl;
            }
        }
    }

    void issueBook(const string& author, const string& name) {
        auto it = std::find_if(lib.begin(), lib.end(), [&author, &name](const Book& b) {
            return b.author == author && b.name == name;
            });
        if (it != lib.end() && it->available) {
            it->available = false;
            cout << "Book issued: " << *it << endl;
        }
        else {
            cout << "Book not available or not found.\n";
        }
    }

    void returnBook(const string& author, const string& name) {
        auto it = std::find_if(lib.begin(), lib.end(), [&author, &name](const Book& b) {
            return b.author == author && b.name == name;
            });
        if (it != lib.end() && !it->available) {
            it->available = true;
            cout << "Book returned: " << *it << endl;
        }
        else {
            cout << "Book not found or already available.\n";
        }
    }

    void sortBooks() {
        lib.sort([](const Book& a, const Book& b) {
            return a.author < b.author || (a.author == b.author && a.name < b.name);
            });
        cout << "Books sorted.\n";
    }

    void removeBook(const string& author, const string& name, int year) {
        lib.remove_if([&author, &name, year](const Book& b) {
            return b.author == author && b.name == name && b.year == year;
            });
        cout << "Book removed if found.\n";
    }

    void removeBookByIndex(size_t index) {
        if (index >= lib.size()) {
            cout << "Invalid index.\n";
            return;
        }
        auto it = lib.begin();
        std::advance(it, index);
        lib.erase(it);
        cout << "Book removed by index.\n";
    }

    void editBook(const string& author, const string& name) {
        auto it = std::find_if(lib.begin(), lib.end(), [&author, &name](const Book& b) {
            return b.author == author && b.name == name;
            });
        if (it != lib.end()) {
            cout << "Editing book: " << *it << endl;
            cout << "Enter new author: ";
            cin >> it->author;
            cout << "Enter new title: ";
            cin >> it->name;
            cout << "Enter new year: ";
            cin >> it->year;
            cout << "Availability (1 - yes, 0 - no): ";
            cin >> it->available;
            cout << "Book updated.\n";
        }
        else {
            cout << "Book not found.\n";
        }
    }
};
