#include <iostream>
#include <stdio.h>
#include <vector>

typedef std::vector<int> BigInt;

const int MAX_ENTER(9999);
const int UP_NUMBER(10000);

BigInt bigFactorial(int n) {

    BigInt result;

    if (n <= MAX_ENTER) {
        result.push_back(1);

        for (int i = 1; i <= n; ++i) {
            int up = 0;
            for (auto& child : result) {
                int product = child * i + up;
                child = product % UP_NUMBER;
                up = product / UP_NUMBER;
            }

            if (up > 0) {
                result.push_back(up);
            }
        }
    }

    return result;
}

int main()
{
    using namespace std;

    int n;
    do {
        cout << "Please enter n: " << flush;
        if (cin >> n) {
            if (n >= 0) {
                BigInt nfact = bigFactorial(n);
                if (nfact.empty()) {
                    cerr << "overflow error: " << n << " is too big." << endl;
                } else {
                    cout << "bigFactorial(" << n << ") = ";
                    printf("%d", (int)nfact.back());
                    for (auto it = nfact.rbegin()+1; it != nfact.rend(); ++it)
                        printf("%04d", (int)*it);
                    printf("\n");
                }
            } else {
                cerr << "Undefined: factorial of a negative number: " << n << endl;
            }
        } else {
            cerr << "Undefined: factorial of a non-numeric!" << endl;
            break;
        }
    } while (n != MAX_ENTER);

    return 0;
}
