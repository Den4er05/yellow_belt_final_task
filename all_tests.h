#pragma once

#include "database.h"
#include "date.h"
#include "condition_parser.h"
#include "node.h"
#include "test_runner.h"

ostream& operator << (ostream& os, pair<Date, string> p);

string ParseEvent(istream& is);

class AlwaysFalseNode : public Node {
    bool Evaluate(const Date&, const std::string& event) const override;
};

int DoRemove(Database& db, const string& str);

string DoFind(Database& db, const string& str);

void TestDbAdd();

void TestDbFind();

void TestDbLast();

void TestDbRemoveIf();

void TestInsertionOrder();

void TestsMyCustom();

void TestDatabase();

void TestDateComparisonNode();

void TestEventComparisonNode();

void TestLogicalOperationNode();

void TestEmptyNode();

void AssertDbPrintOutput(const Database& db, const string& hint, const vector<string> expected);

void TestDatabasePrint();

void TestDatabaseDel();

void TestAll();
