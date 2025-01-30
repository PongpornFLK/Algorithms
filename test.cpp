#include <bits/stdc++.h>
#include <string>
using namespace std;

class ans {
public:
    string X; 
    string Y; 
    string A; 
    string B; 
    string C; 
    string D;
    long long result;
};

long long karasuba(string a, string b, vector<ans>& log) {
    int n = max(a.size(), b.size());

    if (a.size() < n) a = string(n - a.size(), '0') + a;
    if (b.size() < n) b = string(n - b.size(), '0') + b;

    if (n == 1) {
        return stoll(a) * stoll(b);
    }

    if (n % 2 != 0) {
        a = "0" + a;
        b = "0" + b;
        n++;
    }

    int m = n / 2;

    string A = a.substr(0, m);
    string B = a.substr(m);
    string C = b.substr(0, m);
    string D = b.substr(m);

    ans temp;
    temp.X = a;
    temp.Y = b;
    temp.A = A;
    temp.B = B;
    temp.C = C;
    temp.D = D;

    long long p1 = karasuba(A, C, log);
    long long p2 = karasuba(B, D, log);
    long long p3 = karasuba(to_string(stoll(A) + stoll(B)), to_string(stoll(C) + stoll(D)), log) - p1 - p2;
    long long result = p1 * pow(10, 2 * m) + p3 * pow(10, m) + p2;

    temp.result = result;
    log.push_back(temp);

    return result;
}

int main() {
    string a = "4568";
    string b = "3275";
    vector<ans> log; 

    long long result = karasuba(a, b, log);
    
    for (int i = 0; i < log.size(); i++) {
        cout << "Step " << i + 1 << ":\n";
        cout << "X: " << log[i].X << endl;
        cout << "Y: " << log[i].Y << endl;
        cout << "A: " << log[i].A ;
        cout << " B: " << log[i].B << endl;
        cout << "C: " << log[i].C ;
        cout << " D: " << log[i].D << endl;
        cout << "Result: " << log[i].result << endl;
        cout << endl;
    }
    
        cout << "Final Result: " << result << endl;
    return 0;
}
