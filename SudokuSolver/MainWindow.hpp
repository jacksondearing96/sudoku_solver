#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_reset_clicked();

private:
    Ui::MainWindow *ui;

    int** initialState_;

    void SetupBoard();
    void ExtractBoardData();
};

#endif // MAINWINDOW_H
