cmake_minimum_required(VERSION 3.10)
project(LibraryManagementSystem)

set(CMAKE_CXX_STANDARD 20)

# Find nlohmann_json package
find_package(nlohmann_json 3.2.0 REQUIRED)

# Include directories
include_directories(include)

# Source files
file(GLOB SOURCES "src/*.cpp")

# Create data directory if it doesn't exist
# file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/data)

# Main executable
add_executable(LibraryManagementSystem ${SOURCES})

# Link nlohmann_json to your target
target_link_libraries(LibraryManagementSystem PRIVATE
    nlohmann_json::nlohmann_json
)

# Copy data files to build directory
configure_file(data/books.json ${CMAKE_CURRENT_BINARY_DIR}/data/books.json COPYONLY)
configure_file(data/users.json ${CMAKE_CURRENT_BINARY_DIR}/data/users.json COPYONLY)
configure_file(data/transactions.json ${CMAKE_CURRENT_BINARY_DIR}/data/transactions.json COPYONLY)
# configure_file(data/auth.json ${CMAKE_CURRENT_BINARY_DIR}/data/auth.json COPYONLY)
