#include "profilemodel.h"


ProfileModel::ProfileModel()
{
}

ProfileModel::ProfileModel(int id_, QString name_): QListWidgetItem()
{
    this->id = id_;
    this->name = name_;
    this->scansCount = 0;
}

ProfileModel::ProfileModel(int id_, QString name_, int scansCount_): QListWidgetItem()
{
    this->id = id_;
    this->name = name_;
    this->scansCount = scansCount_;
}

int ProfileModel::getId()
{
    return this->id;
}

QString ProfileModel::getName()
{
    return this->name;
}

int ProfileModel::getScansCount()
{
    return this->scansCount;
}

void ProfileModel::setId(int id_)
{
    this->id = id_;

}

void ProfileModel::setName(QString name_)
{
   this->name = name_;
}

void ProfileModel::setScansCount(int scansCount_)
{
    this->scansCount = scansCount_;
}



