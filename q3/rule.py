def listToString(s):
    str1 = ""
    for ele in s:
        str1 += ele
    return str1

b = []

with open('config.txt', 'r') as myFile:
    contents = myFile.readline()
    str = listToString(contents)
    for i in str.split():
        b.append(int(i))

m = b[0]
n = b[1]
f=m+2
g=n+2

a = [0] * g
for i in range(g):
    a[i] = [0] * f

new_a = [0] * g
for i in range(g):
    new_a[i] = [0] * f

c = [0] * b[2]
for i in range(b[2]):
    c[i] = [0] * 2

for i in range(n):
    for j in range(m):
        a[i][j] = 0

with open('config.txt', 'r') as myFile:
    myFile.readline()
    for i in range(b[2]):
        x=0
        list=myFile.readline()
        str = listToString(list)
        for j in str.split():
            c[i][x]=int(j)
            x=x+1

for i in range(b[2]):
    a[b[1]-c[i][1]+1][c[i][0]]=1

print("intial state")
for i in range(1,n+1):
    for j in range(1,m+1):
        if(a[i][j]==1):
                print("X", end='')
        else:
                print("O", end='')
    print('\n',end='')

def func(o):
    if(o==1):
        return 0
    else:
        return 1
sum=0
while(1):
    print("enter the no of iterations from previous state: ",end='')
    input_k = input()
    k = int(input_k)
    if (k == -1):
        exit()
    sum=sum+k
    new_a=a.copy()
    f=0
    g=0
    y=1
    for z in range(k):
        for i in range(1,n+1):
            for j in range(1,m+1):
                y=func(a[i][j])
                new_a[i][j]=y
        file1 = open("output.txt", "w")
        for i in range(1,n+1):
            for j in range(1,m+1):
                if(new_a[i][j]==1):
                    file1.write("X")
                else:
                    file1.write("O")
            file1.write('\n')
        a=new_a.copy()
    file1 = open("output.txt", "w")
    for i in range(1,n+1):
            for j in range(1,m+1):
                if(new_a[i][j]==1):
                    file1.write("X")
                else:
                    file1.write("O")
            file1.write('\n')
    print("iteration no: ",end='')
    print(sum)
    for i in range(1,n+1):
        for j in range(1,m+1):
            if(new_a[i][j]==1):
                print("X", end='')
            else:
                print("O", end='')
        print('\n',end='')