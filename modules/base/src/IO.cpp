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

#define IO_PATH		QDir::currentPath() + "/rls/"
#define elif		else if

bool eliminarServidor(const QString &sServidor)
{
    return QFile::remove(IO_PATH + sServidor + ".rls");
}

QString leerDirectorio()
{
    QFile dir(IO_PATH + "directorio");
    if(!dir.exists()) return "";
    elif(dir.open(QIODevice::ReadOnly)) return QString(dir.readAll());
}

bool guardarDirectorio(const QString &sDirectorio)
{
    QDir d(IO_PATH);
    if(!d.exists() && !d.mkdir(IO_PATH)) return false;

    QFile f(IO_PATH + "directorio");

    if(f.open(QIODevice::WriteOnly))
    {
        QTextStream os(&f);
        os << sDirectorio;

        return true;
    }
    else return false;
}

bool guardarServidor(const QString &sServidor)
{
    QDir d(IO_PATH);
    if(!d.exists() && !d.mkdir(IO_PATH)) return false;
    
    QFile f(IO_PATH + sServidor + ".rls");
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

void leerServidores(QStringList &servidores)
{
    QDir d(IO_PATH);
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

bool configurarJuego(QString sDirectorio, QString sServidor)
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
