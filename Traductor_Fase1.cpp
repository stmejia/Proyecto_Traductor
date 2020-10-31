/*Grupo #7
--Karla Ortíz
--Rudy Mejía
--Ingenieria en sistemas
--Plan sábado matutino*/
#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>

using namespace std;
void addData();
void listData();
void editData();
void deleteData();
void filtrarData();
void barra();
void pausa();

//Método principal.
int main(){
	//Variables para el Menu Principal.
	//Mientras la bandera sea 0 procedemos a pintar el menu.
	bool bandera = false;
	char opcion;
	void pausa();
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\Cargando...";
	barra();
	do{
		system("color 1e");
		//Limpiamos la pantalla.
		system("cls");
		cin.clear();
		//Pintamos el menu principal.
		//cout<<"\n\n\t\t\t\t\*********************"<<endl;
		cout<<"\n\n\t\t\t\t\t\t\Bienvenido al sistema"<<endl;
		cout<<"\t\t\t\t\t\t\*********************"<<endl;
		cout<<""<<endl;
		cout<<"\n\n\t\t\t\t\Menu de operaciones"<<endl;
		cout<<"\t\t\t\t\*******************"<<endl;
		cout<<"\t\t\t\t1.Consultar"<<endl;
		cout<<"\t\t\t\t2.Registrar"<<endl;
		cout<<"\t\t\t\t3.Actualizar"<<endl;
		cout<<"\t\t\t\t4.Filtrar"<<endl;
		cout<<"\t\t\t\t5.Eliminar"<<endl;
		cout<<"\t\t\t\t6.Salir"<<endl;
		//Esperamos la respuesta del usuario.
		cout<<"\t\t\t\tIngresa una opcion: ";
		cin>>opcion;
		
		//Variables generales.
		//string STRING;
		//ifstream infile;
		//fstream file;
		//char ESP[200];
	    //char ENG[200];
	    //char FUNC[200];
		
		switch(opcion){
			case '1':
				system("cls");
				cout<<"\n\n\t\t\t\t\Datos registrados"<<endl;
				cout<<"\t\t\t\t\*********************"<<endl;
				cout<<""<<endl;
				listData();
				pausa();
				break;
			
			case '2':
				system("cls");
				cout<<"\n\n\t\t\t\t\Nuevo registro"<<endl;
				cout<<"\t\t\t\t\*********************"<<endl;
				cout<<""<<endl;
				addData();
				pausa();
				break;
				
			case '3':
				system("cls");
				cout<<"\n\n\t\t\t\t\Modificando registro"<<endl;
				cout<<"\t\t\t\t\*********************"<<endl;
				cout<<""<<endl;
				editData();
				pausa();
				break;
				
			case '4':
				system("cls");
				cout<<"\n\n\t\t\t\t\Filtrar registros"<<endl;
				cout<<"\t\t\t\t\*********************"<<endl;
				cout<<""<<endl;
				filtrarData();
				pausa();
				break;
				
			case '5':
				system("cls");
				cout<<"\n\n\t\t\t\tEliminando registro"<<endl;
				cout<<"\t\t\t\t\*********************"<<endl;
				cout<<""<<endl;
				deleteData();
				pausa();
				break;
				
			case '6':
				system("cls");
				bandera=true;
				cout << ""<<endl;	
				cout<<"\t\t\t\t\**********************************"<<endl;
				cout << "\t\t\t\t\Gracias por utilizar el sistema c:";
				cout<<"\n\t\t\t\t\**********************************"<<endl;
				break;
				
			default:
				system("cls");
				cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\Debe seleccionar una opcion valida.\n";
				pausa();
				break;
		}
	}while(bandera!=true);
	
	return 0;
}

//Método que agrega la data.
void addData(){
	//Variables generales.
	char ID [25];
	char ESP[25];
	char ENG[25];
	char FUNC[25];
	
	//Creamos y abrimos el archivo en modo append.
	fstream data;
	data.open("data.txt", ios::app);
    cin.ignore();
    
    //Recibimos la data.
    cout << "\t\t\t\t\Ingresa el ID : ";
	cin.getline(ID,25);
	cout << "\t\t\t\t\Ingresa una sentencia : ";
	cin.getline(ESP,25);
	cout << "\t\t\t\t\Ingresa la traduccion : ";
	cin.getline(ENG,25);
	cout << "\t\t\t\t\Ingresa su funcionalidad : ";
	cin.getline(FUNC,25);
	data<< ID<<':'<<ESP<<'|'<<ENG<<'|'<<FUNC<<'\n';
	
	cout << "" << endl;
	cout <<"\t\t\t\t\Documento Actualizado"<< endl;
	data.close();
}

//Método para listar la data.
void listData(){
	//Variables generales.
	string linea;
	ifstream file("data.txt");
	
	//Validamos si el archivo se encuentra vacio, si no pintamos la data.
	if(file.peek() == std::ifstream::traits_type::eof()){
		cout << "\t\t\t\t\Archivo vacio"<<endl;
		cout << "\t\t\t\t\Puedes ingresar datos en la opcion #2"<<endl;
		cout << ""<<endl;	
	} else {
		cout << "\t\t\t\t\SENTENCIA   |TRADUCCION   |FUNCION" << endl;
		while(file.good())
        {
            getline(file,linea);
            cout << "\t\t\t\t" << linea << endl;
        }
        
        file.close();
	}
}

//Método para modificar la data.
void editData(){
	//Variables generales.
	fstream data;
    fstream temp;

    data.open("data.txt",ios::in);
    temp.open("temp.txt",ios::out);
    char ID [25];
    char ESP[25];
    char ENG[25];
    char FUNC[25];
    char CAD[25];
    cin.ignore();
    cout<<" \n\t\t\t\t\Ingresa el ID del registro que quieras modificar : ";
    cin.getline(CAD,25);
    while(!data.eof())
    {
        data.getline(ID,25,':');
        data.getline(ESP,25,'|');
        data.getline(ENG,25,'|');
        data.getline(FUNC,25);
        if(strcmp(ID,CAD)==0)
        {
            cout<<" \n\t\t\t\t\Ingresa los nuevos valores  \n ";
            cout<<" \n\t\t\t\t\ Sentencia : ";
            cin.getline(ESP,25);
            cout<<" \n\t\t\t\t\ Traduccion : ";
            cin.getline(ENG,25);
            cout<<" \n\t\t\t\t\ Funcion : ";
            cin.getline(FUNC,25);
            temp<< ID<<':'<<ESP<<'|'<<ENG<<'|'<<FUNC<<endl;
        }
        else
        {
            temp<< ID<<':'<<ESP<<'|'<<ENG<<'|'<<FUNC<<endl;
        }
    }
    temp.close();
    data.close();

    data.open("data.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof())
    {
    	temp.getline(ID,25,':');
        temp.getline(ESP,25,'|');
        temp.getline(ENG,25,'|');
        temp.getline(FUNC,25);
        data<< ID<<':'<<ESP<<'|'<<ENG<<'|'<<FUNC<<'\n';
    }
    temp.close();
    data.close();
    remove("temp.txt");
}

//Método para eliminar la data.
void deleteData(){
	//Variables generales.
	string linea;
	size_t id = 1;
	ifstream datos_entrada("data.txt");
	
	//Contamos todas las lineas del archivo.
	while (getline(datos_entrada, linea))
	{
		++id;
	}
	
	//Matriz dinamica para almacenar las cadenas con los ID.
	string *datos = new string[id];
	
	datos_entrada.close(); 
	datos_entrada.open("data.txt"); 
	
	//Leemos todas las lineas del archivo y las almacenamos en la matriz.
	for (size_t i = 1; getline(datos_entrada, linea); ++i)
	{
		//cout << linea << endl;
		datos[i] = linea;
	}
	
	datos_entrada.close();
	
	//Pintamos los registros existentes.
	cout << "\t\t\t\tEstos son los registros actuales:" << endl;
	for (size_t i = 1; i < id; ++i)
	{
		cout<<"\t\t\t\t"<< datos[i] << endl;
	}
	
	size_t ID_USER = 0; //ID que ingresará el usuario.
	cout << "" << endl;
	cout << "\t\t\t\t\Ingresa el ID del registro que deseas eliminar: ";
	cin >> ID_USER;
	
	//Validamos si el registro existe para poder eliminarlo.
	if (ID_USER < 0 || ID_USER >= id)
	{
		cout << "";
		cout << "\t\t\t\t\No existe el registro, por favor verifique el ID." << endl;
	}
	else
	{
		cout << "" << endl;
		cout << "\t\t\t\t\Registro eliminado exitosamente: "  << datos[ID_USER] << endl;
		//Eliminamos el registro seleccionado.
		datos[ID_USER].erase();
	}
	
	//Creamos la secuencia y abrimos el archivo con los datos actualizados.
	ofstream datos_salida("data.txt");
	//Pintamos los registros actualizados en pantalla.
	cout << "" << endl;
	cout << "\t\t\t\t\Registros actualizados:" << endl;
	for (size_t i = 0; i < id; ++i)
	{
		if (!datos[i].empty())
		{
			cout <<"\t\t\t\t" << datos[i] << endl; 
			datos_salida << datos[i] << endl;
		}
	}
	
	datos_salida.close();
}

//Metodo para filtrar la data.
void filtrarData(){
	//Variables generales.
	fstream data;
    data.open("data.txt",ios::in);
    char ID [25];
    char ESP[25];
    char ENG[25];
    char FUNC[25];
    char CAD[25];
    
    cout<<" \n\t\t\t\t Ingresa el ID del registro que quieres consultar : ";
    cin.ignore();
    cin.getline(CAD,25);
    int x=0;
    cout<< " \n\t\t\t\t ID \t SENTENCIA \t TRADUCCION \t FUNCION \n";
    while(!data.eof())
    {
        data.getline(ID,25,':');
        data.getline(ESP,25,'|');
        data.getline(ENG,25,'|');
        data.getline(FUNC,25);
        if(strcmp(ID, CAD)==0)
        {
        	cout<< "\n \t\t\t\t"<< ID<<"\t"<<ESP<<"\t"<<ENG<<"\t"<<FUNC<<endl;
            x=1;
            break;
        }

    }
    if(x==0)
    {
        cout<<" \n\t\t\t\t\ No se encontro el registro, verifica el ID ingresado. \n";
    }
    data.close();
}

//Barra de carga
void barra(){
   //Variables generales
   system("color 0e");
   int barl = 60;
   cout << "\n\n\t\t\t\[";     
   for (int i = 0; i < barl; i++) {         
      Sleep(100);       
      cout << ":";  
   }
   cout << "]"<<endl;
   //pausa();
}

//Método para regresar al menú principal.
void pausa()
{
    cout << "\n\t\t\t\t\Pulsa una tecla para regresar al menu principal...";
    getwchar();
    getwchar();
}
