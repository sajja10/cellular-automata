def listToString(s):
    str1 = ""
    for ele in s:
        str1 += ele
    return str1

b = []

with open("config.txt", 'r') as myFile:
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

myFile.close()
with open("config.txt", 'r') as myFile:
    temp = myFile.readline()
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

def func(o,p,q,r,s,t,u,v,w):
    return p+q+r+s+t+u+v+w

for i in range(n):
    for j in range(m):
        new_a[i][j]=a[i][j]

file1 = open("output.txt", "w")
sum1=0
while(1):
    print("enter the no of iterations from previous state: ",end='')
    input_k = input()
    k = int(input_k)
    if (k == -1):
        exit()
    sum1=sum1+k
    for l in range(k):
        for i in range(1,n+1):
            for j in range(1,m+1):
                sum=func(a[i][j],a[i][(j-1)],a[(i-1)][(j-1)],a[(i-1)][(j)],a[(i-1)][(j+1)],a[(i)][(j+1)],a[(i+1)][(j+1)],a[(i+1)][(j)],a[(i+1)][(j-1)])
                if(a[i][j]==1 and sum<2):
                    new_a[i][j]=0
                elif(a[i][j]==1 and sum>3):
                    new_a[i][j]=0
                elif(a[i][j]==0 and sum==3):
                    new_a[i][j]=1
                else:
                    new_a[i][j]=a[i][j]
        file1 = open("output.txt", "w")
        for i in range(1,n+1):
            for j in range(1,m+1):
                if(new_a[i][j]==1):
                    file1.write("X")
                else:
                    file1.write("O")
            file1.write('\n')
        file1 = open("output.txt", "w")
        for i in range(n+2):
            for j in range(m+2):
                a[i][j]=new_a[i][j]
    print("iteration no: ",end='')
    print(sum1)
    for i in range(1,n+1):
        for j in range(1,m+1):
            if(a[i][j]==1):
                print("X", end='')
            else:
                print("O", end='')
        print('\n',end='')