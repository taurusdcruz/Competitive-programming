import sys
import functools as _ft
import itertools as _it
import operator as _op
import bisect as _bsct
import collections as _cllctn
import heapq as _hpq

sys.setrecursionlimit(10**6)
dd = _cllctn.defaultdict
bl = _bsct.bisect_left
br = _bsct.bisect_right

MOD = int(1e9 + 7)
DONT_LOG = 0


def log(level=0):
    prefix = "-".join(["|" for _ in range(level)])
    return lambda *args: None if (DONT_LOG) else print(prefix, *args)


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
