#include <iostream>
using namespace std;

int main()
{
    unsigned long long int N;
    unsigned long long int m[100];
    int k = 0;
    int p;
    cin >> N;
    if (N == 0) { cout << 10 << endl; return 0; }
    while (N > 9) {
        p = 0;
        for (int i = 9; i > 1; i--) {
            if ((N % i) == 0) {
                m[k] = i;
                N = N / i;
                k++;
                p++;
                break;
            }
        }
        if (p==0) {
            cout << -1 << endl;
            return 0;
        }
    }
        m[k] = N;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k - i; j++) {
                if (m[j] > m[j + 1]) {
                    int temp = m[j];
                    m[j] = m[j + 1];
                    m[j + 1] = temp;
                }
            }
        }
        unsigned long long int l = 1;
        unsigned long long int Q = 0;
        for (int i = k; i >= 0;i--) {
            Q = Q + l * m[i];
            l = l * 10;
        }
        cout << Q << endl;
        return 0;
}