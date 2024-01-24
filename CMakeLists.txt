cmake_minimum_required(VERSION 3.10)

project(Flipper)

set(SFML_PATH "/usr/include/")
set(SFML_DIR "${SFML_PATH}SFML/cmake/Modules")
set(CMAKE_PREFIX_PATH "${SFML_PATH}/usr/include/SFML")

find_package(SFML 2.5 COMPONENTS graphics window audio system REQUIRED)

# Add the googletest library
add_subdirectory(googletest)

add_executable(Flipper
    main.cc
    Vector2D.cc
    Ball.cc
    Circle.cc
    Polygone.cc
    Rectangle.cc
    Shape.cc
    Collision.cc
    Wall.cc
    Input.cc
    Flipper.cc
    Launcher.cc
)

target_include_directories(Flipper
    PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest"
)

# Link the executable with SFML libraries
target_link_libraries(Flipper sfml-graphics sfml-window sfml-audio sfml-system)

target_compile_options(Flipper
    PRIVATE
    "-Wall" "-Wextra" "-pedantic" "-g" "-O2"
)

file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})

set_target_properties(Flipper
    PROPERTIES
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
)

# Add test executable and link with gtest
add_executable(TestFlipper
    TestFlipper.cc
    Vector2D.cc 
    Circle.cc 
    Shape.cc
    Rectangle.cc 
    Polygone.cc 
    Collision.cc
    # Add other test files as needed
)

target_include_directories(TestFlipper
    PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest"
)

target_link_libraries(TestFlipper gtest gtest_main sfml-graphics sfml-window sfml-audio sfml-system)
