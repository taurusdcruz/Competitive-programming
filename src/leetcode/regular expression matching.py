import copy
class Solution:
    A2Z='abcdefghijklmnopqrstuvwxyz'
    def isMatch(self, s: str, p: str) -> bool:
        s_encoded=Solution.encode(s)#encoding s
        return self.isMatch1(s_encoded,p)
    
    def isMatch1(self, s: str, p: str) -> bool:
        s=copy.deepcopy(s)
        if(len(p)==1 ):
            return (len(s)==1 and s[0][1]==1) and (p[0]=='.' or (p[0]==s[0][0]))
        if(len(p)==0):
            return (len(s)==0 ) or ((len(s)==1) and s[0][1]==0)
        if(len(s)==0):
            i_p=1
            while(i_p<len(p)):

                if(p[i_p] !='*'):
                    return False
                i_p+=2
            return len(p)%2==0
        i_s,i_p=0,0
        p_ch=p[i_p]
        p_ch1=p[i_p+1]
        s_ch,s_cnt=s[i_s]
        
        is_char=p_ch in Solution.A2Z 
        is_dot=(p_ch=='.')

        if(p_ch1 != '*'):
            #single char/dot
            if(( is_char and p_ch==s_ch) or is_dot ):  
                s[i_s][1]+=-1

                return self.isMatch1(s[i_s +(1 if(s[i_s][1]==0)else 0):],p[i_p+1:])
        elif(p_ch1 =='*'):
            #dot/char with *
            if((is_char and p_ch==s_ch) or is_dot):                    
                flg_one_exists=False
                while(not flg_one_exists):
                    if(i_s<len(s)):
                        if(s[i_s][1]>=0):
                            flg_one_exists=flg_one_exists or self.isMatch1(s[i_s +(1 if(s[i_s][1]==0)else 0):],p[i_p+2:])
                            s[i_s][1]+=-1
                        else:
                            if(p_ch=='.'):
                                i_s+=1
                                #Note:i dont need to update p_ch,s_ch
                            elif((is_char and p_ch==s_ch)):
                                break
                    else:
                        break
                return flg_one_exists
            else:
                return self.isMatch1(s,p[i_p+2:])
                
    @staticmethod
    def encode(s):
        vencoded=[]
        for ch in s:
            if( len(vencoded)==0 or vencoded[-1][0]!=ch):
                vencoded.append([ch,1])
            else:
                vencoded[-1][1]+=1
        return vencoded

print(Solution().isMatch("abba",".*..."))

            
        