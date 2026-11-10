#include "MainWindow.h"
#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Smart Clinic Appointment & Patient Management System (SCAPMS)");
    resize(1000, 650);

    // Initialize Tab Widget
    tabWidget = new QTabWidget(this);

    // Create tabs
    patientTab = new QWidget();
    appointmentTab = new QWidget();
    queueTab = new QWidget();
    searchSortTab = new QWidget();

    // Temporary placeholder layouts for each tab (we will fill these with tables & buttons next)
    QVBoxLayout *patientLayout = new QVBoxLayout(patientTab);
    patientLayout->addWidget(new QLabel("Patient Records Management Panel", this));

    QVBoxLayout *appLayout = new QVBoxLayout(appointmentTab);
    appLayout->addWidget(new QLabel("Appointment Scheduling Panel", this));

    QVBoxLayout *queueLayout = new QVBoxLayout(queueTab);
    queueLayout->addWidget(new QLabel("Waiting Queue & Consultation Panel", this));

    QVBoxLayout *searchLayout = new QVBoxLayout(searchSortTab);
    searchLayout->addWidget(new QLabel("Search, Sort & Reports Panel", this));

    // Add tabs to widget
    tabWidget->addTab(patientTab, "Patient Records");
    tabWidget->addTab(appointmentTab, "Appointments");
    tabWidget->addTab(queueTab, "Waiting Queue");
    tabWidget->addTab(searchSortTab, "Search & Sort");

    setCentralWidget(tabWidget);
}

MainWindow::~MainWindow() {}