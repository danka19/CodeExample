#ifndef CUSTOMWIDGETITEM_H
#define CUSTOMWIDGETITEM_H

#include <QWidget>

namespace Ui {
class CustomWidgetItem;
}

class CustomWidgetItem : public QWidget
{
    Q_OBJECT

public:
    explicit CustomWidgetItem(QWidget *parent = nullptr);
    ~CustomWidgetItem();
    void setText(QString text);
    QString getText();

private:
    Ui::CustomWidgetItem *ui;
};

#endif // CUSTOMWIDGETITEM_H

