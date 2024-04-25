#include "mainscene.h"
#include "ui_mainscene.h"
#include "config.h"
#include "help.h"
#include <qtimer.h>
#include <ctime>
#include <QICon>
#include <QPainter>
#include <QMouseEvent>
#include<QKeyEvent>//键盘事件
#include <QMediaPlayer>
#include <QSoundEffect>
Mainscene::Mainscene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Mainscene)
{
    ui->setupUi(this);
    initScene();//调用初始化场景
   // Help *m_help=new Help(this);
    playGame();//启动游戏
}
void Mainscene::initScene()
{
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);//设置界面长宽
    setWindowTitle(GAME_TITLE);//设置标题
    setWindowIcon(QIcon(GAME_ICON));//加载图标
    m_Timer.setInterval(GAME_RATE);//定时器设置
    //仙人掌、苹果、金苹果、翼龙出场时间间隔
    m_recorder=0;
    m_recorderfood=0;
    m_recorderfood2=0;
    m_recorder2=0;
    flag=false;
    //随机数种子
    srand((unsigned int)time(NULL));
    sDisplay="游戏开始";
    healthLabel="生命值:";
    sDisplay2="游戏开始";
    scoreLabel="得分:";
    // 创建音频对象
    QMediaPlayer *player = new QMediaPlayer;

    // 设置音频源
    player->setSource(QUrl::fromLocalFile("C:\\Users\\45257\\Desktop\\T\\QTproject\\Dinosaur\\resourse\\weaver.wav"));
    // 控制音频播放
    player->play();
}
void Mainscene::playGame()
{

//启动背景音乐
    /*QMediaPlayer player;
    QAudioOutput audioOutput;
    player.setAudioOutput(&audioOutput);
    player.setSource(QUrl::fromLocalFile(":\res\resourse\weaver.wav"));
    player.play();*/
//QSoundEffect *startSound=new QSoundEffect(this);
   // startSound->setSource(QUrl::fromLocalFile(":/res/resourse/weaver.wav"));
    //startSound->setLoopCount(QSoundEffect::Infinite);
    //startSound->setVolume(0.5f);
    //startSound->play();
    m_Timer.start();//启动定时器
    //监听定时器发出的信号
    Timer.start(300);
    connect(&Timer,SIGNAL(timeout()),SLOT(dinosaur_update()));
    connect(&m_Timer,&QTimer::timeout,[=]{
        //敌人1出场
        enemyToScene();
        //苹果出场
        food1ToScene();
        //金苹果出场
        food2ToScene();
        //翼龙出场
        enemy2ToScene();
        //更新游戏中元素的坐标
        updatePosition();
        //绘制到屏幕中
        update();//update函数与paintEvent函数自动绑定，更新即更新paintEvenet
        for(int k=0;k<DINOSAUR_NUM;k++)
        {
            //更新坐标
            m_dinos[k].m_X=m_dino.m_X;
            m_dinos[k].m_Y=m_dino.m_Y;
        }
        //碰撞检测
        collisionDetection1();
        collisionDetection2();
        collisionDetection3();
        collisionDetection4();
    });
}
void Mainscene::keyPressEvent(QKeyEvent *key)
{
    switch(key->key())
    {
    case Qt::Key_Up:nDirection=1;//1代表上
        break;
    case Qt::Key_Down:nDirection=2;//2代表下
        break;
    case Qt::Key_Left:nDirection=3;//3代表左
        break;
    case Qt::Key_Right:nDirection=4;//4代表右
        break;
    case Qt::Key_J:flag=true;//可以发射子弹
        break;
    default:nDirection=0;
    }
}
void Mainscene::updatePosition()
{
    sDisplay="";
    //更新地图的坐标
    m_map.mapPosition();
    //发射子弹
    if(flag)
    {m_dino.shoot();
    flag=false;}
    //计算所有非空闲子弹的当前坐标
    for(int i=0;i<BULLET_NUM;i++)
    {
        //如果非空闲，计算发射位置
        if(m_dino.m_bullets[i].m_Free==false)
        {
            m_dino.m_bullets[i].updatePosition();
        }
    }
}
void Mainscene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);//画到当前屏幕

    //绘制地图
    painter.drawPixmap(m_map.m_map1_posX,0,m_map.m_map1);
    painter.drawPixmap(m_map.m_map2_posX,0,m_map.m_map2);
    //绘制主角恐龙
   // painter.drawPixmap(m_dino.m_X,GAME_HEIGHT-m_dino.m_Y-48,m_dino.m_dinosaur1);

    //绘制主角恐龙
    for(int i=0;i<DINOSAUR_NUM;i++)
    {
        painter.drawPixmap(m_dinos[i].m_X+10,GAME_HEIGHT-2*m_dinos[i].m_Y-150,m_dinos[i].m_pixArr[m_dinos[i].m_index]);
    }
    //绘制苹果
    for(int i=0;i<FOOD1_NUM;i++)
    {
        if(m_food1[i].m_Free==false)
        {
            painter.drawPixmap(m_food1[i].m_X,242,m_food1[i].m_food1);

        }
    }
    //绘制金苹果
    for(int i=0;i<FOOD2_NUM;i++)
    {
        if(m_food2[i].m_Free==false)
        {
            painter.drawPixmap(m_food2[i].m_X,142,m_food2[i].m_food2);

        }
    }

    //绘制敌人1（仙人掌）
    for(int i=0;i<ENEMY1_NUM;i++)
    {
        if(m_enemys[i].m_Free==false)
        {
            painter.drawPixmap(m_enemys[i].m_X,242,m_enemys[i].m_enemy);

        }
    }

    //绘制敌人2（翼龙）
        if(m_enemy2.m_Free==false)
        {
            painter.drawPixmap(m_enemy2.m_X,0,m_enemy2.m_enemy);

        }
    //绘制子弹
    for(int i=0;i<BULLET_NUM;i++)
    {
        //如果非空闲，计算发射位置
        if(m_dino.m_bullets[i].m_Free==false)
            painter.drawPixmap(m_dino.m_bullets[i].m_X+70,/*240*/GAME_HEIGHT-m_dino.m_bullets[i].m_Y-150,m_dino.m_bullets[i].m_Bullet);
    }
    //苹果出场
    for(int i=0;i<FOOD1_NUM;i++)
    {
        if(m_food1[i].m_Free==false)
        {
            m_food1[i].CreateRect();
        }
    }
    //金苹果出场
    for(int i=0;i<FOOD2_NUM;i++)
    {
        if(m_food2[i].m_Free==false)
        {
            m_food2[i].CreateRect();
        }
    }
    //敌人1（仙人掌）出场
    for(int i=0;i<ENEMY1_NUM;i++)
    {
        if(m_enemys[i].m_Free==false)
        {
            m_enemys[i].updatePosition();
        }
    }
    //敌人2（翼龙）出场
        if(m_enemy2.m_Free==false)
        {
            m_enemy2.updatePosition();
        }
        //显示游戏开始、结束
        QFont font1("str",15);
        painter.setFont(font1);
        painter.setPen(Qt::red);
        painter.setBrush(Qt::red);
        painter.drawText(m_dino.m_X+10,GAME_HEIGHT-2*m_dino.m_Y-150,sDisplay);
        //得分显示
        QFont font2("Courier",20);
        painter.setFont(font2);
        painter.setPen(Qt::red);
        painter.setBrush(Qt::white);
        painter.drawText(0,50,healthLabel);
        painter.drawText(100,50,QString::number(health));
        painter.drawText(0,80,scoreLabel);
        painter.drawText(100,80,QString::number(score));
    //计算播放的图片
    for(int i=0;i<DINOSAUR_NUM;i++)
    {
            m_dinos[i].updateInfo();
    }
    if(blsOver)
    {
        painter.drawPixmap(m_dino.m_X+10,GAME_HEIGHT-2*m_dino.m_Y-150,m_dino.gameover);
        sDisplay="游戏结束"; painter.drawText(m_dino.m_X+10,GAME_HEIGHT-2*m_dino.m_Y-150,sDisplay);
        m_Timer.stop();
        Timer.stop();
    }
}
void Mainscene::dinosaur_update()
{
    if((m_dino.m_X<=0&&nDirection==3)||((m_dino.m_X>=(720-m_dino.m_dinosaur1.width()))&&nDirection==4))
    {
        nDirection=2;//flag=true;
    }
    if(GAME_HEIGHT-2*m_dino.m_Y-150<215)
    {
        nDirection=6;
    }
    switch(nDirection)
    {
    case 4:
        m_dino.m_X+=10;
        direction1=4;
        direction3=4;
        direction2=0;
        direction4=0;
        break;
    case 3:
        m_dino.m_X-=10;
        direction1=0;
        direction2=3;
        direction3=0;
        direction4=3;
        break;
    case 2:
        m_dino.m_X=m_dino.m_X;
        direction3=0;
        direction4=0;
        break;
    case 1:
        m_dino.m_Y+=60;
        if(direction1==4)
        {m_dino.m_X+=10;direction1=0;}
        if(direction2==3)
        {m_dino.m_X-=10;direction2=0;}
        nDirection=5;//跳起}
       // flag2=true;
        break;
    case 5:
        //if(!flag||flag2)
        //{
            m_dino.m_Y-=60;//落下
            //flag2=false;}
        nDirection=0;//防止一直落下
        break;
    case 6:
        if(GAME_HEIGHT-2*m_dino.m_Y-150<215)
        {
            nDirection=6;
            m_dino.m_Y-=60;
        }
        else
        {
            if(direction3)
            nDirection=direction3;
            else
            nDirection=direction4;
        }
    default:;
    }
    if(health<=0)
    {

        blsOver=true;
    }
}
void Mainscene::enemyToScene()
{
    m_recorder++;
    if(m_recorder<rand()%40000)//未达到出场间隔
    {
        return;
    }
    m_recorder=0;
    for(int i=0;i<ENEMY1_NUM;i++)
    {
        //如果是空闲敌人1，出场
        if(m_enemys[i].m_Free)
        {
            m_enemys[i].m_Free=false;
            //坐标
            m_enemys[i].m_X=GAME_WIDTH;//rand()%(GAME_WIDTH-m_enemys[i].m_Rect.width());
            m_enemys[i].m_Y=/*GAME_HEIGHT-2*m_dinos[i].m_Y-150*/250;
            break;
        }
    }
}

void Mainscene::collisionDetection1()
{
    //遍历所有非空闲敌人1
    for(int i=0;i<ENEMY1_NUM;i++)
    {

        if(m_enemys[i].m_Free)
        {
            continue;//如果是空闲敌人，执行下一次循环
        }
        else//如果恐龙和仙人掌发生碰撞
        if(m_dino.m_Y<50)
        {if(m_enemys[i].m_X-m_dino.m_X<=70&&m_enemys[i].m_X-m_dino.m_X>50)
            {
                sDisplay="痛";
                health-=10;
            }
        else if(m_enemys[i].m_X-m_dino.m_X<=90&&m_enemys[i].m_X-m_dino.m_X>70)
            {
                sDisplay="啊！";
                health-=20;
            }
        else if(m_enemys[i].m_X-m_dino.m_X<=50&&m_enemys[i].m_X-m_dino.m_X>20)
            {
                sDisplay="好痛！";
                health-=30;
            }
        else if(m_enemys[i].m_X-m_dino.m_X<=20&&m_enemys[i].m_X-m_dino.m_X>0)
            {
                sDisplay="嗷嗷嗷！";
                health-=40;
            }
        }
    }
}

void Mainscene::food1ToScene()
{
    m_recorderfood++;
    if(m_recorderfood<rand()%40000)//未达到出场间隔
    {
        return;
    }
    m_recorderfood=0;
    for(int i=0;i<FOOD1_NUM;i++)
    {
        //如果是空闲苹果，出场
        if(m_food1[i].m_Free)
        {
            m_food1[i].m_Free=false;
            //坐标
            m_food1[i].m_X=GAME_WIDTH;//rand()%(GAME_WIDTH-m_enemys[i].m_Rect.width());
            m_food1[i].m_Y=/*GAME_HEIGHT-2*m_dinos[i].m_Y-150*/250;
            break;
        }
    }
}
void Mainscene::collisionDetection2()
{
    //遍历所有非空闲苹果
    for(int i=0;i<FOOD1_NUM;i++)
    {

        if(m_food1[i].m_Free)
        {
            continue;//如果是空闲苹果，执行下一次循环
        }
        else//如果恐龙和苹果发生碰撞
        {if(m_dino.m_Y<50)
         if(m_food1[i].m_X-m_dino.m_X<=50&&m_food1[i].m_X-m_dino.m_X>30)
            {
                sDisplay="吧唧";
                m_food1[i].m_Free=true;
                score+=20;
            }
        }
    }
}
void Mainscene::food2ToScene()
{
    m_recorderfood2++;
    if(m_recorderfood2<rand()%60000)//未达到出场间隔
    {
        return;
    }
    m_recorderfood2=0;
    for(int i=0;i<FOOD2_NUM;i++)
    {
        //如果是空闲金苹果，出场
        if(m_food2[i].m_Free)
        {
            m_food2[i].m_Free=false;
            //坐标
            m_food2[i].m_X=GAME_WIDTH;//rand()%(GAME_WIDTH-m_enemys[i].m_Rect.width());
            m_food2[i].m_Y=/*GAME_HEIGHT-2*m_dinos[i].m_Y-150*/250;
            break;
        }
    }
}

void Mainscene::collisionDetection3()
{
    //遍历所有非空闲金苹果
    for(int i=0;i<FOOD2_NUM;i++)
    {

        if(m_food2[i].m_Free)
        {
            continue;//如果是空闲金苹果，执行下一次循环
        }
        else//如果恐龙和金苹果发生碰撞
        {
            if(m_food2[i].m_Y-m_dino.m_Y<=200&&m_food2[i].m_Y-m_dino.m_Y>=00)
            if(m_food2[i].m_X-m_dino.m_X<=50&&m_food2[i].m_X-m_dino.m_X>30)
            {
                sDisplay="好吃";
                m_food2[i].m_Free=true;
                score+=30;
                health+=30;
            }
        }
    }
}

void Mainscene::enemy2ToScene()
{
    m_recorder2++;
    if(m_recorder2<rand()%8000000)//未达到出场间隔
    {
        return;
    }
    m_recorder2=0;
        //如果翼龙空闲，出场
        if(m_enemy2.m_Free)
        {
            m_enemy2.m_Free=false;
            //坐标
            m_enemy2.m_X=GAME_WIDTH;//rand()%(GAME_WIDTH-m_enemys[i].m_Rect.width());
            m_enemy2.m_Y=/*GAME_HEIGHT-2*m_dinos[i].m_Y-150*/0;
        }
}
void Mainscene::collisionDetection4()
{
    //检测翼龙是否空闲
 if(m_enemy2.m_Free)
        {
            return;//如果翼龙空闲，执行下一次循环
        }
        //遍历所有非空闲子弹
        for(int j=0;j<BULLET_NUM;j++)
        {
            if(m_dino.m_bullets[j].m_Free)
            {
                continue;
            }
            //如果子弹和翼龙相交，发生碰撞，同时将翼龙和子弹空闲状态设置为真
            if((m_enemy2.m_X-(m_dino.m_bullets[j].m_X+70))<=15&&(m_enemy2.m_X-(m_dino.m_bullets[j].m_X+70))>=-85)
            if((m_enemy2.m_Y-(GAME_HEIGHT-m_dino.m_bullets[j].m_Y-150))>=-40&&(m_enemy2.m_Y-(GAME_HEIGHT-m_dino.m_bullets[j].m_Y-150))<=0)
            {
                m_enemy2.m_Free=true;
                m_dino.m_bullets[j].m_Free=true;
                sDisplay="哇，金色传说！！！";
                health+=200;
                score+=200;
            }
        }
}
Mainscene::~Mainscene()
{
    delete ui;
}
































