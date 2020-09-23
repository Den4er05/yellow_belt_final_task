#include "node.h"
#include "date.h"

bool EmptyNode::Evaluate(const Date& date, const string& event) const {
	return true;
}

DateComparisonNode::DateComparisonNode(const Comparison& cmp_, const Date& date_) : cmp(cmp_), date(date_) {}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
    if (cmp == Comparison::Less) {
        return date < DateComparisonNode::date;
    }
    else if (cmp == Comparison::LessOrEqual) {
        return ((date < DateComparisonNode::date) || (date == DateComparisonNode::date));
    }
    else if (cmp == Comparison::Greater) {
        return date > DateComparisonNode::date;
    }
    else if (cmp == Comparison::GreaterOrEqual) {
        return ((date > DateComparisonNode::date) || (date == DateComparisonNode::date));
    }
    else if (cmp == Comparison::Equal) {
        return date == DateComparisonNode::date;
    }
    else if (cmp == Comparison::NotEqual) {
        return !(date == DateComparisonNode::date);
    }
}
 

EventComparisonNode::EventComparisonNode(const Comparison& cmp_, const string& value_) : cmp(cmp_), value(value_){}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
    if (cmp == Comparison::Less) {
        return event < EventComparisonNode::value;
    }
    else if (cmp == Comparison::LessOrEqual) {
        return ((event < EventComparisonNode::value) || (event == EventComparisonNode::value));
    }
    else if (cmp == Comparison::Greater) {
        return event > EventComparisonNode::value;
    }
    else if (cmp == Comparison::GreaterOrEqual) {
        return ((event > EventComparisonNode::value) || (event == EventComparisonNode::value));
    }
    else if (cmp == Comparison::Equal) {
        return event == EventComparisonNode::value;
    }
    else if (cmp == Comparison::NotEqual) {
        return !(event == EventComparisonNode::value);
    }
}


LogicalOperationNode::LogicalOperationNode(const LogicalOperation& log_op_, shared_ptr<Node> left_, shared_ptr<Node> right_)
	: log_op(log_op_), left(left_), right(right_){}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
    if (log_op == LogicalOperation::And) {
        return (left->Evaluate(date, event) && right->Evaluate(date, event));
    }
    else if (log_op == LogicalOperation::Or) {
        return (left->Evaluate(date, event) || right->Evaluate(date, event));
    }
}
