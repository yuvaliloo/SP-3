// MainWindow.cpp
#include "MainWindow.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), game() {
    QWidget* central = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(central);

    bankLabel = new QLabel("Bank: 0", this);
    currentPlayerLabel = new QLabel("Current Player: ", this);
    layout->addWidget(bankLabel);
    layout->addWidget(currentPlayerLabel);

    playerInfoLayout = new QVBoxLayout();
    layout->addLayout(playerInfoLayout);

    QHBoxLayout* buttonLayout = new QHBoxLayout();

    gatherBtn = new QPushButton("Gather", this);
    taxBtn = new QPushButton("Tax", this);
    bribeBtn = new QPushButton("Bribe", this);
    arrestBtn = new QPushButton("Arrest", this);
    sanctionBtn = new QPushButton("Sanction", this);
    coupBtn = new QPushButton("Coup", this);

    buttonLayout->addWidget(gatherBtn);
    buttonLayout->addWidget(taxBtn);
    buttonLayout->addWidget(bribeBtn);
    buttonLayout->addWidget(arrestBtn);
    buttonLayout->addWidget(sanctionBtn);
    buttonLayout->addWidget(coupBtn);

    layout->addLayout(buttonLayout);
    central->setLayout(layout);
    setCentralWidget(central);

    connect(gatherBtn, &QPushButton::clicked, this, &MainWindow::onGather);
    connect(taxBtn, &QPushButton::clicked, this, &MainWindow::onTax);
    connect(bribeBtn, &QPushButton::clicked, this, &MainWindow::onBribe);
    connect(arrestBtn, &QPushButton::clicked, this, &MainWindow::onArrest);
    connect(sanctionBtn, &QPushButton::clicked, this, &MainWindow::onSanction);
    connect(coupBtn, &QPushButton::clicked, this, &MainWindow::onCoup);

    updateUI();
}

void MainWindow::updateUI() {
    bankLabel->setText(QString("Bank: %1").arg(game->getCoinBank()));
    currentPlayerLabel->setText(QString("Current Player: %1").arg(QString::fromStdString(game->getCurrentPlayerName())));

    QLayoutItem* item;
    while ((item = playerInfoLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    for (const std::string& name : game->getActivePlayerNames()) {
        auto player = game->findPlayerByName(name);
        QLabel* label = new QLabel(QString("%1 | Coins: %2 | Active: %3 | Role: %4")
            .arg(QString::fromStdString(name))
            .arg(player->getCoinCount())
            .arg(player->isCurrentlyActive() ? "Yes" : "No")
            .arg(QString::fromStdString(player->getRole())));
        playerInfoLayout->addWidget(label);
    }
}

void MainWindow::onGather() {
    auto player = game->findPlayerByName(game->getCurrentPlayerName());
    player->gather();
    updateUI();
}

void MainWindow::onTax() {
    auto player = game->findPlayerByName(game->getCurrentPlayerName());
    player->tax();
    updateUI();
}

void MainWindow::onBribe() {
    auto player = game->findPlayerByName(game->getCurrentPlayerName());
    player->bribe();
    updateUI();
}

void MainWindow::onArrest() {
    // You could implement a dialog here to choose target
    QMessageBox::information(this, "Arrest", "Arrest logic needs target selection.");
}

void MainWindow::onSanction() {
    QMessageBox::information(this, "Sanction", "Sanction logic needs target selection.");
}

void MainWindow::onCoup() {
    QMessageBox::information(this, "Coup", "Coup logic needs target selection.");
}

