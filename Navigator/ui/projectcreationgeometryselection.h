#ifndef PROJECTCREATIONGEOMETRYSELECTION_H
#define PROJECTCREATIONGEOMETRYSELECTION_H

#include <QWidget>
#include "..//ScanLab_Cropping/Navigator/base/basefragment.h"
#include "..//ScanLab_Cropping/Navigator/model/projectinfomodel.h"

namespace Ui {
class projectCreationGeometrySelection;
}

class projectCreationGeometrySelection :  public BaseFragment
{
    Q_OBJECT

public:
    explicit projectCreationGeometrySelection();
    ~projectCreationGeometrySelection();

    void setData(BaseModel *model) override;

private:
    Ui::projectCreationGeometrySelection *ui;
    ProjectInfoModel *projectModel;

private slots:
    void btnNextClick();
    void btnBackClick();
    void on_comboBox_currentIndexChanged(const QString &arg1);
};

#endif // PROJECTCREATIONGEOMETRYSELECTION_H
