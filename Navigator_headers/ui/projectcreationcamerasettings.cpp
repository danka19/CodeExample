#include "projectcreationcamerasettings.h"
#include "ui_projectcreationcamerasettings.h"
#include "..//ScanLab_Cropping/ScreensFactory.h"
#include "..//ScanLab_Cropping/CameraDialog.h"
#include "..//ScanLab_Cropping/ExternalCameraControlThread.h"

using namespace screens;

ProjectCreationCameraSettings::ProjectCreationCameraSettings(/*QWidget *parent*/) :
    //QWidget(parent),
    ui(new Ui::ProjectCreationCameraSettings)
{
    ui->setupUi(this);

    connect(ui->btnNext, SIGNAL(clicked()), SLOT(btnNextClick()));
    connect(ui->btnBack, SIGNAL(clicked()), SLOT(btnBackClick()));
    connect(ui->btnCameraSettings, SIGNAL(clicked()), SLOT(btnCameraSettingsClick()));
    connect(ui->checkBoxCameraUse, SIGNAL(clicked()), SLOT(checkBoxCameraUseClick()));
}

ProjectCreationCameraSettings::~ProjectCreationCameraSettings()
{
    delete ui;
}

void ProjectCreationCameraSettings::setData(BaseModel *projectModel)
{
    ProjectInfoModel *model = dynamic_cast<ProjectInfoModel*>(projectModel);
    this->projectModel = model;
    this->scanLabCroppingMain = this->projectModel->getScanLabCroppingMain();
}


bool ProjectCreationCameraSettings::isPathTextEmpty()
{
    if (projectModel->getPath().length()<2){
        return true;
    } else return false;
}

void ProjectCreationCameraSettings::btnNextClick()
{
    emit navigateWhithData(GEOMETRY_TAG, this->projectModel);
}

void ProjectCreationCameraSettings::btnBackClick()
{
    emit backWhithData(this->projectModel);
}

void ProjectCreationCameraSettings::btnCameraSettingsClick()
{
    if (isPathTextEmpty()) {
        return;
    }


    if(ui->comboBoxCameraType->currentIndex() == 1)
    {
        scanLabCroppingMain->isInternalCameraController = false;
    } else
    {
        scanLabCroppingMain->isInternalCameraController = true;
    }

    QMessageBox msgBox;
    msgBox.setText("Удерживайте на сканере кнопку кадр более 5 секунд. "
                   "Включится максимальное освещение. "
                   "После установите необходимые настройки или выберите их из сохраненных");
    msgBox.exec();

    scanLabCroppingMain->edtPath->setText(projectModel->getPath());

    //hide test shot button
    scanLabCroppingMain->cameraDialog->enableBtnTextShot(false);

    scanLabCroppingMain->btnCameraClick();
    //TODO: add camera settings profiles

}

void ProjectCreationCameraSettings::checkBoxCameraUseClick()
{
    if (ui->checkBoxCameraUse->isChecked())
    {
        ui->btnCameraSettings->setEnabled(true);
        ui->comboBoxCameraType->setEnabled(true);
    } else
    {
        ui->btnCameraSettings->setEnabled(false);
        ui->comboBoxCameraType->setEnabled(false);
    }
}
