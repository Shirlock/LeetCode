
/*
O(n^2) Time Limit Exceeded
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA=0;
        int len=height.size();
        for(int i=0;i<len-1;i++){
            for(int j=i+1;j<len;j++){
                int tmp=min(height[i],height[j])*(j-i);
                if(maxA<tmp) maxA=tmp;
            }
        }
        return maxA;
    }
};
/*
22ms
Your runtime beats 37.34% of cpp submissions
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA=0;
        int left=0,right=height.size()-1;
        while(left<right){
            int tmp=(right-left)*min(height[left],height[right]);
            if(tmp>maxA){
                maxA=tmp;
            }
            if(height[left]>height[right])
                    right--;
            else
                    left++;
            /*
            开始这样写，是错误的，因为第二个if语句中right的值已经改变了
            if(height[left]>height[right])
                    right--;
            if(height[left]<=height[right])
                    left++;
            */
        }
        return maxA;
    }
};
/*
26ms
Your runtime beats 21.97% of cpp submissions
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA=0;
        int left=0,right=height.size()-1;
        while(left<right){
            int minh=min(height[left],height[right]);
            maxA=max(maxA,(right-left)*minh);
            while(height[left]<=minh&&left<right)
                    left++;
            while(height[right]<=minh&&left<right)
                    right--;
        }
        return maxA;
    }
};