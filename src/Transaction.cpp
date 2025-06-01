#include "Transaction.h"
#include <iomanip>
#include <iostream>

Transaction::Transaction(int userId, int booId, Type type): userId(userId), bookId(bookId), type(type), timestamp(std::time(nullptr)){}

nlohmann::json Transaction::toJson() const{
    return{
        {"userId", userId},
        {"bookId", bookId},
        {"type", type == Type::BORROW ? "BORROW" : "RETURN"},
        {timestamp, timestamp}
    };
}

Transaction Transaction::fromJson(const nlohmann::json& j) {
    Transaction transaction(
        j.at("userId").get<int>(),
        j.at("bookId").get<int>(),
        j.at("type").get<std::string>() == "BORROW" ? Type::BORROW : Type::RETURN
    );
    return transaction;
}

void Transaction::display() const {
    std::cout << "User ID: " << userId << "\n"
              << "Book ID: " << bookId << "\n"
              << "Type: " << (type == Type::BORROW ? "Borrow" : "Return") << "\n"
              << "Date: " << std::put_time(std::localtime(&timestamp), "%Y-%m-%d %H:%M:%S") << "\n"
              << "-------------------------\n";
}
