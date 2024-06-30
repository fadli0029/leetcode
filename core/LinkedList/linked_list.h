template <typename T>
class LinkedList
{
  public:
    // Constructor
    LinkedList();

    // Copy constructor, deep copy
    LinkedList(const LinkedList& other);

    // Copy constructor, transfer resource (does not perform deep copy)
    LinkedList(LinkedList&& other) noexcept;

    // Destructor
    ~LinkedList();

    // Assignment operator, deep copy
    LinkedList& operator=(const LinkedList& other);

    // Assignment operator, transfer resource (does not perform deep copy)
    LinkedList& operator=(LinkedList&& other) noexcept;

    // Data-structure-specific member functions:
    // ...

  private:
};
