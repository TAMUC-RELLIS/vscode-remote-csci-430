Paging Simulation
=====================================
memory size          : 4
reference stream size: 12
paging scheme        : fifo

-------------------------------------
system time   : 0
page reference: 2
page status   : fault (placement)

frame[000]     2 <-- framePointer
frame[001] EMPTY
frame[002] EMPTY
frame[003] EMPTY

Hit  ratio : 0 / 1 (ratio = 0)
Fault ratio: 1 / 1 (ratio = 1)

Hit count        : 0
Placement count  : 1
Replacement count: 0

-------------------------------------
system time   : 1
page reference: 3
page status   : fault (placement)

frame[000]     2 <-- framePointer
frame[001]     3
frame[002] EMPTY
frame[003] EMPTY

Hit  ratio : 0 / 2 (ratio = 0)
Fault ratio: 2 / 2 (ratio = 1)

Hit count        : 0
Placement count  : 2
Replacement count: 0

-------------------------------------
system time   : 2
page reference: 2
page status   : hit

frame[000]     2 <-- framePointer
frame[001]     3
frame[002] EMPTY
frame[003] EMPTY

Hit  ratio : 1 / 3 (ratio = 0.333333)
Fault ratio: 2 / 3 (ratio = 0.666667)

Hit count        : 1
Placement count  : 2
Replacement count: 0

-------------------------------------
system time   : 3
page reference: 1
page status   : fault (placement)

frame[000]     2 <-- framePointer
frame[001]     3
frame[002]     1
frame[003] EMPTY

Hit  ratio : 1 / 4 (ratio = 0.25)
Fault ratio: 3 / 4 (ratio = 0.75)

Hit count        : 1
Placement count  : 3
Replacement count: 0

-------------------------------------
system time   : 4
page reference: 5
page status   : fault (placement)

frame[000]     2 <-- framePointer
frame[001]     3
frame[002]     1
frame[003]     5

Hit  ratio : 1 / 5 (ratio = 0.2)
Fault ratio: 4 / 5 (ratio = 0.8)

Hit count        : 1
Placement count  : 4
Replacement count: 0

-------------------------------------
system time   : 5
page reference: 2
page status   : hit

frame[000]     2 <-- framePointer
frame[001]     3
frame[002]     1
frame[003]     5

Hit  ratio : 2 / 6 (ratio = 0.333333)
Fault ratio: 4 / 6 (ratio = 0.666667)

Hit count        : 2
Placement count  : 4
Replacement count: 0

-------------------------------------
system time   : 6
page reference: 4
page status   : fault (replacement)

frame[000]     4
frame[001]     3 <-- framePointer
frame[002]     1
frame[003]     5

Hit  ratio : 2 / 7 (ratio = 0.285714)
Fault ratio: 5 / 7 (ratio = 0.714286)

Hit count        : 2
Placement count  : 4
Replacement count: 1

-------------------------------------
system time   : 7
page reference: 5
page status   : hit

frame[000]     4
frame[001]     3 <-- framePointer
frame[002]     1
frame[003]     5

Hit  ratio : 3 / 8 (ratio = 0.375)
Fault ratio: 5 / 8 (ratio = 0.625)

Hit count        : 3
Placement count  : 4
Replacement count: 1

-------------------------------------
system time   : 8
page reference: 3
page status   : hit

frame[000]     4
frame[001]     3 <-- framePointer
frame[002]     1
frame[003]     5

Hit  ratio : 4 / 9 (ratio = 0.444444)
Fault ratio: 5 / 9 (ratio = 0.555556)

Hit count        : 4
Placement count  : 4
Replacement count: 1

-------------------------------------
system time   : 9
page reference: 2
page status   : fault (replacement)

frame[000]     4
frame[001]     2
frame[002]     1 <-- framePointer
frame[003]     5

Hit  ratio : 4 / 10 (ratio = 0.4)
Fault ratio: 6 / 10 (ratio = 0.6)

Hit count        : 4
Placement count  : 4
Replacement count: 2

-------------------------------------
system time   : 10
page reference: 5
page status   : hit

frame[000]     4
frame[001]     2
frame[002]     1 <-- framePointer
frame[003]     5

Hit  ratio : 5 / 11 (ratio = 0.454545)
Fault ratio: 6 / 11 (ratio = 0.545455)

Hit count        : 5
Placement count  : 4
Replacement count: 2

-------------------------------------
system time   : 11
page reference: 2
page status   : hit

frame[000]     4
frame[001]     2
frame[002]     1 <-- framePointer
frame[003]     5

Hit  ratio : 6 / 12 (ratio = 0.5)
Fault ratio: 6 / 12 (ratio = 0.5)

Hit count        : 6
Placement count  : 4
Replacement count: 2

