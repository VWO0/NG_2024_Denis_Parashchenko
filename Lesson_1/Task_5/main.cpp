#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

int main()
{
    double a, b, c;
    cout << "Enter a, b, c: ";
    cin >> a >> b >> c;

    if (a == 0 && b == 0 && c == 0)
    {
        cout << "All coefficients are zero, infinitely many solutions." << endl;
    }
    else if (a == 0 && b == 0)
    {
        cout << "No solutions." << endl;
    }
    else if (a == 0)
    {
        double x = -c / b;
        cout << "Linear equation solution: x = " << x << endl;
    }
    else
    {
        double discriminant = b * b - 4 * a * c;
        if (discriminant > 0)
        {
            double x1 = (-b + sqrt(discriminant)) / (2 * a);
            double x2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Real roots: x1 = " << x1 << ", x2 = " << x2 << endl;
        }
        else if (discriminant == 0)
        {
            double x = -b / (2 * a);
            cout << "One real root: x = " << x << endl;
        }
        else
        {
            complex<double> sqrt_discriminant(0, sqrt(-discriminant));
            complex<double> x1 = (-b + sqrt_discriminant) / (2.0 * a);
            complex<double> x2 = (-b - sqrt_discriminant) / (2.0 * a);
            cout << "Complex roots: x1 = " << x1 << ", x2 = " << x2 << endl;
        }
    }

    return 0;
}
