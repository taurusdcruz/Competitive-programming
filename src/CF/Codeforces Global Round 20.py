
from collections import defaultdict as dd
# def score(ch):
#     return ord(ch)-ord('a') + 1
# def solve():
#     s=input()
#     l=len(s)
#     player={0:"Alice",1:"Bob"}
#     scoreAlice,scoreBob=0,0
#     scoree= lambda s: sum([ score(ch) for ch in s])
#     iwinner=None
#     if(l%2==0):
#         iwinner=0
#         scoreAlice=scoree(s)
#     else:
#         if(l==1):
#             iwinner=1
#             scoreBob=scoree(s)
#         else:
#             iwinner=0          
#             scoreAlice=max(scoree(s[1:]),scoree(s[:-1]))
#             scoreBob = min(score(s[0]),score(s[-1]))
        
#     return "{} {}".format(player[iwinner],abs(scoreBob-scoreAlice))
#     pass

        
def solve():
    s=input()
    cnt = dd(lambda:0)
    ok=True
    if(len(s)>2):
        for i,ch in enumerate(s):
            cnt[ch]+=1
        if(len(cnt.keys())>1):
            if(len(s)==3):
                if(s[0]!=s[-1]):
                    ok=False
            else:
                ok=False
            pch=""        
    return "yes" if(ok)else "no"
for iT in range(int(input())):
    print(solve())

