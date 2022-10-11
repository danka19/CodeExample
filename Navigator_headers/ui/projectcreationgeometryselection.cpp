#include "projectcreationgeometryselection.h"
#include "ui_projectcreationgeometryselection.h"
#include "..//ScanLab_Cropping/ScreensFactory.h"

using namespace screens;

projectCreationGeometrySelection::projectCreationGeometrySelection():
    ui(new Ui::projectCreationGeometrySelection)
{
    ui->setupUi(this);

    connect(ui->btnNext, SIGNAL(clicked()), SLOT(btnNextClick()));
    connect(ui->btnBack, SIGNAL(clicked()), SLOT(btnBackClick()));
}

projectCreationGeometrySelection::~projectCreationGeometrySelection()
{
    delete ui;
}

void projectCreationGeometrySelection::btnNextClick()
{
    //if ((this->projectModel->getGeometryType() != 2) && (this->projectModel->getGeometryType() != 3))
    if ((this->projectModel->getGeometryType() != 0))
    {
        emit navigateWhithData(TEST_TAG, this->projectModel);
    } else emit navigateWhithData(NUM_TAG, this->projectModel);
}

void projectCreationGeometrySelection::btnBackClick()
{
    emit backWhithData(this->projectModel);
}

void projectCreationGeometrySelection::setData(BaseModel *projectModel)
{
    ProjectInfoModel *model = dynamic_cast<ProjectInfoModel*>(projectModel);
    this->projectModel = model;
}

void projectCreationGeometrySelection::on_comboBox_currentIndexChanged(const QString &arg1)
{
    //////////////////////////////////////
    /// Geometry types:                ///
    /// 0 - optimaV,                   ///
    /// 1 - optima_plan(v),            ///
    /// 2 - optima_plan(flat),         ///
    /// 3 - optima_plan(flat, 2 pages) ///
    //////////////////////////////////////

    this->projectModel->setGeometryType(ui->comboBox->currentIndex());
}

