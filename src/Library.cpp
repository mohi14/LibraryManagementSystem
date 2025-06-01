#include "Library.h"
#include <fstream>
#include<algorithm>
#include<iostream>

void Library::addBook(std::string title, std::string author, std::string isbn){
    books.emplace_back(nextBookId++,std::move(title), std::move(author), std::move(isbn));
    std::cout << "Book added successfully with ID: " << (nextBookId - 1)<< "\n";
}

void Library::displayAllBooks() const {
    if (books.empty()) {
        std::cout << "No books in the library.\n";
        return;
    }
    for (const auto& book : books) {
        book.display();
    }
}
void Library::searchBooks(const std::string& keyword) const {
    bool found = false;
    for (const auto& book : books) {
        if (book.getTitle().find(keyword) != std::string::npos ||
            book.getAuthor().find(keyword) != std::string::npos ||
            book.getIsbn().find(keyword) != std::string::npos) {
            book.display();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No books found matching your search.\n";
    }
}
void Library::addUser(std::string name, std::string email) {
    users.emplace_back(nextUserId++, std::move(name), std::move(email));
    std::cout << "User added successfully with ID: " << (nextUserId - 1) << "\n";
}

void Library::displayAllUsers() const {
    if (users.empty()) {
        std::cout << "No users registered.\n";
        return;
    }
    for (const auto& user : users) {
        user.display();
    }
}
void Library::borrowBook(int userId, int bookId) {
    auto userIt = findUserById(userId);
    auto bookIt = findBookById(bookId);

    if (userIt == users.end()) {
        std::cout << "User not found.\n";
        return;
    }

    if (bookIt == books.end()) {
        std::cout << "Book not found.\n";
        return;
    }

    if (!bookIt->isAvailable()) {
        std::cout << "Book is already borrowed.\n";
        return;
    }

    bookIt->setAvailable(false);
    userIt->borrowBook(bookId);
    addTransaction(userId, bookId, Transaction::Type::BORROW);
    std::cout << "Book borrowed successfully.\n";
}

void Library::returnBook(int userId, int bookId) {
    auto userIt = findUserById(userId);
    auto bookIt = findBookById(bookId);

    if (userIt == users.end()) {
        std::cout << "User not found.\n";
        return;
    }

    if (bookIt == books.end()) {
        std::cout << "Book not found.\n";
        return;
    }

    if (bookIt->isAvailable()) {
        std::cout << "Book was not borrowed.\n";
        return;
    }

    if (!userIt->returnBook(bookId)) {
        std::cout << "This user didn't borrow this book.\n";
        return;
    }

    bookIt->setAvailable(true);
    addTransaction(userId, bookId, Transaction::Type::RETURN);
    std::cout << "Book returned successfully.\n";
}
void Library::displayAllTransactions() const {
    if (transactions.empty()) {
        std::cout << "No transactions recorded.\n";
        return;
    }
    for (const auto& transaction : transactions) {
        transaction.display();
    }
}

void Library::saveData() {
    jsonStorage.saveBooks(books, nextBookId);
    jsonStorage.saveUsers(users, nextUserId);
    jsonStorage.saveTransactions(transactions);
    std::cout << "All data saved successfully.\n";
}
void Library::loadData() {
    auto [loadedBooks, bookNextId] = jsonStorage.loadBooks();
    books = loadedBooks;
    nextBookId = bookNextId;

    auto [loadedUsers, userNextId] = jsonStorage.loadUsers();
    users = loadedUsers;
    nextUserId = userNextId;

    transactions= jsonStorage.loadTransactions();
    std::cout << "All data loaded successfully.\n";
}

// Helper methods
std::vector<Book>::iterator Library::findBookById(int id) {
    return std::find_if(books.begin(), books.end(), 
        [id](const Book& book) { return book.getId() == id; });
}

std::vector<User>::iterator Library::findUserById(int id) {
    return std::find_if(users.begin(), users.end(), 
        [id](const User& user) { return user.getId() == id; });
}

std::vector<Book>::const_iterator Library::findBookById(int id) const {
    return std::find_if(books.begin(), books.end(), 
        [id](const Book& book) { return book.getId() == id; });
}

std::vector<User>::const_iterator Library::findUserById(int id) const {
    return std::find_if(users.begin(), users.end(), 
        [id](const User& user) { return user.getId() == id; });
}

void Library::addTransaction(int userId, int bookId, Transaction::Type type) {
    transactions.emplace_back(userId, bookId, type);
}