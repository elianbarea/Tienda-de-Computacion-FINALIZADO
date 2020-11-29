#ifndef INFORME_H_INCLUDED
#define INFORME_H_INCLUDED



///RECAUDACION POR MES DEL AÑO 2020
void MostrarVector(int tam,float *VEC){///muestra cualquiero tipo de vector

int opcion;
for(int x=0;x<tam;x++){
opcion=x+1;

    cout<<"El mes De ";
    switch(opcion)
    {

case 1:
     cout<<"Enero Se recaudo un total de: "<<VEC[x]<<endl;
    break;
case 2:
     cout<<"Febrero Se recaudo un total de: "<<VEC[x]<<endl;
    break;
case 3:
     cout<<"Marzo Se recaudo un total de: "<<VEC[x]<<endl;
    break;
case 4:
     cout<<"Abril Se recaudo un total de: "<<VEC[x]<<endl;
    break;
case 5:
     cout<<"Mayo Se recaudo un total de: "<<VEC[x]<<endl;
    break;
case 6:
     cout<<"Junio Se recaudo un total de: "<<VEC[x]<<endl;
    break;
case 7:
     cout<<"Julio Se recaudo un total de: "<<VEC[x]<<endl;
    break;
case 8:
     cout<<"Agosto Se recaudo un total de: "<<VEC[x]<<endl;
    break;
case 9:
    cout<<"Septiembre Se recaudo un total de: "<<VEC[x]<<endl;
    break;
case 10:
     cout<<"Octubre Se recaudo un total de: "<<VEC[x]<<endl;
    break;
case 11:
     cout<<"Noviembre Se recaudo un total de: "<<VEC[x]<<endl;
    break;
case 12:
    cout<<"Diciembre Se recaudo un total de: "<<VEC[x]<<endl;
    break;
    }





}
system("pause");
system("cls");

}

bool Recaudacion_2020 (){

Venta v;




///float *vectorx;
float vectorx[12]={0};
int tam=12;
int pos=0;


while(v.leerDiscoVenta(pos)){

for(int x=0;x<12;x++){

    if(v.getFechaVentaAnio()==2020){

        if(v.getFechaVentaMes()==x+1){

            vectorx[x]=v.getImporte();
        }
    }

}

pos++;
}

MostrarVector(tam,vectorx);
return true;


}
///------------------------------------------------------------------
///CANTIDAD DE PRODUCTO DISPONIBLE EN STOCK

void buscarProducto(){
Producto aux;
int pos=0;

while(aux.leerdedisco(pos)){

    cout<<"PRODUCTO: "<<aux.getNombre();
    cout<<endl;
    cout<<"MARCA: "<<aux.getmarca();
    cout<<endl;
    cout<<"CANTIDAD DE STOCK: "<<aux.getStock();
    cout<<endl;
    cout<<"---------------------------------"<<endl;
pos++;
}

}
///------------------------------------------------------------------
///

///PROTOTIPO
///
int MostrarVentasPorEmpleado(int,int);
int VentasPorEmpleado();
void subMenuInforme();
///
int MostrarVentasPorEmpleado(int id,int anio)
{
    Venta obj;
    int contador = 0;
    int posicion = 0;
    while(obj.leerDiscoVenta(posicion++))
    {
        if(id==obj.getIDEmpleadoVenta()&& obj.getFechaVentaAnio()==anio)
        {
            contador+=1;
        }
    }
    return contador;
}
int VentasPorEmpleado()
{
    Empleado obj;
    int anio;
    int c = 0;
    int posicion = 0;
    cout<<"INGRESE UN AÑO: ";
    cin >> anio;
    system("cls");
    while(obj.leerdedisco(posicion++))
    {
        if(obj.getEstado()==1)
        {
            c=MostrarVentasPorEmpleado(obj.getIDEmpleado(),anio);
            cout << endl;
            if(c>0)
            {
                cout<<"EMPLEADO: "<<obj.getIDEmpleado()<<endl;
                cout<<"APELLDIO: "<<obj.getApellidoEmpleado()<<endl;
                cout<<"NOMBRE: "<<obj.getNombreEmpleado()<<endl;
                cout <<"CANTIDAD: "<<c<<endl;
                cout << endl;
            }
        }
    }
    return 10;
}



















#endif // INFORME_H_INCLUDED
