Paging Simulation
=====================================
memory size          : 3
reference stream size: 30
paging scheme        : fifo

-------------------------------------
system time   : 0
page reference: 6
page status   : fault (placement)

frame[000]     6 <-- framePointer
frame[001] EMPTY
frame[002] EMPTY

Hit  ratio : 0 / 1 (ratio = 0)
Fault ratio: 1 / 1 (ratio = 1)

Hit count        : 0
Placement count  : 1
Replacement count: 0

-------------------------------------
system time   : 1
page reference: 5
page status   : fault (placement)

frame[000]     6 <-- framePointer
frame[001]     5
frame[002] EMPTY

Hit  ratio : 0 / 2 (ratio = 0)
Fault ratio: 2 / 2 (ratio = 1)

Hit count        : 0
Placement count  : 2
Replacement count: 0

-------------------------------------
system time   : 2
page reference: 2
page status   : fault (placement)

frame[000]     6 <-- framePointer
frame[001]     5
frame[002]     2

Hit  ratio : 0 / 3 (ratio = 0)
Fault ratio: 3 / 3 (ratio = 1)

Hit count        : 0
Placement count  : 3
Replacement count: 0

-------------------------------------
system time   : 3
page reference: 4
page status   : fault (replacement)

frame[000]     4
frame[001]     5 <-- framePointer
frame[002]     2

Hit  ratio : 0 / 4 (ratio = 0)
Fault ratio: 4 / 4 (ratio = 1)

Hit count        : 0
Placement count  : 3
Replacement count: 1

-------------------------------------
system time   : 4
page reference: 2
page status   : hit

frame[000]     4
frame[001]     5 <-- framePointer
frame[002]     2

Hit  ratio : 1 / 5 (ratio = 0.2)
Fault ratio: 4 / 5 (ratio = 0.8)

Hit count        : 1
Placement count  : 3
Replacement count: 1

-------------------------------------
system time   : 5
page reference: 4
page status   : hit

frame[000]     4
frame[001]     5 <-- framePointer
frame[002]     2

Hit  ratio : 2 / 6 (ratio = 0.333333)
Fault ratio: 4 / 6 (ratio = 0.666667)

Hit count        : 2
Placement count  : 3
Replacement count: 1

-------------------------------------
system time   : 6
page reference: 3
page status   : fault (replacement)

frame[000]     4
frame[001]     3
frame[002]     2 <-- framePointer

Hit  ratio : 2 / 7 (ratio = 0.285714)
Fault ratio: 5 / 7 (ratio = 0.714286)

Hit count        : 2
Placement count  : 3
Replacement count: 2

-------------------------------------
system time   : 7
page reference: 5
page status   : fault (replacement)

frame[000]     4 <-- framePointer
frame[001]     3
frame[002]     5

Hit  ratio : 2 / 8 (ratio = 0.25)
Fault ratio: 6 / 8 (ratio = 0.75)

Hit count        : 2
Placement count  : 3
Replacement count: 3

-------------------------------------
system time   : 8
page reference: 3
page status   : hit

frame[000]     4 <-- framePointer
frame[001]     3
frame[002]     5

Hit  ratio : 3 / 9 (ratio = 0.333333)
Fault ratio: 6 / 9 (ratio = 0.666667)

Hit count        : 3
Placement count  : 3
Replacement count: 3

-------------------------------------
system time   : 9
page reference: 6
page status   : fault (replacement)

frame[000]     6
frame[001]     3 <-- framePointer
frame[002]     5

Hit  ratio : 3 / 10 (ratio = 0.3)
Fault ratio: 7 / 10 (ratio = 0.7)

Hit count        : 3
Placement count  : 3
Replacement count: 4

-------------------------------------
system time   : 10
page reference: 7
page status   : fault (replacement)

frame[000]     6
frame[001]     7
frame[002]     5 <-- framePointer

Hit  ratio : 3 / 11 (ratio = 0.272727)
Fault ratio: 8 / 11 (ratio = 0.727273)

Hit count        : 3
Placement count  : 3
Replacement count: 5

-------------------------------------
system time   : 11
page reference: 5
page status   : hit

frame[000]     6
frame[001]     7
frame[002]     5 <-- framePointer

Hit  ratio : 4 / 12 (ratio = 0.333333)
Fault ratio: 8 / 12 (ratio = 0.666667)

Hit count        : 4
Placement count  : 3
Replacement count: 5

-------------------------------------
system time   : 12
page reference: 3
page status   : fault (replacement)

frame[000]     6 <-- framePointer
frame[001]     7
frame[002]     3

Hit  ratio : 4 / 13 (ratio = 0.307692)
Fault ratio: 9 / 13 (ratio = 0.692308)

Hit count        : 4
Placement count  : 3
Replacement count: 6

-------------------------------------
system time   : 13
page reference: 5
page status   : fault (replacement)

frame[000]     5
frame[001]     7 <-- framePointer
frame[002]     3

Hit  ratio : 4 / 14 (ratio = 0.285714)
Fault ratio: 10 / 14 (ratio = 0.714286)

Hit count        : 4
Placement count  : 3
Replacement count: 7

-------------------------------------
system time   : 14
page reference: 4
page status   : fault (replacement)

frame[000]     5
frame[001]     4
frame[002]     3 <-- framePointer

Hit  ratio : 4 / 15 (ratio = 0.266667)
Fault ratio: 11 / 15 (ratio = 0.733333)

Hit count        : 4
Placement count  : 3
Replacement count: 8

-------------------------------------
system time   : 15
page reference: 3
page status   : hit

frame[000]     5
frame[001]     4
frame[002]     3 <-- framePointer

Hit  ratio : 5 / 16 (ratio = 0.3125)
Fault ratio: 11 / 16 (ratio = 0.6875)

Hit count        : 5
Placement count  : 3
Replacement count: 8

-------------------------------------
system time   : 16
page reference: 4
page status   : hit

frame[000]     5
frame[001]     4
frame[002]     3 <-- framePointer

Hit  ratio : 6 / 17 (ratio = 0.352941)
Fault ratio: 11 / 17 (ratio = 0.647059)

Hit count        : 6
Placement count  : 3
Replacement count: 8

-------------------------------------
system time   : 17
page reference: 7
page status   : fault (replacement)

frame[000]     5 <-- framePointer
frame[001]     4
frame[002]     7

Hit  ratio : 6 / 18 (ratio = 0.333333)
Fault ratio: 12 / 18 (ratio = 0.666667)

Hit count        : 6
Placement count  : 3
Replacement count: 9

-------------------------------------
system time   : 18
page reference: 2
page status   : fault (replacement)

frame[000]     2
frame[001]     4 <-- framePointer
frame[002]     7

Hit  ratio : 6 / 19 (ratio = 0.315789)
Fault ratio: 13 / 19 (ratio = 0.684211)

Hit count        : 6
Placement count  : 3
Replacement count: 10

-------------------------------------
system time   : 19
page reference: 1
page status   : fault (replacement)

frame[000]     2
frame[001]     1
frame[002]     7 <-- framePointer

Hit  ratio : 6 / 20 (ratio = 0.3)
Fault ratio: 14 / 20 (ratio = 0.7)

Hit count        : 6
Placement count  : 3
Replacement count: 11

-------------------------------------
system time   : 20
page reference: 3
page status   : fault (replacement)

frame[000]     2 <-- framePointer
frame[001]     1
frame[002]     3

Hit  ratio : 6 / 21 (ratio = 0.285714)
Fault ratio: 15 / 21 (ratio = 0.714286)

Hit count        : 6
Placement count  : 3
Replacement count: 12

-------------------------------------
system time   : 21
page reference: 7
page status   : fault (replacement)

frame[000]     7
frame[001]     1 <-- framePointer
frame[002]     3

Hit  ratio : 6 / 22 (ratio = 0.272727)
Fault ratio: 16 / 22 (ratio = 0.727273)

Hit count        : 6
Placement count  : 3
Replacement count: 13

-------------------------------------
system time   : 22
page reference: 6
page status   : fault (replacement)

frame[000]     7
frame[001]     6
frame[002]     3 <-- framePointer

Hit  ratio : 6 / 23 (ratio = 0.26087)
Fault ratio: 17 / 23 (ratio = 0.73913)

Hit count        : 6
Placement count  : 3
Replacement count: 14

-------------------------------------
system time   : 23
page reference: 4
page status   : fault (replacement)

frame[000]     7 <-- framePointer
frame[001]     6
frame[002]     4

Hit  ratio : 6 / 24 (ratio = 0.25)
Fault ratio: 18 / 24 (ratio = 0.75)

Hit count        : 6
Placement count  : 3
Replacement count: 15

-------------------------------------
system time   : 24
page reference: 1
page status   : fault (replacement)

frame[000]     1
frame[001]     6 <-- framePointer
frame[002]     4

Hit  ratio : 6 / 25 (ratio = 0.24)
Fault ratio: 19 / 25 (ratio = 0.76)

Hit count        : 6
Placement count  : 3
Replacement count: 16

-------------------------------------
system time   : 25
page reference: 2
page status   : fault (replacement)

frame[000]     1
frame[001]     2
frame[002]     4 <-- framePointer

Hit  ratio : 6 / 26 (ratio = 0.230769)
Fault ratio: 20 / 26 (ratio = 0.769231)

Hit count        : 6
Placement count  : 3
Replacement count: 17

-------------------------------------
system time   : 26
page reference: 1
page status   : hit

frame[000]     1
frame[001]     2
frame[002]     4 <-- framePointer

Hit  ratio : 7 / 27 (ratio = 0.259259)
Fault ratio: 20 / 27 (ratio = 0.740741)

Hit count        : 7
Placement count  : 3
Replacement count: 17

-------------------------------------
system time   : 27
page reference: 3
page status   : fault (replacement)

frame[000]     1 <-- framePointer
frame[001]     2
frame[002]     3

Hit  ratio : 7 / 28 (ratio = 0.25)
Fault ratio: 21 / 28 (ratio = 0.75)

Hit count        : 7
Placement count  : 3
Replacement count: 18

-------------------------------------
system time   : 28
page reference: 4
page status   : fault (replacement)

frame[000]     4
frame[001]     2 <-- framePointer
frame[002]     3

Hit  ratio : 7 / 29 (ratio = 0.241379)
Fault ratio: 22 / 29 (ratio = 0.758621)

Hit count        : 7
Placement count  : 3
Replacement count: 19

-------------------------------------
system time   : 29
page reference: 7
page status   : fault (replacement)

frame[000]     4
frame[001]     7
frame[002]     3 <-- framePointer

Hit  ratio : 7 / 30 (ratio = 0.233333)
Fault ratio: 23 / 30 (ratio = 0.766667)

Hit count        : 7
Placement count  : 3
Replacement count: 20

