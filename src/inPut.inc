.code
;x  -> Seran variables directas se modificaran antes de mandar a llamar a el procedimiento
;y  -> Seran variables directas se modificaran antes de mandar a llamar a el procedimiento

;num#Char -> estara en 

leeNum2 macro x, y
	mov [num2Char], 48
	mov [num2Char + 1], 48
	mov [num2Char + 2], 48
	mov [num2Char + 3], 48

	mov [cont], 1d
	imprimeTexto x,y,msg
	mov posCurX, x
	mov posCurY, y
	add posCurX, 43
	lee4_2:

		mov dh, x			;Posiciono el cursor un la linea 5
		mov dl, posCurX		;Posiciono el cursor en la columna count
		mov ah, 02h			;Funcion para movore el cursor
		int 10h				;Interrupcion 10h

		mov ah, 8h			;Funcion que Lee del teclado
		int 21h				;Interrupccion 21h

		mov numTmp, al		;Guarda lo leido en al

		cmp al, 13			;Retorno de Carro
		jz realizaConversion_2;Sale de la lectura

		mov bl, 58			;Guarda el valor ascii del caracter 9

		cmp numTmp, bl		;Comapara numTmp y bl
		jae  lee4_2			;Si numTmp es mayor a 9 no lo recibe

		mov bl, 47			;Guarda el valor ascii del caracter 0

		cmp bl, numTmp		;Comapara numTmp y bl
		jae  lee4_2		;Si numTmp es menor a 0 no lo recibe

		lea dx, [numTmp]	;Creamos un offset de memoria
		mov cx,1d			;Numero de veces que imprimira el caracter
		mov ah, 0Ah			;Funcion que Imprime
		int 10h				;Interrupcion 10h

		;sub numTmp, 48		;realizamos un offset para tener numeros
		mov al, numTmp		;movemos el numero a al

		desplazaNum num2Char, al
		add cont, 1d		;Aumentamos el contador de los caracteres leidos
		mov bl, 4d			;Movemos el numero 4 como maximo num de digitos
		add posCurX, 1
		cmp bl, cont			;comparamos al y bl
		jae lee4_2			;regresamos a leer mas
	realizaConversion_2:
			convierte_Digito_Num num2Char, num2
			convierte_Array_Num num2, num2Digito
endm leeNum2