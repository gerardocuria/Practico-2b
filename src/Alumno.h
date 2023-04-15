/************************************************************************************************
Copyright (c) <year>, <copyright holders>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

#ifndef Alumno_H
#define Alumno_H

/** \brief Brief description of the file
 **
 ** Full file description
 **
 ** \addtogroup name Module denomination
 ** \brief Brief description of the module
 ** @{ */

/* === Headers files inclusions ================================================================ */

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

#include <stdint.h> 
#include <string.h> 
/*se supne que la cavezera del complador van entre llaves y las cavezeras propias entre comillas*/
/*el compilador gcc sabe donde esta stdint.h*/

/* === Public data type declarations =========================================================== */
typedef struct alumno_s{
    char apellido[50];
    char nombre[50];
    uint32_t documento;
} alumno_t;
/*la estructura se llama alumno_s y con typedef la defini como un tipo de dato llamado alumno_t*/


/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

int Serializar(const struct alumno_s * alumno, char cadena[], uint32_t espacio);
/*alumno es un puntero a el tipo de dato alumno_t*/
/*de esta manera paso la direccion de inicio de la estructura y no la estructura entera porque la estructura es grande para andar copiandola*/
/*la marco como const para indicar que no cambio el contenido de la estructura solo la leo*/
/*el const va a la izquierda para que sea constante la estructura, si estuviera a la derecha seria constante el puntero*/
/*un array es un puntero al primer elemeno por lo que char cadena[] es lo mismo que char cadena*/


/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif /* TEMPLATE_H */
