#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <Windows.h>
#include <algorithm>
#include <sstream>
#include <conio.h>
#include <QTime>
#include "person.h"
#include "webservice.h"
#include <QNetworkAccessManager>

using namespace std;
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager qnam;
};

void delay(int millisecondsToWait);
string build_json(Person p);

#endif // MAINWINDOW_H
