#include "Menu.h"
#include <iostream>
#include <limits>

using json = nlohmann::json;

Menu::Menu(Library &library) : library_(library) {}

void Menu::run()
{
    while (true)
    {
        displayMainMenu();
        int choice = getIntInput("Enter your choice: ");
        handleMainMenuChoice(choice);
    }
}

void Menu::displayMainMenu() const
{
    std::cout << "\nLibrary Management System\n"
              << "1. Book Operations\n"
              << "2. User Operations\n"
              << "3. Borrow/Return Operations\n"
              << "4. Save/Load Data\n"
              << "5. Exit\n";
}

void Menu::handleMainMenuChoice(int choice)
{
    switch (choice)
    {
    case 1:
    {
        displayBookMenu();
        int bookChoice = getIntInput("Enter your choice: ");
        break;
    }
    case 2:
    {
        displayUserMenu();
        int userChoice = getIntInput("Enger your Choice: ");
        handleUserMenuChoice(userChoice);
        break;
    }
    case 3:
    {
        displayBorrowMenu();
        int borrowChoice = getIntInput("Enter your choice: ");
        handleBorrowMenuChoice(borrowChoice);
        break;
    }
    case 4:
    {
        displayDataMenu();
        int dataChoice = getIntInput("Enter your choice: ");
        handleDataMenuChoice(dataChoice);
        break;
    }
    case 5:
    {
        std::cout << "Exiting...\n";
        exit(0);
    }

    default:
        std::cout << "Invalid choice. Please try again.\n";
    }
}

void Menu::displayBookMenu() const {
    std::cout << "\nBook Operations\n"
              << "1. Add Book\n"
              << "2. Display All Books\n"
              << "3. Search Books\n"
              << "4. Back to Main Menu\n";
}

void Menu::handleBookMenuChoice(int choice) {
    switch (choice) {
        case 1: {
            std::string title = getStringInput("Enter book title: ");
            std::string author = getStringInput("Enter book author: ");
            std::string isbn = getStringInput("Enter book ISBN: ");
            library_.addBook(title, author, isbn);
            break;
        }
        case 2:
            library_.displayAllBooks();
            break;
        case 3: {
            std::string keyword = getStringInput("Enter search keyword: ");
            library_.searchBooks(keyword);
            break;
        }
        case 4:
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
    }
}

void Menu::displayUserMenu() const {
    std::cout << "\nUser Operations\n"
              << "1. Add User\n"
              << "2. Display All Users\n"
              << "3. Back to Main Menu\n";
}

void Menu::handleUserMenuChoice(int choice) {
    switch (choice) {
        case 1: {
            std::string name = getStringInput("Enter user name: ");
            std::string email = getStringInput("Enter user email: ");
            library_.addUser(name, email);
            break;
        }
        case 2:
            library_.displayAllUsers();
            break;
        case 3:
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
    }
}

void Menu::displayBorrowMenu() const {
    std::cout << "\nBorrow/Return Operations\n"
              << "1. Borrow Book\n"
              << "2. Return Book\n"
              << "3. Back to Main Menu\n";
}

void Menu::handleBorrowMenuChoice(int choice) {
    switch (choice) {
        case 1: {
            int userId = getIntInput("Enter user ID: ");
            int bookId = getIntInput("Enter book ID: ");
            library_.borrowBook(userId, bookId);
            break;
        }
        case 2: {
            int userId = getIntInput("Enter user ID: ");
            int bookId = getIntInput("Enter book ID: ");
            library_.returnBook(userId, bookId);
            break;
        }
        case 3:
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
    }
}

void Menu::displayDataMenu() const {
    std::cout << "\nData Operations\n"
              << "1. Save Data\n"
              << "2. Load Data\n"
              << "3. Back to Main Menu\n";
}
void Menu::handleDataMenuChoice(int choice) {
    switch (choice) {
        case 1: {
            std::string filename = getStringInput("Enter filename to save: ");
            library_.saveData();
            break;
        }
        case 2: {
            std::string filename = getStringInput("Enter filename to load: ");
            library_.loadData();
            break;
        }
        case 3:
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
    }
}

void Menu::clearInputBuffer() const {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int Menu::getIntInput(const std::string& prompt) const {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
        } else {
            clearInputBuffer();
            return value;
        }
    }
}
std::string Menu::getStringInput(const std::string& prompt) const {
    std::string value;
    std::cout << prompt;
    std::getline(std::cin, value);
    return value;
}

