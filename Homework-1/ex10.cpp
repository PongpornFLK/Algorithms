#include <iostream>
using namespace std;

const int n = 100000; 

int main()
{
    
    int N = 0;
    cin >> N;

    int C[n+2] = {0};

    for (int i = 0; i < N; i++)
    {
        int A, B = 0;
        cin >> A >> B;
        C[A]++;     
        C[B + 1]--; 
    }

    int max = 0;
    int time = 0;
    int s = 0;
    int e = 0;

    for (int i = 0; i <= n; i++)
    {
        time += C[i];
        if (time > max)
        {
            max = time;
            s = i;
            e = i;
        }
        else if (time == max)
        {
            e = i;
        }
    }

    cout << s << " " << e << " " << max << endl;

    return 0;
}
