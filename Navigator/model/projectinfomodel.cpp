#include "projectinfomodel.h"

ProjectInfoModel::ProjectInfoModel()
{
    this->geometryType = 0;
    this->cameraUse = true;
    this->internalCameraController = true;
}

void ProjectInfoModel::setScanLabCroppingMain(ScanLabCroppingMain *scanLabCroppingMain)
{
    this->scanLabCroppingMain = scanLabCroppingMain;
}

void ProjectInfoModel::setProfile(ProfileModel *model)
{
    this->profile = model;
}

void ProjectInfoModel::setPath(QString path)
{
    this->path = path;
}

void ProjectInfoModel::setGeometryX(float x)
{
    this->geometryX = x;
}

void ProjectInfoModel::setGeometryY(float y)
{
    this->geometryY = y;
}

void ProjectInfoModel::setGeometryType(int type)
{
    //////////////////////////////////////
    /// Geometry types:                ///
    /// 0 - optimaV,                   ///
    /// 1 - optima_plan(v),            ///
    /// 2 - optima_plan(flat),         ///
    /// 3 - optima_plan(flat, 2 pages) ///
    //////////////////////////////////////

    this->geometryType = type;
}

void ProjectInfoModel::setIsCameraUse(bool isCameraUse)
{
    this->cameraUse = isCameraUse;
}

void ProjectInfoModel::setIsInternalCameraController(bool isInternalCameraController)
{
    this->internalCameraController = isInternalCameraController;
}

void ProjectInfoModel::setBacksidePostfixUse(bool backsidePostfixUse)
{
    this->backsidePostfixUse = backsidePostfixUse;
}

void ProjectInfoModel::setBackSidePostfixText(QString text)
{
    this->backsidePostfixText = text;
}

void ProjectInfoModel::setBacksidePostfixType(int type)
{
    this->backsidePostfixType = type;
}

void ProjectInfoModel::setFirstPageNum(int num)
{
    this->firstPageNum = num;
}

void ProjectInfoModel::setPrefix(QString prefix)
{
    this->prefix = prefix;
}

void ProjectInfoModel::setPageNumType(int type)
{
    this->pageNumType = type;
}

void ProjectInfoModel::setIsBtnScan(bool btn)
{
    this->btnScan = btn;
}

ScanLabCroppingMain *ProjectInfoModel::getScanLabCroppingMain()
{
    return this->scanLabCroppingMain;
}

ProfileModel* ProjectInfoModel::getProfile()
{
    return this->profile;
}

QString ProjectInfoModel::getPath()
{
    return this->path;
}

float ProjectInfoModel::getGeometryX()
{
    return this->geometryX;
}

float ProjectInfoModel::getGeometryY()
{
    return this->geometryY;
}

bool ProjectInfoModel::isCameraUse()
{
    return this->cameraUse;
}

bool ProjectInfoModel::isInternalCameraController()
{
    return this->internalCameraController;
}

bool ProjectInfoModel::isBackSidePostfixUse()
{
    return this->backsidePostfixUse;
}

QString ProjectInfoModel::getBackSidePostfixText()
{
    return this->backsidePostfixText;
}

int ProjectInfoModel::getBacksidePostfixType()
{
    return this->backsidePostfixType;
}

int ProjectInfoModel::getFirstPageNum()
{
    return this->firstPageNum;
}

QString ProjectInfoModel::getPrefix()
{
    return this->prefix;
}

int ProjectInfoModel::getPageNumType()
{
    return this->pageNumType;
}

bool ProjectInfoModel::isBtnScan()
{
    return this->btnScan;
}

int ProjectInfoModel::getGeometryType()
{
    return this->geometryType;
}
