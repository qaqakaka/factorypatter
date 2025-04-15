# cmake_minimum_required(VERSION 3.10)

# # Set the project name
# project(GoogleTestExample)

# # Set C++ Standard
# set(CMAKE_CXX_STANDARD 14)

# # Find GoogleTest
# find_package(GTest REQUIRED)

# # Include GoogleTest headers
# include_directories(${GTEST_INCLUDE_DIRS})
# #include_directories(/opt/homebrew/include)  # Add this line

# # Add your test source file
# add_executable(test_example test_example.cpp)

# # Link with GoogleTest and pthread
# target_link_libraries(test_example ${GTEST_LIBRARIES} pthread) 


cmake_minimum_required(VERSION 3.10)
project(FactoryPatternExample)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 14)

# Find GoogleTest
find_package(GTest REQUIRED)

# Include GoogleTest headers
include_directories(${GTEST_INCLUDE_DIRS})

# Add the source files for the project
add_executable(test_example test_example.cpp)

# Link GoogleTest and pthread
target_link_libraries(test_example ${GTEST_LIBRARIES} pthread)
