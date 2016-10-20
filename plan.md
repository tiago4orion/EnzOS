# Plan notes

## 16-bit real mode

While development in real mode is a big advantage in our case (because of BIOS access), 
being stuck in the 16-bit addressing makes VGA programming inneficient and/or clumsy.
If using the BIOS modes and interruptions (int 10h), the overhead to draw in the screen 
several times could be a problem. The other way, acessing video memory directly is much more
hard to get right in 16-bit real mode.
To address 0xb8000 in 16-bit real mode using a language like C requires the compiler to generate 
far pointers and very few of them have this feature. The problem arises from the fact that 
when in real mode the processor emulates a 8086 processor that had a 20-bit addressing by using
segments and offsets, but C compilers commonly do not generate SEG:OFFSET addresses and far jmp's/rets.

Direct BIOS access by interrupts makes easy to read/write in the hard drives, read from console, write
to serial console, enable/disable APM, change VGA modes, rewrite IVT, and so on. The other downside
is the limitation of 64Kib of code and data, and 1MB of total address space.

Working in real mode made easy to setup the machine to test user code too. Only requiring setting up 
a few exception handlers, load user compiled code at address 0x7c00 and set dl pointing to a drive.

Trade offs:

Pros:
- Easy programming by using BIOS functions;
- Easy to setup processor to test;

Cons:
- Hard to draw screen;
- Code/data size limits (64 Kib) and maximum of 1MB of memory; 
- Hard to use C nowadays;

## 32-bit real mode - aka Unreal mode

Unreal mode is a documented feature of 386 processors that enables up to 4Gib of address space while in real mode.
Until today, every intel processor since 386 had this feature, but it's very obscure and could lead to problems 
if not correctly understood.

Pros:
 - Easy programming by using BIOS functions;
 - Easy to setup processor to test;
 - Up to 4Gib address space
 - Easy to print to screen;
 - Easy to use C;

Cons:
 - Support may be dropped in the future;
 - Obscure feature;
 
 ## 32-bit protected mode
 
 Memory protection is a killer feature for operating systems, but useless in our case (no userspace software).
 Protected supports vm86 real mode tasks, but it cannot be used in our cause because it doesn't support the 
 switch to protected mode.
 
 Pros:
  - Up to 4Gib address space;
  - Easy to print to screen;
  - Easy to use C;
  
 Cons:
  - Requires pmode -> real mode to test user code;
  - Requires development of drivers (disk, serial, etc);
  