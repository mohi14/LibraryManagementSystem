#pragma once

#include "User.h"

using namespace std;

class Admin : public User
{
public:
    Admin(int id, string name);
    void addBook();
    void removeBook();
    void viewAllUsers();
};