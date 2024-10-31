
### Gary Alexander Josué Aju Chuta  
**Carnet:** 202206963  
**Facultad:** Ingeniería Ciencias y Sistemas  
**Sección:** EDD C  

---

En este proyecto, se desarrolló una red social utilizando C++. La aplicación permite a los usuarios registrarse, gestionar amistades, y compartir publicaciones. A través de una estructura de matriz, se organizan las relaciones entre los usuarios, permitiendo una eficiente administración de las interacciones y conexiones en la plataforma. El proyecto también incluye la capacidad de navegar por publicaciones y gestionar amistades, proporcionando una experiencia similar a la de una red social real, todo implementado en un entorno de consola.

## Descripción del Código

El código define la clase `DoublyCircular`, que implementa una lista doblemente enlazada circular en C++. Esta estructura de datos permite manejar elementos de forma circular, donde el último elemento está conectado de vuelta al primero, y viceversa.

### Componentes del Código:

1. **Encabezado y Definiciones:**
   - Se incluyen las librerías necesarias como `<iostream>` y `<string>`, y se incluye un archivo de encabezado `"../headers/NodoListas.h"`.
   - Se define un guard para evitar múltiples inclusiones del código (`#ifndef CIRCULARDOBLE_CPP`).

2. **Atributos Privados:**
   - `NodoListas *head`: Puntero al primer nodo de la lista.
   - `NodoListas *tail`: Puntero al último nodo de la lista.
   - `NodoListas *actual`: Puntero que indica el nodo actual, útil para mostrar publicaciones.

3. **Constructor:**
   - `DoublyCircular()`: Inicializa los punteros `head`, `tail`, y `actual` como `nullptr`.

4. **Métodos Públicos:**
   - **`estaVacia`:** Verifica si la lista está vacía.
   - **`append`:** Agrega un nuevo nodo al final de la lista, ajustando los punteros para mantener la estructura circular.
   - **`push`:** Inserta un nuevo nodo al inicio de la lista, ajustando los punteros para mantener la estructura circular.
   - **`mostrarPublicacionDer`:** Muestra la publicación actual desde la posición derecha, avanzando al siguiente nodo si se llega al final de las publicaciones.
   - **`mostrarPublicacionIzq`:** Muestra la publicación actual desde la posición izquierda, retrocediendo al nodo anterior si se llega al final de las publicaciones.
   - **`eliminar`:** Elimina un nodo basado en el email del propietario de la publicación, ajustando los punteros para mantener la estructura circular.
   - **


## Resumen de Clases en C++

### 1. Clase `DoublyCircular`

La clase `DoublyCircular` implementa una lista doblemente enlazada circular. Sus principales funciones son:

- **Constructor:** Inicializa una lista vacía.
- **`estaVacia`:** Verifica si la lista está vacía.
- **`append`:** Agrega un nodo al final de la lista.
- **`push`:** Agrega un nodo al inicio de la lista.
- **`mostrarPublicacionDer`:** Muestra la publicación actual desde la posición derecha, avanzando si se llega al final de las publicaciones de un nodo.
- **`mostrarPublicacionIzq`:** Muestra la publicación actual desde la posición izquierda, retrocediendo si se llega al final de las publicaciones de un nodo.
- **`eliminar`:** Elimina un nodo basado en el email del propietario de la publicación.
- **`reporte`:** Genera un archivo `.dot` y una imagen `.png` que representa gráficamente la lista.

### 2. Clase `LinkedList`

La clase `LinkedList` representa una lista enlazada simple. Sus principales características incluyen:

- **Constructor:** Inicializa la lista vacía.
- **`estaVacia`:** Verifica si la lista está vacía.
- **`append`:** Agrega un nodo al final de la lista.
- **`push`:** Inserta un nodo al inicio de la lista.
- **`eliminar`:** Elimina un nodo específico basado en un criterio dado.
- **`reporte`:** Genera un reporte visual de la lista enlazada utilizando un archivo `.dot`.

### 3. Clase `Publicaciones`

La clase `Publicaciones` maneja las publicaciones de los usuarios en la red social. Sus funcionalidades incluyen:

- **Constructor:** Inicializa la lista de publicaciones.
- **`agregarPublicacion`:** Agrega una nueva publicación a la lista.
- **`mostrarPublicacionesDer`:** Navega y muestra publicaciones hacia la derecha.
- **`mostrarPublicacionesIzq`:** Navega y muestra publicaciones hacia la izquierda.
- **`eliminarPublicacion`:** Elimina una publicación específica.
- **`reporte`:** Genera un reporte visual de las publicaciones.

### 4. Clase `ModuloUsuario`

La clase `ModuloUsuario` gestiona la información y las acciones relacionadas con los usuarios de la red social. Las principales funciones son:

- **Constructor:** Inicializa el módulo de usuario.
- **`registrarUsuario`:** Registra un nuevo usuario en la red.
- **`eliminarUsuario`:** Elimina un usuario de la red.
- **`mostrarPerfil`:** Muestra el perfil de un usuario.
- **`reporte`:** Genera un reporte visual de los usuarios registrados.

### 5. Clase `ModuloAdmin`

La clase `ModuloAdmin` administra las funciones globales y avanzadas de la red social. Incluye las siguientes funcionalidades:

- **Constructor:** Inicializa el módulo de administrador.
- **`agregarUsuario`:** Permite al administrador agregar usuarios manualmente.
- **`eliminarUsuario`:** Elimina usuarios basados en criterios específicos.
- **`generarReporteGlobal`:** Crea un reporte completo de la red social, incluyendo usuarios y publicaciones.
- **`gestionarPermisos`:** Administra los permisos y roles de los usuarios.

Cada una de estas clases está diseñada para manejar diferentes aspectos de la red social, proporcionando una estructura modular y escalable para la aplicación.


## Clases

### `ListaUsuarios`

- **Descripción**: Administra una lista de usuarios en el sistema.
- **Métodos**:
  - `AgregarUsuario`: Añade un nuevo usuario a la lista.
  - `EliminarUsuario`: Elimina un usuario de la lista por su correo.
  - `ImprimirLista`: Imprime todos los usuarios en la lista.
  - `BuscarUsuario`: Busca un usuario por su correo.
  - `DevolverDatosUsuario`: Devuelve los datos de un usuario por su correo.
  - `DevolverLista`: Devuelve la lista de usuarios.
  - `RecibirSolicitud`: Recibe una solicitud de amistad.
  - `DevolverDatosPor_ID`: Devuelve los datos de un usuario por su ID.
  - `graph`: Genera una representación gráfica de la lista.

### `ListaSolicitudes`

- **Descripción**: Administra una lista de solicitudes de amistad.
- **Métodos**:
  - `AgregarSolicitud`: Añade una nueva solicitud de amistad.
  - `EliminarSolicitud`: Elimina una solicitud de amistad por correo.
  - `ImprimirSolicitudes`: Imprime todas las solicitudes en la lista.
  - `DevolverLista`: Devuelve la lista de solicitudes.
  - `graph`: Genera una representación gráfica de la lista.

### `Pila`

- **Descripción**: Administra una pila de solicitudes de amistad.
- **Métodos**:
  - `Apilar`: Añade una solicitud a la pila.
  - `Desapilar`: Elimina la solicitud en la cima de la pila.
  - `ImprimirSolicitudes`: Imprime todas las solicitudes en la pila.
  - `DevolverPila`: Devuelve la pila de solicitudes.
  - `EliminarElementoDePila`: Elimina un elemento específico de la pila.
  - `GraficarPila`: Genera una representación gráfica de la pila.

### `Matriz`

- **Descripción**: Representa una matriz utilizando una lista doblemente enlazada.
- **Métodos**:
  - `insert`: Inserta un nuevo nodo en la matriz.
  - `existeNodo`: Verifica si un nodo existe en la matriz.
  - `print`: Imprime la matriz.
  - `graph`: Genera una representación gráfica de la matriz.
  - `eliminarNodo`: Elimina un nodo específico de la matriz.
  - `obtenerNodo`: Obtiene un nodo específico de la matriz.
  - `eliminarEncabezadoFila`: Elimina el encabezado de una fila.
  - `eliminarEncabezadoColumna`: Elimina el encabezado de una columna.

### `ListaPublicaciones`

- **Descripción**: Administra una lista de publicaciones.
- **Métodos**:
  - `AgregarPublicacion`: Añade una nueva publicación a la lista.
  - `EliminarPublicaciones`: Elimina publicaciones por correo.
  - `DevolverListaPublicaciones`: Devuelve la lista de publicaciones.
  - `ImprimirPublicaciones`: Imprime todas las publicaciones.
  - `graph`: Genera una representación gráfica de la lista de publicaciones.

### `ListaPersonalPublicaciones`

- **Descripción**: Administra las publicaciones personales de un usuario.
- **Métodos**:
  - `AgregarPublicacion`: Añade una publicación a la lista personal.
  - `EliminarPublicaciones`: Elimina publicaciones por correo.
  - `DevolverListaPublicaciones`: Devuelve la lista de publicaciones personales.
  - `VaciarLista`: Vacía la lista de publicaciones personales.
  - `graph`: Genera una representación gráfica de la lista personal de publicaciones.

### `ListaAmigos`

- **Descripción**: Administra la lista de amigos de un usuario.
- **Métodos**:
  - `AgregarAmigo`: Añade un nuevo amigo a la lista.
  - `EliminarAmigo`: Elimina un amigo de la lista por correo.
  - `ImprimirAmigos`: Imprime todos los amigos en la lista.
  - `VerificarEnListaAmigos`: Verifica si un correo está en la lista de amigos.
  - `DevolverLista`: Devuelve la lista de amigos.

### `ListaCantidadAmigos`

- **Descripción**: Administra una lista de conteo de amigos.
- **Métodos**:
  - `AgregarCifra`: Añade un nuevo conteo de amigos.
  - `VaciarLista`: Vacía la lista de conteo de amigos.
  - `DevolverLista`: Devuelve la lista de conteo de amigos.
  - `OrdenarListaPorCantidad`: Ordena la lista por cantidad de amigos.
  - `MostrarTop5`: Muestra los top 5 usuarios con más amigos.

### `ListaCantidadPublicaciones`

- **Descripción**: Administra una lista de conteo de publicaciones.
- **Métodos**:
  - `AgregarCifra`: Añade un nuevo conteo de publicaciones.
  - `VaciarLista`: Vacía la lista de conteo de publicaciones.
  - `DevolverLista`: Devuelve la lista de conteo de publicaciones.
  - `OrdenarListaPorCantidad`: Ordena la lista por cantidad de publicaciones.
  - `MostrarTop5`: Muestra los top 5 usuarios con más publicaciones.

## Estructuras

### `RegistrarUsuario`

- **Descripción**: Representa un usuario registrado en el sistema.
- **Atributos**:
  - `id`: Identificador del usuario.
  - `VerPublicaciones`: Lista de publicaciones del usuario.
  - `MisAmigos`: Lista de amigos del usuario.
  - `Nombres`, `Apellidos`, `FechaNacimiento`, `Correo`, `Contra`: Información personal del usuario.
  - `SolicitudesEnviadas`: Lista de solicitudes de amistad enviadas.
  - `SolicitudesRecibidas`: Pila de solicitudes de amistad recibidas.
  - `Siguiente`: Puntero al siguiente usuario en la lista.

### `SolicitudDeAmistad`

- **Descripción**: Representa una solicitud de amistad.
- **Atributos**:
  - `Correo`: Correo del usuario que envía la solicitud.
  - `Siguiente`: Puntero a la siguiente solicitud en la lista.

### `Nodo`

- **Descripción**: Representa un nodo en una matriz.
- **Atributos**:
  - `i`, `j`: Posiciones en la matriz.
  - `data`: Datos almacenados en el nodo.
  - `arriba`, `abajo`, `izq`, `dcha`: Punteros a nodos vecinos en la matriz.

### `NodoPublicacion`

- **Descripción**: Representa una publicación en la lista de publicaciones.
- **Atributos**:
  - `Correo`: Correo del usuario que hizo la publicación.
  - `Contenido`: Contenido de la publicación.
  - `Fecha`, `Hora`: Fecha y hora de la publicación.
  - `Siguiente`, `Anterior`: Punteros a los nodos vecino en la lista de publicaciones.

### `Amigos`

- **Descripción**: Representa un amigo en la lista de amigos.
- **Atributos**:
  - `Correo`: Correo del amigo.
  - `Siguiente`: Puntero al siguiente amigo en la lista.

### `NodoContadorAmigos`

- **Descripción**: Representa un nodo en la lista de conteo de amigos.
- **Atributos**:
  - `Correo`: Correo del usuario.
  - `Cantidad`: Número de amigos del usuario.
  - `Siguiente`: Puntero al siguiente nodo en la lista.

### `NodoContadorPublicaciones`

- **Descripción**: Representa un nodo en la lista de conteo de publicaciones.
- **Atributos**:
  - `Correo`: Correo del usuario.
  - `Cantidad`: Número de publicaciones del usuario.
  - `Siguiente`: Puntero al siguiente nodo en la lista.

  ### `Grafo`

- **Descripción**: Representa vertices de amistad.
- **Atributos**:
  - SuperVertice* primero = nullptr;
    SuperVertice* ultimo = nullptr;

    Grafo();
    ~Grafo();

    void insertar(Usuario* emisor, Usuario* receptor);
    void buscarRecomendaciones(SuperVertice* amigos, ListaUsuarios* usuarios);

    SuperVertice* amistedesEmisor(Usuario* emisor);

    bool buscarAmistad(Usuario* emisor, Usuario* receptor);

    void generarSugerencias(Grafo* general, SuperVertice* amigos);
    void generarGrafo();
    void listaAdyacencia();

# Árboles B, AVL y BST

## Árbol B
- **Estructura**: Árbol balanceado de búsqueda, ideal para almacenamiento en disco.
- **Nodos**: Cada nodo puede tener múltiples claves y nodos hijos.
- **Propiedades**:
  - Todos los nodos hoja están al mismo nivel.
  - Los nodos internos tienen entre `m/2` y `m` hijos (donde `m` es el orden del árbol).
  - Las claves de un nodo están ordenadas.
- **Inserción/Eliminación**: Se dividen/fusionan nodos si exceden o quedan por debajo de los límites.

## Árbol AVL
- **Estructura**: Árbol binario de búsqueda (BST) balanceado por altura.
- **Nodos**: Cada nodo tiene una clave y 2 hijos (izquierdo y derecho).
- **Propiedades**:
  - La diferencia de altura entre los subárboles de un nodo es como máximo 1.
- **Inserción/Eliminación**: Requiere rotaciones (simple/doble) para mantener el balance.

## Árbol BST
- **Estructura**: Árbol binario de búsqueda sin balance.
- **Nodos**: Cada nodo tiene una clave y 2 hijos (izquierdo y derecho).
- **Propiedades**:
  - Para cada nodo, los valores del subárbol izquierdo son menores y los del derecho mayores.
- **Inserción/Eliminación**: No garantiza balance, por lo que puede degenerar en una lista enlazada en el peor caso.


