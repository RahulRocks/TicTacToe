#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    bool won = false;
    bool tie = false;
    int winner = 0;
    int X_Score = 0;
    int O_Score = 0;
    int Tie_Score = 0;
    void checkBoard();
    void Winner();
    void Tie();
    void clearBoardGUI();
private:
    Ui::MainWindow *ui;
    int pressCount;


private slots :
    void button_pressed1();
    void button_pressed2();
    void button_pressed3();
    void button_pressed4();
    void button_pressed5();
    void button_pressed6();
    void button_pressed7();
    void button_pressed8();
    void button_pressed9();
    void clear_button_pressed();
    void reset_button_pressed();


};
#endif // MAINWINDOW_H
