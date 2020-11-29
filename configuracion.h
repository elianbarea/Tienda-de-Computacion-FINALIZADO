#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED
///PROTOTIPO DE CONFIGURACION
///
bool backupProductos();
bool backupProveedor();
bool backupCliente();
bool backupVentas();
bool backupCompra();
bool backupEmpleado();
void subMenuBackup();
void menuBackup();
bool restaurarProductos();
bool restaurarProveedor();
bool restaurarCliente();
bool restaurarVentas();
bool restaurarCompra();
bool restaurarEmpleado();
void subMenuRestaurar();
void menuRestaurar();
void subMenuConfiguracion();
///

bool backupProductos()
{
    Producto reg;
    FILE* ANTERIOR = fopen(PRODUCTOS_CHAR,"rb");
    FILE* NUEVO = fopen(PRODUCTOS_CHAR_BACKUP,"ab");
    if(ANTERIOR==NULL || NUEVO==NULL)
    {
        cout<<"NO SE PUDO HACER EL BACKUP PRODUCTOS."<<endl;
        return false;
    }
    while (fread(&reg,sizeof(Producto),1,ANTERIOR)==1)
    {
        fwrite(&reg,sizeof(Producto),1,NUEVO);
    }
    fclose(ANTERIOR);
    fclose(NUEVO);
    return true;
}
bool backupProveedor()
{
    Proveedor reg;
    FILE* ANTERIOR = fopen(PROVEEDOR_CHAR,"rb");
    FILE* NUEVO = fopen(PROVEEDOR_CHAR_BACKUP,"ab");
    if(ANTERIOR==NULL || NUEVO==NULL)
    {
        cout<<"NO SE PUDO HACER EL BACKUP PROVEEDOR."<<endl;
        return false;
    }
    while (fread(&reg,sizeof(Proveedor),1,ANTERIOR)==1)
    {
        fwrite(&reg,sizeof(Proveedor),1,NUEVO);
    }
    fclose(ANTERIOR);
    fclose(NUEVO);
    return true;
}
bool backupCliente()
{
    Cliente reg;
    FILE* ANTERIOR = fopen(CLIENTE_CHAR,"rb");
    FILE* NUEVO = fopen(CLIENTE_CHAR_BACKUP,"ab");
    if(ANTERIOR==NULL || NUEVO==NULL)
    {
        cout<<"NO SE PUDO HACER EL BACKUP CLIENTES."<<endl;
        return false;
    }
    while (fread(&reg,sizeof(Cliente),1,ANTERIOR)==1)
    {
        fwrite(&reg,sizeof(Cliente),1,NUEVO);
    }
    fclose(ANTERIOR);
    fclose(NUEVO);
    return true;
}
bool backupVentas()
{
    Venta reg;
    FILE* ANTERIOR = fopen(VENTAS_CHAR,"rb");
    FILE* NUEVO = fopen(VENTAS_CHAR_BACKUP,"ab");
    if(ANTERIOR==NULL || NUEVO==NULL)
    {
        cout<<"NO SE PUDO HACER EL BACKUP VENTAS."<<endl;
        return false;
    }
    while (fread(&reg,sizeof(Venta),1,ANTERIOR)==1)
    {
        fwrite(&reg,sizeof(Venta),1,NUEVO);
    }
    fclose(ANTERIOR);
    fclose(NUEVO);
    return true;
}
bool backupCompra()
{
    Compra reg;
    FILE* ANTERIOR = fopen(COMPRA_CHAR,"rb");
    FILE* NUEVO = fopen(COMPRA_CHAR_BACKUP,"ab");
    if(ANTERIOR==NULL || NUEVO==NULL)
    {
        cout<<"NO SE PUDO HACER EL BACKUP COMPRA."<<endl;
        return false;
    }
    while (fread(&reg,sizeof(Compra),1,ANTERIOR)==1)
    {
        fwrite(&reg,sizeof(Compra),1,NUEVO);
    }
    fclose(ANTERIOR);
    fclose(NUEVO);
    return true;
}
bool backupEmpleado()
{
    Empleado reg;
    FILE* ANTERIOR = fopen(EMPLEADO_CHAR,"rb");
    FILE* NUEVO = fopen(EMPLEADO_CHAR_BACKUP,"ab");
    if(ANTERIOR==NULL || NUEVO==NULL)
    {
        cout<<"NO SE PUDO HACER EL BACKUP EMPLEADO."<<endl;
        return false;
    }
    while (fread(&reg,sizeof(Empleado),1,ANTERIOR)==1)
    {
        fwrite(&reg,sizeof(Empleado),1,NUEVO);
    }
    fclose(ANTERIOR);
    fclose(NUEVO);
    return true;
}

void menuBackup()
{

        system("cls");

            if (backupProductos()==true) cout<<"EL BACKUP DEL PRODUCTO SE REALIZO CORRECTAMENTE."<<endl;

            if (backupProveedor()==true) cout<<"EL BACKUP DEL PROVEEDOR SE REALIZO CORRECTAMENTE."<<endl;

            if (backupCliente()==true) cout<<"EL BACKUP DEL CLIENTE SE REALIZO CORRECTAMENTE."<<endl;

            if (backupVentas()==true) cout<<"EL BACKUP DE LAS VENTAS SE REALIZO CORRECTAMENTE."<<endl;

            if (backupCompra()==true)cout<<"EL BACKUP DE LA COMPRA SE REALIZO CORRECTAMENTE."<<endl;

            if (backupEmpleado()==true) cout<<"EL BACKUP DEL EMPLEADO SE REALIZO CORRECTAMENTE."<<endl;

}
bool restaurarProductos()
{
    Producto reg;
    FILE*BACKUP = fopen(PRODUCTOS_CHAR_BACKUP,"rb");
    FILE*RESTAURAR = fopen(PRODUCTOS_CHAR,"wb");
    if(BACKUP==NULL||RESTAURAR==NULL)
    {
        cout << endl;
        cout<<"NO SE PUDO HACER LA RESTAURACION DEL PRODUCTO."<<endl;
        return false;
    }
    while(fread(&reg,sizeof(Producto),1,BACKUP)==1)
    {
        fwrite(&reg,sizeof(Producto),1,RESTAURAR);
    }
    fclose(BACKUP);
    fclose(RESTAURAR);
    return true;
}
bool restaurarProveedor()
{
    Proveedor reg;
    FILE*BACKUP = fopen(PROVEEDOR_CHAR_BACKUP,"rb");
    FILE*RESTAURAR = fopen(PROVEEDOR_CHAR,"wb");
    if(BACKUP==NULL||RESTAURAR==NULL)
    {
        cout << endl;
        cout<<"NO SE PUDO HACER LA RESTAURACION DEL PROVEEDOR."<<endl;
        return false;
    }
    while(fread(&reg,sizeof(Proveedor),1,BACKUP)==1)
    {
        fwrite(&reg,sizeof(Proveedor),1,RESTAURAR);
    }
    fclose(BACKUP);
    fclose(RESTAURAR);
    return true;
}
bool restaurarCliente()
{
    Cliente reg;
    FILE*BACKUP = fopen(CLIENTE_CHAR_BACKUP,"rb");
    FILE*RESTAURAR = fopen(CLIENTE_CHAR,"wb");
    if(BACKUP==NULL||RESTAURAR==NULL)
    {
        cout << endl;
        cout<<"NO SE PUDO HACER LA RESTAURACION DEL CLIENTE."<<endl;
        return false;
    }
    while(fread(&reg,sizeof(Cliente),1,BACKUP)==1)
    {
        fwrite(&reg,sizeof(Cliente),1,RESTAURAR);
    }
    fclose(BACKUP);
    fclose(RESTAURAR);
    return true;
}
bool restaurarVentas()
{
    Venta reg;
    FILE*BACKUP = fopen(VENTAS_CHAR_BACKUP,"rb");
    FILE*RESTAURAR = fopen(VENTAS_CHAR,"wb");
    if(BACKUP==NULL||RESTAURAR==NULL)
    {
        cout << endl;
        cout<<"NO SE PUDO HACER LA RESTAURACION DEL LAS VENTAS."<<endl;
        return false;
    }
    while(fread(&reg,sizeof(Venta),1,BACKUP)==1)
    {
        fwrite(&reg,sizeof(Venta),1,RESTAURAR);
    }
    fclose(BACKUP);
    fclose(RESTAURAR);
    return true;
}
bool restaurarCompra()
{
    Compra reg;
    FILE*BACKUP = fopen(COMPRA_CHAR_BACKUP,"rb");
    FILE*RESTAURAR = fopen(COMPRA_CHAR,"wb");
    if(BACKUP==NULL||RESTAURAR==NULL)
    {
        cout << endl;
        cout<<"NO SE PUDO HACER LA RESTAURACION DEL LA COMPRA."<<endl;
        return false;
    }
    while(fread(&reg,sizeof(Compra),1,BACKUP)==1)
    {
        fwrite(&reg,sizeof(Compra),1,RESTAURAR);
    }
    fclose(BACKUP);
    fclose(RESTAURAR);
    return true;
}
bool restaurarEmpleado()
{
    Empleado reg;
    FILE*BACKUP = fopen(EMPLEADO_CHAR_BACKUP,"rb");
    FILE*RESTAURAR = fopen(EMPLEADO_CHAR,"wb");
    if(BACKUP==NULL||RESTAURAR==NULL)
    {
        cout << endl;
        cout<<"NO SE PUDO HACER LA RESTAURACION DEL EMPLEADO."<<endl;
        return false;
    }
    while(fread(&reg,sizeof(Empleado),1,BACKUP)==1)
    {
        fwrite(&reg,sizeof(Empleado),1,RESTAURAR);
    }
    fclose(BACKUP);
    fclose(RESTAURAR);
    return true;
}
void restaurarTodos()
{
    bool restaurarProductos();
    bool restaurarProveedor();
    bool restaurarCliente();
    bool restaurarVentas();
    bool restaurarCompra();
    bool restaurarEmpleado();
    system("cls");
    cout<<"TODO LAS RESTAURACIONES HAN SIDO REALIZADO CORRECTAMENTE"<<endl;
}

void menuRestaurar()
{

        system("cls");


            if (restaurarProductos()==true) cout<<"LA RESTAURACION DEL PRODUCTO SE REALIZO CORRECTAMENTE."<<endl;

            if (restaurarProveedor()==true) cout<<"LA RESTAURACION DEL PROVEEDOR SE REALIZO CORRECTAMENTE."<<endl;



            if (restaurarCliente()==true) cout<<"LA RESTAURACION DEL CLIENTE SE REALIZO CORRECTAMENTE."<<endl;




            if (restaurarVentas()==true) cout<<"LA RESTAURACION DE LAS VENTAS SE REALIZO CORRECTAMENTE."<<endl;




             if (restaurarCompra()==true)cout<<"LA RESTAURACION DE LA COMPRA SE REALIZO CORRECTAMENTE."<<endl;




            if (restaurarEmpleado()==true) cout<<"LA RESTAURACION DEL EMPLEADO SE REALIZO CORRECTAMENTE."<<endl;
            return;



}
#endif // CONFIGURACION_H_INCLUDED
