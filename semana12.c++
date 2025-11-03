#include <iostream>

using namespace std;

struct usuario{
	string nombre;
	string apellido;
	int edad;
	usuario* siguiente;
	usuario(string nombre, string apellido, int edad)
	{
		nombre=nombre;
		apellido=apellido;
		edad=edad;
		siguiente=NULL;
	}
};

struct productos{
    string nom_producto;
    double precio_producto;
    int cantidad_producto;

    productos* siguiente_pro;
    productos(string cadena, double precio,int cantidad)
    {
        nom_producto=cadena;
        precio_producto=precio;
        cantidad_producto=cantidad;
        siguiente_pro=NULL;
    }
};
////////////////////////////
void registrar(usuario* &inicio_usua,string nombre_usua, string apellido_usua,int edad_usua)
{
	usuario* nuevo=new usuario(nombre_usua,apellido_usua,edad_usua);
	if(inicio_usua==NULL)
	{
		inicio_usua=nuevo;
	}else
	{
		usuario* temp=inicio_usua;
		while(temp->siguiente!=NULL)
		{
			temp=temp->siguiente;
		}
		temp->siguiente=nuevo;
	}
}
/////////////////////
void Verdescripcionproductos(productos* inicio_pro){
	
	if(inicio_pro==NULL)
	{
		cout<<"la lista esta vacia"<<endl;
		return;
	}
	
	string productobuscar;
	cout << "Ingrese producto a buscar: ";
	getline(cin, productobuscar);
	
	productos* busquedanombre = inicio_pro;
	int posicion = 0;
	while (busquedanombre!= NULL){
		if(busquedanombre->nom_producto == productobuscar){
			cout << "Producto encontrad "<<endl;
			cout<<"Nombre de producto: "<<busquedanombre->nom_producto<<"\nPrecio de producto : S/"<<busquedanombre->precio_producto<<"\nCantidad de producto: "<<busquedanombre->cantidad_producto<<endl;
			return;
		}
		busquedanombre=busquedanombre->siguiente_pro;
	}
	cout << "Elemento no encontrado"<<endl;
}
///////////////////////////////////



void agregarProducto(productos* &inicio_pro, string nombre,double precio,int cantidad)
{
    productos* nuevo_producto=new productos(nombre,precio,cantidad);
    if(inicio_pro==NULL)
    {
    	inicio_pro=nuevo_producto;
	}else
	{
		productos* temp=inicio_pro;
		while(temp->siguiente_pro!=NULL)
		{
			temp=temp->siguiente_pro;
		}
		temp->siguiente_pro=nuevo_producto;
	}
}
/////////////////////////////
void eliminar(productos* &inicio_pro,string nombre_elim)
{
	if(inicio_pro==NULL)
	{
		cout<<"error la lista esta vacia"<<endl;
		return;
	}
	
	if(inicio_pro->nom_producto==nombre_elim)
	{
		productos* temp=inicio_pro;
		inicio_pro=inicio_pro->siguiente_pro;
		delete temp;
		return;
	}
	
	productos* anterior=inicio_pro;
	productos* actual=inicio_pro->siguiente_pro;
	
	while(actual != NULL && actual->nom_producto!=nombre_elim)
	{
		anterior=actual;
		actual=actual->siguiente_pro;
	}
	
	if(actual==NULL)
	{
		cout<<"elemento no encontrado"<<endl;
	}else
	{
		anterior->siguiente_pro=actual->siguiente_pro;
		cout<<endl<<"elemento eliminado"<<endl;
		delete actual;
	}
}
////////////////////
void mostrar(productos* inicio)
{
	if(inicio==NULL)
	{
		cout<<"la lista esta vacia"<<endl;
		return;
	}
	while(inicio!=NULL)
	{
		cout<<"Nombre de producto: "<<inicio->nom_producto<<"\nPrecio de producto : S/"<<inicio->precio_producto<<"\nCantidad de producto: "<<inicio->cantidad_producto<<endl;
		inicio=inicio->siguiente_pro;
	}
}



void Menu(){
	cout<<"\n============ TIENDA DON PEPE ============\n";
	cout<<"1) Registrar Usuario\n";
	cout<<"2) Agregar productos, descuentos y cantidad\n";
	cout<<"3) Buscar nombre, precio y cantidad\n";
	cout<<"4) Eliminar productos\n";
	cout<<"5) Mostrar todos los productos\n";
	cout<<"6) Salir\n";
	cout<<"Ingrese opcion: ";
}

int main()
{
	usuario* inicio_usua=NULL;
	productos* inicio_pro=NULL;
	
	
	string nombre_pro,nombre_usua,apellido_usua, nombre_pro_elim;
	
	double precio_pro;
	int cantidad_pro,edad_usua;
	
	int opcion;
	
	do{
		Menu();
		cin >> opcion;
        cin.ignore(1024,'\n');

		switch (opcion){
			case 1:
				{
					cout<<"ingrese el nombre del usuario: ";
					cin>>nombre_usua;
					cout<<"ingrese el apellido del usuario: ";
					cin>>apellido_usua;
					cout<<"ingrese la edad del usuario: ";
					cin>>edad_usua;
					registrar(inicio_usua,nombre_usua,apellido_usua,edad_usua);
				}break;
			
			case 2:
				{
					cout<<"ingrese el nombre del producto: ";
					getline(cin,nombre_pro);
					cout<<"ingrese el precio del producto: ";
					cin>>precio_pro;
					cout<<"ingrese la cantidad: ";
					cin>>cantidad_pro;
					agregarProducto(inicio_pro,nombre_pro,precio_pro,cantidad_pro);
					cin.ignore();
				}break;
			
			case 3:
				{
					
					Verdescripcionproductos(inicio_pro);
				}break;
			
			case 4:
				{
					cout<<"ingrese el producto a eliminar: ";
					cin>>nombre_pro_elim;
					eliminar(inicio_pro,nombre_pro_elim);
				}break;
			case 5:
				{
					mostrar(inicio_pro);
				}break;
			case 6:
				cout<<"Gracias por su visita vuelva pronto\n";
				break;
			default:
				cout<<"Ingrese opcion valida"<<endl;
				break;
		}
		
	}while(opcion!=6);
}


//1registrar usuario 
//2)agregar productos y descuentos, catnidad
//3)ver nombre y precio cantidad
//4)eliminar productos
//5)salir

