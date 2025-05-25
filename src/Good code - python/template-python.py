import sys
import functools as FT
import itertools as IT
import operator as OP
import bisect as BSCT
import collections as CLLN
import heapq as HPQ

sys.setrecursionlimit(10**6)
dd = CLLN.defaultdict
bl = BSCT.bisect_left
br = BSCT.bisect_right

MOD = int(1e9 + 7)
def log(func):
    _d = 0
    @FT.wraps(func)
    def wrapper(*args, **kwargs):
        nonlocal _d
        _d+=1
        indent = "".join(["-|" for i in range(_d)])
        pref = (indent, args)
        print(*pref)
        res = func(*args, **kwargs)
        print(*pref, res)
        _d+=-1
        return res
    return wrapper

def is_bit_set(N, i):
    return (N >> i) & 1

def set_bit(N, i):
    return N | (1 << i)

def exists(x):
    return x is not None


def in_int():
    return int(input())


def in_arr_int():
    return list(map(int, input().split()))


def args_not_none(*args):
    return filter(lambda x: x is not None, args)


def min_excluding_none(*args):
    res = min(args_not_none(args), default=None)
    return res


def solve(t):
    res = None
    print("Case #{}: {}".format(t + 1, res))


T = int(input())
for t in range(T):
    try:
        solve(t)
    except Exception as e:
        print(e)
