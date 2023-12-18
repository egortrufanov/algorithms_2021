using namespace std;
#include <iostream>
#include <math.h>

double function(double x, double y);
double method_RK(double x, double y);
void task1();
void task2();
void task3();
void task4();



double function(double x, double y)
{
    double f = cos(x) * y;
    return f;
}

double solution(double x) 
{
    double s = exp(sin(x));
    return s;
}

void task1() //Метод Рунге-Кутты
{
    setlocale(LC_ALL, "Russian");
    double x0 = 0, y0 = 2, h = 0.1, x, y, n = 11, z;
    x = x0;
    y = y0;
    cout << "Результат функции y*cos(x) по методу Рунге-Кутты:" << endl;
    cout << "x:\ty:\texp^sin(x)" << endl;
    for (int i = 1; i <= n; ++i) 
    {
        z = solution(x);
        cout << x << '\t' << y << '\t' << z << endl;
        double k0, k1, k2, k3;
        k0 = h * function(x, y);
        k1 = h * function(x + h / 2, y + k0 / 2);
        k2 = h * function(x + h / 2, y + k1 / 2);
        k3 = h * function(x + h, y + k2);
        y = y + (k0 + 2 * k1 + 2 * k2 + k3) / 6;
        x = x0 + i * h;
    }
}



double method_RK(double x, double y)
{
    double h = 0.1, k1, k2, k3, k4;

    k1 = function(x, y);
    k2 = function(x + h / 2, y + (h * k1) / 2);
    k3 = function(x + h / 2, y + (h * k2) / 2);
    k4 = function(x + h, y + (h * k3));
    y = y + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
    x = x + h;
    return y;
}

void task2() //Метод прогноза и коррекции
{
    setlocale(LC_ALL, "Russian");
    double h = 0.1, x = 0, y = 2, z;
    const int n = 12;
    double dy[n + 1], X[n], Y[n];
    X[0] = x;
    Y[0] = y;
    dy[0] = y;
    cout << "Результат функции y*cos(x) по методу прогноза и коррекции:" << endl;
    cout << "x:\ty:\texp^sin(x)" << endl;
    for (int i = 0; i < 3; i++)
    {
        z = solution(X[i]);
        cout << X[i] << '\t' << Y[i] << '\t' << z << endl;
        Y[i + 1] = method_RK(X[i], Y[i]);// находим первые 3 значения y через Рунге-Кутта
        dy[i + 1] = function(X[i], Y[i]);// находим значение функции в точках х,у
        X[i + 1] = X[i] + h;

    }

    for (int i = 3; i < n - 1; i++)
    {
        z = solution(X[i]);
        cout << X[i] << '\t' << dy[i] << '\t' << z << endl;
        X[i + 1] = X[i] + h;
        dy[i + 1] = Y[i] + h / 24 * (55 * dy[i] - 59 * dy[i - 1] + 37 * dy[i - 2] - 9 * dy[i - 3]);  // прогноз
        Y[i + 1] = Y[i] + h / 24 * (9 * dy[i + 1] + 19 * dy[i] - 5 * dy[i - 1] + dy[i - 2]); // коррекция для у
    }

}

void task3() //Метод Адамса
{
    setlocale(LC_ALL, "Russian");
    double h = 0.1, x = 0, y = 1, z;
    const int n = 12;
    double dy[n + 1], X[n], Y[n], d1[n], d2[n], d3[n];
    X[0] = x;
    Y[0] = y;
    dy[0] = y;
    cout << "Результат функции y*cos(x) по методу Адамса:" << endl;
    cout << "x:\ty:\texp^sin(x)" << endl;

    for (int i = 0; i < 3; i++)
    {
        z = solution(X[i]);
        cout << X[i] << '\t' << Y[i] << '\t' << z << endl;
        Y[i + 1] = method_RK(X[i], Y[i]);// находим первые 3 значения y через Рунге-Кутта
        dy[i + 1] = function(X[i], Y[i]);// находим значение функции в точках х,у
        X[i + 1] = X[i] + h;

    }

    for (int i = 3; i < n - 1; i++)
    {
        z = solution(X[i]);
        cout << X[i] << '\t' << dy[i] << '\t' << z << endl;
        d1[i] = dy[i] - dy[i - 1];
        d2[i] = dy[i] - 2 * dy[i - 1] + dy[i - 2];
        d3[i] = dy[i] - 3 * dy[i - 1] + 3 * dy[i - 2] - dy[i - 3];
        dy[i + 1] = dy[i] + h * dy[i] + h * h / 2 * d1[i] + 5 / 12 * h * h * h * d2[i] + 3 / 8 * h * h * h * h * d3[i];
        X[i + 1] = X[i] + h;
    }

}

float integral(float x, float y) {
    return y * x * sin(x);
}

void task4() //Метод последовательных приближений
{
    double x0= 0, y0 = 1, h = 0.1, y, z;
    const int n = 12;
    double  X[n], Y[n];
    X[0] = x0;
    Y[0] = y0;
    cout << "Результат функции y*cos(x) по методу последовательных приближений:" << endl;
    cout << "x:\ty:\texp^sin(x)" << endl;
    for (int i = 0; i < n-1; i++)
    {
        z = solution(X[i]);
        cout << X[i] << '\t' << Y[i] << '\t' << z << endl;
        Y[i + 1] = y0 + integral( X[i], Y[i]);
        X[i + 1] = X[i] + h;
    }

}

int main() {
    task1();
    cout << "\n";
    task2();
    cout << "\n";
    task3();
    cout << "\n";
    task4();
}

