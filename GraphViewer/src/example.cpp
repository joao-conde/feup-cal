#include <cstdio>
#include "graphviewer.h"

int main() {
  GraphViewer *gv = new GraphViewer(600, 600, true);
  
  //gv->setBackground("background.jpg");

  gv->createWindow(600, 600);
  
  gv->defineEdgeColor("blue");
  gv->defineVertexColor("lightGray");

  gv->addNode(0);
  gv->addNode(1);
  gv->addNode(2);
  gv->addEdge(0, 0, 1, EdgeType::UNDIRECTED);
  gv->addEdge(3, 0, 1, EdgeType::UNDIRECTED);
  gv->addEdge(1, 0, 2, EdgeType::UNDIRECTED);
  gv->addEdge(2, 1, 2, EdgeType::DIRECTED);

  gv->setEdgeLabel(0, "Edge number 0");
  gv->setEdgeColor(1, "yellow");
  gv->setEdgeThickness(1, 5);

  gv->setVertexColor(0, "green");
 
  gv->rearrange();

  sleep(5); // use sleep(3) in linux ; Sleep(3) on Windows

  gv->removeNode(0);
  gv->rearrange();

  sleep(5); // use sleep(3) in linux ; Sleep(3) on Windows

  gv->removeEdge(2);
  gv->addNode(3);
  gv->setVertexLabel(3, "Hi! I'm the new vertex!");
  gv->rearrange();

  getchar();

  gv->closeWindow();

  getchar();

  gv->createWindow(800, 600);

  getchar();
  return 0;
}
