------------------------------------------------------------------------
Event: new

<Simulation> system time: 1
  timeSliceQuantum      : 5
  numActiveProcesses    : 1
  numFinishedProcesses  : 0

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 2
  timeSliceQuantum      : 5
  numActiveProcesses    : 1
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 1   quant: 1   event: 0  
  CPU

  Ready Queue Head
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 3
  timeSliceQuantum      : 5
  numActiveProcesses    : 1
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 2   quant: 2   event: 0  
  CPU

  Ready Queue Head
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 4
  timeSliceQuantum      : 5
  numActiveProcesses    : 1
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 3   quant: 3   event: 0  
  CPU

  Ready Queue Head
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: new

<Simulation> system time: 4
  timeSliceQuantum      : 5
  numActiveProcesses    : 2
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 3   quant: 3   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 4   used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: new

<Simulation> system time: 4
  timeSliceQuantum      : 5
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 3   quant: 3   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 4   used: 0   quant: 0   event: 0  
    Pid: 3   state: READY    start: 4   used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: new

<Simulation> system time: 4
  timeSliceQuantum      : 5
  numActiveProcesses    : 4
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 3   quant: 3   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 4   used: 0   quant: 0   event: 0  
    Pid: 3   state: READY    start: 4   used: 0   quant: 0   event: 0  
    Pid: 4   state: READY    start: 4   used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 5
  timeSliceQuantum      : 5
  numActiveProcesses    : 4
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 4   quant: 4   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 4   used: 0   quant: 0   event: 0  
    Pid: 3   state: READY    start: 4   used: 0   quant: 0   event: 0  
    Pid: 4   state: READY    start: 4   used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 6
  timeSliceQuantum      : 5
  numActiveProcesses    : 4
  numFinishedProcesses  : 0

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 4   used: 0   quant: 0   event: 0  
    Pid: 3   state: READY    start: 4   used: 0   quant: 0   event: 0  
    Pid: 4   state: READY    start: 4   used: 0   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 7
  timeSliceQuantum      : 5
  numActiveProcesses    : 4
  numFinishedProcesses  : 0

  CPU
    Pid: 2   state: RUNNING  start: 4   used: 1   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 3   state: READY    start: 4   used: 0   quant: 0   event: 0  
    Pid: 4   state: READY    start: 4   used: 0   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 8
  timeSliceQuantum      : 5
  numActiveProcesses    : 4
  numFinishedProcesses  : 0

  CPU
    Pid: 2   state: RUNNING  start: 4   used: 2   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 3   state: READY    start: 4   used: 0   quant: 0   event: 0  
    Pid: 4   state: READY    start: 4   used: 0   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: block EventId: 4

<Simulation> system time: 8
  timeSliceQuantum      : 5
  numActiveProcesses    : 4
  numFinishedProcesses  : 0

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 3   state: READY    start: 4   used: 0   quant: 0   event: 0  
    Pid: 4   state: READY    start: 4   used: 0   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 9
  timeSliceQuantum      : 5
  numActiveProcesses    : 4
  numFinishedProcesses  : 0

  CPU
    Pid: 3   state: RUNNING  start: 4   used: 1   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 4   state: READY    start: 4   used: 0   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
  Blocked List

------------------------------------------------------------------------
Event: block EventId: 8

<Simulation> system time: 9
  timeSliceQuantum      : 5
  numActiveProcesses    : 4
  numFinishedProcesses  : 0

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 4   state: READY    start: 4   used: 0   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 3   state: BLOCKED  start: 4   used: 1   quant: 0   event: 8  
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 10
  timeSliceQuantum      : 5
  numActiveProcesses    : 4
  numFinishedProcesses  : 0

  CPU
    Pid: 4   state: RUNNING  start: 4   used: 1   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 3   state: BLOCKED  start: 4   used: 1   quant: 0   event: 8  
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 11
  timeSliceQuantum      : 5
  numActiveProcesses    : 4
  numFinishedProcesses  : 0

  CPU
    Pid: 4   state: RUNNING  start: 4   used: 2   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 3   state: BLOCKED  start: 4   used: 1   quant: 0   event: 8  
  Blocked List

------------------------------------------------------------------------
Event: block EventId: 17

<Simulation> system time: 11
  timeSliceQuantum      : 5
  numActiveProcesses    : 4
  numFinishedProcesses  : 0

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 3   state: BLOCKED  start: 4   used: 1   quant: 0   event: 8  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 12
  timeSliceQuantum      : 5
  numActiveProcesses    : 4
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 6   quant: 1   event: 0  
  CPU

  Ready Queue Head
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 3   state: BLOCKED  start: 4   used: 1   quant: 0   event: 8  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: new

<Simulation> system time: 12
  timeSliceQuantum      : 5
  numActiveProcesses    : 5
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 6   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 5   state: READY    start: 12  used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 3   state: BLOCKED  start: 4   used: 1   quant: 0   event: 8  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: new

<Simulation> system time: 12
  timeSliceQuantum      : 5
  numActiveProcesses    : 6
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 6   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 5   state: READY    start: 12  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 3   state: BLOCKED  start: 4   used: 1   quant: 0   event: 8  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 13
  timeSliceQuantum      : 5
  numActiveProcesses    : 6
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 7   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 5   state: READY    start: 12  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 3   state: BLOCKED  start: 4   used: 1   quant: 0   event: 8  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 14
  timeSliceQuantum      : 5
  numActiveProcesses    : 6
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 8   quant: 3   event: 0  
  CPU

  Ready Queue Head
    Pid: 5   state: READY    start: 12  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 3   state: BLOCKED  start: 4   used: 1   quant: 0   event: 8  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 15
  timeSliceQuantum      : 5
  numActiveProcesses    : 6
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 9   quant: 4   event: 0  
  CPU

  Ready Queue Head
    Pid: 5   state: READY    start: 12  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 3   state: BLOCKED  start: 4   used: 1   quant: 0   event: 8  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: unblock EventId: 8

<Simulation> system time: 15
  timeSliceQuantum      : 5
  numActiveProcesses    : 6
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 9   quant: 4   event: 0  
  CPU

  Ready Queue Head
    Pid: 5   state: READY    start: 12  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 0   quant: 0   event: 0  
    Pid: 3   state: READY    start: 4   used: 1   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 16
  timeSliceQuantum      : 5
  numActiveProcesses    : 6
  numFinishedProcesses  : 0

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 5   state: READY    start: 12  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 0   quant: 0   event: 0  
    Pid: 3   state: READY    start: 4   used: 1   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 10  quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 17
  timeSliceQuantum      : 5
  numActiveProcesses    : 6
  numFinishedProcesses  : 0

  CPU
    Pid: 5   state: RUNNING  start: 12  used: 1   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 6   state: READY    start: 12  used: 0   quant: 0   event: 0  
    Pid: 3   state: READY    start: 4   used: 1   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 10  quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 18
  timeSliceQuantum      : 5
  numActiveProcesses    : 6
  numFinishedProcesses  : 0

  CPU
    Pid: 5   state: RUNNING  start: 12  used: 2   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 6   state: READY    start: 12  used: 0   quant: 0   event: 0  
    Pid: 3   state: READY    start: 4   used: 1   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 10  quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 19
  timeSliceQuantum      : 5
  numActiveProcesses    : 6
  numFinishedProcesses  : 0

  CPU
    Pid: 5   state: RUNNING  start: 12  used: 3   quant: 3   event: 0  
  CPU

  Ready Queue Head
    Pid: 6   state: READY    start: 12  used: 0   quant: 0   event: 0  
    Pid: 3   state: READY    start: 4   used: 1   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 10  quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 20
  timeSliceQuantum      : 5
  numActiveProcesses    : 6
  numFinishedProcesses  : 0

  CPU
    Pid: 5   state: RUNNING  start: 12  used: 4   quant: 4   event: 0  
  CPU

  Ready Queue Head
    Pid: 6   state: READY    start: 12  used: 0   quant: 0   event: 0  
    Pid: 3   state: READY    start: 4   used: 1   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 10  quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 21
  timeSliceQuantum      : 5
  numActiveProcesses    : 6
  numFinishedProcesses  : 0

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 6   state: READY    start: 12  used: 0   quant: 0   event: 0  
    Pid: 3   state: READY    start: 4   used: 1   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 10  quant: 0   event: 0  
    Pid: 5   state: READY    start: 12  used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 22
  timeSliceQuantum      : 5
  numActiveProcesses    : 6
  numFinishedProcesses  : 0

  CPU
    Pid: 6   state: RUNNING  start: 12  used: 1   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 3   state: READY    start: 4   used: 1   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 10  quant: 0   event: 0  
    Pid: 5   state: READY    start: 12  used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: new

<Simulation> system time: 22
  timeSliceQuantum      : 5
  numActiveProcesses    : 7
  numFinishedProcesses  : 0

  CPU
    Pid: 6   state: RUNNING  start: 12  used: 1   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 3   state: READY    start: 4   used: 1   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 10  quant: 0   event: 0  
    Pid: 5   state: READY    start: 12  used: 5   quant: 0   event: 0  
    Pid: 7   state: READY    start: 22  used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: new

<Simulation> system time: 22
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 6   state: RUNNING  start: 12  used: 1   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 3   state: READY    start: 4   used: 1   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 10  quant: 0   event: 0  
    Pid: 5   state: READY    start: 12  used: 5   quant: 0   event: 0  
    Pid: 7   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 8   state: READY    start: 22  used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 23
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 6   state: RUNNING  start: 12  used: 2   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 3   state: READY    start: 4   used: 1   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 10  quant: 0   event: 0  
    Pid: 5   state: READY    start: 12  used: 5   quant: 0   event: 0  
    Pid: 7   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 8   state: READY    start: 22  used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 24
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 6   state: RUNNING  start: 12  used: 3   quant: 3   event: 0  
  CPU

  Ready Queue Head
    Pid: 3   state: READY    start: 4   used: 1   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 10  quant: 0   event: 0  
    Pid: 5   state: READY    start: 12  used: 5   quant: 0   event: 0  
    Pid: 7   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 8   state: READY    start: 22  used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 25
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 6   state: RUNNING  start: 12  used: 4   quant: 4   event: 0  
  CPU

  Ready Queue Head
    Pid: 3   state: READY    start: 4   used: 1   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 10  quant: 0   event: 0  
    Pid: 5   state: READY    start: 12  used: 5   quant: 0   event: 0  
    Pid: 7   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 8   state: READY    start: 22  used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 26
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 3   state: READY    start: 4   used: 1   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 10  quant: 0   event: 0  
    Pid: 5   state: READY    start: 12  used: 5   quant: 0   event: 0  
    Pid: 7   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 8   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 27
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 3   state: RUNNING  start: 4   used: 2   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 10  quant: 0   event: 0  
    Pid: 5   state: READY    start: 12  used: 5   quant: 0   event: 0  
    Pid: 7   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 8   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 28
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 3   state: RUNNING  start: 4   used: 3   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 10  quant: 0   event: 0  
    Pid: 5   state: READY    start: 12  used: 5   quant: 0   event: 0  
    Pid: 7   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 8   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 29
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 3   state: RUNNING  start: 4   used: 4   quant: 3   event: 0  
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 10  quant: 0   event: 0  
    Pid: 5   state: READY    start: 12  used: 5   quant: 0   event: 0  
    Pid: 7   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 8   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 30
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 3   state: RUNNING  start: 4   used: 5   quant: 4   event: 0  
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 10  quant: 0   event: 0  
    Pid: 5   state: READY    start: 12  used: 5   quant: 0   event: 0  
    Pid: 7   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 8   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: block EventId: 11

<Simulation> system time: 30
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 10  quant: 0   event: 0  
    Pid: 5   state: READY    start: 12  used: 5   quant: 0   event: 0  
    Pid: 7   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 8   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 3   state: BLOCKED  start: 4   used: 5   quant: 0   event: 11 
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 31
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 11  quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 5   state: READY    start: 12  used: 5   quant: 0   event: 0  
    Pid: 7   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 8   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 3   state: BLOCKED  start: 4   used: 5   quant: 0   event: 11 
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 32
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 12  quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 5   state: READY    start: 12  used: 5   quant: 0   event: 0  
    Pid: 7   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 8   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 3   state: BLOCKED  start: 4   used: 5   quant: 0   event: 11 
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: block EventId: 19

<Simulation> system time: 32
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 5   state: READY    start: 12  used: 5   quant: 0   event: 0  
    Pid: 7   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 8   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 3   state: BLOCKED  start: 4   used: 5   quant: 0   event: 11 
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 33
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 5   state: RUNNING  start: 12  used: 6   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 7   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 8   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 3   state: BLOCKED  start: 4   used: 5   quant: 0   event: 11 
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 34
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 5   state: RUNNING  start: 12  used: 7   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 7   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 8   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 3   state: BLOCKED  start: 4   used: 5   quant: 0   event: 11 
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 35
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 5   state: RUNNING  start: 12  used: 8   quant: 3   event: 0  
  CPU

  Ready Queue Head
    Pid: 7   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 8   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 3   state: BLOCKED  start: 4   used: 5   quant: 0   event: 11 
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
  Blocked List

------------------------------------------------------------------------
Event: block EventId: 23

<Simulation> system time: 35
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 7   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 8   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 3   state: BLOCKED  start: 4   used: 5   quant: 0   event: 11 
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 36
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 7   state: RUNNING  start: 22  used: 1   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 8   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 3   state: BLOCKED  start: 4   used: 5   quant: 0   event: 11 
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 37
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 7   state: RUNNING  start: 22  used: 2   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 8   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 4   used: 2   quant: 0   event: 4  
    Pid: 3   state: BLOCKED  start: 4   used: 5   quant: 0   event: 11 
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: unblock EventId: 4

<Simulation> system time: 37
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 7   state: RUNNING  start: 22  used: 2   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 8   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 5   quant: 0   event: 0  
    Pid: 2   state: READY    start: 4   used: 2   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 3   state: BLOCKED  start: 4   used: 5   quant: 0   event: 11 
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 38
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 7   state: RUNNING  start: 22  used: 3   quant: 3   event: 0  
  CPU

  Ready Queue Head
    Pid: 8   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 5   quant: 0   event: 0  
    Pid: 2   state: READY    start: 4   used: 2   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 3   state: BLOCKED  start: 4   used: 5   quant: 0   event: 11 
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 39
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 7   state: RUNNING  start: 22  used: 4   quant: 4   event: 0  
  CPU

  Ready Queue Head
    Pid: 8   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 5   quant: 0   event: 0  
    Pid: 2   state: READY    start: 4   used: 2   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 3   state: BLOCKED  start: 4   used: 5   quant: 0   event: 11 
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 40
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 8   state: READY    start: 22  used: 0   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 5   quant: 0   event: 0  
    Pid: 2   state: READY    start: 4   used: 2   quant: 0   event: 0  
    Pid: 7   state: READY    start: 22  used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 3   state: BLOCKED  start: 4   used: 5   quant: 0   event: 11 
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 41
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 8   state: RUNNING  start: 22  used: 1   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 6   state: READY    start: 12  used: 5   quant: 0   event: 0  
    Pid: 2   state: READY    start: 4   used: 2   quant: 0   event: 0  
    Pid: 7   state: READY    start: 22  used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 3   state: BLOCKED  start: 4   used: 5   quant: 0   event: 11 
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: block EventId: 7

<Simulation> system time: 41
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 6   state: READY    start: 12  used: 5   quant: 0   event: 0  
    Pid: 2   state: READY    start: 4   used: 2   quant: 0   event: 0  
    Pid: 7   state: READY    start: 22  used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 3   state: BLOCKED  start: 4   used: 5   quant: 0   event: 11 
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 42
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 6   state: RUNNING  start: 12  used: 6   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 4   used: 2   quant: 0   event: 0  
    Pid: 7   state: READY    start: 22  used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 3   state: BLOCKED  start: 4   used: 5   quant: 0   event: 11 
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 43
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 6   state: RUNNING  start: 12  used: 7   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 4   used: 2   quant: 0   event: 0  
    Pid: 7   state: READY    start: 22  used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 3   state: BLOCKED  start: 4   used: 5   quant: 0   event: 11 
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 44
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 6   state: RUNNING  start: 12  used: 8   quant: 3   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 4   used: 2   quant: 0   event: 0  
    Pid: 7   state: READY    start: 22  used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 3   state: BLOCKED  start: 4   used: 5   quant: 0   event: 11 
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: unblock EventId: 11

<Simulation> system time: 44
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 6   state: RUNNING  start: 12  used: 8   quant: 3   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 4   used: 2   quant: 0   event: 0  
    Pid: 7   state: READY    start: 22  used: 5   quant: 0   event: 0  
    Pid: 3   state: READY    start: 4   used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 45
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 6   state: RUNNING  start: 12  used: 9   quant: 4   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 4   used: 2   quant: 0   event: 0  
    Pid: 7   state: READY    start: 22  used: 5   quant: 0   event: 0  
    Pid: 3   state: READY    start: 4   used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 46
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 4   used: 2   quant: 0   event: 0  
    Pid: 7   state: READY    start: 22  used: 5   quant: 0   event: 0  
    Pid: 3   state: READY    start: 4   used: 5   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 10  quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 4   state: BLOCKED  start: 4   used: 2   quant: 0   event: 17 
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: unblock EventId: 17

<Simulation> system time: 46
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 2   state: RUNNING  start: 4   used: 2   quant: 0   event: 0  
  CPU

  Ready Queue Head
    Pid: 7   state: READY    start: 22  used: 5   quant: 0   event: 0  
    Pid: 3   state: READY    start: 4   used: 5   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 10  quant: 0   event: 0  
    Pid: 4   state: READY    start: 4   used: 2   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 47
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 2   state: RUNNING  start: 4   used: 3   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 7   state: READY    start: 22  used: 5   quant: 0   event: 0  
    Pid: 3   state: READY    start: 4   used: 5   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 10  quant: 0   event: 0  
    Pid: 4   state: READY    start: 4   used: 2   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 48
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 2   state: RUNNING  start: 4   used: 4   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 7   state: READY    start: 22  used: 5   quant: 0   event: 0  
    Pid: 3   state: READY    start: 4   used: 5   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 10  quant: 0   event: 0  
    Pid: 4   state: READY    start: 4   used: 2   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 49
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 2   state: RUNNING  start: 4   used: 5   quant: 3   event: 0  
  CPU

  Ready Queue Head
    Pid: 7   state: READY    start: 22  used: 5   quant: 0   event: 0  
    Pid: 3   state: READY    start: 4   used: 5   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 10  quant: 0   event: 0  
    Pid: 4   state: READY    start: 4   used: 2   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 50
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    Pid: 2   state: RUNNING  start: 4   used: 6   quant: 4   event: 0  
  CPU

  Ready Queue Head
    Pid: 7   state: READY    start: 22  used: 5   quant: 0   event: 0  
    Pid: 3   state: READY    start: 4   used: 5   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 10  quant: 0   event: 0  
    Pid: 4   state: READY    start: 4   used: 2   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 51
  timeSliceQuantum      : 5
  numActiveProcesses    : 8
  numFinishedProcesses  : 0

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 7   state: READY    start: 22  used: 5   quant: 0   event: 0  
    Pid: 3   state: READY    start: 4   used: 5   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 10  quant: 0   event: 0  
    Pid: 4   state: READY    start: 4   used: 2   quant: 0   event: 0  
    Pid: 2   state: READY    start: 4   used: 7   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: done

<Simulation> system time: 51
  timeSliceQuantum      : 5
  numActiveProcesses    : 7
  numFinishedProcesses  : 1

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 3   state: READY    start: 4   used: 5   quant: 0   event: 0  
    Pid: 6   state: READY    start: 12  used: 10  quant: 0   event: 0  
    Pid: 4   state: READY    start: 4   used: 2   quant: 0   event: 0  
    Pid: 2   state: READY    start: 4   used: 7   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 52
  timeSliceQuantum      : 5
  numActiveProcesses    : 7
  numFinishedProcesses  : 1

  CPU
    Pid: 3   state: RUNNING  start: 4   used: 6   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 6   state: READY    start: 12  used: 10  quant: 0   event: 0  
    Pid: 4   state: READY    start: 4   used: 2   quant: 0   event: 0  
    Pid: 2   state: READY    start: 4   used: 7   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 53
  timeSliceQuantum      : 5
  numActiveProcesses    : 7
  numFinishedProcesses  : 1

  CPU
    Pid: 3   state: RUNNING  start: 4   used: 7   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 6   state: READY    start: 12  used: 10  quant: 0   event: 0  
    Pid: 4   state: READY    start: 4   used: 2   quant: 0   event: 0  
    Pid: 2   state: READY    start: 4   used: 7   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 54
  timeSliceQuantum      : 5
  numActiveProcesses    : 7
  numFinishedProcesses  : 1

  CPU
    Pid: 3   state: RUNNING  start: 4   used: 8   quant: 3   event: 0  
  CPU

  Ready Queue Head
    Pid: 6   state: READY    start: 12  used: 10  quant: 0   event: 0  
    Pid: 4   state: READY    start: 4   used: 2   quant: 0   event: 0  
    Pid: 2   state: READY    start: 4   used: 7   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 55
  timeSliceQuantum      : 5
  numActiveProcesses    : 7
  numFinishedProcesses  : 1

  CPU
    Pid: 3   state: RUNNING  start: 4   used: 9   quant: 4   event: 0  
  CPU

  Ready Queue Head
    Pid: 6   state: READY    start: 12  used: 10  quant: 0   event: 0  
    Pid: 4   state: READY    start: 4   used: 2   quant: 0   event: 0  
    Pid: 2   state: READY    start: 4   used: 7   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: done

<Simulation> system time: 55
  timeSliceQuantum      : 5
  numActiveProcesses    : 6
  numFinishedProcesses  : 2

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 6   state: READY    start: 12  used: 10  quant: 0   event: 0  
    Pid: 4   state: READY    start: 4   used: 2   quant: 0   event: 0  
    Pid: 2   state: READY    start: 4   used: 7   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
    Pid: 5   state: BLOCKED  start: 12  used: 8   quant: 0   event: 23 
  Blocked List

------------------------------------------------------------------------
Event: unblock EventId: 23

<Simulation> system time: 55
  timeSliceQuantum      : 5
  numActiveProcesses    : 6
  numFinishedProcesses  : 2

  CPU
    Pid: 6   state: RUNNING  start: 12  used: 10  quant: 0   event: 0  
  CPU

  Ready Queue Head
    Pid: 4   state: READY    start: 4   used: 2   quant: 0   event: 0  
    Pid: 2   state: READY    start: 4   used: 7   quant: 0   event: 0  
    Pid: 5   state: READY    start: 12  used: 8   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 56
  timeSliceQuantum      : 5
  numActiveProcesses    : 6
  numFinishedProcesses  : 2

  CPU
    Pid: 6   state: RUNNING  start: 12  used: 11  quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 4   state: READY    start: 4   used: 2   quant: 0   event: 0  
    Pid: 2   state: READY    start: 4   used: 7   quant: 0   event: 0  
    Pid: 5   state: READY    start: 12  used: 8   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 57
  timeSliceQuantum      : 5
  numActiveProcesses    : 6
  numFinishedProcesses  : 2

  CPU
    Pid: 6   state: RUNNING  start: 12  used: 12  quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 4   state: READY    start: 4   used: 2   quant: 0   event: 0  
    Pid: 2   state: READY    start: 4   used: 7   quant: 0   event: 0  
    Pid: 5   state: READY    start: 12  used: 8   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 58
  timeSliceQuantum      : 5
  numActiveProcesses    : 6
  numFinishedProcesses  : 2

  CPU
    Pid: 6   state: RUNNING  start: 12  used: 13  quant: 3   event: 0  
  CPU

  Ready Queue Head
    Pid: 4   state: READY    start: 4   used: 2   quant: 0   event: 0  
    Pid: 2   state: READY    start: 4   used: 7   quant: 0   event: 0  
    Pid: 5   state: READY    start: 12  used: 8   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
  Blocked List

------------------------------------------------------------------------
Event: block EventId: 4

<Simulation> system time: 58
  timeSliceQuantum      : 5
  numActiveProcesses    : 6
  numFinishedProcesses  : 2

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 4   state: READY    start: 4   used: 2   quant: 0   event: 0  
    Pid: 2   state: READY    start: 4   used: 7   quant: 0   event: 0  
    Pid: 5   state: READY    start: 12  used: 8   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 6   state: BLOCKED  start: 12  used: 13  quant: 0   event: 4  
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 59
  timeSliceQuantum      : 5
  numActiveProcesses    : 6
  numFinishedProcesses  : 2

  CPU
    Pid: 4   state: RUNNING  start: 4   used: 3   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 4   used: 7   quant: 0   event: 0  
    Pid: 5   state: READY    start: 12  used: 8   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 6   state: BLOCKED  start: 12  used: 13  quant: 0   event: 4  
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 60
  timeSliceQuantum      : 5
  numActiveProcesses    : 6
  numFinishedProcesses  : 2

  CPU
    Pid: 4   state: RUNNING  start: 4   used: 4   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 4   used: 7   quant: 0   event: 0  
    Pid: 5   state: READY    start: 12  used: 8   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 6   state: BLOCKED  start: 12  used: 13  quant: 0   event: 4  
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 61
  timeSliceQuantum      : 5
  numActiveProcesses    : 6
  numFinishedProcesses  : 2

  CPU
    Pid: 4   state: RUNNING  start: 4   used: 5   quant: 3   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 4   used: 7   quant: 0   event: 0  
    Pid: 5   state: READY    start: 12  used: 8   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 6   state: BLOCKED  start: 12  used: 13  quant: 0   event: 4  
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 62
  timeSliceQuantum      : 5
  numActiveProcesses    : 6
  numFinishedProcesses  : 2

  CPU
    Pid: 4   state: RUNNING  start: 4   used: 6   quant: 4   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 4   used: 7   quant: 0   event: 0  
    Pid: 5   state: READY    start: 12  used: 8   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 6   state: BLOCKED  start: 12  used: 13  quant: 0   event: 4  
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 63
  timeSliceQuantum      : 5
  numActiveProcesses    : 6
  numFinishedProcesses  : 2

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 4   used: 7   quant: 0   event: 0  
    Pid: 5   state: READY    start: 12  used: 8   quant: 0   event: 0  
    Pid: 4   state: READY    start: 4   used: 7   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 6   state: BLOCKED  start: 12  used: 13  quant: 0   event: 4  
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
  Blocked List

------------------------------------------------------------------------
Event: done

<Simulation> system time: 63
  timeSliceQuantum      : 5
  numActiveProcesses    : 5
  numFinishedProcesses  : 3

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 5   state: READY    start: 12  used: 8   quant: 0   event: 0  
    Pid: 4   state: READY    start: 4   used: 7   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 6   state: BLOCKED  start: 12  used: 13  quant: 0   event: 4  
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 64
  timeSliceQuantum      : 5
  numActiveProcesses    : 5
  numFinishedProcesses  : 3

  CPU
    Pid: 5   state: RUNNING  start: 12  used: 9   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 4   state: READY    start: 4   used: 7   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 6   state: BLOCKED  start: 12  used: 13  quant: 0   event: 4  
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
  Blocked List

------------------------------------------------------------------------
Event: done

<Simulation> system time: 64
  timeSliceQuantum      : 5
  numActiveProcesses    : 4
  numFinishedProcesses  : 4

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 4   state: READY    start: 4   used: 7   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 6   state: BLOCKED  start: 12  used: 13  quant: 0   event: 4  
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
  Blocked List

------------------------------------------------------------------------
Event: unblock EventId: 4

<Simulation> system time: 64
  timeSliceQuantum      : 5
  numActiveProcesses    : 4
  numFinishedProcesses  : 4

  CPU
    Pid: 4   state: RUNNING  start: 4   used: 7   quant: 0   event: 0  
  CPU

  Ready Queue Head
    Pid: 6   state: READY    start: 12  used: 13  quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 65
  timeSliceQuantum      : 5
  numActiveProcesses    : 4
  numFinishedProcesses  : 4

  CPU
    Pid: 4   state: RUNNING  start: 4   used: 8   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 6   state: READY    start: 12  used: 13  quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 66
  timeSliceQuantum      : 5
  numActiveProcesses    : 4
  numFinishedProcesses  : 4

  CPU
    Pid: 4   state: RUNNING  start: 4   used: 9   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 6   state: READY    start: 12  used: 13  quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
  Blocked List

------------------------------------------------------------------------
Event: done

<Simulation> system time: 66
  timeSliceQuantum      : 5
  numActiveProcesses    : 3
  numFinishedProcesses  : 5

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 6   state: READY    start: 12  used: 13  quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 67
  timeSliceQuantum      : 5
  numActiveProcesses    : 3
  numFinishedProcesses  : 5

  CPU
    Pid: 6   state: RUNNING  start: 12  used: 14  quant: 1   event: 0  
  CPU

  Ready Queue Head
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 68
  timeSliceQuantum      : 5
  numActiveProcesses    : 3
  numFinishedProcesses  : 5

  CPU
    Pid: 6   state: RUNNING  start: 12  used: 15  quant: 2   event: 0  
  CPU

  Ready Queue Head
  Ready Queue Tail

  Blocked List
    Pid: 8   state: BLOCKED  start: 22  used: 1   quant: 0   event: 7  
    Pid: 1   state: BLOCKED  start: 1   used: 12  quant: 0   event: 19 
  Blocked List

