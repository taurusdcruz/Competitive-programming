"""
Problem : https://leetcode.com/problems/parallel-courses/
"""
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


class Solution:
    def minimumSemesters(self, n, rel):
        e_wt_dir = dd(lambda: dd(lambda: None))
        e_wt_undir = dd(lambda: dd(lambda: None))
        for prev, curr in rel:
            e_wt_dir[curr][prev] = "unweighted"
            e_wt_undir[curr][prev] = "unweighted"
            e_wt_undir[prev][curr] = "unweighted"
        v_set = set(e_wt_undir.keys())
        dfs_node_state = {"un-processed": 0, "processing": 1, "processed": 2}

        def find_longest_path(v_set, e_wt_dir):
            v_vis = dd(lambda: dfs_node_state["un-processed"])
            longest_path = None
            is_cycle = False
            mmz = dd(lambda: None)  # memoize processed node in graph

            def dfs(v_i):
                nonlocal is_cycle
                longest_path = None
                if v_i is not None:
                    if v_vis[v_i] == dfs_node_state["processed"]:
                        return mmz[v_i]
                    if v_vis[v_i] == dfs_node_state["processing"]:
                        is_cycle = True
                    if not is_cycle:
                        if v_vis[v_i] == dfs_node_state["un-processed"]:
                            v_vis[v_i] = dfs_node_state["processing"]
                            for v_j in e_wt_dir[v_i]:
                                longest_path1 = dfs(v_j)
                                if longest_path1 is not None:
                                    longest_path = max(
                                        args_not_none(longest_path, longest_path1 + 1)
                                    )
                            v_vis[v_i] = dfs_node_state["processed"]
                    if longest_path is None:
                        longest_path = 1
                mmz[v_i] = longest_path
                return longest_path

            for v in v_set:
                if v_vis[v] == dfs_node_state["un-processed"]:
                    v_vis = dd(lambda: dfs_node_state["un-processed"])
                    longest_path1 = dfs(v)
                    if is_cycle:
                        longest_path = None
                        break
                    if longest_path1 is not None:
                        longest_path = max(args_not_none(longest_path, longest_path1))
            return longest_path, is_cycle

        longest_path, is_cycle = find_longest_path(v_set, e_wt_dir)
        return -1 if (is_cycle) else longest_path


tests = [
    [3, [[1, 3], [2, 3]]],
]

for test in tests:
    Solution().minimumSemesters(*test)
