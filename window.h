#pragma once
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>
#include <QMenuBar>
#include <QAction>
#include <QMenu>
#include <QMessageBox>
#include <QFileDialog>

#include "canvas.h"
#include "graph.h"

class Window : public QObject{
public:
    Window(QWidget *parent = nullptr);
    void show();
    void openFile();
    void loadFile(const QString &fileName);
    void showMessage();
    QString selectFile();
private:
    void createActions();

    QMainWindow *window;
    QMenuBar *menuBar;
    Canvas *canvas;
    QVBoxLayout *layout;
    QWidget *widget;
    QWidget *topFiller;
    QWidget *bottomFiller;
    QAction *file;
    QAction *about;
    QMessageBox *info;
};
