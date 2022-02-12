==================== cycle: 1
-------------------- fetch
CPU Registers
-------------
PC: 100
AC: 0
IR: 1150

Memory
------
100: 1150
101: 1175
102: 1190
103: 1200
150: 42
175: -5
190: 123

-------------------- execute
CPU Registers
-------------
PC: 101
AC: 42
IR: 1150
    opcode : 1 (LOAD)
    address: 150

Memory
------
100: 1150
101: 1175
102: 1190
103: 1200
150: 42
175: -5
190: 123

==================== cycle: 2
-------------------- fetch
CPU Registers
-------------
PC: 101
AC: 42
IR: 1175

Memory
------
100: 1150
101: 1175
102: 1190
103: 1200
150: 42
175: -5
190: 123

-------------------- execute
CPU Registers
-------------
PC: 102
AC: -5
IR: 1175
    opcode : 1 (LOAD)
    address: 175

Memory
------
100: 1150
101: 1175
102: 1190
103: 1200
150: 42
175: -5
190: 123

==================== cycle: 3
-------------------- fetch
CPU Registers
-------------
PC: 102
AC: -5
IR: 1190

Memory
------
100: 1150
101: 1175
102: 1190
103: 1200
150: 42
175: -5
190: 123

-------------------- execute
CPU Registers
-------------
PC: 103
AC: 123
IR: 1190
    opcode : 1 (LOAD)
    address: 190

Memory
------
100: 1150
101: 1175
102: 1190
103: 1200
150: 42
175: -5
190: 123

==================== cycle: 4
-------------------- fetch
CPU Registers
-------------
PC: 103
AC: 123
IR: 1200

Memory
------
100: 1150
101: 1175
102: 1190
103: 1200
150: 42
175: -5
190: 123

Simulation run resulted in runtime error occurring:
translateAddress: Memory bounds access error, illegal reference to address: 200
