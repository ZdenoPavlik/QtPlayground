#include <iostream>
#include <QTest>
#include "AutoTest.h"

class DataDrivenFoo : public QObject
{
    Q_OBJECT

private slots: //must be private slots, otherwise not working.
};

DECLARE_TEST(DataDrivenFoo)
#include "DataDrivenFoo.moc"