;Esto es un comentario
title "Estructura de un programa en lenguaje ensamblador" ;codigo opcional. Descripcion breve del programa, el texto entrecomillado se imprime como cabecera en cada pagina de codigo
	.model small ;directiva de modelo de memoria, small => 64KB para memoria de programa y 64KB para memoria de datos
	.386		;directiva para indicar version procesador
	.stack 64 	;Define el tamano del segmento de stack, se mide en bytes

f_x_ macro

;mov cl, len
;dec cl
loop1:
;Borramos ax
xor ax, ax

;movemos a di el contador
mov di, cont

;Obtemos el valor de bx
mov bl, [x + di]

;Aqui va el codigo
;Primer Funcion
cmp bl, 5
jbe f_x_1


;Tercer Funcion
mov al, 10
cmp al, bl
jb f_x_3

;Segunda Funcion
;Si no entro a alguno de los otros dos es por que esta en medio
jmp f_x_2

;aumentamos el contador
inc cont

;Compararamos ax y cx "EL contador y len"
mov ax, len
mov cx, cont
cmp cx, ax
jb loop1
jmp salir_f_x_

f_x_1:
    xor ax, ax
    mov al, bl
    mul bl
    add ax, 3
    mov [y + di], ax

    ;aumentamos el contador
    inc cont
    ;Compararamos ax y cx "EL contador y len"
    mov ax, len
    mov cx, cont
    cmp cx, ax
    jb loop1
    jmp salir_f_x_

f_x_2:
    xor ax, ax
    mov ax, cont
    cmp ax, 0
    je siguiente

    mov dx, di
    dec di
    mov ax, [y + di]
    mov di, dx
    sub ax, 2
    mov [y + di], ax


    siguiente:
    ;aumentamos el contador
    inc cont
    ;Compararamos ax y cx "EL contador y len"
    mov ax, len
    mov cx, cont
    cmp cx, ax
    jb loop1
    jmp salir_f_x_

f_x_3:
    xor ax, ax
    mov al, bl
    mov cl, 2
    div cl
    mov [y + di], ax
    mov al, bl
    mov cl, 4
    mul cl
    sub ax, 5
    add ax, [y + di]
    mov [y + di], ax

    ;aumentamos el contador
    inc cont
    ;Compararamos ax y cx "EL contador y len"
    mov ax, len
    mov cx, cont
    cmp cx, ax
    jb loop1
    jmp salir_f_x_
salir_f_x_:
endm

	.data		;Definicion del segmento de dato

    len     equ      22
    cont    dw       0           
	x db    0,  2,  3,  4,  7,  8,  9, 10, 12, 15, 18, 20, 17, 14, 13, 11,  9,  6,  5,  2,  1,  0
    y dw    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    

	.code				;segmento de codigo
inicio:					;etiqueta inicio
	mov ax,@data 		;AX = directiva @data, @data es una variable de sistema que contiene la direccion del segmento de datos 
	mov ds,ax 			;DS = AX, inicializa segmento de datos

	f_x_
salir:
	mov ah,4Ch			;AH = 4Ch, opcion para terminar programa
	mov al,0			;AL = [exCode] = 0 Exit Code, codigo devuelto al finalizar el programa
						;AX es un argumento necesario para interrupciones
	int 21h				;señal 21h de interrupcion, pasa el control al sistema operativo
	end inicio			;fin de etiqueta inicio, fin de programa