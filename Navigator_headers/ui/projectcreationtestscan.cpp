#include "projectcreationtestscan.h"
#include "ui_projectcreationtestscan.h"
#include <QDir>
#include <QThread>
#include <QDebug>
#include <windows.h>

using namespace screens;

ProjectCreationTestScan::ProjectCreationTestScan() :
    ui(new Ui::ProjectCreationTestScan)
{
    ui->setupUi(this);

    connect(ui->btnNext, SIGNAL(clicked()), SLOT(btnNextClick()));
    connect(ui->btnBack, SIGNAL(clicked()), SLOT(btnBackClick()));
    connect(ui->btnScan, SIGNAL(clicked()), SLOT(btnScanClick()));

    cropAdjustmentDialog = new CropAdjustmentDialog();
    connect(cropAdjustmentDialog, SIGNAL(updateCurrentPage()), SLOT(applyCropSettingsClicked()));

    imageLoadingTimer = new QTimer(this);
    connect(imageLoadingTimer, SIGNAL(timeout()), this, SLOT(imageLoadingTimerListener()));

    cropAdjustmentDialog->setX(51.2);
    cropAdjustmentDialog->setY(1.18);

    ui->checkBoxBtnScan->setVisible(false);
}

ProjectCreationTestScan::~ProjectCreationTestScan()
{
    delete ui;
}

void ProjectCreationTestScan::setData(BaseModel *projectModel)
{
    ProjectInfoModel *model = dynamic_cast<ProjectInfoModel*>(projectModel);
    this->projectModel = model;

    this->projectModel->setGeometryX(cropAdjustmentDialog->getX());
    this->projectModel->setGeometryY(cropAdjustmentDialog->getY());
}

void ProjectCreationTestScan::btnNextClick()
{
    this->projectModel->setIsBtnScan(this->ui->checkBoxBtnScan->isChecked());
    emit navigateWhithData(NUM_TAG, this->projectModel);
}

void ProjectCreationTestScan::btnBackClick()
{
    emit backWhithData(this->projectModel);
}

void ProjectCreationTestScan::btnScanClick()
{

    //считать изображение из папки
    if (isPathTextEmpty()) {
        ui->btnScan->toggle();
        return;
    }

    // Start or stop timer
    if (ui->btnScan->isChecked()) {
        imageLoadingTimer->start(1000);
    } else {
        imageLoadingTimer->stop();
    }
}

void ProjectCreationTestScan::imageLoadingTimerListener()
{
    QDir root(this->projectModel->getPath());
    QStringList filters;
    filters << "*.jpg" << "*.jpeg" << "*.JPEG"<<"*.JPG";
    QFileInfoList files = root.entryInfoList(filters);

    if (files.empty()) {
        return;
    }

    // Sleep to complete of writing images from Camera
    Sleep(1000);

    //ОН ЖДЕТ 1 СЕК А ПОТОМ ВЫВОДИТ СОО, ЧТО НЕТ ОТСКАНИРОВАННЫХ ИЗОБРАЖЕНИЙ

    try {
        QFileInfo file = files.at(0);
        if(!file.isDir()) {

            QApplication::processEvents();

        }
        if (!imageLoadingTimer->isActive()) {
            //break
        }
        this->imagePath = file.absoluteFilePath();
        qDebug() << "!!! imagePath: " << imagePath;
        imageLoadingTimer->stop();
        ui->btnScan->toggle();

        //call cropAdjustmentDialog
        callCropp(imagePath);
    } catch (...) {}
}

bool ProjectCreationTestScan::isPathTextEmpty() {
    bool result = false;
    if (this->projectModel->getPath().length()<2) {
        QMessageBox msgBox;
        msgBox.setText("Необходимо определить путь!");
        msgBox.exec();
        result = true;
    }
    return result;
}

void ProjectCreationTestScan::callCropp(QString path)
{
    if (path.isEmpty())
    {
        qDebug() << "No Image!";
        return;
    }
    //int angle = checkBoxRotate90->isChecked() ? 0 : -90;
    bool isMirror = false;
    int angle = 0;
    cropAdjustmentDialog->setModal(true);

    cropAdjustmentDialog->load(path, angle, isMirror);
    cropAdjustmentDialog->setMultipleSelect(false);
    cropAdjustmentDialog->exec();
}

void ProjectCreationTestScan::applyCropSettingsClicked()
{
    this->projectModel->setGeometryX(cropAdjustmentDialog->getX());
    this->projectModel->setGeometryY(cropAdjustmentDialog->getY());
    qDebug() << "X: " << this->projectModel->getGeometryX() << ", Y: " << this->projectModel->getGeometryY();
    cropAdjustmentDialog->close();
}
