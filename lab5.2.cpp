// Lab_05.2.cpp
// Сіденко Василь
// Лабораторна робота №5.2
// Обчислення суми ряду Тейлора за допомогою функцій
// Варіант 24

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void S(const double x, const double eps, int &n, double &s);
void A(const double x, const int n, double &a);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-----------------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
         << setw(12) << "ln(1+x)" << " |"
         << setw(12) << "S(x)" << " |"
         << setw(7) << "n" << " |"
         << endl;
    cout << "-----------------------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        S(x, eps, n, s);
        cout << "|" << setw(7) << setprecision(2) << x << " |"
             << setw(12) << setprecision(6) << log(1 + x) << " |"
             << setw(12) << setprecision(6) << s << " |"
             << setw(7) << n << " |"
             << endl;
        x += dx;
    }

    cout << "-----------------------------------------------------------" << endl;
    return 0;
}

void S(const double x, const double eps, int &n, double &s)
{
    n = 0;
    double a = x; // перший член ряду при n=0: (-1)^0 * x^(1)/(1) = x
    s = a;

    do {
        n++;
        A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
}

void A(const double x, const int n, double &a)
{
    // рекурентне співвідношення:
    // a_n = (-1)^n * x^(n+1) / (n+1)
    // => a_n = a_(n-1) * (-1) * x * n / (n+1)
    a *= (-1) * x * n / (n + 1);
}
