
// Own
#include <Principal.hpp>

// Qt
#include <QApplication>
#include <QTextCodec>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QTextCodec * pCodec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(pCodec);
    QTextCodec::setCodecForCStrings(pCodec);
    QTextCodec::setCodecForLocale(pCodec);

#ifdef _WIN32
    app.addLibraryPath(QCoreApplication::applicationDirPath());
#endif

    Principal p;
    p.setWindowTitle("WSS");
    p.show();

    return app.exec();
}
