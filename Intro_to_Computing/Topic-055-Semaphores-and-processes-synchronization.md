# **Topic 055 — Semaphores**

Operating Systems | Exam-Oriented Notes

## **1. What is a Semaphore?**

A **Semaphore** is a protected variable or flag used by an operating system to control access to shared, non-sharable resources among multiple processes.

It helps prevent multiple processes from accessing the same resource simultaneously when such access could cause problems.

**Examples of shared resources:**

- Printer
- Shared file
- Memory location
- I/O device

Exam definition (memorize):

> A semaphore is a properly implemented flag used to control access to shared resources and provide mutual exclusion between processes.

## **2. Why Do We Need a Semaphore?**

Suppose two processes, Process A and Process B, want to use the same printer.

If both processes use the printer at the same time, their output may become mixed or corrupted.

The operating system must therefore:

- Check whether the resource is available.
- Allow access if it is free.
- Prevent access if it is already occupied.
- Make other processes wait until the resource becomes available.

This mechanism is known as **synchronization**.

[04 Kernel Programming Guide | Kernel | Micrium OS | v5.11.0 | Silicon Labs](https://images.openai.com/static-rsc-4/Wv8WbWaKF9LfbFS45Qzz4OzaL3ZIH4P2uSExO1UHl1ZANcN4IhkDeF5jcx5nZBGX2Wtfdo2zUmZBje6u6WbquCl_V7A_Pyr8oTtVIVoYRi8T94vCZnHqvEOkmbC9Wfa5Ah-Aoo834VeGPEG9ihZtJ2n-BmtCIZ-BEswgupygBSI?purpose=inline)

[PPT - Task 통신 및 동기화 : Message Queue, Semaphore Shared Memory PowerPoint Presentation - ID:4362220](https://images.openai.com/static-rsc-4/-kDjUJcc2uCqnAs5D5mIK5znnw7-xx4o3BKbBDu8o1x1hglh0NM9tJJs2Y3NbdVtU8eb0dgjDXaSRo75hCtFvF_cfrgJsmOwodSwdcco_KVGrQlWBreVdsRSsRUqOV2dYbi1baWXDY5w-sY3s7qgwXD-wVj_HPf_4K2qIBa4QGY?purpose=inline)

[Semaphore in OS - Scaler Topics](https://images.openai.com/static-rsc-4/tUgAjctmyEMhFsDFfmnsWhNDBLubWK1KR8DzQfmjidnBiBhX_1RYKSICkh4L1Z1IuOVYH1KV0w-YnyplLnH9hdCdc0-AdDzHNUOmJblM-5enr7vC01yYrpxzd1NSHRELvCAMi81G70uy7BFY1yClzHFC0xT0XhO5a5ijITPAoa0?purpose=inline)

6

## **3. Semaphore Using a Simple Flag**

The OS can use a single bit in memory called a **flag** to track the availability of a resource.

| Flag value  | State | Meaning                          |
| ----------- | ----- | -------------------------------- |
| `0` (Clear) | Free  | Resource is available            |
| `1` (Set)   | Busy  | Resource is currently being used |

### **Working**

- If the flag is `0`, the resource is available.
- The process is allowed to access the resource.
- The flag is changed to `1`.
- When the process finishes, the flag is cleared back to `0`.

Important exam point: A simple flag alone is not reliable in a multitasking operating system because checking and updating the flag can be interrupted.

## **4. Problem with a Simple Flag — Race Condition**

A simple flag can cause a **race condition** when multiple processes try to access a resource at the same time.

### **Example**

Suppose the printer is available and the flag is initially `0`.

**Process A**

**Process B**

**Step 1:** Process A checks the flag → `0` (Free)

**Step 2:** Process A is interrupted before setting the flag to `1`.

**Step 3:** Process B starts and checks the flag → `0` (Free)

**Step 4:** Process B sets the flag to `1` and enters the critical region.

**Step 5:** Process A resumes, sets the flag to `1`, and also enters the critical region.

Result: Both processes enter the critical region simultaneously.

This may cause data corruption or incorrect output.

### **Why does this happen?**

Because checking the flag and setting the flag are two separate operations. A process may be interrupted between them, allowing another process to check the same flag.

This problem is called a **Race Condition**.

Exam definition:

> A race condition occurs when multiple processes access or modify shared data concurrently, and the final result depends on the timing or order of their execution.

## **5. Solutions to the Simple Flag Problem**

The checking and setting of the flag must be performed as an **atomic operation**.

An atomic operation is completed as a single indivisible operation, without another process interfering in the middle.

There are two solutions in this lecture:

### **Solution 1 — Disabling Interrupts**

The operating system temporarily disables interrupts before checking and setting the flag.

Sequence

1\. Disable interrupts.

2\. Check the flag.

3\. Set the flag to `1` if the resource is free.

4\. Enable interrupts again.

**How it works:**

When interrupts are disabled, the CPU cannot respond to ordinary interrupt signals that could interrupt the protected routine and cause a context switch. Thus, the checking and setting process can complete without interruption by that mechanism.

**Advantages:**

- Prevents interruption during the flag-checking routine.
- Makes the flag checking and setting sequence safe on a single CPU when properly used by the OS.

**Limitation:**

- Disabling interrupts for too long can reduce system responsiveness.
- It is generally a privileged operation, so ordinary user processes cannot freely disable interrupts.
- Disabling interrupts on one CPU does not by itself protect shared data from other CPUs in a multiprocessor system.

[Mutual Exclusion Using Interrupt Disabling](https://images.openai.com/static-rsc-4/WF-0Y0PStpzVkmBubdTjCp63WrPxqYE48TCmw3bnIRcX2ismUhJ3FJB_pnlbVfv4vr_kf8aFeLHWrPogR12-HotcyEAsFBwX2ZabBd3hHH9K96kQ9PxdTvZl8hRCBKcAVwZCuToRSBpzUfPz6D--DGBffeiintVpNXZSnyhpy0o?purpose=inline)

### **Solution 2 — Test-and-Set Instruction**

**Test-and-Set** is a special hardware instruction that checks the current value of a flag and sets it in one atomic operation.

It performs the following tasks:

1. Reads the current value of the flag.
2. Returns or records the old value.
3. Sets the flag to `1`.

These operations occur indivisibly, so another process cannot interfere between the test and the update.

**Example**

- Initially, flag = `0`.
- Process A executes Test-and-Set → receives old value `0`, and the flag becomes `1`.
- Process B executes Test-and-Set → receives old value `1`, and the flag remains `1`.
- Process A gets access to the resource.
- Process B must wait.

**Why is it useful?**

Because the CPU completes the atomic Test-and-Set instruction before handling an ordinary interrupt, the check and update cannot be separated by an interrupt.

Exam definition:

> Test-and-Set is a hardware instruction that atomically reads the value of a flag and sets it to 1.

## **6. Critical Region (Critical Section)**

A **Critical Region** is a section of a program where a process accesses a shared or non-sharable resource.

Only one process should be allowed to execute in the critical region at a time when exclusive access is required.

### **Example**

Imagine two processes trying to print their documents using a single printer.

- Process A enters the critical region and uses the printer.
- Process B is not allowed to enter the critical region while A is using the printer.
- When A finishes, B may enter and use the printer.

[6.3: Processes and Concurrency - Engineering LibreTexts](https://images.openai.com/static-rsc-4/cOM0SigZZPWs1wjXNPyH5Fhe09u3LmEbpbAmaRNUxvzhrJoNUv1qfN54Hmd6fZZ8mj39RzegKPFAbZP0CZl2hvxZOWOBK5nmvUL9Re8gKGi3HvFL-3WOr7w6Vcf4v5hu_3G1wemopqMAMrq3O1s3fLt1lKiKfFZBkWYsS1kOVpY?purpose=inline)

Exam definition:

> A critical region is a sequence of instructions that accesses a shared resource and must be executed by only one process at a time to avoid interference.

## **7. Mutual Exclusion**

**Mutual Exclusion** is a mechanism or requirement that ensures only one process can enter a critical region at a time.

It prevents simultaneous access to a shared resource when concurrent access could cause errors.

### **Example**

If Process A is using a printer, Process B must wait until Process A finishes.

This ensures that both processes do not use the printer simultaneously.

Exam definition:

> Mutual exclusion is the requirement that only one process at a time can execute inside a critical region.

## **8. Relationship Between Semaphore, Critical Region & Mutual Exclusion**

This is an important conceptual question for exams.

**Semaphore**

Controls access to a shared resource

**Mutual Exclusion**

Ensures one process at a time

**Critical Region**

The protected code accessing the resource

| Term             | Purpose                                |
| ---------------- | -------------------------------------- |
| Semaphore        | Controls access to the shared resource |
| Mutual Exclusion | Prevents simultaneous entry            |
| Critical Region  | The code that accesses the resource    |

## **9. Important Differences (Exam Table)**

| Semaphore                                             | Simple Flag                                     |
| ----------------------------------------------------- | ----------------------------------------------- |
| Properly implemented protected variable/flag          | Ordinary variable used to indicate availability |
| Provides safe coordination when implemented correctly | Can cause race conditions                       |
| Uses atomic operations or equivalent protection       | Checking and setting may be interrupted         |
| Controls access to shared resources                   | Only stores the resource's status               |

| Critical Region                          | Mutual Exclusion                  |
| ---------------------------------------- | --------------------------------- |
| A section of program code                | A rule or requirement             |
| Contains code accessing shared resources | Allows only one process at a time |
| Needs protection                         | Protection is the goal            |

## **10. Short Questions — 2/3 Marks**

### **Q1. What is a semaphore?**

A semaphore is a properly implemented flag or protected variable used by an operating system to control access to shared resources among processes.

### **Q2. What is a critical region?**

A critical region is a section of code that accesses a shared resource and should be executed by only one process at a time.

### **Q3. Define mutual exclusion.**

Mutual exclusion is the requirement that only one process at a time can execute inside a critical region.

### **Q4. What is an atomic operation?**

An atomic operation is an operation that executes completely as a single indivisible unit, without interruption in the middle.

### **Q5. What is a race condition?**

A race condition occurs when multiple processes access shared data concurrently and the outcome depends on the timing or order of their execution.

### **Q6. Why is a simple flag not sufficient in a multitasking OS?**

Because checking and setting the flag involve separate instructions. A process can be interrupted between them, allowing another process to access the resource at the same time.

### **Q7. What is the Test-and-Set instruction?**

Test-and-Set is a hardware instruction that atomically reads the current value of a flag and sets it to `1`.

### **Q8. What is the purpose of disabling interrupts?**

Disabling interrupts prevents the CPU from responding to ordinary interrupt signals during a protected routine, helping prevent interruption while the flag is being checked and set.

### **Q9. What is a non-sharable resource?**

A non-sharable resource is a resource that cannot safely be used by multiple processes simultaneously.

**Examples:** A printer or a resource that requires exclusive access.

## **11. Long Questions — Exam Preparation**

### **Q1. Explain the semaphore and the problem with a simple flag.**

**Answer:**

A semaphore is a properly implemented flag used by an operating system to control access to shared, non-sharable resources among competing processes.

For example, when two processes want to use a single printer, the operating system must ensure that only one process uses it at a time.

A simple flag may be used to indicate the resource's availability:

- `0` indicates that the resource is free.
- `1` indicates that the resource is busy.

However, a simple flag is not reliable because checking and setting the flag are separate operations. A process may be interrupted after checking the flag but before setting it. Another process may then check the same flag and also find it free.

Consequently, both processes may enter the critical region, resulting in a race condition.

This problem can be solved by using atomic operations, such as disabling interrupts during the flag-checking routine or using a hardware Test-and-Set instruction.

### **Q2. Explain the race condition with an example.**

**Answer:**

A race condition occurs when multiple processes access shared data simultaneously, and the result depends on the order or timing of their execution.

Suppose two processes, A and B, want to use a printer. The printer is available, and its flag is initially `0`.

1. Process A checks the flag and finds it `0`.
2. Before A sets the flag to `1`, it is interrupted.
3. Process B checks the flag and also finds it `0`.
4. Process B sets the flag to `1` and enters the critical region.
5. Process A resumes, sets the flag to `1`, and also enters the critical region.

Both processes are now using the printer simultaneously.

This can cause incorrect output and data corruption. Atomic operations can prevent this problem.

### **Q3. Explain the two solutions for the simple flag problem.**

**Answer:**

The two solutions are:

**1. Disabling Interrupts**

The operating system disables interrupts before checking and setting the flag. After completing the operation, interrupts are enabled again. This prevents ordinary interrupt-driven task switching from interrupting the protected sequence.

**2. Test-and-Set Instruction**

Test-and-Set is a hardware instruction that reads the current flag and sets it to `1` atomically. Since the operation cannot be divided or interrupted in the middle, another process cannot interfere during the flag update.

Both techniques help protect shared resources and prevent race conditions when correctly applied.

### **Q4. Explain critical region and mutual exclusion with an example.**

**Answer:**

A critical region is a sequence of instructions that accesses a shared resource. It must be protected to prevent simultaneous access by multiple processes.

Mutual exclusion is the requirement that only one process at a time can execute inside the critical region.

For example, when Process A is using a printer, Process B must wait. Once Process A finishes, Process B can use the printer.

This prevents interference, incorrect output, and data corruption.

## **12. MCQs — Practice for Exams**

**1. A properly implemented flag used to control access to shared resources is called:**

- A) Register
- B) Semaphore
-

* C) Semaphore

1. D) Compiler

Correct answer: C) Semaphore

**2. A critical region contains instructions that:**

- A) Execute only during booting
- B) Access shared resources
- C) Compile a program
- D) Create processes

Correct answer: B) Access shared resources

**3. The requirement that only one process executes in a critical region at a time is called:**

- A) Multiprogramming
- B) Deadlock
- C) Mutual exclusion
- D) Paging

Correct answer: C) Mutual exclusion

**4. A race condition occurs because:**

- A) The CPU is too fast
- B) Processes compete and the result depends on execution timing
- C) The computer has no memory
- D) The printer is turned off

Correct answer: B) Processes compete and the result depends on execution timing

**5. Which instruction atomically checks and sets a flag?**

- A) Interrupt Enable
- B) Test-and-Set
- C) Read
- D) Write

Correct answer: B) Test-and-Set

**6. A flag value of&#x20;**`0`**&#x20;generally indicates that a resource is:**

- A) Busy
- B) Blocked
- C) Free
- D) Corrupted

Correct answer: C) Free

**7. Which technique can be used to prevent interruption while checking and setting a flag?**

- A) Paging
- B) Disabling interrupts
- C) Spooling
- D) Compilation

Correct answer: B) Disabling interrupts

## **13. Last-Minute Revision Sheet**

## **Memorize these before the exam**

- **Semaphore:** A properly implemented flag used to control access to shared resources.
- **Flag = 0:** Resource free.
- **Flag = 1:** Resource busy.
- **Race condition:** Result depends on process execution timing.
- **Critical region:** Code accessing a shared resource.
- **Mutual exclusion:** Only one process inside the critical region at a time.
- **Atomic operation:** Executes as one indivisible operation.
- **Test-and-Set:** Atomically reads and sets a flag.
- **Interrupt disabling:** Prevents ordinary interrupt handling during the protected sequence.
- **Problem with simple flag:** It can be interrupted between checking and setting.
- **Solution:** Use atomic operations or suitable OS-level protection.

### **Most important questions to prepare ⭐**

1. Define semaphore, critical region, and mutual exclusion.
2. Explain why a simple flag fails in a multitasking operating system.
3. Explain the race condition with the printer example.
4. Explain disabling interrupts as a solution.
5. Explain the Test-and-Set instruction.
6. Differentiate critical region and mutual exclusion.

Exam tip: If a long question asks about *semaphores*, don't forget to mention the **simple flag problem (race condition)** and both solutions (**disabling interrupts and Test-and-Set**). These are the key concepts connecting the entire lecture.

If you send the next lecture, I can keep the same exam-notes format so all your Operating Systems topics stay consistent and easy to revise.
