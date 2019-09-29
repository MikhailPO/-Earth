#ifndef MAINSCENE_H
#define MAINSCENE_H
#include <QGuiApplication>
#include <Qt3DExtras>
#include <Qt3DCore>
#include <Qt3DRender>
#include <QObject>
#include <QWidget>

class MainScene: public Qt3DExtras::Qt3DWindow
{
    Q_OBJECT
private:
    Qt3DCore::QEntity *createScene();
    Qt3DRender::QCamera *cameraMain;
    Qt3DCore::QTransform *objectTransform;

public:
    MainScene();

private slots:
    void Rotate();

};

#endif // MAINSCENE_H
