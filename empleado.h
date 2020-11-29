#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "colormenues.h"
int ValidarDni(int d){
Empleado e;
int pos=0;

while(e.leerdedisco(pos++)){

    if(e.getDNI()==d){
        return -1;
    }


}
return 0;

}
int empleadoRepetido(int em){
Empleado e;
int pos=0;

while(e.leerdedisco(pos++)){
    if(e.getIDEmpleado()==em){

        return -1;
    }


}

return 0;
}

///ALFANUMERICO
int BuscarIDempleado()
{
    Empleado a;
    int mayorid = 0;

    FILE* p = fopen(EMPLEADO_CHAR,"rb");
    if(p==NULL)
    {
        return mayorid+1;
    }

    while(fread(&a,sizeof(Empleado),1,p)==1)
    {

        if(a.getIDEmpleado()>mayorid)
        {

            mayorid = a.getIDEmpleado();
        }

    }


    return mayorid +1;
}

bool Empleado::nuevoEmpleado()
{
    textcolor(cNEGRO,cVERDE);

    ///ID CLIENTE EN ALFANUMERICO
        idEmpleado = BuscarIDempleado();
    if(empleadoRepetido(idEmpleado)==-1){cout<<"ID EMPLEADO REPETIDO, ";return false;}
    cout<<"SUELDO: ";
    cin>>sueldo;
    cout<<"INGRESE NOMBRE: ";
    cin.ignore();
    cin.getline(nombre,40);
    if (strlen(nombre)==0)
    {
        return false;
    }
    cout<<"INGRESE APELLIDO: ";
    cin.getline(apellido,40);
    if (strlen(apellido)==0)
    {
        return false;
    }
    cout<<"INGRESE DNI: ";
    cin>>dni;
    if(ValidarDni(dni)==-1){cout<<"DNI REPETIDO! ";return false;}
    cout<<"INGRESE NUMERO DE TELEFONO: ";
    cin>>nroTelefono;
    cout<<"INGRESE DOMICILIO: ";
    cin.ignore();
    cin.getline(domicilio,50);
    if (strlen(domicilio)==0)
    {
        return false;
    }
    cout<<"FECHA DE NACIMIENTO";
    cout<<endl;
    while (nacimiento.cargarFecha()==0)
    {
        system("cls");
        cout<<"FECHA INVALIDA."<<endl;
        cout<<"FECHA DE NACIMIENTO"<<endl;
    }
    cout<<"INGRESE EMAIL: ";
    cin.ignore();
    cin.getline(email,50);
    if(strlen(email)==0)
    {
        return false;
    }
    cout<<"INGRESE GENERO: ";
    cin.getline(genero,10);
    if(strlen(genero)==0)
    {
        return false;
    }
    activo=1;
    return true;
}

void Empleado::MostrarEmpleado()
{
    textcolor(cNEGRO,cVERDE);
     if(activo==1)
    {
        cout<<"ID EMPLEADO: ";
        cout<<idEmpleado<<endl;
        cout<<"SUELDO: ";
        cout<<sueldo<<endl;

        cout<<"APELLIDO: ";
        cout<<apellido<<endl;
        cout<<"NOMBRE: ";
        cout<<nombre<<endl;
        cout<<"DNI: ";
        cout<<dni<<endl;
        cout<<"NUMERO DE TELEFONO: ";
        cout<<nroTelefono<<endl;
        cout<<"DOMICILIO: ";
        cout<<domicilio<<endl;
        cout<<"FECHA DE NACIMIENTO"<<endl;
        cout<<nacimiento.getdia()<<"/"<<nacimiento.getmes()<<"/"<<nacimiento.getanio()<<endl;
        cout<<"EMAIL: ";
        cout<<email<<endl;
        cout<<"GENERO: ";
        cout<<genero<<endl;
        system("pause");

    }
    else
    {
        cout<< "ESTE EMPLEADO SE ENCUENTRA DADO DE BAJA ACTUALMENTE : "<<endl;
    }
}
///GRABAR
bool Empleado::grabarEmpleado()
{
    FILE *p;
    p=fopen("Empleados.dat", "ab");
    if(p==NULL)
        return false;
    bool escribio=fwrite(this, sizeof (Empleado), 1, p);
    fclose(p);
    return escribio;
}
bool Empleado::altaEmpleado()
{
    textcolor(cNEGRO,cVERDE);
    Empleado e;

   if(e.nuevoEmpleado()==false)
    return false;

///VERIFICACION...
    if (e.dni>0)
    {

    }
    else
    {
        cout << "NO SE PUDO AGREGAR al empleado VERIFICACION DNI INCORRECTO"<<endl;
        system("pause");
        system("cls");
        return false;
    }


    if(e.grabarEmpleado()==true)
    {
        cout<<"EMPLEADO AGREGADO"<<endl;

    }
    else
    {
        cout<<"NO SE PUDO AGREGAR EMPLEADO"<<endl;

    }
    system("pause");
    system("cls");


}

///LISTAR

bool Empleado::leerdedisco(int pos)
{
    FILE *p;
    p=fopen("Empleados.dat","rb");
    if(p==NULL)
        return false;
    fseek(p,sizeof *this *pos,0);
    bool leyo=fread(this,sizeof *this,1,p);
    fclose(p);
    return leyo;


}
void Empleado::listarEmpleado()
{
    textcolor(cNEGRO,cVERDE);
    FILE *p;
    Empleado e;
    int pos=0;
    p=fopen("Empleados.dat","rb");
    if(p==NULL)
        exit(1);
    while(e.leerdedisco(pos++))
    {
        e.MostrarEmpleado();
        cout<<endl;
        cout<<"-------------------"<<endl;
    }
    fclose(p);
}

///ELIMINAR

void Empleado::eliminarEmpleado()
{
    textcolor(cNEGRO,cVERDE);
    FILE *p;
    char opcion;
    int pos=0;
    int d;
    Empleado e;
    p=fopen("Empleados.dat","rb+");
    if(p==NULL)
        exit(1);
    cout<<" INGRESE DNI DE PERSONA A ELIMINAR: ";
    cin>>d;
    cout<<endl;
    while(e.leerdedisco(pos++))
    {
        if(d==e.dni)
        {
            cout<< "¿DESEA ELIMINAR A ESTA PERSONA?: "<<endl;
            e.MostrarEmpleado();
            cout<<endl;
            cout<<"..........................."<<endl;
            cout<<" INGRESE S ( SI ) O N (NO):  " ;
            cin>> opcion;
            if (opcion=='s'||opcion=='S')
            {
                e.activo=0;

                cout<<" ELIMINADO CORRECTAMENTE "<<endl;
                fseek(p,ftell(p)-sizeof e,0);
                fwrite(this, sizeof (Empleado), 1, p);
                fclose(p);
            }
            fclose(p);
            return;
        }

    }
    cout<< "NO SE ENCONTRO A LA PERSONA ";
    fclose(p);


}
///BUSQUEDAS
void Empleado::buscarporCodigoEmpleado()
{
    textcolor(cNEGRO,cVERDE);
    Empleado e;
    int d;
    int pos=0;
    cout<<" INGRESE DNI DEL EMPLEADO QUE QUIERE BUSCAR: ";
    cin>>d;
    cout<<endl;

    while(e.leerdedisco(pos++))
    {
        if(d==e.dni)
        {
            e.MostrarEmpleado();

        }
        else
        {
            cout<<"este DNI no es de ninguna persona actualemte "<<endl;

        }
    }

}
///LISTADO

void ListarPorApellido(){
Empleado e;
char apellido[40];
int pos=0;
cout<<"INGRESE APELLIDO: ";
cin>>apellido;
system("cls");
while(e.leerdedisco(pos++)){
    if (strcmp(e.getApellidoEmpleado(),apellido)==0){
        e.listarEmpleado();
    }
}
}
void listarporDNI(){
Empleado e;
int dni;
int pos=0;
cout<<"INGRESE DNI: ";
cin>>dni;
system("cls");
while(e.leerdedisco(pos++)){
        if (e.getDNI()==dni){
                e.listarEmpleado();
    }
}


}


#endif // EMPLEADO_H_INCLUDED
