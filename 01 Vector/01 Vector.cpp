#include <iostream>
using namespace std;

template <typename Object>
class Vector {
public:
    enum { SPARE_CAPACITY = 15 };


    /*  Constructor */
    Vector(int initSize = 0)
        : theSize(initSize), theCapacity( initSize + SPARE_CAPACITY )
    {
        objects = new Object[theCapacity];   
    }

    /*  Constructor */
    Vector(const Vector &rhs) : objects(NULL)
    {
        operator=(rhs);
    }

    /*  Destructor */
    ~Vector()
    {
        delete [] objects;
    }

    /*  Set-equal override */
    const Vector &operator=(const Vector &rhs)
    {
        if (this != rhs)
        {
            delete [] objects;
            theSize = rhs.size();
            theCapacity = rhs.theCapacity;

            objects = new Object[ capacity() ];
            for (int i = 0; i != size(); i++) 
            {
                objects[i] = rhs.objects[i];
            }
        }
        return *this;
    }

    /*  Resize */
    void resize(int newSize)
    {
        if (newSize > theCapacity)
            reserve(newSize * 2 + 1);
        theSize = newSize;
    }

    /*  Reserve */
    void reserve(int newCapacity)
    {
        if (newCapacity < theSize)
            return;

        Object *oldArray = objects;

        objects = new Object[newCapacity];
        for (int i = 0; i < theSize; i++)
            objects[i] = oldArray[i];

        theCapacity = newCapacity;

        delete [] oldArray;
    }

    /*  Element-of override */
    Object &operator[](int index)
    {
        return objects[index];
    }

    /*  Element-of override const */
    const Object &operator[](int index) const
    {
        return objects[index];
    }

    /*  Is it empty? */
    bool empty() const 
    {
        return size() == 0;
    }

    /*  The Size */
    int size() const
    {
        return theSize;
    }

    /*  The Capacity */
    int capacity() const
    {
        return theCapacity;
    }

    /*  Add new element */
    void push_back(const Object &x)
    {
        if (theSize == theCapacity)
            reserve(2 * theCapacity + 1);
        objects[theSize++] = x;
    }

    /*  Remove last element */
    void pop_back()
    {
        theSize--;
    }

    /*  Retrieve last element (immutable) */
    const Object &back() const
    {
        return objects[theSize - 1];
    }

    /*  ITERATORS:  */
    typedef Object *iterator;
    typedef const Object *const_iterator;

    /*  Begin iterator */
    iterator begin()
    {
        return &objects[0];
    }

    /*  Begin iterator const */
    const_iterator begin() const
    {
        return &objects[0];
    }

    /*  End iterator */
    iterator end()
    {
        return &objects[size()];
    }

    /*  End iterator const */
    const_iterator end() const
    {
        return &objects[size()];
    }


private:
    int theSize;
    int theCapacity;
    Object *objects;
};


int main(int argc, char *argv[])
{
    Vector<int> myVector;
    myVector.push_back(3);
    myVector.push_back(2);
    myVector.push_back(1);

    for (Vector<int>::iterator iter = myVector.begin(); iter != myVector.end(); iter++) {
        cout << *iter << "\n";
    }
}