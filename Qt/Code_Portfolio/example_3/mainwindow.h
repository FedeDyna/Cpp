#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <stdio.h> /* printf */
#include <iostream>
#include <fstream>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <QApplication>
#include <QLabel>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_EnergyCalc_clicked();

    void on_orbit_integration_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
