#include <iostream>

using namespace std;

// S为主串，T为模式串
int bruteForce(string S, string T) {
    int i = 0, j = 0;
    while (i < S.length() && j < T.length()) {
        if (S[i] == T[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    j >= T.length() ? cout << "YES" : cout << "NO";
}

int main() {
    string S, T;
    cin >> S >> T;
    bruteForce(S,T);
    return 0;
}