#ifndef PROJECTCREATIONPAGENUM_H
#define PROJECTCREATIONPAGENUM_H

#include <QWidget>
#include "..//ScanLab_Cropping/Navigator/base/basefragment.h"
#include "..//ScanLab_Cropping/Navigator/model/projectinfomodel.h"

namespace Ui {
class ProjectCreationPageNum;
}

class ProjectCreationPageNum : public BaseFragment
{
    Q_OBJECT

public:
    explicit ProjectCreationPageNum();
    ~ProjectCreationPageNum();
    void setData(BaseModel *model);

private:
    Ui::ProjectCreationPageNum *ui;
    ProjectInfoModel *projectModel;

private slots:
    void checkBoxBacksideNumClick();
    void btnBackClick();
    void btnNextClick();
};

#endif // PROJECTCREATIONPAGENUM_H
