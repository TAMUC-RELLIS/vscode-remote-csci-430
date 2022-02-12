Paging Simulation
=====================================
memory size          : 4
reference stream size: 34
paging scheme        : fifo

-------------------------------------
system time   : 0
page reference: 1
page status   : fault (placement)

frame[000]     1 <-- framePointer
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
page reference: 8
page status   : fault (placement)

frame[000]     1 <-- framePointer
frame[001]     8
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
page status   : fault (placement)

frame[000]     1 <-- framePointer
frame[001]     8
frame[002]     2
frame[003] EMPTY

Hit  ratio : 0 / 3 (ratio = 0)
Fault ratio: 3 / 3 (ratio = 1)

Hit count        : 0
Placement count  : 3
Replacement count: 0

-------------------------------------
system time   : 3
page reference: 2
page status   : hit

frame[000]     1 <-- framePointer
frame[001]     8
frame[002]     2
frame[003] EMPTY

Hit  ratio : 1 / 4 (ratio = 0.25)
Fault ratio: 3 / 4 (ratio = 0.75)

Hit count        : 1
Placement count  : 3
Replacement count: 0

-------------------------------------
system time   : 4
page reference: 1
page status   : hit

frame[000]     1 <-- framePointer
frame[001]     8
frame[002]     2
frame[003] EMPTY

Hit  ratio : 2 / 5 (ratio = 0.4)
Fault ratio: 3 / 5 (ratio = 0.6)

Hit count        : 2
Placement count  : 3
Replacement count: 0

-------------------------------------
system time   : 5
page reference: 7
page status   : fault (placement)

frame[000]     1 <-- framePointer
frame[001]     8
frame[002]     2
frame[003]     7

Hit  ratio : 2 / 6 (ratio = 0.333333)
Fault ratio: 4 / 6 (ratio = 0.666667)

Hit count        : 2
Placement count  : 4
Replacement count: 0

-------------------------------------
system time   : 6
page reference: 6
page status   : fault (replacement)

frame[000]     6
frame[001]     8 <-- framePointer
frame[002]     2
frame[003]     7

Hit  ratio : 2 / 7 (ratio = 0.285714)
Fault ratio: 5 / 7 (ratio = 0.714286)

Hit count        : 2
Placement count  : 4
Replacement count: 1

-------------------------------------
system time   : 7
page reference: 7
page status   : hit

frame[000]     6
frame[001]     8 <-- framePointer
frame[002]     2
frame[003]     7

Hit  ratio : 3 / 8 (ratio = 0.375)
Fault ratio: 5 / 8 (ratio = 0.625)

Hit count        : 3
Placement count  : 4
Replacement count: 1

-------------------------------------
system time   : 8
page reference: 8
page status   : hit

frame[000]     6
frame[001]     8 <-- framePointer
frame[002]     2
frame[003]     7

Hit  ratio : 4 / 9 (ratio = 0.444444)
Fault ratio: 5 / 9 (ratio = 0.555556)

Hit count        : 4
Placement count  : 4
Replacement count: 1

-------------------------------------
system time   : 9
page reference: 1
page status   : fault (replacement)

frame[000]     6
frame[001]     1
frame[002]     2 <-- framePointer
frame[003]     7

Hit  ratio : 4 / 10 (ratio = 0.4)
Fault ratio: 6 / 10 (ratio = 0.6)

Hit count        : 4
Placement count  : 4
Replacement count: 2

-------------------------------------
system time   : 10
page reference: 2
page status   : hit

frame[000]     6
frame[001]     1
frame[002]     2 <-- framePointer
frame[003]     7

Hit  ratio : 5 / 11 (ratio = 0.454545)
Fault ratio: 6 / 11 (ratio = 0.545455)

Hit count        : 5
Placement count  : 4
Replacement count: 2

-------------------------------------
system time   : 11
page reference: 8
page status   : fault (replacement)

frame[000]     6
frame[001]     1
frame[002]     8
frame[003]     7 <-- framePointer

Hit  ratio : 5 / 12 (ratio = 0.416667)
Fault ratio: 7 / 12 (ratio = 0.583333)

Hit count        : 5
Placement count  : 4
Replacement count: 3

-------------------------------------
system time   : 12
page reference: 3
page status   : fault (replacement)

frame[000]     6 <-- framePointer
frame[001]     1
frame[002]     8
frame[003]     3

Hit  ratio : 5 / 13 (ratio = 0.384615)
Fault ratio: 8 / 13 (ratio = 0.615385)

Hit count        : 5
Placement count  : 4
Replacement count: 4

-------------------------------------
system time   : 13
page reference: 8
page status   : hit

frame[000]     6 <-- framePointer
frame[001]     1
frame[002]     8
frame[003]     3

Hit  ratio : 6 / 14 (ratio = 0.428571)
Fault ratio: 8 / 14 (ratio = 0.571429)

Hit count        : 6
Placement count  : 4
Replacement count: 4

-------------------------------------
system time   : 14
page reference: 4
page status   : fault (replacement)

frame[000]     4
frame[001]     1 <-- framePointer
frame[002]     8
frame[003]     3

Hit  ratio : 6 / 15 (ratio = 0.4)
Fault ratio: 9 / 15 (ratio = 0.6)

Hit count        : 6
Placement count  : 4
Replacement count: 5

-------------------------------------
system time   : 15
page reference: 5
page status   : fault (replacement)

frame[000]     4
frame[001]     5
frame[002]     8 <-- framePointer
frame[003]     3

Hit  ratio : 6 / 16 (ratio = 0.375)
Fault ratio: 10 / 16 (ratio = 0.625)

Hit count        : 6
Placement count  : 4
Replacement count: 6

-------------------------------------
system time   : 16
page reference: 1
page status   : fault (replacement)

frame[000]     4
frame[001]     5
frame[002]     1
frame[003]     3 <-- framePointer

Hit  ratio : 6 / 17 (ratio = 0.352941)
Fault ratio: 11 / 17 (ratio = 0.647059)

Hit count        : 6
Placement count  : 4
Replacement count: 7

-------------------------------------
system time   : 17
page reference: 5
page status   : hit

frame[000]     4
frame[001]     5
frame[002]     1
frame[003]     3 <-- framePointer

Hit  ratio : 7 / 18 (ratio = 0.388889)
Fault ratio: 11 / 18 (ratio = 0.611111)

Hit count        : 7
Placement count  : 4
Replacement count: 7

-------------------------------------
system time   : 18
page reference: 2
page status   : fault (replacement)

frame[000]     4 <-- framePointer
frame[001]     5
frame[002]     1
frame[003]     2

Hit  ratio : 7 / 19 (ratio = 0.368421)
Fault ratio: 12 / 19 (ratio = 0.631579)

Hit count        : 7
Placement count  : 4
Replacement count: 8

-------------------------------------
system time   : 19
page reference: 4
page status   : hit

frame[000]     4 <-- framePointer
frame[001]     5
frame[002]     1
frame[003]     2

Hit  ratio : 8 / 20 (ratio = 0.4)
Fault ratio: 12 / 20 (ratio = 0.6)

Hit count        : 8
Placement count  : 4
Replacement count: 8

-------------------------------------
system time   : 20
page reference: 5
page status   : hit

frame[000]     4 <-- framePointer
frame[001]     5
frame[002]     1
frame[003]     2

Hit  ratio : 9 / 21 (ratio = 0.428571)
Fault ratio: 12 / 21 (ratio = 0.571429)

Hit count        : 9
Placement count  : 4
Replacement count: 8

-------------------------------------
system time   : 21
page reference: 6
page status   : fault (replacement)

frame[000]     6
frame[001]     5 <-- framePointer
frame[002]     1
frame[003]     2

Hit  ratio : 9 / 22 (ratio = 0.409091)
Fault ratio: 13 / 22 (ratio = 0.590909)

Hit count        : 9
Placement count  : 4
Replacement count: 9

-------------------------------------
system time   : 22
page reference: 7
page status   : fault (replacement)

frame[000]     6
frame[001]     7
frame[002]     1 <-- framePointer
frame[003]     2

Hit  ratio : 9 / 23 (ratio = 0.391304)
Fault ratio: 14 / 23 (ratio = 0.608696)

Hit count        : 9
Placement count  : 4
Replacement count: 10

-------------------------------------
system time   : 23
page reference: 6
page status   : hit

frame[000]     6
frame[001]     7
frame[002]     1 <-- framePointer
frame[003]     2

Hit  ratio : 10 / 24 (ratio = 0.416667)
Fault ratio: 14 / 24 (ratio = 0.583333)

Hit count        : 10
Placement count  : 4
Replacement count: 10

-------------------------------------
system time   : 24
page reference: 7
page status   : hit

frame[000]     6
frame[001]     7
frame[002]     1 <-- framePointer
frame[003]     2

Hit  ratio : 11 / 25 (ratio = 0.44)
Fault ratio: 14 / 25 (ratio = 0.56)

Hit count        : 11
Placement count  : 4
Replacement count: 10

-------------------------------------
system time   : 25
page reference: 2
page status   : hit

frame[000]     6
frame[001]     7
frame[002]     1 <-- framePointer
frame[003]     2

Hit  ratio : 12 / 26 (ratio = 0.461538)
Fault ratio: 14 / 26 (ratio = 0.538462)

Hit count        : 12
Placement count  : 4
Replacement count: 10

-------------------------------------
system time   : 26
page reference: 4
page status   : fault (replacement)

frame[000]     6
frame[001]     7
frame[002]     4
frame[003]     2 <-- framePointer

Hit  ratio : 12 / 27 (ratio = 0.444444)
Fault ratio: 15 / 27 (ratio = 0.555556)

Hit count        : 12
Placement count  : 4
Replacement count: 11

-------------------------------------
system time   : 27
page reference: 2
page status   : hit

frame[000]     6
frame[001]     7
frame[002]     4
frame[003]     2 <-- framePointer

Hit  ratio : 13 / 28 (ratio = 0.464286)
Fault ratio: 15 / 28 (ratio = 0.535714)

Hit count        : 13
Placement count  : 4
Replacement count: 11

-------------------------------------
system time   : 28
page reference: 7
page status   : hit

frame[000]     6
frame[001]     7
frame[002]     4
frame[003]     2 <-- framePointer

Hit  ratio : 14 / 29 (ratio = 0.482759)
Fault ratio: 15 / 29 (ratio = 0.517241)

Hit count        : 14
Placement count  : 4
Replacement count: 11

-------------------------------------
system time   : 29
page reference: 3
page status   : fault (replacement)

frame[000]     6 <-- framePointer
frame[001]     7
frame[002]     4
frame[003]     3

Hit  ratio : 14 / 30 (ratio = 0.466667)
Fault ratio: 16 / 30 (ratio = 0.533333)

Hit count        : 14
Placement count  : 4
Replacement count: 12

-------------------------------------
system time   : 30
page reference: 3
page status   : hit

frame[000]     6 <-- framePointer
frame[001]     7
frame[002]     4
frame[003]     3

Hit  ratio : 15 / 31 (ratio = 0.483871)
Fault ratio: 16 / 31 (ratio = 0.516129)

Hit count        : 15
Placement count  : 4
Replacement count: 12

-------------------------------------
system time   : 31
page reference: 2
page status   : fault (replacement)

frame[000]     2
frame[001]     7 <-- framePointer
frame[002]     4
frame[003]     3

Hit  ratio : 15 / 32 (ratio = 0.46875)
Fault ratio: 17 / 32 (ratio = 0.53125)

Hit count        : 15
Placement count  : 4
Replacement count: 13

-------------------------------------
system time   : 32
page reference: 3
page status   : hit

frame[000]     2
frame[001]     7 <-- framePointer
frame[002]     4
frame[003]     3

Hit  ratio : 16 / 33 (ratio = 0.484848)
Fault ratio: 17 / 33 (ratio = 0.515152)

Hit count        : 16
Placement count  : 4
Replacement count: 13

-------------------------------------
system time   : 33
page reference: 4
page status   : hit

frame[000]     2
frame[001]     7 <-- framePointer
frame[002]     4
frame[003]     3

Hit  ratio : 17 / 34 (ratio = 0.5)
Fault ratio: 17 / 34 (ratio = 0.5)

Hit count        : 17
Placement count  : 4
Replacement count: 13

