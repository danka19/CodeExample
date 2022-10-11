#ifndef PROFILEMODEL_H
#define PROFILEMODEL_H
#include "basemodel.h"
#include <QString>
#include <QListWidgetItem>
#include <QLabel>
#include <QVBoxLayout>

class ProfileModel: public QListWidgetItem{
public:

    //init
    ProfileModel();
    ProfileModel(int id, QString name);
    ProfileModel(int id, QString name, int scansCount);

    //getters
    int getId();
    QString getName();
    int getScansCount();

    //setters
    void setId(int id);
    void setName(QString name);
    void setScansCount(int scansCount);

private:
    int id;
    QString name;
    int scansCount;
};

#endif // PROFILEMODEL_H
