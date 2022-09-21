
'''
Contest link: https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb409
About : This file contains solutions for problem - A, B
'''
import sys
import functools as FT
import itertools as IT
import operator as OP
import bisect as BSCT
import collections as CLLCTN
sys.setrecursionlimit(10**6)
dd = CLLCTN.defaultdict
bl = BSCT.bisect_left
br = BSCT.bisect_right
 

def solveA(t):
    res = None
    N = int(input())
    C = [None for i in range(N)]
    D = [None for i in range(N)]
    U = [None for i in range(N)]
    for i in range(N):
        C[i], D[i], U[i] = input().split()
        D[i], U[i] = map(int, [D[i], U[i]])
    items1 = sorted(range(N), key=lambda x: (C[x], U[x]))
    items2 = sorted(range(N), key=lambda x: (D[x], U[x]))
    res = len(list(filter(lambda x: items1[x] == items2[x], range(N))))
    print("Case #{}: {}".format(t+1, res))


def solveB(t):
    res = None
    N, Q = map(int, input().split())
    e_wt = dd(lambda: dd(lambda: None))
    v_vis = dd(lambda: False)
    for i in range(N-1):
        containeri, containerj = map(int, input().split())
        e_wt[containeri][containerj] = 0
        e_wt[containerj][containeri] = 0
    row_nodes_count_by_level = dd(lambda: None)
    queries = [None for i in range(Q)]
    for i in range(Q):
        queries[i] = int(input())

    def bfs(parent_nodes, level=0):
        row_nodes = []
        for iparent_node in parent_nodes:
            v_vis[iparent_node] = True
        if (len(parent_nodes) > 0):
            for iparent_node in parent_nodes:
                new_row_nodes = list(
                    filter(lambda x: not v_vis[x], e_wt[iparent_node].keys()))
                if (len(new_row_nodes)):
                    row_nodes.extend(new_row_nodes)

            row_nodes_count_by_level[level+1] = len(row_nodes)
            bfs(row_nodes, level=level+1)
    row_nodes_count_by_level[0] = 1
    bfs([1])
    row_node_count = [
        x[1] for x in sorted(
            row_nodes_count_by_level.items(),
            key=lambda x: x[0]
        )
    ]
    cumulative_capacity = list(IT.accumulate(row_node_count, OP.add))
    ires = br(cumulative_capacity, Q) - 1
    if (ires == -1):
        res = 0
    else:
        res = cumulative_capacity[ires]
    print("Case #{}: {}".format(t+1, res))

def solve(t)
    print("Case #{}: {}".format(t+1, res))

T = int(input())
for t in range(T):
    try:
        solve(t)
    except Exception as e:
        print(e)
