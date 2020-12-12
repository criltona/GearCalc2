#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
//int reqDr, int reqAcc, int reqEva, int reqAp, int reqDp, int reqCost
void MainWindow::doStuff(){
    addItems();
    genEars();
    genRings();
    createSets();
   \
}

MainWindow::~MainWindow()
{
    delete ui;
}
//1 = helm
//2 = ear
//3 = belt
//4 = ring
//5 = neck
//6 = alch
// eva, dr, ap, acc, dp, name, slot
void MainWindow::addItems(){
    items.push_back(Equip(122,68,0,0,88,"Heve",1,25));
    items.push_back(Equip(104,90,0,0,96,"Griffon",1,80));
    items.push_back(Equip(0,-5,21,16,-5,"Disto",2,105));
    items.push_back(Equip(0,0,14,38,0,"Dawn",2,85));
    items.push_back(Equip(0,0,17,12,0,"Tungrad Ear",2,30));
    items.push_back(Equip(0,0,20,12,0,"Basi",3,38));
    items.push_back(Equip(0,0,17,34,0,"Turo",3,120));
    items.push_back(Equip(60,0,0,12,20,"Centaur",3,30));
    items.push_back(Equip(0,0,21,12,0,"Tungrad Belt",3,105));
    items.push_back(Equip(0,0,20,12,0,"Crescent",4,40));
    items.push_back(Equip(0,0,21,12,0,"Tungrad Ring",4,80));
    items.push_back(Equip(0,0,18,26,0,"Ominous",4,100));
    items.push_back(Equip(0,0,35,24,0,"Ogre",5,80));
    items.push_back(Equip(39,0,22,24,13,"Sicil",5,30));
    items.push_back(Equip(0,0,3,1,0,"Vell",6,10));
    items.push_back(Equip(0,0,0,14,0,"Destuction",6,30));
}
void MainWindow::genEars(){
    QList<Equip> combo;
    int comboEva;
    int comboDr;
    int comboAp;
    int comboAcc;
    int comboDp;
    int comboCost;
    QString comboName;

    for(int i = 0; i < items.length();i++){
        if(items[i].slot == 2){
            qDebug() << "Found one";
            for(int j =i; j < items.length(); j++){
                if(items[j].slot == 2){
                    comboEva = items[i].eva + items[j].eva;
                    comboDr = items[i].dr + items[j].dr;
                    comboAp = items[i].ap + items[j].ap;
                    comboAcc = items[i].acc + items[j].acc;
                    comboDp = items[i].dp + items[j].dp;
                    comboCost = items[i].cost + items[j].cost;
                    comboName = items[i].name + " + " + items[j].name;
                    combo.push_back(Equip(comboEva, comboDr,comboAp,comboAcc,comboDp,comboName,2, comboCost));

                }
            }
        }
    }
    QList<int> nums;
    for(int i =0; i < items.length();i++){
        if(items[i].slot == 2)
           nums.push_back(i);
    }
    int p = 0;
    for(int i = 0; i < nums.length(); i++){
        items.removeAt(nums[i-p++]);
    }
    for(int i = 0; i < combo.length(); i++){
        items.push_back(combo[i]);
     }

}
void MainWindow::genRings(){
    QList<Equip> combo;
    int comboEva;
    int comboDr;
    int comboAp;
    int comboAcc;
    int comboDp;
    int comboCost;
    QString comboName;

    for(int i = 0; i < items.length();i++){
        if(items[i].slot == 4){
            for(int j =i; j < items.length(); j++){
                if(items[j].slot == 4){
                    comboEva = items[i].eva + items[j].eva;
                    comboDr = items[i].dr + items[j].dr;
                    comboAp = items[i].ap + items[j].ap;
                    comboAcc = items[i].acc + items[j].acc;
                    comboDp = items[i].dp + items[j].dp;
                    comboCost = items[i].cost + items[j].cost;
                    comboName = items[i].name + " + " + items[j].name;

                    combo.push_back(Equip(comboEva, comboDr,comboAp,comboAcc,comboDp,comboName,4, comboCost));

                }
            }
        }
    }
    QList<int> nums;
    for(int i =0; i < items.length();i++){
        if(items[i].slot == 4)
           nums.push_back(i);
    }
    int p = 0;
    for(int i = 0; i < nums.length(); i++){
        items.removeAt(nums[i-p++]);
    }
    for(int i = 0; i < combo.length(); i++){
        items.push_back(combo[i]);

     }

}
void MainWindow::printEquip(Equip e){
    qDebug() << e.name;
    qDebug() << "EVA: " + QString::number(e.eva);
    qDebug() << "DR: " + QString::number(e.dr);
    qDebug() << "Ap: " + QString::number(e.ap);
    qDebug() << "Acc: " + QString::number(e.acc);
    qDebug() << "Dp: " + QString::number(e.dp);
    qDebug() << "Cost: " + QString::number(e.cost);

    qDebug() << "";
}
//1 = helm
//2 = ear
//3 = belt
//4 = ring
//5 = neck
//6 = alch
void MainWindow::createSets(){


    QList<gearSet> holdGears;
    gearSet g1, g2;
    g1.equipment.push_back(items[0]);
    g2.equipment.push_back(items[1]);
    gears.push_back(g1);
    gears.push_back(g2);

    //add ears
    for(int i = 0; i < items.length(); i++){
        if(items[i].slot == 2){
            for(int p = 0; p < gears.length(); p++){
                gearSet g = gears[p];
                g.equipment.push_back(items[i]);
                holdGears.push_back(g);
            }
        }
    }
    //add belt
    gears = holdGears;
    holdGears.clear();
    for(int i = 0; i < items.length(); i++){
        if(items[i].slot == 3){
            for(int p = 0; p < gears.length(); p++){
                gearSet g = gears[p];
                g.equipment.push_back(items[i]);
                holdGears.push_back(g);
            }
        }
    }
    //add ring
    gears = holdGears;
    holdGears.clear();
    for(int i = 0; i < items.length(); i++){
        if(items[i].slot == 4){
            for(int p = 0; p < gears.length(); p++){
                gearSet g = gears[p];
                g.equipment.push_back(items[i]);
                holdGears.push_back(g);
            }
        }
    }
    //add neck
    gears = holdGears;
    holdGears.clear();
    for(int i = 0; i < items.length(); i++){
        if(items[i].slot == 5){
            for(int p = 0; p < gears.length(); p++){
                gearSet g = gears[p];
                g.equipment.push_back(items[i]);
                holdGears.push_back(g);
            }
        }
    }
    //add alch
    gears = holdGears;
    holdGears.clear();
    for(int i = 0; i < items.length(); i++){
        if(items[i].slot == 6){
            for(int p = 0; p < gears.length(); p++){
                gearSet g = gears[p];
                g.equipment.push_back(items[i]);
                holdGears.push_back(g);
            }
        }
    }
    gears = holdGears;
    holdGears.clear();
    tallyGear();
}
void MainWindow::tallyGear(){
    for(int i = 0; i < gears.length(); i++){
        for(int p = 0; p < gears[i].equipment.length(); p++){
            gears[i].baseAp += gears[i].equipment[p].ap;
            gears[i].baseAcc += gears[i].equipment[p].acc;
            gears[i].baseDp += gears[i].equipment[p].dp;
            gears[i].baseDr += gears[i].equipment[p].dr;
            gears[i].baseEva += gears[i].equipment[p].eva;
            gears[i].baseCost += gears[i].equipment[p].cost;
        }
    }
}

/*
int baseDr = 245;
int baseAcc = 359;
int baseEva = 593;
int baseAp = 175;
int baseDp = 309;
int baseCost = 0;
*/
void MainWindow::filterGear(int reqDr, int reqAcc, int reqEva, int reqAp, int reqDp, int reqCost){
    filtered.clear();
    for(int i = 0; i < gears.length(); i++){

        if(gears[i].baseDr < reqDr)
            continue;
        if(gears[i].baseAcc < reqAcc)
            continue;
        if(gears[i].baseEva < reqEva)
            continue;
        if(gears[i].baseAp < reqAp)
            continue;
        if(gears[i].baseDp < reqDp)
            continue;
        if(gears[i].baseCost > reqCost)
            continue;
        filtered.push_back(gears[i]);
    }
}
void MainWindow::printAllGearsets(){
    for(int i = 0; i < filtered.length(); i++){
        printSet(filtered[i]);
    }
}
void MainWindow::printSet(gearSet g){
    QString q = "";
    q += "GEARSET::: ";
    for(int i = 0; i < g.equipment.length(); i++){
        q += g.equipment[i].name;
        q+= ", ";

    }
    q+= '\n';
    q += "Eva: " + QString::number(g.baseEva);
    q += ", DR: " + QString::number(g.baseDr);
    q += ", DP: " + QString::number(g.baseDp);
    q += ", Ap: " + QString::number(g.baseAp);
    q += ", ACC: " + QString::number(g.baseAcc);
    q += ", Cost: " + QString::number(g.baseCost);
   // printf("Eva: %d, Dr: %d, Dp: %d, Ap: %d, Acc: %d, Cost: %d", g.baseEva, g.baseDr, g.baseDp, g.baseAp, g.baseAcc, g.baseCost);
     q+= '\n';
     ui->listWidget->addItem(q);
}
//(int reqDr, int reqAcc, int reqEva, int reqAp, int reqDp, int reqCost){
void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->clear();
    filterGear(ui->drEdit->text().toInt(), ui->accEdit->text().toInt(), ui->evaEdit->text().toInt(),
               ui->apEdit->text().toInt(), ui->dpEdit->text().toInt(), ui->costEdit->text().toInt());
    sortSets(ui->comboBox->currentIndex() +1);
    printAllGearsets();

}
void MainWindow::sortSets(int sortBy){
    QList<gearSet> sorted;
    int max;
    int stat;
    int curMax;
    for(int p = 0; p < filtered.length(); p++){
        int curMax = 0;
        if(sortBy == 6)
            curMax = 999999;
        for(int i = 0; i < filtered.length(); i++){
            if(sortBy == 1){
                stat = filtered[i].baseAp;
            }else if(sortBy == 2){
                stat = filtered[i].baseDp;
            }else if(sortBy == 3){
                stat = filtered[i].baseEva;
            }else if(sortBy == 4){
                stat = filtered[i].baseDr;
            }else if(sortBy == 5){
                stat = filtered[i].baseAcc;
            }else if(sortBy == 6){
                stat = filtered[i].baseCost;
            }
            if(sortBy <= 5){
                if(stat > curMax){
                curMax = stat;
                max = i;
                }
            }else{
                if(stat < curMax){
                curMax = stat;
                max = i;
                }
            }
        }


        sorted.push_back(filtered[max]);
        filtered[max].baseAp = 0;
        filtered[max].baseDp = 0;
        filtered[max].baseEva = 0;
        filtered[max].baseDr = 0;
        filtered[max].baseAcc = 0;
        filtered[max].baseCost = 999999;

    }
    filtered = sorted;
}
