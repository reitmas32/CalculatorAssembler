menu_Botones macro

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Aqui va la lógica de la posicion del mouse;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;Si el mouse fue presionado en el renglon 0
	;se va a revisar si fue dentro del boton [X]
	cmp dx,0
	je botonX
	;Si el mouse fue presionado antes del renglon 9
	;no hay nada que revisar
	cmp dx,9
	jb mouse_no_clic
	;Si el mouse fue presionado despues del renglon 20
	;no hay nada que revisar
	cmp dx,20
	jg mouse_no_clic
	;Si el mouse fue presionado antes de la columna 24
	;no hay nada que revisar
	cmp cx,24
	jb mouse_no_clic
	;Si el mouse fue presionado despues de la columna 57
	;no hay nada que revisar
	cmp cx,57
	jg mouse_no_clic

	;Si el mouse fue presionado antes o dentro de la columna 28
	;revisar si fue dentro de un boton
	;Botones entre columnas 24 y 28: '7', '4', '1', 'C'
	cmp cx,28
	jbe botones_7_4_1_C

	;Si el mouse fue presionado en la columna 29
	;en esa columna no hay boton
	cmp cx,29
	je mouse_no_clic

	;Si el mouse fue presionado antes o dentro de la columna 34
	;revisar si fue dentro de un boton
	;Botones entre columnas 30 y 34: '8', '5', '2', '0'
	cmp cx,34
	jbe botones_8_5_2_0

	;Si el mouse fue presionado en la columna 35
	;en esa columna no hay boton
	cmp cx,35
	je mouse_no_clic

	;Si el mouse fue presionado antes o dentro de la columna 34
	;revisar si fue dentro de un boton
	;Botones entre columnas 36 y 40: '8', '5', '2', '0'
	cmp cx,40
	jbe botones_9_6_3_DEL

	;Si el mouse fue presionado en la columna 45
	;en esa columna no hay boton
	cmp cx,45
	je mouse_no_clic

	;Si el mouse fue presionado antes o dentro de la columna 34
	;revisar si fue dentro de un boton
	;Botones entre columnas 46 y 50: '8', '5', '2', '0'
	cmp cx,50
	jbe botones_Suma_Mul_Mod

	;Si el mouse fue presionado en la columna 53
	;en esa columna no hay boton
	cmp cx,53
	je mouse_no_clic

	;Si el mouse fue presionado antes o dentro de la columna 34
	;revisar si fue dentro de un boton
	;Botones entre columnas 46 y 50: '8', '5', '2', '0'
	cmp cx,57
	jbe botones_Resta_DivC_Igual
	;;;
	;;; COMPLETAR COMPARACIONES
	;;;

jmp_mouse_no_clic:
	jmp mouse_no_clic

botones_7_4_1_C:
	;Revisar si el renglon en donde fue presionado el mouse
	;corresponde con boton '7'
	cmp dx,11
	jbe boton7

	;Revisar si el renglon en donde fue presionado el mouse
	;corresponde con boton '4'
	cmp dx,14
	jbe boton4

	;Revisar si el renglon en donde fue presionado el mouse
	;corresponde con boton '1'
	cmp dx,17
	jbe boton1

	;Revisar si el renglon en donde fue presionado el mouse
	;corresponde con boton 'C'
	cmp dx,20
	jbe botonC

	;Si no es ninguno de los anteriores
	jmp mouse_no_clic
botones_8_5_2_0:
	;Revisar si el renglon en donde fue presionado el mouse
	;corresponde con boton '8'
	cmp dx,11
	jbe boton8
	;Revisar si el renglon en donde fue presionado el mouse
	;corresponde con boton '5'
	cmp dx,14
	jbe boton5
	;Revisar si el renglon en donde fue presionado el mouse
	;corresponde con boton '2'
	cmp dx,17
	jbe boton2
	;Revisar si el renglon en donde fue presionado el mouse
	;corresponde con boton '0'
	cmp dx,20
	jbe boton0
	;Si no es ninguno de los anteriores
	jmp mouse_no_clic

botones_9_6_3_DEL:
	;Revisar si el renglon en donde fue presionado el mouse
	;corresponde con boton '9'
	cmp dx,11
	jbe boton9
	;Revisar si el renglon en donde fue presionado el mouse
	;corresponde con boton '6'
	cmp dx,14
	jbe boton6
	;Revisar si el renglon en donde fue presionado el mouse
	;corresponde con boton '3'
	cmp dx,17
	jbe boton3
	;Revisar si el renglon en donde fue presionado el mouse
	;corresponde con boton 'DEL'
	cmp dx,20
	jbe botonDEL
	;Si no es ninguno de los anteriores
	jmp mouse_no_clic

botones_Suma_Mul_Mod:
	;Revisar si el renglon en donde fue presionado el mouse
	;corresponde con boton 'Suma'
	cmp dx,11
	jbe botonSuma
	;Revisar si el renglon en donde fue presionado el mouse
	;corresponde con boton 'Mul'
	cmp dx,15
	jbe botonMult
	;Revisar si el renglon en donde fue presionado el mouse
	;corresponde con boton 'Mod'
	cmp dx,19
	jbe botonDivR
	;Si no es ninguno de los anteriores
	jmp mouse_no_clic

botones_Resta_DivC_Igual:	;Revisar si el renglon en donde fue presionado el mouse
	;corresponde con boton 'Suma'
	cmp dx,11
	jbe botonResta
	;Revisar si el renglon en donde fue presionado el mouse
	;corresponde con boton 'Mul'
	cmp dx,15
	jbe botonDivC
	;Revisar si el renglon en donde fue presionado el mouse
	;corresponde con boton 'Mod'
	cmp dx,19
	jbe botonIgual
	;Si no es ninguno de los anteriores
	jmp mouse_no_clic

;Dependiendo la posicion del mouse
;se salta a la seccion correspondiente
botonX:
	jmp botonX_1
botonC:
	jmp botonC_1
botonDEL:
	jmp botonDEL_1
boton0:
	jmp boton0_1
boton1:
	jmp boton1_1
boton2:
	jmp boton2_1
boton3:
	jmp boton3_1
boton4:
	jmp boton4_1
boton5:
	jmp boton5_1
boton6:
	jmp boton6_1
boton7:
	jmp boton7_1
boton8:
	jmp boton8_1
boton9:
	jmp boton9_1
botonSuma:
	jmp botonSuma_1
botonResta:
	jmp botonResta_1
botonMult:
	jmp botonMult_1
botonDivC:
	jmp botonDivC_1
botonDivR:
	jmp botonDivR_1
botonIgual:
	posiciona_cursor 0,0
	mov al, [num1 + 0]
	add al, 48d
	imprime_caracter_color al, cAzul
	jmp mouse_no_clic
;Logica para revisar si el mouse fue presionado en [X]
;[X] se encuentra en renglon 0 y entre columnas 76 y 79
botonX_1:
	cmp cx,76
	jge botonX_2
	jmp mouse_no_clic
botonX_2:
	cmp cx,79
	jbe botonX_3
	jmp mouse_no_clic
botonX_3:
	;Se cumplieron todas las condiciones
	jmp salir
;Logica para revisar si el mouse fue presionado en '0'
;boton '0' se encuentra entre renglones 18 y 20,
;y entre columnas 24 y 28
boton0_1:
	cmp dx,18 		
	jge boton0_2
	jmp mouse_no_clic
boton0_2:
	cmp dx,20
	jbe boton0_3
	jmp mouse_no_clic
boton0_3:
	;Se cumplieron todas las condiciones
	mov num_boton,0
	jmp jmp_lee_num1 		;Salto a 'jmp_lee_num1' para procesar el numero

;Logica para revisar si el mouse fue presionado en '1'
;boton '1' se encuentra entre renglones 15 y 17,
;y entre columnas 24 y 28
boton1_1:
	cmp dx,15 		
	jge boton1_2
	jmp mouse_no_clic
boton1_2:
	cmp dx,17
	jbe boton1_3
	jmp mouse_no_clic
boton1_3:
	;Se cumplieron todas las condiciones
	mov num_boton,1
	jmp jmp_lee_num1 		;Salto a 'jmp_lee_num1' para procesar el numero

;Logica para revisar si el mouse fue presionado en '2'
;boton '2' se encuentra entre renglones 15 y 17,
;y entre columnas 24 y 28
boton2_1:
	cmp dx,15 		
	jge boton2_2
	jmp mouse_no_clic
boton2_2:
	cmp dx,17
	jbe boton2_3
	jmp mouse_no_clic
boton2_3:
	;Se cumplieron todas las condiciones
	mov num_boton,2
	jmp jmp_lee_num1 		;Salto a 'jmp_lee_num1' para procesar el numero

;Logica para revisar si el mouse fue presionado en '3'
;boton '3' se encuentra entre renglones 15 y 17,
;y entre columnas 36 y 40
boton3_1:
	cmp dx,15 		
	jge boton3_2
	jmp mouse_no_clic
boton3_2:
	cmp dx,17
	jbe boton3_3
	jmp mouse_no_clic
boton3_3:
	;Se cumplieron todas las condiciones
	mov num_boton,3
	jmp jmp_lee_num1 		;Salto a 'jmp_lee_num1' para procesar el numero

;Logica para revisar si el mouse fue presionado en '4'
;boton '4' se encuentra entre renglones 12 y 14,
;y entre columnas 24 y 28
boton4_1:
	cmp dx,12 		
	jge boton4_2
	jmp mouse_no_clic
boton4_2:
	cmp dx,14
	jbe boton4_3
	jmp mouse_no_clic
boton4_3:
	;Se cumplieron todas las condiciones
	mov num_boton,4
	jmp jmp_lee_num1 		;Salto a 'jmp_lee_num1' para procesar el numero

;Logica para revisar si el mouse fue presionado en '5'
;boton '5' se encuentra entre renglones 12 y 14,
;y entre columnas 30 y 34
boton5_1:
	cmp dx,12 		
	jge boton5_2
	jmp mouse_no_clic
boton5_2:
	cmp dx,14
	jbe boton5_3
	jmp mouse_no_clic
boton5_3:
	;Se cumplieron todas las condiciones
	mov num_boton,5
	jmp jmp_lee_num1 		;Salto a 'jmp_lee_num1' para procesar el numero

;Logica para revisar si el mouse fue presionado en '6'
;boton '6' se encuentra entre renglones 12 y 14,
;y entre columnas 36 y 40
boton6_1:
	cmp dx,12 		
	jge boton6_2
	jmp mouse_no_clic
boton6_2:
	cmp dx,14
	jbe boton6_3
	jmp mouse_no_clic
boton6_3:
	;Se cumplieron todas las condiciones
	mov num_boton,6
	jmp jmp_lee_num1 		;Salto a 'jmp_lee_num1' para procesar el numero

;Logica para revisar si el mouse fue presionado en '7'
;boton '7' se encuentra entre renglones 9 y 11,
;y entre columnas 24 y 28
boton7_1:
	cmp dx,9		
	jge boton7_2
	jmp mouse_no_clic
boton7_2:
	cmp dx,11
	jbe boton7_3
	jmp mouse_no_clic
boton7_3:
	;Se cumplieron todas las condiciones
	mov num_boton,7
	jmp jmp_lee_num1 		;Salto a 'jmp_lee_num1' para procesar el numero

;Logica para revisar si el mouse fue presionado en '8'
;boton '8' se encuentra entre renglones 9 y 11,
;y entre columnas 30 y 34
boton8_1:
	cmp dx,9 		
	jge boton8_2
	jmp mouse_no_clic
boton8_2:
	cmp dx,11
	jbe boton8_3
	jmp mouse_no_clic
boton8_3:
	;Se cumplieron todas las condiciones
	mov num_boton,8
	jmp jmp_lee_num1 		;Salto a 'jmp_lee_num1' para procesar el numero

;Logica para revisar si el mouse fue presionado en '9'
;boton '9' se encuentra entre renglones 9 y 11,
;y entre columnas 36 y 40
boton9_1:
	cmp dx,9 		
	jge boton9_2
	jmp mouse_no_clic
boton9_2:
	cmp dx,11
	jbe boton9_3
	jmp mouse_no_clic
boton9_3:
	;Se cumplieron todas las condiciones
	mov num_boton,9
	jmp jmp_lee_num1 		;Salto a 'jmp_lee_num1' para procesar el numero

;Logica para revisar si el mouse fue presionado en '0'
;boton '0' se encuentra entre renglones 18 y 20,
;y entre columnas 36 y 40
botonDEL_1:
	cmp dx,18 		
	jge botonDEL_2
	jmp mouse_no_clic
botonDEL_2:
	cmp dx,20
	jbe botonDEL_3
	jmp mouse_no_clic
botonDEL_3:
	;Se cumplieron todas las condiciones
	;mov num_boton,0
	;jmp jmp_lee_num1 		;Salto a 'jmp_lee_num1' para procesar el numero
	call BORRA_DIGITO_NUM_1

;Logica para revisar si el mouse fue presionado en '0'
;boton 'Suma' se encuentra entre renglones 18 y 20,
;y entre columnas 46 y 50
botonSuma_1:
	cmp dx,9 		
	jge botonSuma_2
	jmp mouse_no_clic
botonSuma_2:
	cmp dx,11
	jbe botonSuma_3
	jmp mouse_no_clic
botonSuma_3:
	;Se cumplieron todas las condiciones
	mov operador,1							;Numero de operacion 1 es la Suma
	posiciona_cursor 4, 58					;Posciono el CUrsor para poner el operador
	mov cl, 2Bh								;Caracter de la Suma
	imprime_caracter_color cl, cRojoClaro	;Se imprime el caracter suma
	jmp no_lee_num 		

;Logica para revisar si el mouse fue presionado en '0'
;boton 'Multiplicación' se encuentra entre renglones 18 y 20,
;y entre columnas 46 y 50
botonMult_1:
	cmp dx,13 		
	jge botonMult_2
	jmp mouse_no_clic
botonMult_2:
	cmp dx,15
	jbe botonMult_3
	jmp mouse_no_clic
botonMult_3:
	;Se cumplieron todas las condiciones
	mov operador,2							;Numero de operacion 2 es la Mult
	posiciona_cursor 4, 58					;Posciono el CUrsor para poner el operador
	mov cl, 78h								;Caracter de la Mult
	imprime_caracter_color cl, cRojoClaro	;Se imprime el caracter Mult
	jmp no_lee_num 

;Logica para revisar si el mouse fue presionado en '0'
;boton 'Residuo' se encuentra entre renglones 18 y 20,
;y entre columnas 46 y 50
botonDivR_1:
	cmp dx,17 		
	jge botonDivR_2
	jmp mouse_no_clic
botonDivR_2:
	cmp dx,19
	jbe botonDivR_3
	jmp mouse_no_clic
botonDivR_3:
	;Se cumplieron todas las condiciones
	mov operador, 3							;Numero de operacion 3 es la DivR
	posiciona_cursor 4, 58					;Posciono el CUrsor para poner el operador
	mov cl, 25h								;Caracter de la DivR
	imprime_caracter_color cl, cRojoClaro	;Se imprime el caracter DivR
	jmp no_lee_num 

;Logica para revisar si el mouse fue presionado en '0'
;boton 'Resta' se encuentra entre renglones 18 y 20,
;y entre columnas 46 y 50
botonResta_1:
	cmp dx,9 		
	jge botonResta_2
	jmp mouse_no_clic
botonResta_2:
	cmp dx,11
	jbe botonResta_3
	jmp mouse_no_clic
botonResta_3:
	;Se cumplieron todas las condiciones
	mov operador, 4							;Numero de operacion 3 es la Resta
	posiciona_cursor 4, 58					;Posciono el CUrsor para poner el operador
	mov cl, 2Dh								;Caracter de la Resta
	imprime_caracter_color cl, cRojoClaro	;Se imprime el caracter Resta
	jmp no_lee_num 

;Logica para revisar si el mouse fue presionado en '0'
;boton 'Cociente' se encuentra entre renglones 18 y 20,
;y entre columnas 46 y 50
botonDivC_1:
	cmp dx,13 		
	jge botonDivC_2
	jmp mouse_no_clic
botonDivC_2:
	cmp dx,15
	jbe botonDivC_3
	jmp mouse_no_clic
botonDivC_3:
	;Se cumplieron todas las condiciones
	mov operador, 5							;Numero de operacion 3 es la DivC
	posiciona_cursor 4, 58					;Posciono el CUrsor para poner el operador
	mov cl, 2Fh								;Caracter de la DivC
	imprime_caracter_color cl, cRojoClaro	;Se imprime el caracter DivC
	jmp no_lee_num 
;Salto auxiliar para hacer un salto más largo
jmp_lee_num1:
	jmp lee_num1

;Salto auxiliar para hacer un salto más largo
jmp_lee_num2:
	jmp lee_num2

;Logica para revisar si el mouse fue presionado en C
;boton C se encuentra entre renglones 18 y 20,
;y entre columnas 24 y 28
botonC_1:
	cmp dx,18		
	jge botonC_2
	jmp mouse_no_clic
botonC_2:
	cmp dx,20
	jbe botonC_3
	jmp mouse_no_clic
botonC_3:
	;Se cumplieron todas las condiciones
	;mov num_boton,7
	;jmp jmp_lee_num1 		;Salto a 'jmp_lee_num1' para procesar el numero
	call LIMPIA_PANTALLA_CALC
	jmp botones_7_4_1_C

endm