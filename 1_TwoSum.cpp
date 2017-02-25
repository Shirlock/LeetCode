/*
O(n^2)   
Runtime: 106 ms. 
Your runtime beats 34.93% of cpp submissions
2017/2/22
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int>a(2,0);
        for(int i=0;i<nums.size()-1;i++)
            for(int j=i+1;j<nums.size();j++)
                if (nums[i]+nums[j]==target){
                    a[0]=i;
                    a[1]=j;
                    return a;
                }
    }
};

/*
O(nlogn)   
Runtime: 6 ms. 
Your runtime beats 94.18% of cpp submissions
2017/2/22
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> pri_nums(nums.begin(),nums.end());
      sort(nums.begin(),nums.end());
      
      vector<int>a(2,0);
      bool flag=false;
        for(int i=0;i<nums.size()-1;i++){
            int low=i+1,high=nums.size()-1,middle;
            if(flag){
                break;
            }
            while(low<=high){
                middle=(low+high)/2;
                if (nums[i]+nums[middle]==target){
                     a[0]=nums[i];
                     a[1]=nums[middle];
                     flag=true;
                     break;
                }else if(nums[i]+nums[middle]<target){
                    low=middle+1;
                } else {
                    high=middle-1;
                }
            }
        }
      for(int i=0;i<pri_nums.size();i++){
          if(a[0]==pri_nums[i]) {
              a[0]=i;
              break;
          }
      }
      for(int i=0;i<pri_nums.size();i++){
          if(a[1]==pri_nums[i]&& i!=a[0]) {
           a[1]=i;
           break;
          }
      }
      if(a[0]>a[1])
      swap(a[0],a[1]);
      return a;
        
    }
};

/*
O(n)???    不清楚 map.count的复杂度，怎么会这么慢呢？？网上看到同样的算法，用了 unordered_map是6ms
Runtime: 9 ms. 
Your runtime beats 68.32% of cpp submissions
2017/2/22
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<int>a(2,0);
	map<int,int>M;
	M.clear();
	int len=nums.size();
	for(int i=0;i<len;i++)
	{
		if(M.count(nums[i])==0) 
		{
			M[nums[i]]=i;
		}
		if(M.count(target-nums[i])==1 && M[target-nums[i]]!=i) 
		{
			a[0]=M[target-nums[i]];
			a[1]=i;
			return a;
		}

	}  
    }
};
