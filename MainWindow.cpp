#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include "Game.h"
#include "Player.h"
#include "Drawer.h"

#include <memory>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("SUDOKU Solver");
    SetupBoard();
    Drawer::board_ = ui->board;
    this->setWindowTitle("SUDOKU Solver");
}

void MainWindow::SetupBoard()
{

    for (int i=0; i<ui->board->horizontalHeader()->count(); i++)
    {
        ui->board->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
        ui->board->verticalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
        ui->board->horizontalHeader()->setStyleSheet("border-left : red");
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            QTableWidgetItem* item = new QTableWidgetItem();
            ui->board->setItem(i, j, item);
            item->setTextAlignment(Qt::AlignCenter);
            item->setBackgroundColor(QColor("white"));
            QFont font;
            font.setPointSize(23);
            item->setFont(font);
        }
    }

    // FOR TESTING //

        int testState[9][9] = {
                                {0,4,0,5,0,0,2,1,0},
                                {0,0,5,1,4,8,7,0,0},
                                {8,0,0,0,0,0,0,0,0},
                                {2,0,3,0,0,0,0,5,0},
                                {0,1,0,0,0,0,0,2,0},
                                {0,5,0,0,0,0,8,0,3},
                                {0,0,0,0,0,0,0,0,6},
                                {0,0,7,9,8,3,5,0,0},
                                {0,8,4,0,0,6,0,7,0},
                            };

        for (int i=0 ; i<9 ; i++) {
            for (int j=0 ; j<9 ; j++) {
                ui->board->item(i,j)->setData(QVariant::Int, testState[i][j]);
            }
        }
}

void MainWindow::ExtractBoardData()
{
    initialState_ = new int*[9];
    for (int i = 0; i < 9; i++)
    {
        initialState_[i] = new int[9];
    }

    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            QVariant data = ui->board->item(row, col)->data(QVariant::Int);
            initialState_[row][col] = (data.isNull()) ? 0 : data.toInt();
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Drawer::speed_ = ui->speedSlider->maximum() - ui->speedSlider->value();
    ui->pushButton->setDisabled(true);
    ExtractBoardData();
    std::shared_ptr<Game> game = std::make_shared<Game>(initialState_);
    std::shared_ptr<Player> player = std::make_shared<Player>(game);
    Drawer::SetInitialState(initialState_);
    player->playGame();
    Drawer::GameComplete();
    ui->pushButton->setEnabled(true);
}

void MainWindow::on_reset_clicked()
{
    SetupBoard();
    Drawer::SetAllSquaresToColor("white");
}
