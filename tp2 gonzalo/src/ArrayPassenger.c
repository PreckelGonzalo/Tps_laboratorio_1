#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "segundaEstructura.h"
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

int soloLetras(char palabra[])
{
	int retorno= -1;
	int longitud = strlen(palabra);

	for(int i= 0; i < longitud; i++)
	{
		if((palabra[i] > 64 && palabra[i] < 91) || (palabra[i] > 96 && palabra[i] < 123))
		{
			retorno= 1;
		}// fin if

	}// fin for

return retorno;
}

int menu()
{
    int opcion;
    printf(" ----------------------------\n");
    printf("\n    **MENU DE OPCIONES**\n");
    printf(" ----------------------------\n");
    printf("\nSi quiere dar de alta un pasajero presione 1");
    printf("\nSi desea modificar algun dato del pasajero presione 2");
    printf("\nSi desea dar de baja un pasajero presione 3");
    printf("\nSi el informe de los pasajeros presione 4");
    printf("\nSi desea harcodear los pasajeros presione 5");
    printf("\nSi desea salir presione 6");
    printf("\n\nSeleccione una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int subMenu()
{
	int opcion;
		printf(" ----------------------------\n");
	    printf("\n    **SUBMENU DE OPCIONES**\n");
	    printf(" ----------------------------\n");
	    printf("\nSi quiere ordenar los pasajeros por apellido y tipo de pasajero de forma ascendente 1");
	    printf("\nSi quiere ordenar los pasajeros por apellido y tipo de pasajero de forma descendente 2");
	    printf("\nSi desea ver total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio presione 3");
	    printf("\nSi desea ver el listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’ de forma ascendente presione 4");
	    printf("\nSi desea ver el listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’ de forma ascendente presione 5");
	    printf("\nSi desea salir presione 6");
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

int addPassenger(ePassenger* pListaPasajeros, int tam,  eEstado pListaEstado[], int tamEstado, int id, char nombre[],char apellido[],float precio,int tipoPasajero, char flycode[], int estadoDelVuelo)
{
	int retorno = -1;
	int index;
	char letras[51];
	int comprobar;

	if(pListaPasajeros != NULL && tam > 0 && pListaEstado !=NULL && tamEstado > 0 && id > 0 && nombre != NULL && apellido != NULL && flycode != NULL)
	{
			index = buscarEspacio(pListaPasajeros, tam);
			if(index != -1)
			{
				printf("*ALTA PASAJEROS*\n");
				pListaPasajeros[index].id = id;
				id++;

				printf("Ingrese un nombre: \n");
				fflush(stdin);
				gets(letras);
				comprobar = soloLetras(letras);
				while(comprobar == -1 || strlen(letras) > 51)
				{

					printf("error, ingrese letras para el nombre o un nombre mas corto: \n");
					fflush(stdin);
					gets(letras);
					comprobar = soloLetras(letras);
				}

				strcpy(pListaPasajeros[index].nombre, letras);

				printf("Ingrese un apellido: \n");
				fflush(stdin);
				gets(letras);
				comprobar = soloLetras(letras);
				while(comprobar == -1 || strlen(letras) > 51)
				{
					printf("error, ingrese letras para el apellido o un apellido mas corto: \n");
					fflush(stdin);
					gets(letras);
					comprobar = soloLetras(letras);
				}
				strcpy(pListaPasajeros[index].apellido, letras);

				printf("Ingrese un precio: \n");
				gets(letras);
				comprobar = soloLetras(letras);
				while(comprobar == 1)
				{
					printf("error, Ingrese precio valido: \n");
					gets(letras);
					comprobar = soloLetras(letras);
				}
				pListaPasajeros[index].precio = atof(letras);

				printf("Ingrese un codigo de vuelo: \n");
				fflush(stdin);
				gets(letras);
				comprobar = soloLetras(letras);
				while(comprobar == -1 || strlen(letras)>10)
				{
					printf("error,Ingrese un codigo de vuelo mas corto o que tenga letras: \n");
					fflush(stdin);
					gets(letras);
					comprobar = soloLetras(letras);

				}
				strcpy(pListaPasajeros[index].codigoDeVuelo, letras);

				printf("Ingrese un tipo de pasajero: \n");
				gets(letras);
				comprobar = soloLetras(letras);
				while(comprobar == 1)
				{
					printf("error, ingrese un tipo de pasajero valido: \n");
					gets(letras);
					comprobar = soloLetras(letras);
				}
				pListaPasajeros[index].tipoDePasajero = atoi(letras);

				printf("Ingrese un estado de vuelo: \n");
				scanf("%d", &estadoDelVuelo);
				while(estadoDelVuelo < 1 && estadoDelVuelo > 4)
				{
					printf("error,Ingrese un estado de vuelo del 1 al 3: \n");
					scanf("%d", &estadoDelVuelo);
				}
				pListaPasajeros[index].estadoDelVuelo = estadoDelVuelo;

				pListaPasajeros[index].isEmpty = OCUPADO;
				printf("Id   Nombre       Apellido  \t  Precio    Codigo de vuelo    Tipo de pasajero    Estado de vuelo\n");
				printPassenger(pListaPasajeros[index], tam,pListaEstado, tamEstado);

				retorno = 0;
			}
			else
			{
				printf("No hay espacio en el sistema\n");
			}
		}

	return retorno;
}



int printPassenger(ePassenger unPasajero, int tam, eEstado pListaEstado[], int tamEstado)
{
	int retorno = -1;
	char estado[20];
	char estadoDos[20];
	if(tam > 0 && pListaEstado !=NULL && tamEstado)
	{
		mostrarTipos(unPasajero.tipoDePasajero , estadoDos);
		cargarDescripcionEstado(pListaEstado, tamEstado, unPasajero.estadoDelVuelo, estado);
		printf("%d    %-10s    %-10s    %1.2f    %-10s    %4d  %s  %15d  %s\n", unPasajero.id, unPasajero.nombre, unPasajero.apellido,
				unPasajero.precio, unPasajero.codigoDeVuelo, unPasajero.tipoDePasajero, estadoDos, unPasajero.estadoDelVuelo, estado);

	}
	return retorno;
}

int printPassengers(ePassenger* pListaPasajeros, int tam, eEstado pListaEstado[], int tamEstado)
{
	int retorno = -1;
	if(pListaPasajeros != NULL && tam > 0 && pListaEstado !=NULL && tamEstado > 0)
	{
		printf("Id     Nombre          Apellido                           Precio          Codigo de vuelo             Tipo de pasajero          Estado de vuelo\n");
		for(int i = 0; i < tam; i++)
		{
			if(pListaPasajeros[i].isEmpty == OCUPADO)
			{
				printPassenger(pListaPasajeros[i], tam, pListaEstado,tamEstado);
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


int modificarPasajeros(ePassenger* pListaPasajeros, int tam, eEstado pListaEstado[], int tamEstado)
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

	if(pListaPasajeros != NULL && tam > 0 && pListaEstado!=NULL && tamEstado > 0 )
	{
		printPassengers( pListaPasajeros, tam, pListaEstado,tamEstado);
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
			printPassenger(pListaPasajeros[idEncontrado], tam, pListaEstado, tamEstado);
		}
	}
	return idEncontrado;
}

int removePassenger(ePassenger* pListaPasajeros, int tam, eEstado pListaEstado[], int tamEstado)
{
	int retorno = -1;
	int index;
	int id;
	if(pListaPasajeros != NULL && tam > 0)
	{
		printPassengers(pListaPasajeros,tam, pListaEstado, tamEstado);
		printf("Elija el id del pasajero que quiere quitar del sistema: ");
		scanf("%d", &id);
		index = buscarPasajeroPorId(pListaPasajeros, tam, id);
		if(index == -1)
		{
			printf("No se encontraron pasajeros\n");
		}
		else
		{
			for(int i = 0; i < tam; i++)
			{
				pListaPasajeros[i].isEmpty = VACIO;
			}
			printf("El pasajero de la posicion %d fue eliminado del sistema\n", id);
			printPassengers(pListaPasajeros,tam,pListaEstado, tamEstado);
			retorno = id;

		}
	}

	return retorno;

}


int ordenarPasajeros(ePassenger* pListaPasajeros, int tam, int orden)
{
	int retorno = -1;
	ePassenger aux;

	if(pListaPasajeros != NULL && tam > 0)
	{
		if(orden == 0)
		{
			for(int i = 0; i < tam-1; i++)
			{
				for(int j = i+1; j < tam; j++)
				{
					if(strcmp(pListaPasajeros[i].apellido, pListaPasajeros[j].apellido)>=0 || (strcmp(pListaPasajeros[i].apellido, pListaPasajeros[j].apellido) == 0
							&& (pListaPasajeros[i].tipoDePasajero > pListaPasajeros[j].tipoDePasajero)))
					{
						aux = pListaPasajeros[i];
						pListaPasajeros[i] = pListaPasajeros[j];
						pListaPasajeros[j] = aux;
						retorno = 0;
					}
				}//FOR J
			}//FOR I
		}//IF ORDEN ASC
	if(orden == 1)
	{
		for(int i = 0; i<tam-1; i++)
		{
			for(int j = i-1; j < tam; j++)
			{
				if(strcmp(pListaPasajeros[i].apellido, pListaPasajeros[j].apellido) <= 0 || (strcmp(pListaPasajeros[i].apellido, pListaPasajeros[j].apellido) == 0
						&& (pListaPasajeros[i].tipoDePasajero < pListaPasajeros[j].tipoDePasajero)))
				{
					aux = pListaPasajeros[i];
					pListaPasajeros[i] = pListaPasajeros[j];
					pListaPasajeros[j] = aux;
					retorno = 0;
				}
			}
		}
	}
	}//IF NULL

	return retorno;
}

int mostrarPrecios(ePassenger* pListaPasajeros, int tam)
{
	int retorno = -1;
	if(pListaPasajeros != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(pListaPasajeros[i].isEmpty == OCUPADO)
			{
				printf("El precio del pasaje es %.2f\n", pListaPasajeros[i].precio);
			}
		}//FIN FOR i
	}
	return retorno;
}
int totalYPromedioPrecios(ePassenger* pListaPasajeros, int tam)
{
	float acumPrecios = 0;
	int contadorPrecios = 0;
	float promedio;

	if(pListaPasajeros != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(pListaPasajeros[i].isEmpty == OCUPADO)
			{
				acumPrecios = acumPrecios + pListaPasajeros[i].precio;
				contadorPrecios++;

			}
		 }
		promedio = acumPrecios / contadorPrecios;
		printf("El total de los precios es %.2f y el promedio es %.2f\n", acumPrecios, promedio);

	}//fin if


return promedio;
}

void superanPrecioPromedio (ePassenger* pListaPasajeros, int tam, float promedio)
{
	if(pListaPasajeros != NULL && tam > 0)
	{
		for (int i = 0; i<tam; i++)
		{
			if(pListaPasajeros[i].isEmpty > 0)
			{
			    if(pListaPasajeros[i].precio >= promedio )
			    {
			        printf("%s %s supera el Precio promedio porque su vuelo sale %.2f\n", pListaPasajeros[i].nombre, pListaPasajeros[i].apellido, pListaPasajeros[i].precio);
			    }//fin if

			}// fin if

		}// finfor

	}// fin if

}//fin void

int sortPassengers(ePassenger pListaPasajeros[], int tam, int orden, eEstado pListaEstado[], int tamEstado)
{
	int retorno = -1;
	ePassenger aux;

	if(pListaPasajeros!= NULL && tam > 0)
	{
		if(orden == 0)
		{
			for(int i = 0; i < tam -1; i++)
			{
				for(int j = i+1; j < tam; j++)
				{
					if(pListaPasajeros[i].tipoDePasajero < pListaPasajeros[j].tipoDePasajero)
					{
						aux = pListaPasajeros[i];
						pListaPasajeros[i] = pListaPasajeros[j];
						pListaPasajeros[j] = aux;
					}
				}
			}
		}//Orden ascendente
		if(orden == 1)
		{
			for(int i = 0; i < tam -1; i++)
			{
				for(int j = i+1; j < tam; j++)
				{
					if(pListaPasajeros[i].tipoDePasajero > pListaPasajeros[j].tipoDePasajero)
					{
						aux = pListaPasajeros[i];
						pListaPasajeros[i] = pListaPasajeros[j];
						pListaPasajeros[j] = aux;
					}
				}
			}
		}//Orden descendente
		for(int i = 0; i < tam; i++)
		{
			if(pListaPasajeros[i].estadoDelVuelo == 3 && pListaPasajeros[i].isEmpty == OCUPADO)
			{
				printPassenger(pListaPasajeros[i], tam, pListaEstado,tamEstado);
			}
		}

	}//fin if null

return retorno;
}

void mostrarTipos(int idTipo, char nombre[15])
{
    char tipo[3][15] = {"Menor", "Mayor", "Anciano"};

    if((idTipo > 0 && idTipo < 4) && nombre != NULL)
    {
    	idTipo = idTipo -1;
        strcpy(nombre, tipo[idTipo]);
    }//fin if

}//fin void



int HarcodeoPasajeros(ePassenger* pListaPasajeros, int tam , int cant, int id)
{
	int contador = -1;
	int idPasajero = 0;

	int ids[6] = {1,2,3,4,5,6};
	char nombre[6][51] = {"Martin", "Christian", "German", "Mauricio", "Octavio", "Monica"};
	char apellido[6][51] = {"Isusi", "Baus", "Scarafilo", "Davila", "Villegas", "Estrany"};
	float precio[6] = {32000, 48666, 37636, 21945, 87412, 66819};
	char codigoDeVuelo[6][10] = {"lPr","Kaj", "PfK", "LjD", "OPa", "Abs"};
	int tipoDePasajero[6] = {1, 3, 2, 3, 2, 1};
	int estadoDeVuelo[6] = {3, 1, 3, 2, 1, 3};

	if(pListaPasajeros != NULL && tam > 0 && cant > 0 && cant <=tam && id > 0)
	{
		contador = 1;
		for(int i = 0; i < cant; i++)
		{
			idPasajero=buscarPasajeroPorId(pListaPasajeros,tam,ids[i]);

			if(idPasajero==-1)
			{
				idPasajero=buscarEspacio(pListaPasajeros,tam);

			}//fin if

			pListaPasajeros[idPasajero].id = ids[i];
			strcpy(pListaPasajeros[idPasajero].nombre, nombre[i]);
			strcpy(pListaPasajeros[idPasajero].apellido, apellido[i]);
			pListaPasajeros[idPasajero].precio = precio[i];
			strcpy(pListaPasajeros[idPasajero].codigoDeVuelo, codigoDeVuelo[i]);
			pListaPasajeros[idPasajero].tipoDePasajero = tipoDePasajero[i];
			pListaPasajeros[idPasajero].estadoDelVuelo = estadoDeVuelo[i];
			pListaPasajeros[idPasajero].isEmpty = OCUPADO;
			contador++;

		}//fin for

	}//fin if niull


return contador;
}
