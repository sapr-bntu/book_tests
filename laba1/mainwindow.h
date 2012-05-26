#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public:
    Ui::MainWindow *ui;
    QSqlQueryModel *model;


    Ui::MainWindow *GetUi(){
        return ui;
    };
	
	

public slots:
    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_lineEdit_7_textChanged(QString );
    void on_pushButton_5_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();
    bool author(QString str);
    bool genre(QString str);
    bool year1(QString str);
    bool year2(QString str);
    bool rating1(QString str);
    bool rating2(QString str);
    bool title(QString str);
    bool insert(QString str);
    bool del(QString str);
    bool textchange(QString str);
};

#endif // MAINWINDOW_H