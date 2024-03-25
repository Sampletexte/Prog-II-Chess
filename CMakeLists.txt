cmake_minimum_required(VERSION 3.21)
project(sfmlcmaketst)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "C:\\SFML-2.6.1")
set(SFML_STATIC_LIBRARIES TRUE)

list(APPEND CMAKE_PREFIX_PATH "${SFML_DIR}/lib/cmake/")

include_directories("${SFML_DIR}/include")
link_directories("${SFML_DIR}/lib")

find_package(SFML COMPONENTS system window graphics)

add_executable(${PROJECT_NAME} main.cpp Board/Board.cpp Board/Board.h ChessPiece/ChessPiece.h Util.h)

target_link_libraries(${PROJECT_NAME} PUBLIC sfml-graphics sfml-window sfml-system)
