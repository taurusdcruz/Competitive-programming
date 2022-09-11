# import collections as CL
import functools as FT
import operator as OP
MOD = int(1e9+7)


def exists(x):
    return x is not None


def inputI():
    return int(input())


def inputArrI():
    return list(map(int, input().split()))


def solve(t):
    N, K = inputArrI()
    A = inputArrI()
    B = inputArrI()

    '''
    Helpers - start
    '''
    def get_value_from_arr(index, shift, array, N):
        shifted_index = (index + shift + N) % N
        return array[shifted_index]

    def equal_arrays(A1, A2, shift):
        N = len(A1)
        ok = len(A1) == len(A2)
        if (ok):
            for i in range(N):
                if (get_value_from_arr(i, shift, A1, N) != A2[i]):
                    ok = False
                    break
        return ok

    def cyclically_equal(A1, A2):
        N = len(A1)
        ok = len(A1) == len(A2)
        if (ok):
            ok1 = False
            for i in range(N):
                if (equal_arrays(A1, A2, i)):
                    ok1 = True
                    break
            ok = ok and ok1
        return ok
    '''
    Helpers - end
    '''
    ok = True
    if (K == 0):
        ok = ok and equal_arrays(A, B, 0)
    elif (K == 1):
        ok = ok and (not equal_arrays(A, B, 0)) and cyclically_equal(A, B)
        ok = ok or equal_arrays(A, B, 1)
    elif (K >= 2):
        if (N == 2):
            if (K % 2 == 0):
                ok = ok and equal_arrays(A, B, 0)
            else:
                ok = ok and equal_arrays(A, B, 1)
        else:
            ok = ok and cyclically_equal(A, B)
    res = "YES" if (ok) else "NO"
    print("Case #{}: {}".format(t+1, res))


T = inputI()
for t in range(T):
    solve(t)
