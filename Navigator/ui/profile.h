#ifndef PROFILE_H
#define PROFILE_H

#include "../ScanLab_Cropping/Navigator/base/basefragment.h"
#include "../ScanLab_Cropping/Navigator/model/projectinfomodel.h"

namespace Ui {
class Profile;
}

class Profile: public BaseFragment
{
    Q_OBJECT

public:
    explicit Profile(/*QWidget *parent = nullptr*/);
    ~Profile();

    void profileStackAdd(ProfileModel *profileElement);
    ProfileModel* selectedProfileElement;
    ProjectInfoModel* projectModel;

private slots:
    void on_radioButtonNew_toggled(bool checked);
    void on_pushButton_clicked();
    void setData(BaseModel *model) override;


private:
    Ui::Profile *ui;
};

#endif // PROFILE_H
