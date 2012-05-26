#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "conn.h"
#include <QtSql>
#include <QtGui>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QTableView>
#include <QDebug>
#include "delegat.h"
#include <QSqlTableModel>
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
    createConnection();
    model= new QSqlQueryModel (this);
  //  model->setTable("books");
    //model->setEditStrategy(QSqlQueryModel::OnRowChange);
   // model->select();
    model->setQuery("SELECT * FROM books");
    ui->tableView->setItemDelegate(new delegat(ui->tableView));


    model->setHeaderData(0, Qt::Horizontal, tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, tr("Title"));
    model->setHeaderData(2, Qt::Horizontal, tr("Author"));
    model->setHeaderData(3, Qt::Horizontal, tr("Genre"));
    model->setHeaderData(4, Qt::Horizontal, tr("Year"));
    model->setHeaderData(5, Qt::Horizontal, tr("Rating"));


    this->ui->tableView->setModel(model);

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    bool author=false,title=false,genre=false,rating=false,year=false,first=true;
    QString result="SELECT * FROM books WHERE ";


    if ((this->ui->lineEdit_4->text())!="") author=true;
    if ((this->ui->lineEdit->text())!="") title=true;
    if ((this->ui->lineEdit_3->text())!="") genre=true;
    if ((this->ui->lineEdit_5->text())!="") rating=true;
    if ((this->ui->lineEdit_2->text())!="") year=true;

    if (author)
    {
        if (!first)
        {
            result+=" AND ";
        }
        result+="author LIKE '%";
        result+=this->ui->lineEdit_4->text();
        result+="%'";
        first=false;

    }
    if (title)
    {
        if (!first)
        {
            result+=" AND ";
        }
        result+="title LIKE '%";
        result+=this->ui->lineEdit->text();
        result+="%'";
        first=false;
    }
    if (genre)
    {
        if (!first)
        {
            result+=" AND ";
        }
        result+="genre LIKE '%";
        result+=this->ui->lineEdit_3->text();
        result+="%'";
        first=false;
    }
    if (year)
    {
        if (!first)
        {
            result+=" AND ";
        }
        result+="year LIKE '%";
        result+=this->ui->lineEdit_2->text();
        result+="%'";
        first=false;
    }
    if (rating)
    {
        if (!first)
        {
            result+=" AND ";
        }
        result+="rating LIKE '%";
        result+=this->ui->lineEdit_5->text();
        result+="%'";
        first=false;
    }


    QSqlQuery query;
    query.exec(result);
    model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, tr("Title"));
    model->setHeaderData(2, Qt::Horizontal, tr("Author"));
    model->setHeaderData(3, Qt::Horizontal, tr("Genre"));
    model->setHeaderData(4, Qt::Horizontal, tr("Year"));
    model->setHeaderData(5, Qt::Horizontal, tr("Rating"));


    this->ui->tableView->setModel(model);
}

void MainWindow::on_pushButton_4_clicked()//reset
{


    model->setQuery("SELECT * FROM books");

    model->setHeaderData(0, Qt::Horizontal, tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, tr("Title"));
    model->setHeaderData(2, Qt::Horizontal, tr("Author"));
    model->setHeaderData(3, Qt::Horizontal, tr("Genre"));
    model->setHeaderData(4, Qt::Horizontal, tr("Year"));
    model->setHeaderData(5, Qt::Horizontal, tr("Rating"));


    this->ui->tableView->setModel(model);
}

void MainWindow::on_pushButton_3_clicked()
{

    QString result="INSERT INTO books (Title, Author, Genre, Year, Rating) VALUES ('";
    result+=ui->lineEdit->text();
    result+="', '";
    result+=ui->lineEdit_4->text();
    result+="', '";
    result+=ui->lineEdit_3->text();
    result+="', '";
    result+=ui->lineEdit_2->text();
    result+="', '";
    result+=ui->lineEdit_5->text();
    result+="')";

    QSqlQuery query;

    query.exec(result);
    model->setQuery("SELECT * FROM books");

    model->setHeaderData(0, Qt::Horizontal, tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, tr("Title"));
    model->setHeaderData(2, Qt::Horizontal, tr("Author"));
    model->setHeaderData(3, Qt::Horizontal, tr("Genre"));
    model->setHeaderData(4, Qt::Horizontal, tr("Year"));
    model->setHeaderData(5, Qt::Horizontal, tr("Rating"));
    this->ui->tableView->setModel(model);
}

void MainWindow::on_pushButton_2_clicked()
{
QString del="",result="";

   del+=model->data(ui->tableView->selectionModel()->currentIndex()).toString();
    result+="delete from books where id="+del;
   QSqlQuery query;
   query.exec(result);

   model->setQuery(query);
   model->submit();

   model->setHeaderData(0, Qt::Horizontal, tr("Id"));
   model->setHeaderData(1, Qt::Horizontal, tr("Title"));
   model->setHeaderData(2, Qt::Horizontal, tr("Author"));
   model->setHeaderData(3, Qt::Horizontal, tr("Genre"));
   model->setHeaderData(4, Qt::Horizontal, tr("Year"));
   model->setHeaderData(5, Qt::Horizontal, tr("Rating"));
   this->ui->tableView->setModel(model);
}

void MainWindow::on_pushButton_5_clicked()
{
QString result="SELECT * FROM books WHERE ";
                result+="id LIKE '%";
               result+=ui->lineEdit_6->text();
               result+="%' OR title LIKE '%";
               result+=ui->lineEdit_6->text();
               result+="%' OR author LIKE '%";
               result+=ui->lineEdit_6->text();
               result+="%' OR genre LIKE '%";
               result+=ui->lineEdit_6->text();
               result+="%' OR year LIKE '%";
               result+=ui->lineEdit_6->text();
               result+="%' OR rating LIKE '%";
               result+=ui->lineEdit_6->text();
               result+="%'";

QSqlQuery query;
query.exec(result);
model->setQuery(query);

model->setHeaderData(0, Qt::Horizontal, tr("Id"));
model->setHeaderData(1, Qt::Horizontal, tr("Title"));
model->setHeaderData(2, Qt::Horizontal, tr("Author"));
model->setHeaderData(3, Qt::Horizontal, tr("Genre"));
model->setHeaderData(4, Qt::Horizontal, tr("Year"));
model->setHeaderData(5, Qt::Horizontal, tr("Rating"));


this->ui->tableView->setModel(model);


}

void MainWindow::on_lineEdit_7_textChanged(QString res)
{

    if (ui->checkBox->checkState()==Qt::Checked)
    {
    QString result="SELECT * FROM books WHERE ";
    result+="id LIKE '%";
                   result+=res;
                   result+="%' OR title LIKE '%";
                   result+=res;
                   result+="%' OR author LIKE '%";
                   result+=res;
                   result+="%' OR genre LIKE '%";
                   result+=res;
                   result+="%' OR year LIKE '%";
                   result+=res;
                   result+="%' OR rating LIKE '%";
                   result+=res;
                   result+="%'";

    QSqlQuery query;
    query.exec(result);
    model->setQuery(query);
    //model->setFilter(result);

    model->setHeaderData(0, Qt::Horizontal, tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, tr("Title"));
    model->setHeaderData(2, Qt::Horizontal, tr("Author"));
    model->setHeaderData(3, Qt::Horizontal, tr("Genre"));
    model->setHeaderData(4, Qt::Horizontal, tr("Year"));
    model->setHeaderData(5, Qt::Horizontal, tr("Rating"));


    this->ui->tableView->setModel(model);
}
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    ui->stackedWidget->setCurrentIndex(0);
   QString line;// = in.readAll();


    int row=index.row();
    line = model->record(row).value("Text").toString();
    ui->textEdit->setPlainText(line);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);

}

//FOR_TESTS
bool MainWindow::author(QString str)
{
    bool flag=true;
    try
    {
        int mystr=str.toInt();
    }
    catch(char* a)
    {
        flag=false;
    }
    return flag;
}
bool MainWindow::genre(QString str)
{
    bool flag=true;
    try
    {
        int mystr=str.toInt();
    }
    catch(char* a)
    {
        flag=false;
    }
    return flag;
}
bool MainWindow::year1(QString str)
{
    bool flag;
    if (str.toInt())
    {
        flag=true;
    }
    else {flag=false;}
    return flag;
}
bool MainWindow::year2(QString str)
{
    bool flag;
    if (str.toInt()>1900 && str.toInt()<2012)
    {
        flag=true;
    }
    else {flag=false;}
    return flag;
}
bool MainWindow::rating1(QString str)
{
    bool flag;
    if (str.toInt())
    {
        flag=true;
    }
    else {flag=false;}
    return flag;
}
bool MainWindow::rating2(QString str)
{
    bool flag;
    if (str.toInt()>=0 && str.toInt()<=5)
    {
        flag=true;
    }
    else {flag=false;}
    return flag;
}
bool MainWindow::title(QString str)
{
    bool flag = false;
    QString result="SELECT * FROM books WHERE ";
    result+="title LIKE '%";
    result+=str;
    result+="%'";
    QSqlQuery query;
    flag = query.exec(result);
    return flag;
}
bool MainWindow::insert(QString str)
{
    bool flag = false;
    QString result="INSERT INTO books (Title, Author, Genre, Year, Rating) VALUES ('";
    result+=str;
    result+="', '";
    result+=str;
    result+="', '";
    result+=str;
    result+="', '";
    result+=str;
    result+="', '";
    result+=str;
    result+="')";
    QSqlQuery query;
    flag = query.exec(result);
    return flag;
}
bool MainWindow::del(QString str)
{
    bool flag = false;
    QString result="delete from books where id=";
    result+=str;
    QSqlQuery query;
    flag = query.exec(result);
    return flag;
}
bool MainWindow::textchange(QString str)
{
    bool flag = false;
    QString result="SELECT * FROM books WHERE ";
    result+="id LIKE '%";
    result+=str;
    result+="%' OR title LIKE '%";
    result+=str;
    result+="%' OR author LIKE '%";
    result+=str;
    result+="%' OR genre LIKE '%";
    result+=str;
    result+="%' OR year LIKE '%";
    result+=str;
    result+="%' OR rating LIKE '%";
    result+=str;
    result+="%'";
    QSqlQuery query;
    flag = query.exec(result);
    return flag;
}
