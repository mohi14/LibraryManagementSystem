#include "Book.h"
#include <iostream>

Book::Book(int id, std::string title, std::string author, std::string isbn, bool available) : id(id), title(std::move(title)), author(std::move(author)), isbn(std::move(isbn)), available(available) {}

nlohmann::json Book::toJson() const
{
    return {
        {"id", id},
        {"title", title},
        {"author", author},
        {"isbn",isbn},
        {"available", available}};
}

Book Book::fromJson(const nlohmann::json &j)
{
    return Book(
        j.at("id").get<int>(),
        j.at("title").get<std::string>(),
        j.at("author").get<std::string>(),
        j.at("isbn").get<std::string>(),
        j.at("available").get<bool>());
}

int Book::getId() const { return id; }
const std::string &Book::getTitle() const { return title; }
const std::string &Book::getAuthor() const { return author; }
const std::string &Book::getIsbn() const { return isbn; }
bool Book::isAvailable() const { return available; }
void Book::setAvailable(bool availablity) { available = availablity; }

void Book::display() const {
    std::cout<< "ID: "<< id << "\n" 
    << "Title: "<< title << "\n" 
    << "Author: " << author << "\n" 
    << "ISBN: " << isbn << "\n" 
    << "Status: " << (available ? "Available" : "Borrowed")<< "\n" 
    << "------------------------\n";
}