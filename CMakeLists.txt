cmake_minimum_required(VERSION 3.21)
project(Prog_II_Chess)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "C:\\SFML-2.6.1")
set(SFML_STATIC_LIBRARIES TRUE)

list(APPEND CMAKE_PREFIX_PATH "${SFML_DIR}/lib/cmake/")

include_directories("${SFML_DIR}/include")
link_directories("${SFML_DIR}/lib")

find_package(SFML COMPONENTS system window graphics)

add_executable(${PROJECT_NAME}
        main.cpp
        Board/Board.h Board/Board.cpp
        ChessPiece/ChessPiece.h
        ChessPiece/Pawn/Pawn.cpp ChessPiece/Pawn/Pawn.h
        ChessPiece/King/King.cpp ChessPiece/King/King.h
        ChessPiece/Queen/Queen.cpp ChessPiece/Queen/Queen.h
        ChessPiece/Bishop/Bishop.cpp ChessPiece/Bishop/Bishop.h
        ChessPiece/Knight/Knight.cpp ChessPiece/Knight/Knight.h
        ChessPiece/Rook/Rook.cpp ChessPiece/Rook/Rook.h
        )

target_link_libraries(${PROJECT_NAME} PUBLIC sfml-graphics sfml-window sfml-system)
