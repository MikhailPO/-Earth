#include "mainscene.h"

MainScene::MainScene()
{
    Qt3DCore::QEntity *rootEntity =  createScene();

     Qt3DCore::QEntity *objectEntity = new Qt3DCore::QEntity(rootEntity);
     Qt3DRender::QSceneLoader *sceneLoader = new Qt3DRender::QSceneLoader(objectEntity);
     sceneLoader->setSource(QUrl("qrc:/obj/earth.obj"));
     objectEntity->addComponent(sceneLoader);

     objectTransform = new Qt3DCore::QTransform(objectEntity);
     objectTransform->setScale(0.5f);
     objectEntity->addComponent(objectTransform);

    QTimer* timer = new QTimer();

    Qt3DRender::QCamera *cameraMain = this->camera();

    cameraMain->lens()->setPerspectiveProjection(60.0f, (float)this->width() / this->height(), 0.1f, 1000.0f);
    cameraMain->setPosition(QVector3D(0.0f, 0.0f, 140.0f));
    cameraMain->setViewCenter(QVector3D(0.0f, 0.0f, 0.0f));

    this->defaultFrameGraph()->setClearColor(QColor(0, 0, 0));
    this->setRootEntity(rootEntity);
    connect(timer,SIGNAL(timeout()),this,SLOT(Rotate()));
    timer->start(50);
}

void MainScene::Rotate() {
    objectTransform->setRotationY(objectTransform->rotationY()+10.0f);

}

Qt3DCore::QEntity *MainScene::createScene() {

    Qt3DCore::QEntity *resultEntity = new Qt3DCore::QEntity;

    return resultEntity;
}
