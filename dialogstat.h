#ifndef DIALOGSTAT_H
#define DIALOGSTAT_H

#include <QDialog>

namespace Ui {
class Dialogstat;
}

class Dialogstat : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogstat(QWidget *parent = nullptr);
    ~Dialogstat();

private:
    Ui::Dialogstat *ui;
};

#endif // DIALOGSTAT_H
