#pragma once
#include <string>
#include <nlohmann/json.hpp>

class Book
{
private:
    int id = 0;
    std::string title;
    std::string author;
    std::string isbn;
    bool available = true;

public:
    Book() = default;
    Book(int id, std::string title, std::string author, std::string isbn, bool available = true);

    // Serialization
    nlohmann::json toJson() const;
    static Book fromJson(const nlohmann::json &j);

    // Getters
    int getId() const;
    const std::string& getTitle() const;
    const std::string& getAuthor() const;
    const std::string& getIsbn() const;
    bool isAvailable() const;

    // Setters
    void setAvailable(bool available);

    // Display
    void display() const;
};
