// MainWindow.hpp
#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidget>
#include <QMessageBox>

#include "Game.hpp"

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    Game* game;

    QLabel* bankLabel;
    QListWidget* playersList;

    QPushButton* gatherBtn;
    QPushButton* taxBtn;
    QPushButton* bribeBtn;
    QPushButton* arrestBtn;
    QPushButton* sanctionBtn;
    QPushButton* coupBtn;

    QLabel* currentPlayerLabel;
    QLabel* coinBankLabel;
    QLabel* playerCoinsLabel;
    QLabel* playerStatusLabel;

    // Layout or container widgets, if needed
    QWidget* centralWidget;
    QVBoxLayout* layout;
    QVBoxLayout* playerInfoLayout;

    void updateUI();
    void showMessage(const QString& message);

private slots:
    void onGather();
    void onTax();
    void onBribe();
    void onArrest();
    void onSanction();
    void onCoup();

public:
    MainWindow(QWidget* parent = nullptr);
};

#endif // MAINWINDOW_HPP
