# Stack Data Structure - Input/Output Analysis

## Problem: Valid Parentheses (LeetCode #20)

### Problem Description
Given a string `s` containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

---

## Input Specification

**Type:** String
**Constraints:**
- 1 ≤ s.length ≤ 10⁴
- s consists of parentheses only: '()[]{}'

**Examples:**
```
Input: s = "()"
Input: s = "()[]{}"
Input: s = "(]"
Input: s = "([)]"
Input: s = "{[]}"
```

---

## Output Specification

**Type:** Boolean (true/false or 1/0)
**Meaning:**
- `true`: The string has valid parentheses
- `false`: The string has invalid parentheses

---

## Test Cases

| Input | Output | Explanation |
|-------|--------|-------------|
| "()" | true | Single pair, correctly closed |
| "()[]{}" | true | Multiple pairs, all valid |
| "(]" | false | Mismatched brackets |
| "([)]" | false | Wrong closing order |
| "{[]}" | true | Nested brackets, valid |
| "(((" | false | Only opening brackets |
| ")))" | false | Only closing brackets |
| "" | true | Empty string is valid |

---

## Why Use a Stack?

**Stack Properties Needed:**
1. **LIFO (Last In, First Out)** - Most recent opening bracket should match first closing bracket
2. **Push Operation** - Store opening brackets
3. **Pop Operation** - Match closing brackets with most recent opening
4. **Peek Operation** - Check top element without removing
5. **isEmpty Check** - Verify all brackets are matched

**Algorithm Logic:**
- When we see an opening bracket → Push to stack
- When we see a closing bracket → Check if it matches the top of stack
- At the end → Stack should be empty (all brackets matched)