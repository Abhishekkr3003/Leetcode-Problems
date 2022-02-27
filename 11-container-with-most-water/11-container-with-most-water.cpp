class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_=0;
        int beg=0, end=height.size()-1;
        while(end>beg)
        {
            max_=max(max_, min(height[beg], height[end])*(end-beg));
            height[beg]>height[end]?end-=1:beg+=1;
        }
        return max_;
    }
};