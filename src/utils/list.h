#ifndef __LIST
#define __LIST
template<typename T> class List{
    public:
        List();
        ~List();
        void add(T item);
        void add(int index, T item);
        T operator[](int index);
        int find(T item);
        void remove(T item);
        void removeAt(int index);
        int size();
    private:
        static const int INCREASE_STEP = 7;

        T* itemContainer;
        int internalSize;
        int maxSize;
        void increaseContainerSize();
        void decreaseContainerSize();
        void move(int startIndex, int distance);
};

#endif
