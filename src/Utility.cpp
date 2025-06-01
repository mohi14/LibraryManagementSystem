#include "Utility.h"
#include <fstream>
#include <iostream>

nlohmann::json load_json(const std::string& filename) {
    std::ifstream file(filename);
    return nlohmann::json::parse(file);
}

void print_json(const nlohmann::json& j) {
    std::cout << j.dump(2) << std::endl;
}