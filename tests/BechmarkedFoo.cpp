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

    void notCalled()
    {
        QSKIP("This is not a test function", SkipAll);
        std::cout << "If you see this, it is problem!" << std::endl;
    }

    void back_data()
    { //Creating table
        QTest::addColumn<std::vector<int>>("unsortedVector");
        QTest::addColumn<std::vector<int>>("sortedVector");

        std::vector<int> perfectVector = {0, 1, 2, 3, 4, 5};

        //Inserting test data
        QTest::newRow("First scenario") << std::vector<int>{1, 0, 2, 3, 4, 5} << perfectVector;
        QTest::newRow("Second scenario") << std::vector<int>{1, 0, 2, 3, 5, 4} << perfectVector;
        QTest::newRow("Third scenario") << std::vector<int>{1, 0, 3, 2, 4, 5} << perfectVector;
        QTest::newRow("Forth scenario") << std::vector<int>{1, 0, 2, 3, 4, 5} << perfectVector;
        QTest::newRow("Fifth scenario") << std::vector<int>{1, 2, 0, 3, 4, 5} << perfectVector;
        QTest::newRow("Sixth scenario") << std::vector<int>{1, 5, 2, 3, 0, 5} << perfectVector;
        QTest::newRow("Seventh scenario") << std::vector<int>{5, 4, 3, 2, 1, 0} << perfectVector;

        //sort(v.begin(), v.end());
    }

    void back()
    {
        QFETCH(std::vector<int>, unsortedVector);
        QFETCH(std::vector<int>, sortedVector);

        sort(unsortedVector.begin(), unsortedVector.end());

        QCOMPARE(unsortedVector.back(), sortedVector.back());
    }

    void toUpper()
    {
        QFETCH(QString, string);
        QFETCH(QString, result);

        QCOMPARE(string.toUpper(), result);
    }

    //https://doc.qt.io/qt-5/qttestlib-tutorial2-example.html
    void toUpper_data()
    {
        //Creating table
        QTest::addColumn<QString>("string");
        QTest::addColumn<QString>("result");
        const QString result = "HELLO";

        //Inserting test data
        QTest::newRow("all lower") << "hello"
                                   << result;
        QTest::newRow("mixed") << "Hello"
                               << result;
        QTest::newRow("all upper") << "HELLO"
                                   << result;
    }
};

DECLARE_TEST(BenchmarkedFoo)
#include "BechmarkedFoo.moc"