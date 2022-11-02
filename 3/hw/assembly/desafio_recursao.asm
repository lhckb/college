.data
	msg: .asciiz "Digite seu número: "
	res: .asciiz "Seu número fatorial é: "
	
.text
	li $v0, 4 
	la $a0, msg
	syscall  # print initial message
	
	li $v0, 5
	syscall  # read integer
	move $t1, $v0  # store integer
	
	move $t2, $t1  # store in control register
	
	factorial:
		beq $t1, 1, out
		sub $t1, $t1, 1
		mul $t2, $t2, $t1
		j factorial
		
	out:
		li $v0, 4
		la $a0, res
		syscall  # print finish message
	
		move $a0, $t2
		li $v0, 1
		syscall  # print finish integer