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

    productos* siguiente_pro;
    productos(string cadena, double precio)
    {
        nom_producto=cadena;
        precio_producto=precio;
        siguiente_pro=NULL;
    }
};


void agregarProducto(productos* &inicio_pro, string nombre,double precio)
{
    productos* nuevo_producto=new productos()
	
	
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

int main()
{
	int opcion;
	
	do{
		Menu();
		cin >> opcion;
        cin.ignore(1024,'\n');

		switch (opcion){
			case 1:
			
			case 2:
			
			case 3:
			
			case 4:
				
			case 5:
				cout<<"Gracias por su visita vuelva pronto\n";
				break;
			default:
				cout<<"Ingrese opcion valida"<<endl;
				break;
		}
		
	}while(opcion!=5);
}


//1registrar usuario 
//2)agregar productos y descuentos, catnidad
//3)ver nombre y precio cantidad
//4)eliminar productos
//5)salir

