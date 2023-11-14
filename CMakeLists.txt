# How to use:
#   mkdir build
#   cd build
#   cmake ..
#   make
#   ./Flipper

cmake_minimum_required(VERSION 3.10)

project(Flipper)
 
set(SFML_PATH "/usr/include/")
#Les deux truc là c'est le chemin vers le répertoir ou vous avez installer sfml 
set(SFML_DIR "${SFML_PATH}SFML/cmake/Modules")
set(CMAKE_PREFIX_PATH "${SFML_PATH}/usr/include/SFML")

find_package(SFML 2.5 COMPONENTS graphics window audio system REQUIRED)


add_executable(Flipper
    #Tout nos executable
    Flipper.cc
    Vector2D.cc
    #TestFlipper.cc
    #googletest/googletest/src/gtest-all.cc
)

#Pour les tests qu'on devra faire
target_include_directories(Flipper
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest"
)

# Lier l'exécutable avec les bibliothèques SFML
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-audio sfml-system)

target_compile_options(Flipper
  PRIVATE
    "-Wall" "-Wextra" "-pedantic" "-g" "-O2"
)

# Copiez les fichiers de ressources dans le répertoire de build 
file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})


set_target_properties(Flipper
  PROPERTIES
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
)

