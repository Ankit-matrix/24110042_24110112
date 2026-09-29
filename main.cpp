#include <iostream>
#include <cstdlib>
#include <ctime>
#include "randfuncs.h"
#include "mathfuncs.h"

using namespace std;

int main()
{
    srand(time(0));

    // Random functions
    cout << "Coin: " << flipCoin() << endl;
    cout << "D6: " << rollD6() << endl;
    cout << "D10: " << rollD10() << endl;

    // Math functions
    int a = add(2, 3);
    int b = subtract(5, 4);
    int c = multiply(9, 10);
    int d = divide(2, 5);

    cout << "Add: " << a << endl;
    cout << "Subtract: " << b << endl;
    cout << "Multiply: " << c << endl;
    cout << "Divide: " << d << endl;

    return 0;
}