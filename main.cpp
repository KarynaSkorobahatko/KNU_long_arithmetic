#include <iostream>
#include "myint.h"
#include<bits/stdc++.h>

using namespace std;

apa::myint inv(apa::myint a, apa::myint m) {
    //modular multiplicative inverse
    apa::myint m0 = m, t, q;
    apa::myint x0 = 0, x1 = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    return x1;
}

apa::myint findMinX(apa::myint num[], apa::myint rem[], int k) {
    apa::myint prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];
    apa::myint result = 0;
    for (int i = 0; i < k; i++) {
        apa::myint pp = prod / num[i];
        result += rem[i] * inv(pp, num[i]) * pp;
    }
    return result % prod;
}

int main() {
    do{
    cout << "Опція:" << '\n';
    cout << "1) +" << '\n';
    cout << "2) -" << '\n';
    cout << "3) *" << '\n';
    cout << "4) /" << '\n';
    cout << "5) %" << '\n';
    cout << "6) **" << '\n';
    cout << "7) ==" << '\n';
    cout << "8) >" << '\n';
    cout << "9) <" << '\n';
    cout << "10) mod +" << '\n';
    cout << "11) mod -" << '\n';
    cout << "12) mod *" << '\n';
    cout << "13) mod /" << '\n';
    cout << "14) mod %" << '\n';
    cout << "15) mod **" << '\n';
    cout << "17) sqrt" << '\n';
    cout << "18) chinese remainder theorem" << '\n';

    int var = -1;
    apa::myint a;
    apa::myint b;
    apa::myint mod;
    cin >> var;
    if (var == -1) return 0;
    cin.get();
    if (var > 0 and var < 17) {
        cout << "Введіть ліве число:" << '\n';
        cin >> a;
        cout << "Введіть праве число" << '\n';
        cin >> b;
        if (var > 9) {
            cout << "Введіть модуль:" << '\n';
            cin >> mod;
        }
    }

    //apa::myint num[] = {apa::myint("2323323232323232323232323232323232323232323232323"), apa::myint("2323323232323212323232323232323232323232323"), 5};
    //apa::myint rem[] = {2, 3, 1};
    apa::myint num[] = { 7, 11, 13};
    apa::myint rem[] = { 3, 10, 12};
    //apa::myint num[] = {11};
    //apa::myint rem[] = {7};
    int k = sizeof(num) / sizeof(num[0]);

    switch (var) {
        case 1:
            cout << "Результат: " << a + b << '\n';
            break;
        case 2:
            cout << "Результат: " << a - b << '\n';
            break;
        case 3:
            cout << "Результат: " << a * b << '\n';
            break;
        case 4:
            cout << "Результат: " << a / b << '\n';
            break;
        case 5:
            cout << "Результат: " << a % b << '\n';
            break;
        case 6:
            cout << "Результат: " << apa::pow(a, b) << '\n';
            break;
        case 7:
            cout << "Результат: " << bool(a == b) << '\n';
            break;
        case 8:
            cout << "Результат: " << bool(a > b) << '\n';
            break;
        case 9:
            cout << "Результат: " << bool(a < b) << '\n';
            break;
        case 10:
            cout << "Результат: " << (a % mod + b % mod) % mod << '\n';
            break;
        case 11:
            cout << "Результат: " << (a % mod - b % mod) % mod << '\n';
            break;
        case 12:
            cout << "Результат: " << ((a % mod) * (b % mod)) % mod << '\n';
            break;
        case 13:
            cout << "Результат: " << /*(((a % mod)*apa::powmod(b, mod - 2, mod))) % mod */ (a / b) % mod << '\n';
            break;
        case 14:
            cout << "Результат: " << ((a % mod) % (b % mod)) % mod << '\n';
            break;
        case 15:
            //cout << "Результат: " << apa::pow(a % mod, b % mod) % mod << '\n';
            cout << "Результат: " << apa::powmod(a , b,mod)  << '\n';
            break;
        case 16:
            cout << "Результат: " << a + b << '\n';
            break;
        case 17:
            cout << "Введіть число" << '\n';
            cin >> a;
            cout << "Результат: " << apa::sqrt(a) << '\n';
            break;
        case 18:
            cout << "Результат: " << findMinX(num, rem, k)<<endl;
            break;
        default:
            cout << "Неправильна опція" << '\n';
            break;
    }
    }while (true);

}