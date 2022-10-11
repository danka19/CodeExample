#ifndef MAINMENU_H
#define MAINMENU_H

#include "../ScanLab_Cropping/Navigator/base/basefragment.h"
#include "../ScanLab_Cropping/Navigator/model/projectinfomodel.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public BaseFragment
{
    Q_OBJECT

public:
    MainMenu();
    ~MainMenu();

    void setData(BaseModel* profileModel) override;

public slots:
    void btnNewProjectClick();
    void btnOpenProjectClick();
    void btnChangeUserClick();
    void userNameUpdate();

private:
    ProjectInfoModel* projectModel;
    ProfileModel* profile;
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
