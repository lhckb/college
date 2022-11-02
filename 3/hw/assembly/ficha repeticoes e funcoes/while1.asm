.data
	one: .byte 1

.text
	move $t0, $zero  # total sum
	la $t1, one  # input register
	
	while:
		beqz $t1, out  # stop if read number is 0
		li $v0, 5
		syscall  # read integer
		move $t1, $v0  # store integer
		add $t0, $t0, $t1  # increment sum
		j while
		
	out:
		li $v0, 1
		move $a0, $t0
		syscall  # print final sum