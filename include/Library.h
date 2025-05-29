#pragma once

#include <iostream>
#include <vector>
#include <map>
#include "Book.h"
#include "User.h"
#include "Admin.h"

using namespace std;

class Library
{
private:
    vector<Book> books;
    map<int, User> users;

public:
void loadData(){
    cout<< "Data Loading...."<< endl;
};
void saveData();
void searchBook(const string& keyword);
void borrowBook(int userId, int bookId);
void returnBook(int userId, int bookId);
};