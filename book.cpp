#include "book.h"
int main() {
    Library myLibrary;

    myLibrary.addBook("test_name_N1", "test_book_N1", 1111);
    myLibrary.addBook("test_name_N2", "test_book_N2", 2222);
    myLibrary.addBook("test_name_N2", "test_book_N3", 3333);

    cout << "All books:\n";
    myLibrary.printAllBooks();

    cout << "\nFinding 'test_book_N2':\n";
    myLibrary.findBook("test_name_N2", "test_book_N2");

    cout << "\nIssuing 'test_book_N2':\n";
    myLibrary.issueBook("test_name_N2", "test_book_N2");

    cout << "\nIssuing 'test_book_N2' again:\n";
    myLibrary.issueBook("test_name_N2", "test_book_N2");

    cout << "\nReturning 'test_book_N2':\n";
    myLibrary.returnBook("test_name_N2", "test_book_N2");

    cout << "\nSorting books:\n";
    myLibrary.sortBooks();
    myLibrary.printAllBooks();

    cout << "\nRemoving 'test_book_N1':\n";
    myLibrary.removeBook("test_name_N1", "test_book_N1", 1111);
    myLibrary.printAllBooks();

    cout << "\nEditing 'test_book_N3':\n";
    myLibrary.editBook("test_name_N2", "test_book_N3");
    myLibrary.printAllBooks();

    return 0;
}
