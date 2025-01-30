#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
void perm(int x[], int start, int end)
{
    if (start == end)
    {
        //		bool tid = false;
        //		for(int i = 2 ; i <=end; i++){
        //			if(x[i] == 2 || x[i] == 3){
        //				if(x[i-1] == 2 || x[i-1] == 3){
        //					tid = true;
        //				}
        //
        //			}
        //		}
        //
        //		if(tid == false){
        vector<int> v;
        for (int i = 1; i <= end; i++)
        {
            v.push_back(x[i]);
        }
        ans.push_back(v);
        return;
        //		}
    }

    for (int i = start; i <= end; i++)
    {
        swap(x[start], x[i]);
        perm(x, start + 1, end);
        swap(x[start], x[i]);
    }
}

int main()
{

    int n = 4;
    int arr[] = {-1, 1, 2, 3, 4};

    perm(arr, 1, n);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << i + 1 << " : ";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}