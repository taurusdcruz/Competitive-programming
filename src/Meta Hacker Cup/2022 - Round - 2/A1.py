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


def min_excluding_none(*args):
    filtered_args = filter(lambda x: x is not None, args)
    res = min(filtered_args, default=None)
    return res


def solve(t):
    S = input()
    Q = in_int()
    cnt = dd(lambda: dd(lambda: 0))
    L = [None for _ in range(Q)]
    R = [None for _ in range(Q)]
    for i in range(Q):
        L[i], R[i] = map(int, input().split())
        L[i] += -1
        R[i] += -1

    def get_cnt_range(l, r):
        cnt1 = dd(lambda: 0)
        for ch in cnt[r]:
            cnt1[ch] = cnt[r][ch] - cnt[l - 1][ch]
        return cnt1

    def diff_cnt(cnt_l, cnt_r):
        keys = set(cnt_l.keys()) | set(cnt_r.keys())
        cnt1 = dd(lambda: 0)
        for key in keys:
            delta = cnt_r[key] - cnt_l[key]
            if delta != 0:
                cnt1[key] = delta
        return cnt1

    def differ_by_one_char(cnt_diff):
        keys = list(cnt_diff.keys())
        if len(keys) == 1:
            if abs(cnt_diff[keys[0]]) == 1:
                return True
        return False

    def is_almost_perfectly_balanced(l, r):
        if l == r:
            return True
        s = S[l : r + 1]
        mid = (l + r) // 2
        if len(s) % 2 == 1:
            cnt_l1 = get_cnt_range(l, mid)
            cnt_r1 = get_cnt_range(mid + 1, r)
            cnt_diff_lr1 = diff_cnt(cnt_l1, cnt_r1)
            ok = differ_by_one_char(cnt_diff_lr1)
            if ok:
                return True
            cnt_l2 = get_cnt_range(l, mid - 1)
            cnt_r2 = get_cnt_range(mid, r)
            cnt_diff_lr2 = diff_cnt(cnt_l2, cnt_r2)
            ok = differ_by_one_char(cnt_diff_lr2)
            if ok:
                return True
        return False

    for i in range(len(S)):
        ch = S[i]
        if i == 0:
            cnt[i][ch] += 1
        else:
            cnt[i] = cnt[i - 1].copy()
            cnt[i][ch] += 1
    res = 0
    for i in range(Q):
        if is_almost_perfectly_balanced(L[i], R[i]):
            res += 1

    print("Case #{}: {}".format(t + 1, res))


T = in_int()
for t in range(T):
    solve(t)
