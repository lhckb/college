.data
	msg: .asciiz "Digite a temperatura em C°: "
	resultado: .asciiz "A temperatura em Fahrenheit é, aproximadamente "
	multiplicator: .float 1.8
	trintaedois: .float 32.0
	
.text
	li $v0, 4 
	la $a0, msg
	syscall  # print initial message
	
	li $v0, 6
	syscall
	mov.s $f1, $f0  # get input floating point number
	
	jal convert
	
	li $v0, 4 
	la $a0, resultado
	syscall  # print final message
	
	li $v0, 2
	mov.s $f12, $f1
	syscall  # print float
	

	li $v0, 10
	syscall  # finish program
	
	convert:
		# load constants
  		l.s $f2, multiplicator
  		l.s $f3, trintaedois  
	
		# calculate
		mul.s $f1, $f1, $f2
		add.s $f1, $f1, $f3
		
		jr $ra