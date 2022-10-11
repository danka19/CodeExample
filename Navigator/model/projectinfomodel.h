#ifndef PROJECTINFOMODEL_H
#define PROJECTINFOMODEL_H

#include "basemodel.h"
//#include "profilemodel.h"
#include "..//ScanLab_Cropping/ScanLabCroppingMain.h"


class ProjectInfoModel: public BaseModel
{
public:
    ProjectInfoModel();

    //setters
    void setScanLabCroppingMain(ScanLabCroppingMain *scanLabCroppingMain);

    void setProfile(ProfileModel *model);
    void setPath(QString path);
    void setGeometryX(float x);
    void setGeometryY(float y);
    void setGeometryType(int type);
    void setIsCameraUse(bool isCameraUse);
    void setIsInternalCameraController(bool isInternalCameraController);
    void setBacksidePostfixUse(bool backsidePostfixUse);
    void setBackSidePostfixText(QString text);
    void setBacksidePostfixType(int type);
    void setFirstPageNum(int num);
    void setPrefix(QString prefix);
    void setPageNumType(int type);
    void setIsBtnScan(bool btn);

    //getters
    ScanLabCroppingMain* getScanLabCroppingMain();

    ProfileModel* getProfile();
    QString getPath();
    float getGeometryX();
    float getGeometryY();
    int getGeometryType();
    bool isCameraUse();
    bool isInternalCameraController();
    bool isBackSidePostfixUse();
    QString getBackSidePostfixText();
    int getBacksidePostfixType();
    int getFirstPageNum();
    QString getPrefix();
    int getPageNumType();
    bool isBtnScan();

private:
    ProfileModel *profile;
    QString path;
    ScanLabCroppingMain *scanLabCroppingMain;

    //geometry settings
    float geometryX;
    float geometryY;
    int geometryType;

    //camera settings
    bool cameraUse;
    bool internalCameraController;

    //page num settings
    bool backsidePostfixUse;
    QString backsidePostfixText;
    int backsidePostfixType;
    int firstPageNum;
    QString prefix;
    int pageNumType;
    bool btnScan;
};

#endif // PROJECTINFOMODEL_H
