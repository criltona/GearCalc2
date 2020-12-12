#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "equip.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    struct gearSet{
        int baseDr = 245;
        int baseAcc = 359;
        int baseEva = 593;
        int baseAp = 175;
        int baseDp = 309;
        int baseCost = 0;
        QList<Equip> equipment;
        int finalEva;
        int finalDr;
        int finalAp;
        int finalAcc;
        int finalDp;
        int finalCost;

    };
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void doStuff();
    void addItems();
    void genEars();
    void genNeck();
    void genBelt();
    void genRings();
    void genHelm();
    void printEquip(Equip e);
    void createSets();
    void tallyGear();
    void filterGear(int reqDr, int reqAcc, int reqEva, int reqAp, int reqDp, int reqCost);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QList<Equip> items;
    QList<gearSet> gears;
    QList<gearSet> filtered;
    void printAllGearsets();
    void printSet(gearSet g);
    void sortSets(int sortBy);
};
#endif // MAINWINDOW_H
