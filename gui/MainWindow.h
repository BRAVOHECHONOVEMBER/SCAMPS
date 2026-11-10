#pragma once

#include <QMainWindow>
#include <QTabWidget>
#include <QWidget>

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QTabWidget *tabWidget;
    QWidget *patientTab;
    QWidget *appointmentTab;
    QWidget *queueTab;
    QWidget *searchSortTab;
};