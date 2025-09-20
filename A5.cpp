#include <iostream>
using namespace std;

int n, k;
char s[100]; // đủ lớn cho n

bool hasRunGreaterThanK(char str[], int n, int k) {
    int cnt = 0, maxc = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '1') cnt++;
        else cnt = 0;
        if (cnt > maxc) maxc = cnt;
    }
    return maxc > k; // chỉ chấp nhận khi có dãy dài hơn k
}

void backtrack(int pos) {
    if (pos == n) {
        if (hasRunGreaterThanK(s, n, k)) {
            for (int i = 0; i < n; i++) cout << s[i];
            cout << "\n";
        }
        return;
    }
    s[pos] = '0';
    backtrack(pos + 1);
    s[pos] = '1';
    backtrack(pos + 1);
}

int main() {
    cin >> n >> k;
    backtrack(0);
    return 0;
}
