def main():
    
    n = int(input())
    arr = input()   # takes the whole line of n numbers
    L = list(map(int,arr.split(' '))) 

    A = []
    pl = {}
    for i in range(n):
        if L[i] in pl:
            pl[L[i]].append(i)
        else:
            pl[L[i]] = [i]

    S = 0
    for a in pl:
        l = [-1] + pl[a] + [n]
        Sp = n*(n-1)/2
        for i in range(1,len(l)):
            Sp -= ((l[i]-l[i-1]-1)*(l[i]-l[i-1]-2))/2
        S += Sp

    print((2*S)/(n*n) + 1/n)

if __name__ == "__main__":
    main()
        
