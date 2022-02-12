Paging Simulation
=====================================
memory size          : 3
reference stream size: 30
paging scheme        : fifo

-------------------------------------
system time   : 0
page reference: 6
page status   : fault (placement)

frame[000]     6 use=1 <-- framePointer
frame[001] EMPTY use=1
frame[002] EMPTY use=1

Hit  ratio : 0 / 1 (ratio = 0)
Fault ratio: 1 / 1 (ratio = 1)

Hit count        : 0
Placement count  : 1
Replacement count: 0

-------------------------------------
system time   : 1
page reference: 5
page status   : fault (placement)

frame[000]     6 use=1 <-- framePointer
frame[001]     5 use=1
frame[002] EMPTY use=1

Hit  ratio : 0 / 2 (ratio = 0)
Fault ratio: 2 / 2 (ratio = 1)

Hit count        : 0
Placement count  : 2
Replacement count: 0

-------------------------------------
system time   : 2
page reference: 2
page status   : fault (placement)

frame[000]     6 use=1 <-- framePointer
frame[001]     5 use=1
frame[002]     2 use=1

Hit  ratio : 0 / 3 (ratio = 0)
Fault ratio: 3 / 3 (ratio = 1)

Hit count        : 0
Placement count  : 3
Replacement count: 0

-------------------------------------
system time   : 3
page reference: 4
page status   : fault (replacement)

frame[000]     4 use=1
frame[001]     5 use=0 <-- framePointer
frame[002]     2 use=0

Hit  ratio : 0 / 4 (ratio = 0)
Fault ratio: 4 / 4 (ratio = 1)

Hit count        : 0
Placement count  : 3
Replacement count: 1

-------------------------------------
system time   : 4
page reference: 2
page status   : hit

frame[000]     4 use=1
frame[001]     5 use=0 <-- framePointer
frame[002]     2 use=1

Hit  ratio : 1 / 5 (ratio = 0.2)
Fault ratio: 4 / 5 (ratio = 0.8)

Hit count        : 1
Placement count  : 3
Replacement count: 1

-------------------------------------
system time   : 5
page reference: 4
page status   : hit

frame[000]     4 use=1
frame[001]     5 use=0 <-- framePointer
frame[002]     2 use=1

Hit  ratio : 2 / 6 (ratio = 0.333333)
Fault ratio: 4 / 6 (ratio = 0.666667)

Hit count        : 2
Placement count  : 3
Replacement count: 1

-------------------------------------
system time   : 6
page reference: 3
page status   : fault (replacement)

frame[000]     4 use=1
frame[001]     3 use=1
frame[002]     2 use=1 <-- framePointer

Hit  ratio : 2 / 7 (ratio = 0.285714)
Fault ratio: 5 / 7 (ratio = 0.714286)

Hit count        : 2
Placement count  : 3
Replacement count: 2

-------------------------------------
system time   : 7
page reference: 5
page status   : fault (replacement)

frame[000]     4 use=0 <-- framePointer
frame[001]     3 use=0
frame[002]     5 use=1

Hit  ratio : 2 / 8 (ratio = 0.25)
Fault ratio: 6 / 8 (ratio = 0.75)

Hit count        : 2
Placement count  : 3
Replacement count: 3

-------------------------------------
system time   : 8
page reference: 3
page status   : hit

frame[000]     4 use=0 <-- framePointer
frame[001]     3 use=1
frame[002]     5 use=1

Hit  ratio : 3 / 9 (ratio = 0.333333)
Fault ratio: 6 / 9 (ratio = 0.666667)

Hit count        : 3
Placement count  : 3
Replacement count: 3

-------------------------------------
system time   : 9
page reference: 6
page status   : fault (replacement)

frame[000]     6 use=1
frame[001]     3 use=1 <-- framePointer
frame[002]     5 use=1

Hit  ratio : 3 / 10 (ratio = 0.3)
Fault ratio: 7 / 10 (ratio = 0.7)

Hit count        : 3
Placement count  : 3
Replacement count: 4

-------------------------------------
system time   : 10
page reference: 7
page status   : fault (replacement)

frame[000]     6 use=0
frame[001]     7 use=1
frame[002]     5 use=0 <-- framePointer

Hit  ratio : 3 / 11 (ratio = 0.272727)
Fault ratio: 8 / 11 (ratio = 0.727273)

Hit count        : 3
Placement count  : 3
Replacement count: 5

-------------------------------------
system time   : 11
page reference: 5
page status   : hit

frame[000]     6 use=0
frame[001]     7 use=1
frame[002]     5 use=1 <-- framePointer

Hit  ratio : 4 / 12 (ratio = 0.333333)
Fault ratio: 8 / 12 (ratio = 0.666667)

Hit count        : 4
Placement count  : 3
Replacement count: 5

-------------------------------------
system time   : 12
page reference: 3
page status   : fault (replacement)

frame[000]     3 use=1
frame[001]     7 use=1 <-- framePointer
frame[002]     5 use=0

Hit  ratio : 4 / 13 (ratio = 0.307692)
Fault ratio: 9 / 13 (ratio = 0.692308)

Hit count        : 4
Placement count  : 3
Replacement count: 6

-------------------------------------
system time   : 13
page reference: 5
page status   : hit

frame[000]     3 use=1
frame[001]     7 use=1 <-- framePointer
frame[002]     5 use=1

Hit  ratio : 5 / 14 (ratio = 0.357143)
Fault ratio: 9 / 14 (ratio = 0.642857)

Hit count        : 5
Placement count  : 3
Replacement count: 6

-------------------------------------
system time   : 14
page reference: 4
page status   : fault (replacement)

frame[000]     3 use=0
frame[001]     4 use=1
frame[002]     5 use=0 <-- framePointer

Hit  ratio : 5 / 15 (ratio = 0.333333)
Fault ratio: 10 / 15 (ratio = 0.666667)

Hit count        : 5
Placement count  : 3
Replacement count: 7

-------------------------------------
system time   : 15
page reference: 3
page status   : hit

frame[000]     3 use=1
frame[001]     4 use=1
frame[002]     5 use=0 <-- framePointer

Hit  ratio : 6 / 16 (ratio = 0.375)
Fault ratio: 10 / 16 (ratio = 0.625)

Hit count        : 6
Placement count  : 3
Replacement count: 7

-------------------------------------
system time   : 16
page reference: 4
page status   : hit

frame[000]     3 use=1
frame[001]     4 use=1
frame[002]     5 use=0 <-- framePointer

Hit  ratio : 7 / 17 (ratio = 0.411765)
Fault ratio: 10 / 17 (ratio = 0.588235)

Hit count        : 7
Placement count  : 3
Replacement count: 7

-------------------------------------
system time   : 17
page reference: 7
page status   : fault (replacement)

frame[000]     3 use=1 <-- framePointer
frame[001]     4 use=1
frame[002]     7 use=1

Hit  ratio : 7 / 18 (ratio = 0.388889)
Fault ratio: 11 / 18 (ratio = 0.611111)

Hit count        : 7
Placement count  : 3
Replacement count: 8

-------------------------------------
system time   : 18
page reference: 2
page status   : fault (replacement)

frame[000]     2 use=1
frame[001]     4 use=0 <-- framePointer
frame[002]     7 use=0

Hit  ratio : 7 / 19 (ratio = 0.368421)
Fault ratio: 12 / 19 (ratio = 0.631579)

Hit count        : 7
Placement count  : 3
Replacement count: 9

-------------------------------------
system time   : 19
page reference: 1
page status   : fault (replacement)

frame[000]     2 use=1
frame[001]     1 use=1
frame[002]     7 use=0 <-- framePointer

Hit  ratio : 7 / 20 (ratio = 0.35)
Fault ratio: 13 / 20 (ratio = 0.65)

Hit count        : 7
Placement count  : 3
Replacement count: 10

-------------------------------------
system time   : 20
page reference: 3
page status   : fault (replacement)

frame[000]     2 use=1 <-- framePointer
frame[001]     1 use=1
frame[002]     3 use=1

Hit  ratio : 7 / 21 (ratio = 0.333333)
Fault ratio: 14 / 21 (ratio = 0.666667)

Hit count        : 7
Placement count  : 3
Replacement count: 11

-------------------------------------
system time   : 21
page reference: 7
page status   : fault (replacement)

frame[000]     7 use=1
frame[001]     1 use=0 <-- framePointer
frame[002]     3 use=0

Hit  ratio : 7 / 22 (ratio = 0.318182)
Fault ratio: 15 / 22 (ratio = 0.681818)

Hit count        : 7
Placement count  : 3
Replacement count: 12

-------------------------------------
system time   : 22
page reference: 6
page status   : fault (replacement)

frame[000]     7 use=1
frame[001]     6 use=1
frame[002]     3 use=0 <-- framePointer

Hit  ratio : 7 / 23 (ratio = 0.304348)
Fault ratio: 16 / 23 (ratio = 0.695652)

Hit count        : 7
Placement count  : 3
Replacement count: 13

-------------------------------------
system time   : 23
page reference: 4
page status   : fault (replacement)

frame[000]     7 use=1 <-- framePointer
frame[001]     6 use=1
frame[002]     4 use=1

Hit  ratio : 7 / 24 (ratio = 0.291667)
Fault ratio: 17 / 24 (ratio = 0.708333)

Hit count        : 7
Placement count  : 3
Replacement count: 14

-------------------------------------
system time   : 24
page reference: 1
page status   : fault (replacement)

frame[000]     1 use=1
frame[001]     6 use=0 <-- framePointer
frame[002]     4 use=0

Hit  ratio : 7 / 25 (ratio = 0.28)
Fault ratio: 18 / 25 (ratio = 0.72)

Hit count        : 7
Placement count  : 3
Replacement count: 15

-------------------------------------
system time   : 25
page reference: 2
page status   : fault (replacement)

frame[000]     1 use=1
frame[001]     2 use=1
frame[002]     4 use=0 <-- framePointer

Hit  ratio : 7 / 26 (ratio = 0.269231)
Fault ratio: 19 / 26 (ratio = 0.730769)

Hit count        : 7
Placement count  : 3
Replacement count: 16

-------------------------------------
system time   : 26
page reference: 1
page status   : hit

frame[000]     1 use=1
frame[001]     2 use=1
frame[002]     4 use=0 <-- framePointer

Hit  ratio : 8 / 27 (ratio = 0.296296)
Fault ratio: 19 / 27 (ratio = 0.703704)

Hit count        : 8
Placement count  : 3
Replacement count: 16

-------------------------------------
system time   : 27
page reference: 3
page status   : fault (replacement)

frame[000]     1 use=1 <-- framePointer
frame[001]     2 use=1
frame[002]     3 use=1

Hit  ratio : 8 / 28 (ratio = 0.285714)
Fault ratio: 20 / 28 (ratio = 0.714286)

Hit count        : 8
Placement count  : 3
Replacement count: 17

-------------------------------------
system time   : 28
page reference: 4
page status   : fault (replacement)

frame[000]     4 use=1
frame[001]     2 use=0 <-- framePointer
frame[002]     3 use=0

Hit  ratio : 8 / 29 (ratio = 0.275862)
Fault ratio: 21 / 29 (ratio = 0.724138)

Hit count        : 8
Placement count  : 3
Replacement count: 18

-------------------------------------
system time   : 29
page reference: 7
page status   : fault (replacement)

frame[000]     4 use=1
frame[001]     7 use=1
frame[002]     3 use=0 <-- framePointer

Hit  ratio : 8 / 30 (ratio = 0.266667)
Fault ratio: 22 / 30 (ratio = 0.733333)

Hit count        : 8
Placement count  : 3
Replacement count: 19

