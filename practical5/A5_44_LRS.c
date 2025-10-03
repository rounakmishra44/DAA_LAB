#include <iostream>
#include <string>
using namespace std;

string LRS(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    int c[100][100]; 


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1] && i != j)
                c[i][j] = 1 + c[i-1][j-1];
            else
                c[i][j] = max(c[i-1][j], c[i][j-1]);
        }
    }


    cout << "DP Matrix:" << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }

    cout << "\nLength of LRS: " << c[n][m] << endl;

    string lrs = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1] && i != j) {
            lrs = s1[i-1] + lrs;
            i--;
            j--;
        } else if (c[i-1][j] > c[i][j-1])
            i--;
        else
            j--;
    }

    return lrs;
}

int main() {
    string s1 = "AABEBCDD";
    string s2 = "AABEBCDD";
    string result = LRS(s2, s2);
    cout << "LRS: " << result << endl;
    return 0;
}
