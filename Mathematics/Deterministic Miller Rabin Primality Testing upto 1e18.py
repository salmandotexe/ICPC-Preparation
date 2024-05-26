import time
def is_prime(n):
    """Returns True if n is a prime number, else False."""
    if n < 2:
        return False
    if n in (2, 3):
        return True
    if n % 2 == 0:
        return False

    def check_composite(a, d, n, s):
        x = pow(a, d, n)
        if x == 1 or x == n - 1:
            return False
        for _ in range(s - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                return False
        return True

    # Write (n - 1) as d * 2^s
    d, s = n - 1, 0
    while d % 2 == 0:
        d //= 2
        s += 1

    bases = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]
    for a in bases:
        if a % n == 0:
            continue
        if check_composite(a, d, n, s):
            return False
    return True

def test_miller_rabin():
    fermat_liars = [
        561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341,
        41041, 46657, 52633, 62745, 63973, 75361, 101101, 115921, 126217,
        162401, 172081, 188461, 252601, 278545, 294409, 314821, 334153,
        340561, 399001, 410041, 449065, 488881, 512461, 530881, 552721,
        656601, 658801, 670033, 748657, 838201, 852841, 997633, 1024651,
        1033669, 1066033, 1082809, 1152271, 1193221, 1461241
    ]

    for liar in fermat_liars:
        assert not is_prime(liar), f"Test failed for composite number {liar}"

    print("All tests passed!")

st = time.time()

maxn, cn = int(1e7+1), 0
for i in range(1,maxn):
    cn += 1 if is_prime(i) else 0
et = time.time()
print(f"{et-st} secs. {cn} primes")
assert cn == 664579
test_miller_rabin()
