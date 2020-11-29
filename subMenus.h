#ifndef SUBMENUS_H_INCLUDED
#define SUBMENUS_H_INCLUDED
#include "colormenues.h"
#include "producto.h"
#include "configuracion.h"

void subMenuConfiguracion()
{
    int opcion;
    while (true)
    {
        system("cls");
        MENUCONFIGURACION();
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
            subMenuBackup();
            break;
        case 2:
            subMenuRestaurar();
            break;
        case 0:
            cout<<"VOLVIENDO AL MENU PRINCIPAL"<<endl;
            return;
            break;
        default:
            cout<<"OPCION INCORRECTA POR FAVOR VUELVA INTRODUCCIR LA OPCION CORRECTA EN PANTALLA"<<endl;
            break;
        }
        system("pause");
    }
}

void subMenuRestaurar()
{
    int opcion;
    while (true)
    {
        system("cls");
        MENUCONFIGURACIONRESTAURACION();
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
            menuRestaurar();
            break;
        case 2:
            restaurarTodos();
            break;
        case 0:
            cout<<"VOLVIENDO AL MENU PRINCIPAL"<<endl;
            return;
            break;
        default:
            cout<<"OPCION INCORRECTA POR FAVOR VUELVA INTRODUCCIR LA OPCION CORRECTA EN PANTALLA"<<endl;
            break;
        }
        system("pause");
    }
}

void subMenuBackup()
{
    int opcion;
    while (true)
    {
        system("cls");
        MENUCONFIGURACIONBACKUP();
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
            menuBackup();
            break;
        case 2:
            menuRestaurar();
            break;
        case 0:
            cout<<"VOLVIENDO AL MENU PRINCIPAL"<<endl;
            return;
            break;
        default:
            cout<<"OPCION INCORRECTA POR FAVOR VUELVA INTRODUCCIR LA OPCION CORRECTA EN PANTALLA"<<endl;
            break;
        }
        system("pause");
    }
}

void subMenuProducto()
{
    int opcion;
    Producto p;
    while (true)
    {
        system("cls");
        MENUCOLORPRODUCTO();
        cout<<"ingrese una opcion"<<endl;
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
            p.eliminarproducto();
            break;
        case 2:
            p.modificarproducto();
            break;
        case 3:
            p.listarproducto();
            break;
        case 4:
            listarDeUnDeterminadoProducto();
            break;
        case 0:
            cout<<"VOLVIENDO AL MENU PRINCIPAL"<<endl;
            return;
            break;
        default:
            cout<<"OPCION INCORRECTA POR FAVOR VUELVA INTRODUCCIR LA OPCION CORRECTA EN PANTALLA"<<endl;
            break;
        }
        system("pause");
    }
}
void subMenuProveedor()
{
    Proveedor reg;
    int opcion;
    while (true)
    {
        system("cls");
        MENUCOLORPROVEEDOR();
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
            reg.altaProveedor();
            break;
        case 2:
            reg.bajaProveedor();
            break;
        case 3:
            reg.modificarProveedorNuevo();
            break;
        case 4:
            reg.listarProveedor();
            break;
        case 5:
            listarDeUnDeterminadoProveedor();
            break;
        case 0:
            cout<<"VOLVIENDO AL MENU PRINCIPAL"<<endl;
            return;
            break;
        default:
            cout<<"OPCION INCORRECTA POR FAVOR VUELVA INTRODUCCIR LA OPCION CORRECTA EN PANTALLA"<<endl;
            break;
        }
        system("pause");
    }
}

void subMenuCliente()
{
    Cliente aux;
    int opcion;
    while (true)
    {
        system("cls");
        MENUCOLORCLIENTE();
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
            aux.listarCliente();
            break;
        case 2:
            aux.listarPorIDCliente();
            break;
        case 0:
            cout<<"VOLVIENDO AL MENU PRINCIPAL"<<endl;
            return;
            break;
        default:
            cout<<"OPCION INCORRECTA POR FAVOR VUELVA INTRODUCCIR LA OPCION CORRECTA EN PANTALLA"<<endl;
            break;
        }
        system("pause");
    }
}

void subMenuVenta()
{
    int opcion;
    Venta v;
    while (true)
    {
        system("cls");
        MENUCOLORVENTA();
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
            v.altaventa();
            break;
        case 2:
            v.bajaVenta();
            break;
        case 3:
            v.modificarVentaNuevo();
            break;
        case 4:
            v.listarventa();
            break;
        case 5:
            UNAVENTA();
            break;
        case 0:
            cout<<"VOLVIENDO AL MENU PRINCIPAL"<<endl;
            return;
            break;
        default:
            cout<<"OPCION INCORRECTA POR FAVOR VUELVA INTRODUCCIR LA OPCION CORRECTA EN PANTALLA"<<endl;
            break;
        }
        system("pause");
    }
}
void subMenuEmpleado()
{
    Empleado e;
    int opcion;
    while (true)
    {
        system("cls");
        MENUCOLOREMPLEADO();
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
            e.altaEmpleado();
            break;
        case 2:
            e.eliminarEmpleado();
            break;
        case 3:
            e.listarEmpleado();
            break;
        case 0:
            cout<<"VOLVIENDO AL MENU PRINCIPAL"<<endl;
            return;
            break;
        default:
            cout<<"OPCION INCORRECTA POR FAVOR VUELVA INTRODUCCIR LA OPCION CORRECTA EN PANTALLA"<<endl;
            break;
        }
        system("pause");
    }
}

void subMenuCompra()
{
    Compra c;
    int opcion;
    while (true)

    {
        system("cls");
        MENUCOLORCOMPRA();
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
            c.altaCompra();
            break;
        case 2:
            c.bajaCompra();
            break;
        case 3:
            c.modificarCompra();
            break;
        case 4:
            c.listarCompra();
            break;
        case 0:
            cout<<"VOLVIENDO AL MENU PRINCIPAL"<<endl;
            return;
            break;
        default:
            cout<<"OPCION INCORRECTA POR FAVOR VUELVA INTRODUCCIR LA OPCION CORRECTA EN PANTALLA"<<endl;
            break;
        }
        system("pause");
    }
}

void subMenuInforme()
{
    int opcion;
    while (true)

    {
        system("cls");
        MENUCOLORINFORME();
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
            Recaudacion_2020();
            break;
        case 2:
            VentasPorEmpleado();
            break;
        case 3:
            buscarProducto();
            break;
        case 4:

            break;
        case 0:
            cout<<"VOLVIENDO AL MENU PRINCIPAL"<<endl;
            return;
            break;
        default:
            cout<<"OPCION INCORRECTA POR FAVOR VUELVA INTRODUCCIR LA OPCION CORRECTA EN PANTALLA"<<endl;
            break;
        }
        system("pause");
    }
}
#endif // SUBMENUS_H_INCLUDED
