# 🖥️ Operating Systems — Custom Shell & File Management

![Language](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c)
![OS](https://img.shields.io/badge/OS-Linux-FCC624?style=for-the-badge&logo=linux)
![Institution](https://img.shields.io/badge/IPCA-EST-005A36?style=for-the-badge)

A comprehensive practical project exploring the core concepts of operating systems, including direct file manipulation, process management, and file system administration. 

---

## 📋 Project Overview

This project is divided into three main modules that interact directly with the Linux Operating System kernel, completely bypassing high-level libraries where applicable.

### Part 1: File Manipulation via System Calls
Implementation of standard file utility commands utilizing strict, low-level UNIX system calls (`open`, `read`, `write`, `close`, `lstat`, `unlink`, `opendir`) instead of standard C libraries (`fopen`, `printf`).
* **`mostra`:** Displays the contents of a file to standard output.
* **`copia`:** Creates an exact duplicate of a target file.
* **`acrescenta`:** Appends the contents of a source file to a destination file.
* **`conta`:** Counts and prints the number of lines within a text file.
* **`apaga`:** Prompts for user confirmation and safely deletes a file.
* **`informa`:** Outputs metadata (inode, UID, creation/modification dates, file type).
* **`lista`:** Lists directory contents, differentiating between files and folders.

### Part 2: Custom Command Line Interpreter (Shell)
Development of an interactive shell to read and execute user commands.
* **Process Creation & Synchronization:** Uses `fork()` to spawn child processes, `execvp()` to execute binaries, and `wait()` to sync parent-child execution states.
* **Dual Implementation:** Includes two versions of the interpreter—one leveraging LibC (`fgets`, `strtok`) for string parsing, and a strict system-call-only version ensuring complete low-level control.

### Part 3: Storage Management & Forensics
System administration tasks focusing on disk partitioning, volume management, and forensic data recovery.
* **Logical Volume Management (LVM):** Creation of Physical Volumes (PV), Volume Groups (VG), and Logical Volumes (LV) over a newly provisioned 10GB virtual disk using `fdisk`.
* **File Systems:** Formatting logical volumes with `ext3` and `ext4`, followed by directory mounting (`mount`) and strict permission adjustments (`chmod 604`).
* **Forensic Analysis:** Inspection of a FAT12 file system image (`fs.img`). Utilized tools like `fsstat` for metadata, `fls` to identify deleted directories/files, and `icat` to extract the raw content of a deleted file located at block 4.

---

## 🎓 Academic Information

* **Institution:** Instituto Politécnico do Cávado e do Ave (IPCA)
* **School:** Escola Superior de Tecnologia (EST)
* **Degree:** Licenciatura em Engenharia de Sistemas Informáticos
* **Course Unit:** Sistemas Operativos (Operating Systems)
* **Academic Year:** 2024/2025
* **Instructor:** Prof. Fernando Alexandre Peixoto Gomes

---

## 👥 Development Team

* **Marina Silva** — No. 31029
* **Nelson Cruz** — No. 31103
* **Nuno Oliveira** — No. 31550
