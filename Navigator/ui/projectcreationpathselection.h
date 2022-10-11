#ifndef PROJECTCREATIONPATHSELECTION_H
#define PROJECTCREATIONPATHSELECTION_H

#include <QWidget>
#include "..//ScanLab_Cropping/Navigator/base/basefragment.h"
#include "..//ScanLab_Cropping/Navigator/model/projectinfomodel.h"

#include <QObject>

namespace Ui {
class ProjectCreationPathSelection;
}

class ProjectCreationPathSelection : public BaseFragment
{
    Q_OBJECT

public:
    explicit ProjectCreationPathSelection(/*QWidget *parent = nullptr*/);
    void setData(BaseModel *model) override;
    ~ProjectCreationPathSelection();

private:
    Ui::ProjectCreationPathSelection *ui;
    ProjectInfoModel *projectModel;
private slots:
    void btnNextClick();
    void btnCancelClick();
    void btnBrowseClick();
    void on_edtPath_textChanged(const QString &arg1);
};

#endif // PROJECTCREATIONPATHSELECTION_H
