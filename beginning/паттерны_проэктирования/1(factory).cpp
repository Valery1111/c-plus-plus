
#include <iostream>

class Base {

};

class Parameters {

};

class AbstractSelectionA {
 public:
  virtual ~AbstractSelectionA(){};
  virtual std::string UsefulFunctionA() const = 0;
};


class ConcreteSelectionA1 : public AbstractSelectionA {
 public:
  std::string UsefulFunctionA() const override {
    return "The result of the Selection A1.";
  }
};

class ConcreteSelectionA2 : public AbstractSelectionA {
  std::string UsefulFunctionA() const override {
    return "The result of the Selection A2.";
  }
};


class AbstractFilter {
 public:
  AbstractFilter(Base b, Parameters p) {

  }
  virtual AbstractSelectionA *CreateSelectionA() const = 0;
};


class ConcreteFilter1 : public AbstractFilter {
 public:
  ConcreteFilter1(Base b, Parameters p) : AbstractFilter(b, p){

  }
  AbstractSelectionA *CreateSelectionA() const override {
    return new ConcreteSelectionA1();
  }
};


class ConcreteFilter2 : public AbstractFilter {
 public:
  ConcreteFilter2(Base b, Parameters p) : AbstractFilter(b, p){

  }
  AbstractSelectionA *CreateSelectionA() const override {
    return new ConcreteSelectionA2();
  }
};


void Client(const AbstractFilter &filter) {
  const AbstractSelectionA *selection_a = filter.CreateSelectionA();
  std::cout << selection_a->UsefulFunctionA() << "\n";
  delete selection_a;
}

int main() {
  Base b;
  Parameters p1, p2;
  std::cout << "Client: Testing client code with the first Filter type:\n";
  ConcreteFilter1 *f1 = new ConcreteFilter1(b, p1);
  Client(*f1);
  delete f1;
  std::cout << std::endl;
  std::cout << "Client: Testing the same client code with the second Filter type:\n";
  ConcreteFilter2 *f2 = new ConcreteFilter2(b, p2);
  Client(*f2);
  delete f2;
  system("pause");
  return EXIT_SUCCESS;
}
