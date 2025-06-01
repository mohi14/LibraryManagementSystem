#pragma once
#include <string>
#include <ctime>
#include <nlohmann/json.hpp>

class Transaction
{
public:
    enum class Type
    {
        BORROW,
        RETURN
    };

    Transaction() = default;
    Transaction(int userId, int bookId, Type type);

    // Serialization
    nlohmann::json toJson() const;
    static Transaction fromJson(const nlohmann::json &j);

    // Display
    void display() const;

private:
    int userId;
    int bookId;
    Type type;
    std::time_t timestamp;
};