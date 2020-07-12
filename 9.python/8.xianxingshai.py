#!/usr/bin/env python
# coding=utf-8

maxn = 50
prime = [0] * 1000
i = 2
for i in range(maxn): 
    if prime[i] == 0:
        prime[prime[0]] = i
        prime[0] += 1
    j = 1
    for j in range(prime[0]):
        if i * prime[j] > maxn:
            break
        prime[i * prime[j]] = 1
        if i % prime[j] == 0:
            break

i = 0
for i in range(maxn):
    print(prime[i])
