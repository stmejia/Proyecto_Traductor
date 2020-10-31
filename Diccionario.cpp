#include<iostream>
#include<fstream>
#include<string.h>
#include<cstring>
using namespace std;

class Diccionario{
	private : const char *nombre_archivo = "archivo.txt";
	private : const char *nombre2 = "archivo2.txt";
	private : char palabrasTotales[500];	
	public : int contador=0;
	
	public: 
	struct Datos{
		string palabra;
		string traduccion;
		string funcionalidad;
	}Palabras[200];
	
	void obtenerDatos(){
		contador = 0;	
		string datAlone;
		unsigned pos;
		char delimitador[] = "-";

		ifstream archivo;
		string contenido;
		archivo.open(nombre_archivo,ios::app);
		if (archivo.fail()){
			cout<<"No es posible abrir el archivo";
			exit(1);
		}else{
			do{
				getline(archivo,contenido);
				if(!contenido.empty()){
					strcpy(palabrasTotales, contenido.c_str());
					char *dato = strtok(palabrasTotales, delimitador);
					string dat(dato);
					if(dato != NULL){
						pos = dat.find(":");
						datAlone = dat.substr(pos+1);
						Palabras[contador].palabra = datAlone;
				
						while((dato=strtok(NULL, delimitador)) != NULL){
							string dat2(dato);
							if (strncmp(dat2.substr(0,1).c_str(), "T",1)==0){
								pos = dat2.find(":");
								datAlone = dat2.substr(pos+1);
								Palabras[contador].traduccion = datAlone;
							} else if(strncmp(dat2.substr(0,1).c_str(), "F",1)==0){
								pos = dat2.find(":");
								datAlone = dat2.substr(pos+1);
								Palabras[contador].funcionalidad = datAlone;
							}
						}	
					}	
					contador++;
				}
			}while(!archivo.eof());
		}
		archivo.close();
	}
	void abrir(){
		int fila = 0;
		ifstream archivo;
		string contenido;
		archivo.open(nombre_archivo,ios::app);
		if (archivo.fail()){
			cout<<"No es posible abrir el archivo";
			exit(1);
		}else{
			cout<<"----------------CONTENIDO DEL ARCHIVO--------------------"<<endl;
			do{
				getline(archivo,contenido);
				if(!contenido.empty()){
					cout<<fila<<"| "<<contenido<<endl;
					cout<<"______________________________________________________________"<<endl;
					fila++;
				}
			}while(!archivo.eof());
			cout<<"---------------FIN CONTENIDO DEL ARCHIVO-----------------\n"<<endl;
		}
		archivo.close();
	}
	void ingresar(){
		ofstream archivo;
		char res='s';
		Datos info;
		archivo.open(nombre_archivo,ios::app);
		if (archivo.fail()){
			cout<<"No es posible abrir el archivo";
			exit(1);
		}else{
			while(res == 's'){
				cout<<"Ingrese palabra: ";
				cin>>info.palabra;
				cout<<"Ingrese traduccion: ";
				cin.ignore();
				getline(cin,info.traduccion);
				cout<<"Ingrese funcionalidad:";
				getline(cin,info.funcionalidad);

				archivo<<"\nPalabra:"<<info.palabra<<"-"<<"Traduccion:"<<info.traduccion<<"-"<<"Funconalidad:"<<info.funcionalidad;
				cout<<"Desea agregar otra palabra? (s/n): ";
				cin>>res;
				system("cls");
			}

			archivo.close();
			abrir();
		}	
	}
	void modificar(){
		int datoMod = 0;
		int opc = 0;
		char res='s';

		obtenerDatos();
		ofstream archivo;
		ofstream archivo2;
		archivo2.open(nombre2,ios::app);
		archivo.open(nombre_archivo,ios::app);
		if (archivo.fail() || archivo2.fail()){
			cout<<"No es posible abrir el archivo";
			exit(1);
		}else{
			while(res == 's'){
				system("cls");
				abrir();
				cout<<"Ingrese numero de fila para modificar: ";
				cin>>datoMod;
				cout<<datoMod<<"| Palabra: "<<Palabras[datoMod].palabra<<" Traduccion: "<<Palabras[datoMod].traduccion<<"\nFuncionalidad: "<<Palabras[datoMod].funcionalidad<<endl;
				cout<<"Ingrese numero de la opcion que se quiere modificar:"<<endl;
				cout<<"1. Palabra"<<endl;
				cout<<"2. Traduccion"<<endl;
				cout<<"3. Funcionalidad"<<endl;
				cin>>opc;

				if(opc == 1){
					cout<<"Ingrese nueva palabra: ";
					cin>>Palabras[datoMod].palabra;
				} else if(opc == 2){
					cout<<"Ingrese nueva traduccion: ";
					cin>>Palabras[datoMod].traduccion;
				} else if(opc == 3){
					cout<<"Ingrese nueva funcionalidad: ";
					cin>>Palabras[datoMod].funcionalidad;
				} else {
					cout<<"Opcion no valida"<<endl;
				}

				cout<<"Desea modificar otro dato? (s/n): ";
				cin>>res;
			}
		
			for(int i=0; i<200; i++){
				archivo<<"Palabra:"<<Palabras[i].palabra<<"-"<<"Traduccion:"<<Palabras[i].traduccion<<"-"<<"Funconalidad:"<<Palabras[i].funcionalidad<<"\n";
			}
		
			archivo.close();
			archivo2.close();
			remove(nombre_archivo);
			rename(nombre2, nombre_archivo);
			system("cls");
			archivo.close();
		}
	}

	void eliminar(){
		int datoEli = 0;
		obtenerDatos();

		ofstream archivo;
		char res='s';
		Datos info;
		archivo.open(nombre_archivo,ios::app);
		if (archivo.fail()){
			cout<<"No es posible abrir el archivo";
			exit(1);
		}else{
			while(res == 's'){
				cout<<"Ingrese palabra: ";
				cin>>info.palabra;
				cout<<"Ingrese traduccion: ";
				cin.ignore();
				getline(cin,info.traduccion);
				cout<<"Ingrese funcionalidad:";
				getline(cin,info.funcionalidad);

				archivo<<"Palabra:"<<info.palabra<<"-"<<"Traduccion:"<<info.traduccion<<"-"<<"Funconalidad:"<<info.funcionalidad<<"\n";
				cout<<"Desea agregar otra palabra? (s/n): ";
				cin>>res;
				system("cls");
			}

			archivo.close();
			abrir();
		}	
	}
};


/*main(){
	char res='s';
	char resm='s';
	int opc = 0;
	abrir();
	cout<<"Desea modificar el contenido del archivo? (s/n): ";
	cin>>res;
	if(res == 's'){
		while(resm == 's'){
			system("cls");
			cout<<"Ingrese el numero de la accion que desea realizar"<<endl;
			cout<<"1. Crear"<<endl;
			cout<<"2. Leer"<<endl;
			cout<<"3. Actualizar"<<endl;
			cout<<"4. Borrar"<<endl;
			cin>>opc;

			if(opc == 1){
				ingresar();
			} else if(opc == 2){
				abrir();
			} else if(opc == 3){
				modificar();
			} else if(opc == 4){
				eliminar();
			} else {
				cout<<"Opcion no valida"<<endl;
			}
			cout<<"Desea continuar en CRUD? (s/n): ";
			cin>>resm;
		}
	}
	
	cout<<"Presione cualquier tecla para cerrar :)";
	system("PAUSE");
}

void obtenerDatos(){
	int contador = 0;	
	string datAlone;
	unsigned pos;

	ifstream archivo;
	string contenido;
	archivo.open(nombre_archivo,ios::app);
	if (archivo.fail()){
		cout<<"No es posible abrir el archivo";
		exit(1);
	}else{
		do{
			getline(archivo,contenido);
			if(!contenido.empty()){
				strcpy(palabrasTotales, contenido.c_str());
				char *dato = strtok(palabrasTotales, delimitador);
				string dat(dato);
				if(dato != NULL){
					pos = dat.find(":");
					datAlone = dat.substr(pos+1);
					Palabras[contador].palabra = datAlone;
				
					while((dato=strtok(NULL, delimitador)) != NULL){
						string dat2(dato);
						if (strncmp(dat2.substr(0,1).c_str(), "T",1)==0){
							pos = dat2.find(":");
							datAlone = dat2.substr(pos+1);
							Palabras[contador].traduccion = datAlone;
						} else if(strncmp(dat2.substr(0,1).c_str(), "F",1)==0){
							pos = dat2.find(":");
							datAlone = dat2.substr(pos+1);
							Palabras[contador].funcionalidad = datAlone;
						}
					}	
				}	
				contador++;
			}
		}while(!archivo.eof());
	}
	archivo.close();
}
void abrir(){
	int fila = 0;
	ifstream archivo;
	string contenido;
	archivo.open(nombre_archivo,ios::app);
	if (archivo.fail()){
		cout<<"No es posible abrir el archivo";
		exit(1);
	}else{
		cout<<"----------------CONTENIDO DEL ARCHIVO--------------------"<<endl;
		do{
			getline(archivo,contenido);
			if(!contenido.empty()){
				cout<<fila<<"| "<<contenido<<endl;
				cout<<"______________________________________________________________"<<endl;
				fila++;
			}
		}while(!archivo.eof());
		cout<<"---------------FIN CONTENIDO DEL ARCHIVO-----------------\n"<<endl;
	}
	archivo.close();
}
void ingresar(){
	ofstream archivo;
	char res='s';
	Datos info;
	archivo.open(nombre_archivo,ios::app);
	if (archivo.fail()){
		cout<<"No es posible abrir el archivo";
		exit(1);
	}else{
		while(res == 's'){
			cout<<"Ingrese palabra: ";
			cin>>info.palabra;
			cout<<"Ingrese traduccion: ";
			cin.ignore();
			getline(cin,info.traduccion);
			cout<<"Ingrese funcionalidad:";
			getline(cin,info.funcionalidad);

			archivo<<"\nPalabra:"<<info.palabra<<"-"<<"Traduccion:"<<info.traduccion<<"-"<<"Funconalidad:"<<info.funcionalidad;
			cout<<"Desea agregar otra palabra? (s/n): ";
			cin>>res;
			system("cls");
		}

		archivo.close();
		abrir();
	}	
}
void modificar(){
	int datoMod = 0;
	int opc = 0;
	char res='s';

	obtenerDatos();
	ofstream archivo;
	ofstream archivo2;
	archivo2.open(nombre2,ios::app);
	archivo.open(nombre_archivo,ios::app);
	if (archivo.fail() || archivo2.fail()){
		cout<<"No es posible abrir el archivo";
		exit(1);
	}else{
		while(res == 's'){
			system("cls");
			abrir();
			cout<<"Ingrese numero de fila para modificar: ";
			cin>>datoMod;
			cout<<datoMod<<"| Palabra: "<<Palabras[datoMod].palabra<<" Traduccion: "<<Palabras[datoMod].traduccion<<"\nFuncionalidad: "<<Palabras[datoMod].funcionalidad<<endl;
			cout<<"Ingrese numero de la opcion que se quiere modificar:"<<endl;
			cout<<"1. Palabra"<<endl;
			cout<<"2. Traduccion"<<endl;
			cout<<"3. Funcionalidad"<<endl;
			cin>>opc;

			if(opc == 1){
				cout<<"Ingrese nueva palabra: ";
				cin>>Palabras[datoMod].palabra;
			} else if(opc == 2){
				cout<<"Ingrese nueva traduccion: ";
				cin>>Palabras[datoMod].traduccion;
			} else if(opc == 3){
				cout<<"Ingrese nueva funcionalidad: ";
				cin>>Palabras[datoMod].funcionalidad;
			} else {
				cout<<"Opcion no valida"<<endl;
			}

			cout<<"Desea modificar otro dato? (s/n): ";
			cin>>res;
		}
		
		for(int i=0; i<200; i++){
				archivo<<"Palabra:"<<Palabras[i].palabra<<"-"<<"Traduccion:"<<Palabras[i].traduccion<<"-"<<"Funconalidad:"<<Palabras[i].funcionalidad<<"\n";
		}
		
		archivo.close();
		archivo2.close();
		remove(nombre_archivo);
		rename(nombre2, nombre_archivo);
		system("cls");
		archivo.close();
	}
}
void eliminar(){
	int datoEli = 0;
	obtenerDatos();

	ofstream archivo;
	char res='s';
	Datos info;
	archivo.open(nombre_archivo,ios::app);
	if (archivo.fail()){
		cout<<"No es posible abrir el archivo";
		exit(1);
	}else{
		while(res == 's'){
			cout<<"Ingrese palabra: ";
			cin>>info.palabra;
			cout<<"Ingrese traduccion: ";
			cin.ignore();
			getline(cin,info.traduccion);
			cout<<"Ingrese funcionalidad:";
			getline(cin,info.funcionalidad);

			archivo<<"Palabra:"<<info.palabra<<"-"<<"Traduccion:"<<info.traduccion<<"-"<<"Funconalidad:"<<info.funcionalidad<<"\n";
			cout<<"Desea agregar otra palabra? (s/n): ";
			cin>>res;
			system("cls");
		}

		archivo.close();
		abrir();
	}	
}*/

