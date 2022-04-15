/*
 ============================================================================
 Name        : GonzaloPreckel_tp1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
	setbuf(stdout, NULL);
    float km;
    float kmForzado = 7090;

    float precioVueloAerolineasForzado = 162965;
    float precioVueloLatamForzado = 159339;

    float precioVueloAerolineas;
    float precioVueloLatam;

    float precioFinalCreditoA;
    float precioFinalDebitoA;
    float precioFinalBtcA;

    float precioFinalCreditoL;
    float precioFinalDebitoL;
    float precioFinalBtcL;

    float precioFinalCreditoAForzado;
    float precioFinalDebitoAForzado;
    float precioFinalBtcAForzado;
    float precioKmAForzado;

    float precioFinalCreditoLForzado;
    float precioFinalDebitoLForzado;
    float precioFinalBtcLForzado;
    float precioKmLForzado;

    float precioUnitarioAerolinea;
    float precioUnitarioLatam;
    float precioDiferencia;
    float precioDiferenciaForzada;

    int flagUno = 1;
    int flagDos = 1;
    int flagTres = 1;
    int flagCuatro = 1;


    char seguir = 's';
  do
  {
    switch(menu())
    {
        case 1:
            printf("\nIngrese los kilometros: ");
            scanf("%f", &km);
            printf("Kilometros %f\n", km);
            flagUno = 0;
        break;
        case 2:
            if(flagUno == 1)
            {
                printf("\nPrimero debe seleccionar la opcion 1\n");
            }
            else
            {
                printf("\nIngrese el precio de Aerolinea: ");
                scanf("%f", &precioVueloAerolineas);
                printf("\nIngrese el precio de Latam: ");
                scanf("%f", &precioVueloLatam);
                flagDos = 0;
            }
        break;
        case 3:
             if(flagDos == 1)
            {
                    printf("\nPrimero debe seleccionar la opcion 2\n");
            }
            else
            {
                precioFinalCreditoA = tarjetaCredito(precioVueloAerolineas);
                precioFinalDebitoA = tarjetaDebito(precioVueloAerolineas);
                precioFinalBtcA = bitcoin(precioVueloAerolineas);

                precioFinalCreditoL = tarjetaCredito(precioVueloLatam);
                precioFinalDebitoL = tarjetaDebito(precioVueloLatam);
                precioFinalBtcL = bitcoin(precioVueloLatam);
                precioUnitarioAerolinea = precioUnitario (km, precioVueloAerolineas);
                precioUnitarioLatam = precioUnitario(km,precioVueloLatam);
                precioDiferencia = diferenciaDePrecios(precioVueloLatam,precioVueloAerolineas);

                flagTres = 0;
                printf("\nYa se realizaron las operaciones\n");
            }

        break;
        case 4:
        if(flagTres == 1)
            {
                printf("\nPrimero debe seleccionar la opcion 3\n");
            }
            else
            {
            	printf("los kiloemetros son: %.2f", km);

                printf("\nEl precio de Aerolinea es: %f\n", precioVueloAerolineas);
                printf("\nEl precio final con tarjeta de credito para Aerolinea es: %f", precioFinalCreditoA);
                printf("\nEl precio final con tarjeta de debito para Aerolinea es: %f", precioFinalDebitoA);
                printf("\nEl precio final con bitcoin para Aerolinea es: %f\n", precioFinalBtcA);
                printf("\nEl precio unitario de Latam es: %f\n", precioUnitarioAerolinea);

                printf("\nEl precio de Latam es: %f\n", precioVueloLatam);
                printf("\nEl precio final con tarjeta de credito para Latam es: %f", precioFinalCreditoL);
                printf("\nEl precio final con tarjeta de debito para Latam es: %f", precioFinalDebitoL);
                printf("\nEl precio final con bitcoin para Latam es: %f\n", precioFinalBtcL);
                printf("\nEl precio unitario de Latam es: %f\n", precioUnitarioLatam);

                printf("\nLa diferencia de precios es de: %f\n",precioDiferencia);



                flagCuatro = 0;

            }

        break;
        case 5:
            if(flagUno == 0 || flagDos == 0 || flagTres == 0 || flagCuatro == 0)
            {
                printf("\nPara forzar los datos no debe haber presionado ninguna otra opcion\n");
            }
            else
            {
                precioFinalCreditoAForzado = tarjetaCredito(precioVueloAerolineasForzado);
                precioFinalDebitoAForzado = tarjetaDebito(precioVueloAerolineasForzado);
                precioFinalBtcAForzado = bitcoin(precioVueloAerolineasForzado);
                precioKmAForzado = precioUnitario(kmForzado, precioVueloAerolineasForzado);
                precioDiferenciaForzada = diferenciaDePrecios(precioVueloLatamForzado,precioVueloAerolineasForzado);

                precioFinalCreditoLForzado = tarjetaCredito(precioVueloLatamForzado);
                precioFinalDebitoLForzado = tarjetaDebito(precioVueloLatamForzado);
                precioFinalBtcLForzado = bitcoin(precioVueloLatamForzado);
                precioKmLForzado = precioUnitario(kmForzado, precioVueloLatamForzado);

            	printf("los kiloemetros son: %.2f\n", kmForzado);
                printf("\nEl precio de Latam es: %f", precioVueloAerolineasForzado);

                printf("\nEl precio final con tarjeta de credito para Aerolinea es: %f", precioFinalCreditoAForzado);
                printf("\nEl precio final con tarjeta de debito para Aerolinea es: %f", precioFinalDebitoAForzado);
                printf("\nEl precio final con bitcoin para Aerolinea es: %f\n", precioFinalBtcAForzado);
                printf("\nEl precio unitario de Aerolinea es: %f\n", precioKmAForzado);

                printf("\nEl precio de Latam es: %f", precioVueloLatamForzado);
                printf("\nEl precio final con tarjeta de credito para Latam es: %f", precioFinalCreditoLForzado);
                printf("\nEl precio final con tarjeta de debito para Latam es: %f", precioFinalDebitoLForzado);
                printf("\nEl precio final con bitcoin para Latam es: %f", precioFinalBtcLForzado);
                printf("\nEl precio unitario de Aerolinea es: %f\n", precioKmLForzado);

                printf("\nLa diferencia de precios es de: %f\n",precioDiferenciaForzada);

            }

        break;
        case 6:
        printf("\n¿Desea seguir?\n");
        fflush(stdin);
        scanf("%c", &seguir);
        break;

        default:
        printf("\nLa opcion que eligio no existe\n");
        break;
    }
    system("pause");

  }while(seguir == 's');



    return 0;
}
