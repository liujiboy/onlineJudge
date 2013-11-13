def isprime(n):
    i=2
    while(i*i<n):
        if(n%i==0):
            return 0
        i+=1
    return 1
primes=[2,3,5,7]
for i in range(2,5):
    newprimes=[];
    for p in primes:
        for d in range(1,10,2):
            newp=p*10+d
            if isprime(newp):
                newprimes.append(newp)
    primes=newprimes
for i in newprimes:
    print i
