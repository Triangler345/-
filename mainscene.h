#ifndef MAINSCENE_H
#define MAINSCENE_H
#include <help.h>
#include <QWidget>
#include "map.h"
#include "food.h"
#include "food2.h"
#include "enemy.h"
#include<QTimer>
#include "dinosaur.h"
#include "pterosaur.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class Mainscene;
}
QT_END_NAMESPACE

class Mainscene : public QWidget
{
    Q_OBJECT

public:
    Mainscene(QWidget *parent = nullptr);


    ~Mainscene();

    //初始化场景
    void initScene();
    //启动游戏
    void playGame();
    //更新所有游戏元素的坐标
    void updatePosition();
    //绘制到屏幕中  !!!此函数名称固定
    void paintEvent(QPaintEvent *);
    //定义键盘事件
    void keyPressEvent(QKeyEvent *key);
    //恐龙移动方向
    int nDirection;
    //敌人1（仙人掌）出场
    void enemyToScene();
    //碰撞1检测
    void collisionDetection1();
    //敌人1（仙人掌）数组
    Enemy m_enemys[ENEMY1_NUM];
    //敌人1（仙人掌）出场时间间隔记录
    int m_recorder;
    //苹果出场
    void food1ToScene();
    //碰撞2检测
    void collisionDetection2();
    //苹果数组
    food m_food1[FOOD1_NUM];
    //苹果出场时间间隔记录
    int m_recorderfood;
    //金苹果出场
    void food2ToScene();
    //碰撞3检测
    void collisionDetection3();
    //金苹果数组
    food2 m_food2[FOOD2_NUM];
    //金苹果出场时间间隔记录
    int m_recorderfood2;
    //翼龙出场
    void enemy2ToScene();
    //碰撞4检测
    void collisionDetection4();
    //翼龙数组
    pterosaur m_enemy2;
    //翼龙出场时间间隔记录
    int m_recorder2;
    //地图对象
    Map m_map;
    //恐龙对象
    dinosaur m_dino;
    //设定定时器
    QTimer m_Timer;
    QTimer Timer;
    //恐龙数组
    dinosaur m_dinos[DINOSAUR_NUM];
    bool flag;
    int direction1,direction2,direction3,direction4;
    QString sDisplay;//开始结束提示
    QString healthLabel;//显示生命值三个字
    int health=200;
    QString sDisplay2;//开始结束提示
    QString scoreLabel;//显示生命值三个字
    int score=0;
    bool blsOver=false;
    bool play=false;
    Help n_help;
public slots:
    void dinosaur_update();
private:
    Ui::Mainscene *ui;
};
#endif // MAINSCENE_H
