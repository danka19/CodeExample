#include "projectcreationpagenum.h"
#include "ui_projectcreationpagenum.h"
#include "..//ScanLab_Cropping/ScreensFactory.h"

ProjectCreationPageNum::ProjectCreationPageNum():
    ui(new Ui::ProjectCreationPageNum)
{
    ui->setupUi(this);

    connect(ui->checkBoxBacksideNumUse, SIGNAL(clicked()), SLOT(checkBoxBacksideNumClick()));
    connect(ui->btnNext, SIGNAL(clicked()), SLOT(btnNextClick()));
    connect(ui->btnBack, SIGNAL(clicked()), SLOT(btnBackClick()));

    ui->comboBoxBacksidePostfixType->setCurrentIndex(1);
}

ProjectCreationPageNum::~ProjectCreationPageNum()
{
    delete ui;
}

void ProjectCreationPageNum::setData(BaseModel *projectModel)
{
    ProjectInfoModel *model = dynamic_cast<ProjectInfoModel*>(projectModel);
    this->projectModel = model;
}

void ProjectCreationPageNum::checkBoxBacksideNumClick()
{
    if (ui->checkBoxBacksideNumUse->isChecked())
    {
        //ui->comboBoxBacksidePostfixType->setEnabled(true);
        ui->edtBacksidePostfixText->setEnabled(true);
    } else
    {
        //ui->comboBoxBacksidePostfixType->setEnabled(false);
        ui->edtBacksidePostfixText->setEnabled(false);
    }
}

void ProjectCreationPageNum::btnBackClick()
{
    emit backWhithData(this->projectModel);
}

void ProjectCreationPageNum::btnNextClick()
{
    this->projectModel->setPrefix(ui->edtPrefixJpg->text());
    this->projectModel->setPageNumType(ui->comboBoxNumType->currentIndex());
    this->projectModel->setBacksidePostfixUse(ui->checkBoxBacksideNumUse->isChecked());
    this->projectModel->setBacksidePostfixType(ui->comboBoxBacksidePostfixType->currentIndex());
    this->projectModel->setBackSidePostfixText(ui->edtBacksidePostfixText->text());
    this->projectModel->setFirstPageNum(ui->edtFirstPageNum->text().toInt());

    emit this->closeWindow();
}

