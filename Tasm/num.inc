.model small
.386
.stack 64
.data

m   db  '0', '0', '0','$'

.code
num proc 
	mov al, [m]
    mov al, 5
    inc al
    mov al, 15
    ret
endp

num1 proc 
	mov bl, [m]
    mov bl, [ m + 1]
    ret
endp