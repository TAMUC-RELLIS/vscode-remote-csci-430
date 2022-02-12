------------------------------------------------------------------------
Event: new

<Simulation> system time: 1
  timeSliceQuantum      : 10
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
  timeSliceQuantum      : 10
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
  timeSliceQuantum      : 10
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
  timeSliceQuantum      : 10
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
  timeSliceQuantum      : 10
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
  timeSliceQuantum      : 10
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 3   quant: 3   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 2   used: 0   quant: 0   event: 0  
    Pid: 3   state: READY    start: 3   used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 5
  timeSliceQuantum      : 10
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 4   quant: 4   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 2   used: 0   quant: 0   event: 0  
    Pid: 3   state: READY    start: 3   used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 6
  timeSliceQuantum      : 10
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 5   quant: 5   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 2   used: 0   quant: 0   event: 0  
    Pid: 3   state: READY    start: 3   used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 7
  timeSliceQuantum      : 10
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 6   quant: 6   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 2   used: 0   quant: 0   event: 0  
    Pid: 3   state: READY    start: 3   used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 8
  timeSliceQuantum      : 10
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 7   quant: 7   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 2   used: 0   quant: 0   event: 0  
    Pid: 3   state: READY    start: 3   used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: block EventId: 22

<Simulation> system time: 8
  timeSliceQuantum      : 10
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 2   used: 0   quant: 0   event: 0  
    Pid: 3   state: READY    start: 3   used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 1   state: BLOCKED  start: 1   used: 7   quant: 0   event: 22 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 9
  timeSliceQuantum      : 10
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 2   state: RUNNING  start: 2   used: 1   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 3   state: READY    start: 3   used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 1   state: BLOCKED  start: 1   used: 7   quant: 0   event: 22 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 10
  timeSliceQuantum      : 10
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 2   state: RUNNING  start: 2   used: 2   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 3   state: READY    start: 3   used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 1   state: BLOCKED  start: 1   used: 7   quant: 0   event: 22 
  Blocked List

------------------------------------------------------------------------
Event: block EventId: 17

<Simulation> system time: 10
  timeSliceQuantum      : 10
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 3   state: READY    start: 3   used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 2   used: 2   quant: 0   event: 17 
    Pid: 1   state: BLOCKED  start: 1   used: 7   quant: 0   event: 22 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 11
  timeSliceQuantum      : 10
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 3   state: RUNNING  start: 3   used: 1   quant: 1   event: 0  
  CPU

  Ready Queue Head
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 2   used: 2   quant: 0   event: 17 
    Pid: 1   state: BLOCKED  start: 1   used: 7   quant: 0   event: 22 
  Blocked List

------------------------------------------------------------------------
Event: unblock EventId: 22

<Simulation> system time: 11
  timeSliceQuantum      : 10
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 3   state: RUNNING  start: 3   used: 1   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 7   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 2   state: BLOCKED  start: 2   used: 2   quant: 0   event: 17 
  Blocked List

------------------------------------------------------------------------
Event: unblock EventId: 17

<Simulation> system time: 11
  timeSliceQuantum      : 10
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 3   state: RUNNING  start: 3   used: 1   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 7   quant: 0   event: 0  
    Pid: 2   state: READY    start: 2   used: 2   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 12
  timeSliceQuantum      : 10
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 3   state: RUNNING  start: 3   used: 2   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 7   quant: 0   event: 0  
    Pid: 2   state: READY    start: 2   used: 2   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 13
  timeSliceQuantum      : 10
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 3   state: RUNNING  start: 3   used: 3   quant: 3   event: 0  
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 7   quant: 0   event: 0  
    Pid: 2   state: READY    start: 2   used: 2   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 14
  timeSliceQuantum      : 10
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 3   state: RUNNING  start: 3   used: 4   quant: 4   event: 0  
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 7   quant: 0   event: 0  
    Pid: 2   state: READY    start: 2   used: 2   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 15
  timeSliceQuantum      : 10
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 3   state: RUNNING  start: 3   used: 5   quant: 5   event: 0  
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 7   quant: 0   event: 0  
    Pid: 2   state: READY    start: 2   used: 2   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 16
  timeSliceQuantum      : 10
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 3   state: RUNNING  start: 3   used: 6   quant: 6   event: 0  
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 7   quant: 0   event: 0  
    Pid: 2   state: READY    start: 2   used: 2   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 17
  timeSliceQuantum      : 10
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 3   state: RUNNING  start: 3   used: 7   quant: 7   event: 0  
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 7   quant: 0   event: 0  
    Pid: 2   state: READY    start: 2   used: 2   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 18
  timeSliceQuantum      : 10
  numActiveProcesses    : 3
  numFinishedProcesses  : 0

  CPU
    Pid: 3   state: RUNNING  start: 3   used: 8   quant: 8   event: 0  
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 7   quant: 0   event: 0  
    Pid: 2   state: READY    start: 2   used: 2   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: done

<Simulation> system time: 18
  timeSliceQuantum      : 10
  numActiveProcesses    : 2
  numFinishedProcesses  : 1

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 7   quant: 0   event: 0  
    Pid: 2   state: READY    start: 2   used: 2   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 19
  timeSliceQuantum      : 10
  numActiveProcesses    : 2
  numFinishedProcesses  : 1

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 8   quant: 1   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 2   used: 2   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 20
  timeSliceQuantum      : 10
  numActiveProcesses    : 2
  numFinishedProcesses  : 1

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 9   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 2   used: 2   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 21
  timeSliceQuantum      : 10
  numActiveProcesses    : 2
  numFinishedProcesses  : 1

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 10  quant: 3   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 2   used: 2   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: done

<Simulation> system time: 21
  timeSliceQuantum      : 10
  numActiveProcesses    : 1
  numFinishedProcesses  : 2

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 2   used: 2   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 22
  timeSliceQuantum      : 10
  numActiveProcesses    : 1
  numFinishedProcesses  : 2

  CPU
    Pid: 2   state: RUNNING  start: 2   used: 3   quant: 1   event: 0  
  CPU

  Ready Queue Head
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 23
  timeSliceQuantum      : 10
  numActiveProcesses    : 1
  numFinishedProcesses  : 2

  CPU
    Pid: 2   state: RUNNING  start: 2   used: 4   quant: 2   event: 0  
  CPU

  Ready Queue Head
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: done

<Simulation> system time: 23
  timeSliceQuantum      : 10
  numActiveProcesses    : 0
  numFinishedProcesses  : 3

  CPU
    IDLE
  CPU

  Ready Queue Head
  Ready Queue Tail

  Blocked List
  Blocked List

