import bisect
import sys
sys.setrecursionlimit(1000)
class Solution:
    def findMedianSortedArrays(self, nums1, nums2) -> float:
        if(len(nums1)==0):
            return (nums2[(len(nums2)+1)//2-1] +nums2[(len(nums2)+2)//2-1])/2
        elif(len(nums2)==0):
            return (nums1[(len(nums1)+1)//2-1] +nums1[(len(nums1)+2)//2-1])/2
     
        if((len(nums1)+len(nums2))%2==0):
            flg_min=nums1[0]<nums2[0]
            flg_max=nums1[-1]>nums2[-1]
            l=r=None
            n1=nums1[(1 if(flg_min)else 0):]
            n2=nums2[(0 if(flg_min)else 1):]
            r=self.FMSA(n1,n2,0,len(n1)-1,0,len(n2)-1)
            n1=nums1[:len(nums1)-(1 if(flg_max)else 0)]
            n2=nums2[:len(nums2)-(0 if(flg_max)else 1)]
            l=self.FMSA(n1,n2,0,len(n1)-1,0,len(n2)-1)
            return (l+r)/2
        else:
            return self.FMSA(nums1,nums2,0,len(nums1)-1,0,len(nums2)-1)
                
                
    def FMSA(self, nums1, nums2, l1,r1,l2,r2) -> float:
        #assumption:always (len(nums1)+len(nums2))%2==1
        while(True):
            if(len(nums1)==0):
                return (nums2[(len(nums2)+1)//2-1] +nums2[(len(nums2)+2)//2-1])/2
            elif(len(nums2)==0):
                return (nums1[(len(nums1)+1)//2-1] +nums1[(len(nums1)+2)//2-1])/2
            len1,len2=len(nums1),len(nums2)
            mid1,mid2=(l1+r1)//2,(l2+r2)//2  
            if(l1<=r1):
                val1=nums1[mid1]
                indx2l=bisect.bisect_left(nums2,val1)
                indx2r=bisect.bisect_right(nums2,val1)
                cnt_right1l=(len1-1-mid1) + (len2-indx2l)
                cnt_right1r=(len1-1-mid1) + (len2-indx2r)                
                delta1l=cnt_right1l-((len1+len2)//2)
                delta1r=cnt_right1r-((len1+len2)//2)    
                if(delta1l>=0 and delta1r<=0):
                    return val1            
                elif(delta1l>0):
                    l1=mid1+1
                elif(delta1l<0):
                    r1=mid1-1
            
            if(l2<=r2):
                val2=nums2[mid2]
                indx1l=bisect.bisect_left(nums1,val2)
                cnt_right2l=(len1-indx1l) + (len2-1-mid2)
                delta2l=cnt_right2l-((len1+len2)//2)
                indx1r=bisect.bisect_right(nums1,val2)
                cnt_right2r=(len1-indx1r) + (len2-1-mid2)
                delta2r=cnt_right2r-((len1+len2)//2)
                if(delta2l>=0 and delta2r<=0):
                    return val2
                elif(delta2l>0):
                    l2=mid2+1
                elif(delta2l<0):
                    r2=mid2-1

                 
print(Solution().findMedianSortedArrays([2,3,4],[1]))