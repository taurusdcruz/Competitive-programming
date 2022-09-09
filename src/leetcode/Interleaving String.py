class Solution:
    
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        global found_res,stored_res
        found_res=[[False for i2 in range(0,len(s2)+1)] for i1 in range(0,len(s1)+1)]
        stored_res=[[-1 for i2 in range(0,len(s2)+1)] for i1 in range(0,len(s1)+1)]
        return iI(s1,s2,s3,0,0,0)

found_res=stored_res=None
#is it possible to 
def iI(s1,s2,s3,i1,i2,i3) -> bool:
    global found_res,stored_res
    if(i1>=len(s1)):
        return s3[i3:]==s2[i2:]
    if(i2>=len(s2)):
        return s3[i3:]==s1[i1:]
    if(i3>=len(s3)):
        return (i1>=len(s1)) and (i2>=len(s2))
    if(found_res[i1][i2]):
        return stored_res[i1][i2]
    else:            
        f13=s1[i1]==s3[i3]
        f12=s2[i2]==s3[i3]
        res=False
        if(f13):                
            stored_res[i1+1][i2]=iI(s1,s2,s3,i1+1,i2,i3+1)
            found_res[i1+1][i2]=True
            res=res or stored_res[i1+1][i2]
            
        if(f12):
            stored_res[i1][i2+1]=iI(s1,s2,s3,i1,i2+1,i3+1)
            found_res[i1][i2+1]=True
            res=res or stored_res[i1][i2+1]
        
        return res
s1="aabaac"
s2="aadaaeaaf"
s3="aadaaeaabaafaac"
print(Solution().isInterleave(s1,s2,s3))
    
        
            