/*
    Este programa es una utilidad libre para la administraci�n sencilla de servidores para WoW.
    Copyright (C) 2012 Sigifredo Escobar G�mez (sigifredo89@gmail.com).

    Este programa es software libre: usted puede redistribuirlo y/o modificarlo
    bajo los t�rminos de la Licencia P�blica General GNU publicada
    por la Fundaci�n para el Software Libre, ya sea la versi�n 3
    de la Licencia, o (a su elecci�n) cualquier versi�n posterior.

    Este programa se distribuye con la esperanza de que sea útil, pero
    SIN GARANT�A ALGUNA; ni siquiera la garant�a impl�cita
    MERCANTIL o de APTITUD PARA UN PROP�SITO DETERMINADO.
    Consulte los detalles de la Licencia P�blica General GNU para obtener
    una informaci�n m�s detallada.

    Deber� haber recibido una copia de la Licencia P�blica General GNU
    junto a este programa.
    En caso contrario, consulte <http://www.gnu.org/licenses/>.
*/

// Own
#include<IO.hpp>
#include<Label.hpp>
#include<Principal.hpp>

// Qt
#include<QDebug>
#include<QFileDialog>
#include<QGridLayout>
#include<QInputDialog>
#include<QListWidget>
#include<QMessageBox>
#include<QPushButton>

// Windows
#ifdef _WIN32
#  include<windows.h>
#endif

// GfifDev
#include<GUIQtWin.hpp>
#include<GUIAbout.hpp>

#ifndef elif
#  define elif		else if
#endif

Principal::Principal(QWidget * pPadre):
    QWidget(pPadre)
{
    QGridLayout * _pLayout = new QGridLayout(this);

    // Secci�n de directorios
    {
        _pDirectorio = new QLabel("Directorio:", this);
        _pDirectorios = new QListWidget(this);
        _pAgregarDirectorio = new QPushButton(QIcon(":/SwitchRL/agregar.png"), "", this);
        _pEliminarDirectorio = new QPushButton(QIcon(":/SwitchRL/eliminar.png"), "", this);
    }

    // Secci�n de servidores
    {
        _pServidor = new QLabel("Servidor:", this);
        _pServidores = new QListWidget(this);
        _pAgregarServidor = new QPushButton(QIcon(":/SwitchRL/agregar.png"), "", this);
        _pEliminarServidor = new QPushButton(QIcon(":/SwitchRL/eliminar.png"), "", this);
    }

    _pIniciarJuego = new QPushButton("Iniciar", this);
    _pSpacer = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);
    _pAyuda = new QPushButton("?", this);

    connect(_pAyuda, SIGNAL(clicked()), this, SLOT(acercaDe()));
    connect(_pAgregarDirectorio, SIGNAL(clicked()), this, SLOT(agregarDirectorio()));
    connect(_pEliminarDirectorio, SIGNAL(clicked()), this, SLOT(eliminarDirectorio()));
    connect(_pAgregarServidor, SIGNAL(clicked()), this, SLOT(agregarServidor()));
    connect(_pEliminarServidor, SIGNAL(clicked()), this, SLOT(eliminarServidor()));
    connect(_pIniciarJuego, SIGNAL(clicked()), this, SLOT(iniciarJuego()));

    _pLayout->addWidget(_pDirectorio, 0, 0, 1, 3);
    _pLayout->addWidget(_pDirectorios, 1, 0, 2, 3);
    _pLayout->addWidget(_pAgregarDirectorio, 1, 4, 1, 1);
    _pLayout->addWidget(_pEliminarDirectorio, 2, 4, 1, 1);

    _pLayout->addWidget(_pServidor, 3, 0, 1, 3);
    _pLayout->addWidget(_pServidores, 4, 0, 2, 3);
    _pLayout->addWidget(_pAgregarServidor, 4, 4, 1, 1);
    _pLayout->addWidget(_pEliminarServidor, 5, 4, 1, 1);

    _pLayout->addWidget(_pIniciarJuego, 6, 0, 1, 1);
    _pLayout->addItem(_pSpacer, 6, 1, 1, 1);
    _pLayout->addWidget(_pAyuda, 6, 2, 1, 1);

    _pDirectorios->setAlternatingRowColors(true);
    _pServidores->setAlternatingRowColors(true);
    llenarListaDirectorios();
    llenarListaServidores();

    // Transparencia (Solo Windows 7)
    #ifdef _WIN32
      // verificarmos que est� activada la transparencia en el sistema
      if(GUI::QtWin::isCompositionEnabled())
      {
          this->setAttribute(Qt::WA_TranslucentBackground);
          this->setAttribute(Qt::WA_NoSystemBackground, false);
          QPalette pal = this->palette();
          QColor bg = pal.window().color();
          bg.setAlpha(0x0);
          pal.setColor(QPalette::Window, bg);
          this->setPalette(pal);
          this->ensurePolished(); // workaround Oxygen filling the background
          this->setAttribute(Qt::WA_StyledBackground, false);

          GUI::QtWin::extendFrameIntoClientArea(this);
          this->setContentsMargins(0, 0, 0, 0);
      }
    #endif
}

void Principal::acercaDe()
{
    QString sDescription = "SwitchRL es una utilidad creada para todas aquellas personas que\njuegan en mas de un servidor de WoW. El programa administra de\nforma autom�tica el archivo \"realmlist.wtf\" para que el jugador no se\ntenga que preocupar por editar archivos para cambiar de servidor.\n\nEste programa es distribuido bajo licencia GPLv3, no hace parte de\nBlizzard, no modifica ninguna funcionalidad del juego.";
    GUI::About ab("SwitchRL", "1.0.1", sDescription);
    ab.exec();
}

void Principal::agregarDirectorio()
{
    QString sDirectorio;
    QFileDialog fd(this);
    fd.setFileMode(QFileDialog::Directory);

    if(fd.exec() == QDialog::Accepted && (sDirectorio = fd.selectedFiles().at(0).trimmed()) != "")
        if(!IO::guardarDirectorio(sDirectorio))
            QMessageBox::critical(this, "Error", "Ha ocurrido un problema al intentar guardar el directorio. Es posible que se requieran privilegios de administrador.");
        else
        {
            _pDirectorios->clear();
            llenarListaDirectorios();
        }
}

void Principal::eliminarDirectorio()
{
    if(_pDirectorios->currentItem() != NULL && _pDirectorios->currentItem()->text() != "" && !IO::eliminarDirectorio(_pDirectorios->currentItem()->text()))
        QMessageBox::critical(this, "Error", "Ha ocurrido un problema al intentar eliminar el directorio. Es posible que se requieran privilegios de administrador.");
    else
    {
        _pDirectorios->clear();
        llenarListaDirectorios();
    }
}

void Principal::agregarServidor()
{
    QInputDialog id(this);
    id.setLabelText("realmlist:");
    if(id.exec() == QDialog::Accepted && id.textValue().trimmed() != "")
        if(!IO::guardarServidor(id.textValue().trimmed()))
            QMessageBox::critical(this, "Error", "Ha ocurrido un problema al intentar guardar el servidor. Es posible que se requieran privilegios de administrador.");
        else
        {
            _pServidores->clear();
            llenarListaServidores();
        }
}

void Principal::eliminarServidor()
{
    if(_pServidores->currentItem() != NULL && _pServidores->currentItem()->text() != "" && !IO::eliminarServidor(_pServidores->currentItem()->text()))
        QMessageBox::critical(this, "Error", "Ha ocurrido un problema al intentar eliminar el servidor. Es posible que se requieran privilegios de administrador.");
    else
    {
        _pServidores->clear();
        llenarListaServidores();
    }
}

void Principal::iniciarJuego()
{
    QString sDir;

    if(_pServidores->currentItem() != NULL && _pDirectorios->currentItem() != NULL && _pDirectorios->currentItem()->text() != "" && IO::configurarJuego(sDir = IO::leerDirectorio(_pDirectorios->currentItem()->text()), _pServidores->currentItem()->text()))
    {
#ifdef _WIN32
        QString sComando = sDir.replace("/", "\\") + "\\Wow.exe";
        ShellExecute(NULL, TEXT("open"), TEXT(sComando.toStdString().c_str()), NULL, NULL, SW_SHOWNORMAL);
#elif defined(linux)
        QString sComando = "wine " + sDir + "/Wow.exe &";

        system(sComando.toStdString().c_str());
#endif
    }
    elif(_pServidores->currentItem() != NULL)
        QMessageBox::critical(this, "Error", "Ha ocurrido un problema al intentar escribir el archivo \"realmlist.wtf\". Es posible que se requieran privilegios de administrador o que el idioma del juego no se encuentre soportado en la actualidad.");
}

void Principal::llenarListaDirectorios()
{
    QStringList directorios;
    IO::leerDirectorios(directorios);

    _pDirectorios->addItems(directorios);
}

void Principal::llenarListaServidores()
{
    QStringList servidores;
    IO::leerServidores(servidores);

    _pServidores->addItems(servidores);
}
