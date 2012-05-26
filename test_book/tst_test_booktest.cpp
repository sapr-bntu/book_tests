#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QtCore/QCoreApplication>

#include <QtGui>
#include <QSqlDatabase>
#include "../laba1/mainwindow.h"

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
    void initTestCase();
    void cleanupTestCase();
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
};

Test_bookTest::Test_bookTest()
{
}
void Test_bookTest::initTestCase()
{
}
void Test_bookTest::cleanupTestCase()
{
}
void Test_bookTest::testCase1()
{
    bool flag = mw.author("Sergey Esenin");;
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
    bool flag = mw.author("Learning");;
    QCOMPARE(true, flag);
}
void Test_bookTest::testCase7()
{
    bool flag = mw.title("C#11");;
    QCOMPARE(true, flag);
}
void Test_bookTest::testCase8()
{
    bool flag = mw.insert("inlineedit");;
    QCOMPARE(true, flag);
}
void Test_bookTest::testCase9()
{
    bool flag = mw.del("1");;
    QCOMPARE(true, flag);
}
void Test_bookTest::testCase10()
{
    bool flag = mw.textchange("2005");;
    QCOMPARE(true, flag);
}

QTEST_MAIN(Test_bookTest)

#include "tst_test_booktest.moc"
