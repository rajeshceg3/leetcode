class MyQueue {
  std::stack<int> enqueueFrame;
  std::stack<int> dequeueFrame;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        enqueueFrame.push(x);        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
		int value;
		if (dequeueFrame.empty())
		{
			while(!enqueueFrame.empty())
			{
				value = enqueueFrame.top();
				dequeueFrame.push(value);
				enqueueFrame.pop();								
			}				
		}		
		value = dequeueFrame.top();
		dequeueFrame.pop();
		return value;	        
    }
    
    /** Get the front element. */
    int peek() {
		int value;
		if (dequeueFrame.empty())
		{
			while(!enqueueFrame.empty())
			{
				value = enqueueFrame.top();
				dequeueFrame.push(value);
				enqueueFrame.pop();								
			}				
		}		
		value = dequeueFrame.top();
		return value;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return dequeueFrame.empty() && enqueueFrame.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
