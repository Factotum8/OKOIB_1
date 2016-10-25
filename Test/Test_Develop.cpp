#include <QString>
#include <QtTest>
#include "develop.h"


class Test_Develop : public QObject
{
    Q_OBJECT

public:
    Test_Develop();

private Q_SLOTS:
    void init_number_employees();
};

Test_Develop::Test_Develop()
{
}

void Test_Develop::init_number_employees()
{
    Develop develop;

    QVERIFY2(true, "Failure");
    QCOMPARE(develop.init_number_employees(2,2),void)
}

QTEST_APPLESS_MAIN(Test_Develop)

#include "Test_Develop.moc"
