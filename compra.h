#ifndef COMPRA_H_INCLUDED
#define COMPRA_H_INCLUDED
#include "colormenues.h"

int Compra::ValidacionCodproducto(const char *codigo){
FILE *P=fopen (PRODUCTOS_CHAR,"rb");
if(P==NULL)
    {
        return 1;
        exit(1);
    }
Producto p;


if(p.validarproducto(codigo)==0){

fclose(P);

    return 0;
}
fclose(P);

return 1;
}

bool Compra::stockup(const char *codigo,int stock){
FILE *P =fopen(PRODUCTOS_CHAR,"rb+");
if(P==NULL)
{
    return false;
    exit(1);
}
Producto p;
int pos=0;
while (p.leerdedisco(pos))
    {

        if (strcmp(p.getCodigoProducto(),codigo)==0)
        {


            p.setStock(stock+p.getStock());
            p.modificar(pos);

            fclose(P);
            return true;

        }
        pos++;
    }
    return false;
}


float Compra::buscarprecio(const char *codigo){
FILE *P=fopen(PRODUCTOS_CHAR,"rb");
if(P==NULL) return 0;

Producto p;
int pos=0;
float precio=0;


while(p.leerdedisco(pos)){

    if(strcmp(p.getCodigoProducto(),codigo)==0){

        precio=p.getPrecio();
        fclose(P);
        return precio;

    }
pos++;
}
return 0;

}

int BuscarIDcompra()
{
    Compra a;
    int mayorid = 0;

    FILE* p = fopen(COMPRA_CHAR,"rb");
    if(p==NULL)
    {
        return mayorid+1;
    }

    while(fread(&a,sizeof(Compra),1,p)==1)
    {

        if(a.getNrocompra()>mayorid)
        {

            mayorid = a.getNrocompra();
        }

    }


    return mayorid +1;
}

bool Compra::CargarCompra()
{
    Producto p;
    char sino;
    ///nrocompra alfanumerico
    Nrocompra=BuscarIDcompra();
    cout<<"CODIGO DE PRODUCTO: ";
    cin.ignore();
    cin.getline(codProducto,10);
    if (strlen(codProducto)==0)
    {
        return false;
    }
    ///----------------------------------validacion de codigo
    if(ValidacionCodproducto(codProducto)==1){
        cout<<"El codigo de producto no existe, queres ingresar ahora este nuevo producto?"<<endl;
        cout<<"(s SI n NO)"<<endl;
        cin>>sino;
        if(sino=='s' || sino=='S'){

         p.altaproducto(codProducto);

        }
        else{ return false;}
        system("cls");
        cout<<"Listo!"<<endl;
        cout<<"carga los datos de la compra:"<<endl;
    }
    ///----------------------------------///

    setcodProductoCompra(codProducto);
    cout<<"NUMERO DE PROVEEDOR: ";
    cin>>numProveedor;
    setnumProveedorCompra(numProveedor);
    cout<<"CANTIDAD INGRESADA: ";
    cin>>cantIngresada;
    ///-----------------------------------cantidad x precio
    float precio=buscarprecio(codProducto);
    ///-----------------------------------///

    ///----------------------------------V de numeros negativos o 0
    setcantIngresadaCompra(cantIngresada);
    while (cantIngresada<=0)
    {
        system("cls");
        cout<<"NO SE PERMITE QUE SE INGRESE CANTIDAD NEGATIVO O CERO"<<endl;
        cout<<"CANTIDAD INGRESADA: ";
        cin>>cantIngresada;
        setcantIngresadaCompra(cantIngresada);
    }
    ///----------------------------------////
    ///----------------------------------aumento de stock de productos
    stockup(codProducto,cantIngresada);

    ///----------------------------------////

    cout<<"FECHA DE COMPRA"<<endl;
    while (fechaDeCompra.cargarFecha()==0)
    {
        system("cls");
        cout<<"FECHA INVALIDA."<<endl;
        cout<<"FECHA DE COMPRA"<<endl;
    }
    cout<<"FECHA DE VENCIMIENTO DE PAGO"<<endl;
    while (fechaVencimientoPago.cargarFecha()==0)
    {
        system("cls");
        cout<<"FECHA INVALIDA."<<endl;
        cout<<"FECHA DE VENCIMIENTO DE PAGO"<<endl;
    }
    importe=cantIngresada*precio;
    setImporteCompra(importe);
    while (importe<=0)
    {
        system("cls");
        cout<<"NO SE PERMITE QUE SE INGRESE IMPORTE NEGATIVO O CERO"<<endl;
        cout<<"IMPORTE: ";
        cin>>importe;
        setImporteCompra(importe);
    }
    cout<<"FORMA DE PAGO: ";
    cin>>formaPago;
    setFormaPagoCompra(formaPago);
    while (formaPago<=0||formaPago>=5)
    {
        system("cls");
        cout<<"NO SE PERMITE INGRESAR FORMA DE PAGO NEGATIVO O CREO Y QUE NO SEAN MAYORES A 5 O IGUALES"<<endl;
        cout<<"FORMA DE PAGO: ";
        cin>>formaPago;
        setFormaPagoCompra(formaPago);
    }
    setActivoCompra(true);
    return true;
}
void Compra::MostrarCompra()
{
    if (getActivoComprar()==true)
    {
        cout<<"NRO DE COMPRA: "<<getNrocompra()<<endl;
        cout<<"CODIGO DE PRODUCTO: "<<getcodProductoCompra()<<endl;
        cout<<"NUMERO DE PROVEEDOR: "<<getnumProveedor()<<endl;
        cout<<"CANTIDAD INGRESADA: "<<getCantidadCompra()<<endl;
        cout<<"FECHA DE COMPRA"<<endl;
        cout<<fechaDeCompra.getdia()<<" / "<<fechaDeCompra.getmes()<<" / "<<fechaDeCompra.getanio()<<endl;
        cout<<"FECHA DE VENCIMIENTO DE PAGO"<<endl;
        cout<<fechaVencimientoPago.getdia()<<" / "<<fechaVencimientoPago.getmes()<<" / "<<fechaVencimientoPago.getanio()<<endl;
        cout<<"IMPORTE: "<<getImporteCompra()<<endl;
        cout<<"FORMA DE PAGO: "<<getFormapagoCompra()<<endl;
        cout<<"--------------------------------"<<endl<<endl;
    }
}
bool Compra::grabarCompra()
{
    FILE *archivo_compra=fopen(COMPRA_CHAR,"ab");
    if(archivo_compra==NULL)
    {
        return false;
        exit(1);
    }
    bool escribio=fwrite(this, sizeof (Compra), 1, archivo_compra);
    fclose(archivo_compra);
    return escribio;
}
bool Compra::altaCompra()
{
    Compra a;
    if(a.CargarCompra()==true)
    {
        if(a.grabarCompra()==true)
        {
            cout <<"COMPRA AGREGADO."<<endl;
        }
    }
    else
    {
        cout<<"NO SE PUDO AGREGAR COMPRA."<<endl;
    }
}
bool Compra::leerDiscoCompra(int posicion)
{
    FILE *archivo_compra=fopen(COMPRA_CHAR,"rb");
    if(archivo_compra==NULL)
    {
        return false;
        exit(1);
    }
    fseek(archivo_compra,sizeof *this *posicion,0);
    bool leyo=fread(this,sizeof *this,1,archivo_compra);
    fclose(archivo_compra);
    return leyo;
}
bool Compra::listarCompra()
{
    Compra a;
    int pos=0;
    while(a.leerDiscoCompra(pos++))
    {
        a.MostrarCompra();
        cout<<endl;
    }
    return true;
}
void Compra::bajaCompra()
{
    char opcion;
    int pos=0;
    int aux;
    Compra a;
    cout<<" INGRESE EL NUMERO DE COMPRA A ELIMINAR: ";
    cin>>aux;
    cout<<endl;
    while(a.leerDiscoCompra(pos++))
    {
        if(aux==a.Nrocompra)
        {
            cout<< "¿DESEA ELIMINAR A ESTE CODIGO DE PRODUCTO?: "<<endl;
            a.MostrarCompra();
            cout<<endl;
            cout<<"..........................."<<endl;
            cout<<" INGRESE S ( SI ) O N (NO):  " ;
            cin>> opcion;
            if (opcion=='s'||opcion=='S')
            {
                a.activo=false;
                cout<<" ELIMINADO CORRECTAMENTE "<<endl;
                a.modificar(pos-1);
            }
            return;
        }
    }
    cout<< "NO SE ENCONTRO AL CODIGO DE PRODUCTO";
}
bool Compra::modificar(int posicion)
{
    FILE *archivo_compra=fopen(COMPRA_CHAR,"rb+");
    if(archivo_compra==NULL)
    {
        return false;
    }
    fseek(archivo_compra,sizeof*this*posicion,0);
    bool escribio=fwrite(this, sizeof*this, 1, archivo_compra);
    fclose(archivo_compra);
}
int Compra::buscarCompra(int nrocompraaux)
{
    int posicion=0;
    Compra a;
    while(a.leerDiscoCompra(posicion))
    {

        if (nrocompraaux==a.Nrocompra)
        {
            return posicion;
        }
    posicion++;
    }
    return -1;
}
bool Compra::modificarCompra()
{
    int nrocompraaux;
    int numProveedorAux,cantIngresadaAux;
    int diaC,mesC,anioC,diaV,mesV,anioV;
    float importeAux;
    int formaPagoAux;
    int posicion=0;
    char opcion;
    Compra a;
    cout<<"INGRESE EL NRO DE COMPRA QUE DESEA MODIFICAR: ";
    cin>>nrocompraaux;
    posicion=buscarCompra(nrocompraaux);
    if(posicion!=-1)
    {
        cout<<"ARCHIVO DE COMPRA ENCONTRADO"<<endl;
        a.leerDiscoCompra(posicion);
        a.MostrarCompra();
        cout<<"ESTAS SEGURO QUE QUIERE MODIFICAR EL CODIGO DE PRODUCTO DE LA COMPRA?."<<endl;
        cout<<"INGRESE S ( SI ) O N (NO):  ";
        cin>>opcion;
        if (opcion=='s'||opcion=='S')
        {
            cout<<"INGRESE EL NUEVO NUMERO DE PROVEEDOR: ";
            cin>>numProveedorAux;
            a.setnumProveedorCompra(numProveedorAux);
            cout<<"INGRESE EL NUEVO CANTIDAD INGRESADA: ";
            cin>>cantIngresadaAux;
            a.setcantIngresadaCompra(cantIngresadaAux);
            cout<<"INGRESE EL NUEVO FECHA DE COMPRA: ";
            cin>>diaC;
            cin>>mesC;
            cin>>anioC;
            a.fechaDeCompra.setdia(diaC);
            a.fechaDeCompra.setmes(mesC);
            a.fechaDeCompra.setanio(anioC);
            cout<<"INGRESE EL NUEVO FECHA DE VENCIMIENTO DE PAGO: ";
            cin>>diaV;
            cin>>mesV;
            cin>>anioV;
            a.fechaVencimientoPago.setdia(diaV);
            a.fechaVencimientoPago.setmes(mesV);
            a.fechaVencimientoPago.setanio(anioV);
            cout<<"INGRESE EL NUEVO IMPORTE: ";
            cin>>importeAux;
            a.setImporteCompra(importeAux);
            cout<<"INGRESE EL NUEVO FORMA DE PAGO: ";
            cin>>formaPagoAux;
            a.setFormaPagoCompra(formaPagoAux);
            a.modificar(posicion);
            cout<<"MODIFICADO CORRECTAMENTE"<<endl;
            posicion++;
        }
    }
    else
    {
        cout<<"NO EXISTE EL CODIGO DE PRODUCTO"<<endl;
    }
}
#endif // COMPRA_H_INCLUDED
