class Solution
{
public:
   int findUnsortedSubarray(vector<int> &nums)
   {
      int maxy = INT_MIN;
      int miny = INT_MAX;
      int n = nums.size();
      int i, j;
      if (n == 1)
         return 0;

      for (i = 0; i < n; i++)
      {
         if (i == 0)
         {
            if (nums[i] > nums[i + 1])
            {
               maxy = max(maxy, nums[i]);
               miny = min(miny, nums[i]);
            }
         }

         else if (i == n - 1)
         {
            if (nums[i] < nums[i - 1])
            {
               maxy = max(maxy, nums[i]);
               miny = min(miny, nums[i]);
            }
         }
         else
         {
            if (nums[i] > nums[i + 1] || nums[i] < nums[i - 1])
            {
               maxy = max(maxy, nums[i]);
               miny = min(miny, nums[i]);
            }
         }
      }

      if (maxy == INT_MIN || miny == INT_MAX)
         return 0;

      for (i = 0; i < n && nums[i] <= miny; i++)
         ;
      for (j = n - 1; j >= 0 && nums[j] >= maxy; j--)
         ;

      return j - i + 1;
   }
};
