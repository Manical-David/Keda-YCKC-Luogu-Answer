#include <bits/stdc++.h>
using namespace std;

const int MAX_ROLLS = 3;
const int MAX_DICE = 5;
const int MAX_FACE = 100;

double dp[MAX_ROLLS + 1][MAX_DICE + 1][MAX_FACE + 1];

int main() {
    vector<int> faces(MAX_FACE + 1);
    for (int i = 1; i <= MAX_FACE; ++i) {
        cin >> faces[i];
    }

    // Initialize dp for the last roll
    for (int i = 0; i <= MAX_DICE; ++i) {
        for (int j = 1; j <= MAX_FACE; ++j) {
            dp[MAX_ROLLS][i][j] = i * j;
        }
    }

    // Fill dp table from the second last roll to the first roll
    for (int k = MAX_ROLLS - 1; k >= 0; --k) {
        for (int i = 0; i <= MAX_DICE; ++i) {
            for (int j = 1; j <= MAX_FACE; ++j) {
                double max_exp_value = 0.0;
                for (int l = 0; l <= MAX_DICE - i; ++l) {
                    double exp_value = i * j;
                    for (int v = 1; v <= MAX_FACE; ++v) {
                        exp_value += dp[k + 1][i + l][v] * (pow(1.0 / 6.0, l) * pow(5.0 / 6.0, MAX_DICE - i - l));
                    }
                    max_exp_value = max(max_exp_value, exp_value);
                }
                dp[k][i][j] = max_exp_value;
            }
        }
    }

    // Calculate the final expected value
    double final_exp_value = 0.0;
    for (int v = 1; v <= MAX_FACE; ++v) {
        final_exp_value += dp[0][0][v] * (1.0 / 6.0);
    }

    cout << fixed << setprecision(10) << final_exp_value << endl;
    return 0;
}
