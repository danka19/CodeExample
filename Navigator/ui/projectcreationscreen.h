#ifndef PROJECTCREATIONSCREEN_H
#define PROJECTCREATIONSCREEN_H

#include <QMainWindow>
#include <QStackedWidget>
#include "..//ScanLab_Cropping/Navigator/Navigator.h"
#include "..//ScanLab_Cropping/ScreensFactory.h"
#include "..//ScanLab_Cropping/Navigator/base/basefragment.h"


class ProjectCreationScreen : public QMainWindow
{
    Q_OBJECT

private:
    QStackedWidget *container;
    Navigator *navigator;
    BaseScreensFactory *factory;
    ScanLabCroppingMain *scanLabCroppingMain;

public:
    ProjectCreationScreen(QWidget *parent = nullptr);
    ~ProjectCreationScreen();
    void setScanLabCroppingMain(ScanLabCroppingMain *scanLabCroppingMain);
    ProjectInfoModel *projectInfoModel;
    void init();

public slots:
    void closeWindow();

signals:
    void closing();
};

#endif // PROJECTCREATIONSCREEN_H
