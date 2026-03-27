cmake_minimum_required(VERSION 3.10)
project(MedidorEnergia VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include_directories(include)

set(SOURCES
    src/MedidorEnergia.cpp
    src/main.cpp
)

add_executable(MedidorEnergia ${SOURCES})

# ── Doxygen (opcional) ────────────────────────────────────────────────────────
find_package(Doxygen OPTIONAL_COMPONENTS dot)

if(DOXYGEN_FOUND)
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/docs)
    set(DOXYGEN_PROJECT_NAME "Medidor de Energia")
    set(DOXYGEN_PROJECT_BRIEF "Sistema de gestion de medidores de energia electrica")
    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_GENERATE_LATEX NO)
    set(DOXYGEN_EXTRACT_ALL YES)
    set(DOXYGEN_HAVE_DOT NO)
    doxygen_add_docs(docs
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src
        COMMENT "Generando documentacion con Doxygen..."
    )
    message(STATUS "Doxygen encontrado. Usa: cmake --build . --target docs")
else()
    message(STATUS "Doxygen no encontrado. Ejecuta: doxygen Doxyfile")
endif()
