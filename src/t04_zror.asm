title "Proyecto para EyPC 2020-2 Calculadora de dos numeros con Graficos"
    
	.model small
	.386
	.stack 64
	.data
x	db	6
y	dw	0
.code				;segmento de codigo
inicio:					;etiqueta inicio
	mov ax,@data 		;AX = directiva @data, @data es una variable de sistema que contiene la direccion del segmento de datos 
	mov ds,ax 			;DS = AX, inicializa segmento de datos

	xor ax, ax
	; x elevada al cubo 
	mov al, x
	mov bl, x
	mul bl
	mul bl
	mov y, ax

	xor ax, ax
	; x elevada al cuadrado multiplicado por dos
	mov al, x
	mov bl, x
	mul bl
	mov bl, 2
	mul bl

	;Le restamos el resultado a y
	sub y, ax

	xor ax, ax
	;multiplicamos por 3 x
	mov al, x
	mov bl, 3
	mul bl

	;Dividimos por 2 ax
	mov bl, 2
	div bl

	;Sumamos el resultado a y
	add y, ax

	;Sumamos y + 5
	add y, 5

salir:					;inicia etiqueta salir
	mov ah,4Ch			;AH = 4Ch, opcion para terminar programa
	mov al,0			;AL = 0 Exit Code, codigo devuelto al finalizar el programa
						;AX es un argumento necesario para interrupciones
	int 21h				;senal 21h de interrupcion, pasa el control al sistema operativo
	end inicio			;fin de etiqueta inicio, fin de programa