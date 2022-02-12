==================== cycle: 1
-------------------- fetch
CPU Registers
-------------
PC: 200
AC: 32
IR: 2250

Memory
------
200: 2250
201: 2242
202: 2287
203: 2199
242: 1
250: 1
287: 1

-------------------- execute
CPU Registers
-------------
PC: 201
AC: 32
IR: 2250
    opcode : 2 (STORE)
    address: 250

Memory
------
200: 2250
201: 2242
202: 2287
203: 2199
242: 1
250: 32
287: 1

==================== cycle: 2
-------------------- fetch
CPU Registers
-------------
PC: 201
AC: 32
IR: 2242

Memory
------
200: 2250
201: 2242
202: 2287
203: 2199
242: 1
250: 32
287: 1

-------------------- execute
CPU Registers
-------------
PC: 202
AC: 32
IR: 2242
    opcode : 2 (STORE)
    address: 242

Memory
------
200: 2250
201: 2242
202: 2287
203: 2199
242: 32
250: 32
287: 1

==================== cycle: 3
-------------------- fetch
CPU Registers
-------------
PC: 202
AC: 32
IR: 2287

Memory
------
200: 2250
201: 2242
202: 2287
203: 2199
242: 32
250: 32
287: 1

-------------------- execute
CPU Registers
-------------
PC: 203
AC: 32
IR: 2287
    opcode : 2 (STORE)
    address: 287

Memory
------
200: 2250
201: 2242
202: 2287
203: 2199
242: 32
250: 32
287: 32

==================== cycle: 4
-------------------- fetch
CPU Registers
-------------
PC: 203
AC: 32
IR: 2199

Memory
------
200: 2250
201: 2242
202: 2287
203: 2199
242: 32
250: 32
287: 32

Simulation run resulted in runtime error occurring:
translateAddress: Memory bounds access error, illegal reference to address: 199
