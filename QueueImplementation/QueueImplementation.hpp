#include <iostream>

using namespace std;

template <typename T>
struct Node
{
	T data;
	Node<T>* next;

	Node(const T& dt, Node<T>* nxt = nullptr)
	{
		data = dt;
		next = nxt;
	}
};

template <typename T>
class Queue
{
private:
	Node<T>* first;
	Node<T>* last;
	size_t size;

	void copy(const Queue& other)
	{
		Node<T>* temp = other.first;
		for (size_t i = 0; i < other.getSize(); i++)
		{
			this->push(temp->data);
			temp = temp->next;
		}
	}
	void destroy()
	{
		while (!empty())
		{
			this->pop();
		}
	}
public:
	Queue()
	{
		this->first = nullptr;
		this->last = nullptr;
		this->size = 0;
	}
	Queue(const Queue& other)
	{
		this->copy(other);
	}
	Queue& operator=(const Queue& other)
	{
		if (this != &other)
		{
			this->destroy();
			this->copy(other);
		}

		return *this;
	}
	const T& front() const
	{
		if (this->first != nullptr)
		{
			return this->first->data;
		}
		throw "Empty queue";
	}
	const T& back() const
	{
		if (this->last != nullptr)
		{
			return this->last->data;
		}
		throw "Empty queue";
	}
	void pop()
	{
		if (!empty())
		{
			Node<T>* temp = first;
			this->first = this->first->next;
			delete temp;
			this->size--;
		}
	}
	void push(const T& data)
	{
		Node<T>* newNode = new Node<T>(data);
		if (empty())
		{
			this->first = newNode;
			this->last = newNode;
		}
		else
		{
			this->last->next = newNode;
			this->last = newNode;
		}
		this->size++;
	}
	bool empty() const
	{
		return this->size == 0;
	}
	size_t getSize() const
	{
		return this->size;
	}
	~Queue()
	{
		this->destroy();
	}
};

int main()
{
	Queue<int> q;
	//q.push(5);
	try
	{
		int front = q.front();
		cout << front << endl;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}