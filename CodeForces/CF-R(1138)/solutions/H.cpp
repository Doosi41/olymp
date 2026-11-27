#include <array>
#include <iostream>
#include <vector>

using Directions = std::array<int, 2>;

Directions exchange(const Directions& endpoints, Directions& sent,
                    std::vector<int>& known) {
    const auto [u, v] = endpoints;
    // On a tree, every news item from the opposite side arrived on this edge.
    const int alreadyShared = sent[0] + sent[1];
    const Directions gained{known[u] - alreadyShared, known[v] - alreadyShared};
    sent[0] += gained[0];
    sent[1] += gained[1];
    known[u] += gained[1];
    known[v] += gained[0];
    return gained;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tests;
    std::cin >> tests;
    while (tests--) {
        int n, m;
        std::cin >> n >> m;

        std::vector<Directions> edges(n - 1);
        for (auto& [u, v] : edges) {
            std::cin >> u >> v;
            --u;
            --v;
        }

        std::vector<int> calls(m);
        std::vector<int> known(n, 1);
        std::vector<Directions> sent(n - 1);
        std::vector<Directions> firstArrival(m);
        for (int i = 0; i < m; ++i) {
            int edge;
            std::cin >> edge;
            calls[i] = --edge;
            firstArrival[i] = exchange(edges[edge], sent[edge], known);
        }

        known.assign(n, 1);
        sent.assign(n - 1, Directions{});
        std::vector<long long> answer(m);
        for (int i = m - 1; i >= 0; --i) {
            const int edge = calls[i];
            const auto lastDeparture = exchange(edges[edge], sent[edge], known);
            // A source-destination pair is lost only if this is both the first
            // and the last call on this edge that can connect the pair.
            answer[i] = 1LL * firstArrival[i][0] * lastDeparture[1]
                      + 1LL * firstArrival[i][1] * lastDeparture[0];
        }

        for (int i = 0; i < m; ++i) {
            if (i > 0) {
                std::cout << ' ';
            }
            std::cout << answer[i];
        }
        std::cout << '\n';
    }
}
