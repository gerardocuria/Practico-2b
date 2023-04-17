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


 /** \brief 
 **
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "Alumno.h"
#include <stdio.h>

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

static int SerializarCadena();
static int SerializarNumero();

/*con estatic hago que sean internas del c porque si alguien modifica el h y pone extern puede modificar la funcion*/

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/** @brief 
muestra en formato json y devuelve la cantidad de espacio usado
*/

static int SerializarCadena(const char * campo,const char * valor, char * cadena, int espacio){
    return snprintf(cadena, espacio, "\"%s\":\"%s\",", campo, valor);
}
/** @brief 
muestra en formato json y devuelve la cantidad de espacio usado
*/
static int SerializarNumero(const char * campo, int valor, char * cadena, int espacio){
    return snprintf(cadena, espacio, "\"%s\":\"%d\",", campo, valor);
}



/* === Public function implementation ========================================================== */

int Serializar(const struct alumno_s * alumno, char cadena[], uint32_t espacio){
    int disponibles = espacio;
    int resultado;

    cadena[0] = '{';
    cadena++;
    disponibles--;
    resultado = SerializarCadena("apellido",&alumno->apellido,cadena,disponibles);

    if (resultado > 0){
        disponibles -= resultado;
        cadena += resultado;
        resultado = SerializarCadena("nombre",&alumno->nombre,cadena,disponibles);
    }
    if (resultado > 0){
        disponibles -= resultado;
        cadena += resultado;
        resultado = SerializarNumero("documento",alumno->documento,cadena,disponibles);
    }
    if (resultado > 0){
        cadena += resultado;
        disponibles -= resultado;
        *(cadena-1)= '}';
        resultado = espacio - disponibles;
    }

    return resultado;
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */