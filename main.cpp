#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "dialitem.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<DialItem>("IVIControls", 1, 0, "DialItem");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
