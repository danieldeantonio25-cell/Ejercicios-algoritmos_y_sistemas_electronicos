#pragma once
#include <mutex>
#include <stdexcept>
#include <optional>

namespace banking {

// Excepción lanzada cuando se opera sobre una cuenta cerrada
class account_not_open : public std::runtime_error {
public:
    account_not_open() : std::runtime_error("account not open") {}
};

class BankAccount {
public:
    BankAccount();

    // Abre la cuenta con saldo 0. Lanza account_not_open si ya está abierta.
    void open();

    // Cierra la cuenta. Lanza account_not_open si ya está cerrada.
    void close();

    // Retorna el saldo actual. Lanza account_not_open si la cuenta está cerrada.
    int balance() const;

    // Deposita amount. Lanza account_not_open si cerrada, o
    // std::invalid_argument si amount <= 0.
    void deposit(int amount);

    // Retira amount. Lanza account_not_open si cerrada,
    // std::invalid_argument si amount <= 0, o
    // std::runtime_error si fondos insuficientes.
    void withdraw(int amount);

private:
    mutable std::mutex mutex_;
    bool is_open_;
    int balance_;
};

} // namespace banking
