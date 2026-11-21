# Topic 049: OS Components (I) — User Interface & Kernel Overview

---

## 1. Two Primary Architectural Layers of an Operating System
An Operating System is divided into two main parts to separate user interaction from low-level hardware control:
1. **User Interface (Shell):** The outer layer that handles communication with the user.
2. **Kernel:** The internal core containing the software components that perform the fundamental functions required throughout the computer's operation.

---

## 2. The User Interface (Shell)
The user interface acts as the intermediary between the human user and the OS kernel. Over time, interfaces have evolved into two major forms:

### A. Command-Line Interface (CLI) / Text-Based Shell
* **How it works:** Older shells communicated with users strictly through **textual messages** using a keyboard and monitor. Users typed explicit text commands to perform operations.
* **Characteristics:** Lightweight and fast for experienced users, but requires memorizing exact command syntax.

### B. Graphical User Interface (GUI)
* **How it works:** Modern shells represent system objects—such as files, folders, and programs—as visual **icons** on the screen.
* **Interaction Method:** Users issue commands by manipulating these icons using pointing devices (such as a **mouse**, **trackpad**, or **touchscreen**) alongside the keyboard.
* **Window Manager:**
  * A dedicated software component within a GUI shell responsible for allocating screen space to different applications.
  * Tracks which application is associated with each window and notifies the appropriate program when the user interacts with its window (e.g., clicking or typing inside it).

---

## 3. The Kernel & Its Core Components
Located beneath the shell, the **Kernel** performs the critical, behind-the-scenes management tasks of the OS. It consists of four major internal components (introduced here and detailed in subsequent topics):

1. **File Manager:** Coordinates the use of the machine's mass storage facilities (organizing files, directories, and access permissions).
2. **Device Drivers:** Software units that communicate directly with peripheral controllers (printers, monitors, disk drives) to carry out I/O operations.
3. **Memory Manager:** Coordinates the allocation and tracking of main memory (RAM) among competing programs and data.
4. **Scheduler & Dispatcher:**
   * **Scheduler:** Determines which activities/processes are considered for execution.
   * **Dispatcher:** Controls the allocation of CPU time to those scheduled activities (managing time slices and context switching).

---

## Quick Exam Revision Checklist
* **Shell = User Interface:** Translates user input into system requests (CLI = text commands; GUI = visual icons + pointing devices).
* **Window Manager Role:** Allocates screen space, tracks active windows, and routes user interactions (clicks/keystrokes) to the correct application.
* **4 Core Kernel Components:** File Manager, Device Drivers, Memory Manager, and Scheduler/Dispatcher.
* **MCQ Distinction — Scheduler vs. Dispatcher:** Scheduler decides *what* runs; Dispatcher allocates the actual *CPU time* to execute it.
