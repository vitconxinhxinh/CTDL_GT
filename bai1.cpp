#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    if (T < 1 || T > 100) return 0;

    while (T--) {
        int n;
        cin >> n;
        if (n < 1 || n > 100000) return 0;

        int A[100000];
        for (int i = 0; i < n; i++) cin >> A[i];

        sort(A, A + n); // sắp xếp tăng dần

        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (A[i] == ans) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
