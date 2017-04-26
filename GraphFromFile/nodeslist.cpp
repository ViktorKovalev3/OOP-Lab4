#include "nodeslist.h"

NodesFromFile::NodesFromFile(std::string filename, int rectWidht, int rectHeigth)
{
    this->rectWidht  = rectWidht;
    this->rectHeigth = rectHeigth;
    this->nodeRadius = nodeRadius;
    setNewFile(filename);
}

QPointF NodesFromFile::getPosition(int nodeNumber)
{
    int xOfRow = 0, yOfCol = 0;
    for (int i = NodePositionOnMatrix->size1(); i > 0; --i){
        for (int j = NodePositionOnMatrix->size2(); j > 0; --j){
            if (NodePositionOnMatrix->at_element(i, j) == nodeNumber){
                xOfRow = i; yOfCol = j;
                goto coordinateFind;
            }
        }
    }
coordinateFind:
    return QPointF(cellWidth * (xOfRow + 0.5), cellHeigth * (yOfCol + 0.5));
}



bool NodesFromFile::isConnected(unsigned nodeNumber1, unsigned nodeNumber2)
{
    return AdjacencyMatrix->at_element(nodeNumber1, nodeNumber2);
}

void NodesFromFile::setNewFile(std::string filename)
{
    NodePositionOnMatrix.reset();
    AdjacencyMatrix.reset();

    unique_ptr<MatricesFromFileFactory> MatrixFactory(new MatricesFromFileFactory(filename));
    NodePositionOnMatrix = unique_ptr<Matrix>(MatrixFactory->getNextMatrix());
    AdjacencyMatrix = unique_ptr<Matrix>(MatrixFactory->getNextMatrix());
    calculateNodeRadius();
}

void NodesFromFile::setNewSizeOfArea(int rectWidht, int rectHeigth, int nodeRadius)
{
    this->rectWidht = rectWidht; this->rectHeigth = rectHeigth; this->nodeRadius = nodeRadius;
    calculateNodeRadius();
}

NodesFromFile::~NodesFromFile()
{}

void NodesFromFile::calculateNodeRadius()
{
    int numOfGridRows = AdjacencyMatrix->size1();
    int numOfGridCols = AdjacencyMatrix->size2();

    cellWidth = rectWidht   / numOfGridCols;
    cellHeigth = rectHeigth / numOfGridRows;

    //Diameter = 50% of cell area
    nodeRadius = (cellWidth <= cellHeigth) ? cellWidth * 0.5 / 2 : cellHeigth * 0.5 / 2;
}
