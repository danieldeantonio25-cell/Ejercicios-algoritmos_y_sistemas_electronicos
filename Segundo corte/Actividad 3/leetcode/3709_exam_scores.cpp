/*
 * LeetCode 3709 - Design Exam Scores Tracker
 *
 * Descripción:
 * Implementar un rastreador de puntajes de examen que soporte:
 *   - addScore(studentId, score): agrega el puntaje de un estudiante.
 *   - getTopStudents(k): retorna los IDs de los k mejores estudiantes
 *     (mayor puntaje total). En caso de empate, se ordena por studentId
 *     de menor a mayor.
 *   - resetStudent(studentId): elimina todos los puntajes del estudiante.
 *
 * Restricciones relevantes:
 *   - 1 <= studentId <= 10^5
 *   - 1 <= score <= 100
 *   - 1 <= k <= número de estudiantes con al menos un puntaje
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

class ExamScoresTracker {
private:
    // studentId -> puntaje total acumulado
    std::unordered_map<int, long long> scores;

public:
    ExamScoresTracker() {}

    void addScore(int studentId, int score) {
        scores[studentId] += score;
    }

    std::vector<int> getTopStudents(int k) {
        // Recopilar todos los estudiantes con sus puntajes
        std::vector<std::pair<long long, int>> ranking; // (puntaje, studentId)
        for (auto& [id, total] : scores) {
            ranking.push_back({total, id});
        }

        // Ordenar: mayor puntaje primero; en empate, menor id primero
        std::sort(ranking.begin(), ranking.end(),
            [](const std::pair<long long, int>& a, const std::pair<long long, int>& b) {
                if (a.first != b.first) return a.first > b.first; // mayor puntaje
                return a.second < b.second;                        // menor id
            });

        std::vector<int> result;
        for (int i = 0; i < k && i < (int)ranking.size(); i++) {
            result.push_back(ranking[i].second);
        }
        return result;
    }

    void resetStudent(int studentId) {
        scores.erase(studentId);
    }
};

// Utilitario para imprimir vectores
void printVector(const std::vector<int>& v) {
    std::cout << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        std::cout << v[i];
        if (i + 1 < (int)v.size()) std::cout << ", ";
    }
    std::cout << "]\n";
}

int main() {
    std::cout << "=== LeetCode 3709: Design Exam Scores Tracker ===\n\n";

    ExamScoresTracker tracker;

    // Ejemplo básico
    tracker.addScore(1, 85);
    tracker.addScore(2, 92);
    tracker.addScore(3, 78);
    tracker.addScore(1, 90); // estudiante 1 suma: 85+90=175
    tracker.addScore(2, 60); // estudiante 2 suma: 92+60=152
    tracker.addScore(3, 95); // estudiante 3 suma: 78+95=173

    std::cout << "Puntajes acumulados:\n";
    std::cout << "  Estudiante 1: 175\n";
    std::cout << "  Estudiante 2: 152\n";
    std::cout << "  Estudiante 3: 173\n\n";

    std::cout << "getTopStudents(1) -> ";
    printVector(tracker.getTopStudents(1)); // [1]

    std::cout << "getTopStudents(2) -> ";
    printVector(tracker.getTopStudents(2)); // [1, 3]

    std::cout << "getTopStudents(3) -> ";
    printVector(tracker.getTopStudents(3)); // [1, 3, 2]

    // Prueba de resetStudent
    std::cout << "\nreset Estudiante 1...\n";
    tracker.resetStudent(1);

    std::cout << "getTopStudents(2) -> ";
    printVector(tracker.getTopStudents(2)); // [3, 2]

    // Prueba con empate en puntaje
    std::cout << "\n--- Prueba de empate (mismo puntaje -> menor ID primero) ---\n";
    ExamScoresTracker tracker2;
    tracker2.addScore(5, 100);
    tracker2.addScore(3, 100);
    tracker2.addScore(7, 100);

    std::cout << "Estudiantes 3, 5 y 7 tienen 100 puntos cada uno\n";
    std::cout << "getTopStudents(3) -> ";
    printVector(tracker2.getTopStudents(3)); // [3, 5, 7]

    // Prueba con agregar al mismo estudiante varias veces
    std::cout << "\n--- Prueba acumulativa ---\n";
    ExamScoresTracker tracker3;
    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j < i; j++) {
            tracker3.addScore(i, 10);
        }
    }
    std::cout << "Puntajes: est1=10, est2=20, est3=30, est4=40, est5=50\n";
    std::cout << "getTopStudents(3) -> ";
    printVector(tracker3.getTopStudents(3)); // [5, 4, 3]

    return 0;
}
