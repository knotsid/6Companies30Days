class Solution
{
public:
   int minOperations(vector<int> &nums, vector<int> &numsDivide)
   {
      int hcf = findGCD(numsDivide);
      int cnt = 0;
      sort(nums.begin(), nums.end());
      for (int i = 0; i < nums.size(); i++)
      {
         if (hcf % nums[i] == 0)
            return cnt;
         else
            cnt++;
      }
      return -1;
   }

   int gcd(int a, int b)
   {
      if (a == 0)
         return b;
      else
         return gcd(b % a, a);
   }

   int findGCD(vector<int> arr)
   {
      int ans = arr[0];
      for (auto i : arr)
      {
         ans = gcd(ans, i);
         if (ans == 1)
         {
            return 1;
         }
      }
      return ans;
   }
};