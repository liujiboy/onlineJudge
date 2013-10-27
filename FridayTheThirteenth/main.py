def isLeapYear(year):
    if (year%4==0 and year%100<>0) or (year%400==0):
        return True
    else:
        return False
def diff(year,month,day):
    months=[31,28,31,30,31,30,31,31,30,31,30,31]
    total=0
    for i in range(1900,year):
        if isLeapYear(i):
            total+=366
        else:
            total+=365
    for i in range(1,month):
        if i<>2:
            total+=months[i-1];
        else:
            if isLeapYear(year):
                total+=29
            else:
                total+=months[i-1]
    total+=day
    return total
if __name__=="__main__":
    counts=[0,0,0,0,0,0,0]
    fin=open("friday.in")
    n=int(fin.readline())
    for year in range(1900,1900+n):
        for month in range(1,13):
            day=13
            total=diff(year,month,day)
            counts[(total-1+2)%7]+=1
    print counts
