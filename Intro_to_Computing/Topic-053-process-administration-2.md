# Topic 053: Process and Its Administration (II)

---

## 1. The Process Table
To track and coordinate multiple processes competing for CPU time, the **Scheduler** maintains a dedicated block of information in main memory called the **Process Table**.

### What is Stored in Each Process Table Entry?
Whenever a new program is started, the Scheduler creates a new entry for its process in the Process Table containing:
* **Memory Area Assigned:** The exact starting address and size of the main memory (RAM) block allocated to that process (provided by the Memory Manager).
* **Process Priority:** A ranking value used by the Scheduler/Dispatcher to decide which waiting process should receive CPU time first.
* **Process State (Ready vs. Waiting):**
  * **Ready:** The process is in a state where its execution can continue immediately as soon as the CPU is assigned to it.
  * **Waiting:** The process is currently paused because its execution is delayed until some external event occurs (e.g., waiting for a disk read/write to finish or waiting for user keyboard input).

---

## 2. The Dispatcher & Time-Sharing Mechanics
The **Dispatcher** is the kernel component responsible for overseeing the actual execution of the scheduled processes by dividing CPU time into short intervals called **time slices** (typically around **50 milliseconds** or less).

### Step-by-Step Context Switching Cycle:
1. **Start Time Slice:** The Dispatcher selects a **Ready** process from the Process Table, resets a hardware timer circuit to measure one time slice, and jumps to that process's instruction in memory to begin execution.
2. **Timer Interrupt Signal:** When the allotted time slice expires, the timer circuit generates an electronic signal called an **interrupt**.
3. **Save Process State (Context):** Upon receiving the interrupt, the CPU stops executing the current process, saves its current state (values of the **Program Counter**, general-purpose **registers**, and status flags) into memory/Process Table, and switches back to the Dispatcher.
4. **Select Next Process:** The Dispatcher updates the Process Table, picks the next **Ready** process (taking priority into account), loads its previously saved register/Program Counter values, resets the timer, and starts the next time slice.

---

## 3. Early Termination of a Time Slice (I/O Wait)
A process does not always use its entire allotted time slice:
* If a running process requests a slow operation (such as reading data from mass storage or waiting for user input), it cannot proceed until that operation finishes.
* The Dispatcher immediately marks that process as **Waiting** in the Process Table and switches the CPU to another **Ready** process early—preventing valuable CPU cycles from sitting idle.
* Once the external event completes, the process's state is changed back from **Waiting** to **Ready**.

---

## Quick Exam Revision Checklist
* **Process Table:** Maintained by the **Scheduler** in main memory; tracks each process's **memory area**, **priority**, and **state (Ready vs. Waiting)**.
* **Ready vs. Waiting:** **Ready** = able to execute immediately; **Waiting** = paused until an external event (like I/O) completes.
* **Time Slice & Interrupt:** A **time slice** is a short CPU interval (~50 ms); when it ends, the timer triggers an **interrupt** so the **Dispatcher** can perform a **context switch** (saving registers & Program Counter).

### 4. Summary Table for Topic 53

| Component / Term | Core Function & Responsibility |
| :--- | :--- |
| **Scheduler** | Adds/removes processes and maintains the master Process Table in RAM. |
| **Process Table** | Master memory block storing Process ID, priority, memory bounds, and status (**Ready** vs. **Waiting**). |
| **Dispatcher** | Allocates CPU time slices to processes and oversees context switching. |
| **Time Slice** | Tiny slice of CPU execution time (milliseconds/microseconds). |
| **Timer Circuit & Interrupt** | Triggers a hardware interrupt signal when a process's time slice expires. |
| **Interrupt Handler** | Kernel code that preempts the current process and transfers control back to the dispatcher. |
| **Context Switch** | Saving the state of an interrupted process and restoring the state of the next ready process. |
