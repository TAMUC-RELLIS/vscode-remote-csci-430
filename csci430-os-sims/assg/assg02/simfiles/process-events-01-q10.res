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
Event: cpu

<Simulation> system time: 3
  timeSliceQuantum      : 10
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
  timeSliceQuantum      : 10
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
  timeSliceQuantum      : 10
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
Event: cpu

<Simulation> system time: 5
  timeSliceQuantum      : 10
  numActiveProcesses    : 2
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 4   quant: 4   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 4   used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 6
  timeSliceQuantum      : 10
  numActiveProcesses    : 2
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 5   quant: 5   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 4   used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 7
  timeSliceQuantum      : 10
  numActiveProcesses    : 2
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 6   quant: 6   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 4   used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 8
  timeSliceQuantum      : 10
  numActiveProcesses    : 2
  numFinishedProcesses  : 0

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 7   quant: 7   event: 0  
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 4   used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: block EventId: 83

<Simulation> system time: 8
  timeSliceQuantum      : 10
  numActiveProcesses    : 2
  numFinishedProcesses  : 0

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 2   state: READY    start: 4   used: 0   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
    Pid: 1   state: BLOCKED  start: 1   used: 7   quant: 0   event: 83 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 9
  timeSliceQuantum      : 10
  numActiveProcesses    : 2
  numFinishedProcesses  : 0

  CPU
    Pid: 2   state: RUNNING  start: 4   used: 1   quant: 1   event: 0  
  CPU

  Ready Queue Head
  Ready Queue Tail

  Blocked List
    Pid: 1   state: BLOCKED  start: 1   used: 7   quant: 0   event: 83 
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 10
  timeSliceQuantum      : 10
  numActiveProcesses    : 2
  numFinishedProcesses  : 0

  CPU
    Pid: 2   state: RUNNING  start: 4   used: 2   quant: 2   event: 0  
  CPU

  Ready Queue Head
  Ready Queue Tail

  Blocked List
    Pid: 1   state: BLOCKED  start: 1   used: 7   quant: 0   event: 83 
  Blocked List

------------------------------------------------------------------------
Event: unblock EventId: 83

<Simulation> system time: 10
  timeSliceQuantum      : 10
  numActiveProcesses    : 2
  numFinishedProcesses  : 0

  CPU
    Pid: 2   state: RUNNING  start: 4   used: 2   quant: 2   event: 0  
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 7   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 11
  timeSliceQuantum      : 10
  numActiveProcesses    : 2
  numFinishedProcesses  : 0

  CPU
    Pid: 2   state: RUNNING  start: 4   used: 3   quant: 3   event: 0  
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 7   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 12
  timeSliceQuantum      : 10
  numActiveProcesses    : 2
  numFinishedProcesses  : 0

  CPU
    Pid: 2   state: RUNNING  start: 4   used: 4   quant: 4   event: 0  
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 7   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: done

<Simulation> system time: 12
  timeSliceQuantum      : 10
  numActiveProcesses    : 1
  numFinishedProcesses  : 1

  CPU
    IDLE
  CPU

  Ready Queue Head
    Pid: 1   state: READY    start: 1   used: 7   quant: 0   event: 0  
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 13
  timeSliceQuantum      : 10
  numActiveProcesses    : 1
  numFinishedProcesses  : 1

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 8   quant: 1   event: 0  
  CPU

  Ready Queue Head
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 14
  timeSliceQuantum      : 10
  numActiveProcesses    : 1
  numFinishedProcesses  : 1

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 9   quant: 2   event: 0  
  CPU

  Ready Queue Head
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 15
  timeSliceQuantum      : 10
  numActiveProcesses    : 1
  numFinishedProcesses  : 1

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 10  quant: 3   event: 0  
  CPU

  Ready Queue Head
  Ready Queue Tail

  Blocked List
  Blocked List

------------------------------------------------------------------------
Event: cpu

<Simulation> system time: 16
  timeSliceQuantum      : 10
  numActiveProcesses    : 1
  numFinishedProcesses  : 1

  CPU
    Pid: 1   state: RUNNING  start: 1   used: 11  quant: 4   event: 0  
  CPU

  Ready Queue Head
  Ready Queue Tail

  Blocked List
  Blocked List

