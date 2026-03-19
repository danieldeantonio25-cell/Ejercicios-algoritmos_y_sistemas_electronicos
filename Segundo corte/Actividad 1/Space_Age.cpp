#include <iostream>
#include <iomanip>
#include <cmath>

class SpaceAge {
private:
    long long seconds;
    const double earthYearSeconds = 31557600.0;

public:
    SpaceAge(long long s) : seconds(s) {}

    double onEarth() { return seconds / earthYearSeconds; }
    double onMercury() { return seconds / (earthYearSeconds * 0.2408467); }
    double onVenus() { return seconds / (earthYearSeconds * 0.61519726); }
    double onMars() { return seconds / (earthYearSeconds * 1.8808158); }
    double onJupiter() { return seconds / (earthYearSeconds * 11.862615); }
    double onSaturn() { return seconds / (earthYearSeconds * 29.447498); }
    double onUranus() { return seconds / (earthYearSeconds * 84.016846); }
    double onNeptune() { return seconds / (earthYearSeconds * 164.79132); }
};


int main() {
    long long segundos = 1000000000; 
    SpaceAge age(segundos);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Edad con " << segundos << " segundos:" << std::endl;
    std::cout << "Tierra: " << age.onEarth() << " años" << std::endl;
    std::cout << "Marte:  " << age.onMars() << " años" << std::endl;
    std::cout << "Jupiter: " << age.onJupiter() << " años" << std::endl;

    return 0;
}

