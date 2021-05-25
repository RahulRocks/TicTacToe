#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "string.h";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(released()),this,SLOT(button_pressed1()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(button_pressed2()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(button_pressed3()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(button_pressed4()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(button_pressed5()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(button_pressed6()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(button_pressed7()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(button_pressed8()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(button_pressed9()));
    connect(ui->pushButton_10,SIGNAL(released()),this,SLOT(clear_button_pressed()));
    connect(ui->pushButton_11,SIGNAL(released()),this,SLOT(reset_button_pressed()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

// Winning fuction showcases a pop up to illustrate the game and who won, and automatically resets the game board.
void MainWindow::Winner(){
    if(won == true && winner == 1){
        QMessageBox::information(
            this,
            tr("Victorious Approval"),
            tr("Player X is victorious!") );
        X_Score += 1;
        ui->label1->setText("Player X: " + QString :: number(X_Score));
        clear_button_pressed();
    } else if (won == true && winner == 2) {
        QMessageBox::information(
            this,
            tr("Victorious Approval"),
            tr("Player O is victorious!") );
        O_Score += 1;
        ui->label2->setText("Player O: " + QString :: number(O_Score));
        clear_button_pressed();
     }
}



// Tie fuction showcases a pop up to illustrate the game is over becuase its tied,  and automatically resets the game board.
void MainWindow::Tie(){
    int check = 0;
    for (int i = 0; i < 3; ++i)
           {
               for (int j = 0; j < 3; ++j)
               {
                 if  (board[i][j] == ' '){
                     break;
                 }
                 check+=1;
               }
           }
        if(check==9){
        QMessageBox::warning(
            this,
            tr("Prodigious Dissapointment"),
            tr("The Game is tied! Try Again!") );
            clear_button_pressed();
            Tie_Score += 1;
            ui->label3->setText("Tie: " + QString :: number(Tie_Score));
        }

}

//Clears the values on the board
void MainWindow::clear_button_pressed()
{
    for (int i = 0; i < 3; ++i)
       {
           for (int j = 0; j < 3; ++j)
           {
              board[i][j] = ' ';
           }
       }
    won = false;

    clearBoardGUI();
}


//clears the values on the board and labels checking the score (tie and wins).
void MainWindow::reset_button_pressed()
{
   won = false;
   X_Score = 0;
   O_Score = 0;
   Tie_Score = 0;

    for (int i = 0; i < 3; ++i)
       {
           for (int j = 0; j < 3; ++j)
           {
              board[i][j] = ' ';
           }
       }

   ui->label1->setText("Player X: " + QString :: number(X_Score));
   ui->label2->setText("Player O: " + QString :: number(O_Score));
   ui->label3->setText("Tie: " + QString :: number(Tie_Score));

   clearBoardGUI();

}

//Resets each individual button on the UI
void MainWindow::clearBoardGUI() {
    QPushButton * tempPushButton1 = ui->pushButton;
    tempPushButton1->setText(" ");
    tempPushButton1->setStyleSheet(" ");
    tempPushButton1->setDisabled(false);
    QPushButton * tempPushButton2 = ui->pushButton_2;
    tempPushButton2->setText(" ");
    tempPushButton2->setStyleSheet(" ");
    tempPushButton2->setDisabled(false);
    QPushButton * tempPushButton3 = ui->pushButton_3;
    tempPushButton3->setText(" ");
    tempPushButton3->setStyleSheet(" ");
    tempPushButton3->setDisabled(false);
    QPushButton * tempPushButton4 = ui->pushButton_4;
    tempPushButton4->setText(" ");
    tempPushButton4->setStyleSheet(" ");
    tempPushButton4->setDisabled(false);
    QPushButton * tempPushButton5 = ui->pushButton_5;
    tempPushButton5->setText(" ");
    tempPushButton5->setStyleSheet(" ");
    tempPushButton5->setDisabled(false);
    QPushButton * tempPushButton6 = ui->pushButton_6;
    tempPushButton6->setText(" ");
    tempPushButton6->setStyleSheet(" ");
    tempPushButton6->setDisabled(false);
    QPushButton * tempPushButton7 = ui->pushButton_7;
    tempPushButton7->setText(" ");
    tempPushButton7->setStyleSheet(" ");
    tempPushButton7->setDisabled(false);
    QPushButton * tempPushButton8 = ui->pushButton_8;
    tempPushButton8->setText(" ");
    tempPushButton8->setStyleSheet(" ");
    tempPushButton8->setDisabled(false);
    QPushButton * tempPushButton9 = ui->pushButton_9;
    tempPushButton9->setText(" ");
    tempPushButton9->setStyleSheet(" ");
    tempPushButton9->setDisabled(false);
}


// function determeines whether a win has been showcased on the board, if so, links winning fuction to associated player.
void MainWindow::checkBoard()
{
    int  row=0, col=0;
    won = false;
    for ( row=0; row<3; row++ ) {  //horizontal
        if (board[row][col] == ' ' ){
            continue;
        }

        col = 0;
        while ( board[row][col] == 'x' ){
            col++;
        }
        if ( col == 3 ){
            won = true;
            winner = 1;
        }

        col = 0;
        while ( board[row][col] == 'o' ){
            col++;
        }
        if ( col == 3 ){
            won = true;
            winner = 2;
        }
    }

    for ( col=0; col<3; col++ ) {  //vertical
        if (board[row][col] == ' ' ){
            continue;
        }

        row = 0;
        while ( board[row][col] == 'x' ){
            row++;
        }
        if ( row == 3 ){
            won = true;
            winner = 1;
        }

        row = 0;
        while ( board[row][col] == 'o' ){
            row++;
        }
        if ( row == 3 ){
            won = true;
            winner = 2;
        }
    }

    if ( board[0][0] != ' '  ) {  //diagonal top left to bottom right
        if ( board[0][0] == 'x'){
            if ( board[1][1] == 'x'){
                if ( board[2][2] == 'x'){
                     won = true;
                     winner = 1;
                }
            }
        }
        if ( board[0][0] == 'o'){
            if ( board[1][1] == 'o'){
                if ( board[2][2] == 'o'){
                     won = true;
                     winner = 2;
                }
            }
        }
    }

    if ( board[0][2] != ' '  ) {  //diagonal top right to bottom left
        if ( board[0][2] == 'x'){
            if ( board[1][1] == 'x'){
                if ( board[2][0] == 'x'){
                     won = true;
                     winner = 1;
                }
            }
        }
        if ( board[0][2] == 'o'){
            if ( board[1][1] == 'o'){
                if ( board[2][0] == 'o'){
                     won = true;
                     winner = 2;
                }
            }
        }
    }
    if (won == true ){
        Winner();
    } else {
        Tie();
    }




}


// When players pressses a button, deals with applying an x and o within the indexes of the ui and the associated color while preventing from clicking on it again.
void MainWindow::button_pressed1(){
    QPushButton * button = (QPushButton*)sender();
    if (pressCount++%2==0){
        button->setText("x");
        button->setStyleSheet("background-color: rgb(252, 175, 62);color: red;");
        board[0][0] = 'x';
        button->setDisabled(true);
        checkBoard();
    } else {
        button->setText("o");
        button->setStyleSheet("background-color: rgb(252, 175, 62);color: blue;");
        board[0][0] = 'o';
        button->setDisabled(true);

        checkBoard();
    }
}
// When players pressses a button,  deals with applying an x and o within the indexes of the ui and the associated color while preventing from clicking on it again.
void MainWindow::button_pressed2(){
    QPushButton * button = (QPushButton*)sender();
    if (pressCount++%2==0){
        button->setText("x");
        button->setStyleSheet("background-color: rgb(252, 175, 62);color: red;");
        board[0][1] = 'x';

        button->setDisabled(true);
        checkBoard();
    } else {
        button->setText("o");
        button->setStyleSheet("background-color: rgb(252, 175, 62);color: blue;");
        board[0][1] = 'o';
        button->setDisabled(true);

        checkBoard();
    }
}
// When players pressses a button,  deals with applying an x and o within the indexes of the ui and the associated color while preventing from clicking on it again.
void MainWindow::button_pressed3(){
    QPushButton * button = (QPushButton*)sender();
    if (pressCount++%2==0){
        button->setText("x");
        button->setStyleSheet("background-color: rgb(252, 175, 62);color: red;");
        board[0][2] = 'x';
        button->setDisabled(true);
        checkBoard();
    } else {
        button->setText("o");
        button->setStyleSheet("background-color: rgb(252, 175, 62);color: blue;");
        board[0][2] = 'o';
        button->setDisabled(true);
        checkBoard();
    }

}
// When players pressses a button,  deals with applying an x and o within the indexes of the ui and the associated color while preventing from clicking on it again.
void MainWindow::button_pressed4(){
    QPushButton * button = (QPushButton*)sender();
    if (pressCount++%2==0){
        button->setText("x");
        button->setStyleSheet("background-color: rgb(252, 175, 62);color: red;");
        board[1][0] = 'x';
        button->setDisabled(true);
        checkBoard();
    } else {
        button->setText("o");
        button->setStyleSheet("background-color: rgb(252, 175, 62);color: blue;");
        board[1][0] = 'o';
        button->setDisabled(true);
        checkBoard();
    }
}
// When players pressses a button,  deals with applying an x and o within the indexes of the ui and the associated color while preventing from clicking on it again.
void MainWindow::button_pressed5(){
    QPushButton * button = (QPushButton*)sender();
    if (pressCount++%2==0){
        button->setText("x");
        button->setStyleSheet("background-color: rgb(252, 175, 62);color: red;");
        board[1][1] = 'x';
        button->setDisabled(true);
        checkBoard();
    } else {
        button->setText("o");
        button->setStyleSheet("background-color: rgb(252, 175, 62);color: blue;");
        board[1][1] = 'o';
        button->setDisabled(true);
        checkBoard();
    }

}
// When players pressses a button,  deals with applying an x and o within the indexes of the ui and the associated color while preventing from clicking on it again.
void MainWindow::button_pressed6(){
    QPushButton * button = (QPushButton*)sender();
    if (pressCount++%2==0){
        button->setText("x");
        button->setStyleSheet("background-color: rgb(252, 175, 62);color: red;");
        board[1][2] = 'x';
        button->setDisabled(true);
        checkBoard();
    } else {
        button->setText("o");
        button->setStyleSheet("background-color: rgb(252, 175, 62);color: blue;");
        board[1][2] = 'o';
        button->setDisabled(true);
        checkBoard();
    }

}
// When players pressses a button,  deals with applying an x and o within the indexes of the ui and the associated color while preventing from clicking on it again.
void MainWindow::button_pressed7(){
    QPushButton * button = (QPushButton*)sender();
    if (pressCount++%2==0){
        button->setText("x");
        button->setStyleSheet("background-color: rgb(252, 175, 62);color: red;");
        board[2][0] = 'x';
        button->setDisabled(true);
        checkBoard();
    } else {
        button->setText("o");
        button->setStyleSheet("background-color: rgb(252, 175, 62);color: blue;");
        board[2][0] = 'o';
        button->setDisabled(true);
        checkBoard();
    }

}
// When players pressses a button,  deals with applying an x and o within the indexes of the ui and the associated color while preventing from clicking on it again.
void MainWindow::button_pressed8(){
    QPushButton * button = (QPushButton*)sender();
    if (pressCount++%2==0){
        button->setText("x");
        button->setStyleSheet("background-color: rgb(252, 175, 62);color: red;");
        board[2][1] = 'x';
        button->setDisabled(true);
        checkBoard();
    } else {
        button->setText("o");
        button->setStyleSheet("background-color: rgb(252, 175, 62);color: blue;");
        board[2][1] = 'o';
        button->setDisabled(true);
        checkBoard();
    }

}
// When players pressses a button,  deals with applying an x and o within the indexes of the ui and the associated color while preventing from clicking on it again.
void MainWindow::button_pressed9(){
    QPushButton * button = (QPushButton*)sender();
    if (pressCount++%2==0){
        button->setText("x");
        button->setStyleSheet("background-color: rgb(252, 175, 62);color: red;");
        board[2][2] = 'x';
        button->setDisabled(true);
        checkBoard();
    } else {
        button->setText("o");
        button->setStyleSheet("background-color: rgb(252, 175, 62);color: blue;");
        board[2][2] = 'o';
        button->setDisabled(true);
        checkBoard();
    }

}
