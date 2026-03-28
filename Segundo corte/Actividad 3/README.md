# Corte 2 - Entrega 2: Estructuras de Datos y Diseño en C++

## Integrantes
- [Tu nombre aquí]

---

## Descripción general

Este repositorio contiene las soluciones a cuatro ejercicios de programación en C++:

| # | Fuente | Problema |
|---|--------|----------|
| 1 | LeetCode 1797 | Design Authentication Manager |
| 2 | LeetCode 3709 | Design Exam Scores Tracker |
| 3 | Exercism | Crypto Square |
| 4 | Exercism | Bank Account (thread-safe) |

---

## Estructura de archivos

```
.
├── CMakeLists.txt          # Compilación unificada de todos los programas
├── 1797_auth_manager.cpp   # LeetCode 1797
├── 3709_exam_scores.cpp    # LeetCode 3709
├── crypto_square.h         # Exercism Crypto Square (header)
├── crypto_square.cpp       # Exercism Crypto Square (implementación + main)
├── bank_account.h          # Exercism Bank Account (header)
├── bank_account.cpp        # Exercism Bank Account (implementación + main)
└── README.md
```

---

## Requisitos

- CMake >= 3.14
- Compilador C++17 (g++ 9+, clang++ 9+, MSVC 2019+)
- Biblioteca de hilos del sistema (pthreads en Linux/macOS)

---

## Compilación

```bash
# Desde la raíz del proyecto
mkdir build && cd build
cmake ..
cmake --build .
```

Los ejecutables generados serán:
- `auth_manager`
- `exam_scores`
- `crypto_square`
- `bank_account`

---

## Ejecución

```bash
# Dentro del directorio build/
./auth_manager
./exam_scores
./crypto_square
./bank_account
```

---

## Descripción de los problemas

### 1. LeetCode 1797 – Design Authentication Manager

**Estructura usada:** `std::unordered_map<string, int>` (tokenId → tiempo de expiración).

Implementa tres operaciones:
- `generate(tokenId, currentTime)`: crea un token que expira en `currentTime + TTL`.
- `renew(tokenId, currentTime)`: renueva el token si aún no ha expirado.
- `countUnexpiredTokens(currentTime)`: cuenta tokens con `expTime > currentTime`.

**Complejidad:** O(n) por `countUnexpiredTokens`, O(1) para generate y renew.

---

### 2. LeetCode 3709 – Design Exam Scores Tracker

**Estructura usada:** `std::unordered_map<int, long long>` (studentId → puntaje acumulado).

Implementa:
- `addScore(studentId, score)`: acumula puntaje.
- `getTopStudents(k)`: retorna los k mejores (mayor puntaje, menor ID en empate).
- `resetStudent(studentId)`: elimina al estudiante del sistema.

**Complejidad:** O(n log n) para `getTopStudents`, O(1) para add/reset.

---

### 3. Exercism – Crypto Square

Implementa el cifrado por cuadrado:
1. **Normalización**: se eliminan espacios y puntuación, se convierte a minúsculas.
2. **Dimensiones**: se calcula el rectángulo más cuadrado posible (c ≥ r, c−r ≤ 1).
3. **Cifrado**: se leen las columnas de arriba a abajo para obtener el mensaje cifrado.
4. **Salida**: chunks de longitud `r` separados por espacios, con relleno de espacios al final si es necesario.

**Librería usada:** `<cmath>` para `ceil` y `sqrt`.

---

### 4. Exercism – Bank Account

Implementa una cuenta bancaria **thread-safe** usando `std::mutex`.

- `open()` / `close()`: abre/cierra la cuenta.
- `balance()`, `deposit(amount)`, `withdraw(amount)`: operaciones sobre el saldo.
- Todas las operaciones sobre una cuenta cerrada lanzan `account_not_open`.
- Se usa `std::lock_guard` (RAII) para garantizar la liberación del mutex incluso ante excepciones.

**Librería usada:** `<mutex>`, `<thread>` (C++17).

---

## Recursos externos utilizados

- Documentación de C++ (cppreference.com)
- Enunciados de LeetCode: [1797](https://leetcode.com/problems/design-authentication-manager/), [3709](https://leetcode.com/problems/design-exam-scores-tracker/)
- Enunciados de Exercism: [Crypto Square](https://exercism.org/tracks/cpp/exercises/crypto-square), [Bank Account](https://exercism.org/tracks/cpp/exercises/bank-account)
