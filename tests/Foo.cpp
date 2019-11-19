#include <iostream>
#include <QTest>
#include "AutoTest.h"

class Foo : public QObject
{
    Q_OBJECT

private slots:
    int initTestCase()
    {
        //std::cout << "-------------------- Starting FOO test cases -------------" << std::endl;
        int i = 0;
        i++;
    }

    void cleanupTestCase()
    {
        //std::cout << "-------------------- Cleaning up FOO test cases -------------" << std::endl;
        int i = 0;
        i++;
    }

    void test1()
    {
        std::cout << "From inside of unit test" << std::endl;

        QVERIFY(true);
        QCOMPARE(1, 1);

        QWARN("Hell yeah. Adding some warning message");
        QVERIFY2((1 + 1) == 3, "Conditional reasonable message");
    }

    void test2()
    {
        std::cout << "From inside of unit test" << std::endl;
        QVERIFY(true);
        QEXPECT_FAIL("", "Expected fail, 1 is not 2 ", Continue);
        QCOMPARE(1, 2);
    }
};

DECLARE_TEST(Foo)
#include "Foo.moc"