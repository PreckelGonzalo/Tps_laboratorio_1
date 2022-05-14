/*
 * segundaEstructura.h
 *
 *  Created on: 13 may. 2022
 *      Author: usuario
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef SEGUNDAESTRUCTURA_H_
#define SEGUNDAESTRUCTURA_H_

typedef struct
{
	int id;
	char descripcion[20];
	int isEmpty;
}eEstado;

int cargarDescripcionEstado(eEstado pListaEstado[], int tam, int id,char descripcion[]);
/**
* \brief carga la descripcion de un estado
*
* \param pListaEstado
* \param tam
* \param id
* \param tamEstado
* \param descripcion
* \return int
*/

#endif /* SEGUNDAESTRUCTURA_H_ */
