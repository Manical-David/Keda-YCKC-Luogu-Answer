#include <iostream>
using namespace std;
int main() {
    int N, A, B;
    cin >> N >> A >> B;
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        int num = i;
        int digt = 0;
        while (num > 0) {
            digt += num % 10;
            num /= 10;
        }
        if (digt >= A && digt <= B)
            sum += i;
    }
    cout << sum;
    return 0;
}