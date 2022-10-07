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
    N= inputI()
    TREES = [inputArrI() for _ in range(N)]
    Q= inputI()
    POINTS = [inputArrI() for _ in range(Q)]
    A = [pt[0] for pt in TREES]
    B = [pt[1] for pt in TREES]

    '''
    Helpers - start
    '''
    def mod(x):
        return x % MOD

    def mod_add(x, y):
        x, y = map(mod, [x, y])
        return mod(x+y)

    def mod_mul(x, y):
        x, y = map(mod, [x, y])
        return mod(x*y)

    def mod_reduce(func_reduce, func_transform_sequence, sequence, initial_val):
        return FT.reduce(
            lambda val_reduced, val: mod(func_reduce(val_reduced, val)),
            map(lambda x: mod(func_transform_sequence(x)), sequence),
            initial_val
        )

    def func_inconvenience(pt):
        x, y = map(mod, pt)
        return mod(x*x + y*y)

    '''
    Helpers - end
    '''

    C0 = mod_reduce(
        OP.add,
        func_inconvenience,
        TREES,
        0
    )
    C1 = mod_reduce(
        OP.add,
        lambda x: mod_mul(-2, x),
        A,
        0
    )
    C2 = mod_reduce(
        OP.add,
        lambda x: mod_mul(-2, x),
        B,
        0
    )

    def func_inconvenience_from_xy(pt):
        xi, yi = map(mod, pt)
        res = mod(
            C0
            + mod_mul(C1, xi)
            + mod_mul(C2, yi)
            + mod_mul(
                N,
                mod_add(
                    mod_mul(xi, xi),
                    mod_mul(yi, yi)
                )
            )
        )
        return res
    res = mod_reduce(
        OP.add,
        func_inconvenience_from_xy,
        POINTS,
        0
    )
    print("Case #{}: {}".format(t+1, res))


T = inputI()
for t in range(T):
    solve(t)
