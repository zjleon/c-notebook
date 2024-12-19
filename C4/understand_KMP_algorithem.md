
i=3, j=3
k is unknown
p[1],p[2],...,p[k-1] = p[3-k+1]p[3-k+2],...,p[3-1]
s[3-k+1],s[3-k+2],s[3-1]

i=7, j=5
k is unknown
p[1],p[2],...,p[k-1] = p[7-k+1]p[7-k+2],...,p[7-1]
s[7-k+1],s[7-k+2],s[7-1]


////////////////////

123456789
a string star
star

// use enumerate method to evaluate next function
next(j) {
    j == 1: 0
    max(k|1<k<j, '')
        j=3, k=2 's' != 't', equation failed, k is invalid
        j=4, k=2 's' != 'a', equation failed, k is invalid
        j=4, k=3 'st' != 'ta', equation failed, k is invalid
    1
}
index start from 1

i=1     -> a
j=1     -> s
current char doesn't equal, trigger next(j)
next(j) -> 0
j reach 0, i, j increase 1
i++ -> 2; j++   ->1

i=2     -> 
j=1     -> s
current char doesn't equal, trigger next(j)
next(j) -> 0
j reach 0, i, j increase 1
i++ -> 3; j++   ->1

i=3     -> s
j=1     -> s
current char equal, i,j increase 1
i++     -> 4
j++     -> 2

i=4     -> t
j=2     -> t
current char equal, i,j increase 1
i++     -> 5
j++     -> 3

/////////////////// vital step //////////////
i=5     -> r
j=3     -> a
current char doesn't equal, trigger next(j), and i++
next(j) -> 1
i++     -> 6
/////////////////// vital step //////////////

i=6     -> i
j=1     -> s
current char doesn't equal, trigger next(j)
next(j) -> 0
j reach 0, i, j increase 1
i++ -> 7; j++   ->1

i=7     -> n
j=1     -> s
current char doesn't equal, trigger next(j)
next(j) -> 0
j reach 0, i, j increase 1
i++ -> 8; j++   ->1

i=8     -> g
j=1     -> s
current char doesn't equal, trigger next(j)
next(j) -> 0
j reach 0, i, j increase 1
i++ -> 9; j++   ->1
