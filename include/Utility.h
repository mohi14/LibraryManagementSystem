#pragma once
#include <nlohmann/json.hpp>

using namespace std;

nlohmann::json load_json(const string& filename);
void print_json(const nlohmann::json& j);