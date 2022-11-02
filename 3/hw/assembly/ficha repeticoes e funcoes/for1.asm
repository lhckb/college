.data
	newline: .byte '\n'

.text
	move $t0, $zero  # register $t0 will be our iterator
	
	while:
		li $v0, 1  
		move $a0, $t0
		syscall  # print value of $t0
		
		li $v0, 4  
		la $a0, newline
		syscall  # print newline
		
		add $t0, $t0, 1  # increment
		blt $t0, 10, while  # repeat while $t0 is less than 10
		