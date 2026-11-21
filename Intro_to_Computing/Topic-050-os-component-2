# Topic 050: OS Components (II) — File Manager, Device Drivers & Memory Manager

---

## 1. File Manager
The **File Manager** is the kernel component responsible for coordinating the use of the machine's **mass storage facilities** (such as hard drives, SSDs, and USB drives).

### Key Responsibilities:
* **Tracking File Metadata:** Maintains records of every file's physical location on storage, size, creation/modification timestamps, and file type.
* **Access Control & Permissions:** Enforces security rules specifying which users or programs are permitted to read, modify, or delete specific files.
* **Managing Free Space:** Keeps track of which storage sectors/blocks are currently available for new files.
* **Directories (Folders) & Directory Paths:**
  * Groups files into **directories** (folders) to simplify organization for users.
  * Supports hierarchical nesting (directories inside directories), creating chains known as **directory paths**.
* **File Descriptors:**
  * When an application needs to access a file, it requests permission from the File Manager.
  * Once verified, the File Manager grants access and constructs a **file descriptor**—a data structure containing the information needed to locate and interact with the file.

---

## 2. Device Drivers
**Device Drivers** are specialized software units within the kernel that communicate directly with peripheral **controllers** (or directly with the peripheral devices themselves) to carry out input/output (I/O) operations.

### Key Concepts:
* **Hardware Abstraction:** Each device driver is uniquely designed for a specific type of peripheral device (e.g., a specific printer model, graphics card, disk drive, or monitor).
* **Translating Generic Requests:** Drivers translate generic, high-level I/O requests from the OS or applications (e.g., "print this document" or "read this sector") into the low-level technical signals required by that specific hardware controller.
* **Plug-and-Play Modularity:** Because device-specific logic is isolated inside drivers, new hardware can be added to a computer simply by installing its corresponding driver—without rewriting the rest of the Operating System.

---

## 3. Memory Manager
The **Memory Manager** is the kernel component responsible for coordinating the machine's use of **main memory (RAM)**.

### Key Responsibilities:
* **Single-Task vs. Multi-Task Environments:**
  * In simple single-program systems, memory management is minimal (loading one program, running it, and replacing it with the next).
  * In **multi-user or multitasking** environments, multiple programs and data blocks reside in RAM simultaneously, requiring strict coordination so programs do not overwrite or interfere with one another.
* **Allocation & Tracking:** Finds and reserves sufficient free memory space for each incoming program/data block and tracks which areas of RAM are currently occupied or free.
* **Virtual Memory & Paging:**
  * When the total memory required by running programs exceeds the physical capacity of main memory (RAM), the Memory Manager creates the illusion of larger memory space—known as **virtual memory**.
  * **Paging:** Accomplishes virtual memory by dividing programs and data into fixed-size units called **pages** (typically a few kilobytes each) and shuffling them back and forth between **main memory (RAM)** and **mass storage** as needed.

---

## Quick Exam Revision Checklist
* **File Manager:** Manages mass storage; creates **directories/directory paths**; issues a **file descriptor** when an app requests file access.
* **Device Drivers:** Communicate with hardware **controllers**; translate generic OS requests into device-specific instructions.
* **Memory Manager:** Manages **main memory (RAM)**; prevents interference between concurrent programs.
* **Virtual Memory & Paging:** Uses **mass storage** to simulate extra RAM by swapping fixed-size blocks called **pages** in and out of main memory.
