#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include "colormenues.h"
///PROTOTIPO
void subMenusListadoProducto();
void subMenusListadoProveedor();
void listarDeUnDeterminadoProducto();



///LISTADO
void listarDeUnDeterminadoProducto()
{
    Producto obj;
    char aux[10];
    int pos=0;
    cout<<"INGRESE UN CODIGO DE PRODUTO: ";
    cin>>aux;
    cout<<endl;
    while (obj.leerdedisco(pos++))
    {
        if (strcmp(obj.getCodigoProducto(),aux)==0)
        {
            obj.mostrarproducto();
            cout<<endl;
        }
    }
}


int Producto :: modificar(int posicion) ///modificar el precio y stock de producto
{
    FILE *PR=fopen(PRODUCTOS_CHAR,"rb+");
    if(PR==NULL)
    {
        return false;
    }
    fseek(PR,sizeof *this *posicion,0);
    bool escribio=fwrite(this, sizeof *this , 1, PR);
    fclose(PR);
}///end


bool Producto::modificarproducto()
{
Producto p;


int pos=0;
char codigo[10];
char opcion;
float precios;
int stocks;
int valida;

cout<<"ingrese el codigo de producto que deseas modificar"<<endl;
cin>>codigo;

while(p.leerdedisco(pos)==1){

    if(strcmp(p.getCodigoProducto(),codigo)==0){

        cout<<"PRODUCTO ENCONTRADO:"<<endl<<endl;
        p.mostrarproducto();
        cout<<"Este es el producto a modificar? s/n:"<<endl<<endl;
        cin>>opcion;

        switch(opcion){

        case 's':
        case 'S':
        cout<<"queres modificar el stock s/n?:"<<endl<<endl;
        cin>>opcion;



        system("cls");

        if(opcion=='s'||opcion=='S'){

            cout<<"ingrese la cantidad de stock"<<endl;
            cin>>stocks;
            if(stocks>0){
            p.setStock(stocks);
            cout<<"STOCK MODIFICADO PERFECTAMENTE"<<endl;
            system("pause");
            system("cls");
            p.modificar(pos);

        }
        else{
        cout<<"NUMERO MENOR A 0 O CON COMA. INTENTELO MAS TARDE CON UN STOCK CORRECTO"<<endl;
        }
 }
        cout<<"queres modificar el precio s/n?:"<<endl<<endl;
        cin>>opcion;

        if(opcion=='s'||opcion=='S'){

            cout<<"ingrese el precio nuevo"<<endl;
            cin>>precios;
            if(precios>0){
            p.setPrecio(precios);
            cout<<"PRECIO MODIFICADO PERFECTAMENTE"<<endl;
            system("pause");
            system("cls");
            p.modificar(pos);

        }
        else{
        cout<<"NUMERO MENOR A 0 . INTENTELO MAS TARDE CON UN PRECIO QUE SEA CORRECTO"<<endl;
        }
    }
         return true;


        break;

        case 'n':
        case 'N':
        return false;
        break;


        }

    }
    cout<<"PRODUCTO NO EXISTENTE"<<endl;
    return false;

}


}

bool Producto::validarproducto(const char *codigo){
    Producto P;
    int pos=0;

    while(P.leerdedisco(pos++)){

        if(strcmp(P.getCodigoProducto(),codigo)==0){
            return 0;
        }
    }
    return 1;
}


bool Producto::nuevoproducto(const char *codigoproductoaux)
{
    textcolor(cNEGRO,cVERDE);
strcpy(codigoProducto,codigoproductoaux);
///validacion
    if(validarproducto(codigoProducto)==0){
    cout<<"codigo repetido"<<endl;
    system("pause");
    system("cls");
    return false;
    }
///validacion
    cout<<"NOMBRE:";
    cin.ignore();
    cin.getline(nombre, 40);
    if (strlen(nombre)==0)
    {
        return false;
    }
    cout<<"PRECIO:";
    cin>>precio;
    if(precio<0){
        cout<<"Numero Negativo, por favor ingrese un precio correcto."<<endl;
        return false;
    }
    /*cout<<"STOCK:";
    cin>>stock;
    if(stock<0){
        cout<<"Numero Negativo, por favor ingrese un stock correcto."<<endl;
        return false;
    }*/
    cout<<"MARCA DEL PRODUCTO:";
    cin.ignore();
    cin.getline(NombreMarca, 15);
    if (strlen(nombre)==0)
    {
        return false;
    }
    activo=1;
    system("cls");
    return true;
}
///GRABAR
bool Producto::grabarproducto()
{
    bool grabo;

    FILE *p= fopen("productos.dat","ab");
    if(p==NULL)return false;

    grabo=fwrite(this, sizeof *this,1,p);
    fclose(p);
    return grabo;


}


bool Producto::altaproducto(const char *codigoproductoaux)
{
    textcolor(cNEGRO,cVERDE);
    Producto a;

    if(a.nuevoproducto(codigoproductoaux)==true)
    {

        if(a.grabarproducto()==true)
        {

            cout << "Producto cargado y guardado correctamente." << endl;

        }
    }
    else
    {
        cout << "producto no guardado" << endl;

    }



}

///LISTAR
bool Producto::leerdedisco(int pos)
{
    FILE*b = fopen ("productos.dat","rb");

    if(b==NULL)
    {

        return false;
    }

    fseek(b,sizeof*this*pos,0);
    bool leyo = fread(this,sizeof *this,1,b);
    fclose(b);

    return leyo;
}




void Producto::listarproducto()
{
    textcolor(cNEGRO,cVERDE);
    FILE *p;
    Producto a;
    int pos=0;
    p=fopen("productos.dat","rb");
    if(p==NULL)
        exit(1);

    while(a.leerdedisco(pos++))
    {
        if(a.activo==1){
                cout<<"-------------------"<<endl;
        a.mostrarproducto();
        cout<<endl;
        cout<<"-------------------"<<endl;
        }
    }
    fclose(p);
}
void Producto::mostrarproducto()
{

    textcolor(cNEGRO,cVERDE);
    if(activo==1)
    {

        cout<<"CÓDIGO DE PRODUCTO:       ";
        cout<<codigoProducto<<endl;
        cout<<"NOMBRE:                   ";
        cout<<nombre<<endl;
        cout<<"PRECIO:                   ";
        cout<<precio<<endl;
        cout<<"STOCK:                    ";
        cout<<stock<<endl;
        cout<<"MARCA:                    ";
        cout<<NombreMarca<<endl;

    }
    else
    {
        cout<< "ESTE PRODUCTO SE ENCUENTRA SIN STOCK : "<<endl;
    }

}
///ELIMINAR

void Producto::eliminarproducto()
{
    Producto p;
    FILE *PR=fopen("productos.dat","rb+");
    if(PR==NULL)
    {
        exit(1);
    }

    char codigoProductox [10];
    int pos=0;
    char opcion;

    cout<<"Ingrese el codigo que deseas eliminar"<<endl<<endl;
    cin>>codigoProducto;

    while(p.leerdedisco(pos))
    {

        if(strcmp(p.codigoProducto,codigoProducto)==0)
        {


            p.mostrarproducto();
            cout<<endl;
            cout<<"este es el producto que deseas eliminar?"<<endl;
            cout<<"INGRESE LA OPCION S(si) || N(no)"<<endl;
            cin>>opcion;
            system("pause");
            system("cls");

            switch (opcion)
            {

            case 's':
            case 'S':

                p.activo=0;
                cout<<" ELIMINADO CORRECTAMENTE "<<endl;
                system("pause");
                fseek(PR,ftell(PR)-sizeof p,0);
                fwrite(this, sizeof (Producto), 1, PR);
                fclose(PR);



                system ("cls");
                return ;
                break;

            case 'n':
            case 'N':
                fclose(PR);
                return;
                break;
            }



        }

pos++;
    }
fclose(PR);
return;

}




#endif // PRODUCTO_H_INCLUDED
