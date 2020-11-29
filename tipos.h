#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED
class Fecha
{
private:
    int dia;
    int mes;
    int anio;
public:
   fecha(){int dia=mes=anio=0;}
    int  cargarFecha();
    int Validacion(int,int,int);
    int getdia()
    {
        return dia;
    }
    int getmes()
    {
        return mes;
    }
    int getanio()
    {
        return anio;
    }
    void setdia(int d)
    {
        dia=d;
    }
    void setmes(int m)
    {
        mes=m;
    }
    void setanio(int a)
    {
        anio=a;
    }
};

int Fecha::cargarFecha()
{
    int fechaAux;
    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"AÑO: ";
    cin>>anio;
    fechaAux=Validacion(dia,mes,anio);
    return fechaAux;
}
int Fecha::Validacion(int dia,int mes,int anio)
{
    int bol = 0;
    if (mes>=1 && mes <= 12)
    {
        switch (mes)
        {
        /// Meses de 31 dias Enero, Marzo, Julio, Agosto, Octubre y Diciembre.
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (dia>=1 && dia <=31)
            {
                bol = 1;
            }
            break;
        /// Meses de 30 dias Abril, Junio, Septiembre y Noviembre.
        case 4:
        case 6:
        case 9:
        case 11:
            if (dia >=1 && dia <= 30)
            {
                bol = 1;
            }
            break;
        case 2:
            /// Febrero
            /// Si el año es bisiesto + 1 dia.
            /// Formula para saber si un año es bisiesto.
            if( (anio%4 == 0)   &&   (anio%100 != 0)   ||   (anio%400 == 0) )
            {
                /// Si es bisiesto, sumamos un dia.
                if( dia >= 1 && dia <= 29 )
                {
                    bol = 1;
                };
            }
            else
            {
                /// En el caso contrario no sumamos nadaaaaaaaaaaaaaaaaaaaaa.
                if( dia >= 1 && dia <= 28 )
                {
                    bol = 1;
                };
            };
            break;
        }
    }
    return bol;
}


class Producto
{
private:
    char codigoProducto [10];
    char nombre[40];
    float precio;
    int stock;
    char NombreMarca[15];
    int activo;
public:
    producto(){activo=0;}
    void CargarProducto();
    const char *getCodigoProducto(){return codigoProducto;}
    const char *getmarca(){return NombreMarca;}
    const char *getNombre(){return nombre;}
    float getPrecio(){return precio;}
    int getStock(){return stock;}
    const char *getCodigomarca(){return NombreMarca;}
    void setCodigo(const char *codigox){strcpy(codigoProducto,codigox);}
    void setNombre(const char *nombrex){strcpy(nombre,nombrex);}
    void setPrecio(float f){precio=f;}
    void setStock(int h){stock=h;}
    void setMarca(const char *marcax){strcpy(NombreMarca,marcax);}
    bool nuevoproducto();
    bool grabarproducto();
    bool altaproducto();
    bool leerdedisco(int);
    void mostrarproducto();
    void eliminarproducto();
    int modificar(int);
    bool modificarproducto();
    void listarproducto();
    void buscarporCodigoProducto();
    bool validarproducto(const char *);


};

class Categoria
{
private:
    int codigoCategoriaProducto;
    char nombreCategoriaProducto[40];
public:
    int getCodigoCate();
    const char *getNombreCat();
    void setCodigoCate(int);
    void setNombreCate(const char *);
};
class Proveedor
{
private:
    int numeroProveedor;
    char nombre[40];
    char apellido[40];
    int dni;
    int nroTelefono;
    char  domicilio[50];
    Fecha nacimiento;
    char email[50];
    char genero[10];

    int activo;
public:
    Proveedor(){activo=0;}
    bool getActivo();
    void setActivo(bool a){activo=a;}
    bool CargarProveedor();
    void MostrarProveedor();
    int getNumeroProveedor(){return numeroProveedor;}

    void setNumeroProveedor(int );
    bool grabarProveedor();
    bool leerProveedor(int );
    bool altaProveedor();
    bool leerDiscoProveedor(int );
    void listarPorNumeroProveedor();
    void bajaProveedor();
    bool modificarProveedor(int);
    void modificarProveedorNuevo();
    void listarProveedor();
    int buscarProveedor(int);
};
class Cliente
{

private:
    int idcompra;
    int idCliente;
    char nombre[40];
    char apellido[40];
    int dni;
    int nroTelefono;
    char  domicilio[50];
    Fecha nacimiento;
    char email[50];
    char genero[10];

    bool activo;

public:
    bool getActivo();
    void setActivo(bool a){activo=a;}
    bool CargarCliente(int);
    void MostrarCliente();
    int getIDCliente(){return idCliente ;}
    int getDNI(){return dni;}
    void setIDCliente(int);
    bool grabarCliente();
    bool leerCliente(int );
    bool altaCliente(int);
    bool leerDiscoCliente(int );
    void listarPorIDCliente();
    void bajaCliente();
    bool modificarCliente(int);
    void modificarClienteNuevo();
    void listarCliente();
    int buscarCliente(int);
    int VALIDARID(int);
    int getidcompra(){return idcompra;}


};



class Venta
{
private:
    int idVenta;
    int idCliente;
    int idEmpleado;
    char codigoProducto[10];
    int formaPago;
    float importe;
    int cantvendida;
    Fecha fechaVenta;
    int activo;
public:
    Venta(){activo=0;}
    ///gets
    bool getEstado();
    int getCantvendida();
    int getIDcliente(){return idCliente;}
    int getIDVenta(){return idVenta;}
    int getIDEmpleadoVenta(){return idEmpleado;}
    float getImporte(){return importe;}
    int getFormaPago();
    int getFechaVentaDia(){return fechaVenta.getdia();}
    int getFechaVentaMes(){return fechaVenta.getmes();}
    int getFechaVentaAnio(){return fechaVenta.getanio();}
    char getCodigoProducto(){return *codigoProducto;}
    ///sets
    void setIdEmpleado(int aux){idEmpleado=aux;}
    void setIDVenta(int);
    void setImporte(float);
    void setFormaPago(int);
    ///funciones
    bool altaventa();
    bool CargarVenta();
    void MostarVenta();
    bool grabarventa();
    void listarventa();
    void bajaVenta();
    void modificarVentaNuevo();
    bool leerDiscoVenta(int);
    void listarPorNumeroVenta();
    bool modificarVenta(int);
    int buscarVenta(int);
    bool BuscarStock (const char *, int );
    bool ModificarStock(const char *, int );
};
class Empleado
{
private:
    int idEmpleado;
    float sueldo;
    char nombre[40];
    char apellido[40];
    int dni;
    int nroTelefono;
    char  domicilio[50];
    Fecha nacimiento;
    char email[50];
    char genero[10];
    int activo;
public:
    void CargarEmpleado();
    void MostrarEmpleado();
    int getIDEmpleado(){return idEmpleado;}
    float getSueldo();
    int getDNI(){return dni;}
    const char *getApellidoEmpleado(){return apellido;}
    const char *getNombreEmpleado(){return nombre;}
    int getEstado(){return activo;}
    void setIDEmpleado(int);
    void setSueldo(float);
    void *setNombre(const char);
    bool nuevoEmpleado();
    bool grabarEmpleado();
    bool altaEmpleado();
    bool leerdedisco(int);
    void eliminarEmpleado();
    void modificarEmpleado();
    void listarEmpleado();
    void buscarporCodigoEmpleado();
};

class Compra
{
private:
    int Nrocompra;
    char codProducto[10];
    int numProveedor;
    int cantIngresada;
    Fecha fechaDeCompra;
    Fecha fechaVencimientoPago;
    float importe;
    int formaPago;
    bool activo;
public:
    ////Cargar/Mostrar
    bool CargarCompra();
    void MostrarCompra();
    ////
    bool leerDiscoCompra(int);
    bool nuevaCompra();
    bool altaCompra();
    bool modificar(int);
    bool modificarCompra();///se carga lo que queres modificar
    int buscarCompra(int);
    bool listarCompra();
    bool grabarCompra();
    void bajaCompra();
    bool ValidacionCodproducto(const char *);
    //// Getters/Setters
    void setcodProductoCompra(const char * auxCodProductoCompra){strcpy(codProducto,auxCodProductoCompra);}
    void setnumProveedorCompra(int auxNumProveedorCompra){numProveedor=auxNumProveedorCompra;}
    void setcantIngresadaCompra(int auxCantIngresadaCompra){cantIngresada=auxCantIngresadaCompra;}
    Fecha getFecha(){return fechaDeCompra;}
    void setImporteCompra(float auxImporteCompra){importe=auxImporteCompra;}
    void setFormaPagoCompra(int auxFormaPagoCompra){formaPago=auxFormaPagoCompra;}
    void setActivoCompra(bool auxActivo){activo=auxActivo;}
    const char *getcodProductoCompra(){return codProducto;}
    int getnumProveedor(){return numProveedor;}
    int getCantidadCompra(){return cantIngresada;}
    float getImporteCompra(){return importe;}
    int getFormapagoCompra(){return formaPago;}
    bool getActivoComprar(){return activo;}
    bool stockup(const char *,int);
    float buscarprecio(const char *);
    int getNrocompra(){return Nrocompra;}

};
#endif // TIPOS_H_INCLUDED
