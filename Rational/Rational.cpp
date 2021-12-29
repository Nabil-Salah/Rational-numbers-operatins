#include <iostream>
#include "RationalNumber.h"

using namespace std;
int main()
{
    RationalNumber r1{ 1,2 };
    RationalNumber r2{ 5,2 };

    cout << r1.toString() << " " << r2.toString()<<endl;
    r1 += r2;
    cout << r1.toString() << " " << r2.toString() << endl;
    r1 -= r2;
    cout << r1.toString() << " " << r2.toString() << endl;
    r1 *= r2;
    cout << r1.toString() << " " << r2.toString() << endl;
    r1 /= r2;
    cout << r1.toString() << " " << r2.toString() << endl;
}
