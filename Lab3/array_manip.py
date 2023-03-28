# -*- coding: utf-8 -*-
"""
Created on Thu Mar 16 20:56:41 2023

@author: anuki
"""
import random

def arrayManipulation(n, queries):
    # Write your code here
    values = {(0, n-1): 0}
    queries = sorted(queries, key = lambda x:(x[1] - x[0]), reverse = True)
    for i,q in enumerate(queries):
        a, b, k = q
        a -= 1
        b -= 1
        new_values = {}
        for (c, d), val in values.items():
            if d < a or b < c: 
                new_values[c, d] = val
            elif a <= c and d <= b:
                new_values[(c, d)] = val + k
            elif c < a and b < d:
                new_values[(c, a-1)] = new_values[b+1, d] = val
                new_values[a, b] = val + k
            elif c < a and d <= b:
                new_values[(c, a-1)] = val
                new_values[a, d] = val + k
            elif a <= c and b < d:
                new_values[b+1, d] = val
                new_values[c, b] = val + k
            else:
                print(a, b, c, d)
        values = new_values
        #print(values)
        if i%2000 == 0:
            print(len(values))
    return max(values.values())

def arrayManipulation1(n, queries):
    # Write your code here
    arr = [0] * n
    maxi = 0
    for q in queries:
        a, b, k = q
        for i in range(a-1, b):
            arr[i] += k
            maxi = max(maxi, arr[i])
    return maxi

def arrayManipulation(n, queries):
    sections = set((1, n))
    for a, b, k in queries:
        sections.add(a)
        sections.add(b+1)
    sections.discard(n+1)
    sorted_sections = sorted(sections)
    print(len(sorted_sections))
    
    n = len(sorted_sections)
    values = [0] * n
    
    queries = sorted(queries, key = lambda x:(x[1] - x[0]), reverse = True)
    for a, b, k in queries:
        start = binary_search(sorted_sections, a, 0, n)
        end = binary_search(sorted_sections, b+1, 0, n)
        #print(start, end)
        for i in range(start, end):
            values[i] += k
    return max(values)
    
def arrayManipulation(n, queries):
    # Write your code here
    values = {(0, n-1): 0}
    queries = sorted(queries, key = lambda x:(x[1] - x[0]), reverse = True)
    for i,q in enumerate(queries):
        a, b, k = q
        a -= 1
        b -= 1
        new_values = {}
        for (c, d), val in values.items():
            if d < a or b < c: 
                new_values[c, d] = val
            elif a <= c and d <= b:
                new_values[(c, d)] = val + k
            elif c < a and b < d:
                new_values[(c, a-1)] = new_values[b+1, d] = val
                new_values[a, b] = val + k
            elif c < a and d <= b:
                new_values[(c, a-1)] = val
                new_values[a, d] = val + k
            elif a <= c and b < d:
                new_values[b+1, d] = val
                new_values[c, b] = val + k
            else:
                print(a, b, c, d)
        values = new_values
        #print(values)
        if i%2000 == 0:
            print(len(values))
    return max(values.values())    
        

def binary_search(arr, num, start, end):
    if start > end: return None
    mid = (start + end)//2
    if arr[mid] == num: return mid
    if arr[mid] < num: return binary_search(arr, num, mid+1, end)
    if arr[mid] > num: return binary_search(arr, num, start, mid-1)
    
from collections import defaultdict
def arrayManipulation(n, queries):
    values = defaultdict(int);
    values[1] = 0
    for a, b, k in queries:
        values[a] += k
        values[b+1] -= k
    maxi = 0
    cur = 0
    for i in sorted(values):
        cur += values[i]
        maxi = max(cur, maxi)
    return maxi

n = 10**7
queries = []
random.seed(0)
for i in range(2*10**5):
    a = random.randint(1, n)
    b = random.randint(a, n)
    queries.append((a, b, random.randint(0, 10**9)))
print('made queries')

sections = set((0, n-1))
for a, b, k in queries:
    sections.add(a-1)
    sections.add(b)
sections.discard(n)
sorted_sections = sorted(sections)

    
print(arrayManipulation(n, queries))
    