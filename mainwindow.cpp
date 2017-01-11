#include "mainwindow.h"
#define __IFTTT_URL "https://maker.ifttt.com/trigger/" IFTTT_EVENT "/with/key/" IFTTT_KEY

const int wait = 1500;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_returnPressed()
{
    QString message;
    QString ID = ui->lineEdit-> text();
    ui->lineEdit->clear();

    //search for entry
    Person person = Person::load(ID.toInt());
    //ui->label->setText(QString::number(ID.toInt()));
    //Produce entry message
    if (person.loaded)
    {
        ui->label_2->setStyleSheet("background-color: blue; color: white");
        message = QString::fromStdString(person.f_name);
        QString jsondata = QString::fromStdString(build_json(person));
        QUrl url = QUrl(__IFTTT_URL);
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));

        /* QNetworkReply* reply */
        qnam.post(request, jsondata.toUtf8());
    }
    else
    {
        ui->label_2->setStyleSheet("background-color: red; color: white");
        message = "Not Found";
    }

    //Display message
    ui->label_2->setText(message);
    delay(wait);
    ui->label_2->setStyleSheet("background-color: white");
    ui->label_2->setText("Sign In Here");
}

void delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

string build_json(Person p)
{
    string json_string = "{";
    string value1 = "\"value1\":\"" + to_string(p.card_id) + "\"";
    string value2 = "\"value2\":\"" + p.f_name + "\"";
    string value3 = "\"value3\":\"" + p.l_name + "\"";
    json_string += (value1 + ",");
    json_string += (value2 + ",");
    json_string += (value3);
    json_string += "}";
    cout << json_string << endl;
    return json_string;
}
