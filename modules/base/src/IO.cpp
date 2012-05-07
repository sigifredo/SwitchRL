/*
    Este programa es una utilidad libre para la administración sencilla de servidores para WoW.
    Copyright (C) 2012 Sigifredo Escobar Gómez.

    Este programa es software libre: usted puede redistribuirlo y/o modificarlo
    bajo los términos de la Licencia Pública General GNU publicada
    por la Fundación para el Software Libre, ya sea la versión 3
    de la Licencia, o (a su elección) cualquier versión posterior.

    Este programa se distribuye con la esperanza de que sea útil, pero
    SIN GARANTÍA ALGUNA; ni siquiera la garantía implícita
    MERCANTIL o de APTITUD PARA UN PROPÓSITO DETERMINADO.
    Consulte los detalles de la Licencia Pública General GNU para obtener
    una información más detallada.

    Debería haber recibido una copia de la Licencia Pública General GNU
    junto a este programa.
    En caso contrario, consulte <http://www.gnu.org/licenses/>.
*/

// Own
#include<IO.hpp>

// Qt
#include<QDir>
#include<QDebug>

#define RLS_PATH		QDir::currentPath() + "/rls/"
#define DIR_PATH		QDir::currentPath() + "/dir/"
#ifndef elif
#  define elif		else if
#endif

using namespace IO;

bool IO::eliminarDirectorio(const QString &sDirectorio)
{
    return QFile::remove(DIR_PATH + sDirectorio + ".dir");
}

bool IO::eliminarServidor(const QString &sServidor)
{
    return QFile::remove(RLS_PATH + sServidor + ".rls");
}

QString IO::leerDirectorio(const QString &directorio)
{
    QFile f(DIR_PATH + "/" + directorio + ".dir");
    
    if(f.exists() && f.open(QIODevice::ReadOnly))
    {
        QTextStream in(&f);
        return in.readAll();
    }
    else
        return QString();
}

void IO::leerDirectorios(QStringList &directorios)
{
    QDir d(DIR_PATH);
    if(!d.exists()) return;

    QStringList dirs = d.entryList();

    QStringListIterator it(dirs);

    while(it.hasNext())
    {
        QString directorio = it.next();
        
        if(directorio.right(4) == ".dir")
            directorios << directorio.left(directorio.length()-4);
    }
}

bool IO::guardarDirectorio(const QString &sDirectorio)
{
    QDir d(DIR_PATH);
    if(!d.exists() && !d.mkdir(DIR_PATH)) return false;

    QString::const_iterator it;
    if(sDirectorio.right(1) == "/")
        it = sDirectorio.end()-2;
    else
        it = sDirectorio.end()-1;

    QString sDir(".dir");
    for(; *it != '/'; sDir.prepend(*it--));

    QFile f(DIR_PATH + sDir);

    if(f.exists())
        return true;
    elif(f.open(QIODevice::WriteOnly))
    {
        QTextStream os(&f);
        os << sDirectorio;

        return true;
    }
    else return false;
}

bool IO::guardarServidor(const QString &sServidor)
{
    QDir d(RLS_PATH);
    if(!d.exists() && !d.mkdir(RLS_PATH)) return false;
    
    QFile f(RLS_PATH + sServidor + ".rls");
    if(f.exists())
        return true;
    elif(f.open(QIODevice::WriteOnly))
    {
        QTextStream os(&f);
        os << sServidor;
        return true;
    }
    else
        return false;
}

void IO::leerServidores(QStringList &servidores)
{
    QDir d(RLS_PATH);
    if(!d.exists()) return;

    QStringList serv = d.entryList();

    QStringListIterator it(serv);

    while(it.hasNext())
    {
        QString servidor = it.next();
        
        if(servidor.right(4) == ".rls")
            servidores << servidor.left(servidor.length()-4);
    }
}

bool IO::configurarJuego(QString sDirectorio, QString sServidor)
{
    #define N_IDIOMAS	2
    QString idiomas[] = { "esES", "esMX" };

    QDir d;
    sDirectorio += "/Data/";

    for(int i = 0; i < N_IDIOMAS; i++)
    {
        if(d.exists(sDirectorio + idiomas[i]))
        {
            sDirectorio += idiomas[i] + "/";
            break;
        }
    }

    QFile f(sDirectorio + "realmlist.wtf");

    if(f.open(QIODevice::WriteOnly))
    {
        QTextStream os(&f);
        os << QString("Set realmlist " + sServidor);

        return true;
    }
    else return false;
}
