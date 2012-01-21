
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
