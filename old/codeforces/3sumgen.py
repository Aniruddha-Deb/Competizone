def is_3sum_complete(a):
    s = set(a)
    for i in range(len(a)):
        for j in range(i+1,len(a)):
            for k in range(j+1,len(a)):
                if a[i] + a[j] + a[k] not in s:
                    return False
    return True

def get_3sum_completes():
    for i in range(3,6):
        a = [0 for j in range(i)]
        for j in range(11**i):
            for k in range(i):
                a[k] = ((j//11**k)%11) - 5
            #print(a)
            if (is_3sum_complete(a)):
                print(a)

get_3sum_completes()
