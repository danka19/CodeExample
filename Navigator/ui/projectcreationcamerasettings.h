#ifndef PROJECTCREATIONCAMERASETTINGS_H
#define PROJECTCREATIONCAMERASETTINGS_H

#include <QWidget>
#include "..//ScanLab_Cropping/Navigator/base/basefragment.h"
#include "..//ScanLab_Cropping/Navigator/model/projectinfomodel.h"
#include "..//ScanLab_Cropping/ScanLabCroppingMain.h"

namespace Ui {
class ProjectCreationCameraSettings;
}

class ProjectCreationCameraSettings : public BaseFragment
{
    Q_OBJECT

public:
    explicit ProjectCreationCameraSettings(/*QWidget *parent = nullptr*/);
    ~ProjectCreationCameraSettings();

    void setData(BaseModel *model) override;

private:
    Ui::ProjectCreationCameraSettings *ui;
    bool isPathTextEmpty();
    ProjectInfoModel *projectModel;
    ScanLabCroppingMain *scanLabCroppingMain;

private slots:
    void btnNextClick();
    void btnBackClick();
    void btnCameraSettingsClick();
    void checkBoxCameraUseClick();

};

#endif // PROJECTCREATIONCAMERASETTINGS_H
