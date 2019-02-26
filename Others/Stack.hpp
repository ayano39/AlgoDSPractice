#include <iostream>
#include <queue>
#include <exception>

using namespace std;

// Stack implemented by two queues

template <typename T> class CStack {
	public: 
		CStack(void);
		~CStack(void);

		void push(const T &node);
		T pop();

	private:
		queue<T> queue1;
		queue<T> queue2;
};

template <typename T> CStack<T>::CStack(void) {
	
}

template <typename T> CStack<T>::~CStack(void) {
	
}

template <typename T> void CStack<T>::push(const T &node) {
	queue1.push(node);
}

template <typename T> T CStack<T>::pop() {
	queue<T> *in_queue, *out_queue;
	if (queue1.empty() && queue2.empty()) 
		throw exception();
	else if (queue1.empty() && !queue2.empty()) {
		in_queue = &queue1;
		out_queue = &queue2;
	}
	else {
		in_queue = &queue2;
		out_queue = &queue1;
	}
		

	T pop_node = out_queue->front();
	out_queue->pop();
	while (!out_queue->empty()) {
		in_queue->push(pop_node);
		pop_node = out_queue->front();
		out_queue->pop();
	}
	return pop_node;
}