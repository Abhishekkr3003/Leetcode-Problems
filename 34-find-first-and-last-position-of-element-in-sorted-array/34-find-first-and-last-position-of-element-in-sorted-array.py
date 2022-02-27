class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        lo,hi=0,len(nums)-1
        res=[-1,-1]
        while lo<=hi:
            mid=lo+((hi-lo)>>1);
            if nums[mid]==target:
                res[0]=mid
                hi=mid-1
            elif nums[mid]>target:
                hi=mid-1
            else:
                lo=mid+1
        lo,hi=0,len(nums)-1
        while lo<=hi:
            mid=lo+((hi-lo)>>1);
            if nums[mid]==target:
                res[1]=mid
                lo=mid+1
            elif nums[mid]>target:
                hi=mid-1
            else:
                lo=mid+1
        return res
        