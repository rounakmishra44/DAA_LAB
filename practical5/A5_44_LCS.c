#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#define MAX_SIZE 100
using namespace std;
void cost_matrix(const string& s1, const string& s2) {
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> x(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                x[i][j] = 1 + x[i - 1][j - 1];
            } else {
                x[i][j] = max(x[i - 1][j], x[i][j - 1]);
            }
        }
    }
    for (int j = 0; j < n; ++j) {
        cout << setw(3) << s2[j] << " ";
    }
    cout << endl;
    for (int i = 0; i <= m; ++i) {
        if (i > 0) {
            cout << s1[i - 1] << " ";
        } else {
            cout << " ";
        }
        for (int j = 0; j <= n; ++j) {
            cout << setw(3) << x[i][j] << " ";
        }
        cout << endl;
    }
}
int lcs_length(const string& s1, const string& s2) {
    int m = s1.length();
    int n = s2.length();
    int y[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j == 0) {
                y[i][j] = 0;
            } else if (s1[i - 1] == s2[j - 1]) {
                y[i][j] = 1 + y[i - 1][j - 1];
            } else {
                y[i][j] = max(y[i - 1][j], y[i][j - 1]);
            }
        }
    }
    return y[m][n];
}
string findLCS(const string& a, const string& b) {
    int m = a.length();
    int n = b.length();
    int z[MAX_SIZE][MAX_SIZE];
    char dir[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i <= m; ++i) {
        z[i][0] = 0;
    }
    for (int j = 0; j <= n; ++j) {
        z[0][j] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                z[i][j] = 1 + z[i - 1][j - 1];
                dir[i][j] = 'd';
            } else if (z[i - 1][j] >= z[i][j - 1]) {
                z[i][j] = z[i - 1][j];
                dir[i][j] = 'u';
            } else {
                z[i][j] = z[i][j - 1];
                dir[i][j] = 'l';
            }
        }
    }
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (dir[i][j] == 'd') {
            lcs = a[i - 1] + lcs;
            i--;
            j--;
        } else if (dir[i][j] == 'u') {
            i--;
        } else {
            j--;
        }
    }
    cout << "Length: " << z[m][n] << endl;
    return lcs;
}
int main() {
    string d1 = "AGCCCTAAGGGCTACCTAGCTT";
    string d2 = "GACAGCCTACAAGCGTTAGCTTG";
    cost_matrix(d1, d2);
    int length = lcs_length(d1, d2);
    string lcs = findLCS(d1, d2);
    cout << "LCS: " << lcs << endl;
    return 0;
}
