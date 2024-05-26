import random, time
def miller_rabin(n, k=5):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0:
        return False
    r, d = 0, n - 1
    while d % 2 == 0:
        d //= 2
        r += 1
    def check_composite(a, d, n, r):
        x = pow(a, d, n)
        if x == 1 or x == n - 1:
            return False
        for _ in range(r - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                return False
        return True
    for _ in range(k):
        a = random.randint(2, n - 2)
        if check_composite(a, d, n, r):
            return False
    return True

st = time.time()
maxn = int(1e7+1)
cn = 0
for i in range(1,maxn):
    cn += 1 if miller_rabin(i) else 0
et= time.time()
print(f"{et-st} secs. {cn} primes")
assert cn == 664579
