/*
 * Composite Pattern
 * Author: Kei Nakata
 * Data: Oct.6.2014
 * Compose objects into tree structures to represent part-whole
 * hierarchies. Composite lets clients treat individual objects
 * and composition of objects unifomly.
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <map>
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::pair;

class Component
{
protected:
  string _name;
public:
  Component(const string& name) : _name(name) {}
  virtual ~Component() = default;
  virtual void show() = 0;
};

class Composite :public Component
{
  map<int, Component*> children;
public:
  using Component::Component;
  ~Composite()
  {
    for(auto it = children.begin(); it != children.end(); it++)
    {
      cout << "Des" << endl;
      delete it->second;
    }
  };
  void destroy()
  {
    for(auto it = children.begin(); it != children.end(); it++)
    {
      cout << "Destroy" << endl;
      delete it->second;
    }
    delete this;
  };
  void add(Component* child)
  {
    static int index = 0;
    children.insert(pair<int, Component*>(index, child));
    ++index;
  }

  void remove(int index)
  {
    auto it = children.find(index);
    children.erase(it);
  }

  void show()
  {
    auto it = children.begin();
    for(it = children.begin(); it != children.end(); ++it)
      {
        it->second->show();
      }
  }

};

class Leaf:public Component
{
public:
  using Component::Component;
  void show()
  {
    cout << this->_name << endl;
  }
};



int main()
{
  Composite* container= new Composite("box");
  Composite* small_container = new Composite("small_box");
  container->add(new Leaf("apple"));
  container->add(new Leaf("pear"));
  container->add(new Leaf("orange"));
  small_container->add(new Leaf("beaf"));
  small_container->add(new Leaf("chicken"));
  small_container->add(new Leaf("pork"));
  container->add(small_container);
  container->show();
  delete container;

  return EXIT_SUCCESS;
}
