#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "../ScanLab_Cropping/ScreensFactory.h"

using namespace screens;


MainMenu::MainMenu():
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    connect(ui->btnNewProject, SIGNAL(clicked()), SLOT(btnNewProjectClick()));
    connect(ui->btnOpenProject, SIGNAL(clicked()), SLOT(btnOpenProjectClick()));
    connect(ui->btnChangeUser, SIGNAL(clicked()), SLOT(btnChangeUserClick()));

    ui->tableView->setVisible(false);
    ui->label_3->setVisible(false);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::setData(BaseModel *profileModel)
{
    ProjectInfoModel *model = dynamic_cast<ProjectInfoModel*>(profileModel);
    this->projectModel = model;
    this->profile = this->projectModel->getProfile();

    userNameUpdate();
}

void MainMenu::btnNewProjectClick()
{
    emit navigateWhithData(PATH_TAG, this->projectModel);
}

void MainMenu::btnOpenProjectClick()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open ScanLab project"),
                                                "C:\\", "ScanLab project (*.scanlab)");
    if (!(path.length() < 2)) {
        this->projectModel->getScanLabCroppingMain()->openProject(path);
        this->closeWindow();
    }
}

void MainMenu::btnChangeUserClick()
{
   emit  back();
}

void MainMenu::userNameUpdate()
{
    if(profile != 0){
        QString newProfileName = profile->getName();
        ui->labelUserName->setText(newProfileName);
    }
    else  ui->labelUserName->setText("");
}

