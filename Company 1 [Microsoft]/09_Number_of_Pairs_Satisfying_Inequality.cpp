class Solution
{
public:
   long long cnt = 0;
   long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int diff)
   {

      int n = nums1.size();
      vector<int> arr(n, 0);
      for (int i = 0; i < n; i++)
      {
         arr[i] = nums1[i] - nums2[i];
      }

      mergeSort(0, n - 1, arr, diff);
      return cnt;
   }

   void merge(int start, int mid, int end, vector<int> &arr, int &diff)
   {
      int left = start;
      int right = mid + 1;
      while (left <= mid && right <= end)
      {
         if (arr[left] <= arr[right] + diff)
         {
            cnt += (end - right + 1);
            left++;
         }
         else
         {
            right++;
         }
      }
      sort(arr.begin() + start, arr.begin() + end + 1);
   }

   void mergeSort(int start, int end, vector<int> &arr, int &diff)
   {
      if (start >= end)
         return;
      int mid = (start + end) / 2;
      mergeSort(start, mid, arr, diff);
      mergeSort(mid + 1, end, arr, diff);
      merge(start, mid, end, arr, diff);
   }
};