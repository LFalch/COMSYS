# Kaldkonvention

## Caller-saves

`%rax`,`%rcx`,`%rdx`,`%rsi`,`%rdi`,`%r10`-`%r11`

Typisk funktionsargumenter: `%rcx`,`%rdx`,`%rsi`,`%rdi`
Typisk returværdi: `%rax`

I x86prime bruges `%r11` til at holde returaddressen ved et funktionskald.

## Callee-saves

`%rbx`, `%rbp`, `%r12`-`%r15`
