#include <iostream>
#include <QTest>
#include "AutoTest.h"

class DataDrivenFoo : public QObject
{
    Q_OBJECT

private slots: //must be private slots, otherwise not working.

    void compareVectors_data()
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
        QTest::newRow("Sixth scenario") << std::vector<int>{1, 5, 2, 3, 0, 4} << perfectVector;
        QTest::newRow("Seventh scenario") << std::vector<int>{5, 4, 3, 2, 1, 0} << perfectVector;
    }

    void compareVectors()
    {
        QFETCH(std::vector<int>, unsortedVector);
        QFETCH(std::vector<int>, sortedVector);

        sort(unsortedVector.begin(), unsortedVector.end());

        for(int i = 0; i < unsortedVector.size(); i++)
        {
            QCOMPARE(unsortedVector[i], sortedVector[i]);
        }
    }

    //https://doc.qt.io/qt-5/qttestlib-tutorial2-example.html
    void compareStrings_data()
    {
        //Creating table
        QTest::addColumn<QString>("string");
        QTest::addColumn<QString>("result");
        const QString result = "HELLO";

        //Inserting test data
        QTest::newRow("String testing - all lower") << "hello" << result;
        QTest::newRow("String testing - mixed") << "Hello" << result;
        QTest::newRow("String testing - all upper") << "HELLO" << result;
    }

    void compareStrings()
    {
        QFETCH(QString, string);
        QFETCH(QString, result);

        QCOMPARE(string.toUpper(), result);
    }
};

DECLARE_TEST(DataDrivenFoo)
#include "DataDrivenFoo.moc"