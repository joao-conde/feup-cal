#include "graphviewer.h"

#ifdef linux
pid_t GraphViewer::procId = 0;
#endif

GraphViewer::GraphViewer(int width, int height, bool dynamic) {
  this->width = width;
  this->height = height;
  this->isDynamic = dynamic;

#ifdef linux
  if (!(procId = fork())) { 
    system("java -jar GraphViewerController.jar");
    kill(getppid(), SIGINT);
    exit(0);
  }
  else {    
    usleep(2000000);
    con = new Connection();

    char buff[200];
    sprintf_s(buff, "newGraph %d %d %s\n", width, height, (dynamic?"true":"false"));
    string str(buff);
    con->sendMsg(str);
  }
#else
  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  ZeroMemory( &si, sizeof(si) );
  si.cb = sizeof(si);
  ZeroMemory( &pi, sizeof(pi) );

  if( !CreateProcess( NULL,   // No module name (use command line)
		      "java -jar GraphViewerController.jar",        // Command line
		      NULL,           // Process handle not inheritable
		      NULL,           // Thread handle not inheritable
		      FALSE,          // Set handle inheritance to FALSE
		      0,              // No creation flags
		      NULL,           // Use parent's environment block
		      NULL,           // Use parent's starting directory 
		      &si,            // Pointer to STARTUPINFO structure
		      &pi )           // Pointer to PROCESS_INFORMATION structure
      ) {
    printf( "CreateProcess failed (%d).\n", GetLastError() );
    return;
  }
 
  // Close process and thread handles. 
  CloseHandle( pi.hProcess );
  CloseHandle( pi.hThread );

  Sleep(2000);
  con = new Connection();
  
  char buff[200];
  sprintf_s(buff, "newGraph %d %d %s\n", width, height, (dynamic?"true":"false"));
  string str(buff);
  con->sendMsg(str);
#endif

}

bool GraphViewer::createWindow(int width, int height) {
  char buff[200];
  sprintf_s(buff, "createWindow %d %d\n", width, height);
  string str(buff);
  return con->sendMsg(str);
}

bool GraphViewer::closeWindow() {
  char buff[200];
  sprintf_s(buff, "closeWindow\n");
  string str(buff);
  return con->sendMsg(str);
}

bool GraphViewer::addNode(int id) {
  char buff[200];
  sprintf_s(buff, "addNode1 %d\n", id);
  string str(buff);
  return con->sendMsg(str);
}

bool GraphViewer::addNode(int id, int x, int y) {
  char buff[200];
  sprintf_s(buff, "addNode3 %d %d %d\n", id, x, y);
  string str(buff);
  return con->sendMsg(str);
}

bool GraphViewer::addEdge(int id, int v1, int v2, int edgeType) {
  char buff[200];
  sprintf_s(buff, "addEdge %d %d %d %d\n", id, v1, v2, edgeType);
  string str(buff);
  return con->sendMsg(str);
}

bool GraphViewer::setEdgeLabel(int k, string label) {
  char buff[200];
  sprintf_s(buff, "setEdgeLabel %d %s\n", k, label.c_str());
  string str(buff);
  return con->sendMsg(str);
}

bool GraphViewer::setVertexLabel(int k, string label) {
  char buff[200];
  sprintf_s(buff, "setVertexLabel %d %s\n", k, label.c_str());
  string str(buff);
  return con->sendMsg(str);
}

bool GraphViewer::defineEdgeColor(string color) {
  char buff[200];
  sprintf_s(buff, "defineEdgeColor %s\n", color.c_str());
  string str(buff);
  return con->sendMsg(str);
}

bool GraphViewer::removeNode(int id) {
  char buff[200];
  sprintf_s(buff, "removeNode %d\n", id);
  string str(buff);
  return con->sendMsg(str);
}

bool GraphViewer::removeEdge(int id) {
  char buff[200];
  sprintf_s(buff, "removeEdge %d\n", id);
  string str(buff);
  return con->sendMsg(str);
}

bool GraphViewer::setEdgeColor(int k, string color) {
  char buff[200];
  sprintf_s(buff, "setEdgeColor %d %s\n", k, color.c_str());
  string str(buff);
  return con->sendMsg(str);
}

bool GraphViewer::setEdgeThickness(int k, int thickness) {
  char buff[200];
  sprintf_s(buff, "setEdgeThickness %d %d\n", k, thickness);
  string str(buff);
  return con->sendMsg(str);
}


bool GraphViewer::defineVertexColor(string color) {
  char buff[200];
  sprintf_s(buff, "defineVertexColor %s\n", color.c_str());
  string str(buff);
  return con->sendMsg(str);
}

bool GraphViewer::setVertexColor(int k, string color) {
  char buff[200];
  sprintf_s(buff, "setVertexColor %d %s\n", k, color.c_str());
  string str(buff);
  return con->sendMsg(str);
}

bool GraphViewer::setBackground(string path) {
  char buff[200];
  sprintf_s(buff, "setBackground %s\n", path.c_str());
  string str(buff);
  return con->sendMsg(str);
}

bool GraphViewer::defineEdgeCurved(bool curved) {
	char buff[200];
	sprintf_s(buff, "defineEdgeCurved %s\n", curved ? "true" : "false");
	string str(buff);
	return con->sendMsg(str);
}


bool GraphViewer::rearrange() {
  return con->sendMsg("rearrange\n");
}
