#include "filter.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector <Filter> createFilters();
vector <Filter> createFiltersV1();

vector <Filter> createFilters(string coeffsFileName);
