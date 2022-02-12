Paging Simulation
=====================================
memory size          : 3
reference stream size: 12
paging scheme        : fifo

-------------------------------------
system time   : 0
page reference: 2
page status   : fault (placement)

frame[000]     2 use=1 <-- framePointer
frame[001] EMPTY use=1
frame[002] EMPTY use=1

Hit  ratio : 0 / 1 (ratio = 0)
Fault ratio: 1 / 1 (ratio = 1)

Hit count        : 0
Placement count  : 1
Replacement count: 0

-------------------------------------
system time   : 1
page reference: 3
page status   : fault (placement)

frame[000]     2 use=1 <-- framePointer
frame[001]     3 use=1
frame[002] EMPTY use=1

Hit  ratio : 0 / 2 (ratio = 0)
Fault ratio: 2 / 2 (ratio = 1)

Hit count        : 0
Placement count  : 2
Replacement count: 0

-------------------------------------
system time   : 2
page reference: 2
page status   : hit

frame[000]     2 use=1 <-- framePointer
frame[001]     3 use=1
frame[002] EMPTY use=1

Hit  ratio : 1 / 3 (ratio = 0.333333)
Fault ratio: 2 / 3 (ratio = 0.666667)

Hit count        : 1
Placement count  : 2
Replacement count: 0

-------------------------------------
system time   : 3
page reference: 1
page status   : fault (placement)

frame[000]     2 use=1 <-- framePointer
frame[001]     3 use=1
frame[002]     1 use=1

Hit  ratio : 1 / 4 (ratio = 0.25)
Fault ratio: 3 / 4 (ratio = 0.75)

Hit count        : 1
Placement count  : 3
Replacement count: 0

-------------------------------------
system time   : 4
page reference: 5
page status   : fault (replacement)

frame[000]     5 use=1
frame[001]     3 use=0 <-- framePointer
frame[002]     1 use=0

Hit  ratio : 1 / 5 (ratio = 0.2)
Fault ratio: 4 / 5 (ratio = 0.8)

Hit count        : 1
Placement count  : 3
Replacement count: 1

-------------------------------------
system time   : 5
page reference: 2
page status   : fault (replacement)

frame[000]     5 use=1
frame[001]     2 use=1
frame[002]     1 use=0 <-- framePointer

Hit  ratio : 1 / 6 (ratio = 0.166667)
Fault ratio: 5 / 6 (ratio = 0.833333)

Hit count        : 1
Placement count  : 3
Replacement count: 2

-------------------------------------
system time   : 6
page reference: 4
page status   : fault (replacement)

frame[000]     5 use=1 <-- framePointer
frame[001]     2 use=1
frame[002]     4 use=1

Hit  ratio : 1 / 7 (ratio = 0.142857)
Fault ratio: 6 / 7 (ratio = 0.857143)

Hit count        : 1
Placement count  : 3
Replacement count: 3

-------------------------------------
system time   : 7
page reference: 5
page status   : hit

frame[000]     5 use=1 <-- framePointer
frame[001]     2 use=1
frame[002]     4 use=1

Hit  ratio : 2 / 8 (ratio = 0.25)
Fault ratio: 6 / 8 (ratio = 0.75)

Hit count        : 2
Placement count  : 3
Replacement count: 3

-------------------------------------
system time   : 8
page reference: 3
page status   : fault (replacement)

frame[000]     3 use=1
frame[001]     2 use=0 <-- framePointer
frame[002]     4 use=0

Hit  ratio : 2 / 9 (ratio = 0.222222)
Fault ratio: 7 / 9 (ratio = 0.777778)

Hit count        : 2
Placement count  : 3
Replacement count: 4

-------------------------------------
system time   : 9
page reference: 2
page status   : hit

frame[000]     3 use=1
frame[001]     2 use=1 <-- framePointer
frame[002]     4 use=0

Hit  ratio : 3 / 10 (ratio = 0.3)
Fault ratio: 7 / 10 (ratio = 0.7)

Hit count        : 3
Placement count  : 3
Replacement count: 4

-------------------------------------
system time   : 10
page reference: 5
page status   : fault (replacement)

frame[000]     3 use=1 <-- framePointer
frame[001]     2 use=0
frame[002]     5 use=1

Hit  ratio : 3 / 11 (ratio = 0.272727)
Fault ratio: 8 / 11 (ratio = 0.727273)

Hit count        : 3
Placement count  : 3
Replacement count: 5

-------------------------------------
system time   : 11
page reference: 2
page status   : hit

frame[000]     3 use=1 <-- framePointer
frame[001]     2 use=1
frame[002]     5 use=1

Hit  ratio : 4 / 12 (ratio = 0.333333)
Fault ratio: 8 / 12 (ratio = 0.666667)

Hit count        : 4
Placement count  : 3
Replacement count: 5

