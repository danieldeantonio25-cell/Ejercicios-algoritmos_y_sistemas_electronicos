/*
 * Exercism - Bank Account (C++)
 *
 * Implementa una cuenta bancaria thread-safe usando std::mutex.
 * Soporta: open, close, balance, deposit, withdraw.
 * Las operaciones sobre una cuenta cerrada lanzan account_not_open.
 * Se utiliza RAII (std::lock_guard) para garantizar que el mutex
 * siempre sea liberado, incluso ante excepciones.
 */

#include "bank_account.h"
#include <iostream>
#include <thread>
#include <vector>
#include <stdexcept>

namespace banking {

BankAccount::BankAccount() : is_open_(false), balance_(0) {}

void BankAccount::open() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (is_open_) throw account_not_open();
    is_open_ = true;
    balance_ = 0;
}

void BankAccount::close() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (!is_open_) throw account_not_open();
    is_open_ = false;
}

int BankAccount::balance() const {
    std::lock_guard<std::mutex> lock(mutex_);
    if (!is_open_) throw account_not_open();
    return balance_;
}

void BankAccount::deposit(int amount) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (!is_open_) throw account_not_open();
    if (amount <= 0) throw std::invalid_argument("deposit amount must be positive");
    balance_ += amount;
}

void BankAccount::withdraw(int amount) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (!is_open_) throw account_not_open();
    if (amount <= 0) throw std::invalid_argument("withdraw amount must be positive");
    if (amount > balance_) throw std::runtime_error("insufficient funds");
    balance_ -= amount;
}

} // namespace banking

// ---- Función main de demostración ----
int main() {
    using namespace banking;

    std::cout << "=== Exercism: Bank Account ===\n\n";

    // --- Pruebas básicas ---
    BankAccount account;
    account.open();
    std::cout << "Cuenta abierta. Saldo inicial: " << account.balance() << "\n";

    account.deposit(500);
    std::cout << "Depósito de 500. Saldo: " << account.balance() << "\n";

    account.withdraw(200);
    std::cout << "Retiro de 200. Saldo: " << account.balance() << "\n";

    account.deposit(100);
    account.deposit(50);
    std::cout << "Depósitos de 100 y 50. Saldo: " << account.balance() << "\n";

    account.withdraw(300);
    std::cout << "Retiro de 300. Saldo: " << account.balance() << "\n";

    // --- Prueba de error: cuenta cerrada ---
    account.close();
    std::cout << "\nCuenta cerrada.\n";
    try {
        account.balance();
    } catch (const account_not_open& e) {
        std::cout << "balance() sobre cuenta cerrada -> excepción: " << e.what() << "\n";
    }
    try {
        account.deposit(100);
    } catch (const account_not_open& e) {
        std::cout << "deposit() sobre cuenta cerrada -> excepción: " << e.what() << "\n";
    }

    // --- Prueba concurrente: múltiples hilos depositan y retiran ---
    std::cout << "\n--- Prueba concurrente (10 hilos x 100 depósitos de 1) ---\n";
    BankAccount concAccount;
    concAccount.open();

    const int NUM_THREADS = 10;
    const int OPS_PER_THREAD = 100;

    std::vector<std::thread> threads;
    for (int t = 0; t < NUM_THREADS; t++) {
        threads.emplace_back([&concAccount]() {
            for (int i = 0; i < OPS_PER_THREAD; i++) {
                concAccount.deposit(1);
            }
        });
    }
    for (auto& th : threads) th.join();

    int expected = NUM_THREADS * OPS_PER_THREAD;
    int actual = concAccount.balance();
    std::cout << "Saldo esperado: " << expected << "\n";
    std::cout << "Saldo obtenido: " << actual << "\n";
    std::cout << "Prueba concurrente: " << (actual == expected ? "PASÓ" : "FALLÓ") << "\n";

    concAccount.close();

    return 0;
}
