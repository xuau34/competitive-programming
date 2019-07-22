#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        long double d, a;
        cin >> d >> a;
        // if is square
        long double l = d / sqrtl(2.0L);
        long double r = d / 2.0L;
        if (abs(a-l*l)<1e-5) { // square
            cout << "Square: ";
            cout << fixed << setprecision(12) << (4.0L*l) << endl;
        } else if(abs(M_PI*r*r-a)<1e-5) { // circle
            cout << "Cirle; ";
            cout << fixed << setprecision(12) << (d*M_PI) << endl;
        } else {
            cout << "You liar!" << endl;
        }
    }
    return 0;
}
