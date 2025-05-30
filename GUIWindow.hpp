// GUIWindow.hpp
#ifndef GUIWINDOW_HPP
#define GUIWINDOW_HPP

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <memory>
#include "Game.hpp"

class GUIWindow : public QMainWindow {
    Q_OBJECT

private:
    Game game;
    QWidget* centralWidget;
    QLabel* bankLabel;
    QLabel* currentPlayerLabel;
    QListWidget* playerList;
    QLabel* currentPlayerInfo;
    QPushButton* gatherButton;
    QPushButton* taxButton;
    QPushButton* bribeButton;
    QPushButton* arrestButton;
    QPushButton* sanctionButton;
    QPushButton* coupButton;
    QPushButton* endTurnButton;

    void setupUI();
    void connectSignals();
    void updateDisplay();

private slots:
    void onGather();
    void onTax();
    void onBribe();
    void onArrest();
    void onSanction();
    void onCoup();
    void onEndTurn();

public:
    GUIWindow(QWidget* parent = nullptr);
};

#endif // GUIWINDOW_HPP
