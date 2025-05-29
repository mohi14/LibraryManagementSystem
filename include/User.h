#pragma once

#include <string>
#include <vector>

using namespace std;

class User
{
public:
    int id;
    string name;
    vector<int> borrowedBooks;

    User(int id, string name);
    ~User();

    virtual void displayInfo() const;
};