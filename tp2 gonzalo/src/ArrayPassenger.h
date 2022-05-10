#ifndef ARRAYPASSENGER_H_INCLUDED
#define ARRAYPASSENGER_H_INCLUDED

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float precio;
    char codigoDeVuelo[10];
    int tipoDePasajero; // 1)Menor 2 Adulto 3)Anciano
    int estadoDelVuelo; // 1)Activo 2)Demorado 3)Cancelado
    int isEmpty;
}ePassenger;

#endif // ARRAYPASSENGER_H_INCLUDED

int menu();

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
int addPassenger(ePassenger* pListaPasajeros, int tam, int id, char nombre[],char apellido[],float precio,int tipoPasajero, char flycode[], int estadoDelVuelo);
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
//int removePassenger(ePassenger* pListaPasajeros, int len, int id);

/**
*\brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
//int sortPassengers(ePassenger* pListaPasajeros, int len, int order);

/**
*\brief print the content of passengers array
* \param list Passenger*
* \param length int
* \return int
*/
int printPassenger(ePassenger unPasajero, int tam);

int printPassengers(ePassenger* pListaPasajeros, int tam);

int modificarPasajeros(ePassenger* pListaPasajeros, int tam);

int buscarPasajeroPorId(ePassenger* pListaPasajeros, int tam,int id);


