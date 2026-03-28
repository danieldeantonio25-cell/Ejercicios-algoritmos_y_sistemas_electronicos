/*
 * LeetCode 1797 - Design Authentication Manager
 *
 * Descripción:
 * Hay un sistema de autenticación donde el usuario recibe tokens de autenticación.
 * Cada token tiene un tiempo de vida (timeToLive) en segundos.
 * El sistema soporta:
 *   - generate(tokenId, currentTime): genera un token con tiempo de expiración
 *     currentTime + timeToLive.
 *   - renew(tokenId, currentTime): renueva un token no expirado al momento
 *     currentTime, extendiendo su expiración a currentTime + timeToLive.
 *   - countUnexpiredTokens(currentTime): retorna el número de tokens no expirados
 *     en el momento currentTime.
 *
 * Un token está expirado si su tiempo de expiración <= currentTime.
 */

#include <iostream>
#include <unordered_map>
#include <string>

class AuthenticationManager {
private:
    int ttl;
    // tokenId -> tiempo de expiración
    std::unordered_map<std::string, int> tokens;

public:
    AuthenticationManager(int timeToLive) : ttl(timeToLive) {}

    void generate(std::string tokenId, int currentTime) {
        tokens[tokenId] = currentTime + ttl;
    }

    void renew(std::string tokenId, int currentTime) {
        auto it = tokens.find(tokenId);
        if (it != tokens.end() && it->second > currentTime) {
            it->second = currentTime + ttl;
        }
        // Si no existe o ya expiró, no se hace nada
    }

    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (auto& [id, expTime] : tokens) {
            if (expTime > currentTime) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    std::cout << "=== LeetCode 1797: Design Authentication Manager ===\n\n";

    // Ejemplo del enunciado
    // timeToLive = 5
    AuthenticationManager authManager(5);

    authManager.generate("aaa", 1);
    std::cout << "generate(\"aaa\", 1)  -> token expira en t=6\n";

    std::cout << "renew(\"aaa\", 2)     -> ";
    authManager.renew("aaa", 2);
    std::cout << "token aaa renovado, expira en t=7\n";

    std::cout << "countUnexpiredTokens(6) -> "
              << authManager.countUnexpiredTokens(6) << "\n"; // Esperado: 1

    authManager.generate("bbb", 7);
    std::cout << "generate(\"bbb\", 7)  -> token expira en t=12\n";

    std::cout << "renew(\"aaa\", 8)     -> ";
    authManager.renew("aaa", 8); // aaa expiró en t=7, no hace nada
    std::cout << "token aaa ya expiró, sin efecto\n";

    std::cout << "renew(\"bbb\", 10)    -> ";
    authManager.renew("bbb", 10); // bbb expira en t=12 > 10, se renueva a t=15
    std::cout << "token bbb renovado, expira en t=15\n";

    std::cout << "countUnexpiredTokens(15) -> "
              << authManager.countUnexpiredTokens(15) << "\n"; // Esperado: 0

    std::cout << "\n--- Prueba adicional ---\n";
    AuthenticationManager am2(10);
    am2.generate("tok1", 0);
    am2.generate("tok2", 3);
    am2.generate("tok3", 7);
    std::cout << "Tokens creados: tok1(exp=10), tok2(exp=13), tok3(exp=17)\n";
    std::cout << "countUnexpiredTokens(9)  -> " << am2.countUnexpiredTokens(9) << "\n";  // 3
    std::cout << "countUnexpiredTokens(11) -> " << am2.countUnexpiredTokens(11) << "\n"; // 2
    std::cout << "countUnexpiredTokens(14) -> " << am2.countUnexpiredTokens(14) << "\n"; // 1
    std::cout << "countUnexpiredTokens(18) -> " << am2.countUnexpiredTokens(18) << "\n"; // 0

    return 0;
}
