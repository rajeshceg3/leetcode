class Solution {
	int calculate(int op1,int op2, string slice)
	{
		int result = 0;
		if ( slice == "+") result = op1 + op2;
		else if ( slice == "-") result = op2 - op1;
		else if ( slice == "*") result = op1 * op2;
		else if ( slice == "/") result = op2 / op1;
		return result;
	}
public:
    int evalRPN(vector<string>& tokens) {
		std::unordered_set<string> operators = {"+","-","*","/"};
		std::stack<int> lifo;
		for(const string& slice: tokens)
		{
			if (operators.count(slice) == 0) lifo.push(stoi(slice));
			else
			{
				int op1 = lifo.top();
				lifo.pop();
				int op2 = lifo.top();
				lifo.pop();
				int result = calculate(op1,op2,slice);
                lifo.push(result);
			}
		}
        return lifo.top();
    }
};
