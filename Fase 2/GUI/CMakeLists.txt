cmake_minimum_required(VERSION 3.16)

project(GUI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ../Estructuras/AVLtree.h
        ../Estructuras/AVLtree.cpp
        ../Estructuras/TreeUsuario.cpp
        ../Estructuras/ListaPosts.h
        ../Estructuras/ListaPosts.cpp
        ../Estructuras/ListaABB.cpp
        ../Estructuras/ListaABB.cpp
        ../Estructuras/NodoABB.cpp
        ../Estructuras/NodoABB.h
        ../Estructuras/NodoPosts.cpp
        ../Estructuras/NodoPosts.h
        ../Estructuras/TreeUsuario.h
        ../Estructuras/ABBtree.h
        ../Estructuras/ABBtree.cpp
        ../Estructuras/TreePost.h
        ../Estructuras/TreePost.cpp
        ../Estructuras/PostSimple.cpp
        ../Estructuras/PostSimple.h
        ../Estructuras/tinyfiledialogs/tinyfiledialogs.h
        ../Estructuras/tinyfiledialogs/tinyfiledialogs.c
        ../Estructuras/ListaUsuarios.h
        ../Estructuras/ListaUsuarios.cpp
        ../Estructuras/ArbolB.cpp
        ../Estructuras/ArbolB.h
        ../Estructuras/Comentarios.cpp
        ../Estructuras/Comentarios.h
        ../Estructuras/NodoB.cpp
        ../Estructuras/NodoB.h
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/headers/Publicacion.h"
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/headers/NodoStories.h"
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/Usuario.cpp"
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/headers/Usuario.h"
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/Estructuras/EnlazadaDoble.cpp"
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/Estructuras/Matriz.cpp"
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/Estructuras/Matriz.h"
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/headers/NodoUser.h"
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/UsuarioA.cpp"
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/headers/UsuarioA.h"
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/Estructuras/SimpleAmistad.cpp"
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/Estructuras/Pila.cpp"
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/headers/NodoAmistad.h"
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/headers/Amistad.h"
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 3/Estructuras/Grafo.h"
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 3/Estructuras/Grafo.cpp"
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 3/Estructuras/SuperVertice.h"
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 3/Estructuras/SuperVertice.cpp"
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 3/Estructuras/Vertice.h"
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 3/Estructuras/Vertice.cpp"
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 3/Estructuras/Block.h"
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 3/Estructuras/Block.cpp"
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(GUI
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}


    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET GUI APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(GUI SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(GUI
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(GUI PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.GUI)
endif()
set_target_properties(GUI PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS GUI
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(GUI)
endif()
