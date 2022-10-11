#include "profile.h"
#include "ui_profile.h"
#include "QDebug"
#include "../ScanLab_Cropping/Settings.h"

#include "../model/customwidgetitem.h"
#include "../ScanLab_Cropping/ScreensFactory.h"


using namespace screens;

Profile::Profile(/*QWidget *parent*/) :
   // QWidget(parent),
    ui(new Ui::Profile)
{
    ui->setupUi(this);

    // Load profiles
    Settings::instance().load(ui->listWidgetSelection);
}

Profile::~Profile()
{
    delete ui;
}

void Profile::setData(BaseModel *projectModel)
{
    ProjectInfoModel *model = dynamic_cast<ProjectInfoModel*>(projectModel);
    this->projectModel = model;
}


void Profile::on_radioButtonNew_toggled(bool checked)
{
    if(checked)
    {
       ui->name->setEnabled(true);
       ui->listWidgetSelection->setEnabled(false);
    }
    if(!checked)
    {
        ui->name->setEnabled(false);
        ui->listWidgetSelection->setEnabled(true);
    }
}

void Profile::on_pushButton_clicked()
{
    if (ui->radioButtonNew->isChecked())
    {
        this->selectedProfileElement = new ProfileModel(ui->listWidgetSelection->count(), ui->name->text());
        CustomWidgetItem* itemWidget = new CustomWidgetItem();
        itemWidget->setText(selectedProfileElement->getName());
        selectedProfileElement->setSizeHint(itemWidget->sizeHint());
        ui->listWidgetSelection->addItem(selectedProfileElement);
        ui->listWidgetSelection->setItemWidget(selectedProfileElement, itemWidget);

        //saving new profile to reg
        Settings::instance().save(ui->listWidgetSelection);
    }

   if (ui->radioButtonSelect->isChecked())
   {
       this->selectedProfileElement = (ProfileModel*)(ui->listWidgetSelection->currentItem());
   }

   this->projectModel->setProfile(this->selectedProfileElement);
   emit navigateWhithData(MENU_TAG, this->projectModel);
}



