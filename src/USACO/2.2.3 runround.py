"""
ID: taurusd1
LANG: PYTHON3
TASK: runround
CONCEPTS: Getting next unique digit number( See function get_next_unique_digit_no(n,dig_used))
"""
import math
import sys
import os

from functools import reduce

"""Getting filename and asssigning it to task"""
# filename = os.path.basename(sys.argv[0])
# filename_wo_extension = os.path.splitext(filename)[0]
# last_word_of_filename=filename_wo_extension.split(' ')[-1]
# task = last_word_of_filename#Assuming: task is last word of filename
#-----------------------------------------(but the judge changes the filename:C So no point !)
task = 'runround'
path = ''
# path = 'Z:\\'
task = path+task
# input
class solver:
    #static variables

    #constructor
    def open_files(self,prob_name):
        self.fin = open(prob_name+'.in', 'r')
        self.fout = open(prob_name+'.out', 'w')
    def close_files(self):
        self.fin.close()
        self.fout.close()
class runround_solver(solver):
    def __init__(self,prob_name):
        self.prob_name = prob_name
    
    def read(self):
        self.N= int(self.fin.readline().strip())
        
        pass
    def write(self):
        pass

    def solve(self):
        #open files
        self.open_files(self.prob_name)

        #read input
        self.read()
        
        #logic for solving problem
        self.N+=1
        no_digits= math.ceil(math.log10(self.N))
        dig_used=[0 for i in range(0,10)]

        #checking if number has unique digits
        curr_place=no_digits-1#L -> R scanning
        while(curr_place>=0):
            curr_dig=get_dig_at(self.N,curr_place)
            if(dig_used[curr_dig] == 0 ):
                dig_used[curr_dig]+=1
            else:
                curr_dig1=curr_dig+1
                while(curr_dig1<10 and dig_used[curr_dig1]!=0):
                    curr_dig1+=1
                lds,cd,rds=shift_right(self.N,curr_place+1),curr_dig1,(self.N%int(10**(curr_place)))
                self.N=lds*10**(curr_place+1)+cd*10**(curr_place)+rds
                curr_dig=curr_dig1
                if(curr_dig1 == 10):
                    #not possible to get unique digits greater than given number
                    break
            curr_place+=-1                

        #iterate over consecutive unique-digit numbers and check for runround condition
        while(True):
            if(self.N>98765432):
                return -1
            elif(is_runround(self.N)):
                print(self.N,file=self.fout)
                return 
            else:
                self.N=get_next_unique_digit_no(self.N,dig_used)#dig_used modified by function
                print(self.N," is"+ (""if(is_runround(self.N))else "'nt")+" a runround no")

        #close files
        self.close_files()


def is_runround(n):
    no_digits= math.ceil(math.log10(n))
    vis_cnt=[0 for i in range(0,10)]#1623
    cnt_dig_visited=0
    curr_place=no_digits-1
    curr_dig=get_dig_at(n,curr_place)
    while(vis_cnt[curr_dig] == 0 ):
        vis_cnt[curr_dig]+=1
        curr_place= no_digits-1 - ((no_digits-1-curr_place) +curr_dig)%no_digits
        curr_dig=get_dig_at(n,curr_place)
        cnt_dig_visited+=1
    if( cnt_dig_visited == no_digits and curr_place==no_digits-1):
        return True
    else:
        return False

def get_dig_at(n,curr_place):
    return int(n//10**curr_place)%10 # precedence: (**) > (//,%)

def shift_right(n,curr_place):
    return int(n//10**curr_place)

def get_next_unique_digit_no(n ,dig_used):
    #Assuming:
    #A1-n is a unique digit number
    #A2-n has <= 9 digits

    no_digits= math.ceil(math.log10(n))
    if(no_digits>9):
        return -1
    #init dig_used

    #scan number R -> L
    #if there is no digit >curr_dig then return -1
    curr_place=0
    #vvv Using assumption A1 => max power of 10 allowed is 8
    while(curr_place<9):#<<< while-else loop                
        curr_dig=get_dig_at(n,curr_place)
        dig_used[curr_dig]=0 #<<< mark curr_dig as unused
        #vvv curr_dig range[get_dig_at(n,curr_place) +1,9]
        curr_dig+=1
        while(curr_dig<10):#<<< while-else loop
            if(dig_used[curr_dig] == 0):                        
                dig_used[curr_dig]+=1 #<<< mark curr_dig as used
                #lds - cd - (rds formed in ascending order of available digits)
                #calculating rds
                rds=0
                curr_place1=curr_place-1 
                curr_dig1=1 #<<< zero as a digit can never give a runround number
                while(curr_place1>=0 and curr_dig1<10):
                    if(dig_used[curr_dig1] == 0):
                        rds=rds*10+curr_dig1 #precedence: (*) > (+)
                        curr_place1+= -1
                    curr_dig1+=1
                #if rds possible to be formed out of available digits
                if(curr_place1== -1):
                    return (  shift_right(n,(curr_place+1)) * 10**(curr_place+1) 
                            + curr_dig * 10**(curr_place) 
                            + rds
                            )
            else:
                dig_used[curr_dig]=0 #<<< mark curr_dig as un-used
                curr_dig+=1
        else:
            curr_place+=1
            #mark digits in rds as unused and digits of lds as used
            dig_used=[0 for i in range(0,10)]
            no_digits= math.ceil(math.log10(n))
            curr_place1=no_digits-1
            while(curr_place1>=curr_place):
                curr_dig1= get_dig_at(n,curr_place1)
                dig_used[curr_dig1]+=1
                curr_place1+=-1
            n = shift_right(n,curr_place)*10**(curr_place)
    else:                
        return -1


runround_solver(task).solve()