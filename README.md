# 🔢 Number Theory Problem Collection: Beginner to Advanced 🚀

Welcome to the **Number Theory Problem Collection**! This repository contains a curated list of number theory problems, ranging from beginner-friendly tasks to advanced-level competitive programming challenges.

Whether you're a student, a CP enthusiast, or preparing for coding interviews, these problems will help sharpen your understanding of number theory fundamentals and techniques.

---

# 📚 Table of Contents

- [👒 Modular Arithmetic](#modular-arithmetic)
- [🧮 Greatest Common Divisor](#greatest-common-divisor)
- [🧠 Prime Numbers](#prime-numbers)
- [✨ Modular Exponentiation](#modular-exponentiation)
- [🎵 Matrix Exponentiation](#matrix-exponentiation)
- [🔐Fermat's Little Theorem](#fermats-little-theorem)
- [🐚 Wilson's Theorem](#wilsons-theorem)
- [🎨Euler's Totient Function](#eulers-totient-function)
- [💎 Practise Problems](#practise-problems)


---

# 👒Modular Arithmetic

Modular arithmetic is a system where numbers "wrap around" after reaching a certain value M. It's widely used in competitive programming to keep numbers within bounds.

```
(a + b) % M = (a%M + b%M)%M
(a - b) % M = (a - b + M) % M
(a*b)%M = (((ll)a%M)*(b%M))%M
(a/b)%M = ((a%M)* bInv)%M - where bInv is multiplicative modulo inverse of b wrt M.

```

---

# 🧮Greatest Common Divisor

> The GCD of two numbers is the largest positive number that divides both the numbers.

## Euclid's Division Lemma

```
int GCD(int A, int B) {
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}

```

> 🧠 The time complexity is O(log(max(A, B))).


## Extended Euclidean Algorithm

```
int d, x, y;
void extendedEuclid(int A, int B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

```

## Modular multiplicative inverse

```
int d,x,y;
int modInverse(int A, int M)
{
    extendedEuclid(A,M);
    return (x%M+M)%M;  
}

```

> 🧠 A and M have to Co-Primes.

---

# 🚁Prime Numbers

> Prime numbers are those numbers that have only two factors 1 and itself.

## Prime Check

```

void checkprime(int N) {
        int count = 0;
        for( int i = 1;i * i <=N;++i ) {
             if( N % i == 0) {
                 if( i * i == N )
                         count++;
                 else       // i < sqrt(N) and (N / i) > sqrt(N)
                         count += 2;
              }
        }
        if(count == 2) cout << "Prime Number" << endl;
   }

```

## Sieve of Eratosthenes

You can use the Sieve of Eratosthenes to find all the prime numbers in a given Range.

```
void buildSieve(int N) {

        int isPrime[N+1];
        for(int i = 0; i <= N;++i) {
            isPrime[i] = 1;
        }
        isPrime[0] = 0;
        isPrime[1] = 0;
        for(int i = 2; i * i <= N; ++i) {
             if(isPrime[i]) {               
                 for(int j = i * i; j <= N ;j += i)
                     isPrime[j] = 0;
            }
        }
    }

```

> 🧠 Time complexity - O(NloglogN)

## Segmented Sieve

```

bool isPrime[r - l + 1]; //filled by true
for (long long i = 2; i * i <= r; ++i) {
    for (long long j = max(i * i, (l + (i - 1)) / i  * i); j <= r; j += i) {
        isPrime[j - l] = false;
    }
}

```

---

# ✨Modular Exponentiation

> Modular Exponentiation is used to efficiently compute powers under a modulus, i.e., compute \( a^b mod m \) without overflow and in logarithmic time.

## 🎻 Recursive Version

```
long long modExpRecursive(long long a, long long b, long long m) {
    if (b == 0) return 1;
    long long half = modExpRecursive(a, b / 2, m);
    long long result = (half * half) % m;
    if (b % 2) result = (result * a) % m;
    return result;
}
```

## 🔒 Iterative Version

```
long long modExpIterative(long long a, long long b, long long m) {
    long long result = 1;
    a %= m;
    while (b > 0) {
        if (b & 1)
            result = (result * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return result;
}
```

> 🧠 Time Complexity - O(log b) for both recursive and iterative versions


--- 

# 🎵Matrix Exponentiation

Matrix Exponentiation is a powerful technique to compute linear recurrence relations in **O(log n)** time using matrices, commonly used to compute nth Fibonacci number and similar sequences.

> ⏱️ Time Complexity - O(log n) for computing nth term in recurrence.

[Read More](https://codeforces.com/blog/entry/67776)

[Check complete code here](./Number%20Theory/MatrixExponentiation.cpp)

---

# 🔐Fermat's Little Theorem

Fermat's little theorem states that if p is a prime number, then for any integer a, the number a ^ p - a is an integer multiple of p. 

```
a^p ≡ a (mod p)
a^p-1 ≡ 1 (mod p)
a^p-2 ≡ a^-1 (mod p)

```

## 💡 Applications
- Efficient modular inverse computation - (a^-1 wrt p = a^p-2%p)


## ✅ Conditions
- \( p \) must be **prime**
- \( a \) must be **not divisible** by \( p \)

---

# 🐚Wilson's Theorem

Wilson's Theorem provides a unique primality test based on factorials and modular arithmetic.

## 📌 Statement

A positive integer \( p > 1 \) is **prime** if and only if:

```
(p - 1)! ≡ -1 (mod p)
```

## ✅ Conditions
- \( p \) must be **prime**
- \( (p-1)! \) means factorial from 1 to \( p-1 \)

---

# 🎨Euler's Totient Function

The Euler's Totient Function, denoted by φ(n), counts the number of integers from 1 to n that are coprime to n.

> φ(n) = count of integers k such that 1 ≤ k ≤ n and gcd(k, n) = 1

## 🧠 Key Properties

- If n is a prime number → φ(n) = n - 1
  
- For any integer n with prime factorization

```
φ(n) = n × (1 - 1/p₁) × (1 - 1/p₂) × ... × (1 - 1/pk)
where p₁, p₂, ..., pk are the distinct prime factors of n
```

[Check complete code here](./Number%20Theory/EulerTotient.cpp)

---

# 💎Practise Problems

- [GCD2](http://spoj.com/problems/GCD2/)
- [Cube Free Numbers](https://www.spoj.com/problems/CUBEFR)
- [NFACTOR - N-Factorful](https://www.spoj.com/problems/NFACTOR)
- [Card Game Again](https://codeforces.com/problemset/problem/818/E)
- [BORING - Boring Factorials](https://www.spoj.com/problems/BORING)
- [Daulat Ram's income](https://www.hackerearth.com/problem/algorithm/recurrence/)
  
