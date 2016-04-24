.text
.globl main

main:
move $fp $sp
sw $ra 0($sp)
addiu $sp $sp -4

li $t0,0
sw $t0, 0($sp)
addiu $sp $sp -4
sw $fp 0($sp)
addiu $sp $sp -4
li $t0, 1
sw $t0, 0($sp)
addiu $sp $sp -4
sw $t0 0($fp)
sw $t0 -4($fp)
li $t0, 0
sw $t0, 0($sp)
addiu $sp $sp -4

addiu $sp $sp 4
lw $ra 4($sp)
addiu $sp $sp 12
lw $fp 0($sp)
li $v0 10
syscall


chinmay:
move $fp $sp
sw $ra 0($sp)
addiu $sp $sp -4

sw $t0 -4($fp)

addiu $sp $sp 0
lw $ra 4($sp)
addiu $sp $sp 20
lw $fp 0($sp)
jr $ra


