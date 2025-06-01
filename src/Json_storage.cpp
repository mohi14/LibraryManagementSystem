#include "Json_storage.h"
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

JsonStorage::JsonStorage(const std::string& dataDir) : dataDir(dataDir) {
    ensureDataDirectoryExists();
}

void JsonStorage::ensureDataDirectoryExists() const {
    if (!fs::exists(dataDir)) {
        fs::create_directory(dataDir);
    }
}

nlohmann::json JsonStorage::readJsonFile(const std::string& filename) const {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return nlohmann::json();
    }
    
    nlohmann::json data;
    try {
        file >> data;
    } catch (const nlohmann::json::exception& e) {
        std::cerr << "Error reading JSON file: " << e.what() << "\n";
        return nlohmann::json();
    }
    
    return data;
}

void JsonStorage::writeJsonFile(const std::string& filename, const nlohmann::json& data) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << data.dump(4); // Pretty print with 4 spaces
    } else {
        std::cerr << "Unable to write to file: " << filename << "\n";
    }
}

void JsonStorage::saveBooks(const std::vector<Book>& books, int nextId) {
    nlohmann::json data;
    data["books"] = nlohmann::json::array();
    for (const auto& book : books) {
        data["books"].push_back(book.toJson());
    }
    data["nextId"] = nextId;
    
    writeJsonFile(dataDir + "/books.json", data);
}

std::pair<std::vector<Book>, int> JsonStorage::loadBooks() {
    auto data = readJsonFile(dataDir + "/books.json");
    if (data.empty()) {
        return {{}, 1};
    }

    std::vector<Book> books;
    for (const auto& bookJson : data["books"]) {
        books.push_back(Book::fromJson(bookJson));
    }

    int nextId = data.value("nextId", 1);
    return {books, nextId};
}

void JsonStorage::saveUsers(const std::vector<User>& users, int nextId) {
    nlohmann::json data;
    data["users"] = nlohmann::json::array();
    for (const auto& user : users) {
        data["users"].push_back(user.toJson());
    }
    data["nextId"] = nextId;
    
    writeJsonFile(dataDir + "/users.json", data);
}

std::pair<std::vector<User>, int> JsonStorage::loadUsers() {
    auto data = readJsonFile(dataDir + "/users.json");
    if (data.empty()) {
        return {{}, 1};
    }

    std::vector<User> users;
    for (const auto& userJson : data["users"]) {
        users.push_back(User::fromJson(userJson));
    }

    int nextId = data.value("nextId", 1);
    return {users, nextId};
}

void JsonStorage::saveTransactions(const std::vector<Transaction>& transactions) {
    nlohmann::json data = nlohmann::json::array();
    for (const auto& transaction : transactions) {
        data.push_back(transaction.toJson());
    }
    
    writeJsonFile(dataDir + "/transactions.json", data);
}

std::vector<Transaction> JsonStorage::loadTransactions() {
    auto data = readJsonFile(dataDir + "/transactions.json");
    if (data.empty() || !data.is_array()) {
        return {};
    }

    std::vector<Transaction> transactions;
    for (const auto& transactionJson : data) {
        transactions.push_back(Transaction::fromJson(transactionJson));
    }

    return transactions;
}