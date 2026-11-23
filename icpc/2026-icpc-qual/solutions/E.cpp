#include <iostream>
#include <vector>

using namespace std;


int main() {
    long long n, k;
    cin >> n >> k;

    vector<int> answer;
    int low = 1, high = n;

    // Taking the largest remaining value first creates exactly high - low inversions.
    while (low < high && k >= high - low) {
        answer.push_back(high--);
        k -= high - low + 1;
    }

    if (k > 0) {
        const int middle = low + k;
        answer.push_back(middle);
        for (int value = low; value < middle; ++value) {
            answer.push_back(value);
        }
        low = middle + 1;
    }

    for (int value = low; value <= high; ++value) {
        answer.push_back(value);
    }

    for (int value : answer) {
        cout << value << ' ';
    }
    cout << '\n';
}
