# -*- coding: utf-8 -*-
"""
Created on Thu Mar 16 14:38:52 2023

@author: anuki
"""

import random
import matplotlib.pyplot as plt


arrays = []

for lengths in [3, 6, 10, 16, 20]:
    arrays.append([random.randint(1, 100) for i in range(lengths)])
    
    
def insertion_sort(array):
    for i in range (1, len(array)):
        cur_element = array[i]
        j = i - 1
        while array[j] >= cur_element and j >= 0:
            array[j+1] = array[j]
            j -= 1
        array[j+1] = cur_element
    return array


def bubble_sort(array):
    for n in range(len(array), 1, -1):
        for i in range(1, n):
            if array[i] < array[i-1]:
                array[i-1], array[i] = array[i], array[i-1]