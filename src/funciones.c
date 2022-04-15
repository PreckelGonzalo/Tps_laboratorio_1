/*
 * funciones.c
 *
 *  Created on: 15 abr. 2022
 *      Author: usuario
 */

#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int menu()
{
    int opcion;

    printf("\n*MENU DE OPCIONES*\n");
    printf("\nSi desea ingresar los kilometros presione 1");
    printf("\nSi desea ingresar el precio de Aerolineas y de Latam presione 2");
    printf("\nSi desea hacer el calculo de los costos presione 3");
    printf("\nSi desea ver los resultados presione 4");
    printf("\nSi desea forzar la carga presione 5");
    printf("\nSi desea salir presione 6");
    printf("\n\nSeleccione una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


float tarjetaCredito(float precio)
{
    float precioFinal;
    float interes = 1.25;

    precioFinal = precio * interes;

    return precioFinal;
}

float tarjetaDebito(float precio)
{
    float precioFinal;
    float descuento = 0.10;

    precioFinal = precio - (precio * descuento);

    return precioFinal;
}


float bitcoin(float precio)
{
    float precioFinal;
    float valorBtc = 4606954.55;

    precioFinal = precio / valorBtc;

    return precioFinal;
}

float precioUnitario(float km, float precio)
{
   float precioPorKm;

    precioPorKm = precio / km;

   return precioPorKm;
}

float mostrarPrecio(float precio)
{
	float resultado;
	resultado = precio;
	return resultado;
}

float diferenciaDePrecios(float precioAerolineas, float precioLatam)
{
	return precioAerolineas - precioLatam;
}
