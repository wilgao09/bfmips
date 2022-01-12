.data
	memory: .space 30000
.text
.globl _main
_main:
la $t0, memory
lbu $t1, 0($t0)
addi $t1, $t1, 8
sb $t1, 0($t0)
l1:
addi $t0, $t0 1
lbu $t1, 0($t0)
addi $t1, $t1, 4
sb $t1, 0($t0)
l2:
addi $t0, $t0 1
lbu $t1, 0($t0)
addi $t1, $t1, 2
sb $t1, 0($t0)
addi $t0, $t0 1
lbu $t1, 0($t0)
addi $t1, $t1, 3
sb $t1, 0($t0)
addi $t0, $t0 1
lbu $t1, 0($t0)
addi $t1, $t1, 3
sb $t1, 0($t0)
addi $t0, $t0 1
lbu $t1, 0($t0)
addi $t1, $t1, 1
sb $t1, 0($t0)
addi $t0, $t0 -4
lbu $t1, 0($t0)
addi $t1, $t1, -1
sb $t1, 0($t0)
lbu $t1, 0($t0)
bnez $t1, l2
addi $t0, $t0 1
lbu $t1, 0($t0)
addi $t1, $t1, 1
sb $t1, 0($t0)
addi $t0, $t0 1
lbu $t1, 0($t0)
addi $t1, $t1, 1
sb $t1, 0($t0)
addi $t0, $t0 1
lbu $t1, 0($t0)
addi $t1, $t1, -1
sb $t1, 0($t0)
addi $t0, $t0 2
lbu $t1, 0($t0)
addi $t1, $t1, 1
sb $t1, 0($t0)
l3:
addi $t0, $t0 -1
lbu $t1, 0($t0)
bnez $t1, l3
addi $t0, $t0 -1
lbu $t1, 0($t0)
addi $t1, $t1, -1
sb $t1, 0($t0)
lbu $t1, 0($t0)
bnez $t1, l1
addi $t0, $t0 2
lbu $t1, 0($t0)
move $a0, $t1
addi $v0, $0, 11
syscall
addi $t0, $t0 1
lbu $t1, 0($t0)
addi $t1, $t1, -3
sb $t1, 0($t0)
lbu $t1, 0($t0)
move $a0, $t1
addi $v0, $0, 11
syscall
lbu $t1, 0($t0)
addi $t1, $t1, 7
sb $t1, 0($t0)
lbu $t1, 0($t0)
move $a0, $t1
addi $v0, $0, 11
syscall
lbu $t1, 0($t0)
move $a0, $t1
addi $v0, $0, 11
syscall
lbu $t1, 0($t0)
addi $t1, $t1, 3
sb $t1, 0($t0)
lbu $t1, 0($t0)
move $a0, $t1
addi $v0, $0, 11
syscall
addi $t0, $t0 2
lbu $t1, 0($t0)
move $a0, $t1
addi $v0, $0, 11
syscall
addi $t0, $t0 -1
lbu $t1, 0($t0)
addi $t1, $t1, -1
sb $t1, 0($t0)
lbu $t1, 0($t0)
move $a0, $t1
addi $v0, $0, 11
syscall
addi $t0, $t0 -1
lbu $t1, 0($t0)
move $a0, $t1
addi $v0, $0, 11
syscall
lbu $t1, 0($t0)
addi $t1, $t1, 3
sb $t1, 0($t0)
lbu $t1, 0($t0)
move $a0, $t1
addi $v0, $0, 11
syscall
lbu $t1, 0($t0)
addi $t1, $t1, -6
sb $t1, 0($t0)
lbu $t1, 0($t0)
move $a0, $t1
addi $v0, $0, 11
syscall
lbu $t1, 0($t0)
addi $t1, $t1, -8
sb $t1, 0($t0)
lbu $t1, 0($t0)
move $a0, $t1
addi $v0, $0, 11
syscall
addi $t0, $t0 2
lbu $t1, 0($t0)
addi $t1, $t1, 1
sb $t1, 0($t0)
lbu $t1, 0($t0)
move $a0, $t1
addi $v0, $0, 11
syscall
addi $t0, $t0 1
lbu $t1, 0($t0)
addi $t1, $t1, 2
sb $t1, 0($t0)
lbu $t1, 0($t0)
move $a0, $t1
addi $v0, $0, 11
syscall
addi $v0, $0, 10
syscall
