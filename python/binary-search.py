"""
/* ********************************************* */
/* Binary Search                                 */  
/*                                               */ 
/* binary-search.py                              */
/* Created 09/02/2020 by shennguyenrs            */ 
/* ********************************************* */
"""

from math import floor

arr = []
flag = []

for i in range(int(input())):
    n, check_num = map(int, input().split())
    for j in map(int, input().split()):
        arr.append(j)

    arr.sort()
    low = 0
    high = n-1
    lo = 0

    while arr[lo] != check_num:
        lo = floor((low+high)/2)
        if low > high:
            flag[i] = -1
            break
        else:
            if arr[lo] > check_num:
                high = lo
            else:
                low = lo
    flag[i] = 1

for k in flag:
    print(k, end='\n')
