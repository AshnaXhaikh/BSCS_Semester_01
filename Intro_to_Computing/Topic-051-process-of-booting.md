# Topic 051: Process of Booting (Getting It Started)

---
> One Line Takeaway : Because main memory (RAM) is volatile and loses its contents when powered off, booting relies on a permanent boot loader stored in non-volatile ROM to copy the Operating System from mass storage into RAM and hand over CPU control upon startup.

## 1. The Core Problem: Volatile RAM & The Startup Paradox
* **Main Memory (RAM) is Volatile:** Whenever a computer is turned off, all contents inside main memory (RAM)—including the Operating System—are completely erased.
* **The Startup Paradox:** When the computer is first powered on, the CPU is designed to fetch and execute instructions from main memory, yet **RAM is completely empty** and the OS resides only on **mass storage** (hard drive/SSD).
* **Booting (Bootstrapping):** The automated startup procedure that transfers the Operating System from mass storage into main memory so the computer becomes operational.

---

## 2. Role of Non-Volatile Memory (ROM) & The Boot Loader
To solve the empty-RAM problem, computers reserve a small portion of main memory space constructed from **non-volatile memory cells** (such as **ROM — Read-Only Memory** or flash memory) whose contents survive even when power is disconnected.

* **Initial Program Counter Setup:** When the machine is turned on, the CPU's **Program Counter (PC)** is hardwired to start executing from the exact memory address where this non-volatile ROM begins.
* **Boot Loader (Bootstrap Program):**
  * A small, permanent program stored inside the non-volatile ROM.
  * **Primary Job:** Directs the CPU to read the main Operating System from a predetermined location on **mass storage** (e.g., hard disk or SSD) and load it into the volatile section of **main memory (RAM)**.
  * Once the OS is loaded into RAM, the boot loader executes a **jump instruction** that hands control of the CPU over to the Operating System.

---

## 3. Firmware & Modern Extensions (BIOS / UEFI)
* **Firmware:** Software permanently stored in non-volatile memory (ROM/flash) rather than on removable or standard mass storage—such as the boot loader routines.
* **Booting from Alternative Devices:**
  * Most modern boot loaders allow configuration changes (via BIOS/UEFI setup) so the computer can boot from a **USB flash drive**, **CD/DVD**, or **network server** instead of the primary hard drive (useful for installing a new OS or recovering a damaged system).
* **Embedded Systems Difference:**
  * In dedicated appliances (e.g., microwaves, washing machines, automotive controllers), the entire Operating System is often stored permanently in **ROM/firmware**, eliminating the need to copy it from mass storage during startup.

---

## 4. Step-by-Step Summary of the Booting Sequence
1. **Power On:** Electricity reaches the CPU; volatile RAM is empty.
2. **CPU Reads ROM:** The CPU's Program Counter points to the starting address of non-volatile **ROM** containing the **Boot Loader**.
3. **OS Transfer:** Following the boot loader's instructions, the CPU copies the Operating System from **mass storage** into **main memory (RAM)**.
4. **Control Handover:** The boot loader jumps to the OS entry point in RAM, and the Operating System takes over control of the machine.

---

## Quick Exam Revision Checklist
* **Why is Booting Needed?** Because **RAM is volatile** (loses its contents on power-off) while the OS is stored on **mass storage**.
* **Where is the Boot Loader Stored?** In **non-volatile memory (ROM / firmware)** so it is immediately available upon power-on.
* **What Does the Boot Loader Do?** Copies the OS from mass storage into volatile main memory (RAM) and transfers CPU execution control to it.
* **Firmware Definition:** Permanent software embedded in non-volatile memory (ROM) of a hardware device.
