#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QtCore/QCoreApplication>
#include <QtGui>
#include <QSqlDatabase>
#include "../laba1/mainwindow.h"
#include "../laba1/conn.h"

namespace Ui {
    class MainWindow;
}

class Test_bookTest : public QObject
{
    Q_OBJECT

public:
    Test_bookTest();
    MainWindow mw;

private Q_SLOTS:
    void testCase1();
    void testCase2();
    void testCase3();
    void testCase4();
    void testCase5();
    void testCase6();
    void testCase7();
    void testCase8();
    void testCase9();
    void testCase10();
    void testCase11();
    void testCase12();
    void testCase13();
    void testCase14();
};

Test_bookTest::Test_bookTest()
{
}
void Test_bookTest::testCase1()
{
    bool flag = mw.fauthor("Sergey Esenin");
    QCOMPARE(true, flag);
}
void Test_bookTest::testCase2()
{
    bool flag = mw.year1("1234");
    QCOMPARE(true, flag);
}
void Test_bookTest::testCase3()
{
    bool flag = mw.year2("1950");
    QCOMPARE(true, flag);
}
void Test_bookTest::testCase4()
{
    bool flag = mw.rating1("4");
    QCOMPARE(true, flag);
}
void Test_bookTest::testCase5()
{
    bool flag = mw.rating2("3");
    QCOMPARE(true, flag);
}
void Test_bookTest::testCase6()
{
    bool flag = mw.fgenre("Learning");
    QCOMPARE(true, flag);
}
void Test_bookTest::testCase7()
{
    bool flag = mw.title("C#");
    QCOMPARE(true, flag);
}
void Test_bookTest::testCase8()
{
    bool flag = mw.insert("inlineedit");
    QCOMPARE(true, flag);
}
void Test_bookTest::testCase9()
{
    bool flag = mw.del("1");
    QCOMPARE(true, flag);
}
void Test_bookTest::testCase10()
{
    bool flag = mw.textchange("2005");
    QCOMPARE(true, flag);
}
void Test_bookTest::testCase11()
{
    int flag = mw.titlen("C#");
    QCOMPARE(0, flag);
}
void Test_bookTest::testCase12()
{
    bool flag = createConnection();
    QCOMPARE(true, flag);
}
void Test_bookTest::testCase13()
{
    bool flag = mw.title("C#");
    QCOMPARE(true, flag);
}
void Test_bookTest::testCase14()
{
    bool flag = mw.lastQuery("1");
    QCOMPARE(true, flag);
}
QTEST_MAIN(Test_bookTest)

#include "tst_test_booktest.moc"
