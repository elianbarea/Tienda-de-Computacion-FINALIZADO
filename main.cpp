#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <windows.h>
#include <clocale>
using namespace std;
const char *PROVEEDOR_CHAR="proveedor.dat";
const char *CLIENTE_CHAR="cliente.dat";
const char *VENTAS_CHAR="ventas.dat";
const char *COMPRA_CHAR="compras.dat";
const char *EMPLEADO_CHAR="Empleados.dat";
const char *PRODUCTOS_CHAR="productos.dat";
const char *PRODUCTOS_CHAR_BACKUP="productos.bkp";
const char *PROVEEDOR_CHAR_BACKUP="proveedor.bkp";
const char *CLIENTE_CHAR_BACKUP="cliente.bkp";
const char *VENTAS_CHAR_BACKUP="ventas.bkp";
const char *COMPRA_CHAR_BACKUP="compras.bkp";
const char *EMPLEADO_CHAR_BACKUP="empleado.bkp";
#include "tipos.h"
#include "producto.h"
#include "proveedor.h"
#include "cliente.h"
#include "venta.h"
#include "empleado.h"
#include "compra.h"
#include "informe.h"
#include "configuracion.h"
#include "subMenus.h"
#include "colormenues.h"
int main()
{
    system("color 24");
    setlocale(LC_CTYPE,"Spanish");
    int opcion;
    while (true)
    {
        system("cls");
        MENUCOLORMAIN();
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
            subMenuProducto();
            break;
        case 2:
            subMenuProveedor();
            break;
        case 3:
            subMenuCliente();
            break;
        case 4:
            subMenuVenta();
            break;
        case 5:
            subMenuEmpleado();
            break;
        case 6:
            subMenuCompra();
            break;
        case 7:
            subMenuInforme();
            break;
        case 8:
            subMenuConfiguracion();
            break;
        case 0:
            cout<<"GRACIAS POR USAR EL PROGRAMA QUE TENGA UN BUEN DIA"<<endl;
            return 0;
            break;
        default:
            cout<<"OPCION INCORRECTA POR FAVOR VUELVA INTRODUCCIR LA OPCION CORRECTA EN PANTALLA"<<endl;
            break;
        }
        system("pause");
    }
}
