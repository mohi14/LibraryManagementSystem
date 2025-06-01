#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Book.h"
#include "User.h"
#include "Transaction.h"
#include "Json_storage.h"

class Library
{
private:
    std::vector<Book> books;
    std::vector<User> users;
    std::vector<Transaction> transactions;
    int nextBookId = 1;
    int nextUserId = 1;

    JsonStorage jsonStorage;

    // Helper methods
    std::vector<Book>::iterator findBookById(int id);
    std::vector<User>::iterator findUserById(int id);
    std::vector<Book>::const_iterator findBookById(int id) const;
    std::vector<User>::const_iterator findUserById(int id) const;

    void addTransaction(int userid, int bookId, Transaction::Type type);

public:
    Library() = default;

    // Book operations
    void addBook(std::string title, std::string author, std::string isbn);
    void displayAllBooks() const;
    void searchBooks(const std::string& keyword) const;

    // User operations
    void addUser(std::string name, std::string email);
    void displayAllUsers() const;

    // Borrow/return operations
    void borrowBook(int userId, int bookId);
    void returnBook(int userId, int bookid);
    void displayAllTransactions() const;

    // Data persistence
    void saveData();
    void loadData();

    
};
