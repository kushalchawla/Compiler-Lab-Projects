.text
.globl main

main:
move $fp $sp
sw $ra 0($sp)
addiu $sp $sp -4

li $t0,0
sw $t0, 0($sp)
addiu $sp $sp -4
li $t0  8
move $t3 $t0
li $t0  5
mul $t0 $t0 $t3
sw $t0 -4($fp)
sw $fp 0($sp)
addiu $sp $sp -4
lw $t0 -4($fp)
sw $t0 0($sp)
addiu $sp $sp -4
jal abc
sw $t0 -4($fp)

move $t7 $t0
li $t0  0

addiu $sp $sp 4
lw $ra 4($sp)
addiu $sp $sp 8
lw $fp 0($sp)
li $v0 10
syscall


abc:
move $fp $sp
sw $ra 0($sp)
addiu $sp $sp -4

sw $fp 0($sp)
addiu $sp $sp -4
lw $t0 4($fp)
sw $t0 0($sp)
addiu $sp $sp -4
jal func
sw $t0 4($fp)
lw $t0 4($fp)

addiu $sp $sp 0
lw $ra 4($sp)
addiu $sp $sp 12
lw $fp 0($sp)
jr $ra


func:
move $fp $sp
sw $ra 0($sp)
addiu $sp $sp -4

lw $t0 4($fp)
move $t3 $t0
li $t0  30
sub $t0 $t3 $t0
beq $t0,$zero,scope1_label1

lw $t0 4($fp)
move $t3 $t0
li $t0  10
div $t0 $t3 $t0
sw $t0 4($fp)
scope1_label1:
addiu $sp $sp 0

lw $t0 4($fp)
move $t3 $t0
li $t0  10
sub $t0 $t3 $t0

addiu $sp $sp 0
lw $ra 4($sp)
addiu $sp $sp 12
lw $fp 0($sp)
jr $ra


