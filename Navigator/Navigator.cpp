#include "Navigator.h"
#include "../ScanLab_Cropping/ScreensFactory.h"

#include <QLinkedList>

using namespace screens;

Navigator::Navigator(
        QStackedWidget *container,
        BaseScreensFactory *screensFactory,
        ProjectInfoModel *projectInfoModel
) {
    qDebug("create navigator");
    this->screensFactory = screensFactory;
    this->currentContainer = container;
    qDebug("create start fragment");
    BaseFragment* startFragment = getStartScreen();

    startFragment->setData(projectInfoModel);
    //передать моделть
    qDebug("append start fragment");
    this->stack.append(startFragment);

    qDebug("add widget");
    currentContainer->addWidget(stack.last());
    currentContainer->setCurrentIndex(0);
}

Navigator::~Navigator() {
}

void Navigator::navigateTo(QString tag) {
    qDebug("Navigator navigateTo");
    BaseFragment *newFragment = this->screensFactory->create(tag);
    stack.last()->onPause();
    disconnectFragment(stack.last());
    connectFragment(newFragment);
    stack.append(newFragment);
    currentContainer->addWidget(newFragment);
    currentContainer->setCurrentWidget(newFragment);
}

void Navigator::back() {
    qDebug("Navigator back");
    currentContainer->removeWidget(stack.last());
    delete stack.last();
    stack.removeLast();
    connectFragment(stack.last());
    stack.last()->onResume();
    currentContainer->setCurrentWidget(stack.last());
}

void Navigator::replace(QString tag) {
    qDebug("Navigator replace");
    BaseFragment *newFragment = this->screensFactory->create(tag);
    currentContainer->removeWidget(stack.last());
    delete stack.last();
    stack.removeLast();
    connectFragment(newFragment);
    currentContainer->addWidget(newFragment);
}

void Navigator::newRootScreen(QString tag) {
    qDebug("Navigator newRootScreen");
    BaseFragment *newFragment = this->screensFactory->create(tag);
    disconnectFragment(stack.last());
    stack.clear();
    connectFragment(newFragment);
    for(int i = currentContainer->count(); i >= 0; i--)
    {
        QWidget* widget = currentContainer->widget(i);
        currentContainer->removeWidget(widget);
        widget->deleteLater();
    }
    currentContainer->addWidget(newFragment);
    stack.append(newFragment);
}

void Navigator::backWhithData(BaseModel* model) {
    back();
    stack.last()->setData(model);
}

void Navigator::navigateWhithData(QString tag, BaseModel* model) {
    navigateTo(tag);
    stack.last()->setData(model);
}

void Navigator::closeWindow()
{
    emit closeWindowNavigator();
}

BaseFragment* Navigator::getStartScreen() {
    return createAndConnect(this->screensFactory->createStart());
}

void Navigator::connectFragment(BaseFragment *fragment) {
    qDebug("Navigator connect slots");
    connect(fragment, &BaseFragment::back, this, &Navigator::back);
    connect(fragment, &BaseFragment::replace, this, &Navigator::replace);
    connect(fragment, &BaseFragment::navigateTo, this, &Navigator::navigateTo);
    connect(fragment, &BaseFragment::newRootScreen, this, &Navigator::newRootScreen);
    connect(fragment, &BaseFragment::backWhithData, this, &Navigator::backWhithData);
    connect(fragment, &BaseFragment::navigateWhithData, this, &Navigator::navigateWhithData);
    connect(fragment, &BaseFragment::closeWindow, this, &Navigator::closeWindow);
}


void Navigator::disconnectFragment(BaseFragment *fragment) {
    qDebug("Navigator disconnect slots");
    disconnect(fragment, &BaseFragment::back, this, &Navigator::back);
    disconnect(fragment, &BaseFragment::replace, this, &Navigator::replace);
    disconnect(fragment, &BaseFragment::navigateTo, this, &Navigator::navigateTo);
    disconnect(fragment, &BaseFragment::newRootScreen, this, &Navigator::newRootScreen);
    disconnect(fragment, &BaseFragment::backWhithData, this, &Navigator::backWhithData);
    disconnect(fragment, &BaseFragment::navigateWhithData, this, &Navigator::navigateWhithData);
    disconnect(fragment, &BaseFragment::closeWindow, this, &Navigator::closeWindow);
}

BaseFragment* Navigator::createAndConnect(QString tag) {
    BaseFragment *fragment = this->screensFactory->create(tag);
    qDebug("Navigator create screen");
    connectFragment(fragment);
    return fragment;
}
