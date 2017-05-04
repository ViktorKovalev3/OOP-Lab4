#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QResizeEvent>
#include "GraphFromFile/nodeslist.h"

class GraphWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GraphWidget(QWidget *parent = 0);
    ~GraphWidget();
signals:
    void cantReadFileWithMatrix();
public slots:
    void openFile(QString filename);
protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent (QPaintEvent *event);
private:
    NodesListFromFile* Nodes = nullptr;
};

#endif // GRAPHWIDGET_H
