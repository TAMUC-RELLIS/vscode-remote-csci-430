==================== cycle: 1
-------------------- fetch
CPU Registers
-------------
PC: 300
AC: 0
IR: 3301

Memory
------
300: 3301
301: 4941
302: 1940
940: 4
941: 5

-------------------- execute
CPU Registers
-------------
PC: 301
AC: 0
IR: 3301
    opcode : 3 (JMP)
    address: 301

Memory
------
300: 3301
301: 4941
302: 1940
940: 4
941: 5

==================== cycle: 2
-------------------- fetch
CPU Registers
-------------
PC: 301
AC: 0
IR: 4941

Memory
------
300: 3301
301: 4941
302: 1940
940: 4
941: 5

-------------------- execute
CPU Registers
-------------
PC: 302
AC: -5
IR: 4941
    opcode : 4 (SUB)
    address: 941

Memory
------
300: 3301
301: 4941
302: 1940
940: 4
941: 5

==================== cycle: 3
-------------------- fetch
CPU Registers
-------------
PC: 302
AC: -5
IR: 1940

Memory
------
300: 3301
301: 4941
302: 1940
940: 4
941: 5

-------------------- execute
CPU Registers
-------------
PC: 303
AC: 4
IR: 1940
    opcode : 1 (LOAD)
    address: 940

Memory
------
300: 3301
301: 4941
302: 1940
940: 4
941: 5

==================== cycle: 4
-------------------- fetch
CPU Registers
-------------
PC: 303
AC: 4
IR: 0

Memory
------
300: 3301
301: 4941
302: 1940
940: 4
941: 5

-------------------- execute
CPU Registers
-------------
PC: 303
AC: 4
IR: 0

Memory
------
300: 3301
301: 4941
302: 1940
940: 4
941: 5

