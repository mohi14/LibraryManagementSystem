#pragma once
#include <vector>
#include <string>
#include <nlohmann/json.hpp>
#include "Book.h"
#include "User.h"
#include "Transaction.h"

class JsonStorage
{
private:
    std::string dataDir;

    void ensureDataDirectoryExists() const;

    // Serialization
    nlohmann::json readJsonFile(const std::string &filename) const;
    void writeJsonFile(const std::string &filename, const nlohmann::json &data) const;

public:
    JsonStorage(const std::string &dataDir = "data");

    // Book operations
    void saveBooks(const std::vector<Book> &books, int nextId);
    std::pair<std::vector<Book>, int> loadBooks();

    // User operations
    void saveUsers(const std::vector<User> &users, int nextId);
    std::pair<std::vector<User>, int> loadUsers();

    // Transaction operations
    void saveTransactions(const std::vector<Transaction> &transactions);
    std::vector<Transaction> loadTransactions();
};