/*
1. ALTAS: Se debe permitir ingresar un pasajero calculando autom�ticamente el
n�mero de Id. El resto de los campos se le pedir� al usuario.
2. MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido
o Precio o Tipo de pasajero o C�digo de vuelo
3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
4. INFORMAR:
1. Listado de los pasajeros ordenados alfab�ticamente por Apellido y Tipo de pasajero.
2. Total y promedio de los precios de los pasajes, y cu�ntos pasajeros superan el precio
promedio.
3. Listado de los pasajeros por C�digo de vuelo y estados de vuelos �ACTIVO�
1-NOTA: Se deber� realizar el men� de opciones y las validaciones a trav�s de funciones.
Tener en cuenta que no se podr� ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de alg�n pasajero.
2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "ArrayPassenger.h"
#define TAM 3

int main()
{
	setbuf(stdout, NULL);
    ePassenger pListaPasajeros[TAM];
    ePassenger unPasajero;
    initPassengers(pListaPasajeros, TAM);
    int contadorId = 1;
    int flagHayUnPasajero = 0;
    char seguir = 's';

    do
    {
		switch(menu())
		{
			case 1:
				if(addPassenger(pListaPasajeros,  TAM,  contadorId,  unPasajero.nombre, unPasajero.apellido, unPasajero.precio,
						unPasajero.tipoDePasajero,  unPasajero.codigoDeVuelo, unPasajero.estadoDelVuelo) == 0)
				{
					contadorId++;
					flagHayUnPasajero = 1;
				}
				else
				{
					printf("No se pudo realizar el alta\n");
				}
				break;

			case 2:
				if(flagHayUnPasajero == 1)
				{
					modificarPasajeros(pListaPasajeros, TAM);
				}
				else
				{
					printf("No se ingreso ningun pasajero\n");
				}

			break;
			case 3:
			break;
			case 4:
			break;
			case 5:
				printf("Si desea seguir ingresando pasajeros presione s\n");
				fflush(stdin);
				scanf("%c", &seguir);
			break;
			default:
				printf("La opcion elegida no existe\n");

			break;
		}
    }while(seguir == 's');


    return 0;
}
