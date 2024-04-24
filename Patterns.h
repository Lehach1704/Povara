#ifndef PatternsH
#define PatternsH

template<class Type>
class Iterator
{
protected:
    Iterator() {}

public:
    virtual ~Iterator() {}
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() const = 0;
    virtual Type CurrentItem() const = 0;
};


template<class Type>
class Decorator : public Iterator<Type>
{
protected:
    Iterator<Type> *Iter;

public:
    Decorator(Iterator<Type> *iter) {Iter = iter;}
    virtual ~IteratorDecorator() { delete It; }
    void First() {It->First(); }
    void Next() {It->Next(); }
    bool IsDone() const { return It->IsDone(); }
    Type CurrentItem() const { return It->CurrentItem(); }
};

#endif // PatternsH
