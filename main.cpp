#include "mainscene.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    MainScene* view = new MainScene;
    view->show();

    return app.exec();
}

