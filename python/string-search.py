pattern = input(str()) #input the pattern
string = input(str()) #input the search string
result = []
count = 0

for i in range(len(pattern)-len(string)+1):
    flag = 0
    if pattern[i] == string[0]:
        flag = 1
        for j in range(1, len(string)):
            if pattern[i+j] != string[j]:
                flag = 0
                break
            if flag == 1:
                result.append(i)
                count+=1

print(count)
for k in result:
    print(k, end=' ')