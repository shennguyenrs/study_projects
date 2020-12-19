"""
Advent of Code 2020 - Day 1

Part 1: Find the couple that have total is 2020
        Then print their multiply result

Part 2: Find the triplet that have its total is 2020
        Then print their multiply result
"""

def find_couple(data_list):
    """
    Find the couple from the data list
    O(n)
    """

    begin = 0
    end = len(data_list)-1

    while data_list[begin]<data_list[end]:
        total = data_list[begin] + data_list[end]

        if total==2020:
            print("The first number is {}".format(data_list[begin]))
            print("The second number is {}".format(data_list[end]))
            print("Their multiply is {}".format(
                data_list[begin] * data_list[end]
            ))
            break

        if total>2020:
            end-=1
        else:
            begin+=1

def find_triplet(data_list):
    """
    Find the triplet from the data list
    O(n^2)
    """

    for i in range(len(data_list)-2):
        begin = i
        mid = i+1
        end = len(data_list)-1

        while mid<end:
            total = data_list[begin] + data_list[mid] + data_list[end]

            if total==2020:
                print("The first number is {}".format(data_list[begin]))
                print("The second number is {}".format(data_list[mid]))
                print("The third number is {}".format(data_list[end]))
                print("Their multiply is {}".format(
                    data_list[begin] * data_list[mid] * data_list[end]
                ))
                break

            if total>2020:
                end-=1
            else:
                mid+=1

DataList = list()

# Open file and input data
file = open("entries.txt", "r")
lines = file.readlines()

for line in lines:
    DataList.append(int(line.rstrip()))

# Sort the list
DataList.sort()

# Find and print out the couple
find_couple(DataList)
print()

# Find and print out the triplet
find_triplet(DataList)
