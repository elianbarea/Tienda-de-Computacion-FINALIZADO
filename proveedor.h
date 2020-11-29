#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED
#include "colormenues.h"

void listarDeUnDeterminadoProveedor();

/// LISTAR UN DETERMINADO PROVEEDOR
void listarDeUnDeterminadoProveedor()
{
    Proveedor obj;
    int aux;
    int pos=0;
    cout<<"INGRESE UN CODIGO DE PRODUTO: ";
    cin>>aux;
    cout<<endl;
    while (obj.leerDiscoProveedor(pos++))
    {
        if (obj.getNumeroProveedor()==aux)
        {
            obj.MostrarProveedor();
            cout<<endl;
        }
    }
}

///VALIDACION NUMERO DE PROOVEDOR REPETIDO
int RetornoNumeroProveedor(int id){
Proveedor reg;
int pos=0;

while(reg.leerDiscoProveedor(pos++)){

    if(reg.getNumeroProveedor()==id){
        return -1;
    }

}
return 0;

}

bool Proveedor::CargarProveedor()
{
    textcolor(cNEGRO,cVERDE);
    cout<<"NÚMERO DE PROVEEDOR: ";
    cin>>numeroProveedor;

    ///VALIDACION NUMERO DE PROOVEDOR REPETIDO

    if(RetornoNumeroProveedor(numeroProveedor)==-1){cout<<"NUMERO DE PROVEEDOR REPETIDO, ";return false;}

    cout<<"NOMBRE: ";
    cin.ignore();
    cin.getline(nombre,40);
    if (strlen(nombre)==0)
    {
        return false;
    }
    cout<<"APELLIDO: ";
    cin.getline(apellido,40);
    if (strlen(apellido)==0)
    {
        return false;
    }
    activo=1;
    return true;
}
void Proveedor::MostrarProveedor()
{
    textcolor(cNEGRO,cVERDE);
    if (activo==1)
    {
        cout<<"NÚMERO DE PROVEEDOR: ";
        cout<<numeroProveedor<<endl;
        cout<<"NOMBRE: ";
        cout<<nombre<<endl;
        cout<<"APELLIDO: ";
        cout<<apellido<<endl;
    }
}

bool Proveedor::grabarProveedor()
{
    FILE *archivo_proveedor=fopen(PROVEEDOR_CHAR, "ab");
    if(archivo_proveedor==NULL)
    {
        return false;
    }
    bool escribio=fwrite(this, sizeof (Proveedor), 1, archivo_proveedor);
    fclose(archivo_proveedor);
    return escribio;
}
bool Proveedor::altaProveedor()
{
    textcolor(cNEGRO,cVERDE);
    Proveedor a;


    if(a.CargarProveedor()==true)
    {
        if(a.grabarProveedor()==true){
            cout <<"PROVEEDOR AGREGADO"<<endl;
        }
    }

    else
    {
        cout<<"NO SE PUDO AGREGAR PROVEEDOR"<<endl;
    }
}
bool Proveedor::leerDiscoProveedor(int posicion)
{
    FILE *archivo_proveedor=fopen(PROVEEDOR_CHAR,"rb");
    if(archivo_proveedor==NULL)
    {
        return false;
    }
    fseek(archivo_proveedor,sizeof *this *posicion,0);
    bool leyo=fread(this,sizeof *this,1,archivo_proveedor);
    fclose(archivo_proveedor);
    return leyo;
}
void Proveedor::listarProveedor()
{
    textcolor(cNEGRO,cVERDE);
    FILE *archivo_proveedor=fopen(PROVEEDOR_CHAR,"rb");
    Proveedor a;
    int pos=0;
    if(archivo_proveedor==NULL)
    {
        exit(1);
    }
    while(a.leerDiscoProveedor(pos++))
    {
        a.MostrarProveedor();
        cout<<endl;
        cout<<"-------------------"<<endl;
    }
    fclose(archivo_proveedor);
}
void Proveedor::bajaProveedor()
{
    textcolor(cNEGRO,cVERDE);
    FILE *archivo_proveedor=fopen(PROVEEDOR_CHAR,"rb+");
    char opcion;
    int pos=0;
    int aux;
    Proveedor a;
    if(archivo_proveedor==NULL)
    {
        exit(1);
    }
    cout<<" INGRESE EL NUMERO DE PROVEEDOR A ELIMINAR: ";
    cin>>aux;
    cout<<endl;
    while(a.leerDiscoProveedor(pos++))
    {
        if (aux==a.numeroProveedor)
        {
            cout<< "¿DESEA ELIMINAR A ESTE NUMERO DE PROVEEDOR?: "<<endl;
            a.MostrarProveedor();
            cout<<endl;
            cout<<"..........................."<<endl;
            cout<<" INGRESE S ( SI ) O N (NO):  " ;
            cin>> opcion;
            if (opcion=='s'||opcion=='S')
            {
                a.activo=0;
                cout<<" ELIMINADO CORRECTAMENTE "<<endl;
                fseek(archivo_proveedor,ftell(archivo_proveedor)-sizeof a,0);
                fwrite(this, sizeof (Proveedor), 1, archivo_proveedor);
                fclose(archivo_proveedor);
            }
            fclose(archivo_proveedor);
            return;
        }
    }
    cout<< "NO SE ENCONTRO AL NUMERO DE PROVEEDOR";
    fclose(archivo_proveedor);
}
void Proveedor::listarPorNumeroProveedor()
{
    textcolor(cNEGRO,cVERDE);
    Proveedor a;
    int aux;
    int pos=0;
    cout<<" INGRESE NUMERO DE PROVEEDOR QUE QUIERE BUSCAR: ";
    cin>>aux;
    cout<<endl;
    while(a.leerDiscoProveedor(pos++))
    {
        if (aux==a.numeroProveedor)
        {
            a.MostrarProveedor();
        }
        else
        {
            cout<<"este CODIGO no es de ningun producto actualmente "<<endl;
        }
    }
}
bool Proveedor::modificarProveedor(int posicion)
{
    FILE *archivo_proveedor=fopen(PROVEEDOR_CHAR,"rb+");
    if(archivo_proveedor==NULL)
    {
        return false;
    }
    fseek(archivo_proveedor,sizeof*this*posicion,0);
    bool escribio=fwrite(this, sizeof*this, 1, archivo_proveedor);
    fclose(archivo_proveedor);
}
int Proveedor::buscarProveedor(int numeroProveedorAux)
{
    int pos=0;
    Proveedor a;
    while(a.leerDiscoProveedor(pos)==1)
    {
        if (numeroProveedorAux==a.numeroProveedor)
        {
            return pos;
        }
        pos++;
    }
    return -1;
}
void Proveedor::modificarProveedorNuevo()
{
    textcolor(cNEGRO,cVERDE);
    int numeroProveedorAux;
    float npu;
    int pos;
    Proveedor a;
    cout<<"INGRESE EL NUMERO DE PROVEEDOR QUE DESEA MODIFICAR: ";
    cin>>numeroProveedorAux;
    pos=buscarProveedor(numeroProveedorAux);
    if(pos!=-1)
    {
        a.CargarProveedor();
        a.modificarProveedor(pos);
    }
    else
    {
        cout<<"NO EXISTE EL NUMERO DE PROVEEDOR"<<endl;
    }
}
#endif // PROVEEDOR_H_INCLUDED
