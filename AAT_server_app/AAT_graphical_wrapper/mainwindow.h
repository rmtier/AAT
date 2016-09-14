#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_querry_com_box_currentIndexChanged(const QString &arg1);

    void on_second_querry_comb_box_currentIndexChanged(const QString &arg1);

    void on_run_button_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
