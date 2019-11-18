#include <iostream>
#include <QTest>
#include "AutoTest.h"

class BenchmarkedFoo : public QObject
{
    Q_OBJECT

private slots: //must be private slots, otherwise not working.
    void test()
    {
        QVERIFY(true);
        QCOMPARE(1, 1);
    }

    void dummyName()
    {
        QVERIFY(true);
        QCOMPARE(1, 1);
    }
};

DECLARE_TEST(BenchmarkedFoo)
#include "BechmarkedFoo.moc"