
#include <iostream>
#include <vector>

class Base {

};

class Parameters {

};

class Filter
{

public:
  Filter(Base b, Parameters p) {

  }

};

class One : public Filter
{
  public:
    One(Base b, Parameters p) : Filter(b, p){

    }
};

class Two : public Filter
{
  public:
    Two(Base b, Parameters p) : Filter(b, p){

    }
};

int main(int argc, char ** argv)
{
    Base b;
    Parameters p1, p2;
	std::vector < Filter * > v;

	v.push_back(new One(b, p1));
	v.push_back(new Two(b, p2));

	system("pause");

	return EXIT_SUCCESS;
}
