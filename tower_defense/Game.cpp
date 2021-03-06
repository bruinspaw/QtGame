#include "Game.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Tower.h"
#include <QGraphicsScene>

Game::Game()
    : QGraphicsView()
{
    // create a scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 600);

    // set the scene
    setScene(scene);

    // create a tower
    Tower *t = new Tower();

    // add the tower to scene
    scene->addItem(t);

    // alter window
    setFixedSize(800, 600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // create enemy
    Enemy *enemy = new Enemy();
    enemy->setPos(700, 0);
    scene->addItem(enemy);
}

void Game::mousePressEvent(QMouseEvent *event)
{
    //create a bullet
    Bullet *bullet = new Bullet();
    bullet->setPos(event->pos());
    bullet->setRotation(40);
    scene->addItem(bullet);
}
