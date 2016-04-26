.text
.globl main

main:
move $fp $sp
sw $ra 0($sp)
addiu $sp $sp -4

li $t0,0
sw $t0, 0($sp)
addiu $sp $sp -4
li $t0  10
sw $t0 -4($fp)
li $t0  3
move $t3 $t0
li $t0  5
sub $t4 $t3 $t0
bgez $t4,scope0_label1
scope0_label1:
beq $t0,$zero,scope1_label1

li $t0  8
sw $t0 -4($fp)
scope1_label1:
addiu $sp $sp 0

lw $t0 -4($fp)
move $t3 $t0
li $t0  6
sub $t4 $t0 $t3
bgez $t4,scope0_label2
scope0_label2:
beq $t0,$zero,scope1_label2

li $t0  99
sw $t0 -4($fp)
scope1_label2:
addiu $sp $sp 0

move $t7 $t0
li $t0  0

addiu $sp $sp 4
lw $ra 4($sp)
addiu $sp $sp 8
lw $fp 0($sp)
li $v0 10
syscall


