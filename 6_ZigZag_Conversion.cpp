/*
水题。。。
18ms
Your runtime beats 87.85% of cpp submissions
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1) return s;
        vector<string> a(numRows,"");
    	int cnt=0,len=s.length(),d,y=0;
    	while(cnt<len){
	    	a[y]+=s[cnt++];
	    	if(y>=numRows-1)d=-1;
		    if(y<=0)d=1;
	    	y+=d;
    	}
	    string rs="";
    	for(int i=0;i<numRows;i++){
	    	rs+=a[i];
	    }
    	return rs;
    }
};