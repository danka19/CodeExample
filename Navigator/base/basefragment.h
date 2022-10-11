#ifndef BASEFRAGMENT_H
#define BASEFRAGMENT_H

#include <QFrame>
#include <QVBoxLayout>
#include <QWidget>

#include "../ScanLab_Cropping/Navigator/model/basemodel.h"
#include "../ScanLab_Cropping/Navigator/model/profilemodel.h"
/**
 * @brief The BaseFragment class
 *
 * Базовый фрагмент приложения.
 */
class BaseFragment: public QFrame {
    Q_OBJECT

signals:
    void back();
    void backWhithData(BaseModel* model);

    void navigateTo(QString tag);
    void navigateWhithData(QString tag, BaseModel* model);

    void newRootScreen(QString tag);
    void replace(QString tag);

    void closeWindow();

protected:
    void clearList(QLayout *list);
public:
    BaseFragment();
    virtual ~BaseFragment();

    virtual void onPause();
    virtual void onResume();
    virtual void setData(BaseModel* model);
};

#endif // BASEFRAGMENT_H
