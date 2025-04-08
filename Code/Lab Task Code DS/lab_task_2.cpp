#include <bits/stdc++.h>

using namespace std;

double sqrtBinarySearch(double N) {
    if (N < 0) {
        return -1; // Invalid input
    }

    double low = 0, high = N;
    double mid;

    // If N is less than 1, set high to 1
    if (N < 1) {
        high = 1;
    }

    // Set precision for 4 decimal places
    double precision = 0.00001;

    while (high - low > precision) {
        mid = (low + high) / 2;

        if (mid * mid > N) {
            high = mid;
        } else {
            low = mid;
        }
    }

    return mid;
}

int main() {
    double N;
    cout << "Input: ";
    cin >> N;

    double result = sqrtBinarySearch(N);

    cout << "Output: " << fixed << setprecision(4) << result << endl;

    return 0;
}
