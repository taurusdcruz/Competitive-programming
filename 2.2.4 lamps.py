"""
ID: taurusd1
LANG: PYTHON3
TASK: lamps
CONCEPTS:   1.Comparing specific places of two binary numbers using bit masks
            2.Toggling specific places of a binary number using XOR operation with appropriate binary number
1.
Let _bino_1_,_bino_2_ be binary numbers.
Create a mask(_m_) with 1's in places which you want to compare the bits for equality.
compare specific places by using expression:
    (_bino_1_ & _m_ == _bino_2_ & _m_)

2.
Let _bino_ be a binary number which you want to toggle the bits of.
Create a mask(_m_) with 1's in places which you want to toggle the bits of _bino_.
_bino_toggled = _bino_ ^ _m_
"""
import math
import sys
import os

from functools import reduce

"""

"""

"""Getting filename and asssigning it to task"""
# filename = os.path.basename(sys.argv[0])
# filename_wo_extension = os.path.splitext(filename)[0]
# last_word_of_filename=filename_wo_extension.split(' ')[-1]
# task = last_word_of_filename#Assuming: task is last word of filename
#-----------------------------------------(but the judge changes the filename:C So no point !)
task = 'lamps'
path = ''
# path = 'Z:\\'
task = path+task
# input
class solver:
    #static variables

    #constructor
    def open_files(self,prob_name):
        self.fin = open(prob_name+'.in', 'r')
        self.fout = open(prob_name+'.out', 'w+')
    def close_files(self):
        self.fin.close()
        self.fout.close()
class lamps_solver(solver):
    def __init__(self,prob_name):
        self.prob_name = prob_name
    
    def read(self):
        self.fin.seek(0)
        self.N=int(self.fin.readline().strip())
        self.C=int(self.fin.readline().strip())
        self.final_on=list(map(int,self.fin.readline().split()))[:-1]
        self.final_off=list(map(int,self.fin.readline().split()))[:-1]

        

    def write(self):
        pass

    def solve(self):
        #open files
        self.open_files(self.prob_name)

        #read input
        self.read()
        
        #logic for solving problem

        #initial validation(pattern repeats after six places)
        #since it is valid we only need to generate the first six places
        self.final=''
        vis_val=[[False,'.'] for i in range(0,6)]
        for i in range(0,len(self.final_on)):
            j=self.final_on[i]-1#zero based indexing
            vis,val=vis_val[j%6]
            if(vis and not(val == '1')):
                print('IMPOSSIBLE',file=self.fout)
                return
            elif(not(vis)):
                vis_val[j%6]=[True,'1']
        for i in range(0,len(self.final_off)):
            j=self.final_off[i]-1#zero based indexing
            vis,val=vis_val[j%6]
            if(vis and not(val == '0')):
                print('IMPOSSIBLE',file=self.fout)
                return
            elif(not(vis)):
                vis_val[j%6]=[True,'0']
        self.final=[ vis_val[i][1] for i in range(0,6) ]

        self.final1=0
        #computing mask for considering only specific bits and making the remaining zero
        mask=0
        for i in range(0,6):
            curr_bit=self.final[::-1][i]
            if(curr_bit!='.'):
                mask+= 1<<i
                if(curr_bit=='1'):
                    self.final1+= 1<<i

        res=[False for i in range(0,64)]
        curr_config=63
        cnt_limit=self.C
        tk,t2kp1,t2k,t3kp1=int('111111',2),int('101010',2),int('10101',2),int('100100',2)
        #https://www.geeksforgeeks.org/for-every-set-bit-of-a-number-toggle-bits-of-other/
        cnt=0
        res[63]=True
        while(cnt<cnt_limit):
            tmp=[False for i in range(0,64)]
            j=0
            while(j<64):
                if( res[j]):
                    l=(j ^ tk,j ^ t2kp1,j ^ t2k,j ^ t3kp1)
                    tmp[j ^ tk]=True
                    tmp[j ^ t2kp1]=True
                    tmp[j ^ t2k]=True
                    tmp[j ^ t3kp1]=True
                j+=1
            res=tmp
            cnt+=1
        # precompute(curr_config,vis,res,res1,cnt,cnt_limit,mask,self.final1,path)
        flg_impossible=True
        for i in range(0,len(res)):
            res[i]= res[i] and ( (mask & i) == (mask & self.final1) )
            if(res[i]):
                flg_impossible=False
                tmp=''
                k=self.N//6
                while(k>=0):
                    tmp+=format(i,'06b')                    
                    k+=-1
                tmp=tmp[:self.N]
                print(tmp,file=self.fout)
        if flg_impossible:
            print('IMPOSSIBLE',file=self.fout)
        #close files
        self.close_files()

def str_replace_at(s,i,replaced_char):
    if(i < len(s)):
        return s[:i]+replaced_char+s[i+1:]
lamps_solver(task).solve()

