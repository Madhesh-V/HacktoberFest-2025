# Add Code Here/PYTHON/<YOUR-FILERNAME>.py
# by Parth-co79
# Your code here
n=int(input())
e=0
o=0
while n>0:
    d=n%10
    if d%2==0:
        e+=d
    else:
        o+=d
    n//=10
print(e,o)