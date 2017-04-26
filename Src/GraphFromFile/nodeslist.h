#ifndef NODESLIST_H
#define NODESLIST_H
#include "MatrixFromFile/matrix.h"
#include <string>
#include <QPointF>
#include <memory>

using std::unique_ptr;
/*
 * Adjacency matrix
 * For example {1}:
 * [4, 4]
 * ((1, 1, 1, 0),
 *  (0, 0, 0, 0),
 *  (1, 1, 0, 0),
 *  (1, 1, 0, 0))
 * Node position on rectangle area
 * in matrix representation:
 * [2,2]
 * ((0, 2),
 *  (1, 3))
 * For example, for {1} it's look like:
 *   _
 *  | |
 * \/\/
 * (0)<-->(2)
 *  |      |
 * \/     \/
 * (1)   (3)
*/


class NodesFromFile
{
public:
    NodesFromFile(std::string filename, int rectWidht, int rectHeigth);
    QPointF getPosition(int nodeNumber);
    int getNodeRadius();
    bool isConnected(unsigned nodeNumber1, unsigned nodeNumber2);
    void setNewFile(std::string filename);
    void setNewSizeOfArea(int rectWidht, int rectHeigth, int nodeRadius);
    ~NodesFromFile();
private:
    void calculateNodeRadius();
    int rectWidht, rectHeigth, nodeRadius, cellWidth, cellHeigth;
    unique_ptr<Matrix> NodePositionOnMatrix;
    unique_ptr<Matrix> AdjacencyMatrix;
};
#endif // NODESLIST_H
