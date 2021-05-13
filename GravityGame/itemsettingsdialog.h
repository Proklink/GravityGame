#ifndef ITEMSETTINGSDIALOG_H
#define ITEMSETTINGSDIALOG_H

#include <QDialog>
#include "StorageVariable.h"

namespace Ui {
class ItemSettingsDialog;
}

class ItemSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ItemSettingsDialog(QWidget *parent = nullptr);
    ~ItemSettingsDialog();
public:
    void SetParametrs(float _mass, float _radious, float _xSpeed, float _ySpeed);
private slots:
    void SlotSetParametrs();
private:
    void Init();
private:
    Ui::ItemSettingsDialog *ui;
signals:
    void SignalSendObjectParametrs(ObjectParametrs);
};

#endif // ITEMSETTINGSDIALOG_H
