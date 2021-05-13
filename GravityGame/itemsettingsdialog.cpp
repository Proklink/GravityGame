#include "itemsettingsdialog.h"
#include "ui_itemsettingsdialog.h"
#include <QDebug>

ItemSettingsDialog::ItemSettingsDialog(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::ItemSettingsDialog)
{
    Init();
}

void ItemSettingsDialog::Init()
{
    ui->setupUi(this);
    setFixedSize(300, 250);

    connect(ui->SetButton, &QPushButton::clicked, this, &ItemSettingsDialog::SlotSetParametrs);
}

void ItemSettingsDialog::SetParametrs(float _mass, float _radious, float _xSpeed, float _ySpeed)
{
    ui->MassEdit->setText(QString::number(_mass));
    ui->RadiousEdit->setText(QString::number(_radious));
    ui->xSpeedEdit->setText(QString::number(_xSpeed));
    ui->ySpeedEdit->setText(QString::number(_ySpeed));
}

void ItemSettingsDialog::SlotSetParametrs()
{
    ObjectParametrs objectParams;

    objectParams.mass = ui->MassEdit->text().toDouble();
    objectParams.radious = ui->RadiousEdit->text().toDouble();
    objectParams.xSpeed = ui->xSpeedEdit->text().toDouble();
    objectParams.ySpeed = ui->ySpeedEdit->text().toDouble();

    emit SignalSendObjectParametrs(objectParams);

    close();
}

ItemSettingsDialog::~ItemSettingsDialog()
{
    delete ui;
}
