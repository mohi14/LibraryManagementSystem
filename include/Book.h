#pragma once
#include <string>

using namespace std;

class Book
{
public:
    int id;
    string title;
    string author;
    bool isAvailable;

    Book(int id, string title, string author);

    void display() const;
};