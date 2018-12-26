#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> dp(2);

int main() {
    string s;
    cin >> s;

    int len = s.size() - 1;
    if (s[0] == '0')
        cout << "0" << endl;
    else {
        dp[0] = dp[1] = 1;
        if (s[len] == '0')
            dp[len % 2] = 0;
        for (int i = len - 1; i >= 0; --i) {
            if (s[i] == '0') {
                dp[i % 2] = 0;
                if (dp[0] == 0 && dp[1] == 0) {
                    cout << "0" << endl;
                    break;
                }
            } else {
                int k = (s[i] - '0') * 10 + (s[i + 1] - '0');

                if (k < 27) {
                    dp[i % 2] += dp[(i + 1) % 2];
                    dp[i % 2] %= 1000000;
                } else
                    dp[i % 2] = dp[(i + 1) % 2];
            }
        }
        cout << dp[0] << endl;
    }
}