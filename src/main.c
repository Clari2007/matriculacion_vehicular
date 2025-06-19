// Declaración de bibliotecas y constantes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "matriculaVehicular.h"
#define MAX_USERS 100

// Se muestra al usuario el men
void mostrarMenu() {
	printf("\n\t-- MENU DE MATRICULACION VEHICULAR --\n");
	printf("1. Registrar nuevo vehículo\n");
	printf("2. Buscar vehículo por placa\n");
	printf("3. Listar todos los vehículos\n");
	printf("4. Listar los vehículos matriculados\n");
	printf("5. Generar comprobante\n");
	printf("6. Empezar proceso de matriculación\n");
	printf("7. Salir\n");
	printf("Seleccione una opción: ");
}

//Función principal
int main() {
	Vehiculo vehiculos[MAX_USERS];
	int opcion, contador = 0;
	
	do {
		mostrarMenu();
		scanf("%d", &opcion);
		while (getchar() != '\n');
		switch (opcion) {
		case 1: {
			Vehiculo v = registroVehiculo();
            vehiculos[contador++] = v;
            printf("\nVehiculo registrado exitosamente.\n");
            break;
		}
		case 2: {
			char placaBuscar[10];
			printf("Ingrese la placa a buscar:\n");
			fgets(placaBuscar, sizeof(placaBuscar), stdin);
			placaBuscar[strcspn(placaBuscar, "\n")] = '\0';
			buscarVehiculoPorPlaca(placaBuscar);
			break;
		}
		case 3:
			listarVehiculos(vehiculos, contador);
			break;
			
		case 4:
			listarVehiculosMatriculados();
			break;	
		case 5:
			generarComprobante();
			break;
		case 6:
			procesoMatriculacion(vehiculos, contador);
			break;
		case 7:
			printf("Saliendo......... Gracias!\n");
			break;
		default:
			printf("Opción no válida, por favor intente de nuevo.\n");
		}
		
	} while (opcion != 7);
	
	return 0;
}
