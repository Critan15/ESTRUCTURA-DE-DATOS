#include <iostream>
using namespace std;



void Menu(){
	cout<<"\n============ MENU ============\n";
	cout<<"1) Registrar Usuario\n";
	cout<<"2) Agregar productos, descuentos y cantidad\n";
	cout<<"3) Ver nombre, precio y cantidad\n";
	cout<<"4) Eliminar productos\n";
	cout<<"5) Salir\n";
	cout<<"Ingrese opcion";
	cin<<opcion;
	cin.ignore(1024,'\n');
}

int main(){
	int opcion;
	
	do{
		Menu();
		cin >> opcion;
		
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
	
	
	
	return 0;
	
}