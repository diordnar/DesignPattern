/*
 * Factyory Method Pattern
 * Author: Kei Nakata
 * Data: Oct.6.2014
 * Define an interface for creating an object, but let subclasses
 * decide which class to instantiate. factory method lets a class
 * defer instantiation to subclasses.
 */
#include <iostream>
#include <cstdlib>
#include <stack>
using std::cout;
using std::endl;
using std::stack;

class Product
{
public:
  Product() = default;
  virtual void call() = 0;
  virtual ~Product() = default;
};

class Creator
{
public:
  virtual Product* create() = 0;
  virtual void factoryMethod() = 0;
  Creator() = default;
  virtual ~Creator() = default;
};

class ConcreteProduct: public Product
{
public:
  ConcreteProduct() = default;
  virtual ~ConcreteProduct() = default;
  void call()
  {
    cout << "Hi!" << endl;
  }
};

template<typename T>
class LifeTimeManager
{
  stack<T*> store;
public:
  LifeTimeManager() = default;
  void push(T* p)
  {
    store.push(p);
  }
  virtual ~LifeTimeManager()
  {
    while(!store.empty())
      {
        if(store.top() != NULL)
          delete store.top();
        store.pop();
      }
  }
};

class ConcreteCreator : public Creator
{
  int count = 0;
  LifeTimeManager<Product> manager;
public:
  ConcreteCreator() = default;

  Product* create()
  {
    this->count++;

    Product* p = new ConcreteProduct;
    manager.push(p);
    return p;
  }

  void factoryMethod()
  {
    cout << "I spawned " << this->count << " times!" << endl;
  }
};

int main()
{
  ConcreteCreator mommy;
  Product *a, *b, *c, *d;
  a = mommy.create();
  a->call();
  b = mommy.create();
  b->call();
  c = mommy.create();
  c->call();
  d = mommy.create();
  d->call();
  mommy.factoryMethod();
  return EXIT_SUCCESS;
}
