# CS101 — Topic 047: OS Basic Concepts (II)
**Instructor:** Dr. M. Tanvir Afzal | **Course:** Introduction to Computing (Virtual University)

---

## 1. Evolution of Computer Installations & Workstations
* **Shift from Central Batch Systems:** Following the introduction of multi-user, time-sharing operating systems, computing evolved toward a **central computer connected to remote workstations**.
* **Direct Communication:** Users could interact directly with the computer through their terminals/workstations rather than handing jobs over to a human computer operator.
* **Local Storage:** Commonly used programs and files began residing locally on the workstation's mass storage.

---

## 2. Transition from Computer Operator to System Administrator
* **Elimination of the Human Operator:** Because users could interact directly with the machine, a dedicated human operator was no longer needed to act as a middleman between the user and the hardware.
* **Personal Computers (PCs):** Modern PCs operate entirely at the sole discretion of the individual user.
* **Role of the System Administrator:** In multi-user and networked environments, the human expert's role shifted from hands-on machine operation to administrative management:
  * Obtaining and overseeing software/hardware installations.
  * Issuing and managing new user accounts.
  * Establishing and enforcing mass storage space limits (quotas).

---

## 3. Evolution of Operating System Capabilities
Operating systems progressed from simple programs executing **one job at a time** to complex systems supporting **time-sharing, multiprogramming, multitasking, and memory management**. As multi-processor systems and networks emerged, two key concepts became essential:

* **Load Balancing:** Dynamically allocating and distributing tasks across multiple processors so no single processor is overloaded while others sit idle.
* **Scaling:** Breaking a large task down into smaller subtasks compatible with the number of processors available to execute them efficiently.
* **Computer Networks:** Extend OS resource management across many interconnected machines and users, rather than confining it to an isolated computer.

---

## 4. Embedded Systems
* **Definition & Examples:** Specialized operating systems built into dedicated hardware devices rather than general-purpose computers—such as **medical devices, vehicle electronics, home appliances, cell phones, and handheld computers**.
* **Key Characteristics:**
  * Designed to **conserve battery power** and operate within strict resource constraints.
  * Often required to work continuously in a **real-time fashion** (meeting immediate timing deadlines).

---

## Quick Exam Revision Checklist
* **Computer Operator vs. System Administrator:** Operator = hands-on job execution (legacy batch systems); Administrator = manages accounts, installations, and storage limits.
* **Load Balancing vs. Scaling:** Load balancing = distributing tasks across processors; Scaling = splitting a task into subtasks to match available processors.
* **Embedded OS Priorities:** Power conservation + continuous real-time operation.
