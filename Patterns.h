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

#endif // PatternsH