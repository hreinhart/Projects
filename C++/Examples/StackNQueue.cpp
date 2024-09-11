#include <iostream>

using namespace std;

class Stack {
        int max;
        int array[max];
        int top;
        Stack() {
            max = 10;
            top = -1;
        }
		Stack(int max){
			this->max = max;
			top = -1;
		}
        void push(int x) {
		if (isFull()) throw exception;
		top += 1;
		array[top] = x;
	}
	    int pop() {
		if (isEmpty()) throw exception;
		int x = array[top];
		top -= 1;
		return x;
	}
        int peek() {
		if (isEmpty()) throw exception;
		return array[top];
	}
	boolean isEmpty() {
		return top == -1;
	}
   /* void reverse() {
	stack S();
	while (!endOfFile()) {
		file* = read();
		S.push(data);
	}
	while (!S.isEmpty()) {
		data = S.pop();
		print(data);
	}
} */
};
class Queue {
    int MAX;
	int array[MAX];
	int front, back, n;
	public:
	Queue() {
        MAX = 10;
		front = 0;
		back = MAX-1;
		n = 0; 
		array[MAX];
	}
	Queue(int MAX){
		this->MAX = MAX;
		front = 0;
		back = MAX-1;
		n = 0;
		array[MAX];
	}
    void enqueue(int x) {
		if (isFull()) throw exception;
		back = (back + 1) % MAX;
		array[back] = x;
		n += 1;
	}
	int dequeue() {
		if (isEmpty()) throw exception;
		int x = array[front];
		front = (front + 1) % MAX;
		n -= 1;
		return x;
	}
    int peek() {
		if (isEmpty()) throw exception;
		return array[front];
	}
	int size() {
		return n;
	}
    boolean isEmpty() {
		return n == 0;
	}
	boolean isFull() {
		return n == MAX;
	}
	void print() {
		int move;
		int times;
		move = front;
		times = MAX;
		while(times != 0){
			cout << array[move] << " ";
			move = (move + 1) % MAX;
			times--;
		}
	}
};



int main(){
Queue y;
y.enqueue(2);
y.enqueue(5);
y.enqueue(9);
y.print;
    return 0;
}
