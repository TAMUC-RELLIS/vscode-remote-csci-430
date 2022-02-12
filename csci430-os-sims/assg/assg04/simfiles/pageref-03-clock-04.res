Paging Simulation
=====================================
memory size          : 4
reference stream size: 34
paging scheme        : fifo

-------------------------------------
system time   : 0
page reference: 1
page status   : fault (placement)

frame[000]     1 use=1 <-- framePointer
frame[001] EMPTY use=1
frame[002] EMPTY use=1
frame[003] EMPTY use=1

Hit  ratio : 0 / 1 (ratio = 0)
Fault ratio: 1 / 1 (ratio = 1)

Hit count        : 0
Placement count  : 1
Replacement count: 0

-------------------------------------
system time   : 1
page reference: 8
page status   : fault (placement)

frame[000]     1 use=1 <-- framePointer
frame[001]     8 use=1
frame[002] EMPTY use=1
frame[003] EMPTY use=1

Hit  ratio : 0 / 2 (ratio = 0)
Fault ratio: 2 / 2 (ratio = 1)

Hit count        : 0
Placement count  : 2
Replacement count: 0

-------------------------------------
system time   : 2
page reference: 2
page status   : fault (placement)

frame[000]     1 use=1 <-- framePointer
frame[001]     8 use=1
frame[002]     2 use=1
frame[003] EMPTY use=1

Hit  ratio : 0 / 3 (ratio = 0)
Fault ratio: 3 / 3 (ratio = 1)

Hit count        : 0
Placement count  : 3
Replacement count: 0

-------------------------------------
system time   : 3
page reference: 2
page status   : hit

frame[000]     1 use=1 <-- framePointer
frame[001]     8 use=1
frame[002]     2 use=1
frame[003] EMPTY use=1

Hit  ratio : 1 / 4 (ratio = 0.25)
Fault ratio: 3 / 4 (ratio = 0.75)

Hit count        : 1
Placement count  : 3
Replacement count: 0

-------------------------------------
system time   : 4
page reference: 1
page status   : hit

frame[000]     1 use=1 <-- framePointer
frame[001]     8 use=1
frame[002]     2 use=1
frame[003] EMPTY use=1

Hit  ratio : 2 / 5 (ratio = 0.4)
Fault ratio: 3 / 5 (ratio = 0.6)

Hit count        : 2
Placement count  : 3
Replacement count: 0

-------------------------------------
system time   : 5
page reference: 7
page status   : fault (placement)

frame[000]     1 use=1 <-- framePointer
frame[001]     8 use=1
frame[002]     2 use=1
frame[003]     7 use=1

Hit  ratio : 2 / 6 (ratio = 0.333333)
Fault ratio: 4 / 6 (ratio = 0.666667)

Hit count        : 2
Placement count  : 4
Replacement count: 0

-------------------------------------
system time   : 6
page reference: 6
page status   : fault (replacement)

frame[000]     6 use=1
frame[001]     8 use=0 <-- framePointer
frame[002]     2 use=0
frame[003]     7 use=0

Hit  ratio : 2 / 7 (ratio = 0.285714)
Fault ratio: 5 / 7 (ratio = 0.714286)

Hit count        : 2
Placement count  : 4
Replacement count: 1

-------------------------------------
system time   : 7
page reference: 7
page status   : hit

frame[000]     6 use=1
frame[001]     8 use=0 <-- framePointer
frame[002]     2 use=0
frame[003]     7 use=1

Hit  ratio : 3 / 8 (ratio = 0.375)
Fault ratio: 5 / 8 (ratio = 0.625)

Hit count        : 3
Placement count  : 4
Replacement count: 1

-------------------------------------
system time   : 8
page reference: 8
page status   : hit

frame[000]     6 use=1
frame[001]     8 use=1 <-- framePointer
frame[002]     2 use=0
frame[003]     7 use=1

Hit  ratio : 4 / 9 (ratio = 0.444444)
Fault ratio: 5 / 9 (ratio = 0.555556)

Hit count        : 4
Placement count  : 4
Replacement count: 1

-------------------------------------
system time   : 9
page reference: 1
page status   : fault (replacement)

frame[000]     6 use=1
frame[001]     8 use=0
frame[002]     1 use=1
frame[003]     7 use=1 <-- framePointer

Hit  ratio : 4 / 10 (ratio = 0.4)
Fault ratio: 6 / 10 (ratio = 0.6)

Hit count        : 4
Placement count  : 4
Replacement count: 2

-------------------------------------
system time   : 10
page reference: 2
page status   : fault (replacement)

frame[000]     6 use=0
frame[001]     2 use=1
frame[002]     1 use=1 <-- framePointer
frame[003]     7 use=0

Hit  ratio : 4 / 11 (ratio = 0.363636)
Fault ratio: 7 / 11 (ratio = 0.636364)

Hit count        : 4
Placement count  : 4
Replacement count: 3

-------------------------------------
system time   : 11
page reference: 8
page status   : fault (replacement)

frame[000]     6 use=0 <-- framePointer
frame[001]     2 use=1
frame[002]     1 use=0
frame[003]     8 use=1

Hit  ratio : 4 / 12 (ratio = 0.333333)
Fault ratio: 8 / 12 (ratio = 0.666667)

Hit count        : 4
Placement count  : 4
Replacement count: 4

-------------------------------------
system time   : 12
page reference: 3
page status   : fault (replacement)

frame[000]     3 use=1
frame[001]     2 use=1 <-- framePointer
frame[002]     1 use=0
frame[003]     8 use=1

Hit  ratio : 4 / 13 (ratio = 0.307692)
Fault ratio: 9 / 13 (ratio = 0.692308)

Hit count        : 4
Placement count  : 4
Replacement count: 5

-------------------------------------
system time   : 13
page reference: 8
page status   : hit

frame[000]     3 use=1
frame[001]     2 use=1 <-- framePointer
frame[002]     1 use=0
frame[003]     8 use=1

Hit  ratio : 5 / 14 (ratio = 0.357143)
Fault ratio: 9 / 14 (ratio = 0.642857)

Hit count        : 5
Placement count  : 4
Replacement count: 5

-------------------------------------
system time   : 14
page reference: 4
page status   : fault (replacement)

frame[000]     3 use=1
frame[001]     2 use=0
frame[002]     4 use=1
frame[003]     8 use=1 <-- framePointer

Hit  ratio : 5 / 15 (ratio = 0.333333)
Fault ratio: 10 / 15 (ratio = 0.666667)

Hit count        : 5
Placement count  : 4
Replacement count: 6

-------------------------------------
system time   : 15
page reference: 5
page status   : fault (replacement)

frame[000]     3 use=0
frame[001]     5 use=1
frame[002]     4 use=1 <-- framePointer
frame[003]     8 use=0

Hit  ratio : 5 / 16 (ratio = 0.3125)
Fault ratio: 11 / 16 (ratio = 0.6875)

Hit count        : 5
Placement count  : 4
Replacement count: 7

-------------------------------------
system time   : 16
page reference: 1
page status   : fault (replacement)

frame[000]     3 use=0 <-- framePointer
frame[001]     5 use=1
frame[002]     4 use=0
frame[003]     1 use=1

Hit  ratio : 5 / 17 (ratio = 0.294118)
Fault ratio: 12 / 17 (ratio = 0.705882)

Hit count        : 5
Placement count  : 4
Replacement count: 8

-------------------------------------
system time   : 17
page reference: 5
page status   : hit

frame[000]     3 use=0 <-- framePointer
frame[001]     5 use=1
frame[002]     4 use=0
frame[003]     1 use=1

Hit  ratio : 6 / 18 (ratio = 0.333333)
Fault ratio: 12 / 18 (ratio = 0.666667)

Hit count        : 6
Placement count  : 4
Replacement count: 8

-------------------------------------
system time   : 18
page reference: 2
page status   : fault (replacement)

frame[000]     2 use=1
frame[001]     5 use=1 <-- framePointer
frame[002]     4 use=0
frame[003]     1 use=1

Hit  ratio : 6 / 19 (ratio = 0.315789)
Fault ratio: 13 / 19 (ratio = 0.684211)

Hit count        : 6
Placement count  : 4
Replacement count: 9

-------------------------------------
system time   : 19
page reference: 4
page status   : hit

frame[000]     2 use=1
frame[001]     5 use=1 <-- framePointer
frame[002]     4 use=1
frame[003]     1 use=1

Hit  ratio : 7 / 20 (ratio = 0.35)
Fault ratio: 13 / 20 (ratio = 0.65)

Hit count        : 7
Placement count  : 4
Replacement count: 9

-------------------------------------
system time   : 20
page reference: 5
page status   : hit

frame[000]     2 use=1
frame[001]     5 use=1 <-- framePointer
frame[002]     4 use=1
frame[003]     1 use=1

Hit  ratio : 8 / 21 (ratio = 0.380952)
Fault ratio: 13 / 21 (ratio = 0.619048)

Hit count        : 8
Placement count  : 4
Replacement count: 9

-------------------------------------
system time   : 21
page reference: 6
page status   : fault (replacement)

frame[000]     2 use=0
frame[001]     6 use=1
frame[002]     4 use=0 <-- framePointer
frame[003]     1 use=0

Hit  ratio : 8 / 22 (ratio = 0.363636)
Fault ratio: 14 / 22 (ratio = 0.636364)

Hit count        : 8
Placement count  : 4
Replacement count: 10

-------------------------------------
system time   : 22
page reference: 7
page status   : fault (replacement)

frame[000]     2 use=0
frame[001]     6 use=1
frame[002]     7 use=1
frame[003]     1 use=0 <-- framePointer

Hit  ratio : 8 / 23 (ratio = 0.347826)
Fault ratio: 15 / 23 (ratio = 0.652174)

Hit count        : 8
Placement count  : 4
Replacement count: 11

-------------------------------------
system time   : 23
page reference: 6
page status   : hit

frame[000]     2 use=0
frame[001]     6 use=1
frame[002]     7 use=1
frame[003]     1 use=0 <-- framePointer

Hit  ratio : 9 / 24 (ratio = 0.375)
Fault ratio: 15 / 24 (ratio = 0.625)

Hit count        : 9
Placement count  : 4
Replacement count: 11

-------------------------------------
system time   : 24
page reference: 7
page status   : hit

frame[000]     2 use=0
frame[001]     6 use=1
frame[002]     7 use=1
frame[003]     1 use=0 <-- framePointer

Hit  ratio : 10 / 25 (ratio = 0.4)
Fault ratio: 15 / 25 (ratio = 0.6)

Hit count        : 10
Placement count  : 4
Replacement count: 11

-------------------------------------
system time   : 25
page reference: 2
page status   : hit

frame[000]     2 use=1
frame[001]     6 use=1
frame[002]     7 use=1
frame[003]     1 use=0 <-- framePointer

Hit  ratio : 11 / 26 (ratio = 0.423077)
Fault ratio: 15 / 26 (ratio = 0.576923)

Hit count        : 11
Placement count  : 4
Replacement count: 11

-------------------------------------
system time   : 26
page reference: 4
page status   : fault (replacement)

frame[000]     2 use=1 <-- framePointer
frame[001]     6 use=1
frame[002]     7 use=1
frame[003]     4 use=1

Hit  ratio : 11 / 27 (ratio = 0.407407)
Fault ratio: 16 / 27 (ratio = 0.592593)

Hit count        : 11
Placement count  : 4
Replacement count: 12

-------------------------------------
system time   : 27
page reference: 2
page status   : hit

frame[000]     2 use=1 <-- framePointer
frame[001]     6 use=1
frame[002]     7 use=1
frame[003]     4 use=1

Hit  ratio : 12 / 28 (ratio = 0.428571)
Fault ratio: 16 / 28 (ratio = 0.571429)

Hit count        : 12
Placement count  : 4
Replacement count: 12

-------------------------------------
system time   : 28
page reference: 7
page status   : hit

frame[000]     2 use=1 <-- framePointer
frame[001]     6 use=1
frame[002]     7 use=1
frame[003]     4 use=1

Hit  ratio : 13 / 29 (ratio = 0.448276)
Fault ratio: 16 / 29 (ratio = 0.551724)

Hit count        : 13
Placement count  : 4
Replacement count: 12

-------------------------------------
system time   : 29
page reference: 3
page status   : fault (replacement)

frame[000]     3 use=1
frame[001]     6 use=0 <-- framePointer
frame[002]     7 use=0
frame[003]     4 use=0

Hit  ratio : 13 / 30 (ratio = 0.433333)
Fault ratio: 17 / 30 (ratio = 0.566667)

Hit count        : 13
Placement count  : 4
Replacement count: 13

-------------------------------------
system time   : 30
page reference: 3
page status   : hit

frame[000]     3 use=1
frame[001]     6 use=0 <-- framePointer
frame[002]     7 use=0
frame[003]     4 use=0

Hit  ratio : 14 / 31 (ratio = 0.451613)
Fault ratio: 17 / 31 (ratio = 0.548387)

Hit count        : 14
Placement count  : 4
Replacement count: 13

-------------------------------------
system time   : 31
page reference: 2
page status   : fault (replacement)

frame[000]     3 use=1
frame[001]     2 use=1
frame[002]     7 use=0 <-- framePointer
frame[003]     4 use=0

Hit  ratio : 14 / 32 (ratio = 0.4375)
Fault ratio: 18 / 32 (ratio = 0.5625)

Hit count        : 14
Placement count  : 4
Replacement count: 14

-------------------------------------
system time   : 32
page reference: 3
page status   : hit

frame[000]     3 use=1
frame[001]     2 use=1
frame[002]     7 use=0 <-- framePointer
frame[003]     4 use=0

Hit  ratio : 15 / 33 (ratio = 0.454545)
Fault ratio: 18 / 33 (ratio = 0.545455)

Hit count        : 15
Placement count  : 4
Replacement count: 14

-------------------------------------
system time   : 33
page reference: 4
page status   : hit

frame[000]     3 use=1
frame[001]     2 use=1
frame[002]     7 use=0 <-- framePointer
frame[003]     4 use=1

Hit  ratio : 16 / 34 (ratio = 0.470588)
Fault ratio: 18 / 34 (ratio = 0.529412)

Hit count        : 16
Placement count  : 4
Replacement count: 14

