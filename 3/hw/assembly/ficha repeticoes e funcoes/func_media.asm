.data
	msg: .asciiz "Digite sua primeira nota: "
	resultado: .asciiz "A nota necessária na segunda unidade para passar por média é:  "
	const: .float 14.0
.text
	li $v0, 4 
	la $a0, msg
	syscall  # print initial message
	
	li $v0, 6
	syscall
	mov.s $f1, $f0  # get input floating point number
	
	jal calculate
	
	li $v0, 4 
	la $a0, resultado
	syscall  # print final message
	
	li $v0, 2
	mov.s $f12, $f2
	syscall  # print float

	li $v0, 10
	syscall  # finish program
	
	calculate:
		l.s $f10, const
		sub.s $f2, $f10, $f1
		jr $ra