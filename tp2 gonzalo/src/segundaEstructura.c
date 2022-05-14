/*
 * segundaEstructura.c
 *
 *  Created on: 13 may. 2022
 *      Author: usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "segundaEstructura.h"

int cargarDescripcionEstado(eEstado pListaEstado[], int tam, int id,char descripcion[])
{
	int retorno = 0;

	if (pListaEstado != NULL && tam > 0 && id >= 1 && id <= 3 && descripcion != NULL)
	{
		for (int i = 0; i < tam; i++)
		{

			if (pListaEstado[i].id == id)
			{
				strcpy(descripcion, pListaEstado[i].descripcion);
				break;
			}

		} //fin for

		retorno = 1;

	} //fin if
	return retorno;
}
