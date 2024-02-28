#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Estructura para libro
struct strLibro {
	string titulo;
	string autor;
	int ISBN;
	int anoPublicacion;
	string idioma;
	int numPaginas;
	string genero;
};

// Estructura para usuario
struct strUsuario {
	int IDusuario;
	string nombre;
	string apellido;
	string email;
	int edad;
	string direccion;
};

// Estructura para bibliotecario
struct strBiblio {
	int IDempleado;
	string nombre;
	string apellido;
	string email;
	string turnoLaboral;
	string areaEspecializacion;
};

// Funcion para imprimir un libro
void imprimir(const strLibro* libros, int cantidad, bool imprimirEncabezado = true) {
	if (imprimirEncabezado) {
		cout << setw(30) << left << "TITULO" << setw(22) << left << "AUTOR" << setw(15) << left << "ISBN" << setw(20) << left << "AÑO DE PUBLICACION"
			<< setw(15) << left << "IDIOMA" << setw(15) << left << "NUMERO DE PAGINAS" << setw(20) << left << "GENERO" << endl;
	}
	
	for (int i = 0; i < cantidad; ++i) {
		cout << setw(30) << left << libros[i].titulo << setw(22) << left << libros[i].autor << setw(15) << left << libros[i].ISBN
			<< setw(20) << left << libros[i].anoPublicacion << setw(15) << left << libros[i].idioma << setw(15) << left << libros[i].numPaginas
			<< setw(15) << left << libros[i].genero << endl;
	}
}

// Funcion para imprimir usuarios
void imprimir(const strUsuario* usuarios, int cantidad, bool imprimirEncabezado = true) {
	if (imprimirEncabezado) {
		cout << setw(10) << left << "ID" << setw(15) << left << "Nombre" << setw(15) << left << "Apellido" << setw(30) << left << "Email"
			<< setw(10) << left << "Edad" << setw(30) << left << "Direccion" << endl;
	}
	
	for (int i = 0; i < cantidad; ++i) {
		cout << setw(10) << left << usuarios[i].IDusuario << setw(15) << left << usuarios[i].nombre << setw(15) << left << usuarios[i].apellido
			<< setw(30) << left << usuarios[i].email << setw(10) << left << usuarios[i].edad << setw(30) << left << usuarios[i].direccion << endl;
	}
}

// Funcion para imprimir bibliotecarios
void imprimir(const strBiblio* bibliotecarios, int cantidad, bool imprimirEncabezado = true) {
	if (imprimirEncabezado) {
		cout << setw(10) << left << "ID" << setw(15) << left << "Nombre" << setw(15) << left << "Apellido" << setw(30) << left << "Email"
			<< setw(15) << left << "Turno laboral" << setw(30) << left << "Area de especializacion" << endl;
	}
	
	for (int i = 0; i < cantidad; ++i) {
		cout << setw(10) << left << bibliotecarios[i].IDempleado << setw(15) << left << bibliotecarios[i].nombre << setw(15) << left << bibliotecarios[i].apellido
			<< setw(30) << left << bibliotecarios[i].email << setw(15) << left << bibliotecarios[i].turnoLaboral
			<< setw(30) << left << bibliotecarios[i].areaEspecializacion << endl;
	}
}

// Funcion para buscar un libro por titulo
void buscarLibroTitulo(const strLibro* libros, int cantidad, const string& tituloBuscado) {
	bool encontrado = false;
	string tituloBuscadoLowerCase = tituloBuscado;
	transform(tituloBuscadoLowerCase.begin(), tituloBuscadoLowerCase.end(), tituloBuscadoLowerCase.begin(), ::tolower);
	
	// Variable para almacenar la cantidad de libros encontrados
	int librosEncontrados = 0;
	
	for (int i = 0; i < cantidad; ++i) {
		string tituloActualLowerCase = libros[i].titulo;
		transform(tituloActualLowerCase.begin(), tituloActualLowerCase.end(), tituloActualLowerCase.begin(), ::tolower);
		if (tituloActualLowerCase.find(tituloBuscadoLowerCase) != string::npos) {
			if (!encontrado) {
				// Imprimir encabezados solo una vez cuando se encuentra el primer libro
				cout << "Imprimiendo libros encontrados:" << endl;
				cout << setw(30) << left << "TITULO" << setw(22) << left << "AUTOR" << setw(15) << left << "ISBN" << setw(20) << left << "AÑO DE PUBLICACION"
					<< setw(15) << left << "IDIOMA" << setw(15) << left << "NUMERO DE PAGINAS" << setw(20) << left << "GENERO" << endl;
				encontrado = true;
			}
			cout << setw(30) << left << libros[i].titulo << setw(22) << left << libros[i].autor << setw(15) << left << libros[i].ISBN
				<< setw(20) << left << libros[i].anoPublicacion << setw(15) << left << libros[i].idioma << setw(15) << left << libros[i].numPaginas
				<< setw(15) << left << libros[i].genero << endl;
			librosEncontrados++;
		}
	}
	
	if (!encontrado) {
		cout << "No se encontraron libros con '" << tituloBuscado << "' en el título." << endl;
	} else {
		cout << "Total de libros encontrados: " << librosEncontrados << endl;
	}
}

// Funcion para buscar un usuario por nombre y apellido
void buscarUsuarioNombreApellido(const strUsuario* usuarios, int cantidad, const string& nombreApellidoBuscado) {
	bool encontrado = false;
	string nombreApellidoBuscadoLowerCase = nombreApellidoBuscado;
	transform(nombreApellidoBuscadoLowerCase.begin(), nombreApellidoBuscadoLowerCase.end(), nombreApellidoBuscadoLowerCase.begin(), ::tolower);
	
	// Variable para almacenar la cantidad de usuarios encontrados
	int usuariosEncontrados = 0;
	
	for (int i = 0; i < cantidad; ++i) {
		string nombreActual = usuarios[i].nombre + " " + usuarios[i].apellido;
		string nombreActualLowerCase = nombreActual;
		transform(nombreActualLowerCase.begin(), nombreActualLowerCase.end(), nombreActualLowerCase.begin(), ::tolower);
		if (nombreActualLowerCase.find(nombreApellidoBuscadoLowerCase) != string::npos) {
			if (!encontrado) {
				// Imprimir encabezados solo una vez cuando se encuentra el primer usuario
				cout << "Imprimiendo usuarios encontrados:" << endl;
				cout << setw(10) << left << "ID" << setw(15) << left << "Nombre" << setw(15) << left << "Apellido" << setw(30) << left << "Email"
					<< setw(10) << left << "Edad" << setw(30) << left << "Direccion" << endl;
				encontrado = true;
			}
			cout << setw(10) << left << usuarios[i].IDusuario << setw(15) << left << usuarios[i].nombre << setw(15) << left << usuarios[i].apellido
				<< setw(30) << left << usuarios[i].email << setw(10) << left << usuarios[i].edad << setw(30) << left << usuarios[i].direccion << endl;
			usuariosEncontrados++;
		}
	}
	
	if (!encontrado) {
		cout << "No se encontraron usuarios con '" << nombreApellidoBuscado << "' en el nombre o apellido." << endl;
	} else {
		cout << "Total de usuarios encontrados: " << usuariosEncontrados << endl;
	}
}

// Funcion para buscar un bibliotecario por nombre y apellido
void buscarBibliotecarioNombreApellido(const strBiblio* bibliotecarios, int cantidad, const string& nombreApellidoBuscado) {
	bool encontrado = false;
	string nombreApellidoBuscadoLowerCase = nombreApellidoBuscado;
	transform(nombreApellidoBuscadoLowerCase.begin(), nombreApellidoBuscadoLowerCase.end(), nombreApellidoBuscadoLowerCase.begin(), ::tolower);
	
	// Variable para almacenar la cantidad de bibliotecarios encontrados
	int bibliotecariosEncontrados = 0;
	
	for (int i = 0; i < cantidad; ++i) {
		string nombreActual = bibliotecarios[i].nombre + " " + bibliotecarios[i].apellido;
		string nombreActualLowerCase = nombreActual;
		transform(nombreActualLowerCase.begin(), nombreActualLowerCase.end(), nombreActualLowerCase.begin(), ::tolower);
		if (nombreActualLowerCase.find(nombreApellidoBuscadoLowerCase) != string::npos) {
			if (!encontrado) {
				// Imprimir encabezados solo una vez cuando se encuentra el primer bibliotecario
				cout << "Imprimiendo bibliotecarios encontrados:" << endl;
				cout << setw(10) << left << "ID" << setw(15) << left << "Nombre" << setw(15) << left << "Apellido" << setw(30) << left << "Email"
					<< setw(15) << left << "Turno laboral" << setw(30) << left << "Area de especializacion" << endl;
				encontrado = true;
			}
			cout << setw(10) << left << bibliotecarios[i].IDempleado << setw(15) << left << bibliotecarios[i].nombre << setw(15) << left << bibliotecarios[i].apellido
				<< setw(30) << left << bibliotecarios[i].email << setw(15) << left << bibliotecarios[i].turnoLaboral
				<< setw(30) << left << bibliotecarios[i].areaEspecializacion << endl;
			bibliotecariosEncontrados++;
		}
	}
	
	if (!encontrado) {
		cout << "No se encontraron bibliotecarios con '" << nombreApellidoBuscado << "' en el nombre o apellido." << endl;
	} else {
		cout << "Total de bibliotecarios encontrados: " << bibliotecariosEncontrados << endl;
	}
}

int main() {
	const int TMA = 5;
	
	srand(time(0));
	
	// Arrays fijos de datos
	string listaLibros[] = {"Aprende C", "Aprende PHP", "Aprende Linux", "Aprende Python", "Aprende Java"};
	string listaAutores[] = {"Autor1", "Autor2", "Autor3", "Autor4", "Autor5"};
	int listaISBNs[TMA]; 
	
	for (int i = 0; i < TMA; ++i) {
		listaISBNs[i] = i + 1; 
	}
	
	string listaIdiomas[] = {"Ingles", "Español", "Frances", "Alemán", "Italiano"};
	string listaGeneros[] = {"Ficcion", "No ficcion", "Misterio", "Ciencia ficcion", "Fantasia"};
	string listaNombres[] = {"Juan", "Maria", "Pedro", "Ana", "Luis"};
	string listaApellidos[] = {"Gomez", "Perez", "Lopez", "Martinez", "Garcia"};
	int listaEdades[] = {20, 25, 30, 35, 40}; 
	int listaIDs[] = {1001, 1002, 1003, 1004, 1005}; 
	string listaTurnos[] = {"mañana", "tarde", "noche", "mañana", "tarde"};
	string listaEspecializaciones[] = {"Catalogacion", "Referencia", "Adquisiciones", "Archivos", "Preservacion"};
	
	// Creacion de arreglos para libros, usuarios y bibliotecarios
	strLibro libros[TMA];
	strUsuario usuarios[TMA];
	strBiblio bibliotecarios[TMA];
	
	// Generar datos aleatorios para libros, usuarios y bibliotecarios
	for (int i = 0; i < TMA; ++i) {
		libros[i].titulo = listaLibros[i];
		libros[i].autor = listaAutores[i];
		libros[i].ISBN = listaISBNs[i];
		libros[i].anoPublicacion = 2000 + rand() % 20; 
		libros[i].idioma = listaIdiomas[i];
		libros[i].numPaginas = 100 + rand() % 401; 
		libros[i].genero = listaGeneros[i];
		
		usuarios[i].IDusuario = listaIDs[i];
		usuarios[i].nombre = listaNombres[i];
		usuarios[i].apellido = listaApellidos[i];
		usuarios[i].email = listaNombres[i] + listaApellidos[i] + "@gmail.com"; 
		usuarios[i].edad = listaEdades[i];
		usuarios[i].direccion = "Direccion de " + listaNombres[i]; 
		
		bibliotecarios[i].IDempleado = listaIDs[i] + 1000; 
		bibliotecarios[i].nombre = listaNombres[i];
		bibliotecarios[i].apellido = listaApellidos[i];
		bibliotecarios[i].email = listaNombres[i] + listaApellidos[i] + "@upds.com"; 
		bibliotecarios[i].turnoLaboral = listaTurnos[i];
		bibliotecarios[i].areaEspecializacion = listaEspecializaciones[i];
	}
	
	int opcion;
	do {
		cout << "\nMENU:\n";
		cout << "1) Llenado de datos.\n";
		cout << "2) Listados.\n";
		cout << "3) Busquedas.\n";
		cout << "0) Salir.\n";
		cout << "Ingrese su opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			// Implementar el llenado de datos
			break;
		case 2: {
			char subopcionListados;
			do {
				cout << "\nSUBMENU LISTADOS:\n";
				cout << "A) Listado de Libros.\n";
				cout << "B) Listado Usuarios.\n";
				cout << "C) Listado Bibliotecarios.\n";
				cout << "X) Salir.\n";
				cout << "Ingrese su opcion: ";
				cin >> subopcionListados;
				subopcionListados = tolower(subopcionListados);
				
				switch (subopcionListados) {
				case 'a':
					imprimir(libros, TMA);
					break;
				case 'b':
					imprimir(usuarios, TMA);
					break;
				case 'c':
					imprimir(bibliotecarios, TMA);
					break;
				case 'x':
					cout << "Saliendo del submenu de listados..." << endl;
					break;
				default:
					cout << "Opcion no válida. Intentelo de nuevo." << endl;
				}
			} while (subopcionListados != 'x');
			break;
		}
		case 3: {
			char subopcionBusquedas;
			do {
				cout << "\nSUBMENU BUSQUEDAS:\n";
				cout << "A) Búsqueda de Libro (Titulo).\n";
				cout << "B) Búsqueda de Usuario (Nombre y Apellido).\n";
				cout << "C) Búsqueda de Bibliotecario (Nombre y Apellido).\n";
				cout << "X) Salir.\n";
				cout << "Ingrese su opcion: ";
				cin >> subopcionBusquedas;
				subopcionBusquedas = tolower(subopcionBusquedas);
				
				switch (subopcionBusquedas) {
				case 'a': {
					string tituloBuscado;
					cout << "Ingrese el titulo o parte del titulo del libro a buscar: ";
					cin.ignore();
					getline(cin, tituloBuscado);
					buscarLibroTitulo(libros, TMA, tituloBuscado);
					break;
				}
				case 'b': {
					string nombreApellidoBuscado;
					cout << "Ingrese el nombre o apellido del usuario a buscar: ";
					cin.ignore();
					getline(cin, nombreApellidoBuscado);
					buscarUsuarioNombreApellido(usuarios, TMA, nombreApellidoBuscado);
					break;
				}
				case 'c': {
					string nombreApellidoBuscado;
					cout << "Ingrese el nombre o apellido del bibliotecario a buscar: ";
					cin.ignore();
					getline(cin, nombreApellidoBuscado);
					buscarBibliotecarioNombreApellido(bibliotecarios, TMA, nombreApellidoBuscado);
					break;
				}
				case 'x':
					cout << "Saliendo del submenu de búsquedas..." << endl;
					break;
				default:
					cout << "Opcion no válida. Intentelo de nuevo." << endl;
				}
			} while (subopcionBusquedas != 'x');
			break;
		}
		case 0:
			cout << "Saliendo del programa..." << endl;
			break;
		default:
			cout << "Opcion no válida. Intentelo de nuevo." << endl;
		}
	} while (opcion != 0);
	
	return 0;
}



