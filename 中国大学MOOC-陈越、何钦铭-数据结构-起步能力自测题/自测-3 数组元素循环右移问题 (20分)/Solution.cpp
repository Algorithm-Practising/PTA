#include<iostream>
using namespace std;
const int N = 1e2 + 10;
int a[N];
int main()
{
    int T, K;
    cin >> T >> K;
    for (int i = 0; i < T; i++)
        cin >> a[i];
    K = K % T;
    for (int i = 0; i < T - 1; i++) {
        cout << a[(T+i - K) % T] << " ";
    }
    cout << a[(T+T - 1 - K) % T];
    return 0;
}