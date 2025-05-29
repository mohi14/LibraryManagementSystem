#include "User.h"
#include <iostream>

using namespace std;

User:: User(int id, string name): id(id), name(name){}
User:: ~User(){}

void User::displayInfo() const{
cout << "Displaying..."<< endl;
}