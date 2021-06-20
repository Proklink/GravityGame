#include "widget.h"
#include "ui_widget.h"
#include "planetbuilder.h"
#include <QDebug>
#include <iostream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , scene(new Scene(this))
    , gameLogic(new GameLogic)
    , itemSettingsDialog(new ItemSettingsDialog)
{
    Init();

}

Widget::~Widget()
{
    delete ui;   
    delete gameLogic;
    delete itemSettingsDialog;
}

void Widget::Init()
{
    ui->setupUi(this);
    setFixedSize(900, 850);
    scene->setSceneRect(0, 0, cSceneWidth, cSceneHeight);
    ui->graphicsView->setScene(scene);

    connect(ui->PauseButton, &QPushButton::clicked, gameLogic->GetTimer(), &QTimer::stop);
    connect(ui->ContinueButton, SIGNAL(clicked()), gameLogic->GetTimer(), SLOT(start()));
    connect(ui->DeleteButton, &QPushButton::clicked, this, &Widget::DeleteButtonClicked);
    connect(this, &Widget::SignalDeleteItems, gameLogic, &GameLogic::DeleteItems);

    connect(scene, &Scene::SignalPress, gameLogic, &GameLogic::SlotAddHeavyItem);
    connect(scene, &Scene::SignalRelease, gameLogic, &GameLogic::SlotDeleteHeavyItem);
    connect(scene, &Scene::SignalSendParams, this, &Widget::CreateItemSettingsDialog);
    connect(scene, SIGNAL(SignalStartTimer()), gameLogic->GetTimer(), SLOT(start()));
    connect(scene, SIGNAL(SignalStopTimer()), gameLogic->GetTimer(), SLOT(stop()));
    connect(itemSettingsDialog, &ItemSettingsDialog::SignalSendObjectParametrs, scene, &Scene::SlotSetParametrsToItem);

    QString rawPath = QCoreApplication::applicationDirPath();
    picPath = rawPath.left(rawPath.indexOf("build") - 1) + "/GravityGame/backs/kosmos";
    background = new ProxyImage(picPath + "0.jpg");
}

void Widget::DeleteButtonClicked()
{
    emit SignalDeleteItems();
    scene->clear();
}

void Widget::CreatePlanetClicked()
{
    obj = gameLogic->AddItem();
    scene->addItem(obj);
    obj->setFlag(QGraphicsItem::ItemIsMovable);
}

void Widget::CreateItemSettingsDialog(ObjectParametrs _parametrs)
{
    itemSettingsDialog->SetParametrs(_parametrs.mass,
                                     _parametrs.radious,
                                     _parametrs.xSpeed,
                                     _parametrs.ySpeed);
    itemSettingsDialog->exec();
}

void Widget::BackgroundClicked() {
    QBrush *ibrush = new QBrush;

    ibrush->setTextureImage(*background->getImage());
    scene->setBackgroundBrush(*ibrush);

    backgroundImageConuter++;
    backgroundImageConuter %= ImageNumber;
    background = new ProxyImage(picPath + QString::number(backgroundImageConuter) +".jpg");
}
