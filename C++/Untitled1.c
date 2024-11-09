#include <vector>
#include <iostream>
#include <memory>

class can_display {
public:
  virtual void display() = 0;
  virtual ~can_display() = default;
};

class A : public can_display
{
  void display() override
  {
    // display something
    std::cout << "Display from A\n";
  }
};

class B : public can_display
{
  void display() override
  {
    // display something two
    std::cout << "Display from B\n";
  }
};


int main()
{
    can_display* a = new A();
    can_display* b = new B();

    can_display* array[2] = {a, b};

    array[0]->display();
    array[1]->display();

}
