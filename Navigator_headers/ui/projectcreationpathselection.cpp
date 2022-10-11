#include "projectcreationpathselection.h"
#include "ui_projectcreationpathselection.h"

#include <QFileDialog>
#include "..//ScanLab_Cropping/ScreensFactory.h"

using namespace screens;

ProjectCreationPathSelection::ProjectCreationPathSelection(/*QWidget *parent*/):
    //QWidget(parent),
    ui(new Ui::ProjectCreationPathSelection)
{
    ui->setupUi(this);

    connect(ui->btnNext, SIGNAL(clicked()), SLOT(btnNextClick()));
    connect(ui->btnCancel, SIGNAL(clicked()), SLOT(btnCancelClick()));
    connect(ui->btnBrowse, SIGNAL(clicked()), SLOT(btnBrowseClick()));

    ui->btnNext->setEnabled(false);
}


void ProjectCreationPathSelection::setData(BaseModel *projectModel)
{
    ProjectInfoModel *model = dynamic_cast<ProjectInfoModel*>(projectModel);
    this->projectModel = model;
}

ProjectCreationPathSelection::~ProjectCreationPathSelection()
{
    delete ui;
}

void ProjectCreationPathSelection::btnNextClick()
{
    //emit navigateWhithData(GEOMETRY_TAG, this->projectModel);
    emit navigateWhithData(CAMERA_TAG, this->projectModel);
}

void ProjectCreationPathSelection::btnCancelClick()
{
    emit backWhithData(this->projectModel);
}

void ProjectCreationPathSelection::btnBrowseClick()
{
    QString directory = QFileDialog::getExistingDirectory(this, "Open_Directory", "C:\\",  QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->edtPath->setText(directory);
}


void ProjectCreationPathSelection::on_edtPath_textChanged(const QString &arg1)
{
    bool result = true;
    if (ui->edtPath->text().length()<2) {
        result = false;
    }

    ui->btnNext->setEnabled(result);

    this->projectModel->setPath(ui->edtPath->text());
}


