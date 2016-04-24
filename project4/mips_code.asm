.text
.globl main

main:
move $fp $sp
sw $ra 0($sp)
addiu $sp $sp -4

li $t0,0
sw $t0, 0($sp)
addiu $sp $sp -4

addiu $sp $sp 4
lw $ra 4($sp)
addiu $sp $sp 8
lw $fp 0($sp)
li $v0 10
syscall



