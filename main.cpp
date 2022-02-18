#include <iostream>
#include "Matrix.h"

using namespace std;

int x, y;

int main() {
    Matrix q3;
    cout << "Enter 1st matrix size(x, y): ";
    cin >> x >> y;
    Matrix q1(x, y);
    cout << "Enter matrix:\n";
    cin >> q1;

    cout << "Enter 2nd matrix size(x, y): ";
    cin >> x >> y;
    Matrix q2(x, y);
    cout << "Enter matrix:\n";
    cin >> q2;

    cout << "-----------------------\n";
    cout << "1st matrix:\n";
    cout << q1;
    cout << "\n";
    cout << "2nd matrix:\n";
    cout << q2;
    cout << "-----------------------\n";
    cout << "+:\n";
    q3 = q1 + q2;
    cout << q3;
    cout << "-----------------------\n";
    cout << "-:\n";
    q3 = q1 - q2;
    cout << q3;
    cout << "-----------------------\n";
    cout << "*:\n";
    q3 = q1 * q2;
    cout << q3;
    cout << "-----------------------\n";
    cout << "Enter number: ";
    cin >> x;
    cout << "1st matrix * " << x << ":\n";
    q3 = q1 * x;
    cout << q3;
    return 0;
}
