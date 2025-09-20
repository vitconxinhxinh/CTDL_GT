#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    // Kiểm tra ràng buộc số bộ test
    if (T < 1 || T > 100) {
        cout << "So bo test khong hop le!" << endl;
        return 0;
    }

    while (T--) {
        string s;
        cin >> s;

        // Kiểm tra ràng buộc độ dài chuỗi
        if (s.length() < 1 || s.length() > 1000) {
            cout << "Do dai xau khong hop le!" << endl;
            continue;
        }

        long long sum = 0, num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else {
                sum += num;
                num = 0;
            }
        }
        sum += num;

        // Kiểm tra ràng buộc kết quả
        if (sum > 1000000000) {
            cout << "Ket qua vuot gioi han!" << endl;
        } else {
            cout << sum << endl;
        }
    }

    return 0;
}
