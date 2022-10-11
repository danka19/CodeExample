#ifndef PROJECTCREATIONTESTSCAN_H
#define PROJECTCREATIONTESTSCAN_H

#include "..//ScanLab_Cropping/Navigator/base/basefragment.h"
#include "..//ScanLab_Cropping/Navigator/model/projectinfomodel.h"

#include "..//ScanLab_Cropping/Navigator/Navigator.h"
#include "..//ScanLab_Cropping/ScreensFactory.h"
#include "..//ScanLab_Cropping/CropAdjustmentDialog.h"
#include <QTime>
#include <QTimer>

/// Используется только когда тип геометрии не плоское стекло

namespace Ui {
class ProjectCreationTestScan;
}

class ProjectCreationTestScan : public BaseFragment
{
    Q_OBJECT

public:
    explicit ProjectCreationTestScan();
    ~ProjectCreationTestScan();
    void setData(BaseModel *model);

private:
    Ui::ProjectCreationTestScan *ui;
    ProjectInfoModel *projectModel;
    QTimer *imageLoadingTimer;
    bool isPathTextEmpty();
    QString imagePath;
    void callCropp(QString path);
    CropAdjustmentDialog *cropAdjustmentDialog;

private slots:
    void btnNextClick();
    void btnBackClick();
    void btnScanClick();
    void imageLoadingTimerListener();
    void applyCropSettingsClicked();
};

#endif //PROJECTCREATIONTESTSCAN_H
