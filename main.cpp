#include <iostream>
#include <cstdlib>
#include <ctime>
#include "randfuncs.h"

using namespace std;

int main()
{
    srand(time(0));

    cout << "Coin: " << flipCoin() << endl;
    cout << "D6: " << rollD6() << endl;
    cout << "D10: " << rollD10() << endl;

    return 0;
}	  