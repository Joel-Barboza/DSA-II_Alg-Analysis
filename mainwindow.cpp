
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSplineSeries* series = new QSplineSeries();

    QChart* chart = new QChart();
    chart->legend()->show();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).first()->setRange(-10,1000);
    chart->axes(Qt::Vertical).first()->setRange(-10,1000*1000);
    chart->setVisible(true);


    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setVisible(true);

    QWidget* centralWidget = new QWidget();

    QHBoxLayout* algButtonLayout = new QHBoxLayout();

    QPushButton *btnBubbleS = new QPushButton("Bubble Sort", this);
    QPushButton *btnSelectionS = new QPushButton("Selection Sort", this);
    QPushButton *btnMergeS = new QPushButton("Merge Sort", this);
    QPushButton *btnSortedLkdListSearch = new QPushButton("All Sorted LinkedList Search", this);
    QPushButton *btnBSTInsert = new QPushButton("Binary Search Tree Insert", this);

    algButtonLayout->addWidget(btnBubbleS);
    algButtonLayout->addWidget(btnSelectionS);
    algButtonLayout->addWidget(btnMergeS);
    algButtonLayout->addWidget(btnSortedLkdListSearch);
    algButtonLayout->addWidget(btnBSTInsert);

    QWidget* algBtnWidget = new QWidget();
    algBtnWidget->setLayout(algButtonLayout);


    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->addWidget(algBtnWidget);
    mainLayout->addWidget(chartView);

    setCentralWidget(centralWidget);

    connect(btnBubbleS, &QPushButton::clicked, [this, chart]() {
        BubbleSort(chart);
    });

    connect(btnSelectionS, &QPushButton::clicked, [this, chart]() {
        SelectionSort(chart);
    });

    connect(btnMergeS, &QPushButton::clicked, [this, chart]() {
        MergeSort(chart);
    });

    connect(btnSortedLkdListSearch, &QPushButton::clicked, [this, chart]() {
        AllSortedLinkedListSearch(chart);
    });

    connect(btnBSTInsert, &QPushButton::clicked, [this, chart]() {
        BSTInsert(chart);
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::BubbleSort(QChart* w) {
    w->removeAllSeries();
    QSplineSeries *seriesOn = new QSplineSeries();
    seriesOn->setName("O(n)");
    QSplineSeries *seriesOnSquared = new QSplineSeries();
    seriesOnSquared->setName("O(n^2)");

    int maxN = 1000;
    for (int i = 1; i <= maxN; ++i) {
        double x = i;
        seriesOn->append(x, x);
        seriesOnSquared->append(x, x * x);
    }

    w->addSeries(seriesOn);
    w->addSeries(seriesOnSquared);
    w->axes(Qt::Horizontal).first()->setRange(0, maxN);
    w->axes(Qt::Vertical).first()->setRange(0, maxN * maxN);
}

void MainWindow::SelectionSort(QChart* w) {
    w->removeAllSeries();
    QSplineSeries *seriesOnSquared = new QSplineSeries();
    seriesOnSquared->setName("O(n^2)");

    int maxN = 1000;
    for (int i = 1; i <= maxN; ++i) {
        double x = i;
        seriesOnSquared->append(x, x * x);
    }

    w->addSeries(seriesOnSquared);
    w->axes(Qt::Horizontal).first()->setRange(0, maxN);
    w->axes(Qt::Vertical).first()->setRange(0, maxN * maxN);
}

void MainWindow::MergeSort(QChart* w) {
    w->removeAllSeries();
    QSplineSeries *seriesOnLogN = new QSplineSeries();
    seriesOnLogN->setName("O(n log n)");

    int maxN = 1000;
    for (int i = 1; i <= maxN; ++i) {
        double x = i;
        seriesOnLogN->append(x, x * log2(x));
    }

    w->addSeries(seriesOnLogN);
    w->axes(Qt::Horizontal).first()->setRange(0, maxN);
    w->axes(Qt::Vertical).first()->setRange(0, maxN * log2(maxN));
}

void MainWindow::AllSortedLinkedListSearch(QChart* w) {
    w->removeAllSeries();
    QSplineSeries *seriesO1 = new QSplineSeries();
    seriesO1->setName("O(1)"); // Constant time

    QSplineSeries *seriesOn = new QSplineSeries();
    seriesOn->setName("O(n)");

    int maxN = 1000;
    for (int i = 1; i <= maxN; ++i) {
        double x = i;
        seriesO1->append(x, 1);
        seriesOn->append(x, x);
    }

    w->addSeries(seriesOn);
    w->addSeries(seriesO1);
    w->axes(Qt::Horizontal).first()->setRange(0, maxN);
    w->axes(Qt::Vertical).first()->setRange(0, maxN);
}

void MainWindow::BSTInsert(QChart* w) {
    w->removeAllSeries();
    QSplineSeries *seriesOlogN = new QSplineSeries();
    seriesOlogN->setName("O(log n)");

    QSplineSeries *seriesOn = new QSplineSeries();
    seriesOn->setName("O(n)");

    int maxN = 1000;
    for (int i = 1; i <= maxN; ++i) {
        double x = i;
        seriesOlogN->append(x, log10(x));
        seriesOn->append(x, x);
    }

    w->addSeries(seriesOlogN);
    w->addSeries(seriesOn);
    w->axes(Qt::Horizontal).first()->setRange(0, maxN);
    w->axes(Qt::Vertical).first()->setRange(0, maxN);
}
