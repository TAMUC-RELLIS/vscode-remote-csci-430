Paging Simulation
=====================================
memory size          : 5
reference stream size: 30
paging scheme        : fifo

-------------------------------------
system time   : 0
page reference: 6
page status   : fault (placement)

frame[000]     6 <-- framePointer
frame[001] EMPTY
frame[002] EMPTY
frame[003] EMPTY
frame[004] EMPTY

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
frame[003] EMPTY
frame[004] EMPTY

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
frame[003] EMPTY
frame[004] EMPTY

Hit  ratio : 0 / 3 (ratio = 0)
Fault ratio: 3 / 3 (ratio = 1)

Hit count        : 0
Placement count  : 3
Replacement count: 0

-------------------------------------
system time   : 3
page reference: 4
page status   : fault (placement)

frame[000]     6 <-- framePointer
frame[001]     5
frame[002]     2
frame[003]     4
frame[004] EMPTY

Hit  ratio : 0 / 4 (ratio = 0)
Fault ratio: 4 / 4 (ratio = 1)

Hit count        : 0
Placement count  : 4
Replacement count: 0

-------------------------------------
system time   : 4
page reference: 2
page status   : hit

frame[000]     6 <-- framePointer
frame[001]     5
frame[002]     2
frame[003]     4
frame[004] EMPTY

Hit  ratio : 1 / 5 (ratio = 0.2)
Fault ratio: 4 / 5 (ratio = 0.8)

Hit count        : 1
Placement count  : 4
Replacement count: 0

-------------------------------------
system time   : 5
page reference: 4
page status   : hit

frame[000]     6 <-- framePointer
frame[001]     5
frame[002]     2
frame[003]     4
frame[004] EMPTY

Hit  ratio : 2 / 6 (ratio = 0.333333)
Fault ratio: 4 / 6 (ratio = 0.666667)

Hit count        : 2
Placement count  : 4
Replacement count: 0

-------------------------------------
system time   : 6
page reference: 3
page status   : fault (placement)

frame[000]     6 <-- framePointer
frame[001]     5
frame[002]     2
frame[003]     4
frame[004]     3

Hit  ratio : 2 / 7 (ratio = 0.285714)
Fault ratio: 5 / 7 (ratio = 0.714286)

Hit count        : 2
Placement count  : 5
Replacement count: 0

-------------------------------------
system time   : 7
page reference: 5
page status   : hit

frame[000]     6 <-- framePointer
frame[001]     5
frame[002]     2
frame[003]     4
frame[004]     3

Hit  ratio : 3 / 8 (ratio = 0.375)
Fault ratio: 5 / 8 (ratio = 0.625)

Hit count        : 3
Placement count  : 5
Replacement count: 0

-------------------------------------
system time   : 8
page reference: 3
page status   : hit

frame[000]     6 <-- framePointer
frame[001]     5
frame[002]     2
frame[003]     4
frame[004]     3

Hit  ratio : 4 / 9 (ratio = 0.444444)
Fault ratio: 5 / 9 (ratio = 0.555556)

Hit count        : 4
Placement count  : 5
Replacement count: 0

-------------------------------------
system time   : 9
page reference: 6
page status   : hit

frame[000]     6 <-- framePointer
frame[001]     5
frame[002]     2
frame[003]     4
frame[004]     3

Hit  ratio : 5 / 10 (ratio = 0.5)
Fault ratio: 5 / 10 (ratio = 0.5)

Hit count        : 5
Placement count  : 5
Replacement count: 0

-------------------------------------
system time   : 10
page reference: 7
page status   : fault (replacement)

frame[000]     7
frame[001]     5 <-- framePointer
frame[002]     2
frame[003]     4
frame[004]     3

Hit  ratio : 5 / 11 (ratio = 0.454545)
Fault ratio: 6 / 11 (ratio = 0.545455)

Hit count        : 5
Placement count  : 5
Replacement count: 1

-------------------------------------
system time   : 11
page reference: 5
page status   : hit

frame[000]     7
frame[001]     5 <-- framePointer
frame[002]     2
frame[003]     4
frame[004]     3

Hit  ratio : 6 / 12 (ratio = 0.5)
Fault ratio: 6 / 12 (ratio = 0.5)

Hit count        : 6
Placement count  : 5
Replacement count: 1

-------------------------------------
system time   : 12
page reference: 3
page status   : hit

frame[000]     7
frame[001]     5 <-- framePointer
frame[002]     2
frame[003]     4
frame[004]     3

Hit  ratio : 7 / 13 (ratio = 0.538462)
Fault ratio: 6 / 13 (ratio = 0.461538)

Hit count        : 7
Placement count  : 5
Replacement count: 1

-------------------------------------
system time   : 13
page reference: 5
page status   : hit

frame[000]     7
frame[001]     5 <-- framePointer
frame[002]     2
frame[003]     4
frame[004]     3

Hit  ratio : 8 / 14 (ratio = 0.571429)
Fault ratio: 6 / 14 (ratio = 0.428571)

Hit count        : 8
Placement count  : 5
Replacement count: 1

-------------------------------------
system time   : 14
page reference: 4
page status   : hit

frame[000]     7
frame[001]     5 <-- framePointer
frame[002]     2
frame[003]     4
frame[004]     3

Hit  ratio : 9 / 15 (ratio = 0.6)
Fault ratio: 6 / 15 (ratio = 0.4)

Hit count        : 9
Placement count  : 5
Replacement count: 1

-------------------------------------
system time   : 15
page reference: 3
page status   : hit

frame[000]     7
frame[001]     5 <-- framePointer
frame[002]     2
frame[003]     4
frame[004]     3

Hit  ratio : 10 / 16 (ratio = 0.625)
Fault ratio: 6 / 16 (ratio = 0.375)

Hit count        : 10
Placement count  : 5
Replacement count: 1

-------------------------------------
system time   : 16
page reference: 4
page status   : hit

frame[000]     7
frame[001]     5 <-- framePointer
frame[002]     2
frame[003]     4
frame[004]     3

Hit  ratio : 11 / 17 (ratio = 0.647059)
Fault ratio: 6 / 17 (ratio = 0.352941)

Hit count        : 11
Placement count  : 5
Replacement count: 1

-------------------------------------
system time   : 17
page reference: 7
page status   : hit

frame[000]     7
frame[001]     5 <-- framePointer
frame[002]     2
frame[003]     4
frame[004]     3

Hit  ratio : 12 / 18 (ratio = 0.666667)
Fault ratio: 6 / 18 (ratio = 0.333333)

Hit count        : 12
Placement count  : 5
Replacement count: 1

-------------------------------------
system time   : 18
page reference: 2
page status   : hit

frame[000]     7
frame[001]     5 <-- framePointer
frame[002]     2
frame[003]     4
frame[004]     3

Hit  ratio : 13 / 19 (ratio = 0.684211)
Fault ratio: 6 / 19 (ratio = 0.315789)

Hit count        : 13
Placement count  : 5
Replacement count: 1

-------------------------------------
system time   : 19
page reference: 1
page status   : fault (replacement)

frame[000]     7
frame[001]     1
frame[002]     2 <-- framePointer
frame[003]     4
frame[004]     3

Hit  ratio : 13 / 20 (ratio = 0.65)
Fault ratio: 7 / 20 (ratio = 0.35)

Hit count        : 13
Placement count  : 5
Replacement count: 2

-------------------------------------
system time   : 20
page reference: 3
page status   : hit

frame[000]     7
frame[001]     1
frame[002]     2 <-- framePointer
frame[003]     4
frame[004]     3

Hit  ratio : 14 / 21 (ratio = 0.666667)
Fault ratio: 7 / 21 (ratio = 0.333333)

Hit count        : 14
Placement count  : 5
Replacement count: 2

-------------------------------------
system time   : 21
page reference: 7
page status   : hit

frame[000]     7
frame[001]     1
frame[002]     2 <-- framePointer
frame[003]     4
frame[004]     3

Hit  ratio : 15 / 22 (ratio = 0.681818)
Fault ratio: 7 / 22 (ratio = 0.318182)

Hit count        : 15
Placement count  : 5
Replacement count: 2

-------------------------------------
system time   : 22
page reference: 6
page status   : fault (replacement)

frame[000]     7
frame[001]     1
frame[002]     6
frame[003]     4 <-- framePointer
frame[004]     3

Hit  ratio : 15 / 23 (ratio = 0.652174)
Fault ratio: 8 / 23 (ratio = 0.347826)

Hit count        : 15
Placement count  : 5
Replacement count: 3

-------------------------------------
system time   : 23
page reference: 4
page status   : hit

frame[000]     7
frame[001]     1
frame[002]     6
frame[003]     4 <-- framePointer
frame[004]     3

Hit  ratio : 16 / 24 (ratio = 0.666667)
Fault ratio: 8 / 24 (ratio = 0.333333)

Hit count        : 16
Placement count  : 5
Replacement count: 3

-------------------------------------
system time   : 24
page reference: 1
page status   : hit

frame[000]     7
frame[001]     1
frame[002]     6
frame[003]     4 <-- framePointer
frame[004]     3

Hit  ratio : 17 / 25 (ratio = 0.68)
Fault ratio: 8 / 25 (ratio = 0.32)

Hit count        : 17
Placement count  : 5
Replacement count: 3

-------------------------------------
system time   : 25
page reference: 2
page status   : fault (replacement)

frame[000]     7
frame[001]     1
frame[002]     6
frame[003]     2
frame[004]     3 <-- framePointer

Hit  ratio : 17 / 26 (ratio = 0.653846)
Fault ratio: 9 / 26 (ratio = 0.346154)

Hit count        : 17
Placement count  : 5
Replacement count: 4

-------------------------------------
system time   : 26
page reference: 1
page status   : hit

frame[000]     7
frame[001]     1
frame[002]     6
frame[003]     2
frame[004]     3 <-- framePointer

Hit  ratio : 18 / 27 (ratio = 0.666667)
Fault ratio: 9 / 27 (ratio = 0.333333)

Hit count        : 18
Placement count  : 5
Replacement count: 4

-------------------------------------
system time   : 27
page reference: 3
page status   : hit

frame[000]     7
frame[001]     1
frame[002]     6
frame[003]     2
frame[004]     3 <-- framePointer

Hit  ratio : 19 / 28 (ratio = 0.678571)
Fault ratio: 9 / 28 (ratio = 0.321429)

Hit count        : 19
Placement count  : 5
Replacement count: 4

-------------------------------------
system time   : 28
page reference: 4
page status   : fault (replacement)

frame[000]     7 <-- framePointer
frame[001]     1
frame[002]     6
frame[003]     2
frame[004]     4

Hit  ratio : 19 / 29 (ratio = 0.655172)
Fault ratio: 10 / 29 (ratio = 0.344828)

Hit count        : 19
Placement count  : 5
Replacement count: 5

-------------------------------------
system time   : 29
page reference: 7
page status   : hit

frame[000]     7 <-- framePointer
frame[001]     1
frame[002]     6
frame[003]     2
frame[004]     4

Hit  ratio : 20 / 30 (ratio = 0.666667)
Fault ratio: 10 / 30 (ratio = 0.333333)

Hit count        : 20
Placement count  : 5
Replacement count: 5

