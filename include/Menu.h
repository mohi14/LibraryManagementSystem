#pragma once
#include "Library.h"

class Menu
{
public:
    explicit Menu(Library &library);

    void run();

private:
    Library& library_;

    void displayMainMenu() const;
    void handleMainMenuChoice(int choice);

    void displayBookMenu() const;
    void handleBookMenuChoice(int choice);

    void displayUserMenu() const;
    void handleUserMenuChoice(int choice);

    void displayBorrowMenu() const;
    void handleBorrowMenuChoice(int choice);

    void displayDataMenu() const;
    void handleDataMenuChoice(int choice);

    void clearInputBuffer() const;
    int getIntInput(const std::string& prompt) const;
    std::string getStringInput(const std::string& prompt) const;
};

