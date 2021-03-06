==================== cycle: 1
-------------------- fetch
CPU Registers
-------------
PC: 300
AC: 0
IR: 1940

Memory
------
300: 1940
301: 5941
302: 2941
940: 3
941: 2

-------------------- execute
CPU Registers
-------------
PC: 301
AC: 3
IR: 1940
    opcode : 1 (LOAD)
    address: 940

Memory
------
300: 1940
301: 5941
302: 2941
940: 3
941: 2

==================== cycle: 2
-------------------- fetch
CPU Registers
-------------
PC: 301
AC: 3
IR: 5941

Memory
------
300: 1940
301: 5941
302: 2941
940: 3
941: 2

-------------------- execute
CPU Registers
-------------
PC: 302
AC: 5
IR: 5941
    opcode : 5 (ADD)
    address: 941

Memory
------
300: 1940
301: 5941
302: 2941
940: 3
941: 2

==================== cycle: 3
-------------------- fetch
CPU Registers
-------------
PC: 302
AC: 5
IR: 2941

Memory
------
300: 1940
301: 5941
302: 2941
940: 3
941: 2

-------------------- execute
CPU Registers
-------------
PC: 303
AC: 5
IR: 2941
    opcode : 2 (STORE)
    address: 941

Memory
------
300: 1940
301: 5941
302: 2941
940: 3
941: 5

==================== cycle: 4
-------------------- fetch
CPU Registers
-------------
PC: 303
AC: 5
IR: 0

Memory
------
300: 1940
301: 5941
302: 2941
940: 3
941: 5

-------------------- execute
CPU Registers
-------------
PC: 303
AC: 5
IR: 0

Memory
------
300: 1940
301: 5941
302: 2941
940: 3
941: 5

