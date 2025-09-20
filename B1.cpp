#include <iostream>
using namespace std;

class Date {
    int d, m, y;
public:
    Date(int, int, int);  // constructor 1
    Date(int);            // constructor 2
    void Print();         // in ngày/tháng/năm
};

bool isLeap(int yy) {
    return (yy % 400 == 0) || (yy % 4 == 0 && yy % 100 != 0);
}

int daysInMonth(int mm, int yy) {
    int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (mm == 2 && isLeap(yy)) return 29;
    return days[mm];
}

Date::Date(int dd, int mm, int yy) {
    if (yy > 0 && mm >= 1 && mm <= 12 && dd >= 1 && dd <= daysInMonth(mm, yy)) {
        d = dd; m = mm; y = yy;
    } else {
        d = 1; m = 1; y = 2000;
    }
}

Date::Date(int yy) { // mặc định 1/1/yy
    d = 1; m = 1; y = (yy > 0 ? yy : 2000);
}

void Date::Print() {
    cout << d << "/" << m << "/" << y << endl;
}

int main() {
    int dd, mm, yy;

    cout << "Nhap ngay thang nam cho doi tuong 1: ";
    cin >> dd >> mm >> yy;
    Date date1(dd, mm, yy);
    date1.Print();

    cout << "Nhap ngay thang nam cho doi tuong 2: ";
    cin >> dd >> mm >> yy;
    // dùng constructor 1 nếu muốn đúng cả ngày tháng năm
    Date date2(dd, mm, yy);
    date2.Print();

    return 0;
}
