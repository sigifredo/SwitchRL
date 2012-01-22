
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
#    include<windows.h>
#endif

// GfifDev
#include<GUIQtWin.hpp>
#include<GUIAbout.hpp>

#ifndef elif
#  define elif	else if
#endif

Principal::Principal(QWidget * pPadre):
    QWidget(pPadre)
{
    QGridLayout * _pLayout = new QGridLayout(this);

    _sDirectorio = leerDirectorio();
    QString sDir = _sDirectorio==""?"<directorio>":_sDirectorio;

    _pDirectorio = new Label("WoW: " + sDir, this);
    _pAyuda = new QPushButton("?", this);
    _pServidores = new QListWidget(this);
    _pAgregarServidor = new QPushButton("Agregar", this);
    _pEliminarServidor = new QPushButton("Eliminar", this);
    _pSpacer = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);
    _pIniciarJuego = new QPushButton("Iniciar", this);

    connect(_pAyuda, SIGNAL(clicked()), this, SLOT(acercaDe()));
    connect(_pAgregarServidor, SIGNAL(clicked()), this, SLOT(agregar()));
    connect(_pEliminarServidor, SIGNAL(clicked()), this, SLOT(eliminar()));
    connect(_pIniciarJuego, SIGNAL(clicked()), this, SLOT(iniciarJuego()));
    connect(_pDirectorio, SIGNAL(doubleClick()), this, SLOT(cambiarDirectorio()));

    _pLayout->addWidget(_pDirectorio, 0, 0, 1, 3);
    _pLayout->addWidget(_pAyuda, 0, 3, 1, 1);
    _pLayout->addWidget(_pServidores, 1, 0, 1, 4);
    _pLayout->addWidget(_pAgregarServidor, 2, 0, 1, 1);
    _pLayout->addWidget(_pEliminarServidor, 2, 1, 1, 1);
    _pLayout->addItem(_pSpacer, 2, 2, 1, 1);
    _pLayout->addWidget(_pIniciarJuego, 2, 3, 1, 1);

    _pServidores->setAlternatingRowColors(true);
    llenarLista();

    // Transparencia (Solo Windows 7)
#ifdef _WIN32
    // verificamos que estÃ© activada la transparencia en el sistema
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
    QString sDescripcion = QString::fromUtf8("SwitchRL es una utilidad creada para todas aquellas personas que juegan en mas de un servidor de WoW. El programa administra de forma automática el archivo realmlist para que el jugador no se tenga que preocupar por editar archivos para cambiar de servidor. Este programa es distribuido bajo lidencia GPL3 no hace parte de Blizzard, ni modifica ninguna funcionalidad del juego.");
    GUI::About ab("SwitchRL", "0.5.5", sDescripcion);
    ab.exec();
}

void Principal::agregar()
{
    QInputDialog id(this);
    id.setLabelText("realmlist:");
    if(id.exec() == QDialog::Accepted && id.textValue().trimmed() != "")
    {
        if(!guardarServidor(id.textValue().trimmed()))
        {
            QMessageBox::critical(this, "Error", "Ha ocurrido un problema al intentar guardar el servidor. Es posible que se requieran privilegios de administrador.");
        }
    }

    _pServidores->clear();
    llenarLista();
}

void Principal::eliminar()
{
    if(_pServidores->currentItem() != NULL && _pServidores->currentItem()->text() != "" && !eliminarServidor(_pServidores->currentItem()->text()))
        QMessageBox::critical(this, "Error", "Ha ocurrido un problema al intentar eliminar el servidor. Es posible que se requieran privilegios de administrador.");

    _pServidores->clear();
    llenarLista();
}

void Principal::iniciarJuego()
{
    if(_pServidores->currentItem() != NULL && _pServidores->currentItem()->text() != "" && configurarJuego(_sDirectorio, _pServidores->currentItem()->text()))
    {
        #ifdef _WIN32
        QString sComando = (_sDirectorio.replace("/", "\\") + "\\Wow.exe");
        ShellExecute(NULL, TEXT("open"), TEXT(sComando.toStdString().c_str()), NULL, NULL, SW_SHOWNORMAL);
        #elif defined(linux)
        QString sComando = "wine " + _sDirectorio + "/Wow.exe &";
        system(sComando.toStdString().c_str());
        #endif
    }
    elif(_pServidores->currentItem() != NULL)
        QMessageBox::critical(this, "Error", "Ha ocurrido un problema al intentar escribir el archivo realmlist.wtf. Es posible que se requieran privilegios de administrador ó que el idioma del juego no se encuentra soportado en la actualidad.");
}

void Principal::llenarLista()
{
    QStringList servidores;
    leerServidores(servidores);

    _pServidores->addItems(servidores);
}

void Principal::cambiarDirectorio()
{
    QFileDialog fd(this);
    fd.setFileMode(QFileDialog::DirectoryOnly);

    if(fd.exec() == QDialog::Accepted)
    {
        _sDirectorio = fd.selectedFiles().at(0).trimmed();
        _pDirectorio->setText("WoW: " + _sDirectorio);

        if(!guardarDirectorio(_sDirectorio))
            QMessageBox::critical(this, "Error", "Ha ocurrido un problema al intentar guardar el directorio. Es posible que se requieran privilegios de administrador.");
    }
}
