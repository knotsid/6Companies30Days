#include <bits/stdc++.h>
using namespace std;

int maxRotateFunction(vector<int> &nums)
{

   int n = nums.size(), f = 0, sum = 0;
   for (int i = 0; i < n; i++)
   {
      sum += nums[i];
      f += i * nums[i];
   }
   int mx = f;
   for (int k = n - 1; k > 0; k--)
   {
      f = f + sum - n * nums[k];
      mx = max(mx, f);
   }
   return mx;
}

// TC --> O(N)
// SC --> O(1)

int main()
{

   vector<int> nums = {4, 3, 2, 6};

   cout << maxRotateFunction(nums) << endl;

   return 0;
}