#ifndef CONFIG_H
#define CONFIG_H

/*---------------------主角恐龙数据配置---------------------*/
#define DINOSAUR_PATH ":/res/resourse/dinosaur%1.png"//小恐龙资源路径
#define DINOSAUROVER_PATH ":/res/resourse/gameover.png"//游戏结束时小恐龙路径
#define DINOSAUR_NUM 800//数量
#define DINOSAUR_MAX 2//图片最大索引
#define DINOSAUR_INTERVAL 5//切图时间间隔
/*---------------------游戏数据配置------------------------*/
#define GAME_WIDTH 830//宽度
#define GAME_HEIGHT 372//高度
#define GAME_TITLE "Chrome小恐龙的奇妙冒险 v1.0"//标题
#define GAME_ICON ":/res/resourse/dinosaur1.png"//标题图片路径
#define GAME_RATE 20//定时器刷新时间间隔，10毫秒
/*---------------------地图数据配置------------------------*/
#define MAP1_PATH ":/res/resourse/MAP1.png"//第一张图片资源路径
#define MAP2_PATH ":/res/resourse/MAP2.png"//第二张图片资源路径
#define MAP_SCROLL_SPEED 15//滚动速度为5像素
/*---------------------子弹配置数据------------------------*/
#define BULLET_PATH ":/res/resourse/bullet2.png"
#define BULLET_SPEED 5//子弹移动速度
#define BULLET_NUM 10//子弹数量
#define BULLET_INTERVAL 1//发射子弹时间间隔
/*---------------------敌人1（仙人掌）配置数据---------------*/
#define ENEMY1_PATH ":/res/resourse/enemy1.png"//仙人掌资源路径
#define ENEMY1_SPEED 15//敌人移动速度
#define ENEMY1_NUM 5//敌人总数量
//#define ENEMY_INTERVAL 120//敌人出场时间间隔
/*---------------------食物配置数据-------------------------*/
#define FOOD1_PATH ":/res/resourse/apple1.png"//苹果资源路径
#define FOOD1_SPEED 10//苹果移动速度
#define FOOD1_NUM 5//苹果数量
#define FOOD2_PATH ":/res/resourse/apple2.png"//金苹果资源路径
#define FOOD2_SPEED 10//金苹果移动速度
#define FOOD2_NUM 3//金苹果数量
/*---------------------敌人2（翼龙）配置数据---------------*/
#define ENEMY2_PATH ":/res/resourse/dinosa3.png"//翼龙资源路径
#define ENEMY2_SPEED 5//敌人2移动速度
#define ENEMY2_NUM 1//敌人2总数量
/*--------------------音效配置数据------------------------*/
#define SOUND_BACKGROUND ":/res/resourse/weaver.wav"//背景音乐路径
#define SOUND_BOMB
#endif // CONFIG_H
