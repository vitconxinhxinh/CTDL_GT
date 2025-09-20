#include <iostream>
using namespace std;

const int MAXN = 305;
char s[MAXN];
int dp[MAXN][MAXN];

bool isPalindrome(int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> (s+1); // lưu từ vị trí 1 để dễ làm
        int n = 0;
        while (s[n+1] != '\0') n++;

        // khởi tạo
        for (int i = 1; i <= n; i++) dp[i][i] = 1;

        for (int len = 2; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                dp[i][j] = len; // tệ nhất là xóa từng ký tự

                if (isPalindrome(i, j)) {
                    dp[i][j] = 1;
                } else {
                    for (int k = i; k < j; k++) {
                        if (dp[i][j] > dp[i][k] + dp[k+1][j]) {
                            dp[i][j] = dp[i][k] + dp[k+1][j];
                        }
                    }
                    if (s[i] == s[j] && dp[i][j] > dp[i+1][j-1]) {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
            }
        }
        cout << dp[1][n] << "\n";
    }
    return 0;
}
