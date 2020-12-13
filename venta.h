#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "colormenues.h"
#include "compra.h"
#include "cliente.h"



//LISTAR UNA SOLA VENTA
void UNAVENTA(){
Venta v;

int pos=0;
int id;

cout<<"INGRESE EL NRO ID"<<endl;
cin>>id;
system("cls");

while(v.leerDiscoVenta(pos++)){

    if(id==v.getIDVenta()){

        v.MostarVenta();

    }

}


}



//FUNCION ID VENTA ALFANUMERICO
int BuscarIDventa()
{
    Venta a;
    int mayorid = 0;

    FILE* p = fopen(VENTAS_CHAR,"rb");
    if(p==NULL)
    {
        return mayorid+1;
    }

    while(fread(&a,sizeof(Venta),1,p)==1)
    {

        if(a.getIDVenta()>mayorid)
        {

            mayorid = a.getIDVenta();
        }

    }


    return mayorid +1;
}

bool Venta::ModificarStock(const char *CodPro, int cantidad)
{

    Producto Reg;
    int posicion = 0;
    int Total = 0;

    while(Reg.leerdedisco(posicion))
    {

        if(strcmp(Reg.getCodigoProducto(),CodPro)==0)
        {
            Total = Reg.getStock()-cantidad;
            Reg.setStock(Total);


            Reg.modificar(posicion);
            return true;

        }
posicion++;

    }
    return false;
}

bool Venta::BuscarStock(const char *CodPro,int cantidad)
    {
FILE *P =fopen(PRODUCTOS_CHAR,"rb");
if(P==NULL)
{
    return false;
    exit(1);
}

Producto Reg;
        int posicion = 0;

        while(Reg.leerdedisco(posicion))
        {

            if(strcmp(Reg.getCodigoProducto(),CodPro)==0)
            {

                if(Reg.getStock()>=cantidad )//&& cantidad <=Reg.getStock()
                {
                    if(ModificarStock(CodPro,cantidad)==true){

                    return true;
                    fclose(P);
                    }
                }

            }
fclose(P);
posicion++;
        }

        return false;
    }

    bool Venta::CargarVenta()
    {
Compra P;
Cliente C;

        textcolor(cNEGRO,cVERDE);

        ///ID VENTA EN ALFANUMERICO

        idVenta = BuscarIDventa();


        cout<<"CARGE LOS DATOS DE LA VENTA: "<<endl;

        cout<<"ID DE EMPLEADO: ";
        cin>>idEmpleado;

        cout<<"CODIGO DE PRODUCTO: ";
        cin.ignore();
        cin.getline(codigoProducto,10);
        if (strlen(codigoProducto)==0)
        {
            return false;
        }

        cout<<"FORMA DE PAGO (1: Efectivo, 2: Tarjeta):  ";
        cin>>formaPago;

        ///VALIDACION FORMA DE PAGO

        if (formaPago==1 || formaPago==2) {}
        else
        {
            cout<<"FORMA DE PAGO INCORRECTO, ";
            return false;
        }


        ///VALIDACION IMPORTE MAYOR A 0

        if(importe>0) {}
        else
        {
            cout<<"EL IMPORTE ES MENOS o IGUAL A 0, ";
            return false;
        }
        cout<<"CANTIDAD VENDIDA: ";
        cin>>cantvendida;
        ///VALIDACION STOCK
        if(BuscarStock(codigoProducto,cantvendida)==false){

            cout<<"NO HAY STOCK DEL PRODUCTO"<<endl;
            return false;
        }
        ///VALIDACION STOCK
        ///IMPORTE

        float precio = P.buscarprecio(codigoProducto);

        importe=precio*cantvendida;
        ///IMPORTE

        cout<<"FECHA DE VENTA"<<endl;
        while (fechaVenta.cargarFecha()==0)
        {
            system("cls");
            cout<<"FECHA INVALIDA."<<endl;
            cout<<"FECHA DE VENTA"<<endl;
        }

        cout<<"CARGE LOS DATOS DEL CLIENTE: "<<endl;
        if(C.altaCliente(idVenta)==false){

        return false;

        }
        system("cls");
        activo=true;
        return true;


    }

    int mostraridcliente(int idventa){
    Cliente c;
    int pos=0;
    while(c.leerDiscoCliente(pos)==1)
    {
        if (idventa==c.getidcompra())
        {
            return c.getIDCliente();

        }
        pos++;
    }

    }


    void Venta::MostarVenta()
    {
        textcolor(cNEGRO,cVERDE);
        if (activo==true)
        {
            cout<<"ID EMPLEADO: ";
            cout<<idEmpleado<<endl;
            cout<<"ID DE VENTA: ";
            cout<<idVenta<<endl;
            cout<<"ID DE CLIENTE: ";
            cout<<mostraridcliente(idVenta)<<endl;
            cout<<"CODIGO DE PRODUCTO: ";
            cout<<codigoProducto<<endl;
            cout<<"FORMA DE PAGO: ";
            cout<<formaPago<<endl;
            cout<<"IMPORTE: ";
            cout<<importe<<endl;
            cout<<"CANTIDAD VENDIDAD: ";
            cout<<cantvendida<<endl;
            cout<<"FECHA DE VENTA"<<endl;
            cout<<fechaVenta.getdia()<<"/"<<fechaVenta.getmes()<<"/"<<fechaVenta.getanio();
        }

    }

    bool Venta::grabarventa()
    {

        FILE *archivo_venta=fopen(VENTAS_CHAR,"ab");
        if(archivo_venta==NULL)return false;
        bool escribio=fwrite(this,sizeof(Venta),1,archivo_venta);
        fclose(archivo_venta);
        return escribio;

    }

    bool Venta::altaventa()
    {

        textcolor(cNEGRO,cVERDE);
        Venta a;


        if(a.CargarVenta()==true)
        {
            if(a.grabarventa()==true)
            {
                cout <<"VENTA HECHA!"<<endl;
            }
        }

        else
        {
            cout<<"NO SE PUDO HACER LA VENTA!"<<endl;
        }

    }

    bool Venta::leerDiscoVenta(int posicion)
    {
        FILE *archivo_venta=fopen(VENTAS_CHAR,"rb");
        if (archivo_venta==NULL)
        {
            return false;
        }
        fseek(archivo_venta,sizeof*this*posicion,0);
        bool leyo=fread(this,sizeof *this,1,archivo_venta);
        fclose(archivo_venta);
        return leyo;
    }

    void Venta::listarventa()
    {
        textcolor(cNEGRO,cVERDE);
        FILE *archivo_venta=fopen(VENTAS_CHAR,"rb");
        Venta a;
        int pos=0;
        if(archivo_venta==NULL)
        {
            exit(1);
        }
        while(a.leerDiscoVenta(pos++))
        {
            a.MostarVenta();
            cout<<endl;
            cout<<"-------------------"<<endl;
        }
        fclose(archivo_venta);
    }

    void Venta::bajaVenta()
    {

        textcolor(cNEGRO,cVERDE);
        FILE *archivo_venta=fopen(VENTAS_CHAR,"rb+");
        char opcion;
        int pos=0;
        int aux;
        Venta a;
        if(archivo_venta==NULL)
        {
            exit(1);
        }
        cout<<" INGRESE EL ID DE VENTA A CANCELAR: ";
        cin>>aux;
        cout<<endl;
        while(a.leerDiscoVenta(pos++))
        {
            if (aux==a.idVenta)
            {
                cout<< "¿DESEA CANCELAR ESTA VENTA?: "<<endl;
                a.MostarVenta();
                cout<<endl;
                cout<<"..........................."<<endl;
                cout<<" INGRESE S ( SI ) O N (NO):  " ;
                cin>> opcion;
                if (opcion=='s'||opcion=='S')
                {
                    a.activo=false;
                    cout<<" ELIMINADO CORRECTAMENTE "<<endl;
                    fseek(archivo_venta,ftell(archivo_venta)-sizeof a,0);
                    fwrite(this, sizeof (Venta), 1, archivo_venta);
                    fclose(archivo_venta);
                }
                fclose(archivo_venta);
                return;
            }
        }
        cout<< "NO SE ENCONTRO EL ID DE VENTA";
        fclose(archivo_venta);

    }
    bool Venta::modificarVenta(int posicion)
    {

        FILE *archivo_venta=fopen(VENTAS_CHAR,"rb+");
        if(archivo_venta==NULL)
        {
            return false;
        }
        fseek(archivo_venta,sizeof*this*posicion,0);
        bool escribio=fwrite(this, sizeof*this, 1, archivo_venta);
        fclose(archivo_venta);

    }

    int Venta::buscarVenta(int idVentaAux)
    {

        int pos=0;
        Venta a;
        while(a.leerDiscoVenta(pos))
        {
            if (idVentaAux==a.idVenta)
            {
                return pos;
            }
            pos++;
        }

        return -1;

    }

    void Venta::modificarVentaNuevo()
    {

        textcolor(cNEGRO,cVERDE);
        int idVentaAux;
        float npu;
        int pos;
        Venta a;
        cout<<"INGRESE EL ID DE VENTA QUE DESEA MODIFICAR: ";
        cin>>idVentaAux;
        pos=buscarVenta(idVentaAux);
        if(pos!=-1)
        {
            a.CargarVenta();
            a.modificarVenta(pos);
        }
        else
        {
            cout<<"NO EXISTE EL ID DE VENTA"<<endl;
        }


    }

#endif // VENTA_H_INCLUDED
