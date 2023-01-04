#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void solve(int k, int n, int num, vector<int> &curr)
{

   if (n < 0 || n > 45 || curr.size() > k)
      return;
   if (n == 0 && curr.size() == k)
   {
      ans.push_back(curr);
      return;
   }

   for (int i = num; i <= 9; i++)
   {
      curr.push_back(i);
      solve(k, n - i, i + 1, curr);
      curr.pop_back();
   }
}

vector<vector<int>> combinationSum3(int k, int n)
{

   vector<int> curr;
   solve(k, n, 1, curr);
   return ans;
}

int main()
{

   vector<vector<int>> ans = combinationSum3(3, 9);

   for (int i = 0; i < ans.size(); i++)
   {
      for (int j = 0; j < ans[0].size(); j++)
         cout << ans[i][j] << " ";
      cout << endl;
   }

   return 0;
}