#include "customwidgetitem.h"
#include "ui_customwidgetitem.h"

CustomWidgetItem::CustomWidgetItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomWidgetItem)
{
    ui->setupUi(this);
}

CustomWidgetItem::~CustomWidgetItem()
{
    delete ui;
}

void CustomWidgetItem::setText(QString text)
{
    ui->label->setText(text);
}

QString CustomWidgetItem::getText()
{
    return ui->label->text();
}
