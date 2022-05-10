#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#define VACIO 0
#define OCUPADO 1

int initPassengers(ePassenger* pListaPasajeros, int tam)
{
    int todoOk = -1;

    if(pListaPasajeros != NULL && tam > 0)
    {
        for(int i = 0; i<tam; i++)
        {
            pListaPasajeros[i].isEmpty = VACIO;
        }
        todoOk = 0;
    }


    return todoOk;
}

int menu()
{
    int opcion;

    printf("\n    **MENU DE OPCIONES**\n");
    printf(" ----------------------------\n");
    printf("\nSi quiere dar de alta un pasajero presione 1");
    printf("\nSi desea modificar algun dato del pasajero presione 2");
    printf("\nSi desea dar de baja un pasajero presione 3");
    printf("\nSi el informe de los pasajeros presione 4");
    printf("\nSi desea salir presione 5");
    printf("\n\nSeleccione una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int buscarEspacio(ePassenger* pListaPasajeros, int tam)
{
	int lugarVacio = -1;
	if(pListaPasajeros != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(pListaPasajeros[i].isEmpty == VACIO)
			{
				lugarVacio = i;
			}
		}//FIN FOR
	}//FIN IF
	return lugarVacio;
}//FIN FUN

int addPassenger(ePassenger* pListaPasajeros, int tam, int id, char nombre[],char apellido[],float precio,int tipoPasajero, char flycode[], int estadoDelVuelo)
{
	int retorno = -1;
	int index;
	if(pListaPasajeros != NULL && tam > 0 && id > 0 && nombre != NULL && apellido != NULL && flycode != NULL)
		{
			index = buscarEspacio(pListaPasajeros, tam);
			if(index != -1)
			{
				printf("*ALTA PASAJEROS*\n");
				pListaPasajeros[index].id = id;
				id++;

				printf("Ingrese un nombre: \n");
				fflush(stdin);
				scanf("%s", nombre);
				strcpy(pListaPasajeros[index].nombre, nombre);

				printf("Ingrese un apellido: \n");
				fflush(stdin);
				scanf("%s", apellido);
				strcpy(pListaPasajeros[index].apellido, apellido);

				printf("Ingrese un precio: \n");
				scanf("%f", &precio);
				pListaPasajeros[index].precio = precio;

				printf("Ingrese un codigo de vuelo: \n");
				fflush(stdin);
				scanf("%s", flycode);
				strcpy(pListaPasajeros[index].codigoDeVuelo, flycode);

				printf("Ingrese un tipo de pasajero: \n");
				scanf("%d", &tipoPasajero);
				pListaPasajeros[index].tipoDePasajero = tipoPasajero;

				printf("Ingrese un estado de vuelo: \n");
				scanf("%d", &estadoDelVuelo);
				pListaPasajeros[index].estadoDelVuelo = estadoDelVuelo;

				pListaPasajeros[index].isEmpty = OCUPADO;
				printf("Id   Nombre       Apellido  \t  Precio    Codigo de vuelo    Tipo de pasajero    Estado de vuelo\n");
				printPassenger(pListaPasajeros[index], tam);

				retorno = 0;
			}
			else
			{
				printf("No hay espacio en el sistema\n");
			}
		}

	return retorno;
}



int printPassenger(ePassenger unPasajero, int tam)
{
	int retorno = -1;
	if(tam > 0)
	{
		printf("%d    %-10s    %-10s    %1.2f    %-10s    %4d    %15d\n", unPasajero.id, unPasajero.nombre, unPasajero.apellido, unPasajero.precio,
				unPasajero.codigoDeVuelo, unPasajero.tipoDePasajero, unPasajero.estadoDelVuelo);


	}
	return retorno;
}

int printPassengers(ePassenger* pListaPasajeros, int tam)
{
	int retorno = -1;
	if(pListaPasajeros != NULL && tam > 0)
	{
		printf("Id     Nombre          Apellido                           Precio          Codigo de vuelo             Tipo de pasajero          Estado de vuelo\n");
		for(int i = 0; i < tam; i++)
		{
			if(pListaPasajeros[i].isEmpty == OCUPADO)
			{
				printPassenger(pListaPasajeros[i], tam);
			}

		}
		retorno = 0;
	}

	return retorno;
}
int buscarPasajeroPorId(ePassenger* pListaPasajeros, int tam,int id)
{
	int indexEncontrado = -1;
	if(pListaPasajeros != NULL && tam > 0)
	{
		for(int i = 0 ; i < tam ; i++)
		{
			if(pListaPasajeros[i].isEmpty == OCUPADO && pListaPasajeros[i].id == id)
			{
				indexEncontrado = i;
				break;
			}
		}
	}

	return indexEncontrado;
}


int modificarPasajeros(ePassenger* pListaPasajeros, int tam)
{
	int id;
	int idEncontrado;
	int opciones;
	char nombre[51];
	char apellido[51];
	float precio;
	char codigoDeVuelo[10];
	int tipoDePasajero;
	int estadoDelVuelo;

	if(pListaPasajeros != NULL && tam > 0)
	{
		printPassengers( pListaPasajeros, tam);
		printf("Ingrese el id del pasajero a modificar\n");
		scanf("%d", &id);
		idEncontrado = buscarPasajeroPorId(pListaPasajeros, tam, id);
		if(idEncontrado > 0 && idEncontrado <= tam)
		{
			printf("Pulse 1 para cambiar el nombre\n");
			printf("Pulse 2 para cambiar el apellido\n");
			printf("Pulse 3 para cambiar el precio\n");
			printf("Pulse 4 para cambiar el codigo de vuelo\n");
			printf("Pulse 5 para cambiar el tipo de pasajero\n");
			printf("Pulse 6 para cambiar el estado del vuelo\n");
			scanf("%d", &opciones);

			switch(opciones)
			{
				case 1:
					printf("Ingrese un nuevo nombre: \n");
					fflush(stdin);
					scanf("%s", nombre);
					strcpy(pListaPasajeros[idEncontrado].nombre, nombre);
				break;

				case 2:
					printf("Ingrese un nuevo apellido: \n");
					fflush(stdin);
					scanf("%s", apellido);
					strcpy(pListaPasajeros[idEncontrado].apellido, apellido);
				break;

				case 3:
					printf("Ingrese un nuevo precio: \n");
					scanf("%f", &precio);
					pListaPasajeros[idEncontrado].precio = precio;
				break;

				case 4:
					printf("Ingrese un nuevo codigo de vuelo: \n");
					fflush(stdin);
					scanf("%s", codigoDeVuelo);
					strcpy(pListaPasajeros[idEncontrado].codigoDeVuelo, codigoDeVuelo);
				break;

				case 5:
					printf("Ingrese un nuevo tipo de pasajero: \n");
					scanf("%d", &tipoDePasajero);
					pListaPasajeros[idEncontrado].tipoDePasajero = tipoDePasajero;
				break;

				case 6:
					printf("Ingrese un nuevo estado de vuelo: \n");
					scanf("%d", &estadoDelVuelo);
					pListaPasajeros[idEncontrado].estadoDelVuelo = estadoDelVuelo;
				break;
				default:
					printf("La opcion ingresada no es valida");
				break;

			}
			printPassenger(pListaPasajeros[idEncontrado], tam);
		}
	}
	return idEncontrado;
}



