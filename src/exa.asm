title "EyPC - Segundo Examen Parcial" ;directiva title opcional
	.model small	;directiva para especificar segmento de datos y codigo de 64 KB cada uno
	.stack 64	;define segmento de pila en bytes
	.data		;segmento de datos

factorial macro
mov cl, num2 
mov al, 1
mov bl, 1
loop1:
    mul bl
    inc bl
    dec cx
    cmp cx, 0
    jne loop1
    mov resultado, ax
endm

mulSuma macro
    mov al, num1
    mov bl, num1
    mul bl
    add al, num1
    mov resultado, ax
endm

num1	    db	1	
num2	    db	4
resultado	dw	0
	.code	;segmento de código
inicio:			;etiqueta ‘inicio’
	mov ax,@data	;carga @data en AX para especificar segmento de datos del programa
	mov ds,ax	;DS = AX = @data
	
    mov al, num1
    mov bl, 9
    cmp bl, al
    jb salir
    mov al, num1
    cmp bl, al
    jb salir

    xor ax, ax
    xor bx, bx
    mov al, num1
    mov bl, num2

    cmp al, bl
    jae f2
    jmp f1

    f1:
    factorial
    jmp salir

    f2:
    mulSuma
    jmp salir

salir:			;etiqueta salir
	mov ax,4C00h	;AH = 4Ch, opcion 4C para int 21h, AL = 00, exit Code 
	int 21h		;ejecuta interrupción 21h
	end inicio	;fin de programa