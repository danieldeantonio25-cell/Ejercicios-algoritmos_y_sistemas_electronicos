cmake_minimum_required(VERSION 3.14)
project(Corte2_Entrega2 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Flags de compilación
add_compile_options(-Wall -Wextra -O2)

# -----------------------------------------------
# 1. LeetCode 1797 - Design Authentication Manager
# -----------------------------------------------
add_executable(auth_manager
    leetcode/1797_auth_manager.cpp
)

# -----------------------------------------------
# 2. LeetCode 3709 - Design Exam Scores Tracker
# -----------------------------------------------
add_executable(exam_scores
    leetcode/3709_exam_scores.cpp
)

# -----------------------------------------------
# 3. Exercism - Crypto Square
# -----------------------------------------------
add_executable(crypto_square
    exercism/crypto_square/crypto_square.cpp
)
target_include_directories(crypto_square PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/exercism/crypto_square
)

# -----------------------------------------------
# 4. Exercism - Bank Account (requiere threads)
# -----------------------------------------------
find_package(Threads REQUIRED)

add_executable(bank_account
    exercism/bank_account/bank_account.cpp
)
target_include_directories(bank_account PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/exercism/bank_account
)
target_link_libraries(bank_account PRIVATE Threads::Threads)

# -----------------------------------------------
# Mensaje de ayuda al configurar
# -----------------------------------------------
message(STATUS "Targets disponibles:")
message(STATUS "  auth_manager  -> LeetCode 1797")
message(STATUS "  exam_scores   -> LeetCode 3709")
message(STATUS "  crypto_square -> Exercism Crypto Square")
message(STATUS "  bank_account  -> Exercism Bank Account")
message(STATUS "")
message(STATUS "Compilar todo: cmake --build .")
