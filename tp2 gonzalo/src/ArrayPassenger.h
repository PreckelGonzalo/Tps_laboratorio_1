#ifndef ARRAYPASSENGER_H_INCLUDED
#define ARRAYPASSENGER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "segundaEstructura.h"

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float precio;
    char codigoDeVuelo[10];
    int tipoDePasajero; // 1)Menor 2) Mayor 3)Jubilado
    int estadoDelVuelo; // 1)peruano 2)Descompuesto 3)Activo
    int isEmpty;
}ePassenger;

#endif // ARRAYPASSENGER_H_INCLUDED

int menu();

int subMenu();

/**
*\brief To indicate that all position in the array are empty,
 this function put the flag (isEmpty) in TRUE in all
 position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok

*/

int initPassengers(ePassenger* pListaPasajeros, int len);


/**
*\brief add in a existing list of passengers the values received as parameters
 in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addPassenger(ePassenger* pListaPasajeros, int tam,  eEstado pListaEstado[], int tamEstado, int id, char nombre[],char apellido[],
		float precio,int tipoPasajero, char flycode[], int estadoDelVuelo);

/**
*\brief find a Passenger by Id en returns the index position in array.
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*/
int findPassengerById(ePassenger* pListaPasajeros, int len,int id);

/**
*\brief Remove a Passenger by Id (put isEmpty Flag in 1)
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok

*/
int removePassenger(ePassenger* pListaPasajeros, int tam, eEstado pListaEstado[], int tamEstado);

/**
*\brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int ordenarPasajeros(ePassenger* pListaPasajeros, int len, int orden);

/**
* \brief prints the content of passengers array
*
* \param unPasajero
* \param tam
* \param pListaEstado
* \param tamEstado
* \return int
*
*/
int printPassenger(ePassenger unPasajero, int tam, eEstado pListaEstado[], int tamEstado);

/**
* \brief prints the content of passengers array
*
* \param unPasajero
* \param tam
* \param pListaEstado
* \param tamEstado
* \return int
*
*/
int printPassengers(ePassenger* pListaPasajeros, int tam, eEstado pListaEstado[], int tamEstado);

/**
* \brief modifica un pasajero
*
* \param unPasajero
* \param tam
* \param pListaEstado
* \param tamEstado
* \return int
*
*/
int modificarPasajeros(ePassenger* pListaPasajeros, int tam, eEstado pListaEstado[], int tamEstado);

/**
* \brief busca un pasajero por id
*
* \param unPasajero
* \param tam
* \param pListaEstado
* \param tamEstado
* \return int
*
*/
int buscarPasajeroPorId(ePassenger* pListaPasajeros, int tam,int id);

/**
* \brief muestra todos los precios de los pasajeros
*
* \param unPasajero
* \param tam
* \param id
* \return int
*
*/
int mostrarPrecios(ePassenger* pListaPasajeros, int tam);

/**
* \brief muestra el total y el promedio de los precios de los pasajeros
*
* \param unPasajero
* \param tam
* \return int
*
*/
int totalYPromedioPrecios(ePassenger* pListaPasajeros, int tam);

/**
* \brief muestra los pasajeros que superan el precio promedio
*
* \param unPasajero
* \param tam
* \return int
*
*/
int pasajerosSobrePromedio(ePassenger* pListaPasajeros, int tam);

/**
*\brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
* \param pListaPasajeros*
* \param len tam
* \param order int [1] indicate UP - [0] indicate DOWN
* \param pListaEstado
* \param tamEstado
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int sortPassengers(ePassenger pListaPasajeros[], int tam, int orden, eEstado pListaEstado[], int tamEstado);

/**
* \brief muestra si se ingresaron letras o numeros
*
* \param letras[]
* \return int
*
*/
int soloLetras(char letras[]);

/**
* \brief muestra un harcodeo de tipos de pasajeros
*
* \param idTipo
* \param nombre[]
*/
void mostrarTipos(int idTipo, char nombre[15]);

/**
* \brief muestra el harcodeo de 6 pasajeros
*
* \param unPasajero
* \param tam
* \param cant
* \param id
* \return int
*
*/
int HarcodeoPasajeros(ePassenger* pListaPasajeros, int tam , int cant, int id);

/**
* \brief muestra si superan el precio promedio
*
* \param unPasajero
* \param tam
* \param promedio
*/
void superanPrecioPromedio (ePassenger* pListaPasajeros, int tam, float promedio);
