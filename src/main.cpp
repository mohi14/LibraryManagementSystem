#include <iostream>
#include "Menu.h"

int main()
{
    Library library;
    Menu menu(library);
    menu.run();
    return 0;
}