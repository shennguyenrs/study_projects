"""
/* ********************************************* */
/* Binary Search                                 */  
/*                                               */ 
/* binary-search.py                              */
/* Created 09/02/2020 by shennguyenrs            */ 
/* ********************************************* */
"""

from math import floor

arr = [] #The array contains the numbers to be checked
result = [] #The array contains result 1 or -1 depend on the test cases
flag = 1

for _ in range(int(input())): #Input the test case
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
            flag = -1
            break
        else:
            if arr[lo] > check_num:
                high = lo - 1
            else:
                low = lo + 1

    result.append(flag)

for k in result:
    print(k, end='\n')
