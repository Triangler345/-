#include "mainscene.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QAudioOutput>
#include <QMediaPlayer>
int main(int argc, char *argv[])
{
   QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Dinosaur_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    Mainscene w;
    w.show();
    return a.exec();
}
