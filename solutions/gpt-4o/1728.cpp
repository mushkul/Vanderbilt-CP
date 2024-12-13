#include <iostream>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;
    int r[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> r[i];
    }

    double expected_inversions = 0.0;
    for (int a = 0; a < n; ++a) {
        for (int b = a + 1; b < n; ++b) {
            if (r[a] == 0 || r[b] == 0) continue;
            for (int x_a = 1; x_a <= r[a]; ++x_a) {
                double prob_xa = 1.0 / r[a];
                double sum = 0.0;
                for (int x_b = 1; x_b <= r[b]; ++x_b) {
                    if (x_a > x_b) {
                        sum += 1.0;
                    }
                }
                expected_inversions += prob_xa * (sum / r[b]);
            }
        }
    }

    std::cout << std::fixed << std::setprecision(6) << expected_inversions << std::endl;
    return 0;
}