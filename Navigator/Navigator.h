#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include "../ScanLab_Cropping/Navigator/base/basefragment.h"
#include "../ScanLab_Cropping/Navigator/base/basescreensfactory.h"
#include "../ScanLab_Cropping/Navigator/model/projectinfomodel.h"

#include <QStackedWidget>
#include <QLinkedList>

/**
 * @brief The Navigator class
 *
 * Навигация в риложении и логика замены экранов.
 *
 * <p>Экраны лежат в списке и мы можем выполнить
 * переход дальше по цепочке, заменить текущий экран
 * или перейти назад по цепочке.</p>
 *
 * @author Solyanoy Leonid (solyanoy.leonid@gmail.com)
 */
class Navigator: public QObject {
    Q_OBJECT
private:
    QStackedWidget *currentContainer;
    BaseScreensFactory *screensFactory;
    QLinkedList<BaseFragment*> stack;
    ProjectInfoModel *projectInfoModel;

    /**
     * @brief createAndConnect
     * @param tag тэг создаваемого фрагмента.
     *
     * Создание фрагмента по тегу и его
     * прикрепление к навигатору.
     *
     * @return фрагмент приконекченный к слотам навигатора.
     */
    BaseFragment* createAndConnect(QString tag);

    /**
     * @brief connectFragment
     * @param fragment фрагмент который переходит
     *        в активное состояние.
     *
     * Прикрепление текущего фрагмента
     * к слотам навигатора для быстрого
     * и удобного перехода между экранами.
     *
     */
    void connectFragment(BaseFragment *fragment);

    /**
     * @brief disconnectFragment
     * @param fragment
     *
     * Отключение сигналов от фрагмента.
     */
    void disconnectFragment(BaseFragment *fragment);

    ProfileModel* selectedProfileElement;

public:
    Navigator(
            QStackedWidget *container,
            BaseScreensFactory *screensFactory,
            ProjectInfoModel *projectInfoModel
    );
    ~Navigator();
    BaseFragment* getStartScreen();

public slots:
    /**
     * @brief navigateTo
     * @param tag имя следующего экрана.
     *
     * Переход к следующему экрану.
     */
    void navigateTo(QString tag);

    /**
     * @brief back
     *
     * Переход назад по цепочке.
     */
    void back();

    /**
     * @brief replace
     * @param tag имя экрана на который
     *        произойдет замена.
     *
     * Замена текущего экрана с сохранением
     * предыдущей цепочки.
     */
    void replace(QString tag);

    /**
     * @brief newRootScreen
     * @param tag имя экрана на который
     *        произойдет замена.
     *
     * Замена текущего экрана на новый и сброс
     * всей цепочки экранов.
     */
    void newRootScreen(QString tag);

    /**
     * @brief backWhithData
     * @param model
     *
     * Тот же бэк но с данными.
     */
    void backWhithData(BaseModel* model);

    /**
     * @brief navigateWhithData
     * @param model
     *
     * Тот же navigateTo но с данными.
     */
    void navigateWhithData(QString tag, BaseModel* model);

    void closeWindow();

signals:
    void closeWindowNavigator();
};

#endif // NAVIGATOR_H
