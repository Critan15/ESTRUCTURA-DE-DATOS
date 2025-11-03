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
}

void Verdescripcionproductos(productos* inicio_pro, string productobuscar){
	productos* busquedanombre = inicio_pro;
	int posicion = 0;
	while (busquedanombre!= NULL){
		if(busquedanombre->nom_producto == productobuscar){
			cout << "Producto encontrado\nNombre"<<productobuscar<<endl;
			return;
		}
		busquedanombre=busquedanombre->siguiente_pro;
	}
	cout << "Elemento no encontrado"<<endl;
}

void Menu(){
	cout<<"\n============ MENU ============\n";
	cout<<"1) Registrar Usuario\n";
	cout<<"2) Agregar productos, descuentos y cantidad\n";
	cout<<"3) Ver nombre, precio y cantidad\n";
	cout<<"4) Eliminar productos\n";
	cout<<"5) Salir\n";
	cout<<"Ingrese opcion";
}

int main(){
	string productobuscar;
	usuario* inicio_usua=NULL;
	productos* inicio_pro=NULL;
	
	
	string nombre_pro,nombre_usua,apellido_usua, nombre_pro_elim;
	double precio_pro;
	int cantidad_pro,edad_usua;
	
	int opcion;
	do{
		Menu();
		cin >> opcion;
		
		switch (opcion){
			case 1:{
				
			cout<<"ingrese el nombre del usuario: ";
					cin>>nombre_usua;
					cout<<"ingrese el apellido del usuario: ";
					cin>>apellido_usua;
					cout<<"ingrese la edad del usuario: ";
					cin>>edad_usua;
					//registrar(inicio_usua,nombre_usua,apellido_usua,edad_usua);
			}break;
			case 2:
			{
					
					cin.ignore();
					cout<<"ingrese el nombre del producto: ";
					getline(cin,nombre_pro);
					cout<<"ingrese el precio del producto: ";
					cin>>precio_pro;
					cout<<"ingrese la cantidad: ";
					cin>>cantidad_pro;
					agregarProducto(inicio_pro,nombre_pro,precio_pro,cantidad_pro);
				}break;
			
			case 3:
				cout << "Ingrese producto a buscar: ";
				getline(cin, productobuscar);
				Verdescripcionproductos(inicio_pro,productobuscar);
				break;
			case 4:
				{
					cout<<"ingrese el producto a eliminar: ";
					cin>>nombre_pro_elim;
					eliminar(inicio_pro,nombre_pro_elim);
				}break;
			case 5:
				cout<<"Gracias por su visita vuelva pronto\n";
				break;
			default:
				cout<<"Ingrese opcion valida"<<endl;
				break;
		}
		
	}while(opcion!=5);
	
	
	
	return 0;
	
}