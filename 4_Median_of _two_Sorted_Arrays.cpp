//
//  4_Median_of _two_Sorted_Arrays.cpp
//  
//
//  Created by songyu on 2017/2/25.
//
//

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size()-1;
        int len2=nums2.size()-1;
        int low1=0,high1=len1,low2=0,high2=len2,middle1,middle2;
        while(low1<=high1||low2<=high2){
            if(low1<=high1)
                middle1=(low1+high1)/2;
            if(low2<=high2)
                middle2=(low2+high2)/2;
            //   if(middle2==middle1)
            //  return (nums1[middle1]+nums2[middle2])/2.0;
            //        else
            if(middle2>middle1){
                high2=middle2-1;
                low1=middle1+1;
            }else{
                high1=middle1-1;
                low2=middle2+1;
            }
        }
        return (nums1[middle1]+nums2[middle2])/2.0;
    }
};
