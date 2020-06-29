#ifndef TRIPVECTOR_H
#define TRIPVECTOR_H

enum EmptyContainerException{};
enum NullPointerException{};

template<class T>
class tripVector {
private:
    T* elements; //Elementi del vettore
    unsigned int size; //Numero di elementi che il vettore contiene
    unsigned int capacity; //Numero di elementi che il vettore può contenere


public:
    // Iteratore

    class iterator {
    public:
        T* pointer;

        //Operatori e costruttore

        iterator(T* p = nullptr): pointer(p) {}

        bool operator==(const iterator&) const;
        bool operator!=(const iterator&) const;

        iterator& operator++();
        iterator& operator--();
        iterator operator++(int);        
        iterator operator--(int);

        iterator operator+(int);
        iterator operator-(int);

        T& operator*() const;
    };

    //Iteratore costante

    class const_iterator {
    public:
        T* pointer;

        //Operatori e costruttore

        const_iterator(const T* p = nullptr): pointer(p) {}

        bool operator==(const const_iterator&) const;
        bool operator!=(const const_iterator&) const;

        const_iterator& operator++();
        const_iterator& operator--();
        const_iterator operator++(int);        
        const_iterator operator--(int);

        const_iterator operator+(int);
        const_iterator operator-(int);

        const T& operator*() const;
    };

    //Metodi di tripVector

    tripVector() : elements(nullptr), size(0), capacity(1) {} //Costruttore di default
    tripVector(const T&, unsigned int); //Costruttore a due parametri
    tripVector(const tripVector&); //Costruttore di copia
    ~tripVector(); //Distruttore
    tripVector& operator=(const tripVector&); //Assegnazione

    iterator begin();
    iterator end(); //past-end
    const_iterator begin() const;
    const_iterator end() const; //past-end

    unsigned int getSize() const;
    bool isEmpty() const;

    T& operator[](unsigned int);
    const T& operator[](unsigned int) const;

    void push_back(const T&);
    T pop_back();
    iterator insert(iterator, const T&);
    iterator erase(iterator);
    void erase(unsigned int);
    iterator search(const T&);

    static void doubleCapacity(tripVector<T>&);
};

//_________________________________________________________________________________________________________________________

//Implementazione Iterator

template <class T>
bool tripVector<T>::iterator::operator==(const iterator& i) const{
    return pointer == i.pointer;
}

template <class T>
bool tripVector<T>::iterator::operator!=(const iterator& i) const{
    return pointer!=i.pointer;
}

template <class T>
typename tripVector<T>::iterator& tripVector<T>::iterator::operator++(){	//++ prefisso
    pointer = pointer+1;
    return *this;
}

template <class T>
typename tripVector<T>::iterator& tripVector<T>::iterator::operator--(){  //-- prefisso
    pointer = pointer-1;
    return *this;
}

template <class T>
typename tripVector<T>::iterator tripVector<T>::iterator::operator++(int){	//++ postfisso
    T* temp = pointer;
    pointer = pointer+1;
    return temp;
}

template <class T>
typename tripVector<T>::iterator tripVector<T>::iterator::operator--(int){    //-- postfisso
    T* temp = pointer;
    pointer = pointer-1;
    return temp;
}

template <class T>
typename tripVector<T>::iterator tripVector<T>::iterator::operator+(int i){
    return iterator(pointer+i);
}

template <class T>
typename tripVector<T>::iterator tripVector<T>::iterator::operator-(int i){
    return iterator(pointer-i);
}

template <class T>
T& tripVector<T>::iterator::operator*() const{
    return *pointer;
}

//____________________________________________________________________________________________________________________

//Implementazione Const_Iterator

template <class T>
bool tripVector<T>::const_iterator::operator==(const const_iterator& i) const{
    return pointer == i.pointer;
}

template <class T>
bool tripVector<T>::const_iterator::operator!=(const const_iterator& i) const{
    return pointer!=i.pointer;
}

template <class T>
typename tripVector<T>::const_iterator& tripVector<T>::const_iterator::operator++(){	//++ prefisso
    pointer = pointer+1;
    return *this;
}

template <class T>
typename tripVector<T>::const_iterator& tripVector<T>::const_iterator::operator--(){  //-- prefisso
    pointer = pointer-1;
    return *this;
}

template <class T>
typename tripVector<T>::const_iterator tripVector<T>::const_iterator::operator++(int){	//++ postfisso
    T* temp = pointer;
    pointer = pointer+1;
    return temp;
}

template <class T>
typename tripVector<T>::const_iterator tripVector<T>::const_iterator::operator--(int){    //-- postfisso
    T* temp = pointer;
    pointer = pointer-1;
    return temp;
}

template <class T>
typename tripVector<T>::const_iterator tripVector<T>::const_iterator::operator+(int i){
    return iterator(pointer+i);
}

template <class T>
typename tripVector<T>::const_iterator tripVector<T>::const_iterator::operator-(int i){
    return iterator(pointer-i);
}

template <class T>
const T& tripVector<T>::const_iterator::operator*() const{
    return *pointer;
}

//___________________________________________________________________________________________________________________________

//Implementazione dei metodi di tripVector

template <class T> //Costruttore a due parametri
tripVector<T>::tripVector(const T& t, unsigned int n){
    size = n;
    capacity = n;
    elements = new T[capacity];
    for(unsigned int i=0; i<n; i++)
        elements[i] = t;
}

template <class T> //Costruttore di copia
tripVector<T>::tripVector(const tripVector& t):
    elements(t.size ? new T[t.capacity] : nullptr),
    capacity(t.capacity),
    size(t.size) {
    if(t.size > 0)
        for (unsigned int i=0; i<size; i++)
            elements[i] = t.elements[i];
}

template <class T> //Distruttore
tripVector<T>::~tripVector(){
    if(elements)
        delete[] elements;
}

template <class T> //Assegnazione
tripVector<T>& tripVector<T>::operator=(const tripVector& t){
    elements = new T[t.capacity];
    capacity = t.capacity;
    size = t.size;
    for(unsigned int i=0; i<size; i++)
        elements[i] = t.elements[i];
    return *this;
}

//Metodi di tripVector per iteratori  __________________________________________________________________________________

template <class T>
typename tripVector<T>::iterator tripVector<T>::begin(){
    return iterator(elements);
}

template <class T>
typename tripVector<T>::iterator tripVector<T>::end(){
    return iterator(elements+size);
}

template <class T>
typename tripVector<T>::const_iterator tripVector<T>::begin() const{
    return const_iterator(elements);
}

template <class T>
typename tripVector<T>::const_iterator tripVector<T>::end() const{
    return const_iterator(elements+size);
}

//Metodi per la dimensione occupata dal Vector ____________________________________________________________________________

template <class T>
unsigned int tripVector<T>::getSize() const { return size; }

template <class T>
bool tripVector<T>::isEmpty() const { return size==0; }

//Operatori di subscripting _______________________________________________________________________________________________

template <class T>
T& tripVector<T>::operator[](unsigned int i) { return elements[i]; }

template <class T>
const T& tripVector<T>::operator[](unsigned int i) const { return elements[i]; }

//Operazioni sui dati del Vector _________________________________________________________________________________________

template <class T> //Inserimento in coda
void tripVector<T>::push_back(const T& t){
    if(isEmpty())
        elements = new T[capacity];
    else if(size >= capacity)
        doubleCapacity(*this);
    elements[size] = t;
    size++;
}

template <class T> //Rimozione in coda
T tripVector<T>::pop_back(){
    if(!isEmpty()){
        T temp = elements[size-1];
        size--;
        return temp;
    }
    else throw EmptyContainerException();
}

template <class T>
typename tripVector<T>::iterator tripVector<T>::insert(tripVector<T>::iterator it, const T& t){
    if(isEmpty())
        elements = new T[capacity];
    size++;
    if(size >= capacity)
        doubleCapacity(*this);

    for(auto j=end(); j!=it; j--) //sposto gli elementi in avanti di uno
        *j = *(j-1);
    *it = t; //Inserisco t
    return it;
}

template <class T> //Eliminazione tramite iteratore
typename tripVector<T>::iterator tripVector<T>::erase(tripVector<T>::iterator it){
    if(!isEmpty()){
        if(it.pointer!=nullptr){
            if(size>1){
                for(auto j=it; j!=end()-1; j++) //spostamento degli elementi indietro di uno
                    *j = *(j+1);
                size--;
            }
            return it;
        }
        throw NullPointerException();
    }
    throw EmptyContainerException();
}

template <class T> //Eliminazione dell'N-esimo elemento
void tripVector<T>::erase(unsigned int n){
    if(!isEmpty() && n<size){
        for(unsigned int i=n; i<size-1; i++)
            elements[i] = elements[i+1];
        size--;
    }
}

template <class T> //Ricerca
typename tripVector<T>::iterator tripVector<T>::search(const T& t){
    if(!isEmpty())
        for(auto it=begin(); it!=end(); it++)
            if(*it == t)
                return t;
    return iterator(); //Ritorno un iterator vuoto nel caso in cui non trovo nulla
}

//_____________________________________________________________________________________________________________________________________

template <class T>
void tripVector<T>::doubleCapacity(tripVector<T>& t){
    t.capacity = t.capacity*2;
    T* temp = new T[t.capacity]; //Alloco il nuovo vector
    for (unsigned int i=0; i<t.size; i++)  //copio il vecchio vector
        temp[i] = t.elements[i];
    t.elements = temp; //assegno il nuovo vector
}

#endif // TRIPVECTOR_H
