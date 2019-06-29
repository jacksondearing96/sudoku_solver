#include "Drawer.h"
#include <QThread>
#include <QApplication>

QTableWidget* Drawer::board_;
int** Drawer::currentState_;

int Drawer::speed_ = 1;

void Drawer::SetInitialState(int** initialState)
{
    currentState_ = initialState;
}

void Drawer::Draw(int** state)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (board_->item(row, col)->backgroundColor() == QColor("orange")
                || board_->item(row, col)->backgroundColor() == QColor("red"))
            {
                board_->item(row, col)->setBackgroundColor("white");
            }

            if (state[row][col] != board_->item(row, col)->data(QVariant::Int))
            {
                if (state[row][col] == 0)
                {
                    board_->item(row, col)->setBackgroundColor("orange");
                }
                else
                {
                   board_->item(row, col)->setBackgroundColor("lightgreen");
                }
            }

            board_->item(row, col)->setData(QVariant::Int, state[row][col]);
        }
    }

    QCoreApplication::processEvents();
    QThread::msleep(speed_);
}

void Drawer::DrawBackTrack(int** state)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (state[row][col] != board_->item(row, col)->data(QVariant::Int))
            {

                board_->item(row, col)->setBackgroundColor("orange");
                QCoreApplication::processEvents();
                QThread::msleep(speed_);
                QCoreApplication::processEvents();
            }

            board_->item(row, col)->setData(QVariant::Int, state[row][col]);
        }
    }
}

void Drawer::HighlightContradiction(int row, int col)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (i == row || j == col)
            {
                board_->item(i, j)->setBackgroundColor("red");
            }
        }
    }
    QCoreApplication::processEvents();
    QThread::msleep(speed_ * 7);
    QCoreApplication::processEvents();

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board_->item(i,j)->backgroundColor() == QColor("red"))
            {
                QString newColor = (board_->item(i,j)->data(QVariant::Int) == 0) ? "white" : "lightgreen";
                board_->item(i, j)->setBackgroundColor("white");
            }
        }
    }
}

void Drawer::GameComplete()
{
    QCoreApplication::processEvents();
    SetAllSquaresToColor("lightgreen");
    QCoreApplication::processEvents();
}

void Drawer::SetAllSquaresToColor(QString color)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board_->item(i, j)->backgroundColor() != QColor(color))
            {
                board_->item(i, j)->setBackgroundColor(color);
                QThread::msleep(speed_);
            }
        }
    }
}
