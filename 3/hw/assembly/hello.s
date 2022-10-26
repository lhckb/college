.text
	li $v0, 4  # Write syscall
	la $a0, msg  # Loads the address of msg to $a0
	syscall  # Calls what is in $v0 (in this case 4 is the write syscall)
	
	li $v0, 4  
	la $a0, character  # Loads single byte into $a0
	syscall
	
	li $v0, 4  
	la $a0, newline 
	syscall
	
	li $v0, 1
	lw $a0, numi  # Loads word into register $a0
	syscall
	
	li $t0, 75  # Loads immediate value 75 into $t0
	li $t1, 25  # Loads immediate value 25 into $t1
	add $s0, $t0, $t1  # Sums $t0 and $t1 and stores in $s0
	
	addi $s1, $s0, 100  # Sums the value of $s0 to the immediate value of 100
	
	li $v0, 10
	syscall

.data
	msg: .asciiz "hello world\n"  # msg label containing a string of type .asciiz (zero terminated ascii string)
	character: .byte 'a'  # Type byte represents a single 8-bit character
	numi: .word 3
	newline: .byte '\n'