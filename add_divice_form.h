#ifndef ADD_DIVICE_FORM_H
#define ADD_DIVICE_FORM_H

#include <QDialog>
#include "divace.h"

namespace Ui {
class add_divice_form;
}

class AddDiviceForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddDiviceForm(QWidget *parent = nullptr);
    ~AddDiviceForm();

signals:
    void deviceCreated(const Device& device);

private slots:
    void on_cancelButton_clicked();
    void on_addDiviceButton_clicked();

private:
    Ui::add_divice_form *ui;
    void fillParitySettingCombo();
};

#endif // ADD_DIVICE_FORM_H
