# Topic 054: Handling Competition Between Processes
---

## 1. The Core Problem: Resource Contention
In a multitasking environment, multiple processes compete simultaneously for the computer's finite hardware and software resources (such as CPU time, main memory, printers, and shared data files).
* **Resource Allocation:** The Operating System must arbitrate competing requests so every process receives the resources it needs without corrupting data or crashing the system.
* **Non-Sharable Resources:** Some resources (like a printer or a file being actively modified) cannot be used by two processes at the exact same moment without causing garbled output or inconsistent data.

---

## 2. Semaphores & Mutual Exclusion
To coordinate access to a shared, non-sharable resource, the Operating System uses **semaphores**—special binary flags (control variables) maintained in memory.

### How a Semaphore Works:
* **Flag Values:**
  * **`0` (Clear / Available):** The resource is currently free and available for use.
  * **`1` (Set / Busy):** The resource is currently locked and in use by another process.
* **Access Protocol:**
  1. Before using a shared resource, a process checks the semaphore.
  2. If the semaphore is **`0`**, the process sets it to **`1`** (locking the resource) and proceeds.
  3. If another process checks the semaphore while it is **`1`**, it must wait until the first process finishes and resets the semaphore back to **`0`**.
* **Critical Region & Mutual Exclusion:**
  * **Critical Region:** A sequence of instructions that should be executed by at most one process at a time.
  * **Mutual Exclusion:** The requirement that only one process at a time can execute inside a critical region (or access a non-sharable resource).

### Why Checking & Setting Must Be Atomic (Interrupt-Disabled):
* If a **timer interrupt** occurs right after Process A reads a semaphore as `0`—but *before* Process A changes it to `1`—Process B could also read the semaphore as `0`, and both processes would enter the critical region simultaneously.
* **Solution:** Operating systems implement semaphore testing and setting as a single, indivisible (**atomic**) machine instruction (such as *test-and-set*), or temporarily disable interrupts during that check-and-set step.

---

## 3. Deadlock
When processes hold resources while waiting for other resources held by competing processes, the system can freeze in a state called **deadlock**.

* **Definition:** A condition in which two or more processes are permanently blocked because each process is waiting for a resource currently allocated to another process in the same group (e.g., Process A holds the **printer** and waits for the **CD drive**, while Process B holds the **CD drive** and waits for the **printer**).

### Three Necessary Conditions for Deadlock:
For deadlock to occur, all three of the following conditions must hold simultaneously:
1. **Competition for Non-Sharable Resources:** There is competition for resources that can only be used by one process at a time.
2. **Partial Allocation:** Resources are requested and allocated on a partial basis—a process acquires some resources and then waits to acquire additional ones.
3. **Non-Preemption (No Forcible Retrieval):** Once a resource has been allocated to a process, it cannot be forcibly taken away until the process voluntarily releases it.

---

## 4. Handling Deadlock: Prevention vs. Detection & Correction
Operating systems address deadlock using two main strategies—attacking one of the three necessary conditions (**Prevention**) or allowing deadlocks to happen and breaking them afterward (**Detection & Correction**):

| Strategy | Mechanism | Example |
| :--- | :--- | :--- |
| **Deadlock Prevention** | Eliminates at least one of the 3 necessary conditions so deadlock can never form. | **Spooling** (turns a non-sharable printer into a sharable disk queue); requiring processes to request **all resources at once** (eliminates partial allocation). |
| **Deadlock Detection & Correction** | Allows deadlock to occur, detects the circular wait, and forcibly breaks it. | Killing one of the deadlocked processes or forcibly preempting its allocated resource so the other process can finish. |

### Spooling (Eliminating Condition 1):
* **Spooling** (Simultaneous Peripheral Operations On-Line) resolves printer contention by having processes write their print output to separate files on **mass storage (disk)** instead of sending data directly to the printer.
* The OS then feeds those queued files to the physical printer one by one in the background—allowing multiple processes to "print" simultaneously without waiting or deadlocking.

---

## Quick Exam Revision Checklist
* **Semaphore:** A binary flag (`0` = available, `1` = busy) used to enforce **mutual exclusion** in a **critical region**.
* **Atomic Test-and-Set:** Testing and setting a semaphore must be indivisible so a timer interrupt cannot let two processes enter a critical region together.
* **Deadlock:** Processes permanently blocked waiting for resources held by each other.
* **3 Necessary Conditions for Deadlock:** (1) Competition for non-sharable resources, (2) Partial allocation, and (3) Non-preemption (resources cannot be forcibly retrieved).
* **Spooling:** Saves output to mass storage first so multiple processes can share a non-sharable device like a printer without deadlock.
