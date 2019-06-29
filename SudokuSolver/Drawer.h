#ifndef DRAWER_H
#define DRAWER_H

#include <QTableWidget>

class Drawer
{
public:
    static int speed_;

    static QTableWidget* board_;

    static void Draw(int** state);
    static void SetInitialState(int** initialState);

    static int** currentState_;

    static void HighlightContradiction(int row, int col);
    static void GameComplete();
    static void SetAllSquaresToColor(QString color);

    static void DrawBackTrack(int** state);
};

#endif // DRAWER_H
