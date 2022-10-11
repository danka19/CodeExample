#include "projectcreationscreen.h"
#include <QDesktopWidget>
#include <QException>


ProjectCreationScreen::ProjectCreationScreen(QWidget *parent)
    : QMainWindow(parent)
{


}

ProjectCreationScreen::~ProjectCreationScreen() {
    this->projectInfoModel = nullptr;
    delete container;
    delete navigator;
    delete factory;
}

void ProjectCreationScreen::setScanLabCroppingMain(ScanLabCroppingMain *scanLabCroppingMain)
{
    this->scanLabCroppingMain = scanLabCroppingMain;
}

void ProjectCreationScreen::init()
{
    try {
        qDebug("create main window");

        container = new QStackedWidget;
        container->setObjectName("ui");

        this->factory = new ScreensFactory;

        //model creation
        projectInfoModel = new ProjectInfoModel();
        projectInfoModel->setScanLabCroppingMain(this->scanLabCroppingMain);

        this->navigator = new Navigator(
                    this->container,
                    this->factory,
                    this->projectInfoModel
        );

        connect(navigator, &Navigator::closeWindowNavigator, this, &ProjectCreationScreen::closeWindow);

        container->setObjectName("window");

        this->setWindowTitle("Создание проекта");

        this->resize(600,400);
        this->setCentralWidget(container);


    } catch (std::exception& e) {
        qDebug("%s", e.what());
    }
}

void ProjectCreationScreen::closeWindow()
{
    emit closing();
    this->close();
}
