------------------------------------------------------------------------
Event: new

<Simulation> system time: 1
  timeSliceQuantum      : 3
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
  timeSliceQuantum      : 3
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
Event: new

<Simulation> system time: 2
  timeSliceQuantum      : 3
  numActiveProcesses    : 2
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 1   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 2   used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 3
  timeSliceQuantum      : 3
  numActiveProcesses    : 2
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 2   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 2   used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: new

<Simulation> system time: 3
  timeSliceQuantum      : 3
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 2   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 2   used: 0   quant: 0   event: 0  
    Pid: 3   state: READY    start: 3   used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 4
  timeSliceQuantum      : 3
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 2   used: 0   quant: 0   event: 0  
    Pid: 3   state: READY    start: 3   used: 0   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 3   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 5
  timeSliceQuantum      : 3
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 2   state: RUNNING  start: 2   used: 1   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 3   state: READY    start: 3   used: 0   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 3   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 6
  timeSliceQuantum      : 3
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 2   state: RUNNING  start: 2   used: 2   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 3   state: READY    start: 3   used: 0   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 3   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 7
  timeSliceQuantum      : 3
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 3   state: READY    start: 3   used: 0   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 3   quant: 0   event: 0  
    Pid: 2   state: READY    start: 2   used: 3   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 8
  timeSliceQuantum      : 3
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 3   state: RUNNING  start: 3   used: 1   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 3   quant: 0   event: 0  
    Pid: 2   state: READY    start: 2   used: 3   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: block EventId: 22

<Simulation> system time: 8
  timeSliceQuantum      : 3
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 3   quant: 0   event: 0  
    Pid: 2   state: READY    start: 2   used: 3   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 3   state: BLOCKED  start: 3   used: 1   quant: 0   event: 22 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 9
  timeSliceQuantum      : 3
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 4   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 2   used: 3   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 3   state: BLOCKED  start: 3   used: 1   quant: 0   event: 22 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 10
  timeSliceQuantum      : 3
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 5   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 2   used: 3   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 3   state: BLOCKED  start: 3   used: 1   quant: 0   event: 22 
  Blocked List

------------------------------------------------------------------------
Event: block EventId: 17

<Simulation> system time: 10
  timeSliceQuantum      : 3
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 2   used: 3   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 1   state: BLOCKED  start: 1   used: 5   quant: 0   event: 17 
    Pid: 3   state: BLOCKED  start: 3   used: 1   quant: 0   event: 22 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 11
  timeSliceQuantum      : 3
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 2   state: RUNNING  start: 2   used: 4   quant: 1   event: 0  
  CPU

  Ready Queue Head
  Ready Queue Tail

  Blocked List
    Pid: 1   state: BLOCKED  start: 1   used: 5   quant: 0   event: 17 
    Pid: 3   state: BLOCKED  start: 3   used: 1   quant: 0   event: 22 
  Blocked List

------------------------------------------------------------------------
Event: unblock EventId: 22

<Simulation> system time: 11
  timeSliceQuantum      : 3
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 2   state: RUNNING  start: 2   used: 4   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 3   state: READY    start: 3   used: 1   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 1   state: BLOCKED  start: 1   used: 5   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: unblock EventId: 17

<Simulation> system time: 11
  timeSliceQuantum      : 3
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 2   state: RUNNING  start: 2   used: 4   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 3   state: READY    start: 3   used: 1   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 12
  timeSliceQuantum      : 3
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 2   state: RUNNING  start: 2   used: 5   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 3   state: READY    start: 3   used: 1   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 5   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 13
  timeSliceQuantum      : 3
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 3   state: READY    start: 3   used: 1   quant: 0   event: 0  
    Pid: 1   state: READY    start: 1   used: 5   quant: 0   event: 0  
    Pid: 2   state: READY    start: 2   used: 6   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 14
  timeSliceQuantum      : 3
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 3   state: RUNNING  start: 3   used: 2   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 5   quant: 0   event: 0  
    Pid: 2   state: READY    start: 2   used: 6   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 15
  timeSliceQuantum      : 3
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 3   state: RUNNING  start: 3   used: 3   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 5   quant: 0   event: 0  
    Pid: 2   state: READY    start: 2   used: 6   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 16
  timeSliceQuantum      : 3
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 5   quant: 0   event: 0  
    Pid: 2   state: READY    start: 2   used: 6   quant: 0   event: 0  
    Pid: 3   state: READY    start: 3   used: 4   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 17
  timeSliceQuantum      : 3
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 6   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 2   used: 6   quant: 0   event: 0  
    Pid: 3   state: READY    start: 3   used: 4   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 18
  timeSliceQuantum      : 3
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 7   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 2   used: 6   quant: 0   event: 0  
    Pid: 3   state: READY    start: 3   used: 4   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: done

<Simulation> system time: 18
  timeSliceQuantum      : 3
  numActiveProcesses    : 2
  numFinishedProcesses  : 1

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 2   used: 6   quant: 0   event: 0  
    Pid: 3   state: READY    start: 3   used: 4   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 19
  timeSliceQuantum      : 3
  numActiveProcesses    : 2
  numFinishedProcesses  : 1

  CPU
    Pid: 2   state: RUNNING  start: 2   used: 7   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 3   state: READY    start: 3   used: 4   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 20
  timeSliceQuantum      : 3
  numActiveProcesses    : 2
  numFinishedProcesses  : 1

  CPU
    Pid: 2   state: RUNNING  start: 2   used: 8   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 3   state: READY    start: 3   used: 4   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 21
  timeSliceQuantum      : 3
  numActiveProcesses    : 2
  numFinishedProcesses  : 1

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 3   state: READY    start: 3   used: 4   quant: 0   event: 0  
    Pid: 2   state: READY    start: 2   used: 9   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: done

<Simulation> system time: 21
  timeSliceQuantum      : 3
  numActiveProcesses    : 1
  numFinishedProcesses  : 2

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 2   used: 9   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 22
  timeSliceQuantum      : 3
  numActiveProcesses    : 1
  numFinishedProcesses  : 2

  CPU
    Pid: 2   state: RUNNING  start: 2   used: 10  quant: 1   event: 0  
  CPU

  Ready Queue Head
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 23
  timeSliceQuantum      : 3
  numActiveProcesses    : 1
  numFinishedProcesses  : 2

  CPU
    Pid: 2   state: RUNNING  start: 2   used: 11  quant: 2   event: 0  
  CPU

  Ready Queue Head
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: done

<Simulation> system time: 23
  timeSliceQuantum      : 3
  numActiveProcesses    : 0
  numFinishedProcesses  : 3

  CPU
    IDLE
  CPU

  Ready Queue Head
  Ready Queue Tail

  Blocked List
  Blocked List

