#include "Utility.h"
#include <iostream>

int main() {
    auto config = load_json("data/config.json");
    print_json(config);
    return 0;
}