#pragma once
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

class User
{
private:
    int id = 0;
    std::string name;
    std::string email;
    std::vector<int> borrowedBooks;

public:
    User() = default;
    User(int id, std::string name, std::string email);

    // Serialization
    nlohmann::json toJson() const;
    static User fromJson(const nlohmann::json &j);

    // Getters
    int getId() const;
    const std::string& getName() const;
    const std::string& getEmail() const;
    const std::vector<int>& getBorrowedBooks() const;

    // Book operations
    void borrowBook(int bookId);
    bool returnBook(int bookId);

    // Display
    void display() const;
};
