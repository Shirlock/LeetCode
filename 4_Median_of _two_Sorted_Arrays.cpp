//
//  4_Median_of _two_Sorted_Arrays.cpp
//  
//
//  Created by songyu on  2017/2/26.
//
//

/* 没想出好方法，参考LeetCode 上的解法*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> numsA,numsB;
        if(nums1.size()>nums2.size()){
            numsA=nums2;
            numsB=nums1;
        }else {
            numsA=nums1;
            numsB=nums2;
        }
        int lenA=numsA.size(),lenB=numsB.size();
        int low=0,high=lenA,a,b;
        while(low<=high){
            a=(low+high)/2;
            b=(lenA+lenB+1)/2-a;
           if(a>0 &&numsA[a-1]>numsB[b]){
               high=a-1;
           }else if(a<lenA && numsA[a]<numsB[b-1]){
               low=a+1;
           }else {
               int maxLeft,minRight;
               if(a==0) maxLeft=numsB[b-1];
               else if(b==0) maxLeft=numsA[a-1];
               else maxLeft= max(numsA[a-1],numsB[b-1]);
               
               if(a==lenA) minRight=numsB[b];
               else if(b==lenB) minRight=numsA[a];
               else minRight= min(numsA[a],numsB[b]);
              
               if((lenA+lenB)%2==0) return (maxLeft+minRight)/2.0;
               else return maxLeft;
           }
        }
    }
};
