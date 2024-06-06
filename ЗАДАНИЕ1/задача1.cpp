#include <iostream>
#include "DynamicArrayOfIntegers.h"
struct SizeException{};
using namespace std;

int main()
{
    DynamicArrayOfIntegers x(3, 1);
    cout << x << endl;
    DynamicArrayOfIntegers y(x);
    cout << y << endl;
    cout << x.getSize() << endl;
    x.resize(4);
    cout << x[3] << endl;
    DynamicArrayOfIntegers z;
    z = y;
    cout << z << endl;
    DynamicArrayOfIntegers c(3, 3);
    cout << c << endl;
    DynamicArrayOfIntegers p;
    cout << ">>" << endl;
    cin >> p;
    cout << p << endl;

    cout << "==" << endl;

    if (z == y) cout << "True" << endl;
    else cout << "False" << endl;
    if (z == c) cout << "True" << endl;
    else cout << "False" << endl;
    try{
        if (z == x) cout << "True" << endl;
        else cout << "False" << endl;
    }
    catch(SizeException){cout << "error" << endl;}

    cout << "!=" << endl;

    if (z != c) cout << "True" << endl;
    else cout << "False" << endl;
    if (z != y) cout << "True" << endl;
    else cout << "False" << endl;
    try {
        if (z != x) cout << "True" << endl;
        else cout << "False" << endl;
    }
    catch (SizeException) { cout << "error" << endl; }


    cout << "<" << endl;
    if (y < c) cout << "True" << endl;
    else cout << "False" << endl;
    if (c < y) cout << "True" << endl;
    else cout << "False" << endl;
    if (y < z) cout << "True" << endl;
    else cout << "False" << endl;
    if (y < x) cout << "True" << endl;
    else cout << "False" << endl;
    if (x < y) cout << "True" << endl;
    else cout << "False" << endl;

    cout << ">" << endl;
    if (y > c) cout << "True" << endl;
    else cout << "False" << endl;
    if (c > y) cout << "True" << endl;
    else cout << "False" << endl;
    if (y > z) cout << "True" << endl;
    else cout << "False" << endl;
    if (y > x) cout << "True" << endl;
    else cout << "False" << endl;
    if (x > y) cout << "True" << endl;
    else cout << "False" << endl;

    cout << "<=" << endl;
    if (y <= c) cout << "True" << endl;
    else cout << "False" << endl;
    if (c <= y) cout << "True" << endl;
    else cout << "False" << endl;
    if (y <= z) cout << "True" << endl;
    else cout << "False" << endl;
    if (y <= x) cout << "True" << endl;
    else cout << "False" << endl;

    cout << ">=" << endl;
    if (y >= c) cout << "True" << endl;
    else cout << "False" << endl;
    if (c >= y) cout << "True" << endl;
    else cout << "False" << endl;
    if (y >= z) cout << "True" << endl;
    else cout << "False" << endl;
    if (x >= y) cout << "True" << endl;
    else cout << "False" << endl;

    cout << "+" << endl;
    z = z + c;
    cout << z << endl;
}