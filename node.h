#pragma once

#include "date.h"
#include "token.h"

#include <memory>

class Node {
public:
	virtual bool Evaluate(const Date& date, const string& event) const = 0;
};

class EmptyNode : public Node {
public:
	bool Evaluate(const Date& date, const string& event) const override;
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(const Comparison& cmp_, const Date& date_);
	bool Evaluate(const Date& date, const string& event) const override;
private:
	const Comparison cmp;
	const Date date;
};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison& cmp_, const string& value_);
	bool Evaluate(const Date& date, const string& event) const override;
private:
	const Comparison cmp;
	const string value;
};

class LogicalOperationNode : public Node {
public:
  LogicalOperationNode(const LogicalOperation& log_op_, shared_ptr<Node> left_, shared_ptr<Node> right_);
	bool Evaluate(const Date& date, const string& event) const override;
private:
	const LogicalOperation log_op;
	shared_ptr<Node> left, right;
};
