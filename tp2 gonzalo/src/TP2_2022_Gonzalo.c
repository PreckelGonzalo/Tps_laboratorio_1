/*
1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
número de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Precio o Tipo de pasajero o Código de vuelo
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.
3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
1-NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún pasajero.
2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "segundaEstructura.h"
#define TAM 2000
#define tam_estado 3

int main()
{
	setbuf(stdout, NULL);
    ePassenger pListaPasajeros[TAM];
    ePassenger unPasajero;
    initPassengers(pListaPasajeros, TAM);
    eEstado pListaEstado[tam_estado] =
    {
    		{1, "Cancelado"},
			{2, "Demorado"},
			{3, "Activo"}
    };
    int contadorId = 1;
    int contadorIDS = 1;
    int flagHayUnPasajero = 0;
    int flagHarcodeo = 0;
    char seguir = 's';

    do
    {
		switch(menu())
		{
			case 1:
				if(flagHarcodeo == 0)
				{
					addPassenger(pListaPasajeros,  TAM, pListaEstado, tam_estado, contadorId,  unPasajero.nombre, unPasajero.apellido,
							unPasajero.precio, unPasajero.tipoDePasajero,  unPasajero.codigoDeVuelo, unPasajero.estadoDelVuelo);
					contadorId++;
					flagHayUnPasajero = 1;
				}
				else
				{
					printf("No se pudo realizar el alta\n");
				}
				break;

			case 2:
				if(flagHayUnPasajero == 1 || flagHarcodeo == 1)
				{
					modificarPasajeros(pListaPasajeros, TAM,pListaEstado, tam_estado);
				}
				else
				{
					printf("No se ingreso ningun pasajero\n");
				}

			break;
			case 3:
				if(flagHayUnPasajero == 1 || flagHarcodeo == 1 )
				{
					removePassenger(pListaPasajeros,TAM,pListaEstado, tam_estado);
				}
				else
				{
					printf("No se ingreso ningun pasajero\n");
				}
			break;
			case 4:
				if(flagHayUnPasajero == 1 || flagHarcodeo == 1)
				{
					switch(subMenu())
					{
					case 1:
						printf("Pasajeros desordenados\n");
						printPassengers(pListaPasajeros, TAM, pListaEstado, tam_estado);
						ordenarPasajeros(pListaPasajeros,TAM, 0);
						printf("Pasajeros ordenados\n");
						printPassengers(pListaPasajeros, TAM, pListaEstado, tam_estado);
					break;

					case 2:
						printf("Pasajeros desordenados\n");
						printPassengers(pListaPasajeros, TAM, pListaEstado, tam_estado);
						ordenarPasajeros(pListaPasajeros,  TAM, 1);
						printf("Pasajeros ordenados\n");
						printPassengers(pListaPasajeros, TAM, pListaEstado, tam_estado);
					break;

					case 3:
						mostrarPrecios(pListaPasajeros, TAM);
						superanPrecioPromedio(pListaPasajeros,TAM,totalYPromedioPrecios(pListaPasajeros, TAM));
					break;

					case 4:
						sortPassengers(pListaPasajeros, TAM, 0, pListaEstado, tam_estado);
					break;

					case 5:
						sortPassengers(pListaPasajeros, TAM, 1, pListaEstado, tam_estado);
					break;

					default:
						printf("ingrese una opcion valida\n");
					break;

					}//fin switch

				}//fin if
			break;

			case 5:
				if(flagHayUnPasajero == 1)
				{
					printf("YA HAY PASAJEROS\n");
				}
				else
				{
					HarcodeoPasajeros(pListaPasajeros, TAM , 6 , contadorIDS);
					contadorIDS++;
					printf("ya se hizo el harcodeo adecuadamente\n");
					flagHarcodeo = 1;
				}
			break;

			case 6:
				if(flagHayUnPasajero == 0 || flagHarcodeo == 0)
				{
					printf("seguro desea salir aun cuando no ingreso pasajeros ni los harcodeo?\n");
				}
				printf("Si desea seguir ingresando pasajeros presione s\n");
				fflush(stdin);
				scanf("%c", &seguir);
			break;

			default:
				printf("La opcion elegida no existe\n");
			break;
		}//fin del switch

    }while(seguir == 's');

return 0;
}
