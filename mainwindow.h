#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QtCharts/QtCharts>
#include <QSplineSeries>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void BubbleSort(QChart* cplx);
    void SelectionSort(QChart* cplx);
    void MergeSort(QChart* cplx);
    void AllSortedLinkedListSearch(QChart* cplx);
    void BSTInsert(QChart* cplx);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
