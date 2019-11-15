#include <iostream>
#include <QTest>

class Foo : public QObject {
    Q_OBJECT
private slots:
    void test1() { 
        QVERIFY(true); 
        std::cout << "From inside of unit test" << std::endl;

        QCOMPARE(1, 1);
    }
};

QTEST_MAIN(Foo)
#include "foo.moc"