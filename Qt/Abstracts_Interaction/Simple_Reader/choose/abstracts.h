#ifndef ABSTRACTS_H
#define ABSTRACTS_H

#include <QMainWindow>

namespace Ui {
class abstracts;
}

class abstracts : public QMainWindow
{
    Q_OBJECT

public:
    explicit abstracts(QWidget *parent = 0);
    ~abstracts();

private slots:
    void on_pushButton_clicked();

private:
    Ui::abstracts *ui;
};

#endif // ABSTRACTS_H
