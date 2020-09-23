#pragma once

#include "node.h"

#include <iostream>

shared_ptr<Node> ParseCondition(istream& is);

void TestParseCondition();
