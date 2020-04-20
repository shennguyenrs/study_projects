'''
/* ****************************************************************** */
/* Find Duplicate Numbers                                             */
/*                                                                    */
/* find_duplicate_numbers.py                                          */
/* Created 28.02.2020 by shennguyenrs                                 */
/*                                                                    */
/* ****************************************************************** */
'''

def find_duplicate(li):
    li.sort()
    flag = 0

    for i in range(len(li)-1):
        if li[i] == li[i+1]:
            flag += 1
            print(str(li[i]) + " is the duplicate in the list")
        
    if flag == 0:
        print("No found the duplicate")

#input a line of numbers, split by ' ' and get the result
arr = []

print("Input the line of number to check:")

for i in map(int, input().split()):
    arr.append(i)

find_duplicate(arr)