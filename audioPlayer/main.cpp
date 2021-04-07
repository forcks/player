#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "audiowork.h"
#include "audiomodel.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<AudioModel>("audioM",1,0,"AudioModel");
    qmlRegisterUncreatableType<AudioWork>("audioM",1,0,"AudioWork",QStringLiteral("Something"));

    QQmlApplicationEngine engine;

    AudioWork audioWork;
    engine.rootContext()->setContextProperty(QStringLiteral("audioWork"),&audioWork);

    //const QUrl url(QStringLiteral("qrc:/main.qml"));

    QString nameStartQmlWindow;
    if(audioWork.checkFilePathAudio())
        nameStartQmlWindow = "qrc:/main.qml";
    else
        nameStartQmlWindow = "qrc:/selectPathToFolderForAudio.qml";

    const QUrl url(nameStartQmlWindow);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
