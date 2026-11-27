#include <iostream>
#include <numeric>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tests;
    std::cin >> tests;
    while (tests--) {
        long long length, strawberryStep, blueberryStep;
        std::cin >> length >> strawberryStep >> blueberryStep;

        const auto strawberryDivisor = std::gcd(length, strawberryStep);
        const auto blueberryDivisor = std::gcd(length, blueberryStep);
        std::cout << length / std::lcm(strawberryDivisor, blueberryDivisor) << '\n';
    }
}
