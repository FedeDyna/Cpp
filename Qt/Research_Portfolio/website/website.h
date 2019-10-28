#ifndef WEBSITE_H
#define WEBSITE_H

#include <QMainWindow>

namespace Ui {
class website;
}

class website : public QMainWindow
{
    Q_OBJECT

public:
    explicit website(QWidget *parent = 0);
    ~website();

private slots:
    void on_kepler60_clicked();
    void on_kepler30_clicked();
    void on_kepler29_clicked();
    void on_rem_clicked();
    void on_bologna_clicked();
    void on_pdf_k60_clicked();
    void on_pdf_k30_clicked();
    void on_pdf_k29_clicked();
    void on_pdf_rem_clicked();

private:
    Ui::website *ui;
};

#endif // WEBSITE_H
