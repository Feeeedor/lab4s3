#pragma once
template<typename T>
class vector {
    private:
    T* arr;
    int size_v;
    int capacity_v;
public:
		vector() {
      	arr = new T[1];
      	capacity_v = 1;
        size_v=0;
    }


int empty() const {
    if(size_v == 0)
		return 1;
        else
        return 0;
}
 int size() const {
		return size_v;
}
int capacity() const {
		return capacity_v;
}
void addMemory() {
		capacity_v =capacity_v *2;
    T* arr2 = arr;
    
    arr = new T[capacity_v];
    for (int i = 0; i < size_v; i++)
     arr[i] = arr2[i];
    delete[] arr2;
}
void push_back(const T& n) {
   
		if (size_v >= capacity_v) 
        addMemory();
      
    arr[size_v] = n;
      size_v++;
}
void pop_back(int ind) {
		for (int i = ind + 1; i < size_v; i++) {
    		arr[i - 1] = arr[i];
    }
    
    size_v--;
   
}
T& operator[](int ind)  {
		return arr[ind];
}

const T& operator[](int ind) const {
		return arr[ind];
}
virtual ~vector() {
	delete[] arr;
}
T* begin() {
		return &arr[0];
}
void clear(){
size_v=0;
   
   
}
const T* begin() const {
    return &arr[0];
}

T* end() {
   return &arr[size_v];
}

const T* end() const {
    return &arr[size_v];
}
vector(const vector& second) {
    if (this != &second) {
       // if(size_v!= 0)
        this->clear();
        //delete []arr;
     		arr = new T[second.capacity_v];
        for (int i = 0; i < second.size_v; ++i) 
        arr[i] = second.arr[i];
        size_v = second.size_v;
        capacity_v = second.capacity_v;
    }
}
 vector& operator=( vector& second) {
    if (this != &second) {
       // if(size_v!=0)
        this->clear();
        delete []arr;
      	arr = new T[second.capacity_v];
      	for (int i = 0; i < second.size_v; i++)
         arr[i] = second.arr[i];
        size_v = second.size_v;
        capacity_v = second.capacity_v;
    }
    return *this;
}
};