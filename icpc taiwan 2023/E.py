import sys
sys.setrecursionlimit(2000)

memo = {}

def f(x, a, m):
    if x == 0:
        return 2 % m
    
    if x in memo:
        return memo[x]
    
    if x % 2 == 0:
        val = f(x // 2, a, m)
        res = (val * val - 2) % m
    else:
        val1 = f(x // 2, a, m)
        val2 = f((x + 1) // 2, a, m)
        res = (val1 * val2 - a) % m
        
    memo[x] = res
    return res

def solve():
    input_data = sys.stdin.read().split()
    
    if not input_data:
        return

    iterator = iter(input_data)
    try:
        a = int(next(iterator))
        b = int(next(iterator))
        m = int(next(iterator))
    except StopIteration:
        return

    if m == 1:
        print(0)
        return

    memo.clear()
    a %= m
    memo[1] = a

    res_2 = (a * a - 2) % m
    memo[2] = res_2
    print(f(b, a, m))

if __name__ == '__main__':
    solve()