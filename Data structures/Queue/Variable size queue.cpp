class Queue
{
	int capacity;
	int frontPos=0, rearPos=0;
public:
	int* arr = nullptr;

	Queue()
	{
		capacity = 10;
		arr = (int*)malloc(sizeof(int) * capacity);
	}

	void enqueue(int value);
	int size();
	void dequeue();
	bool isEmpty();
	bool isFull();
	void display();
	void increaseCapacity();
	void cleanup();
};

int Queue::size()
{
	return rearPos;
}

bool Queue::isEmpty()
{
	if(rearPos == -1)
		return true;

	return false;
}


bool Queue::isFull()
{
	if(rearPos == capacity)
		return true;

	return false;
}

void Queue::cleanup()
{
	capacity = 0;
	free(arr);
}

void Queue::display()
{
	if(isEmpty())
		return; 

	for(int i = frontPos; i < rearPos; i++)
	{
		cout << arr[i] << ' ';
	}
}

void Queue::increaseCapacity()
{
	capacity *= 2;
	arr = (int*)realloc(arr, sizeof(int) * capacity);
}

void Queue::dequeue()
{
	if(size()>1)
		frontPos++;
	else
	{
		frontPos = rearPos = -1;
	}
}

void Queue::enqueue(int value)
{
	if(isEmpty())
	{
		frontPos = rearPos = 0;
		arr[rearPos] = value;
	}
	else
	{
		if(isFull())
			increaseCapacity();

		arr[rearPos++] = value;
	}
}