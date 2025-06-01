#include "User.h"
#include <algorithm>
#include <iostream>

User::User(int id, std::string name, std::string email) : id(id), name(std::move(name)), email(std::move(email)) {}

nlohmann::json User::toJson() const
{
    return {
        {"id", id},
        {"name", name},
        {"email", email},
        {"borrowedBooks", borrowedBooks}};
}

User User::fromJson(const nlohmann::json &j)
{
    User user(
        j.at("id").get<int>(),
        j.at("name").get<std::string>(),
        j.at("email").get<std::string>());

    if (j.contains("borrowedBooks"))
    {
        user.borrowedBooks = j.at("borrowedBooks").get<std::vector<int>>();
    }
    return user;
}

int User::getId() const { return id; }
const std::string &User::getName() const { return name; }
const std::string &User::getEmail() const { return email; }
const std::vector<int> &User::getBorrowedBooks() const { return borrowedBooks; }

void User::borrowBook(int booKId)
{
    borrowedBooks.push_back(booKId);
}

bool User::returnBook(int bookId)
{
    auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), bookId);
    if (it != borrowedBooks.end())
    {
        borrowedBooks.erase(it);
        return true;
    }
    return false;
}

void User::display() const
{
    std::cout << "ID: " << id << "\n"
              << "Name: " << name << "\n"
              << "Email: " << email << "\n"
              << "Borrowed Books: ";
    for (int bookId : borrowedBooks)
    {
        std::cout << bookId << " ";
    }
    std::cout << "\n-------------------------\n";
}