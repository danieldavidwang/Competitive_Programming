#include "game.h"
int c[1501];
void initialize(int n) {}
int hasEdge(int u, int v) { return ++c[u > v ? u : v] == (u > v ? u : v); }