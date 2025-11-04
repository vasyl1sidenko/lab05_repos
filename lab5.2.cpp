// Lab_05.2cpp
// Сіденко Василь
// Лабораторна робота №5.2
// Обчислення суми ряду Тейлора за допомогою функцій
// Варіант 24

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double S(const double x, const double eps, int &n);
double A(const double x, const int n, double a);

int main()
{
    double xp, xk, x, dx, eps, s;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "--------------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
         << setw(12) << "ln(1+x)" << " |"
         << setw(12) << "S" << " |"
         << setw(7) << "n" << " |" << endl;
    cout << "--------------------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        s = S(x, eps, n);
        cout << "|" << setw(7) << setprecision(2) << x << " |"
             << setw(12) << setprecision(6) << log(1 + x) << " |"
             << setw(12) << setprecision(6) << s << " |"
             << setw(7) << n << " |" << endl;
        x += dx;
    }

    cout << "--------------------------------------------------------" << endl;
    return 0;
}

double S(const double x, const double eps, int &n)
{
    n = 0;
    double a = x; // перший член ряду при n=0
    double s = a;

    do {
        n++;
        a = A(x, n, a);
        s += a;
    } while (fabs(a) >= eps);

    return s;
}

double A(const double x, const int n, double a)
{
    // Рекурентне співвідношення:
    // a_n = (-1)^n * x^(n+1)/(n+1)
    // => a_n = a_(n-1) * (-1) * x * n / (n+1)
    double R = (-1) * x * n / (n + 1);
    a *= R;
    return a;
}
