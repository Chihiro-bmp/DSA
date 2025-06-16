//using class template to define a list

template <typename T>
class list{
    private:


    public:

    list(){}//constructor

    virtual ~list(){}//base destructor

    //Insert an element at the current Location. Item:the element to be inserted

    virtual void insert(const T& item)=0;

    //append an element at the end of the list. Item:the element to be appended
    virtual void append(const T& item)=0;
    

};