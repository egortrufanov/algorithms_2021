#include <iostream>
#include <math.h>
using namespace std;

void сout(double** a, double* y, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " * x" << j + 1;
            if (j < n - 1)
                cout << " + ";
        }
        cout << " = " << y[i] << endl;
    }
    cout << endl;
}

double* progon(double** a, double* y, int n) {
    double b;
    double* Ai = new double[n];
    double* Bi = new double[n];
    double* x = new double[n];
    n--;

    b = a[0][0];
    Ai[0] = -a[0][1] / b;
    Bi[0] = y[0] / b;
    for (int i = 1; i < n; i++) {
        b = a[i][i] + a[i][i - 1] * Ai[i - 1];
        Ai[i] = -a[i][i + 1] / b;
        Bi[i] = (y[i] - a[i][i - 1] * Bi[i - 1]) / b;
    }

    x[n] = (y[n] - a[n][n - 1] * Bi[n - 1]) / (a[n][n] + a[n][n - 1] * Ai[n - 1]);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = Ai[i] * x[i + 1] + Bi[i];
    }
    return x;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    const int n = 4;
    double** a = new double* [n];
    double* y = new double[n];
    for (int i = 0; i < n; i++)
        a[i] = new double[n];

    a[0][0] = 3; a[0][1] = 1; a[0][2] = 0; a[0][3] = 0; y[0] = 5;
    a[1][0] = 1; a[1][1] = 2; a[1][2] = 1; a[1][3] = 0; y[1] = 6;
    a[2][0] = 0; a[2][1] = 3; a[2][2] = 9; a[2][3] = 6; y[2] = 25;
    a[3][0] = 0; a[3][1] = 0; a[3][2] = 2; a[3][3] = 4; y[3] = 5;
    cout << "Исходная система" << endl;
    сout(a, y, n);
    double* x = progon(a, y, n);
    cout << "Решение системы" << endl;
    for (int i = 0; i < n; i++)
        cout << "x[" << i + 1 << "]=" << x[i] << endl;
    return 0;
}
